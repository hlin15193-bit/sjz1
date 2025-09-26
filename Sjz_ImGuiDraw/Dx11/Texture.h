#pragma once
#include <unordered_map>
#include <iostream>
#include <filesystem>
#include <sstream>


#include"../Utils/Utils.hpp"
#include <d3d11.h>
struct ImGuiTextureInfo
{
    ID3D11ShaderResourceView* Texture;//30109433
    int Width;
    int Height;
};

extern std::unordered_map<std::string, ImGuiTextureInfo> GImGuiTextureMap;

class Texture {
public:
    static inline std::vector<std::string> TEXTURE_EXTENSIONS = { "png", "jpg", "jpeg" };

    static ImGuiTextureInfo LoadTexture(ID3D11Device* g_pd3dDevice, std::string path);

    static void LoadTextures(ID3D11Device* g_pd3dDevice, const std::string folderPath, bool removeColor = false);

    static bool LoadTextureFromFile(ID3D11Device* g_pd3dDevice, const char* filename, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height, bool removeColor = false);


    static ImGuiTextureInfo LoadTextureFromMemory(ID3D11Device* device, const std::vector<uint8_t>& imageData, bool removeColor = false);
};


#pragma pack(push, 1)
struct FileHeader {
    uint64_t itemId;
    uint32_t dataSize;
};
#pragma pack(pop)

struct ImageInfo
{
    uint64_t itemId;
    std::vector<uint8_t> data;
};


class TextureFileUtils
{
public:
    static  bool SaveImageInfoAsPNG(const ImageInfo& img);
    static std::vector<uint8_t> LoadFileBinary(const std::string& path);

    static bool LoadItemsFromBin_NoHeader(const std::string& inputPath, std::vector<ImageInfo>& outItems);
    static  bool SaveImageToBin_NoHeader(const std::string& outputPath, const std::vector<ImageInfo>& items);
};