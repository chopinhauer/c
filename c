//skor.txt unutma
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int n=0;//soru sayisi
int k=0;//kisi sayisi

void soruekle();
void goruntule();
void sil();
void guncelle();
void oyna();
void yuksekskorlar();

struct kisi
    {   char kisi_ismi[30];             
        int skor;
    }kisiler[500];

struct soru
    {   char soru_kismi[500];             
        char a_sikki[50];
        char b_sikki[50];
        char c_sikki[50];
        char d_sikki[50];
        char e_sikki[50];
        char dogru_sik;
    
    }sorular[500];

int main()
{
    
    FILE *kayit;
	kayit = fopen("kayit.txt","r");
    FILE *skor;
	skor = fopen("skor.txt","r");
    if (kayit == NULL)
    {
	    printf("kayit.txt bulunamadi\n");
        getch();
        exit(0);
    } 
    else
    {
        int x=0;
        while(!feof(kayit)){	
	    fscanf(kayit, "%s %s %s %s %s %s %c", sorular[x].soru_kismi, sorular[x].a_sikki, sorular[x].b_sikki, sorular[x].c_sikki, sorular[x].d_sikki, sorular[x].e_sikki,&sorular[n].dogru_sik);
	    x++;}//soru sayisini bulduk
        n=x-1; // 1 fazla saydığı için eksilttik.  
        fclose(kayit);
        int p=0;
        while(!feof(skor)){	
	    fscanf(skor, "%s %d", kisiler[p].kisi_ismi, &kisiler[p].skor);
	    p++;}//kisi sayisini bulduk
        k=p-1; // 1 fazla saydığı için eksilttik.  
        fclose(skor);
    }
    
    
    //menü
    int menu;
    for(;;)
    {
        printf("kisi sayisi %d",k);//KONTROL İÇİNDİR SİLİNECEK
        printf("soru sayisi %d\n",n); //KONTROL İÇİNDİR  SİLİNECEK 
        printf("1.Oyna\n");
        printf("2.Soru Ekle\n");
        printf("3.Soru Sil\n");
        printf("4.Sorulari Goster ve Guncelle\n");
        printf("5.En Yuksek Skorlari Goster\n");
        printf("6.Cik\n");
        char menu=getch();
        char tekrar='e';



        if (menu=='2')
        {
            while(tekrar=='e' || tekrar=='E') //do while da kullanılabilir.
            {
                soruekle();
                printf("Tekrar eklemek icin e\n");
                tekrar=getch();
            }
        }
        else if(menu=='1')
        {
            oyna();
            getch();
        }
        else if(menu=='3')
        {
            sil();
            getch();
        }
        else if(menu=='4')
        {
            goruntule();
            getch();
        }
        else if(menu=='5')
        {
            yuksekskorlar();
            getch();
        }

        else if (menu=='6')
        {
            exit(0);
        }

    }
}

void soruekle()
{
    FILE *kayit = fopen("kayit.txt", "a+");
    printf("\nSoru kismini yaziniz:");
    gets(sorular[n].soru_kismi);
    printf("\nA sikkini yaziniz:");          
    gets(sorular[n].a_sikki);
    printf("\nB sikkini yaziniz:"); 
    gets(sorular[n].b_sikki);
    printf("\nC sikkini yaziniz:"); 
    gets(sorular[n].c_sikki);
    printf("\nD sikkini yaziniz:"); 
    gets(sorular[n].d_sikki);
    printf("\nE sikkini yaziniz:"); 
    gets(sorular[n].e_sikki);
    printf("\nDogru sikki yaziniz:");
    sorular[n].dogru_sik=getch();
        for(int i=0;i<50;i++)
        {
            if(sorular[n].soru_kismi[i]==' ')
            {
                sorular[n].soru_kismi[i]='_';
            }
            if(sorular[n].a_sikki[i]==' ')
            {
                sorular[n].a_sikki[i]='_';
            }
            if(sorular[n].b_sikki[i]==' ')
            {
                sorular[n].b_sikki[i]='_';
            }
            if(sorular[n].c_sikki[i]==' ')
            {
                sorular[n].c_sikki[i]='_';
            }
            if(sorular[n].d_sikki[i]==' ')
            {
                sorular[n].d_sikki[i]='_';
            }
            if(sorular[n].e_sikki[i]==' ')
            {
                sorular[n].e_sikki[i]='_';
            }
        }
    
    fprintf(kayit, "%s\n%s\n%s\n%s\n%s\n%s\n%c\n", sorular[n].soru_kismi, sorular[n].a_sikki, sorular[n].b_sikki, sorular[n].c_sikki, sorular[n].d_sikki, sorular[n].e_sikki, sorular[n].dogru_sik);
    n++;
    fclose(kayit); 
}

