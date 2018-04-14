#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>

char linkfile[3][50] = {"x8051.exe","link4.exe","download.exe"};
char filenamebyload[3][50] = {".asm",".obj",".tsk"};


int main(){
	char filename[100];
	std::cout << "請輸入檔案名稱(不含副檔名):"; 
	scanf("%s",&filename);
	
	for(int loopnum1 = 0 ; loopnum1 < 3; loopnum1++){
		char buffer[100] = "";
		strcat(buffer,linkfile[loopnum1]);
		strcat(buffer," ");
		if(loopnum1 != 1){
			strcat(buffer,filename);
			strcat(buffer,filenamebyload[loopnum1]);
		}else{
			Sleep(1500);
			FILE *pf;
			pf = fopen("2.txt","w");
			
			if(pf != NULL){
				fprintf(pf,"%s%s\n\n\n\n\nX\nX",filename,filenamebyload[loopnum1]);
				fclose(pf);
			}
			strcat(buffer,"< 2.txt");
		}
		printf("%s\n",buffer);
		system(buffer);
	}
	
	system("pause");
	return 0;
} 
