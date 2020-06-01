#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void tampil_komik();
void cari_komik();
void tambah_komik();
void hapus_komik();
void edit_komik();


void close();
struct DATA {
	char nama_komik[50];
	int jumlah;
	int id_komik;
	char genre[20];
	float harga[12];

}tambah,cek,hapus,temp;

int main()
{
	system("cls");
	char username[10];
    char password[10];

    ulangi:
    printf("===LOGIN===\nUsername: "); scanf("%s", username);

    printf("password: "); scanf("%s", password);

    if((strcmp(username,"admin")==0)&&(strcmp(password,"root")==0)){
        printf("status: login sukses");
    } else {
        printf("status: login gagal\n\nMohon Login Kembali\n");
        goto ulangi;
    }

    menu();
	return 0;
}

void menu(){
	int pilih;
	menu:
		system("cls");
		printf("MENU KOMIK::");
		printf("\n1. Tampil Data komik");
		printf("\n2. Cari Data komik");
		printf("\n3. Tambah komik");
		printf("\n4. Hapus Data komik");
		printf("\n5. Edit Data komik");
		printf("\n6. Keluar");
		printf("\n\nInput Pilihan Nomor Menu : ");
		scanf("%d", &pilih);

		switch(pilih){
			case 1:tampil_komik();
				break;
			case 2:cari_komik();
				break;
			case 3:tambah_komik();
				break;
			case 4:hapus_komik();
				break;
			case 5:edit_komik();
				break;
			case 6:close();
				break;
			default:printf("\nMohon Maaf Pilihan Tidak Tersedia !");
				getche();
				goto menu;
		}
}


