#include <iostream>
#include <string>
using namespace std;


extern "C"
{
	
	int __stdcall lenght(char* buffer, char* str)					// ���������� ����� ������
	{
		if (str == nullptr)
			return 0;
		int len = 0;
		for (int i = 0; i < 256; i++)
			if (str[i] == '\0')
			{
				len = i; break;
			}
		return len;
	}


	int __stdcall strcomp(char* str1, char* str2) // ��������� �����
	{
		for (int j = 0; j <256; j++)
		{			
			if (str1[j] == '\0' && str2[j] != '\0')
				return 0;
			if (str1[j] != '\0' && str2[j] == '\0')
				return 0;
			if (str1[j] != str2[j])
				return 0;
			if (str1[j] == '\0' && str2[j] == '\0')
				break;
		}
		return 1;

	}


	int __stdcall atoii(char* buffer, char* ptr)					// �������������� ����������� ��������
	{
		int n = 0;
		while (*ptr >= '0' && *ptr <= '9')
		{
			n *= 10;
			n += *ptr++;
			n -= '0';
		}
		return n;
	}


	char* __stdcall strcopy(char* buffer, char* str)				// ����������� �����
	{
		int i = NULL, len1 = NULL, len2 = NULL;
		for (int j = 0; str[j] != '\0'; j++)
		{
			if (i == 255)
				break;
			buffer[i++] = str[j];
		}
		buffer[i] = '\0';
		return buffer;
	}


	int __stdcall outnum(int value)									// ����� � ������� �������������� ��������
	{
		std::cout << value;
		return 0;
	}


	int __stdcall outstr(char* ptr)									// ����� � ������� ���������� ��������
	{
		if (ptr == nullptr)
			std::cout << std::endl;
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];
		return 0;
	}
}