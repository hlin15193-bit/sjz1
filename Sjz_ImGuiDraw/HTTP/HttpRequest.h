
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
    //CPU����
    const long MAX_COMMAND_SIZE = 10000; // ��������������С     
    WCHAR szFetCmd[] = L"wmic cpu get processorid"; // ��ȡCPU���к�������    
    const string strEnSearch = "ProcessorId"; // CPU���кŵ�ǰ����Ϣ  


    BOOL   bret = FALSE;
    HANDLE hReadPipe = NULL; //��ȡ�ܵ�  
    HANDLE hWritePipe = NULL; //д��ܵ�      
    PROCESS_INFORMATION pi;   //������Ϣ      
    STARTUPINFO         si;   //���������д�����Ϣ  
    SECURITY_ATTRIBUTES sa;   //��ȫ����  

    char            szBuffer[MAX_COMMAND_SIZE + 1] = { 0 }; // ���������н�������������  
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

    //1.0 �����ܵ�  
    bret = CreatePipe(&hReadPipe, &hWritePipe, &sa, 0);
    if (!bret)
    {
        goto END;
    }

    //2.0 ���������д��ڵ���ϢΪָ���Ķ�д�ܵ�  
    GetStartupInfo(&si);
    si.hStdError = hWritePipe;
    si.hStdOutput = hWritePipe;
    si.wShowWindow = SW_HIDE; //���������д���  
    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

    //3.0 ������ȡ�����еĽ���  
    bret = CreateProcess(NULL, szFetCmd, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
    if (!bret)
    {
        goto END;
    }



    //4.0 ��ȡ���ص�����  
    WaitForSingleObject(pi.hProcess, 500/*INFINITE*/);
    bret = ReadFile(hReadPipe, szBuffer, MAX_COMMAND_SIZE, &count, 0);
    if (!bret)
    {
        goto END;
    }

    //5.0 ����CPU���к�  
    bret = FALSE;
    strBuffer = szBuffer;
    ipos = strBuffer.find(strEnSearch);

    if (ipos < 0) // û���ҵ�  
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
    //ȥ���м�Ŀո� \r \n     
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
    //�ر����еľ��  
    CloseHandle(hWritePipe);
    CloseHandle(hReadPipe);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    }


return(bret);
}