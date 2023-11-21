#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Sales{
	int entry;
	char PurchaseDate[4];
	char PurchaseMonth[4];
    char PurchaseYear[6];
	char Name[50];
    char BookType[50];
    char BookName[50];
    int BookQuant;
    int BookPrice;
    int TotalPurchase; 
};

void swap(struct Sales *sls1,struct Sales *sls2){
	struct Sales temp;
	
	strcpy(temp.PurchaseDate,sls1->PurchaseDate);
	strcpy(temp.PurchaseMonth,sls1->PurchaseMonth);
	strcpy(temp.PurchaseYear,sls1->PurchaseYear);
	strcpy(temp.Name,sls1->Name);
	strcpy(temp.BookType,sls1->BookType);
	strcpy(temp.BookName,sls1->BookName);
	temp.BookQuant = sls1->BookQuant;
	temp.BookPrice = sls1->BookPrice;
	temp.TotalPurchase = sls1->TotalPurchase;
	
	strcpy(sls1->PurchaseDate,sls2->PurchaseDate);
	strcpy(sls1->PurchaseMonth,sls2->PurchaseMonth);
	strcpy(sls1->PurchaseYear,sls2->PurchaseYear);
	strcpy(sls1->Name,sls2->Name);
	strcpy(sls1->BookType,sls2->BookType);
	strcpy(sls1->BookName,sls2->BookName);
	sls1->BookQuant = sls2->BookQuant;
	sls1->BookPrice = sls2->BookPrice;
	sls1->TotalPurchase = sls2->TotalPurchase;
	
	strcpy(sls2->PurchaseDate,temp.PurchaseDate);
	strcpy(sls2->PurchaseMonth,temp.PurchaseMonth);
	strcpy(sls2->PurchaseYear,temp.PurchaseYear);
	strcpy(sls2->Name,temp.Name);
	strcpy(sls2->BookType,temp.BookType);
	strcpy(sls2->BookName,temp.BookName);
	sls2->BookQuant = temp.BookQuant;
	sls2->BookPrice = temp.BookPrice;
	sls2->TotalPurchase = temp.TotalPurchase;
}
void sortingPurchaseDate(struct Sales sls[],int n)
{
    for(int i=0; i<n ; i++)
		for(int j=0; j<=n-i ; j++)
	  		if(strcasecmp(sls[j].PurchaseDate,sls[j+1].PurchaseDate)>0)
	  		{ 
       	   	swap(&sls[j],&sls[j+1]);
	 		}
}
void sortingPurchaseMonth(struct Sales sls[],int n)
{
    for(int i=0; i<n ; i++)
		for(int j=0; j<=n-i ; j++)
	  		if(strcasecmp(sls[j].PurchaseMonth,sls[j+1].PurchaseMonth)>0)
	  		{ 
       	   	swap(&sls[j],&sls[j+1]);
	 		}
}
void sortingPurchaseYear(struct Sales sls[],int n)
{
    for(int i=0; i<n ; i++)
		for(int j=0; j<=n-i ; j++)
	  		if(strcasecmp(sls[j].PurchaseYear,sls[j+1].PurchaseYear)>0)
	  		{ 
       	   	swap(&sls[j],&sls[j+1]);
	 		}
}

