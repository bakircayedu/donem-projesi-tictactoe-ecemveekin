#include <stdio.h>
#include <conio.h>

char kutuSec[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int kazanan();
void tahta();

struct bilgi{
    char oyuncuad[20];
    char oyuncusoyad[20];
};
struct bilgi isim1,isim2;

enum yarismacisirasi{
    Ecem, Ekin, Beyza, Taha ,Fatma, Ahmet, Mehmet
} ;
int main()
{

    printf("1. Oyuncu \n");
    printf("Adiniz:");
    scanf("%s",isim1.oyuncuad);
    printf("Soyad:");
    scanf("%s",isim1.oyuncusoyad);
    printf("2. Oyuncu \n");
    printf("Adiniz:");
    scanf("%s",isim2.oyuncuad);
    printf("Soyad:");
    scanf("%s",isim2.oyuncusoyad);

    enum yarismacisirasi yarismaci;
    yarismaci= Ecem ;
    printf("Ecem kacinci sirada?");
    printf("%d",yarismaci);

    printf("Ad ve Soyad: %s %s \n %s %s ", isim1.oyuncuad,isim1.oyuncusoyad,isim2.oyuncuad,isim2.oyuncusoyad);


    int oyuncu = 1, i, secim;

    char isaretle;
    do
    {
        tahta();
        oyuncu = (oyuncu % 2) ? 1 : 2;

        printf("Oyuncu %d, oynamak istediginiz kutucuk numarasini giriniz:  ", oyuncu);
        scanf("%d", &secim);

        isaretle = (oyuncu == 1) ? 'X' : 'O';

        if (secim == 1 && kutuSec[1] == '1')
            kutuSec[1] = isaretle;

        else if (secim == 2 && kutuSec[2] == '2')
            kutuSec[2] = isaretle;

        else if (secim == 3 && kutuSec[3] == '3')
            kutuSec[3] = isaretle;

        else if (secim == 4 && kutuSec[4] == '4')
            kutuSec[4] = isaretle;

        else if (secim == 5 && kutuSec[5] == '5')
            kutuSec[5] = isaretle;

        else if (secim == 6 && kutuSec[6] == '6')
            kutuSec[6] = isaretle;

        else if (secim == 7 && kutuSec[7] == '7')
            kutuSec[7] = isaretle;

        else if (secim== 8 && kutuSec[8] == '8')
            kutuSec[8] = isaretle;

        else if (secim == 9 && kutuSec[9] == '9')
            kutuSec[9] = isaretle;

        else
        {
            printf("%d numarali kutucuk bulunmamaktadir,hatali giris yaptiniz!",secim);

            oyuncu--;
            getch();
        }
        i = kazanan();

        oyuncu++;

    }while (i ==  - 1);

    FILE *pDosya;
    pDosya=fopen("C:\\Users\\ecemb\\Desktop\\tictactoeskor.txt","w");
    if(pDosya==NULL){
        printf("Dosya acilmadi!");
        exit(1);
    }
    tahta();

    if (i == 1)
        fprintf(pDosya,"==>\aOyuncu %d kazandi! ", --oyuncu);
    else
        fprintf(pDosya,"==>\aBerabere!");

    getch();
    if((pDosya=fopen("C:\\Users\\ecemb\\Desktop\\tictactoeskor.txt","r"))!=NULL)
    {
		fscanf(pDosya, "%d", &oyuncu);
		printf("%d.oyuncu kazandi",oyuncu);
	}
	else{

		printf("Berabere!");
	}

    return 0;
    fclose(pDosya);
    }

int kazanan()
{
    if (kutuSec[1] == kutuSec[2] && kutuSec[2] == kutuSec[3])
        return 1;

    else if (kutuSec[4] == kutuSec[5] && kutuSec[5] == kutuSec[6])
        return 1;

    else if (kutuSec[7] == kutuSec[8] && kutuSec[8] == kutuSec[9])
        return 1;

    else if (kutuSec[1] == kutuSec[4] && kutuSec[4] == kutuSec[7])
        return 1;

    else if (kutuSec[2] == kutuSec[5] && kutuSec[5] == kutuSec[8])
        return 1;

    else if (kutuSec[3] == kutuSec[6] && kutuSec[6] == kutuSec[9])
        return 1;

    else if (kutuSec[1] == kutuSec[5] && kutuSec[5] == kutuSec[9])
        return 1;

    else if (kutuSec[3] == kutuSec[5] && kutuSec[5] == kutuSec[7])
        return 1;

    else if (kutuSec[1] != '1' && kutuSec[2] != '2' && kutuSec[3] != '3' &&
        kutuSec[4] != '4' && kutuSec[5] != '5' && kutuSec[6] != '6' && kutuSec[7]
        != '7' && kutuSec[8] != '8' && kutuSec[9] != '9')

        return 0;
    else
        return  - 1;
}


void tahta()
{
    system("cls");
    printf("\n\t\t\t\t\t*****Tic Tac Toe Oyununa Hosgeldiniz*****\n\n");
    printf("Skoru Dosyadan Takip Ediniz!\n");

    printf("%s (X)  -  %s (O)\n\n\n", isim1.oyuncuad,isim2.oyuncuad);


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", kutuSec[1], kutuSec[2], kutuSec[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", kutuSec[4], kutuSec[5], kutuSec[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", kutuSec[7], kutuSec[8], kutuSec[9]);

    printf("     |     |     \n\n");

}

