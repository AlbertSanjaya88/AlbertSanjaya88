// Nama		: Albert Sanjaya Ong
// NIM 		: 2602109536
// Kelas	: BB20 - LAB
// Data Structure Assignment Modul 2

#include <stdio.h>

//define struktur stack
struct Stack{
	char str[1000];
	char option[3];
	int n;
	int space;
};

int main()
{
	//opt adalah kondisi loop
	int opt=1;
	struct Stack Stc;
	do{
		//program mendisplay
		printf("Reverse Sentence\n");
		printf("================\n\n");
		
		do{
			//loop input kalimat, ketika jumlah kata kurang dari 5, maka diminta untuk input lagi
			printf("Input Sentence[minimum 5 words]: ");
			scanf(" %[^\n]",Stc.str);
			
			Stc.n = strlen(Stc.str);
			Stc.space=0;
			//loop untuk memeriksa apakah kalimat benar-benar memiliki 5 kata atau lebih
			for(int i = 0; i < Stc.n; i++){
				int check=-1;
				//disini saya jalankan sebuah loop lagi, jadi meskipun user menaruh banyak space di akhir kalimat, tidak akan dihitung.
				for(int j = i; j <Stc.n; j++){
					if(Stc.str[j+1] !=' '){
						check = check+1;
					}
				}
				//jadi ketika program hanya menemukan space maka loop diberhentikan
				if(check == 0){
					break;
				}
				//dan disini ketika masih tengah kalimat, ketika ada dua atau lebih spasi yang bersebelahan, maka yang dihitung hanya satu
				else if(check > 0){
					if(Stc.str[i]==' '){
						Stc.space = Stc.space + 1;
						if(Stc.str[i+1]=="\n"){
							break;
						}
						else if(Stc.str[i+1]==' '){
							Stc.space = Stc.space - 1;
							continue;
						}
					}
				}
			}// dan disini kondisi loop tetap berjalan adalah ketika spasi yang ditemukan dibawah 4
		}while(Stc.space<4);
		
		
		//disini program mendisplay hasil pembalikan kalimat
		printf("\nThe result is : ");
		for(int i = Stc.n-1; i >= 0; i--){
			printf("%c",Stc.str[i]);
		}
		printf("\n");
			
		do{
			//disini program masuk ke loop baru untuk menanyakan apakah mau lanjut atau tidak
			//ketika user input "no", maka program berhenti dengan mengubah variabel opt sehingga program terputus dari loop
			//ketika user input "yes", maka program keluar dari loop kecil ini dan kembali ke loop besar dan kembali meminta user input kalimat
			//ketika user menginput selain yang diatas, maka program kembali loop untuk "Mau Lanjut atau tidak?"
			printf("\nDo you want to continue[yes/no] ? ");
			scanf("%s",Stc.option);
			
			if(strcasecmp(Stc.option,"no")==0){
				opt = 0;
			}
			
			else if(strcasecmp(Stc.option,"yes")==0){
				opt = 1;
			}
			
			else{
				opt = -1;
			}
		}while (opt == -1);
		printf("\n");
		
		
	}while(opt == 1);
	
	return 0;
}