void goruntule()
{
	FILE *kayit;			
	kayit = fopen("kayit.txt", "a+");
    FILE *yeni=fopen("yeni.txt","a+");
    int x;
    for(x=0;x<n;x++) 
    {
        fscanf(kayit, "%s %s %s %s %s %s %c", sorular[x].soru_kismi, sorular[x].a_sikki, sorular[x].b_sikki, sorular[x].c_sikki, sorular[x].d_sikki, sorular[x].e_sikki,&sorular[x].dogru_sik);
    }
    
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<50;i++)
        {
            if(sorular[j].soru_kismi[i]=='_')
            {
                sorular[j].soru_kismi[i]=' ';
            }
            if(sorular[j].a_sikki[i]=='_')
            {
                sorular[j].a_sikki[i]=' ';
            }
            if(sorular[j].b_sikki[i]=='_')
            {
                sorular[j].b_sikki[i]=' ';
            }
            if(sorular[j].c_sikki[i]=='_')
            {
                sorular[j].c_sikki[i]=' ';
            }
            if(sorular[j].d_sikki[i]=='_')
            {
                sorular[j].d_sikki[i]=' ';
            }
            if(sorular[j].e_sikki[i]=='_')
            {
                sorular[j].e_sikki[i]=' ';
            }
            

        }
    }    
    	if(n==0)
        {
		printf("Hic kayit bulunamamistir\n");
        }
        
        for(x=0;x<n;x++) 
        {	 
            
		    printf("\n%d Numarali kayit:\n",x);
            printf("Soru: %s\n",sorular[x].soru_kismi);
            printf("a)%s\n",sorular[x].a_sikki);
            printf("b)%s\n",sorular[x].b_sikki);
            printf("c)%s\n",sorular[x].c_sikki);
            printf("d)%s\n",sorular[x].d_sikki);
            printf("e)%s\n",sorular[x].e_sikki);
            printf("Dogru sik: %c\n",sorular[x].dogru_sik);
        }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<50;i++)
        {
            if(sorular[j].soru_kismi[i]==' ')
            {
                sorular[j].soru_kismi[i]='_';
            }
            if(sorular[j].a_sikki[i]==' ')
            {
                sorular[j].a_sikki[i]='_';
            }
            if(sorular[j].b_sikki[i]==' ')
            {
                sorular[j].b_sikki[i]='_';
            }
            if(sorular[j].c_sikki[i]==' ')
            {
                sorular[j].c_sikki[i]='_';
            }
            if(sorular[j].d_sikki[i]==' ')
            {
                sorular[j].d_sikki[i]='_';
            }
            if(sorular[j].e_sikki[i]==' ')
            {
                sorular[j].e_sikki[i]='_';
            }
        }
    }  

        printf("Soru guncellemek ister misiniz?(E/H)");
        char kontrol=getch();
        int soruno;
        char hangi;
        if (kontrol=='E' || kontrol=='e')
        {
            printf("\nGuncellemek istediginiz soru numarasini giriniz.");
            //scanf("%d",soruno);
            soruno=5;//silinecek bug test
            printf("\nDegistirmek istediniz sikki giriniz.Soru kismini degistirmek icin 1, dogru cevabi degistirmek icin 2 giriniz");
            hangi=getchar();
            if(hangi=='1')
            {
                    printf("\nYeni soruyu yaziniz:");
                    gets(sorular[soruno].soru_kismi);
            }
            if(hangi=='2')
            {
                    printf("\nYeni dogru cevabi yaziniz:");
                    sorular[soruno].dogru_sik=getchar();//buglu
            }
            if(hangi=='a')
            {
                    printf("\nYeni a sikkini yaziniz:");
                    gets(sorular[soruno].a_sikki);
            }
            if(hangi=='b')
            {
                    printf("\nYeni b sikkini yaziniz:");
                    gets(sorular[soruno].b_sikki);
            }
            if(hangi=='c')
            {
                    printf("\nYeni c sikkini yaziniz:");
                    gets(sorular[soruno].c_sikki);
            }
            if(hangi=='d')
            {
                    printf("\nYeni d sikkini yaziniz:");
                    gets(sorular[soruno].d_sikki);
            }
            if(hangi=='e')
            {
                    printf("\nYeni e sikkini yaziniz:");
                    gets(sorular[soruno].e_sikki);
            }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<50;i++)
        {
            if(sorular[j].soru_kismi[i]==' ')
            {
                sorular[j].soru_kismi[i]='_';
            }
            if(sorular[j].a_sikki[i]==' ')
            {
                sorular[j].a_sikki[i]='_';
            }
            if(sorular[j].b_sikki[i]==' ')
            {
                sorular[j].b_sikki[i]='_';
            }
            if(sorular[j].c_sikki[i]==' ')
            {
                sorular[j].c_sikki[i]='_';
            }
            if(sorular[j].d_sikki[i]==' ')
            {
                sorular[j].d_sikki[i]='_';
            }
            if(sorular[j].e_sikki[i]==' ')
            {
                sorular[j].e_sikki[i]='_';
            }
        }
    }  
    
            for(int i=0;i<n;i++)
            fprintf(yeni, "%s\n%s\n%s\n%s\n%s\n%s\n%c\n", sorular[i].soru_kismi, sorular[i].a_sikki, sorular[i].b_sikki, sorular[i].c_sikki, sorular[i].d_sikki, sorular[i].e_sikki, sorular[i].dogru_sik);
            	
            fclose(kayit);
	        fclose(yeni);
		
	        remove("kayit.txt");
	        rename("yeni.txt", "kayit.txt");
            
        }
 
	}



