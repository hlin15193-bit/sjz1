
#pragma once
#include <string>
#include <vector>

#include <Winhttp.h>

using namespace std;
string GetHost(string strUrl);
string GetRequestStr(string strUrl);
string GetHtml(string strUrl, INTERNET_PORT port);
vector<std::string> Split(const std::string& s, const std::string& seperator);
int index = 0;
BOOL GetCpuByCmd(string& ider, int len/*=128*/)
{
    //CPU序列
    const long MAX_COMMAND_SIZE = 10000; // 命令行输出缓冲大小     
    WCHAR szFetCmd[] = L"wmic cpu get processorid"; // 获取CPU序列号命令行    
    const string strEnSearch = "ProcessorId"; // CPU序列号的前导信息  


    BOOL   bret = FALSE;
    HANDLE hReadPipe = NULL; //读取管道  
    HANDLE hWritePipe = NULL; //写入管道      
    PROCESS_INFORMATION pi;   //进程信息      
    STARTUPINFO         si;   //控制命令行窗口信息  
    SECURITY_ATTRIBUTES sa;   //安全属性  

    char            szBuffer[MAX_COMMAND_SIZE + 1] = { 0 }; // 放置命令行结果的输出缓冲区  
    string          strBuffer;
    unsigned long   count = 0;
    long            ipos = 0;

    memset(&pi, 0, sizeof(pi));
    memset(&si, 0, sizeof(si));
    memset(&sa, 0, sizeof(sa));

    pi.hProcess = NULL;
    pi.hThread = NULL;
    si.cb = sizeof(STARTUPINFO);
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    //1.0 创建管道  
    bret = CreatePipe(&hReadPipe, &hWritePipe, &sa, 0);
    if (!bret)
    {
        goto END;
    }

    //2.0 设置命令行窗口的信息为指定的读写管道  
    GetStartupInfo(&si);
    si.hStdError = hWritePipe;
    si.hStdOutput = hWritePipe;
    si.wShowWindow = SW_HIDE; //隐藏命令行窗口  
    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

    //3.0 创建获取命令行的进程  
    bret = CreateProcess(NULL, szFetCmd, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
    if (!bret)
    {
        goto END;
    }



    //4.0 读取返回的数据  
    WaitForSingleObject(pi.hProcess, 500/*INFINITE*/);
    bret = ReadFile(hReadPipe, szBuffer, MAX_COMMAND_SIZE, &count, 0);
    if (!bret)
    {
        goto END;
    }

    //5.0 查找CPU序列号  
    bret = FALSE;
    strBuffer = szBuffer;
    ipos = strBuffer.find(strEnSearch);

    if (ipos < 0) // 没有找到  
    {
        goto END;
    }
    else
    {
        strBuffer = strBuffer.substr(ipos + strEnSearch.length());
    }

    memset(szBuffer, 0x00, sizeof(szBuffer));
    strcpy_s(szBuffer, strBuffer.c_str());

    //modify here
    //去掉中间的空格 \r \n     
    char temp[512];
    memset(temp, 0, sizeof(temp));


    for (size_t i = 0; i < strBuffer.size(); i++)
    {
        if (strBuffer[i] != ' ' && strBuffer[i] != '\n' && strBuffer[i] != '\r')
        {
            temp[index] = strBuffer[i];
            index++;
        }
    }
    ider = temp;

    bret = TRUE;

END: {
    //关闭所有的句柄  
    CloseHandle(hWritePipe);
    CloseHandle(hReadPipe);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    }


return(bret);
}