#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");
	float L = 353;
	float n = 2;
	printf("Дано:\n  %10d\n  %10d\n \t_________\nОтвет:\n\t%+08.4f",(int)n,(int)L,n/L);
	getchar();
	
	

}