void sortingName(struct Sales sls[],int n)
{
    for(int i=0; i<n ; i++)
		for(int j=0; j<=n-i ; j++)
	  		if(strcasecmp(sls[j].Name,sls[j+1].Name)==0)
	  		{ 
       	   	swap(&sls[j],&sls[j+1]);
	 		}
}
void sortingBookName(struct Sales sls[],int n)
{
    for(int i=0; i<n ; i++)
		for(int j=0; j<=n-i ; j++)
	  		if(strcasecmp(sls[j].BookName,sls[j+1].BookName)>0)
	  		{ 
       	   	swap(&sls[j],&sls[j+1]);
	 		}
}
void sortingBookType(struct Sales sls[],int n)
{
    for(int i=0; i<n ; i++)
		for(int j=0; j<=n-i ; j++)
	  		if(strcasecmp(sls[j].BookType,sls[j+1].BookType)>0)
	  		{ 
       	   	swap(&sls[j],&sls[j+1]);
	 		}
}
void sortingBookQuant(struct Sales sls[],int n)
{
    for(int i=0; i<n ; i++)
		for(int j=0; j<=n-i ; j++)
	  		if(sls[j].BookQuant>sls[j+1].BookQuant)
	  		{ 
       	   	swap(&sls[j],&sls[j+1]);
	 		}
}
void sortingBookPrice(struct Sales sls[],int n)
{
    for(int i=0; i<n ; i++)
		for(int j=0; j<=n-i ; j++)
	  		if(sls[j].BookPrice>sls[j+1].BookPrice)
	  		{ 
       	   	swap(&sls[j],&sls[j+1]);
	 		}
}
void sortingTotalPurchase(struct Sales sls[],int n)
{
    for(int i=0; i<n ; i++)
		for(int j=0; j<=n-i ; j++)
	  		if(sls[j].TotalPurchase>sls[j+1].TotalPurchase)
	  		{ 
       	   	swap(&sls[j],&sls[j+1]);
	 		}
}

