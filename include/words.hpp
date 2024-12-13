#include <string.h>
#include <cstdio>
#include <stdlib.h>

// ȥ���ո�
void strTrim(char* str) 
{
    int len = strlen(str), j = 0;
    for (int i = 0; i < len; i++) 
	{
        if (str[i] != ' ') 
		{
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

//ȥ�������ʡ�
void clearQingWen(char* str)
{
	char *pos = strstr(str,"����");
	if(pos!=NULL)
	{
		// �� "����" �����������ǰ�ƶ����ǵ� "����"
        memmove(pos, pos + strlen("����"), strlen(pos + strlen("����")) + 1);
	}
} 

//ȥ���ʺ� 
void clearWenHao(const char* input, char* output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != '��' && input[i] != '?') {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

// ��ȡ��������
int getPersonName(const char* str1, char* result) {
    char str[4096];  // �����㹻�Ļ�����
    clearWenHao(str1, str);
    clearQingWen(str);
    const char* pos = strstr(str, "��˭");
    if (pos) {
        strncpy(result, str, pos - str);
        result[pos - str] = '\0';
        return 1;
    }

    pos = strstr(str, "˭��");
    if (pos) {
        strcpy(result, pos + 2);
        return 1;
    }

    pos = strstr(str, "��ʲô");
    if (pos) {
        strncpy(result, str, pos - str);
        result[pos - str] = '\0';
        return 1;
    }

    return -1;  // ����������
}
