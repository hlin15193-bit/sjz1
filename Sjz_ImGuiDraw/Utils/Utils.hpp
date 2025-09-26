#pragma once
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS// ��������C++17���þ���
#include <codecvt>

#include <windows.h>
#include <iostream>
#include <string>
#include <ShlObj.h>
#include <ctime>
#include <sstream>
#include <regex>
#include <fstream>
#include <iomanip>
#include <setupapi.h>
#include <initguid.h>
#include <devguid.h>



#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_RESET   "\033[0m"
#define COLOR_LYELLOW "\033[1;33m"
#define COLOR_LGREEN  "\033[1;32m"
#define COLOR_LBLUE   "\033[1;34m"

namespace Utils
{
	static std::string WstrToUtf8(const std::wstring Wstr)
	{
		int Len = WideCharToMultiByte(CP_UTF8, 0, Wstr.c_str(), -1, NULL, 0, 0, NULL);

		std::string NewStr;
		NewStr.resize(Len);

		WideCharToMultiByte(CP_UTF8, 0, Wstr.c_str(), -1, (char*)NewStr.c_str(), Len, 0, NULL);
		return NewStr;
	}
	// �� Unicode ת������ (���� \u5927) ת��Ϊ��Ӧ�� UTF-16 �ַ�
	inline std::wstring unicode_escape_to_wstring(const std::string& str) {
		std::wstring result;
		std::string::const_iterator it = str.begin();

		while (it != str.end()) {
			if (*it == '\\' && (it + 1) != str.end() && *(it + 1) == 'u') {
				it += 2; // ���� \u

				// ���� 4 λʮ��������
				std::string hex_str(it, it + 4);
				unsigned int code_point = std::stoul(hex_str, nullptr, 16);
				wchar_t wchar = static_cast<wchar_t>(code_point);
				result += wchar;
				it += 4; // ���� 4 λʮ��������
			}
			else {
				result += *it;
				++it;
			}
		}

		return result;
	}
	// �����ַ��ַ��� (UTF-16) ת��Ϊָ���� ANSI ����
	inline std::string wstring_to_ansi(const std::wstring& wide_str, UINT code_page) {
		int ansi_char_count = WideCharToMultiByte(code_page, 0, wide_str.c_str(), -1, nullptr, 0, nullptr, nullptr);
		if (ansi_char_count == 0) {
			throw std::runtime_error("Error calculating ANSI buffer size.");
		}

		std::vector<char> ansi_buffer(ansi_char_count);
		int result = WideCharToMultiByte(code_page, 0, wide_str.c_str(), -1, ansi_buffer.data(), ansi_char_count, nullptr, nullptr);
		if (result == 0) {
			throw std::runtime_error("Error converting wide string to ANSI.");
		}

		return std::string(ansi_buffer.data());
	}



	inline bool IsLobby(const std::string& mapName) {
		bool IsLobby = (mapName.find("fail") != std::string::npos || mapName.find("None") != std::string::npos || mapName.find("TslLobby") != std::string::npos || mapName.find("Tsl") != std::string::npos);
		if (IsLobby) return IsLobby;
		return mapName.find("Main") == std::string::npos;
	}

	inline bool Contains(std::vector<std::string> vec, std::string str) {
		for (std::string s : vec) {
			if (s == str)
				return true;
		}
		return false;
	}

