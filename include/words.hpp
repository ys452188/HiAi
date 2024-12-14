#include <string.h>
#include <cstdio>
#include <stdlib.h>

// 去除空格
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

//去除“请问”
void clearQingWen(char* str)
{
	char *pos = strstr(str,"请问");
	if(pos!=NULL)
	{
		// 将 "请问" 后面的内容向前移动覆盖掉 "请问"
        memmove(pos, pos + strlen("请问"), strlen(pos + strlen("请问")) + 1);
	}
} 

//去除问号 
void clearWenHao(const char* input, char* output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != '？' && input[i] != '?') {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

// 提取人物名称
int getPersonName(const char* str1, char* result) {
    char str[4096];  // 分配足够的缓冲区
    clearWenHao(str1, str);
    clearQingWen(str);
    const char* pos = strstr(str, "是谁");
    if (pos) {
        strncpy(result, str, pos - str);
        result[pos - str] = '\0';
        return 1;
    }

    pos = strstr(str, "谁是");
    if (pos) {
        strcpy(result, pos + 2);
        return 1;
    }

    pos = strstr(str, "是什么");
    if (pos) {
        strncpy(result, str, pos - str);
        result[pos - str] = '\0';
        return 1;
    }

    return -1;  // 不是问人物
}
