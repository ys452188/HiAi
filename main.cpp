#pragma waring
#define USIZE 40960  //用户输入占用内存 
#include <stdio.h>
#include <iostream>
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
	//获取学习库信息 
	char* stulib=(char*)malloc(sizeof(char)*16384);
	stulib=getLibInfo();
	
	while(1)
	{
	//获取用户输入
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
			cout<<"\033[38;2;0;160;255mHi:我不知道啊。\n"<<endl;
		}
		free(info1);
	}
	else
	{
		cout<<"\033[38;2;0;160;255mHi:我不知道啊。\n"<<endl;
		free(name);
	}
	}
	
	reColor();
	free(stulib);
	system("pause"); 
	return 0;
}