	inline std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();  // Handles case where 'to' is a substring of 'from'
		}
		return str;
	}

	inline uint32_t ReverseBytes(uint32_t value) {
		return ((value & 0x000000FF) << 24) |
			((value & 0x0000FF00) << 8) |
			((value & 0x00FF0000) >> 8) |
			((value & 0xFF000000) >> 24);
	}

	inline ULONG64 CalcRelative(ULONG64 current)
	{
		return current + *(int32_t*)(current)+4;
	}

	inline std::string RemoveBracketsAndTrim(const std::string& input) {
		size_t leftBracketPos = input.find('[');
		size_t rightBracketPos = input.find(']');

		if (leftBracketPos != std::string::npos && rightBracketPos != std::string::npos && rightBracketPos > leftBracketPos) {
			std::string result = input.substr(rightBracketPos + 1);
			size_t firstNonSpace = result.find_first_not_of(" ");
			size_t lastNonSpace = result.find_last_not_of(" ");

			if (firstNonSpace != std::string::npos && lastNonSpace != std::string::npos) {
				result = result.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
			}
			else {
				result.clear();
			}

			return result;
		}
		else {
			return input;
		}
	}

	inline std::string ExtractSubstring(const std::string& source, const std::string& pattern) {
		if (source == "")
		{
			return "";
		}
		std::regex re(pattern);
		std::smatch match;

		if (std::regex_search(source, match, re) && match.size() > 1) {
			return match.str(1);
		}
		return "";
	}

	inline bool IsPointInScreen(float x, float y, float screenWidth, float screenHeight) {
		return x >= 0 && x <= screenWidth && y >= 0 && y <= screenHeight;
	}

	inline std::vector<std::string> GetCOMPorts() {
		std::vector<std::string> comPorts;

		HDEVINFO hDevInfo;
		SP_DEVINFO_DATA DeviceInfoData;

		hDevInfo = SetupDiGetClassDevs(&GUID_DEVCLASS_PORTS, NULL, NULL, DIGCF_PRESENT);
		if (hDevInfo == INVALID_HANDLE_VALUE) {
			std::cerr << "Failed to get device information set for the COM ports." << std::endl;
			return comPorts;
		}

		DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
		for (DWORD i = 0; SetupDiEnumDeviceInfo(hDevInfo, i, &DeviceInfoData); i++) {
			char friendlyName[256];
			DWORD size = sizeof(friendlyName);

			if (SetupDiGetDeviceRegistryPropertyA(hDevInfo, &DeviceInfoData, SPDRP_FRIENDLYNAME,
				NULL, (PBYTE)friendlyName, size, &size)) {
				comPorts.push_back(friendlyName);
			}
		}

		SetupDiDestroyDeviceInfoList(hDevInfo);
		return comPorts;
	}

	inline float CalculateDistance(float x1, float y1, float x2, float y2) {
		float dx = x2 - x1;
		float dy = y2 - y1;
		return std::sqrt(dx * dx + dy * dy);
	}

	inline void Trim(std::string& s) {
		// Trim from the left
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
			return !std::isspace(ch);
			}));

		// Trim from the right
		s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
			return !std::isspace(ch);
			}).base(), s.end());
	}
	inline bool ValidPtr(uint64_t Ptr)
	{
		auto flag = (bool)(Ptr < 0x1000000 || Ptr > 0x7FFFFFF00000);
		return  !flag;
	}

	inline bool ValidPtr(PVOID Ptr)
	{
		auto v1 = (ULONG64)Ptr;
		auto flag = (bool)(v1 < 0x1000000 || v1 > 0x7FFFFFF00000);
		return !flag;
	}

	inline std::string ReadConfigFile(const std::string& filename) {
		std::ifstream file(filename);
		std::string content;

		if (!file) {
			return "";
		}

		std::string line;
		while (std::getline(file, line)) {
			content += line + '\n';
		}

		return content;
	}

	inline void WriteConfigFile(const std::string& filename, const std::string& content) {
		std::ofstream file(filename);

		if (!file) {
			return;
		}

		file << content;
	}

	inline char* UnicodeToAnsi(char* wstr)
	{
		if (!wstr) { return NULL; }
		int strleng = WideCharToMultiByte(CP_ACP, NULL, (LPCWCH)wstr, (int)wcslen((LPCWCH)wstr), NULL, 0, NULL, FALSE);
		char* str = new char[strleng + 1];
		WideCharToMultiByte(CP_ACP, NULL, (LPCWCH)wstr, (int)wcslen((LPCWCH)wstr), str, strleng, NULL, FALSE);
		str[strleng] = '\0';
		return str;
	}

	inline std::wstring StringToWstring(const std::string& str) {
		std::wstring res;
		int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, nullptr, 0);
		if (len <= 0) {
			return res;
		}
		res.resize(len - 1); // ��1ȥ��ĩβ�� null ��ֹ��
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, &res[0], len);
		return res;
	}

	inline std::string WstringToUTF8(const std::wstring& wstr) {
		std::string res;
		int len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
		if (len <= 0) {
			return res;
		}
		res.resize(len - 1); // ��1ȥ��ĩβ�� null ��ֹ��
		WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &res[0], len, nullptr, nullptr);
		return res;
	}

	inline std::string FormatMinutes(float minutes) {
		// ����Сʱ�ͷ���
		int hours = static_cast<int>(minutes / 60);
		int remainingMinutes = static_cast<int>(minutes) % 60;

		// ʹ�� stringstream ��ʽ���ַ���
		std::stringstream ss;
		ss << std::setw(2) << std::setfill('0') << hours << ":";
		ss << std::setw(2) << std::setfill('0') << remainingMinutes;

		return ss.str();
	}

	inline std::string StringToUTF8(const std::string& str) {
		std::wstring wideStr = StringToWstring(str);
		return WstringToUTF8(wideStr);
	}

	inline std::string getCurrentTime() {
		time_t currentTime;
		struct tm timeinfo;

		// ��ȡ��ǰʱ��
		time(&currentTime);

		// ʹ��localtime_s��������localtime
		localtime_s(&timeinfo, &currentTime);

		// ��ʱ��ת��Ϊtime_t����
		time_t midnight = mktime(&timeinfo);

		// ��ʱ��ת��Ϊ�ַ�����ʽ
		char timeStr[9];
		strftime(timeStr, sizeof(timeStr), "%T", &timeinfo);

		return timeStr;
	}


	//inline bool safeStringToUint64(const std::string& str, uint64_t& result) {
	//	try {
	//		size_t pos = 0;
	//		unsigned long long value = std::stoull(str, &pos);

	//		// ����Ƿ������ַ�������ת����
	//		if (pos != str.size()) {
	//			return false;
	//		}

	//		result = static_cast<uint64_t>(value);
	//		return true;
	//	}
	//	catch (const std::invalid_argument&) {
	//		// �ַ���������Ч����
	//		return false;
	//	}
	//	catch (const std::out_of_range&) {
	//		// ���ֳ��� uint64_t ��Χ
	//		return false;
	//	}
	//}
	inline bool safeStringToUint64(const std::string& str, uint64_t& result) {
		std::stringstream ss(str);
		uint64_t num;
		ss >> num;
		result = num;
		return 0;
	}


	inline void Log(const int& type, const char* format, ...) {
		std::ostringstream oss;

		//oss << COLOR_LYELLOW << "[" << getCurrentTime() << "]";

		if (type == 1) {
			oss << COLOR_LGREEN << "[+] ";
		}
		else if (type == 2) {
			oss << COLOR_RED << "[X] ";
		}
		else {
			oss << COLOR_LYELLOW << "[-] ";
		}

		va_list args;
		va_start(args, format);
		char buffer[256];
		std::vsnprintf(buffer, sizeof(buffer), format, args);

		va_end(args);

		oss << buffer;
		oss << COLOR_RESET;

		std::cout << oss.str() << std::endl;
	}
}