#pragma warning
#define USIZE 40960  //�û�����ռ���ڴ� 
#include <stdio.h>
#include <iostream>
#include <string>
#include "include/view.hpp"
#include "include/words.hpp"
#include "include/studylib.hpp"

using namespace std;

int main(void)
{
	setFontColor(0,255,255);
	printf("HiAi byHuang-Xianghan\n\n");
	printf("\033[38;2;255;255;255m");
	showIcon();
	//��ȡѧϰ����Ϣ 
	// ����̬�����ʼ��Ϊ NULL �����ظ�����
    char* stulib = (char*)malloc(sizeof(char) * 16384);
    if (stulib == NULL) {
        perror("Memory allocation failed!");
        return -1;
    }
    stulib = getLibInfo();

	
	while(1)
	{
	//��ȡ�û�����
	setFontColor(0,255,0);
	printf("YOU: ");
	
	char input[USIZE]; 
	char* user_in;
	fgets(input,sizeof(input),stdin);
	user_in = input;
	strTrim(user_in);
	
	
	
	char *name = (char*)malloc(sizeof(char)*1024);
	int i = getPersonName(user_in,name);
	if(i != -1)
	{
		
		
		
		char* info1 = (char*)malloc(sizeof(char)*8193);
		i = searchForName(stulib,name,info1);
		
		
		
		if(i != -1)
		{
			setFontColor(0,160,255);
			cout<<"Hi:"<<name<<info1<<"\n"<<endl;
		}else{
			cout<<"\033[38;2;0;160;255mHi:�Ҳ�֪������\n"<<endl;
		}
		free(info1);
	}
	else
	{
		cout<<"\033[38;2;0;160;255mHi:�Ҳ�֪������\n"<<endl;
		free(name);
	}
	}
	
	reColor();
	free(stulib);
	system("pause"); 
	return 0;
}

