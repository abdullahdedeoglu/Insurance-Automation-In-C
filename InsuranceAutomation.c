#include <stdio.h>
#include <stdlib.h>

typedef struct Personel
{
    char p_ad[20];
    int yil;
    int maas;
    double prim;
    int id;
    double tprim;

} P;

typedef struct Sirket
{
    char s_ad[20];
    int kod;
    P* p_bilgi;
    int ucret;
    int p_sayi;
    P *pp_bilgi;


} S;

S* s_bilgi;
S* ss_bilgi;
double tprim=0;
int tgelir=0;

S* ekle(int s_sayi)
{
    int i, j;
    int p_sayi;

    s_bilgi=(S*)malloc(sizeof(S)*s_sayi);



    for (i=0; i<s_sayi; i++)
    {
        printf("Sirketin adi?: ");
        scanf("%s", (s_bilgi+i)->s_ad);

        printf("Sirketin eklenme sirasi?: ");
        scanf("%d", &(s_bilgi+i)->kod);

        //Eklenme sirasi, sirketin kodu olarak tanimlanir.

        printf("Sirketin hizmete karsilik odeyecegi ucret?: ");
        scanf("%d", &(s_bilgi+i)->ucret);

        printf("Sirkette calisan personel sayisi?: ");
        scanf("%d", &(s_bilgi+i)->p_sayi);

        p_sayi=(s_bilgi+i)->p_sayi;

        (s_bilgi+i)->p_bilgi= (P*)malloc(sizeof(P)*p_sayi);

        for (j=0; j<p_sayi; j++)
        {
            printf("Personelin adi?: ");
            scanf("%s", ((s_bilgi+i)->p_bilgi+j)->p_ad);

            printf("Personel kac yildir sirkete hizmet vermektedir?: ");
            scanf("%d", &((s_bilgi+i)->p_bilgi+j)->yil);

            printf("Personelin aldigi maas ne kadardir?: ");
            scanf("%d", &((s_bilgi+i)->p_bilgi+j)->maas);

            printf("Personelin id?: ");
            scanf("%d", &((s_bilgi+i)->p_bilgi+j)->id);

        }


    }
    return s_bilgi;
}

