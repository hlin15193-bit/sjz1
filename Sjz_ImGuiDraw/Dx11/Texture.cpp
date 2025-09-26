#define STB_IMAGE_IMPLEMENTATION
#include"Texture.h"
#include "stb_image.h"
#include"imgui.h"

std::unordered_map<std::string, ImGuiTextureInfo> GImGuiTextureMap = {};

void Texture::LoadTextures(ID3D11Device* g_pd3dDevice, const std::string folderPath, bool removeColor) {
    for (auto& file : std::filesystem::recursive_directory_iterator(folderPath)) {
        std::stringstream ss;
        ss << file;

        if (Utils::Contains(TEXTURE_EXTENSIONS, ss.str().substr(ss.str().length() - 4, 3))) {
            ImGuiTextureInfo Info;
            std::string key = ss.str().substr(1, ss.str().length() - 2);
            bool Ret = Texture::LoadTextureFromFile(g_pd3dDevice, key.c_str(), &Info.Texture, &Info.Width, &Info.Height, removeColor);
            IM_ASSERT(Ret);

            key = Utils::ReplaceAll(key.c_str(), "\\\\", "/");
            if (removeColor) key += "_RemoveColor";
            GImGuiTextureMap[key] = Info;
        }
    }
}

ImGuiTextureInfo Texture::LoadTexture(ID3D11Device* g_pd3dDevice, std::string path) {
    ImGuiTextureInfo Info;

    if (GImGuiTextureMap.count(path) > 0)
    {
        Info = GImGuiTextureMap[path];
    }
    else {
        bool Ret = Texture::LoadTextureFromFile(g_pd3dDevice, path.c_str(), &Info.Texture, &Info.Width, &Info.Height);
        IM_ASSERT(Ret);
        path = Utils::ReplaceAll(path.c_str(), "\\\\", "/");
        GImGuiTextureMap[path] = Info;
    }

    return Info;
}

bool Texture::LoadTextureFromFile(ID3D11Device* g_pd3dDevice, const char* filename, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height, bool removeColor)//30109433
{
    // Load from disk into a raw RGBA buffer
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
           return false;
       

    // Convert all pixels to black while preserving alpha (transparency)
    if (removeColor)
    {
        int totalPixels = image_width * image_height;
        for (int i = 0; i < totalPixels; i++)
        {
            int index = i * 4; // Each pixel has 4 components (RGBA)
            image_data[index + 0] = 255; // R
            image_data[index + 1] = 255; // G
            image_data[index + 2] = 255; // B
            // Alpha (image_data[index + 3]) remains unchanged to preserve transparency
        }
    }

    // Create texture
    D3D11_TEXTURE2D_DESC desc;
    ZeroMemory(&desc, sizeof(desc));
    desc.Width = image_width;
    desc.Height = image_height;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;

    ID3D11Texture2D* pTexture = NULL;
    D3D11_SUBRESOURCE_DATA subResource;
    subResource.pSysMem = image_data;
    subResource.SysMemPitch = desc.Width * 4;
    subResource.SysMemSlicePitch = 0;
    g_pd3dDevice->CreateTexture2D(&desc, &subResource, &pTexture);

    // Create texture view
    D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
    ZeroMemory(&srvDesc, sizeof(srvDesc));
    srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Texture2D.MipLevels = desc.MipLevels;
    srvDesc.Texture2D.MostDetailedMip = 0;
    g_pd3dDevice->CreateShaderResourceView(pTexture, &srvDesc, out_srv);
    pTexture->Release();

    *out_width = image_width;
    *out_height = image_height;
    stbi_image_free(image_data);

    return true;
}

