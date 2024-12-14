#pragma once
#include <cstdio>
#include <string.h>

void setFontColor(int r,int g,int b)
{
	printf("\033[38;2;%d;%d;%dm",r,g,b);
}

void reColor(void)
{
	printf("\033[0m");
}

void showIcon(void)
{
	setFontColor(0,160,255);
	printf("	***************************\n");
	printf("	*   MM       MM           *\n");
	printf("	*   MM       MM           *\n");
	printf("	*   MM       MM           *\n");
	printf("	*   MM       MM      M    *\n");
	printf("	*   MMMMMMMMMMM     MMM   *\n");
	printf("	*   MM       MM      M    *\n");
	printf("	*   MM       MM      M    *\n");
	printf("	*   MM       MM      M    *\n");
	printf("	*   MM       MM      M    *\n");
	printf("	***************************\n\n\n");
	reColor();
}

void hxh_output(const char* args)
{
	printf("\033[38;2;0;160;255");
	for(int i=0;i<strlen(args);i++)
	{
		printf("%c",args[i]);
	}
	
}