void sil()
{
	FILE *eski, *yeni; 
    int q,r,x;
	eski=fopen("kayit.txt", "r");
	yeni=fopen("kayit1.txt", "w+"); 
    for(int x=0;x<n;x++) 
    {
        fscanf(eski, "%s %s %s %s %s %s %c", sorular[x].soru_kismi, sorular[x].a_sikki, sorular[x].b_sikki, sorular[x].c_sikki, sorular[x].d_sikki, sorular[x].e_sikki,&sorular[x].dogru_sik);
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<50;i++)
        {
            if(sorular[j].soru_kismi[i]=='_')
            {
                sorular[j].soru_kismi[i]=' ';
            }
            if(sorular[j].a_sikki[i]=='_')
            {
                sorular[j].a_sikki[i]=' ';
            }
            if(sorular[j].b_sikki[i]=='_')
            {
                sorular[j].b_sikki[i]=' ';
            }
            if(sorular[j].c_sikki[i]=='_')
            {
                sorular[j].c_sikki[i]=' ';
            }
            if(sorular[j].d_sikki[i]=='_')
            {
                sorular[j].d_sikki[i]=' ';
            }
            if(sorular[j].e_sikki[i]=='_')
            {
                sorular[j].e_sikki[i]=' ';
            }
            

        }
    }  

    if(n==0)
    {
		printf("Hic kayit bulunamamistir\n");
    }
    
    for(x=0;x<n;x++) 
    {	 	
		printf("\n%d numarali soru:\n",x);
        printf("Soru: %s\n",sorular[x].soru_kismi);
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<50;i++)
        {
            if(sorular[j].soru_kismi[i]==' ')
            {
                sorular[j].soru_kismi[i]='_';
            }
            if(sorular[j].a_sikki[i]==' ')
            {
                sorular[j].a_sikki[i]='_';
            }
            if(sorular[j].b_sikki[i]==' ')
            {
                sorular[j].b_sikki[i]='_';
            }
            if(sorular[j].c_sikki[i]==' ')
            {
                sorular[j].c_sikki[i]='_';
            }
            if(sorular[j].d_sikki[i]==' ')
            {
                sorular[j].d_sikki[i]='_';
            }
            if(sorular[j].e_sikki[i]==' ')
            {
                sorular[j].e_sikki[i]='_';
            }
            
        }
    }  
    printf("Silinecek soru no? :");
	scanf("%d",&q);
    
 	for(r=0;r<n;r++)
    {
		fscanf(eski, "%s %s %s %s %s %s %c", sorular[r].soru_kismi, sorular[r].a_sikki, sorular[r].b_sikki, sorular[r].c_sikki, sorular[r].d_sikki, sorular[r].e_sikki,&sorular[r].dogru_sik);
		if(r!=q)
        {
			fprintf(yeni,"%s\n%s\n%s\n%s\n%s\n%s\n%c\n", sorular[r].soru_kismi, sorular[r].a_sikki, sorular[r].b_sikki, sorular[r].c_sikki, sorular[r].d_sikki, sorular[r].e_sikki, sorular[r].dogru_sik);	
		}
	} 

	fclose(eski);
	fclose(yeni);
		
	remove("kayit.txt");
	rename("kayit1.txt", "kayit.txt");

    if(n>0)
	n--;

