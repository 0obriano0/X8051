#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>

char linkfile[3][50] = {"x8051.exe","link4.exe","download.exe"};
char filenamebyload[3][50] = {".asm",".obj",".tsk"};


int main(){
	char filename[100];
	char checkfile[100] = "";
	FILE *pf;
	do{
		if(pf == NULL)
			fclose(pf);
		std::cout << "請輸入檔案名稱(不含副檔名):";
		scanf("%s",&filename);
		strcat(checkfile,filename);
		strcat(checkfile,filenamebyload[0]);
		pf = fopen(checkfile,"r");
		if(pf == NULL){
			system("cls");
			std::cout << "找不到 " << checkfile << " 檔案請確認檔名是否正確" << std::endl;
			checkfile[0] = '\0';
		} 
	}while(pf == NULL);
	fclose(pf);
	
	
	for(int loopnum1 = 0 ; loopnum1 < 3; loopnum1++){
		char buffer[100] = "";
		strcat(buffer,linkfile[loopnum1]);
		strcat(buffer," ");
		if(loopnum1 != 1){
			strcat(buffer,filename);
			strcat(buffer,filenamebyload[loopnum1]);
		}else{
			Sleep(1500);
			FILE *pf2;
			pf2 = fopen("2.txt","w");
			
			if(pf2 != NULL){
				fprintf(pf2,"%s%s\n\n\n\nX\nX\nX",filename,filenamebyload[loopnum1]);
				fclose(pf2);
			}
			strcat(buffer,"< 2.txt");
		}
		printf("%s\n",buffer);
		system(buffer);
	}
	
	system("pause");
	return 0;
} 
