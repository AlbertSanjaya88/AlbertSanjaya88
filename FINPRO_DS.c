//Final Project DS

#include <malloc.h>
#include <stdio.h>
#include <string.h>

//size yang dipakai saat display dan untuk menentukan elemen paling terakhir
int size = 0;

//Declare FILE
FILE *fp;

struct Schedule{
	char TASK_NAME[51];
	int DEADLINE_DATE;
	int DEADLINE_MONTH;
	int DEADLINE_YEAR;
	int VALUE_PRIORITY;
};
struct Schedule Sch[100];


//function untuk menukar dua elemen
void swap(struct Schedule Sch[10], int c, int d)
{
  	char temp_TASK_NAME[51];
	strcpy(temp_TASK_NAME, Sch[d].TASK_NAME);
  	strcpy(Sch[d].TASK_NAME, Sch[c].TASK_NAME);
  	strcpy(Sch[c].TASK_NAME, temp_TASK_NAME);
  	
	int temp_DEADLINE_DATE = Sch[d].DEADLINE_DATE;
	Sch[d].DEADLINE_DATE = Sch[c].DEADLINE_DATE;
	Sch[c].DEADLINE_DATE = temp_DEADLINE_DATE;
	
	int temp_DEADLINE_MONTH = Sch[d].DEADLINE_MONTH;
	Sch[d].DEADLINE_MONTH = Sch[c].DEADLINE_MONTH;
	Sch[c].DEADLINE_MONTH = temp_DEADLINE_MONTH;
	
	int temp_DEADLINE_YEAR = Sch[d].DEADLINE_YEAR;
	Sch[d].DEADLINE_YEAR = Sch[c].DEADLINE_YEAR;
	Sch[c].DEADLINE_YEAR = temp_DEADLINE_YEAR;
	
	int temp_VALUE_PRIORITY = Sch[d].VALUE_PRIORITY;
	Sch[d].VALUE_PRIORITY = Sch[c].VALUE_PRIORITY;
	Sch[c].VALUE_PRIORITY = temp_VALUE_PRIORITY;
	
}

void sort_date(struct Schedule Sch[10], int size){
	int smallest;
	
	//sort the date
	for(int i = 0; i < size-1; i++){
		smallest=i;
		for(int j = i+1; j < size; j++){
			if(Sch[j].DEADLINE_DATE < Sch[smallest].DEADLINE_DATE){
				smallest = j;
			}
			else{
				continue;
			}
				
			if(smallest != i){
				swap(Sch, i, smallest);
			}
		}
	}
	
	//sort the month
	for(int i = 0; i < size-1; i++){
		smallest=i;
		for(int j = i+1; j < size; j++){
			if(Sch[j].DEADLINE_MONTH < Sch[smallest].DEADLINE_YEAR){
				smallest = j;
			}
			else{
				continue;
			}
				
			if(smallest != i){
				swap(Sch, i, smallest);
			}
		}
	}
	
	//sort the year
	for(int i = 0; i < size-1; i++){
		smallest=i;
		for(int j = i+1; j < size; j++){
			if(Sch[j].DEADLINE_YEAR < Sch[smallest].DEADLINE_YEAR){
				smallest = j;
			}
			else{
				continue;
			}
				
			if(smallest != i){
				swap(Sch, i, smallest);
			}
		}
	}	
}


//function heapify
void heapify(struct Schedule Sch[10], int size, int i)
{
  	if (size == 1){
	}
	
  	else
  	{
	    int largest = i;
	    int l = 2 * i + 1;
	    int r = 2 * i + 2;
	    if (l < size && Sch[l].VALUE_PRIORITY > Sch[largest].VALUE_PRIORITY)
	      	largest = l;
	    if (r < size && Sch[r].VALUE_PRIORITY > Sch[largest].VALUE_PRIORITY)
	      	largest = r;
	    if (largest != i)
	    {
	    	swap(Sch, i, largest);
	      	heapify(Sch, size, largest);
		}
	}
}

//function untuk insert elemen baru
void insert(struct Schedule Sch[10],char newName[51], int newDate, int newMonth, int newYear, int newNum)
{
	if(size<101){
		strcpy(Sch[size].TASK_NAME, newName);
		Sch[size].DEADLINE_DATE = newDate;
		Sch[size].DEADLINE_MONTH = newMonth;
		Sch[size].DEADLINE_YEAR = newYear;
		Sch[size].VALUE_PRIORITY = newNum;
		
		if (size == 0)
		{
			size += 1;
		}
		else
		{
		    size += 1;
		    for (int i = size / 2 - 1; i >= 0; i--)
		    {
		      	heapify(Sch, size, i);
		    }
		}
		fp = fopen("VeryImportantSchedule.txt","r+");
		for(int i = 0; i < size; i++){
			if(i == 0){
				fprintf(fp,"%d;%d/%d/%d;%s;",Sch[i].VALUE_PRIORITY,Sch[i].DEADLINE_DATE,Sch[i].DEADLINE_MONTH,Sch[i].DEADLINE_YEAR,Sch[i].TASK_NAME);
			}
			else{
				fprintf(fp,"\n%d;%d/%d/%d;%s;",Sch[i].VALUE_PRIORITY,Sch[i].DEADLINE_DATE,Sch[i].DEADLINE_MONTH,Sch[i].DEADLINE_YEAR,Sch[i].TASK_NAME);
			}
		}
		fclose(fp);
	}
	else{
		printf("\nList is Full\n");
	}
}

