#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>


int main()
{
	setlocale(LC_CTYPE, "RUS");
	float L = 353;
	float n = 2;
	printf("����:\n\t%.f\n\t%.f\n____________\n�����:\n\t+%d%.4f",n,L,(int)n/(int)L,n/L);
	

}
