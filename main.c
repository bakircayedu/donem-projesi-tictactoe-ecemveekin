#include <stdio.h>
#include <conio.h>


char kutuSec[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; /* tek indisli bir dizi tanimladik (vektor)
                                                                            cünkü tahta fonksiyonu ile ic ice dongu
                                                                            yapisini kurmadan bir oyun tahtasi olusturduk.
                                                                            dizi indisleri 0 dan baslar 9 da kutumuz dolsun diye
                                                                            0 dan basladik 9'a kadar gitmesi
                                                                            icin degerleri yazdik.*/


int kazanan();
void tahta(); // oynayacagimiz oyun tahtasini olusturan fonksiyonumuza ait kodlar en altta verilmistir.

struct bilgi{
    char oyuncuad[20];
    char oyuncusoyad[20];
};
struct bilgi isim1,isim2;

enum yarismacisirasi{
    Ekin=1,Beyza,Ecem, Taha ,Fatma, Ahmet, Mehmet
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
    printf("Oyuncu 1 Ad ve Soyad: %s %s\n Oyuncu 2 Ad Soyad: %s %s \n Devam etmek icin Enter'a basiniz\n", isim1.oyuncuad,isim1.oyuncusoyad,isim2.oyuncuad,isim2.oyuncusoyad);
    getch();
    printf("Yarismacilar arasindan Ecem kacinci sirada bulunmaktadir, ogrenmek icin Enter'a basiniz\n");
    getch();

    enum yarismacisirasi yarismaci;
    yarismaci=Ecem;
    printf("Yarismacilar arasindan Ecem %d. sirada\n",yarismaci);


    printf("Oyuna baslamak icin enter'a basiniz");

    getch(); // ekranda entera basana kadar yazilmis olanlarin durmasi icin

    //oyuncularin istedigi kadar oyun oynayabilmesi icin dongunun basini burada yazdik.

    char cikmakarakteri=0;
    while (cikmakarakteri!='h'){

    int oyuncu = 1, i, secim; /* 2 oyuncu ile oynanan oyunumuzda 1.oyuncu için '1' atamasi yaptik.
                                Kazanan fonksiyonunu atayabilmek icin i degiskeni ve
                                kullanicidan tahtadan hangi kutucugu sectigini ogrenmek icin secim degiskenini olusturduk.*/

    char isaretle; //isaretle degiskeni ile oyuncu sembolu olan X veya O ile isaretleme yapilacak
    do
    {
        tahta();
        oyuncu = (oyuncu % 2) ? 1 : 2; /*oyuncu=1 demistik 3lu operatoru kullanarak 1 in mod %2 si 1 olacak ve
                                        oyuncu=1 olacaktir ve ilk oyuncu oyuna basliyor. */

        printf("Oyuncu %d, oynamak istediginiz kutucuk numarasini giriniz:  ", oyuncu);
        scanf("%d", &secim);


        isaretle = (oyuncu == 1) ? 'X' : 'O';  /* oyuncu=1 ise 3lu operator ile olusturdugumuz bu yapi ile
                                                 kosul dogru oldugu icin ilk degeri yani X sembolunu alacaktir.*/


        if (secim == 1 && kutuSec[1] == '1')
            kutuSec[1] = isaretle;    /* kullanicinin girdigi kutucuk numarasi ve kutuSec dizimizin indisi 1 ise kutuSec[1]
                                        in oldugu kutuya oyuncu 1 oynuyorsa X , oyuncu 2 oynuyorsa O ile isaretlememizi saglar.*/

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


        else  /*eger 1den 9'a kadar olan rakamlar disinda bir secim yapmak istendiyse bu kisma girecek ve
                hatali giris yaptiniz diyerek oynayan oyuncu =1 ise oyuncu =0 olacak ve cikis yapacak sonra asagida tekrar bir artiracagiz
                bu sayede oyuncu tekrar =1 olacak ve tekrar bir kutu secimi yapmasi istenecek
                eger oyuncu=2 iken hata yaptiysa oyuncu=1 olacak ve cikis yapacak oyuncu++ sayesinde oyuncu=2 tekrar oynayacaktir.*/
        {
            printf("%d numarali kutucuk bulunmamaktadir,hatali giris yaptiniz!",secim);

            oyuncu--;
            getch();
        }
        i = kazanan();  // kazanan fonksiyonu sonucunu i ye atar.

        oyuncu++;

    }while (i == -1);  /*kazanan fonksiyonu asagida verilmistir , return 1 ise oyuncu 1 kazanir, return 2 ise oyuncu 2
                        return 0 ise berabere
                        return -1 ise dongu kirilir o sebeple i =-1 olunca kazanan olmayacak,dongu bitti */

    printf("Oyuna devam etmek istemiyorsaniz h ye basiniz.Cunku skor belli oldu!\n");
    cikmakarakteri=getch();
    printf("Sonucu gormek icin 2 kez enter'a basiniz:");
    getch();

    FILE *pDosya;
    pDosya=fopen("tictactoeskor.txt","w"); //w modu ile dosya aciyoruz ve kazanani dosyaya yazacagiz
    if(pDosya==NULL){
        printf("Dosya acilmadi!");
        exit(1);
    }

    tahta();
      if (i == 1 )
        fprintf(pDosya,"%d. oyuncu kazandi!", --oyuncu); //en son oyuncu++ olmuştu ve dongu kirilmisti
    else if(i==2 )
         fprintf(pDosya,"%d. oyuncu kazandi!", --oyuncu); //en son oyuncu++ olmuştu ve dongu kirilmisti

    else
        {
        fprintf(pDosya,"Berabere");
        oyuncu=0;   //oyuncu 1 ve 2 degilken 0 atadik bu durumda return 0 donecek beraberlik durumu olusacaktir
        }

    getch();
    fclose(pDosya);

    pDosya=fopen("tictactoeskor.txt","r"); //dosyadan okuma islemi yapıyoruz

     if(pDosya==NULL){
        printf("Dosya acilmadi!");
        exit(1);
    }
        if (oyuncu == 0)
        printf("Berabere!");
        else
		printf("%d.oyuncu kazandi", oyuncu);

    return 0;
    fclose(pDosya);

    }
}


int kazanan()
{
    //yatay siralarin kontrolu
    if (kutuSec[1] == kutuSec[2] && kutuSec[2] == kutuSec[3])
        return 1;

    else if (kutuSec[4] == kutuSec[5] && kutuSec[5] == kutuSec[6])
        return 1;

    else if (kutuSec[7] == kutuSec[8] && kutuSec[8] == kutuSec[9])
        return 1;
    //dikey(sutunlarin) kontrolu
    else if (kutuSec[1] == kutuSec[4] && kutuSec[4] == kutuSec[7])
        return 1;

    else if (kutuSec[2] == kutuSec[5] && kutuSec[5] == kutuSec[8])
        return 1;

    else if (kutuSec[3] == kutuSec[6] && kutuSec[6] == kutuSec[9])
        return 1;
    //Capraz(kosegenlerin) kontrolu

    else if (kutuSec[1] == kutuSec[5] && kutuSec[5] == kutuSec[9])
        return 1;

    else if (kutuSec[3] == kutuSec[5] && kutuSec[5] == kutuSec[7])
        return 1;

   else // 1.oyuncu kazanamadi 2.oyuncu mu kazandi diye baktigimiz kisim
  {
        //yatay siralarin kontrolu
    if (kutuSec[1] == kutuSec[2] && kutuSec[2] == kutuSec[3])
        return 2;

    else if (kutuSec[4] == kutuSec[5] && kutuSec[5] == kutuSec[6])
        return 2;

    else if (kutuSec[7] == kutuSec[8] && kutuSec[8] == kutuSec[9])
        return 2;
    //dikey(sutunlarin) kontrolu
    else if (kutuSec[1] == kutuSec[4] && kutuSec[4] == kutuSec[7])
        return 2;

    else if (kutuSec[2] == kutuSec[5] && kutuSec[5] == kutuSec[8])
        return 2;

    else if (kutuSec[3] == kutuSec[6] && kutuSec[6] == kutuSec[9])
        return 2;

    else if (kutuSec[1] != '1' && kutuSec[2] != '2' && kutuSec[3] != '3' &&
        kutuSec[4] != '4' && kutuSec[5] != '5' && kutuSec[6] != '6' && kutuSec[7]
        != '7' && kutuSec[8] != '8' && kutuSec[9] != '9')

        return 0;  //berabere olma durumu
     else
        return -1; //oyunu sonuna kadar veya kazanan olana kadar oynamamızı saglar dongude i==-1 olunca kirilmasini istemistik

}
}


void tahta() /*oyunun oynandigi,kutucuklarin bulundugu tahtanin fonksiyonudur.
            biz tek indisli yani bir dizi olusturarak ve kutucuklai | - sembolleri ile cizerek olusturduk
            ve aralarina da düzenli bir sekilde kutuSec dizinin indislerini yerlestirerek bir yapi olusturduk.*/
{
    system("cls");
    printf("\n\t\t\t\t\t*****Tic Tac Toe Oyununa Hosgeldiniz*****\n\n");
    printf("Skoru Dosyadan Da Takip Ediniz!\n");

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

