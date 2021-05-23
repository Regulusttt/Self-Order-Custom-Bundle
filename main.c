#include <stdio.h>
#include <stdlib.h>

void lihatmenu();
void inputharga();
void bayar1();
int bayar();
int pesanpaket();
void pesanunit();
int buatorder1();
int main();

typedef struct
{
    char menupaket[100];
    char menupisah[100];
    int hargapaket;
    int hargapisah;
    float harga;
} data;
data nilai[100];

int total,n,i,j,b,jum=0;

void lihatmenu()
{
    i=0;
    b=0;
            FILE *fptr,*fptr1;
            fptr = fopen("MENU PAKET.txt","r");
            if(fptr == NULL)
            {
                printf("MAAF FILE TIDAK DITEMUKAN");
            }
            while(!feof(fptr))
            {
                fgets(nilai[i].menupaket,100,fptr);
                i++;
                jum++;
            }
            fclose(fptr);
            fflush(stdin);
          fptr1 = fopen("MENU TERPISAH.txt","r");
           if(fptr1 == NULL)
            {
                printf("MAAF FILE TIDAK DITEMUKAN");
            }
            i=0;
            while(!feof(fptr1))
            {
                fgets(nilai[i].menupisah,100,fptr1);
                i++;
                b++;
            }
            fclose(fptr1);
            fflush(stdin);
}

void inputharga()
{
    i=0;
    int a;
    a=0;
    FILE *fh,*fh1;
    fh = fopen("HARGA MENU PAKET.txt","r");
    while(!feof(fh)){
        fscanf(fh,"%d",&nilai[i].hargapaket);
        i++;
        a++;
    }
    fclose(fh);
    i=0;
    a=0;
    fh1 = fopen("HARGA MENU TERPISAH.txt","r");
    while(!feof(fh)){
        fscanf(fh1,"%d",&nilai[i].hargapisah);
        i++;
        a++;
    }
    fclose(fh1);
}

void bayar1()
{
    int kembalian,c;
    printf("Total Pesanan anda : %d\n",total);
        printf("Bayar : ");
        scanf("%d",&c);
        if(c<total){
            puts("Uang anda tidak mencukupi");
            return bayar1();
        }else if(c==total) {
            puts("Uangnya pas ya!");
            puts("Terima kasih telah datang ke resto kami!");
            exit(0);
        }else {
            kembalian = c - total;
            printf("Kembalian anda : %d\n",kembalian);
            puts("Terima kasih telah datang ke resto kami!");
            exit(0);
        }
}

int bayar()
{
    int a,c;
    puts("Apakah anda ingin memesan lagi?");
    puts("1.iya");
    puts("2.tidak");
    printf("Pilihan anda : ");
    scanf("%d",&a);
    if(a==1){
        return buatorder1();
    }
    else if(a==2){
        bayar1();
    }else {
        puts("Pilihan salah");
        return bayar();
    }

}

int pesanpaket()
{
    int a,b1;
    puts("=====Pesan Paket=====");
    puts("1.Lihat Menu Paket");
    puts("2.Pesan menu");
    puts("3.Kembali");
    printf("Masukan Pilihan : ");
    scanf("%d",&a);
    switch(a){
        case 1:
        puts("Menu Paket : ");
            for(i=0; i<jum; i++)
            {
                printf ("#%d ", i+1);
                puts(nilai[i].menupaket);
            }
            return pesanpaket();
            case 2:
            printf("Pesan sesuai nomor : ");
            scanf("%d",&b1);
            if(b1-1>jum){
                puts("Pilihan salah");
                return pesanpaket();
            }
            puts("Menu pesanan anda : ");
            puts(nilai[b1-1].menupaket);
            total = total + nilai[b1-1].hargapaket;
            bayar();
            break;
            case 3:
            return buatorder1();
            break;
            default :
            puts("Pilihan salah");
            return pesanpaket();
    }
    return 0;
}

void pesanunit()
{
    int a,a1;
    puts("=====Pesan Unit=====");
    puts("1.Lihat Menu Paket");
    puts("2.Pesan menu");
    puts("3.Kembali");
    printf("Masukan Pilihan : ");
    scanf("%d",&a);
    switch(a){
        case 1:
        puts("Menu Unit : ");
            for(i=0; i<b; i++)
            {
                puts(nilai[i].menupisah);
            }
            return pesanunit();
        break;
        case 2:
        printf("Pesan sesuai nomor : ");
        scanf("%d",&a1);
        if(a1-1>jum){
                puts("Pilihan salah");
                return pesanunit();
            }
            puts("Menu pesanan anda : ");
            puts(nilai[a1-1].menupisah);
            total = total + nilai[a1-1].hargapisah;
            bayar();
    }
}

int buatorder1()
{
    int buatorder;
        puts("=====================================================================================================================");
        puts("Buat Order :");
        puts("1.Pesan Paket");
        puts("2.Custom Paket");
        puts("3.Pesan Perunit");
        puts("4.Kembali ke Menu Utama");
        puts("=====================================================================================================================");
        printf("Masukkan Pilihan : ");
        scanf("%d", &buatorder);
        switch(buatorder){
            case 1:
            pesanpaket();
            break;
            case 2:

            break;
            case 3:
            pesanunit();
            break;
            case 4:
            return main();
            break;
            default :
            puts("pilihan salah");
            return buatorder1();
            break;
        }
        return 0;
}

int main()
{
    lihatmenu();
    inputharga();
    system("color 0c");
    int pilih;

//awal :
    system("cls");
    puts("=====================================================================================================================");
    puts("\t\t\t\t  Selamat Datang di Resto Pokimane:V");
    puts("\t\t\tContact Person : darryl,yanda,revi,bianca,teguh,ronaldi");
    puts("=====================================================================================================================");
    puts("1.Lihat Menu");
    puts("2.Buat Order");
    puts("3.Pulang");
    puts("=====================================================================================================================");
    printf("Masukan Pilihan : ");
    scanf("%d",&pilih);
    switch (pilih)
    {
    case 1:
        puts("Menu Paket : ");
            for(i=0; i<jum; i++)
            {
                printf("#%d ", i+1);
                puts(nilai[i].menupaket);
            }
            puts(" ");
            puts("Menu Unit : ");
            for(i=0; i<b; i++)
            {
                printf("#%d ", i+1);
                puts(nilai[i].menupisah);
            }
            getch();
        return main();
    case 2:
    buatorder1();
    case 3:
    exit(0);
    break;
    default :
    puts("Pilihan salah");
    return main();
    }

    return 0;
}