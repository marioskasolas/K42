#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	FILE *fpin;
	fpin = fopen(argv[1],"r");
	if(fpin == NULL) exit(10);

	FILE *fpout;
	fpout = fopen(argv[3],"w");
	if(fpout == NULL) exit(10);

	char c;
	if(strcmp(argv[2],"-e")==0){
		printf("message to be encrypted :");
		while((c = fgetc(fpin))!=EOF){
			printf("%c",c);
			fprintf(fpout,"%c",c+1);
		}
	}else if(strcmp(argv[2],"-d")==0){
		printf("message to be decrypted :");
		while((c = fgetc(fpin))!=EOF){
			printf("%c",c);
			fprintf(fpout,"%c",c-1);
		}
	}else exit(10);

	fclose(fpin);
	fclose(fpout);
}