ImGuiTextureInfo Texture::LoadTextureFromMemory(
    ID3D11Device* device,
    const std::vector<uint8_t>& imageData,
    bool removeColor)
{
    ImGuiTextureInfo result = { nullptr, 0, 0 };

    // 基本参数检查
    if (!device || imageData.empty())
        return result;

    // 使用stb_image加载图像
    int width, height, channels;
    unsigned char* pixelData = stbi_load_from_memory(
        imageData.data(),
        static_cast<int>(imageData.size()),
        &width,
        &height,
        &channels,
        4); // 强制转换为RGBA格式

    if (!pixelData)
        return result;

    // 可选：移除颜色（保留透明度）
    if (removeColor)
    {
        const int pixelCount = width * height;
        for (int i = 0; i < pixelCount; ++i)
        {
            const int index = i * 4;
            pixelData[index + 0] = 255; // R
            pixelData[index + 1] = 255; // G
            pixelData[index + 2] = 255; // B
            // Alpha通道保持不变
        }
    }

    // 创建D3D11纹理
    D3D11_TEXTURE2D_DESC desc = {};
    desc.Width = width;
    desc.Height = height;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = pixelData;
    initData.SysMemPitch = width * 4;

    ID3D11Texture2D* texture = nullptr;
    HRESULT hr = device->CreateTexture2D(&desc, &initData, &texture);
    stbi_image_free(pixelData); // 立即释放图像数据

    if (FAILED(hr) || !texture)
        return result;

    // 创建着色器资源视图
    D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
    srvDesc.Format = desc.Format;
    srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Texture2D.MipLevels = desc.MipLevels;

    hr = device->CreateShaderResourceView(texture, &srvDesc, &result.Texture);
    texture->Release(); // 释放纹理，SRV会保持引用

    if (SUCCEEDED(hr))
    {
        result.Width = width;
        result.Height = height;
    }
    else if (result.Texture)
    {
        result.Texture->Release();
        result.Texture = nullptr;
    }

    return result;
}






bool TextureFileUtils::SaveImageInfoAsPNG(const ImageInfo& img)
{
    std::string filename = std::to_string(img.itemId) + ".png";
    std::ofstream out(filename, std::ios::binary);
    if (!out) {

        return false;
    }
    out.write(reinterpret_cast<const char*>(img.data.data()), img.data.size());
    return true;
}

std::vector<uint8_t> TextureFileUtils::LoadFileBinary(const std::string& path)
{
    std::ifstream in(path, std::ios::binary);
    if (!in) return {};
    return std::vector<uint8_t>((std::istreambuf_iterator<char>(in)), {});
}

bool TextureFileUtils::LoadItemsFromBin_NoHeader(const std::string& inputPath, std::vector<ImageInfo>& outItems)
{
    std::ifstream in(inputPath, std::ios::binary | std::ios::ate);
    if (!in) return false;

    std::streamsize fileSize = in.tellg();
    in.seekg(0, std::ios::beg);

    outItems.clear();

    while (in.tellg() < fileSize) {
        FileHeader header;
        in.read(reinterpret_cast<char*>(&header), sizeof(header));
        if (in.gcount() != sizeof(header)) break;

        if (header.dataSize == 0 || header.dataSize > 100 * 1024 * 1024) break;

        ImageInfo info;
        info.itemId = header.itemId;
        info.data.resize(header.dataSize);

        in.read(reinterpret_cast<char*>(info.data.data()), header.dataSize);
        if (in.gcount() != header.dataSize) break;

        outItems.push_back(std::move(info));
    }

    return true;
}

bool TextureFileUtils::SaveImageToBin_NoHeader(const std::string& outputPath, const std::vector<ImageInfo>& items)
{
    std::ofstream out(outputPath, std::ios::binary);
    if (!out) return false;

    for (const auto& item : items) {
        FileHeader header{ item.itemId, static_cast<uint32_t>(item.data.size()) };
        out.write(reinterpret_cast<const char*>(&header), sizeof(header));
        out.write(reinterpret_cast<const char*>(item.data.data()), item.data.size());
        std::cout << "保存 " << item.itemId << ".png 成功\n";
    }

    return true;
}
