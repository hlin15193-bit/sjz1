#include <string>
#include <vector>
#include <winsock2.h>
#include <Winhttp.h>
#include <urlmon.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "AtlBase.h"
#include "AtlConv.h"


using namespace std;
#pragma comment(lib, "winhttp")//这一句不能省略
string GetHost(string strUrl)
{
    int indexHttp = strUrl.find("http://");
    if (indexHttp != -1)
    {
        strUrl = strUrl.substr(7);
    }
    else
        return "";
    int indexSlash = strUrl.find("/");
    if (indexSlash != -1)
    {
        return strUrl.substr(0, indexSlash);
    }
    else
        return strUrl;
    return "";
}
string GetRequestStr(string strUrl)
{
    int indexHttp = strUrl.find("http://");
    if (indexHttp != -1)
    {
        strUrl = strUrl.substr(7);
    }
    else
        return "";
    int indexSlash = strUrl.find("/");
    if (indexSlash == -1)
    {
        return "";
    }
    else
        return strUrl.substr(indexSlash);
}
string GetHtml(string strUrl, INTERNET_PORT port)
{
    string strHost = GetHost(strUrl);//获取Host
    string strRequestStr = GetRequestStr(strUrl);//获取请求路径
    USES_CONVERSION;
    //2014年7月9日10:02:29
    //LPCWSTR的定义 typedef const wchar_t* LPCWSTR;
    //LPSTR的定义   typedef char* LPCWSTR;
    //LPWSTR的定义  typedef wchar_t* LPWSTR;
    LPCWSTR host = A2CW(strHost.c_str());//string转换为常量指针类型
    LPCWSTR requestStr = A2CW(strRequestStr.c_str());
    //Variables
    DWORD dwSize = 0;
    DWORD dwDownloaded = 0;
    LPSTR pszOutBuffer;
    vector <string>  vFileContent;
    BOOL  bResults = FALSE;

    //Note the definition of HINTERNET
    HINTERNET  hSession = NULL,
        hConnect = NULL,
        hRequest = NULL;
    string strHtml = "";// store the html code
    string str;//temporary variables
  //  ofstream out("test.html", ios::binary);//output the html code to a html text;
//2014年7月9日10:39:33
//Search the WinHttp API
//what to do when call the function WinHttpOpen？
// Use WinHttpOpen to obtain a session handle.
    hSession = WinHttpOpen(L"WinHTTP Example/1.0",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS, 0);
    // Specify an HTTP server.
    if (hSession)
       // hConnect = WinHttpConnect(hSession, L"www.microsoft.com",
            //INTERNET_DEFAULT_HTTPS_PORT, 0);
        hConnect = WinHttpConnect(hSession, host,
            port, 0);


    // Create an HTTP request handle.
    if (hConnect)
        hRequest = WinHttpOpenRequest(hConnect, L"GET", requestStr,
            NULL, WINHTTP_NO_REFERER,
            NULL,
            NULL);
    // Send a request.
    if (hRequest)
        bResults = WinHttpSendRequest(hRequest,
            WINHTTP_NO_ADDITIONAL_HEADERS,
            0, WINHTTP_NO_REQUEST_DATA, 0,
            0, 0);
    // End the request.
    if (bResults)
        bResults = WinHttpReceiveResponse(hRequest, NULL);

    //obtain the html source code       
    if (bResults)
        do
        {
            // Check for available data.
            dwSize = 0;
            if (!WinHttpQueryDataAvailable(hRequest, &dwSize))
                printf("Error %u in WinHttpQueryDataAvailable.\n",
                    GetLastError());
            // Allocate space for the buffer.
            pszOutBuffer = new char[dwSize + 1];
            if (!pszOutBuffer)
            {
                printf("Out of memory\n");
                dwSize = 0;
            }
            else
            {
                // Read the Data.
                ZeroMemory(pszOutBuffer, dwSize + 1);
                if (!WinHttpReadData(hRequest, (LPVOID)pszOutBuffer,
                    dwSize, &dwDownloaded))
                {
                    printf("Error %u in WinHttpReadData.\n",
                        GetLastError());
                }
                else
                {
                    //printf("%s", pszOutBuffer);
                   // Data in vFileContent
                    vFileContent.push_back(pszOutBuffer);

                }
                // Free the memory allocated to the buffer.
                delete[] pszOutBuffer;
            }
        } while (dwSize > 0);
        // Keep checking for data until there is nothing left.
       // Report any errors.
        if (!bResults)
            printf("Error %d has occurred.\n", GetLastError());
        // Close any open handles.
        if (hRequest) WinHttpCloseHandle(hRequest);
        if (hConnect) WinHttpCloseHandle(hConnect);
        if (hSession) WinHttpCloseHandle(hSession);


        for (int i = 0; i < (int)vFileContent.size(); i++)
        {
            str = vFileContent[i];
            //out << str;
            strHtml += vFileContent[i];
        }
        // out.close();

        return strHtml;
}

// 分割字符串
vector<std::string> Split(const std::string& s, const std::string& seperator)
{
    std::vector<std::string> result;
    typedef std::string::size_type string_size;
    string_size i = 0;

    while (i != s.size()) {
        // 找到字符串中首个不等于分隔符的字母
        int flag = 0;
        while (i != s.size() && flag == 0) {
            flag = 1;
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[i] == seperator[x]) {
                    ++i;
                    flag = 0;
                    break;
                }
        }

        // 找到又一个分隔符，将两个分隔符之间的字符串取出
        flag = 0;
        string_size j = i;
        while (j != s.size() && flag == 0) {
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[j] == seperator[x]) {
                    flag = 1;
                    break;
                }
            if (flag == 0)
                ++j;
        }
        if (i != j) {
            result.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return result;
}

