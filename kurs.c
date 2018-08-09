#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
//Генерирование карты движения
void Array_gen(int A[][12]){
	for(int j=0;j<12;j++){
		for(int i=0;i<5;i++){
			A[i][j]=rand()%2;	
			}
		if(A[0][j]==1&&A[1][j]==1&&A[2][j]==1)
		j--;
		if(A[0][j]==1&&A[1][j]==1&&A[2][j]==0&&A[0][j-1]==0&&A[1][j-1]==1&&A[2][j-1]==1)
		j--;
		if(A[0][j]==0&&A[1][j]==1&&A[2][j]==1&&A[0][j-1]==1&&A[1][j-1]==1&&A[2][j-1]==0)
		j--;
		if(A[0][j]==1&&A[1][j]==1&&A[2][j]==0&&A[0][j-2]==0&&A[1][j-2]==1&&A[2][j-2]==1)
		j--;
		if(A[0][j]==0&&A[1][j]==1&&A[2][j]==1&&A[0][j-2]==1&&A[1][j-2]==1&&A[2][j-2]==0)
		j--;
		}
	}
	
//Вывод карты на экран
void Printf_Array(int A[][12]){
	for(int j=0;j<10;j++){
		printf("%d   ",j);
		for(int i=0;i<3;i++){
			printf("%2d",A[i][j]);
			}
		printf("\n");
		}
	}
	
//Запись карты в файл kurs1.txt
void Printf_FILE_Array(int A[][12]){
	FILE *f;
	f=fopen("kurs1.dat","ab");
	fprintf(f,"\n");
	for(int j=0;j<10;j++){
		for(int i=0;i<3;i++){
			fprintf(f,"%2d",A[i][j]);
			}
		fprintf(f,"\n");
		}
	fclose(f);	
	}
	
//Поиск пути до финиша
void Array_way(int A[5][12],char B[]){
	memset(B,0,sizeof(B));
	int number[5][12],k,G[11];
	 for(int j=0;j<12;j++){
		for(int i=0;i<5;i++){
		number[i][j]=5;
		}
	 }	
	 for(int j=0;j<12;j++){
		  for(int i=0;i<5;i++){
		  if(A[i][j]==0)
		  number[i][j]=i;
		  }
	 }
	 for(int j=0;j<12;j++){
		  for(int m=0;m<2;m++){
			for(int i=0;i<2-m;i++){
			if(number[i][j]>number[i+1][j]){
				k=number[i][j];
				number[i][j]=number[i+1][j];
				number[i+1][j]=k;
				}
			}	
		  }
	 } 
	 G[0]=1;
	 for(int j=0;j<10;j++){
		  for(int i=0;i<3;i++){
			  if(i==0&&number[i][j]!=5&&abs(number[i][j]-number[i][j+1])<2&&abs(G[j]-number[i][j])<2){
				  if(abs(number[i][j+1]-number[i][j+2])<2||abs(number[i][j+1]-number[i+1][j+2])<2)
				  G[j+1]=number[i][j];
				  }
			  if(i==0&&number[i][j]!=5&&abs(number[i][j]-number[i+1][j+1])<2&&abs(G[j]-number[i][j])<2){
				  if(abs(number[i+1][j+1]-number[i][j+2])<2||abs(number[i+1][j+1]-number[i+1][j+2])<2||abs(number[i+1][j+1]-number[i+2][j+2])<2)
				  G[j+1]=number[i][j];
				  }
			  if(i==1&&number[i][j]!=5&&abs(number[i][j]-number[i-1][j+1])<2&&abs(G[j]-number[i][j])<2){
				  if(abs(number[i-1][j+1]-number[i-1][j+2])<2||abs(number[i-1][j+1]-number[i][j+2])<2)
				  G[j+1]=number[i][j];
				  }   
			  if(i==1&&number[i][j]!=5&&abs(number[i][j]-number[i][j+1])<2&&abs(G[j]-number[i][j])<2){
				  if(abs(number[i][j+1]-number[i-1][j+2])<2||abs(number[i][j+1]-number[i][j+2])<2||abs(number[i][j+1]-number[i+1][j+2])<2)
				  G[j+1]=number[i][j];
				  }  
			  if(i==1&&number[i][j]!=5&&abs(number[i][j]-number[i+1][j+1])<2&&abs(G[j]-number[i][j])<2){
				  if(abs(number[i+1][j+1]-number[i][j+2])<2||abs(number[i+1][j+1]-number[i+1][j+2])<2)
				  G[j+1]=number[i][j];
				  }  
			  if(i==2&&number[i][j]!=5&&abs(number[i][j]-number[i-1][j+1])<2&&abs(G[j]-number[i][j])<2){
				  if(abs(number[i-1][j+1]-number[i-2][j+2])<2||abs(number[i-1][j+1]-number[i-1][j+2])<2||abs(number[i-1][j+1]-number[i][j+2])<2)
				  G[j+1]=number[i][j];
				  }
			  if(i==2&&number[i][j]!=5&&abs(number[i][j]-number[i][j+1])<2&&abs(G[j]-number[i][j])<2){
				  if(abs(number[i][j+1]-number[i-1][j+2])<2||abs(number[i][j+1]-number[i][j+2])<2)
				  G[j+1]=number[i][j];
				  }	  	   
		  }
	 }
	for(int j=1;j<10;j++){
		if(G[j+1]>G[j]){
			strcat(B,"R");
			}
		if(G[j+1]<G[j]){
			strcat(B,"L");
			}	
		if(G[j+1]==G[j]) 
			strcat(B,"E");
		}
	}
	
//Запись найденного пути в компактной форме и вывод на экран
void WAY(char A[],char B[]){
	memset(B,0,sizeof(B));
	int number = 1;
	char Number_[10];
	strncpy(B,A,1);
	for(int i=0;i<9;i++){
		memset(Number_,0,sizeof(Number_));
		if(A[i+1]==A[i])
		number++;
		else {
			if(number<10){
				Number_[0]=number + '0';
				Number_[1]='\0';
				number=1;
				strcat(B,Number_);
				Number_[0]=A[i+1];
				strcat(B,Number_);
				}
			else {
				Number_[0]=number/10+'0';
				number=number%10;
				Number_[1]=number+'0';
				number=1;
				strcat(B,Number_);
				Number_[0]=A[i+1];
				strcat(B,Number_);
				}	
			}
		}
		printf("%s\n",B);
	}
	
//Запись результата в файл	
void Printf_WAY(char Way_[]){
	FILE *f;
	f=fopen("kurs1.dat","ab");
	fprintf(f,"\n");
	fprintf(f,"%s",Way_);
	fclose(f);
	}
	
int main(void){
	int Array[5][12];
	char Way[10],Way_[10];
	int v=0;	
	while(1){
		Array_gen(Array);//формируем карту
		Printf_Array(Array);//производим вывод карты на экран
		Array_way(Array,Way);//Поиск пути до финиша
		WAY(Way,Way_);//Запись найденного пути в компактной форме и вывод на экран
		Printf_FILE_Array(Array);//Вывод карты в файл
		Printf_WAY(Way_);//Запись результата в файл	
		printf("Если хотите продолжить с новой картой нажмите 1");
		scanf("%d",&v);
		if(v!=1) break;
		memset(Way_,0,sizeof(Way_));
		}
	return 0;
	}
