#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int num; //number of rows
   //FILE *fptr, *fptr1;
   FILE *fptr;
   fptr = fopen("file.txt","w");
   // fptr1 = fopen("keys.txt","w");

   //if(fptr == NULL || fptr1 == NULL)
   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

   printf("Enter number of rows: ");
   scanf("%d",&num);
  
	//to randomly genrate characters between 0 to 255
	unsigned char charArrayK[95];
	for(int i =32; i< 127; i++){
		charArrayK[i-32] = i;
	}

/*	unsigned char charArrayV[256];
	for(int i =0; i< 256; i++){
		charArrayV[i] = i;
	}*/

	srand(time(NULL));
	for(int row = 0; row < num; row++){
		unsigned char key[10];
		for (int i =0; i<10; i++){
			int randomIndex = rand() % 95;
			key[i] = charArrayK[randomIndex];
		  fprintf(fptr,"%c",key[i]);
	//		fprintf(fptr1,"%c",key[i]);
		}
	//	fprintf(fptr1,"\n");
		
		unsigned char value[90];
		for (int i =0; i<90; i++){
			int randomIndex = rand() % 95;
			value[i] = charArrayK[randomIndex];
		  fprintf(fptr,"%c",value[i]);
		}
	}
	fclose(fptr);
	//fclose(fptr1);
   return 0;
}


