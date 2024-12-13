#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getLibInfo(void)
{
    FILE* fp = fopen("lib/study.txt", "r");
    if (fp == NULL) {
        perror("\033[38;2;255;0;0m[ERROR]�޷���ѧϰ���ļ�!\033[0m");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);           // ���ļ�ָ���ƶ���ĩβ
    size_t fileSize = ftell(fp);      // ��ȡ�ļ���С
    rewind(fp);                       // ���ļ�ָ�������Ƶ���ͷ

    char* info = (char*)malloc(fileSize + 1); // ��̬�����ڴ�
    if (info == NULL) {
        perror("[ERROR] �ڴ����ʧ�ܣ�");
        fclose(fp);
        return NULL;
    }

    fread(info, sizeof(char), fileSize, fp);
    info[fileSize] = '\0'; // ȷ���ַ����� '\0' ��β

    fclose(fp);
    return info;  // ���ض�̬������ڴ�
}

//��ѧϰ�������Ϣ,���򷵻�-1 
int searchForName(const char* lib_info, const char* name, char* result) {
    // ���� name �� lib_info �е�λ��
    const char* pos = strstr(lib_info, name);
    if (pos == NULL) {
        return -1;  // δ�ҵ� name
    }

    // ���� "��" ��λ�ã���������� name ����
    const char* shi_pos = strstr(pos, "��");
    if (shi_pos == NULL) {
        return -1;  // δ�ҵ� "��"������Ч��Ϣ
    }

    // ��ȡ�� "��" ��ʼ����Ϣ
    const char* info_start = shi_pos;
    const char* info_end = strstr(info_start, ">)]}"); // ���ҽ�����־
    if (info_end == NULL) {
        return -1;  // �޺Ϸ�������־
    }

    // ���������Ϣ�ĳ��Ȳ����Ƶ� result ��
    size_t info_length = info_end - info_start; // ���㳤��
    strncpy(result, info_start, info_length);
    result[info_length] = '\0'; // ����ַ���������

    return 1;  // ���ҳɹ�
}

