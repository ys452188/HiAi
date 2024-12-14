#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getLibInfo(void)
{
    FILE* fp = fopen("lib/study.txt", "r");
    if (fp == NULL) {
        perror("\033[38;2;255;0;0m[ERROR]无法打开学习库文件!\033[0m");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);           // 将文件指针移动到末尾
    size_t fileSize = ftell(fp);      // 获取文件大小
    rewind(fp);                       // 将文件指针重新移到开头

    char* info = (char*)malloc(fileSize + 1); // 动态分配内存
    if (info == NULL) {
        perror("[ERROR] 内存分配失败！");
        fclose(fp);
        return NULL;
    }

    fread(info, sizeof(char), fileSize, fp);
    info[fileSize] = '\0'; // 确保字符串以 '\0' 结尾

    fclose(fp);
    return info;  // 返回动态分配的内存
}

//在学习库查找信息,无则返回-1 
int searchForName(const char* lib_info, const char* name, char* result) {
    // 查找 name 在 lib_info 中的位置
    const char* pos = strstr(lib_info, name);
    if (pos == NULL) {
        return -1;  // 未找到 name
    }

    // 查找 "是" 的位置，必须出现在 name 后面
    const char* shi_pos = strstr(pos, "是");
    if (shi_pos == NULL) {
        return -1;  // 未找到 "是"，无有效信息
    }

    // 提取从 "是" 开始的信息
    const char* info_start = shi_pos;
    const char* info_end = strstr(info_start, ">)]}"); // 查找结束标志
    if (info_end == NULL) {
        return -1;  // 无合法结束标志
    }

    // 计算具体信息的长度并复制到 result 中
    size_t info_length = info_end - info_start; // 计算长度
    strncpy(result, info_start, info_length);
    result[info_length] = '\0'; // 添加字符串结束符

    return 1;  // 查找成功
}