void tampil_komik()
{
	FILE *view;
	view = fopen("data.txt","r");
	int test=0;
	system ("cls");
	printf ("ID KOMIK\t\tNAMA KOMIK\t\tGENRE\t\tJUMLAH\t\tHARGA\n");
	while (fscanf (view,"%d;%[^;];%[^;];%d;%f;\n",&tambah.id_komik,tambah.nama_komik,tambah.genre,&tambah.jumlah,&tambah.harga[0])!=EOF)
	{
		printf("%d\t\t\t%s\t\t%s\t\t%d\t\t%f\n",tambah.id_komik,tambah.nama_komik,tambah.genre,tambah.jumlah,tambah.harga[0]);
		test++;
	}
	printf ("\nJumlah Data komik : %d",test);
	fclose(view);

	if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nTekan a untuk kembali ke menu utama dan s untuk keluar : ");
    switch(getch()){
    	case 'a': menu();
        	break;
        case 's': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}
void cari_komik()
{
	FILE *ptr;
	int test=0;
	system("cls");
	ptr=fopen("data.txt","r");
	system("cls");
	printf("Input id_komik komik : ");
	scanf("%d", &cek.id_komik);
	while(fscanf (ptr,"%d;%[^;];%[^;];%d;%f;\n",&tambah.id_komik,tambah.nama_komik,tambah.genre,&tambah.jumlah,&tambah.harga[0])!=EOF){
		if(tambah.id_komik==cek.id_komik){
			test=1;
		}
	}

	fclose(ptr);
	if(test!=1){
		system("cls");
		detail_print:
		printf("\nData tidak ditemukan !\a\a\a");
		detail_invalid:
		printf("\nInput a untuk mencoba lagi, s untuk ke menu utama dan d untuk keluar :");
        switch(getch()){
            case 'a': cari_komik();
            	break;
            case 's': menu();
            	break;
            case 'd': close();
            	break;
            default:printf("\nMaff Kesalahan Input !");
            	getche();
            	goto detail_invalid;
        }
	}else{
		detail_valid:
		printf("\n\n\nTekan a untuk ke menu utama dan s untuk keluar :");
        switch(getch()){
        	case 'a': menu();
       			break;
       		case 's': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto detail_valid;
       	}
    }

}

void tambah_komik(){
	FILE *ptr,*ptr1;
	int count=0;

	ptr =fopen("data.txt","a");
		system("cls");
		ptr1 =fopen("data.txt","r");
		while (fscanf (ptr1,"%d;%[^;];%[^;];%d;%f;\n",&tambah.id_komik,&tambah.nama_komik,&tambah.genre,&tambah.jumlah,&tambah.harga[0])!=EOF)
		{
			tambah.id_komik++;
		}
		cek.id_komik = tambah.id_komik;
		fclose(ptr1);
		printf ("masukkan nama komik : ");fflush(stdin);
		scanf ("%[^\n]",tambah.nama_komik);
		printf ("masukkan genre komik : ");fflush(stdin);
		scanf ("%[^\n]",tambah.genre);
		printf ("masukkan jumlah komik : ");fflush(stdin);
		scanf ("%d",&tambah.jumlah);
		printf("masukkan harga\t: ");
		scanf("%f",&tambah.harga[0]);

		fprintf(ptr,"%d;%s;%s;%d;%f;\n",tambah.id_komik,tambah.nama_komik,tambah.genre,tambah.jumlah,tambah.harga[0]);
		fclose(ptr);

		printf("\n\nData komik Sudah Disimpan !");
		add_invalid:
		printf("\n\n\tKetik 1 untuk kembali ke menu utama dan 0 untuk keluar : ");

		switch(getch()){
    		case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}

void hapus_komik()
{
	FILE *lama, *baru;
	int test=0;
	lama = fopen("data.txt","r");
	baru = fopen("baru.txt","w");
	system("cls");
	printf("Input id komik yang akan di hapus : ");
	scanf("%d", &hapus.id_komik);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;\n",&tambah.id_komik,tambah.nama_komik,tambah.genre,&tambah.jumlah,&tambah.harga[0])!=EOF)
	{
		if(tambah.id_komik != hapus.id_komik)
		{
			fprintf(baru,"%d;%s;%s;%d;%f;\n",tambah.id_komik,tambah.nama_komik,tambah.genre,tambah.jumlah,tambah.harga[0]);
		}
		else{
			test++;
			printf("\nData komik id komik : %d dengan nama komik : %s\n",tambah.id_komik,tambah.nama_komik);
			printf("\nBerhasil dihapus dari Daftar !");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("data.txt");
	rename("baru.txt","data.txt");
		if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': hapus_komik();
            		break;
            	case '1': menu();
            		break;
            	case '2': close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }

}

void edit_komik()
{
	int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("data.txt","r");
	baru = fopen ("baru.txt","w");
	system("cls");

	printf ("Masukan id_komik komik : ");
	scanf ("%d",&cek.id_komik);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;\n",&tambah.id_komik,tambah.nama_komik,tambah.genre,&tambah.jumlah,&tambah.harga[0])!=EOF)
	{
		if(tambah.id_komik == cek.id_komik)
		{
			test=1;
			ganti:
				printf("\nNo. id komik : %d dimiliki komik dengan nama komik : %s",tambah.id_komik,tambah.nama_komik);
				printf("\n\nData yang akan diganti : ");
				printf("\n1. nama_komik");
				printf("\n2. Jenis Kelamin");
				printf("\n3. jumlah");
				printf("\n4. harga Pokok");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);

				if(pilih == 1)
				{
					printf ("\nMasukan Data nama_komik Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek.nama_komik);
					strcpy(tambah.nama_komik,cek.nama_komik);
						fprintf(baru,"%d;%s;%s;%d;%f;\n",tambah.id_komik,tambah.nama_komik,tambah.genre,tambah.jumlah,tambah.harga[0]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data Jenis Kelamin L/P : ");fflush(stdin);
					scanf ("%[^\n]",cek.genre);
					strcpy(tambah.genre,cek.genre);
						fprintf(baru,"%d;%s;%s;%d;%f;\n",tambah.id_komik,tambah.nama_komik,tambah.genre,tambah.jumlah,tambah.harga[0]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Data jumlah Baru : ");
					scanf ("%d",&cek.jumlah);
					tambah.jumlah = cek.jumlah;
					fprintf(baru,"%d;%s;%s;%d;%f;\n",tambah.id_komik,tambah.nama_komik,tambah.genre,tambah.jumlah,tambah.harga[0]);
					printf ("\nPerubahan Sudah Disimpan !");
				}

                else if (pilih == 4)
				{
					printf ("\nMasukan Data harga Pokok Baru : ");
					scanf("%f",&cek.harga[0]);
					strcpy(tambah.harga,cek.harga);
					fprintf(baru,"%d;%s;%s;%d;%f;\n",tambah.id_komik,tambah.nama_komik,tambah.genre,tambah.jumlah,tambah.harga[0]);
					printf ("\nPerubahan Sudah Disimpan !");
				}

				else{
					printf("\n\nInput Anda Salah !");
					getche();
					goto ganti;
				}
		}
		else
		{
			fprintf(baru,"%d;%s;%s;%d;%f;\n",tambah.id_komik,tambah.nama_komik,tambah.genre,tambah.jumlah,tambah.harga[0]);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("data.txt");
	rename("baru.txt","data.txt");
	if(test!=1){
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': edit_komik();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}