getchar();

}

void oyna()
{
    FILE *kayit;			
	kayit = fopen("kayit.txt", "r");
    FILE *skor;			
	skor = fopen("skor.txt", "w");

    for(int x=0;x<k;x++) 
    {
        fscanf(skor, "%s %d", kisiler[x].kisi_ismi, &kisiler[x].skor);
    }
    


    printf("\nIsminizi yaziniz:");
    gets(kisiler[k].kisi_ismi);
    kisiler[k].skor=0;
    


    char cevap;
    if(n<5)
    {
        printf("5'den fazla soru olmadan oynayamazsiniz.");
    }
    
    else
    {
        for(int x=0;x<n;x++) 
        {
            fscanf(kayit, "%s %s %s %s %s %s %c", sorular[x].soru_kismi, sorular[x].a_sikki, sorular[x].b_sikki, sorular[x].c_sikki, sorular[x].d_sikki, sorular[x].e_sikki,&sorular[x].dogru_sik);
        }


        for(int j=0;j<n;j++)
        {
            for(int i=0;i<50;i++)
            {
                if(sorular[j].soru_kismi[i]=='_')
                {
                    sorular[j].soru_kismi[i]=' ';
                }
                if(sorular[j].a_sikki[i]=='_')
                {
                    sorular[j].a_sikki[i]=' ';
                }
                if(sorular[j].b_sikki[i]=='_')
                {
                    sorular[j].b_sikki[i]=' ';
                }
                if(sorular[j].c_sikki[i]=='_')
                {
                    sorular[j].c_sikki[i]='_';
                }
                if(sorular[j].d_sikki[i]=='_')
                {
                    sorular[j].d_sikki[i]=' ';
                }
                if(sorular[j].e_sikki[i]=='_')
                {
                    sorular[j].e_sikki[i]=' ';
                }
            

        }
    }  
        int a,b,c,d,e;
        srand(time(NULL));
        a=rand()%n;
        do{
            b=rand()%n;
        }while(b==a);
        do{
            c=rand()%n;
        }while(c==a || c==b);
        do{
            d=rand()%n;
        }while(d==a || d==b || d==c);
        do{
            e=rand()%n;
        }while(e==a || e==b || e==c || e==d);

        printf("\nSoru 1: %s",sorular[a].soru_kismi);
        printf("\na)%s",sorular[a].a_sikki);
        printf("\nb)%s",sorular[a].b_sikki);
        printf("\nc)%s",sorular[a].c_sikki);
        printf("\nd)%s",sorular[a].d_sikki);
        printf("\ne)%s",sorular[a].e_sikki);
        printf("\nCevap giriniz.");
        cevap=getch();
        if (cevap==sorular[a].dogru_sik)
        {
            printf("\nTebrikler.");
            kisiler[k].skor=kisiler[k].skor + 1;
        }
        else
        {
            printf("\nYanlis.Dogru cevap %c",sorular[a].dogru_sik);
        }

        printf("\nSoru 2: %s",sorular[b].soru_kismi);
        printf("\na)%s",sorular[b].a_sikki);
        printf("\nb)%s",sorular[b].b_sikki);
        printf("\nc)%s",sorular[b].c_sikki);
        printf("\nd)%s",sorular[b].d_sikki);
        printf("\ne)%s",sorular[b].e_sikki);
        printf("\nCevap giriniz.");
        cevap=getch();
        if (cevap==sorular[b].dogru_sik)
        {
            printf("\nTebrikler.");
            kisiler[k].skor=kisiler[k].skor + 1;
        }
        else
        {
            printf("\nYanlis.Dogru cevap %c",sorular[b].dogru_sik);
        }

        printf("\nSoru 3: %s",sorular[c].soru_kismi);
        printf("\na)%s",sorular[c].a_sikki);
        printf("\nb)%s",sorular[c].b_sikki);
        printf("\nc)%s",sorular[c].c_sikki);
        printf("\nd)%s",sorular[c].d_sikki);
        printf("\ne)%s",sorular[c].e_sikki);
        printf("\nCevap giriniz.");
        cevap=getch();
        if (cevap==sorular[c].dogru_sik)
        {
            printf("\nTebrikler.");
            kisiler[k].skor=kisiler[k].skor + 1;
        }
        else
        {
            printf("\nYanlis.Dogru cevap %c",sorular[c].dogru_sik);
        }

        printf("\nSoru 4: %s",sorular[d].soru_kismi);
        printf("\na)%s",sorular[d].a_sikki);
        printf("\nb)%s",sorular[d].b_sikki);
        printf("\nc)%s",sorular[d].c_sikki);
        printf("\nd)%s",sorular[d].d_sikki);
        printf("\ne)%s",sorular[d].e_sikki);
        printf("\nCevap giriniz.");
        cevap=getch();
        if (cevap==sorular[d].dogru_sik)
        {
            printf("\nTebrikler.");
            kisiler[k].skor=kisiler[k].skor + 1;
        }
        else
        {
            printf("\nYanlis.Dogru cevap %c",sorular[d].dogru_sik);
        }

        printf("\nSoru 5: %s",sorular[e].soru_kismi);
        printf("\na)%s",sorular[e].a_sikki);
        printf("\nb)%s",sorular[e].b_sikki);
        printf("\nc)%s",sorular[e].c_sikki);
        printf("\nd)%s",sorular[e].d_sikki);
        printf("\ne)%s",sorular[e].e_sikki);
        printf("\nCevap giriniz.");
        cevap=getch();
        if (cevap==sorular[e].dogru_sik)
        {
            printf("\nTebrikler.");
            kisiler[k].skor=kisiler[k].skor + 1;
        }
        else
        {
            printf("\nYanlis.Dogru cevap %c",sorular[e].dogru_sik);
        }
        printf("Skorunuz %d",kisiler[k].skor);


        for(int x=0;x<=k;x++)
        fprintf(skor, "%s\n%d\n", kisiler[x].kisi_ismi,kisiler[x].skor);
        k++;
    }

}

void yuksekskorlar()
{
    FILE *skor;
	skor = fopen("skor.txt","r");

    for(int x=0;x<k;x++) 
    {
        fscanf(skor, "%s %d", kisiler[x].kisi_ismi, &kisiler[x].skor);
    }
    
    if(k==0)
    {
		printf("Hic kayit bulunamamistir\n");
    }
        
    for(int x=0;x<k;x++) 
    {	 
            
		printf("\n%s adli kisinin skoru: %d",kisiler[x].kisi_ismi,kisiler[x].skor);

    }     
}