void prim_hesapla( S* s_bilgi, int s_sayi)
{
    int i, j, p_sayi;
    double tprim;
    double b=0;

    for (i=0; i<s_sayi; i++)
    {
        p_sayi=(s_bilgi+i)->p_sayi;

        for (j=0; j<p_sayi; j++)
        {
            if (0<((s_bilgi+i)->p_bilgi+j)->yil<=7)
            {
                ((s_bilgi+i)->p_bilgi+j)->prim=((s_bilgi+i)->p_bilgi+j)->maas*0.1;
                b+=((s_bilgi+i)->p_bilgi+j)->prim;
                printf("%d. Sirketin %d. personelinin aldigi prim: %f \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->prim);
            }
            else if (7<((s_bilgi+i)->p_bilgi+j)->yil<=14)
            {
                ((s_bilgi+i)->p_bilgi+j)->prim=((s_bilgi+i)->p_bilgi+j)->maas*0.2;
                b+=((s_bilgi+i)->p_bilgi+j)->prim;
                printf("%d. Sirketin %d. personelinin aldigi prim: %f \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->prim);
            }

            else if (14<((s_bilgi+i)->p_bilgi+j)->yil)
            {
                ((s_bilgi+i)->p_bilgi+j)->prim=((s_bilgi+i)->p_bilgi+j)->maas*0.3;
                b+=((s_bilgi+i)->p_bilgi+j)->prim;
                printf("%d. Sirketin %d. personelinin aldigi prim: %f \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->prim);
            }
            tprim=b;
            ((s_bilgi)->p_bilgi)->tprim=tprim;
        }


    }
    printf("Toplam prim: %f\n", tprim);

}


void listeleme(S* s_bilgi, int s_sayi)
{
    int i,j;
    int p_sayi;

    for(i=0; i<s_sayi; i++)
    {
        printf("%d. Sirketin adi: %s \n", i+1, (s_bilgi+i)->s_ad);
        printf("%d. Sirketin kodu: %d \n", i+1, (s_bilgi+i)->kod);
        printf("%d. Sirketin hizmete karsilik odeyecegi ucret: %d \n", i+1, (s_bilgi+i)->ucret);
        printf("%d. Sirkette calisan personel sayisi: %d \n",i+1, (s_bilgi+i)->p_sayi);

        p_sayi=(s_bilgi+i)->p_sayi;

        for(j=0; j<p_sayi; j++)
        {
            printf("%d. Sirketin %d. personelinin adi: %s \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->p_ad);
            printf("%d. Sirketin %d. personelinin hizmet yili: %d \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->yil);
            printf("%d. Sirketin %d. personelinin maasi: %d \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->maas);
            printf("%d. Sirketin %d. personelinin aldigi prim: %f \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->prim);
            printf("%d. Sirketin %d. personelinin id: %d \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->id);
        }
    }
}

void silme(S* s_bilgi, int s_sayi)
{
    int i,j,p_sayi;
    int a, b;
    S* p_bilgi;

    printf("Sirket kodunu giriniz?: ");
    scanf("%d", &a);

    for (i=0; i<s_sayi; i++)
    {
        if (a==(s_bilgi+i)->kod)
        {
            printf("Kacinci personeli silmek istiyorsunuz?: ");
            scanf("%d", &b);
            p_sayi=(s_bilgi+i)->p_sayi;

            for (j=b; j<p_sayi; j++)
            {
                *((s_bilgi+i)->p_bilgi+(j-1))= *((s_bilgi+i)->p_bilgi+j);
            }

            p_sayi--;
            (s_bilgi+i)->p_sayi=p_sayi;
            (s_bilgi+i)->pp_bilgi=(P*)malloc(sizeof(P)*p_sayi);
            for(j=0; j<p_sayi; j++)
            {
                *((s_bilgi+i)->pp_bilgi+j)=*((s_bilgi+i)->p_bilgi+j);
            }
            (s_bilgi+i)->p_bilgi=(s_bilgi+i)->pp_bilgi;

        }
    }

}

void guncelleme(S* s_bilgi, int s_sayi)
{
    int i, j, p_sayi;
    int a, b;
    printf("Guncellenecek sirketin kodunu giriniz: ");
    scanf("%d", &a);

    for (i=0; i<s_sayi; i++)
    {
        if (a==(s_bilgi+i)->kod)
        {

            printf("%d. Sirketin hizmete karsilik odeyecegi yeni ucret:", i+1);
            scanf("%d", &(s_bilgi+i)->ucret);
            printf("Guncellemek istediginiz personelin id'si: ");
            scanf("%d", &b);
            p_sayi=(s_bilgi+i)->p_sayi;

            for (j=0; j<p_sayi; j++)
            {
                if (b==(((s_bilgi+i)->p_bilgi+j)->id))

                {
                    printf("%d. Sirketin %d. personelinin adi:%s\n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->p_ad);
                    printf("%d. Sirketin %d. personelinin guncellenen hizmet yili:", i+1,j+1);
                    scanf("%d", &((s_bilgi+i)->p_bilgi+j)->yil);
                    printf("%d. Sirketin %d. personelinin guncellenen maasi:", i+1,j+1);
                    scanf("%d", &((s_bilgi+i)->p_bilgi+j)->maas);
                }

            }
        }
    }


}

void ciro_net(S* s_bilgi, int s_sayi)
{
    double tprim;
    double net;
    int tgelir;
    int i, a;
    tprim=((s_bilgi)->p_bilgi)->tprim;
    a=0;
    for (i=0; i<s_sayi; i++)
    {
        a+=(s_bilgi+i)->ucret;
    }
    tgelir=a;
    printf("Ciro: %d\n", tgelir);
    printf("Odenen toplam prim: %f\n", tprim);
    net=(double)tgelir-tprim;
    printf("Net gelir: %f\n", net);

}

void arama(S* s_bilgi, int s_sayi)
{
    int i,j;
    int p_sayi;
    int aranacakkod;
    int a;

    printf("Personeli aranacak sirketin kodunu giriniz:");
    scanf("%d", &aranacakkod);
    for (i=0; i<s_sayi; i++)
    {
        if (aranacakkod==(s_bilgi+i)->kod)
        {
            p_sayi=(s_bilgi+i)->p_sayi;
            printf("Aranacak personelin id?:");
            scanf("%d", &a);

            for(j=0; j<p_sayi; j++)
            {
                if (a==((s_bilgi+i)->p_bilgi+j)->id)
                {
                printf("%d. Sirketin %d. personelinin adi: %s \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->p_ad);
                printf("%d. Sirketin %d. personelinin hizmet yili: %d \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->yil);
                printf("%d. Sirketin %d. personelinin maasi: %d \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->maas);
                printf("%d. Sirketin %d. personelinin aldigi prim: %f \n", i+1,j+1, ((s_bilgi+i)->p_bilgi+j)->prim);
                }

            }
        }

    }
}
S* sirket_sil(S* s_bilgi, int s_sayi)
{
    int i,j,p_sayi;
    int a;
    S* p_bilgi;

    printf("Silinecek sirketin kodu?:");
    scanf("%d", &a);

    for (i=0; i<s_sayi; i++)
    {
        if (a==(s_bilgi+i)->kod)
        {
            p_sayi=0;
            (s_bilgi+i)->p_sayi=p_sayi;
            (s_bilgi+i)->pp_bilgi=(P*)malloc(sizeof(P)*p_sayi);

            (s_bilgi+i)->p_bilgi=(s_bilgi+i)->pp_bilgi;
            for (j=a; j<s_sayi; j++)
            {
                *(s_bilgi+(j-1))=*(s_bilgi+j);
            }
            s_sayi--;
            ss_bilgi=(S*)malloc(sizeof(S)*s_sayi);
            for(j=0; j<s_sayi; j++)
            {
                *(ss_bilgi+j)=*(s_bilgi+j);
            }
            s_bilgi=ss_bilgi;
        }
    }
    return s_sayi;
}

int main()
{
    int menu;
    int dongu=1;

    while (dongu)

    {
        printf("1.Ekleme\n2.Prim Hesapla\n3.Listeleme\n4.Ciro ve Net\n5.Guncelleme\n6.Personel Silme\n7.Sirket Silme\n8.Personel Arama\n0.Cikis\n");
        printf("=>");
        scanf("%d", &menu);
        int s_sayi;
        int sec;
        switch (menu)
        {
        case 0:
            return dongu;
            break;

        case 1:

            printf("Kac tane sirket eklemek istersiniz?: ");
            scanf("%d", &s_sayi);
            s_bilgi=ekle(s_sayi);
            break;

        case 2:
primenu:
            prim_hesapla(s_bilgi, s_sayi);
            printf("\n");
            printf("Ana menuye donmek icin herhangi bir tusa basiniz.\n");
            printf("=>");
            scanf("%d", &sec);
            printf("\n");

            break;

        case 3:

            listeleme(s_bilgi, s_sayi);
            printf("\n");
            printf("Ana menuye donmek icin herhangi bir tusa basiniz.\n");
            printf("=>");
            scanf("%d", &sec);

            break;

        case 4:
            ciro_net(s_bilgi, s_sayi);
            printf("\n");
            printf("Ana menuye donmek icin herhangi bir tusa basiniz.\n");
            printf("=>");
            scanf("%d", &sec);
            printf("\n");

            break;

         case 5:
guncellememenu:
            guncelleme(s_bilgi, s_sayi);
            printf("\n");
            printf("Bu secimde kalmak icin 1'i, primleri guncellemek icin 2'yi, ana menuye donmek icin 0'i tuslayin.\n");
            printf("=>");
            scanf("%d", &sec);

            if (sec==1)
            {
                goto guncellememenu;
            }
             if (sec==2)
            {
                goto primenu;
            }
            printf("\n");
            break;


        case 6:
silmenu:
            silme(s_bilgi, s_sayi);
            printf("\n");
            printf("Bu secimde kalmak icin 1'i, ana menuye donmek icin 0'i tuslayin.\n");
            printf("=>");
            scanf("%d", &sec);

            if (sec==1)
            {
                goto silmenu;
            }
            printf("\n");
            break;


        case 7:
ssilmenu:
            s_sayi=sirket_sil(s_bilgi,s_sayi);
            printf("\n");
            printf("Bu secimde kalmak icin 1'i, ana menuye donmek icin 0'i tuslayin.\n");
            printf("=>");
            scanf("%d", &sec);

            if (sec==1)
            {
                goto ssilmenu;
            }
            printf("\n");
            break;

             case 8:
aramenu:
            arama(s_bilgi,s_sayi);
            printf("\n");
            printf("Bu secimde kalmak icin 1'i, ana menuye donmek icin 0'i tuslayin.\n");
            printf("=>");
            scanf("%d", &sec);

            if (sec==1)
            {
                goto aramenu;
            }
            printf("\n");
            break;

        }


    }
}
