#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char * argv[]){
	int i,size,chara = 1;
	char c,*text;
	for(i = 0;i < argc;i++){
		printf("Argument n.%d is : %s\n",i,argv[i]);
	}

	FILE * fpin;
	fpin = fopen(argv[1],"r");
	if(fpin == NULL){printf("ERROR");  exit(10);}

	FILE * fpout;
	fpout = fopen(argv[3],"w");
	if(fpout == NULL){printf("ERROR"); exit(10);}

	int key;
	if(strcmp(argv[2],"-e")==0){ printf("\nencryption mode!\n"); key=1; }
	else if(strcmp(argv[2],"-d")==0){printf("\ndecryption mode!\n"); key = 2;}
	else{ printf("ERROR"); exit(10);}

	//encryption
	if(key == 1){
		while((c = fgetc(fpin)) != EOF){size++;}
		text = malloc(size * sizeof(char));
		printf("Memory that needs to be allocated : %d\n",size);
		fpin = fopen(argv[1],"r");
		i = 0;
		while((c = fgetc(fpin)) != EOF){
			text[i] = c;
			i++;
		}
		printf("Encryption completed!");
		for(i = 0;i < size;i++){
			text[i] = text[i] + 1;
			fprintf(fpout,"%c",text[i]);
		   }
		}

	if(key == 2){
		while((c = fgetc(fpin)) != EOF){size++;}
		text = malloc(size * sizeof(char));
		printf("Memory that needs to be allocated : %d\n",size);
		fpin = fopen(argv[1],"r");
		i = 0;
		while((c = fgetc(fpin)) != EOF){
			text[i] = c;
			i++;
		}
		printf("Decryption completed!\n");
		for(i = 0;i < size;i++){
			text[i] = text[i] - 1;
			fprintf(fpout,"%c",text[i]);
		   }
		}
	return 0;
}