//function untuk menghapus root
void deleteRoot(struct Schedule Sch[10])
{	
	if(size>0){
		swap(Sch, 0, size-1);
		size -= 1;
		for (int i = size / 2 - 1; i >= 0; i--)
		{
		    heapify(Sch, size, i);
		}
		
		fp = fopen("VeryImportantSchedule.txt","w");
		for(int i = 0; i < size; i++){
			if(i == 0){
				fprintf(fp,"%d;%d/%d/%d;%s;",Sch[i].VALUE_PRIORITY,Sch[i].DEADLINE_DATE,Sch[i].DEADLINE_MONTH,Sch[i].DEADLINE_YEAR,Sch[i].TASK_NAME);
			}
			else{
				fprintf(fp,"\n%d;%d/%d/%d;%s;",Sch[i].VALUE_PRIORITY,Sch[i].DEADLINE_DATE,Sch[i].DEADLINE_MONTH,Sch[i].DEADLINE_YEAR,Sch[i].TASK_NAME);
			}
		}
		fclose(fp);
	}
	
	else{
		printf("It's Empty, Your works are all done\n");
	}
}

//function untuk print MAX HEAP
void printArray(struct Schedule Sch[10], int size)
{
  	for(int i=0; i<80; i++){
  		printf ("-");
  	}
  	printf("\n");
  	printf(" %-51s | %-10s | %s\n","Task Name","Due Date","Priority Level");
  	for(int i=0; i<80; i++){
  		printf ("-");
  	}
  	printf("\n");
  	
  	for (int i = 0; i < size; i++){
  		printf(" %-51s | %02d/%02d/%04d | %d\n",Sch[i].TASK_NAME, Sch[i].DEADLINE_DATE, Sch[i].DEADLINE_MONTH, Sch[i].DEADLINE_YEAR, Sch[i].VALUE_PRIORITY);
	}
	for(int i=0; i<80; i++){
  		printf ("-");
  	}
  	printf("\n");
}

// Main Display
int main(){

	int menu;
	char Nama_Tugas[51];
	int Tanggal_DL;
	int Bulan_DL;
	int Tahun_DL;
	int Priority_Value;
	
	do{
		size = 0;
		fp = fopen("VeryImportantSchedule.txt","r+");
		while(fscanf(fp,"%d;%d/%d/%d;%[^';'];",&Sch[size].VALUE_PRIORITY,&Sch[size].DEADLINE_DATE,&Sch[size].DEADLINE_MONTH,&Sch[size].DEADLINE_YEAR,Sch[size].TASK_NAME)!=EOF)
		{
			size++; 
		}
		fclose(fp);
		
		printf("size:%d\n",size);
		printf("=== === === === === === ===\n");
		printf("PriSche (Priority Scheduler)\n\n");
		printf("1. Add new Schedule\n");
		printf("2. View All Schedule\n");
		printf("3. Remove Topmost Schedule\n");
		printf("4. Exit Program\n");
		printf("=== === === === === === ===\n");
		printf(">>");
		scanf("%d",&menu);
		
		
		switch(menu){
				case 1:
				
					printf("Input Nama Kegiatan / Tugas [50 char]:");
					scanf(" %[^\n]s",&Nama_Tugas);
					printf("Input Tanggal Deadline [DD/MM/YYYY]:");
					scanf("%d/%d/%d",&Tanggal_DL,&Bulan_DL,&Tahun_DL);
					printf("Input Bobot Prioritas (1-100) [ 1 tidak penting, 100 paling penting ]:");
					scanf("%d",&Priority_Value);
					
					insert(Sch,Nama_Tugas, Tanggal_DL, Bulan_DL, Tahun_DL, Priority_Value);
					
					printf("Insert Success\n");
					printf("Press any key to continue\n");
					getch();
					system("cls");
					break;
				
				case 2:
					sort_date(Sch, size);
					printArray(Sch, size);
					printf("Press any key to continue\n");
					getch();
					system("cls");
					break;
				
				case 3:
					deleteRoot(Sch);
					printf("Delete Success\n");	
					printf("Press any key to continue\n");
					getch();
					system("cls");
					break;
				
				case 4:
					return 0;
					break;
		}
	}while(menu != 4);
}