void cariTanggal(){
    FILE *fp;
    char cTanggal[4];
    char cBulan[4];
    char cTahun[6];
    int i, found = 0;
    int data=0;
    struct Sales sls[100];
    fp = fopen("sales.txt","r+");
    printf("Masukkan tanggal pembelian (DD) untuk mencari record data: ");
    scanf("%s",cTanggal);
    printf("\nMasukkan bulan pembelian (MM) untuk mencari record data: ");
    scanf("%s",cBulan);
    printf("\nMasukkan tahun pembelian (YYYY) untuk mencari record data: ");
    scanf("%s",cTahun);
    while(fscanf (fp, "%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[data].PurchaseDate, sls[data].PurchaseMonth, sls[data].PurchaseYear, sls[data].Name, sls[data].BookType, sls[data].BookName, &sls[data].BookQuant, &sls[data].BookPrice, &sls[data].TotalPurchase) != EOF){
        data++;
    }

    {
        for (i=0 ; i<data ;i++){
		if(memcmp(sls[i].PurchaseDate,cTanggal,3)==0){
            if(memcmp(sls[i].PurchaseMonth,cBulan,3)==0){
            	if(memcmp(sls[i].PurchaseYear,cTahun,5)==0){
					found = i;
		            printf("\n========================================================\n");
		            printf("Nama Pembeli\t: %s\n", sls[found].Name);
		            printf("--------------------------------------------------------\n");
		            printf("Jenis Buku\t: %s\n", sls[found].BookType);
		            printf("Nama Buku\t: %s\n", sls[found].BookName);
		            printf("Jumlah Buku\t: %d\n", sls[found].BookQuant);
		            printf("Harga Buku\t: %d\n", sls[found].BookPrice);
		            printf("Total Pembelian\t: %d\n", sls[found].TotalPurchase);
		            printf("========================================================\n");
				}
			}
    	}
    } if (found==0);
        printf("Data tidak ditemukan\n");
        }
    fclose(fp);
}

void cariTotalPembelian(){
    FILE *fp;
    int total;
    int i, found = 0;
    int data=0;
    struct Sales sls[100];
    fp = fopen("sales.txt","r+");
    printf("Masukkan total pembelian untuk mencari record data: ");
    scanf("%d",&total);
    while(fscanf (fp, "%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[data].PurchaseDate, sls[data].PurchaseMonth, sls[data].PurchaseYear, sls[data].Name, sls[data].BookType, sls[data].BookName, &sls[data].BookQuant, &sls[data].BookPrice, &sls[data].TotalPurchase) != EOF){
        data++;
    }
        for (i=0 ; i<data ;i++){
			if(sls[i].TotalPurchase==total){
					found = i;
		            printf("\n========================================================\n");
		            printf("Nama Pembeli\t: %s\n", sls[found].Name);
		            printf("--------------------------------------------------------\n");
		            printf("Tanggal Pembelian: %s/%s/%s/\n", sls[found].PurchaseDate,sls[found].PurchaseMonth,sls[found].PurchaseYear);
		            printf("Jenis Buku\t: %s\n", sls[found].BookType);
		            printf("Nama Buku\t: %s\n", sls[found].BookName);
		            printf("Jumlah Buku\t: %d\n", sls[found].BookQuant);
		            printf("Harga Buku\t: %d\n", sls[found].BookPrice);
		            printf("========================================================\n");
    		}
    	} 
	if (found==0){
        printf("Data tidak ditemukan\n");
	}
    fclose(fp);
}
void cariNamaPembeli(){
    FILE *fp;
    char nama[50];
    int i, found = 0;
    int data=0;
    struct Sales sls[100];
    fp = fopen("sales.txt","r+");
    printf("Masukkan nama pembeli untuk mencari record data: ");
    getchar();
    scanf("%[^\'/n']s",&nama);
    while(fscanf (fp, "%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[data].PurchaseDate, sls[data].PurchaseMonth, sls[data].PurchaseYear, sls[data].Name, sls[data].BookType, sls[data].BookName, &sls[data].BookQuant, &sls[data].BookPrice, &sls[data].TotalPurchase) != EOF){
        data++;
    }
    {
        for (i=0 ; i<data ;i++){
		if(memcmp(sls[i].BookName,nama,5)==0){
					found = i;
		            printf("\n========================================================\n");
		            printf("Tanggal Pembelian: %s/%s/%s/\n", sls[found].PurchaseDate,sls[found].PurchaseMonth,sls[found].PurchaseYear);
		            printf("--------------------------------------------------------\n");
		            printf("Jenis Buku\t: %s\n", sls[found].BookType);
		            printf("Nama Buku\t: %s\n", sls[found].BookName);
		            printf("Jumlah Buku\t: %d\n", sls[found].BookQuant);
		            printf("Harga Buku\t: %d\n", sls[found].BookPrice);
		            printf("Total Pembelian\t: %d\n", sls[found].TotalPurchase);
		            printf("========================================================\n");
    	}
    } if (found==0);
        printf("Data tidak ditemukan\n");
        }
    fclose(fp);
}

void cariJenisBuku(){
    FILE *fp;
    char buku[50];
    int i, found = 0;
    int data=0;
    struct Sales sls[100];
    fp = fopen("sales.txt","r+");
    printf("Masukkan jenis buku yang dibeli untuk mencari record data: ");
    getchar();
    scanf("%[^\'/n']s",&buku);
    while(fscanf (fp, "%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[data].PurchaseDate, sls[data].PurchaseMonth, sls[data].PurchaseYear, sls[data].Name, sls[data].BookType, sls[data].BookName, &sls[data].BookQuant, &sls[data].BookPrice, &sls[data].TotalPurchase) != EOF){
        data++;
    }
    {
        for (i=0 ; i<data ;i++){
		if(memcmp(sls[i].BookType,buku,5)==0){
					found = i;
		            printf("\n========================================================\n");
		            printf("Nama Pembeli\t: %s\n", sls[found].Name);
		            printf("--------------------------------------------------------\n");
		            printf("Tanggal Pembelian: %s/%s/%s/\n", sls[found].PurchaseDate,sls[found].PurchaseMonth,sls[found].PurchaseYear);
		            printf("Nama Buku\t: %s\n", sls[found].BookName);
		            printf("Jumlah Buku\t: %d\n", sls[found].BookQuant);
		            printf("Harga Buku\t: %d\n", sls[found].BookPrice);
		            printf("Total Pembelian\t: %d\n", sls[found].TotalPurchase);
		            printf("========================================================\n");
    	}
    } if (found==0);
        printf("Data tidak ditemukan\n");
        }
    fclose(fp);
}


void cariNamaBuku(){
    FILE *fp;
    char buku[50];
    int i, found = 0;
    int data=0;
    struct Sales sls[100];
    fp = fopen("sales.txt","r+");
    printf("Masukkan nama buku yang dibeli untuk mencari record data: ");
    getchar();
    scanf("%[^\'/n']s",&buku);
    while(fscanf (fp, "%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[data].PurchaseDate, sls[data].PurchaseMonth, sls[data].PurchaseYear, sls[data].Name, sls[data].BookType, sls[data].BookName, &sls[data].BookQuant, &sls[data].BookPrice, &sls[data].TotalPurchase) != EOF){
        data++;
    }
    {
        for (i=0 ; i<data ;i++){
		if(memcmp(sls[i].BookName,buku,5)==0){
					found = i;
		            printf("\n========================================================\n");
		            printf("Nama Pembeli\t: %s\n", sls[found].Name);
		            printf("--------------------------------------------------------\n");
		            printf("Tanggal Pembelian: %s/%s/%s/\n", sls[found].PurchaseDate,sls[found].PurchaseMonth,sls[found].PurchaseYear);
		            printf("Jenis Buku\t: %s\n", sls[found].BookType);
		            printf("Jumlah Buku\t: %d\n", sls[found].BookQuant);
		            printf("Harga Buku\t: %d\n", sls[found].BookPrice);
		            printf("Total Pembelian\t: %d\n", sls[found].TotalPurchase);
		            printf("========================================================\n");
    	}
    } if (found==0);
        printf("Data tidak ditemukan\n");
        }
    fclose(fp);
}


void cariJumlahBuku(){
    FILE *fp;
    int jumlah;
    int i, found = 0;
    int data=0;
    struct Sales sls[100];
    fp = fopen("sales.txt","r+");
    printf("Masukkan jumlah buku yang dibeli untuk mencari record data: ");
    scanf("%d",&jumlah);
    while(fscanf (fp, "%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[data].PurchaseDate, sls[data].PurchaseMonth, sls[data].PurchaseYear, sls[data].Name, sls[data].BookType, sls[data].BookName, &sls[data].BookQuant, &sls[data].BookPrice, &sls[data].TotalPurchase) != EOF){
        data++;
    }
        for (i=0 ; i<data ;i++){
		if(sls[i].BookQuant==jumlah){
					found = i;
		            printf("\n========================================================\n");
		            printf("Nama Pembeli\t: %s\n", sls[found].Name);
		            printf("--------------------------------------------------------\n");
		            printf("Tanggal Pembelian: %s/%s/%s/\n", sls[found].PurchaseDate,sls[found].PurchaseMonth,sls[found].PurchaseYear);
		            printf("Jenis Buku\t: %s\n", sls[found].BookType);
		            printf("Nama Buku\t: %s\n", sls[found].BookName);
		            printf("Harga Buku\t: %d\n", sls[found].BookPrice);
		            printf("Total Pembelian\t: %d\n", sls[found].TotalPurchase);
		            printf("========================================================\n");
    	}
    } if (found==0);
        printf("Data tidak ditemukan\n");
    fclose(fp);
}

void cariHargaBuku(){
    FILE *fp;
    int harga;
    int i, found = 0;
    int data=0;
    struct Sales sls[100];
    fp = fopen("sales.txt","r+");
    printf("Masukkan harga buku yang dibeli untuk mencari record data: ");
    scanf("%d",&harga);
    while(fscanf (fp, "%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[data].PurchaseDate, sls[data].PurchaseMonth, sls[data].PurchaseYear, sls[data].Name, sls[data].BookType, sls[data].BookName, &sls[data].BookQuant, &sls[data].BookPrice, &sls[data].TotalPurchase) != EOF){
        data++;
    }
    {
        for (i=0 ; i<data ;i++){
		if(sls[i].BookPrice==harga){
					found = i;
		            printf("\n========================================================\n");
		            printf("Nama Pembeli\t: %s\n", sls[found].Name);
		            printf("--------------------------------------------------------\n");
		            printf("Tanggal Pembelian: %s/%s/%s/\n", sls[found].PurchaseDate,sls[found].PurchaseMonth,sls[found].PurchaseYear);
		            printf("Jenis Buku\t: %s\n", sls[found].BookType);
		            printf("Nama Buku\t: %s\n", sls[found].BookName);
		            printf("Jumlah Buku\t: %d\n", sls[found].BookQuant);
		            printf("Total Pembelian\t: %d\n", sls[found].TotalPurchase);
		            printf("========================================================\n");
    	}
    } if (found==0);
        printf("Data tidak ditemukan\n");
        }
    fclose(fp);
}

int main(){
	printf("\t\t========================================\n\n");
    char c;
    int count = 1;
    int data=0;
    FILE *fp;
    
    fp = fopen("sales.txt","r+");
//    for(c = getc(fp); c != EOF; c = getc(fp)){
//        if(c == '\n')
//            count = count + 1;
//    }
//    fclose(fp);
    
    struct Sales sls[10000];
    struct Sales newsales[100];

//	fp = fopen("sales.txt","a+");
//	while(fscanf (fp, "%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[data].PurchaseDate, sls[data].PurchaseMonth, sls[data].PurchaseYear, sls[data].Name, sls[data].BookType, sls[data].BookName, &sls[data].BookQuant, &sls[data].BookPrice, &sls[data].TotalPurchase) != EOF){
//        data++;
//    }
    for(int i = 0; i<data; i++){
		fscanf(fp,"%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[i].PurchaseDate, sls[i].PurchaseMonth, sls[i].PurchaseYear, sls[i].Name, sls[i].BookType, sls[i].BookName, &sls[i].BookQuant, &sls[i].BookPrice, &sls[i].TotalPurchase)!=EOF;
	}
    fclose(fp);
	printf("count\t= %d\n",count);
    printf("data\t= %d\n",data);
    
    for(int i = 0; i<data; i++){
		printf("%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", sls[i].PurchaseDate, sls[i].PurchaseMonth, sls[i].PurchaseYear, sls[i].Name, sls[i].BookType, sls[i].BookName, sls[i].BookQuant, sls[i].BookPrice, sls[i].TotalPurchase);
	}
	
	int boole;
	int menu;
	
	do{
	    printf("\n\n");
	    printf("\t\t========================================\n\n");
	    printf("\t\tSelamat datang di Toko Buku Asli Online\n\n");
	    printf("\t\tLayanan yang tersedia:\n");
	    printf("\t\t1.Entry Penjualan Buku\n\n");
	    printf("\t\t2.Sorting Data Penjalan\n\n");
	    printf("\t\t3.Search Data Penjualan\n\n");
	    printf("\t\t4.Tutup Aplikasi\n\n\n");
	    printf("\t\t========================================\n");
	    printf("\t\tLayanan apa yang mau digunakan?: ");
		scanf("%d",&menu);
		system("cls");
		if (menu==1){
	        do{
				int entry;
		        printf("Masukkan tanggal pembelian (DD): ");
		        scanf("%s",newsales[0].PurchaseDate);
		        printf("Masukkan bulan pembelian (MM): ");
		        scanf("%s",newsales[0].PurchaseMonth);
		        printf("Masukkan tahun pembelian (YYYY): ");
		        scanf("%s",newsales[0].PurchaseYear);
		            
		        printf("Masukkan nama pembeli: ");
		        getchar();
		        scanf("%[^\n]s",newsales[0].Name);
		        
				printf("Berapa entry yang ingin dicatat: ");
		        scanf("%d",&entry);
		        
				for(int i=0; i<entry; i++){
		        
		            printf("Masukkan jenis buku: ");
		            getchar();
		            scanf("%[^\n]s",newsales[i].BookType);
		
		            printf("Masukkan nama buku: ");
		            getchar();
		            scanf("%[^\n]s",newsales[i].BookName);
		
		            printf("Masukkan jumlah buku yang dibeli: ");
		            scanf("%d",&newsales[i].BookQuant);
		            
		            printf("Masukkan harga buku: ");
		            scanf("%d",&newsales[i].BookPrice);
		            
		            newsales[i].TotalPurchase = newsales[i].BookQuant*newsales[i].BookPrice;
		            printf("Total pembelian adalah : %d\n",newsales[i].TotalPurchase);
		        }
		        printf("==========================================================\n\n");
				printf("\t\t\tToko Buku Asli\n");
				printf("Date\t\t:%s/%s/%s\n",newsales[0].PurchaseDate,newsales[0].PurchaseMonth,newsales[0].PurchaseYear);
				printf("Customer\t:%s\n\n",newsales[0].Name);
		        printf("%-25s%-15s%-15s%-10s%s\n","Book Name","BookType","Quantity","Price","Total");
				for(int i=0; i<entry; i++){
					printf("%-25s",newsales[i].BookName);
					
					printf("%-15s",newsales[i].BookType);
	
					printf("%-15d",newsales[i].BookQuant);
					
					printf("%-10d",newsales[i].BookPrice);
					
					printf("%d\n",newsales[i].TotalPurchase);
					
					fprintf(fp,"\n%d;%s/%s/%s;%s;%s;%s;%d;%d;%d",sls[data].entry+i+1, newsales[0].PurchaseDate,newsales[0].PurchaseMonth,newsales[0].PurchaseYear,newsales[0].Name,newsales[i].BookType,newsales[i].BookName,newsales[i].BookQuant,newsales[i].BookPrice,newsales[i].TotalPurchase);
				}
				printf("\n==========================================================\n\n");
		    fclose(fp);
		    data=0;
		    fp = fopen("sales.txt","r+");
			while(fscanf (fp, "%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[data].PurchaseDate, sls[data].PurchaseMonth, sls[data].PurchaseYear, sls[data].Name, sls[data].BookType, sls[data].BookName, &sls[data].BookQuant, &sls[data].BookPrice, &sls[data].TotalPurchase) != EOF){
        		data++;
    		}fclose(fp);
			printf("Mau balik ke menu? (0 adalah Tidak / 1 adalah Iya) : ");
			scanf("%d",&boole);
			system("cls");

			}while(boole==0);
	    }
	    
		if (menu==2){
	    	data = 0;
			fclose(fp);
			fp = fopen("sales.txt","r+");
			while(fscanf (fp, "%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[data].PurchaseDate, sls[data].PurchaseMonth, sls[data].PurchaseYear, sls[data].Name, sls[data].BookType, sls[data].BookName, &sls[data].BookQuant, &sls[data].BookPrice, &sls[data].TotalPurchase) != EOF){
        		data++;
    		}fclose(fp);
			
	     	do{
			printf("=====================================\n");
	        printf("Layanan Sort yang disediakan: \n");
	        printf("1.Tanggal\n");
	        printf("2.Nama Pembeli\n");
	        printf("3.Jenis Buku\n");
	        printf("4.Nama Buku\n");
	        printf("5.Jumlah Buku\n");
	        printf("6.Harga Buku\n");
	        printf("7.Total Pembelian\n");
	        printf("=====================================\n");
	        int sort;
	        printf("Mau Sorting apa: ");
	         scanf("%d",&sort);
	    	system("cls");
	           if(sort==1){
        printf("Sorting menurut Tanggal:\n");
        sortingPurchaseDate(sls,data);
        sortingPurchaseMonth(sls,data);
        sortingPurchaseYear(sls,data);
    }
    else if(sort==2){
        printf("Sorting menurut Nama Pembeli:\n");
        sortingName(sls,data);
    }
    else if(sort==3){
        printf("Sorting menurut Jenis Buku:\n");
        sortingBookType(sls,data);
    }
    else if(sort==4){
        printf("Sorting menurut Nama Buku:\n");
        sortingBookName(sls,data);
    }
    else if(sort==5){
        printf("Sorting menurut Jumlah Buku:\n");
        sortingBookQuant(sls,data);
    }
    else if(sort==6){
        printf("Sorting menurut Harga Buku:\n");
        sortingBookPrice(sls,data);
    }
    else if(sort==7){
        printf("Sorting menurut Total Pembelian:\n");
        sortingTotalPurchase(sls,data);
    }
    else{

    }
	printf("====================================================================================================================\n");
    	 printf("%-17s%-20s%-15s%-20s%-15s%-15s%-15s\n","Purchase Date","Name","Book Type","Book Name","Book Quant","Book Price","TotalPurchase");
    	for(int i=2; i<=data+1 ; i++){
    		printf("%s/%s/%-11s%-20s%-15s%-20s%-15d%-15d%-15d", sls[i].PurchaseDate, sls[i].PurchaseMonth, sls[i].PurchaseYear, sls[i].Name, sls[i].BookType, sls[i].BookName, sls[i].BookQuant, sls[i].BookPrice, sls[i].TotalPurchase);
    		printf("\n");
		}
		printf("====================================================================================================================\n");
    	printf("\nMau balik ke menu? (0 adalah Tidak / 1 adalah Iya) : ");
			scanf("%d",&boole);
			system("cls");
    		}while(boole==0);
	}
		if (menu==3){
	     	int ch;
	     	fp = fopen("sales.txt","r+");
			data = 0;
			while(fscanf (fp, "%d;%[^'/']/%[^'/']/%[^';'];%[^';'];%[^';'];%[^';'];%d;%d;%d", &sls[data].entry, sls[data].PurchaseDate, sls[data].PurchaseMonth, sls[data].PurchaseYear, sls[data].Name, sls[data].BookType, sls[data].BookName, &sls[data].BookQuant, &sls[data].BookPrice, &sls[data].TotalPurchase) != EOF){
        		data++;
    		}	
	     	do{
		        printf("=====================================\n");
		        printf("Kategori Search: \n");
		        printf("1.Tanggal\n");
		        printf("2.Nama Pembeli\n");
		        printf("3.Jenis Buku\n");
		        printf("4.Nama Buku\n");
		        printf("5.Jumlah Buku\n");
		        printf("6.Harga Buku\n");
		        printf("7.Total Pembelian\n");
		        printf("=====================================\n");
		
		        printf("Ingin mencari apa:\n");
				scanf("%d",&ch);
				
				switch(ch){
					case 1:
						cariTanggal();
					case 2:
						cariNamaPembeli();
						break;
					case 3:
						cariJenisBuku();
						break;
					case 4:
						cariNamaBuku();
						break;
					case 5:
						cariJumlahBuku();
						break;
					case 6:
						cariHargaBuku();
						break;
					case 7:
						cariTotalPembelian();
						break;
				}
				
			printf("Mau balik ke menu? (0 adalah Tidak / 1 adalah Iya) : ");
			scanf("%d",&boole);
			system("cls");
			}while(boole==0);
	    }
	    
	    if(menu==4){
			printf("Yakin mau keluar? (0 adalah Tidak / 1 adalah Iya) : \n");
			scanf("%d",&boole);
			if(boole==0){
				menu=0;
			}
			system("cls");
		}
		
		if(menu>4){
			printf("Menu tidak tersedia, silahkan pilih layanan yang tersedia\n");
			system("cls");
		}
	     
	}while(menu!=4);
}
