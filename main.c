#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

struct musteri{
	int mID;
	char kimlikNumarasi[20],adi[20],soyadi[20],dogumTarihi[20],cepTelefonu[20],emailAdresi[50],parola[50],vergiNumarasi[50],sirketAdi[50],kayitTuru[50];
}m;

struct araba{
	int ID,fiyat;
	char marka[50],model[50];
}a;

struct banka{
	int ID;
	char adi[50];
}b;

struct ofis{
	int durum;
	char siraNo[50],adi[50],adres[50],telefon[50],email[50];
}o;

struct iletisim{
	char metin[50],telefon[50],email[50];
}iletisimm;
struct tarih{
	int gun[2],ay[2],yil[2],i,sonuc,hesapla;
}t;
struct transfers{
	int otelID,havalimaniID,fiyat;
	char otelAdi[50],havalimaniAdi[50];
}transfers;

int dilSecim;
int mSira;
void girisYap(){
	system("cls");
	int secim;
	FILE *dosya = fopen("veritabani/musteriBilgileri.dat","r+");
	char emailAdresi[50],parola[50];
	if(dilSecim==0){
	printf("\t\t\t\t\t\tARA� K�RALAMA");
	while(secim!=2){
	printf("\n1 - Devam Et");
	printf("\n2 - Geri D�n");
	printf("\nSe�iminiz: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			system("cls");
			printf("\t\t\t\t\t\tARA� K�RALAMA\n");
			printf("Email Adresi: ");
			scanf("%s",&emailAdresi);
			printf("Parola: ");
			scanf("%s",&parola);
			while(fread(&m,sizeof(struct musteri),1,dosya)){
				if(strcmp(emailAdresi, m.emailAdresi) == 0 && strcmp(parola, m.parola) == 0){
					mSira = m.mID;
					musteriMenu();
				}else{
						printf("E-Mail adresi veya Parola Hatal�...\n");
					 }				
			}
			fclose(dosya);
		break;
		case 2: main(); break;
		default: printf("Hatal� Se�im Yap�ld�...\n"); break;
		}		
	 }
	}
	else{
	printf("\t\t\t\t\t\tRENT A CAR");
	while(secim!=2){
	printf("\n1 - Continue");
	printf("\n2 - Return");
	printf("\nYour Choice: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			system("cls");
			printf("\t\t\t\t\t\tRENT A CAR\n");
			printf("Email Address:");
			scanf("%s",&emailAdresi);
			printf("Password: ");
			scanf("%s",&parola);
			while(fread(&m,sizeof(struct musteri),1,dosya)){
				if(strcmp(emailAdresi, m.emailAdresi) == 0 && strcmp(parola, m.parola) == 0){
					mSira = m.mID;
					musteriMenu();
				}else{
						printf("Wrong Username or Password...\n");
					 }				
			}
			fclose(dosya);
		break;
		case 2: main(); break;
		default: printf("You made a wrong choice...\n"); break;
		}		
	 }
	}
}

void kayitOl(){
	setlocale(LC_ALL,"Turkish");
	system("cls");
	FILE *dosya = fopen("veritabani/musteriBilgileri.dat","a+b");
	int sonuc=0,secim,dosyaUzunlugu,musteriID;
	if(dilSecim==0){
	if (dosya == NULL){
		printf("musteriBilgileri.dat Dosyas� A��lamad�...");
		exit(0);
	}
	fseek(dosya,0,SEEK_END);
	dosyaUzunlugu = ftell(dosya);
	if(dosyaUzunlugu == 0){
		musteriID = 1;
	}else{
		rewind(dosya);
		while(!feof(dosya)){
			fread(&m,sizeof(struct musteri),1,dosya);
			musteriID = m.mID;
		}
		musteriID++;
	}
	printf("\t\t\t\t\t\tARA� K�RALAMA\n");
	while(secim!=2){
	printf("\n1 - Devam Et");
	printf("\n2 - Geri D�n");
	printf("\nSe�iminiz: ");
	scanf("%d",&secim);
	switch(secim){
		case 1: 
		system("cls");
		printf("\t\t\t\t\t\tARA� K�RALAMA\n");
			printf("Kimlik Numaras�: ");
			scanf("%s",m.kimlikNumarasi);
			printf("Ad�n�z: ");
			scanf("%s",m.adi);
			printf("Soyad�n�z: ");
			scanf("%s",m.soyadi);
			printf("Do�um Tarihi: ");
			scanf("%s",m.dogumTarihi);
			printf("Cep Telefonu: ");
			scanf("%s",m.cepTelefonu);
			printf("Email Adresi: ");
			scanf("%s",m.emailAdresi);
			printf("Parola: ");
			scanf("%s",m.parola);
			printf("1 - Bireysel\t2 - Kurumsal\n");
			printf("Kay�t T�r�(1/2): ");
			scanf("%s",m.kayitTuru);
			if(strcmp(m.kayitTuru, "2") == 0){
				printf("Vergi Numaras�: ");
				scanf("%s",m.vergiNumarasi);
				printf("�irket Ad�: ");
				scanf("%s",m.sirketAdi);
			}
				sonuc=1;
			if(sonuc==1){
				rewind(dosya);
				m.mID = musteriID;
				fseek(dosya,(musteriID-1)*sizeof(struct musteri),SEEK_SET);
				fwrite(&m,sizeof(struct musteri),1,dosya);
				printf("Kay�t ��lemi Ba�ar�l�");
				fclose(dosya);
			}else{
				printf("Kay�t ��lemi Ba�ar�s�z");
				system("cls");
				kayitOl();
			}
		break;
		case 2: main(); break;
		default: printf("Hatal� Se�im Yap�ld�...\n"); break;
		}		
	 }		
	}
	else{
	if (dosya == NULL){
		printf("musteriBilgileri.dat File Can Not Be Open...");
		exit(0);
	}
	fseek(dosya,0,SEEK_END);
	dosyaUzunlugu = ftell(dosya);
	if(dosyaUzunlugu == 0){
		musteriID = 1;
	}else{
		rewind(dosya);
		while(!feof(dosya)){
			fread(&m,sizeof(struct musteri),1,dosya);
			musteriID = m.mID;
		}
		musteriID++;
	}
	printf("\t\t\t\t\t\tRENT A CAR\n");
	while(secim!=2){
	printf("\n1 - Continue");
	printf("\n2 - Return");
	printf("\nYour Choice: ");
	scanf("%d",&secim);
	switch(secim){
		case 1: 
		system("cls");
		printf("\t\t\t\t\t\tRENT A CAR\n");
			printf("Identification Number: ");
			scanf("%s",m.kimlikNumarasi);
			printf("Your Name: ");
			scanf("%s",m.adi);
			printf("Your Surname:");
			scanf("%s",m.soyadi);
			printf("Birthday: ");
			scanf("%s",m.dogumTarihi);
			printf("Phone Number: ");
			scanf("%s",m.cepTelefonu);
			printf("Email Address:");
			scanf("%s",m.emailAdresi);
			printf("Password:");
			scanf("%s",m.parola);
			printf("1 - Individual\t2 - Institutional\n");
			printf("Registration Type(1/2): ");
			scanf("%s",m.kayitTuru);
			if(strcmp(m.kayitTuru, "2") == 0){
				printf("Tax Number: ");
				scanf("%s",m.vergiNumarasi);
				printf("Company Name:");
				scanf("%s",m.sirketAdi);
			}
				sonuc=1;
			if(sonuc==1){
				rewind(dosya);
				m.mID = musteriID;
				fseek(dosya,(musteriID-1)*sizeof(struct musteri),SEEK_SET);
				fwrite(&m,sizeof(struct musteri),1,dosya);
				printf("Registration Successful");
				fclose(dosya);
			}else{
				printf("Registration Failed");
				system("cls");
				kayitOl();
			}
		break;
		case 2: main(); break;
		default: printf("You Made a Wrong Choice...\n"); break;
		}		
	 }	
	}
}

void yoneticiGiris(){
	system("cls");
	int secim;
	char kAdi[50],kParola[50];
	if(dilSecim==0){
	printf("\t\t\t\t\t\tARA� K�RALAMA");
	while(secim!=2){
	printf("\n1 - Devam Et");
	printf("\n2 - Geri D�n");
	printf("\nSe�iminiz: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			system("cls");
			printf("\t\t\t\t\t\tARA� K�RALAMA\n");
			printf("Kullan�c� Ad�: ");
			scanf("%s",&kAdi);
			printf("Parola: ");
			scanf("%s",&kParola);
			if(strcmp(kAdi,"admin") == 0 && strcmp(kParola,"1234") == 0){
				yoneticiMenu();
			}else{
				printf("Kullan�c� Ad� veya Parola Hatal�...\n");
			}
		break;
		case 2: main(); break;
		default: printf("Hatal� Se�im Yap�ld�...\n"); break;
		}		
	}		
	}
	else{
	printf("\t\t\t\t\t\tRENT A CAR\n");
	while(secim!=2){
	printf("\n1 - Next");
	printf("\n2 - Return");
	printf("\nYour Choice: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			system("cls");
			printf("\t\t\t\t\t\tRENT A CAR");	
			printf("User Name: ");
			scanf("%s",&kAdi);
			printf("Password: ");
			scanf("%s",&kParola);
			if(strcmp(kAdi,"admin") == 0 && strcmp(kParola,"1234") == 0){
				yoneticiMenu();
			}else{
				printf("Wrong Username or Password...\n");
			}
		break;
		case 2: main(); break;
		default: printf("You Made a Wrong Choice...\n"); break;
		}		
	}		
	}
}

int ayarlar(){
	system("cls");
	printf("\t\t\t\t\t\tARA� K�RALAMA\n");
	int secim;
	if(dilSecim==0){
	while(secim!=3){
	printf("1 - Dil");
	printf("\n2 - Geri D�n");
	printf("\n3 - ��k�� Yap");
	printf("\nSe�iminiz: ");
	scanf("%d",&secim);
	switch(secim){
		case 1: dil(); break;
		case 2: main(); break;
		case 3: printf("��k�� Yap�ld�..."); break;
		default: printf("Hatal� Se�im Yap�ld�...\n"); break;
		}
	}
	exit(0);
	return 0;		
	}
	else{
	while(secim!=3){
	printf("1 - Language");
	printf("\n2 - Return");
	printf("\n3 - Log Out");
	printf("\nYour Choice: ");
	scanf("%d",&secim);
	switch(secim){
		case 1: dil(); break;
		case 2: main(); break;
		case 3: printf("Exited..."); break;
		default: printf("You Made a Wrong Choice...\n"); break;
		}
	}
	exit(0);
	return 0;
	}

}

int dil(){
	system("cls");
	if(dilSecim==0){
	printf("\t\t\t\t\t\tARA� K�RALAMA");
	int secim;
	while(secim!=4){
	printf("\n1- T�rk�e");
	printf("\n2- �ngilizce");
	printf("\n3- Geri D�n");
	printf("\n4- ��k�� Yap");
	printf("\nSe�iminiz: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:	dilSecim=0; ayarlar(); break;
		case 2: dilSecim=1; ayarlar(); break;
		case 3: ayarlar(); break;
		case 4: printf("��k�� Yap�ld�..."); break;
		default: printf("Hatal� Se�im Yap�ld�...\n"); break;
		}		
	}
	exit(0);
	return 0;			
	}
	else{
	printf("\t\t\t\t\t\tRENT A CAR");
	int secim;
	while(secim!=4){
	printf("\n1- Turkish");
	printf("\n2- English");
	printf("\n3- Return");
	printf("\n4- Log Out");
	printf("\nYour Choice: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:	dilSecim=0; ayarlar(); break;
		case 2: dilSecim=1; ayarlar(); break;
		case 3: ayarlar(); break;
		case 4: printf("Exited..."); break;
		default: printf("You Made a Wrong Choice...\n"); break;
		}		
	}
	exit(0);
	return 0;			
	}
}
int tHesap,musteriSecim;
int musteriMenu(){
	system("cls");
	if(dilSecim==0){
	printf("\t\t\t\t\t\tARA� K�RALAMA");
	FILE *dosya = fopen("veritabani/musteriBilgileri.dat","r+");
	while(fread(&m,sizeof(struct musteri),1,dosya)){
		if(mSira == m.mID){
			printf("\nHo� Geldiniz %s %s",m.adi,m.soyadi);
		}
	}
	fclose(dosya);
    while(musteriSecim!=9){
    printf("\n1 - Araba Kiralama");
    printf("\n2 - Transfer");
    printf("\n3 - Rezervasyon");
    printf("\n4 - Kampanyalar");
    printf("\n5 - Ofislerimiz");
    printf("\n6 - Hakk�m�zda");
    printf("\n7 - �leti�im");
    printf("\n8 - Geri D�n");
    printf("\n9 - ��k�� Yap");
    printf("\nSe�iminiz: ");
    scanf("%d",&musteriSecim);
    switch(musteriSecim){
        case 1: tarihIslem(); break;
        case 2: tarihIslem(); break;
        case 3: rezervasyon(); break;
        case 4: kampanyalar(); break;
        case 5: ofislerimiz(); break;
        case 6: hakkimizda(); break;
        case 7: iletisim(); break;
        case 8: main(); break;
        case 9: printf("��k�� Yap�ld�..."); break;
        default: printf("Hatal� Se�im Yap�ld�...\n"); break;
    	}    	
	}
	exit(0);
	return 0;		
	}
	printf("\t\t\t\t\t\tRENT A CAR");
	FILE *dosya = fopen("veritabani/musteriBilgileri.dat","r+");
	while(fread(&m,sizeof(struct musteri),1,dosya)){
		if(mSira == m.mID){
			printf("\nWelcome %s %s",m.adi,m.soyadi);
		}
	}
	fclose(dosya);
    while(musteriSecim!=9){
    printf("\n1 - Car Rental");
    printf("\n2 - Transfer");
    printf("\n3 - Reservation");
    printf("\n4 - Campaigns");
    printf("\n5 - Our Offices");
    printf("\n6 - About Us");
    printf("\n7 - Contact Information");
    printf("\n8 - Turn Back");
    printf("\n9 - Log Out");
    printf("\nYour Choice: ");
    scanf("%d",&musteriSecim);
    switch(musteriSecim){
        case 1: tarihIslem(); break;
        case 2: tarihIslem(); break;
        case 3: rezervasyon(); break;
        case 4: kampanyalar(); break;
        case 5: ofislerimiz(); break;
        case 6: hakkimizda(); break;
        case 7: iletisim(); break;
        case 8: main(); break;
        case 9: printf("Exited..."); break;
        default: printf("You Made a Wrong Choice...\n"); break;
    	}    	
	}
	exit(0);
	return 0;
}

int gun1,ay1,yil1,gun2,ay2,yil2,tHesap;
int tarihIslem(){
	system("cls");
	printf("\t\t\t\t\t\tARA� K�RALAMA\n");
	int i;
	if(dilSecim==0){
	for(i=1;i<=2;i++){
			printf("%d. Tarih Giriniz (g�n.ay.y�l): ",i);
			scanf("%d.%d.%d",&t.gun[i],&t.ay[i],&t.yil[i]);
			if((t.gun[i]>0 && t.gun[i]<32)&&(t.ay[i]>0 && t.ay[i]<13)&&(t.yil[i]>2022 && t.yil[i]<2025)){
				t.sonuc=1;
			}		
		}	
		if(t.sonuc==1){
			t.hesapla = t.gun[1]+(t.ay[1]*30)+(t.yil[1]*365)-(t.gun[2]+(t.ay[2]*30)+t.yil[2]*365);
		if(t.hesapla<0){
				t.hesapla = 0 - t.hesapla;
			}
			tHesap = t.hesapla;
			gun1 = t.gun[1];
			ay1 = t.ay[1];
			yil1 = t.yil[1];
			gun2 = t.gun[2];
			ay2 = t.ay[2];
			yil2 = t.yil[2];
			if(musteriSecim==1){
				aKiralama();
			}else{
				transferMenu();
			}
		}else{
		printf("Ge�erli formatta giriniz. g�n.ay.y�l �eklinde giriniz.\n");
		}
		return 0;
	}
	else{
		system("cls");
		printf("\t\t\t\t\t\tRENT A CAR\n");
		for(i=1;i<=2;i++){
			printf("%d. Enter Date (day.month.year): ",i);
			scanf("%d.%d.%d",&t.gun[i],&t.ay[i],&t.yil[i]);
			if((t.gun[i]>0 && t.gun[i]<32)&&(t.ay[i]>0 && t.ay[i]<13)&&(t.yil[i]>2022 && t.yil[i]<2025)){
				t.sonuc=1;
			}		
		}	
		if(t.sonuc==1){
			t.hesapla = t.gun[1]+(t.ay[1]*30)+(t.yil[1]*365)-(t.gun[2]+(t.ay[2]*30)+t.yil[2]*365);
		if(t.hesapla<0){
				t.hesapla = 0 - t.hesapla;
			}
			tHesap = t.hesapla;
			gun1 = t.gun[1];
			ay1 = t.ay[1];
			yil1 = t.yil[1];
			gun2 = t.gun[2];
			ay2 = t.ay[2];
			yil2 = t.yil[2];
			if(musteriSecim==1){
				aKiralama();
			}else{
				transferMenu();
			}	
		}else{
			printf("Enter in valid format. Enter as day.month.year.\n");
		}
		return 0;
	}
}
int arabaNo;
int aKiralama(){
	system("cls");
	if(dilSecim==0){
	int secim,sonuc=0;	
	FILE *dosya = fopen("veritabani/arabalar.txt","r");
	FILE *dosya2 = fopen("veritabani/arabalar.txt","r");
	if(dosya == NULL && dosya2 == NULL){
		printf("Dosya Bulunamad�...");
	}else{
	printf("\t\t\t\t\t\tARA� K�RALAMA\n");
	while(!feof(dosya2)){
		fscanf(dosya2,"%d\t%s\t%s\t%d\n",&a.ID,a.marka,a.model,&a.fiyat);
		printf("\n%d\t%s\t%s\t%d",a.ID,a.marka,a.model,a.fiyat);
	}
	fclose(dosya2);
	printf("\nS�ra No Giriniz: ");
	scanf("%d",&arabaNo);
	while(!feof(dosya)){
		fscanf(dosya,"%d\t%s\t%s\t%d\n",&a.ID,a.marka,a.model,&a.fiyat);
		if(arabaNo == a.ID){
			sonuc=1;
			break;
		}
	}
			if(sonuc==0){
			printf("Girdi�iniz s�ra numaras�nda ara� bulunamad�...");
			aKiralama();
			}
	fclose(dosya);
		if(mSira!=0){
			mOdeme();
		}else{
			uyesizMusteri();
		}
	return 0;		
	}
	}
	else{
	int secim,sonuc=0;	
	FILE *dosya = fopen("veritabani/arabalar.txt","r");
	FILE *dosya2 = fopen("veritabani/arabalar.txt","r");
	if(dosya == NULL && dosya2 == NULL){
	printf("Dosya Bulunamad�...");
	}else{
	printf("\t\t\t\t\t\tRENT A CAR\n");
	while(!feof(dosya2)){
		fscanf(dosya2,"%d\t%s\t%s\t%d\n",&a.ID,a.marka,a.model,&a.fiyat);
		printf("\n%d\t%s\t%s\t%d",a.ID,a.marka,a.model,a.fiyat);
	}
	fclose(dosya2);
	printf("\nEnter Your Sequence Number: ");
	scanf("%d",&arabaNo);
	while(!feof(dosya)){
		fscanf(dosya,"%d\t%s\t%s\t%d\n",&a.ID,a.marka,a.model,&a.fiyat);
		if(arabaNo == a.ID){
			sonuc=1;
			break;
		}
	}
			if(sonuc==0){
			printf("No vehicle was found in the sequence number you entered...");
			aKiralama();
		}
	fclose(dosya);
		if(mSira!=0){
			fatura();
		}else{
			uyesizMusteri();
		}
	return 0;
	}
	}
}
int otelNo,havalimaniNo;
int otelSecim(){
	if(dilSecim==0){
		int secim,sonuc=0;	
		FILE *dosya = fopen("veritabani/otel.txt","r");
		FILE *dosya2 = fopen("veritabani/otel.txt","r");
		if(dosya == NULL){
			printf("Dosya Bulunamad�...");
		}else{
		printf("\t\t\t\t\t\tARA� K�RALAMA\n");
		while(!feof(dosya2)){
			fscanf(dosya2,"%d%s",&transfers.otelID,transfers.otelAdi);
			printf("%d\t%s\n",transfers.otelID,transfers.otelAdi);
		}
		fclose(dosya2);
		printf("\nOtel ID Giriniz: ");
		scanf("%d",&otelNo);
		while(!feof(dosya)){
			fscanf(dosya,"%d%s",&transfers.otelID,transfers.otelAdi);
			if(otelNo == transfers.otelID){
				sonuc=1;
				break;
			}
		}
				if(sonuc==0){
				printf("Girdi�iniz otel id bulunamad�...");
				otelSecim();
				}else{
					if(havalimaniNo != 0){
						if(mSira!=0){
							mOdeme();
						}else{
							uyesizMusteri();
						}
					}else{
						havalimaniSecim();
					}
				}
		fclose(dosya);
		return 0;		
		}		
	}else{
	int secim,sonuc=0;	
		FILE *dosya = fopen("veritabani/otel.txt","r");
		FILE *dosya2 = fopen("veritabani/otel.txt","r");
		if(dosya == NULL){
			printf("File not found...");
		}else{
		printf("\t\t\t\t\t\tRENT A CAR\n");
		while(!feof(dosya2)){
			fscanf(dosya2,"%d%s",&transfers.otelID,transfers.otelAdi);
			printf("%d\t%s\n",transfers.otelID,transfers.otelAdi);
		}
		fclose(dosya2);
		printf("\nEnter Hotel ID: ");
		scanf("%d",&otelNo);
		while(!feof(dosya)){
			fscanf(dosya,"%d%s",&transfers.otelID,transfers.otelAdi);
			if(otelNo == transfers.otelID){
				sonuc=1;
				break;
			}
		}
				if(sonuc==0){
				printf("We could not found your hotel id...");
				otelSecim();
				}else{
					if(havalimaniNo != 0){
						if(mSira!=0){
							mOdeme();
						}else{
							uyesizMusteri();
						}
					}else{
						havalimaniSecim();
					}
				}
		fclose(dosya);
		return 0;		
		}
	}
}

int havalimaniSecim(){
	if(dilSecim==0){
		int secim,sonuc=0;	
		FILE *dosya = fopen("veritabani/havalimani.txt","r");
		FILE *dosya2 = fopen("veritabani/havalimani.txt","r");
		if(dosya == NULL){
			printf("Dosya Bulunamad�...");
		}else{
		printf("\t\t\t\t\t\tARA� K�RALAMA\n");
		while(!feof(dosya2)){
			fscanf(dosya2,"%d%s",&transfers.havalimaniID,transfers.havalimaniAdi);
			printf("%d\t%s\n",transfers.havalimaniID,transfers.havalimaniAdi);
		}
		fclose(dosya2);
		printf("\nHavaliman� ID Giriniz: ");
		scanf("%d",&havalimaniNo);
		while(!feof(dosya)){
			fscanf(dosya,"%d%s",&transfers.havalimaniID,transfers.havalimaniAdi);
			if(havalimaniNo == transfers.havalimaniID){
				sonuc=1;
				break;
			}
		}
				if(sonuc==0){
				printf("Girdi�iniz havaliman� id bulunamad�...");
				otelSecim();
				}else{
					if(otelNo != 0){
						if(mSira!=0){
							mOdeme();
						}else{
							uyesizMusteri();
						}
					}else{
						otelSecim();
					}
				}
		fclose(dosya);
		return 0;		
		}		
	}else{
		int secim,sonuc=0;	
		FILE *dosya = fopen("veritabani/havalimani.txt","r");
		FILE *dosya2 = fopen("veritabani/havalimani.txt","r");
		if(dosya == NULL){
			printf("Dosya Bulunamad�...");
		}else{
		printf("\t\t\t\t\t\tRENT A CAR\n");
		while(!feof(dosya2)){
			fscanf(dosya2,"%d%s",&transfers.havalimaniID,transfers.havalimaniAdi);
			printf("%d\t%s\n",transfers.havalimaniID,transfers.havalimaniAdi);
		}
		fclose(dosya2);
		printf("\nEnter Airport ID: ");
		scanf("%d",&havalimaniNo);
		while(!feof(dosya)){
			fscanf(dosya,"%d%s",&transfers.havalimaniID,transfers.havalimaniAdi);
			if(havalimaniNo == transfers.havalimaniID){
				sonuc=1;
				break;
			}
		}
				if(sonuc==0){
				printf("We could not found your airport id...");
				otelSecim();
				}else{
					if(otelNo != 0){
						if(mSira!=0){
							mOdeme();
						}else{
							uyesizMusteri();
						}
					}else{
						otelSecim();
					}
				}
		fclose(dosya);
		return 0;		
		}		
	}
}
int transferSecim;
int transferMenu(){
	system("cls");
	if(dilSecim == 0){
		printf("\t\t\t\t\t\tARA� K�RALAMA\n");
		while(transferSecim!=4){
			printf("1 - Havaliman� -> Otel\n");
			printf("2 - Otel -> Havaliman�\n");
			printf("3 - Geri D�n\n");
			printf("4 - ��k�� Yap\n");
			printf("Se�iminiz: ");
			scanf("%d",&transferSecim);
			switch(transferSecim){
				case 1:	havalimaniSecim(); break;
				case 2: otelSecim(); break;
				case 3: musteriMenu(); break;
				case 4: printf("��k�� Yap�ld�..."); break;
				default: printf("Hatal� Se�im Yap�ld�..."); break;
			}
		}
	exit(0);
	return 0;		
	}else{
		printf("\t\t\t\t\t\tRENT A CAR\n");
		while(transferSecim!=4){
			printf("1 - Airport -> Hotel\n");
			printf("2 - Hotel -> Airport\n");
			printf("3 - Return\n");
			printf("4 - Log Out\n");
			printf("\nYour Choice: ");
			scanf("%d",&transferSecim);
			switch(transferSecim){
				case 1:	havalimaniSecim(); break;
				case 2: otelSecim(); break;
				case 3: musteriMenu(); break;
				case 4: printf("��k�� Yap�ld�..."); break;
				default: printf("Hatal� Se�im Yap�ld�..."); break;
			}
		}
	exit(0);
	return 0;		
	}
}

int uyesizMusteri(){
	if(dilSecim==0){
	system("cls");
	int sonuc=0;
	int secim;
		printf("\t\t\t\t\t\tARA� K�RALAMA\n");
		system("cls");
		printf("\t\t\t\t\t\tARA� K�RALAMA\n");
		printf("Kimlik Numaras�: ");
		scanf("%s",m.kimlikNumarasi);
		printf("Ad�n�z: ");
		scanf("%s",m.adi);
		printf("Soyad�n�z: ");
		scanf("%s",m.soyadi);
		printf("Do�um Tarihi: ");
		scanf("%s",m.dogumTarihi);
		printf("Cep Telefonu: ");
		scanf("%s",m.cepTelefonu);
		printf("Email Adresi: ");
		scanf("%s",m.emailAdresi);
		printf("1 - Bireysel\t2 - Kurumsal\n");
		printf("Kay�t T�r�(1/2): ");
		scanf("%s",m.kayitTuru);
		if(strcmp(m.kayitTuru, "2") == 0){
			printf("Vergi Numaras�: ");
			scanf("%s",m.vergiNumarasi);
			printf("�irket Ad�: ");
			scanf("%s",m.sirketAdi);	
		}
			mOdeme();
			return 0;	
	}
	else{
	system("cls");
	int sonuc=0;
	int secim;
	printf("\t\t\t\t\t\tRENT A CAR\n");
		system("cls");
		printf("\t\t\t\t\t\tRENT A CAR\n");
		printf("Identification Number: ");
		scanf("%s",m.kimlikNumarasi);
		printf("Your Name: ");
		scanf("%s",m.adi);
		printf("Your Surname:");
		scanf("%s",m.soyadi);
		printf("Birthday: ");
		scanf("%s",m.dogumTarihi);
		printf("Phone Number: ");
		scanf("%s",m.cepTelefonu);
		printf("Email Address:");
		scanf("%s",m.emailAdresi);
		printf("Password:");
		scanf("%s",m.parola);
		printf("1 - Individual\t2 - Institutional\n");
		printf("Registration Type(1/2): ");
		scanf("%s",m.kayitTuru);
		if(strcmp(m.kayitTuru, "2") == 0){
			printf("Tax Number: ");
			scanf("%s",m.vergiNumarasi);
			printf("Company Name:");
			scanf("%s",m.sirketAdi);
		}
		mOdeme();
		return 0;		
	}
}

int odemeSecim,bankaSecim;
int mOdeme(){
	if(dilSecim == 0){
		FILE *banka = fopen("veritabani/bankalar.txt","r");
		if(banka != NULL){
		printf("1 - Havale\n");
		printf("2 - Kredi Kart�\n");
		printf("Se�iminiz: ");
		scanf("%d",&odemeSecim);
		switch(odemeSecim){
			case 1:
				while(!feof(banka)){
					fscanf(banka,"%d%s",&b.ID,b.adi);
					printf("%d\t%s\n",b.ID,b.adi);
				}
				fclose(banka);
				printf("�deme yap�lacak banka ID giriniz: ");
				scanf("%d",&bankaSecim);
				fatura();			
			break;
			case 2:
				while(!feof(banka)){
					fscanf(banka,"%d%s",&b.ID,b.adi);
					printf("%d\t%s\n",b.ID,b.adi);
				}
				fclose(banka);
				printf("�deme yap�lacak banka ID giriniz: ");
				scanf("%d",&bankaSecim);
				fatura();
			break;
			default: printf("Hatal� Se�im Yap�ld�...");	break;
		}
	}else{
		printf("Dosya Bulunamad�...");
	}
		return 0;		
	}else{
	FILE *banka = fopen("veritabani/bankalar.txt","r");
		if(banka != NULL){
		printf("1 - Havale\n");
		printf("2 - Kredi Kart�\n");
		printf("Se�iminiz: ");
		scanf("%d",&odemeSecim);
		switch(odemeSecim){
			case 1:
				while(!feof(banka)){
					fscanf(banka,"%d%s",&b.ID,b.adi);
					printf("%d\t%s\n",b.ID,b.adi);
				}
				fclose(banka);
				printf("Please enter the will be payment id: ");
				scanf("%d",&bankaSecim);
				fatura();			
			break;
			case 2:
				while(!feof(banka)){
					fscanf(banka,"%d%s",&b.ID,b.adi);
					printf("%d\t%s\n",b.ID,b.adi);
				}
				fclose(banka);
				printf("Please enter the will be payment id: ");
				scanf("%d",&bankaSecim);
				fatura();
			break;
			default: printf("You Made a Wrong Choice...");	break;
		}
	}else{
		printf("File not found...");
	}
		return 0;
	}
}

int randomSayi,tUcret,aUcret;
int fatura(){
	if(dilSecim==0){
	system("cls");
	int secim;
	srand(time(NULL));
	randomSayi = 1 + rand() %99999;	
	FILE *araba = fopen("veritabani/arabalar.txt","r");
	FILE *dosya = fopen("veritabani/musteriBilgileri.dat","r+");
	FILE *dosya2 = fopen("veritabani/rezervasyon.txt","a");
	FILE *transfer = fopen("veritabani/transfer.txt","r");
	FILE *otel = fopen("veritabani/otel.txt","r");
	FILE *havalimani = fopen("veritabani/havalimani.txt","r");
	if(araba == NULL && dosya == NULL && transfer == NULL && otel == NULL && havalimani == NULL){
		printf("Dosya Bulunamad�...");
	}
	if(mSira!=0){
		while(fread(&m,sizeof(struct musteri),1,dosya)){
			if(mSira == m.mID){
				printf("\nRezervasyon Kodu: %d",randomSayi);
				printf("\nKimlik Numaras�: %s",m.kimlikNumarasi);
				printf("\nAd�n�z: %s",m.adi);
				printf("\nSoyad�: %s",m.soyadi);
				printf("\nDo�um Tarihi: %s",m.dogumTarihi);
				printf("\nCep Telefonu: %s",m.cepTelefonu);
				printf("\nEmail Adresi: %s\n",m.emailAdresi);	
				break;	
			}
		}
		fclose(dosya);
		}else{
			printf("\nRezervasyon Kodu: %d",randomSayi);
			printf("\nKimlik Numaras�: %s",m.kimlikNumarasi);
			printf("\nAd�n�z: %s",m.adi);
			printf("\nSoyad�: %s",m.soyadi);
			printf("\nDo�um Tarihi: %s",m.dogumTarihi);
			printf("\nCep Telefonu: %s",m.cepTelefonu);
			printf("\nEmail Adresi: %s\n",m.emailAdresi);
		}
	
	printf("\n****************************\n");
	if(arabaNo!=0){	
	while(!feof(araba)){
		fscanf(araba,"%d\t%s\t%s\t%d\n",&a.ID,a.marka,a.model,&a.fiyat);
			if(arabaNo == a.ID){
				tUcret = tHesap * a.fiyat;
				printf("Ara� Markas�: %s\n",a.marka);
				printf("Ara� Modeli: %s\n",a.model);
				printf("Ara� G�nl�k Fiyat: %d\n",a.fiyat);
				printf("Ara� Al�� Tarihi: %d.%d.%d\n",gun1,ay1,yil1);
				printf("Ara� Veri� Tarihi: %d.%d.%d\n",gun2,ay2,yil2);
				printf("Kiralama G�n Say�s�: %d\n",tHesap);
				printf("Toplam �cret: %d",tUcret);

	fprintf(dosya2,"%-10d\t%-5d\t%-15s\t%-10s\t%-10s\t%-12s\t%-12s\t%-16s\t%-5s\t%-5s\t%-5d\t%d.%d.%d\t%d.%d.%d\t%-15d\t%d\n",
	randomSayi,mSira,m.kimlikNumarasi,m.adi,m.soyadi,m.dogumTarihi,m.cepTelefonu,m.emailAdresi,a.marka,a.model,a.fiyat,gun1,ay1,yil1,gun2,ay2,yil2,tHesap,tUcret);
	fclose(dosya2);
		}
	}
	fclose(araba);
	}else{
			while(!feof(otel)){
			fscanf(otel,"%d%s",&transfers.otelID,transfers.otelAdi);
			if(otelNo == transfers.otelID){
				printf("Otel: %s\n",transfers.otelAdi);	
			}
		}
		
		while(!feof(havalimani)){
			fscanf(havalimani,"%d%s",&transfers.havalimaniID,transfers.havalimaniAdi);
			if(havalimaniNo == transfers.havalimaniID){
				printf("Havaliman�: %s\n",transfers.havalimaniAdi);	
			}
		}
		
		while(!feof(transfer)){
			fscanf(transfer,"%d%d%d",&transfers.otelID,&transfers.havalimaniID,&transfers.fiyat);
			if(havalimaniNo == transfers.havalimaniID && otelNo == transfers.otelID){
				printf("G�nl�k �cret: %d\n",transfers.fiyat);
				aUcret = transfers.fiyat;
			}
		}
	
		printf("Al�� Tarihi: %d.%d.%d\n",gun1,ay1,yil1);
		printf("Veri� Tarihi: %d.%d.%d\n",gun2,ay2,yil2);
		printf("Kiralama G�n Say�s�: %d\n",tHesap);
		tUcret = aUcret*tHesap;
		printf("Toplam �cret: %d",tUcret);
		
	fprintf(dosya2,"%-10d\t%-5d\t%-15s\t%-10s\t%-10s\t%-12s\t%-12s\t%-16s\t%-5s\t%-5s\t%-5d\t%d.%d.%d\t%d.%d.%d\t%-15d\t%d\n",
	randomSayi,mSira,m.kimlikNumarasi,m.adi,m.soyadi,m.dogumTarihi,m.cepTelefonu,m.emailAdresi,otelNo,havalimaniNo,gun1,ay1,yil1,gun2,ay2,yil2,tHesap,tUcret);
	fclose(dosya2);
	fclose(otel);
	fclose(havalimani);
	fclose(transfer);
	}
	printf("\n\n1 - Geri D�n");
	printf("\n2 - ��k�� Yap");
	printf("\nSe�iminiz: ");
	scanf("%d",&secim);
	while(secim!=2){
		switch(secim){
			case 1: main(); break;
			case 2: printf("��k�� Yap�ld�...\n"); break;
			default: printf("Hatal� Se�im Yap�ld�...\n"); break;
		}
	}
	exit(0);
	return 0;			
	}
	else{
	system("cls");
	int secim;
	srand(time(NULL));
	randomSayi = 1 + rand() %99999;	
	FILE *araba = fopen("veritabani/arabalar.txt","r");
	FILE *dosya = fopen("veritabani/musteriBilgileri.dat","r+");
	FILE *dosya2 = fopen("veritabani/rezervasyon.txt","a");
	FILE *transfer = fopen("veritabani/transfer.txt","r");
	FILE *otel = fopen("veritabani/otel.txt","r");
	FILE *havalimani = fopen("veritabani/havalimani.txt","r");
	if(mSira!=0){
		while(fread(&m,sizeof(struct musteri),1,dosya)){
			if(mSira == m.mID){
				printf("\nReservation Code: %d",randomSayi);
				printf("\nIdentification Number: %s",m.kimlikNumarasi);
				printf("\nName: %s",m.adi);
				printf("\nSurname: %s",m.soyadi);
				printf("\nBirthday: %s",m.dogumTarihi);
				printf("\nPhone Number: %s",m.cepTelefonu);
				printf("\nEmail Address: %s\n",m.emailAdresi);	
				break;	
			}
		}
		fclose(dosya);
		}else{
				printf("\nReservation Code: %d",randomSayi);
				printf("\nIdentification Number: %s",m.kimlikNumarasi);
				printf("\nYour Name: %s",m.adi);
				printf("\nLast Name: %s",m.soyadi);
				printf("\nDate of Birth: %s",m.dogumTarihi);
				printf("\nPhone Number: %s",m.cepTelefonu);
				printf("\nEmail Address: %s\n",m.emailAdresi);	
		}
	
	printf("\n****************************\n");
	if(arabaNo!=0){
	while(!feof(araba)){
		fscanf(araba,"%d\t%s\t%s\t%d\n",&a.ID,a.marka,a.model,&a.fiyat);
			if(arabaNo == a.ID){
				tUcret = tHesap * a.fiyat;
				printf("Car Brand: %s\n",a.marka);
				printf("Vehicle Model: %s\n",a.model);
				printf("Vehicle's Daily Price: %d\n",a.fiyat);
				printf("Vehicle's Purchase Date: %d.%d.%d\n",gun1,ay1,yil1);
				printf("Vehicle's Delivery Date: %d.%d.%d\n",gun2,ay2,yil2);
				printf("Number of Rented Days: %d\n",tHesap);
				printf("Total Fee: %d",tUcret);

	fprintf(dosya2,"%-10d\t%-5d\t%-15s\t%-10s\t%-10s\t%-12s\t%-12s\t%-16s\t%-5s\t%-5s\t%-5d\t%d.%d.%d\t%d.%d.%d\t%-15d\t%d\n",
	randomSayi,mSira,m.kimlikNumarasi,m.adi,m.soyadi,m.dogumTarihi,m.cepTelefonu,m.emailAdresi,a.marka,a.model,a.fiyat,gun1,ay1,yil1,gun2,ay2,yil2,tHesap,tUcret);
	fclose(dosya2);
		}
	}
	fclose(araba);
	}else{
			while(!feof(otel)){
			fscanf(otel,"%d%s",&transfers.otelID,transfers.otelAdi);
			if(otelNo == transfers.otelID){
				printf("Hotel: %s\n",transfers.otelAdi);	
			}
		}
		
		while(!feof(havalimani)){
			fscanf(havalimani,"%d%s",&transfers.havalimaniID,transfers.havalimaniAdi);
			if(havalimaniNo == transfers.havalimaniID){
				printf("Airport: %s\n",transfers.havalimaniAdi);	
			}
		}
		
		while(!feof(transfer)){
			fscanf(transfer,"%d%d%d",&transfers.otelID,&transfers.havalimaniID,&transfers.fiyat);
			if(havalimaniNo == transfers.havalimaniID && otelNo == transfers.otelID){
				printf("Daily Price: %d\n",transfers.fiyat);
				aUcret = transfers.fiyat;
			}
		}
		printf("Purchase Date: %d.%d.%d\n",gun1,ay1,yil1);
		printf("Delivery Date: %d.%d.%d\n",gun2,ay2,yil2);
		printf("Number of Rented Days: %d\n",tHesap);
		tUcret = aUcret*tHesap;
		printf("Total Fee: %d",tUcret);
		
	fprintf(dosya2,"%-10d\t%-5d\t%-15s\t%-10s\t%-10s\t%-12s\t%-12s\t%-16s\t%-5s\t%-5s\t%-5d\t%d.%d.%d\t%d.%d.%d\t%-15d\t%d\n",
	randomSayi,mSira,m.kimlikNumarasi,m.adi,m.soyadi,m.dogumTarihi,m.cepTelefonu,m.emailAdresi,otelNo,havalimaniNo,gun1,ay1,yil1,gun2,ay2,yil2,tHesap,tUcret);
	fclose(dosya2);
	fclose(otel);
	fclose(havalimani);
	fclose(transfer);		
	}
	printf("\n\n1 - Return");
	printf("\n2 - Log Out");
	printf("\nYour Choice: ");
	scanf("%d",&secim);
	while(secim!=2){
		switch(secim){
			case 1: main(); break;
			case 2: printf("Exited...\n"); break;
			default: printf("You Made a Wrong Choice...\n"); break;
		}
	}
	exit(0);
	return 0;
	}
}

int rezervasyon(){
	system("cls");
	if(dilSecim==0){
	if(mSira==0){
		printf("\t\t\t\t\t\tARA� K�RALAMA");
		int secim;
		while(secim!=3){
		printf("\n1 - Rezervasyon Ara");
		printf("\n2 - Geri D�n");
		printf("\n3 - ��k�� Yap");
		printf("\nSe�iminiz: ");
		scanf("%d",&secim);
		switch(secim){
			case 1: rezervasyonAra(); break;
			case 2: musteriMenu(); break;
			case 3: printf("��k�� Yap�ld�..."); break;
			default: printf("Hatal� Se�im Yap�ld�...\n"); break;
			}
		}
		exit(0);
		return 0;			
	}else{
		FILE *dosya = fopen("veritabani/rezervasyon.txt","r");
		FILE *araba = fopen("veritabani/arabalar.txt","r");
		if(dosya == NULL){
			printf("Dosya Bulunamad�...");
		}else{
					while(!feof(dosya)){
					fscanf(dosya,"%d%d%s%s%d%d%d%d%d%d%d%d%d",&randomSayi,&m.mID,a.marka,a.model,&a.fiyat,&gun1,&ay1,&yil1,&gun2,&ay2,&yil2,&tHesap,&tUcret);
					if(mSira == m.mID){	
					printf("Rezervasyon Kodu: %d\nM��teri ID: %d\nAra� Marka: %s\nAra� Model: %s\nAra� Fiyat: %d\nAl�� Tarihi: %d.%d.%d\nTeslim Tarihi: %d.%d.%d\nKiralama G�n Say�s�: %d\nToplam �cret: %d"
					,randomSayi,m.mID,a.marka,a.model,a.fiyat,gun1,ay1,yil1,gun2,ay2,yil2,tHesap,tUcret);
						}else{
							printf("Rezervasyon Bulunmamaktad�r...");
						}
					break;
					}
					fclose(dosya);
		}
	}	
	}
	else{
	if(mSira==0){
	printf("\t\t\t\t\t\tRENT A CAR");
	int secim;
	while(secim!=3){
	printf("\n1 - Check for Reservation");
	printf("\n2 - Return");
	printf("\n3 - Log Out");
	printf("\nYour Choice: ");
	scanf("%d",&secim);
	switch(secim){
		case 1: rezervasyonAra(); break;
		case 2: musteriMenu(); break;
		case 3: printf("Exited..."); break;
		default: printf("You Made a Wrong Choice...\n"); break;
		}
	}
	}else{
		FILE *dosya = fopen("veritabani/rezervasyon.txt","r");
		FILE *araba = fopen("veritabani/arabalar.txt","r");
		if(dosya == NULL){
			printf("File not found...");
		}else{
					while(!feof(dosya)){
					fscanf(dosya,"%d%d%s%s%d%d%d%d%d%d%d%d%d",&randomSayi,&m.mID,a.marka,a.model,&a.fiyat,&gun1,&ay1,&yil1,&gun2,&ay2,&yil2,&tHesap,&tUcret);
					if(mSira == m.mID){
					printf("Reservation Code: %d\nCustomer ID: %d\nCar Brand: %s\nVehicle Model: %s\nVehicle Daily Price: %d\nPurchase Date: %d.%d.%d\nDelivery Date: %d.%d.%d\nNumber of Rental Days: %d\nTotal Fee: %d"
					,randomSayi,m.mID,a.marka,a.model,a.fiyat,gun1,ay1,yil1,gun2,ay2,yil2,tHesap,tUcret);
						}else{
							printf("There is no rezervation...");
						}
					break;
					}
					fclose(dosya);
		}		
	}
	exit(0);
	return 0;
	}
}

int rezervasyonAra(){
	FILE *dosya = fopen("veritabani/rezervasyon.txt","r");
	system("cls");
	if(dilSecim==0){
		if(dosya == NULL){
			printf("Dosya Bulunamad�...");
		}
	printf("\t\t\t\t\t\tARA� K�RALAMA\n");
	int rKodu;
	printf("Rezervayon Kodunuzu Giriniz: ");
	scanf("%d",&rKodu);
	while(!feof(dosya)){
		fscanf(dosya,"%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d"
		,&randomSayi,&m.mID,m.kimlikNumarasi,m.adi,m.soyadi,m.dogumTarihi,m.cepTelefonu,m.emailAdresi,a.marka,a.model,&a.fiyat,&gun1,&ay1,&yil1,&gun2,&ay2,&yil2,&tHesap,&tUcret);
		if(rKodu == randomSayi){
			system("cls");
			printf("\t\t\t\t\t\tARA� K�RALAMA\n");
			printf("Rezervasyon Kodu: %d\n",randomSayi);
			printf("Kimlik Numaras�: %s\n",m.kimlikNumarasi);
			printf("Ad�: %s\n",m.adi);
			printf("Soyad�: %s\n",m.soyadi);
			printf("Do�um Tarihi: %s\n",m.dogumTarihi);
			printf("Cep Telefonu: %s\n",m.cepTelefonu);
			printf("Email Adresi: %s\n",m.emailAdresi);
			printf("Ara� Marka: %s\n",a.marka);
			printf("Ara� Model: %s\n",a.model);
			printf("G�nl�k Fiyat: %d\nAl�� Tarihi: %d.%d.%d\nTeslim Tarihi: %d.%d.%d\nKiralama G�n Say�s�: %d\nToplam �cret: %d\n",a.fiyat,gun1,ay1,yil1,gun2,ay2,yil2,tHesap,tUcret);
		}else{
			printf("Rezervasyon Bulunamad�...");
		}
		break;
	}
	fclose(dosya);
	}
	else{
	printf("\t\t\t\t\t\tRENT A CAR\n");
		if(dosya == NULL){
			printf("File not found...");
		}
	printf("\t\t\t\t\t\tARA� K�RALAMA\n");
	int rKodu;
	printf("Enter your Reservation Code: ");
	scanf("%s",&rKodu);
	while(!feof(dosya)){
		fscanf(dosya,"%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d"
		,&randomSayi,&m.mID,m.kimlikNumarasi,m.adi,m.soyadi,m.dogumTarihi,m.cepTelefonu,m.emailAdresi,a.marka,a.model,&a.fiyat,&gun1,&ay1,&yil1,&gun2,&ay2,&yil2,&tHesap,&tUcret);
		if(rKodu == randomSayi){
			system("cls");
			printf("\t\t\t\t\t\tRENT A CAR\n");
			printf("Reservation Code: %d\n",randomSayi);
			printf("Identification Number: %s\n",m.kimlikNumarasi);
			printf("Name: %s\n",m.adi);
			printf("Surname: %s\n",m.soyadi);
			printf("Birthday: %s\n",m.dogumTarihi);
			printf("Phone Number: %s\n",m.cepTelefonu);
			printf("Email Address: %s\n",m.emailAdresi);
			printf("Car Brand: %s\n",a.marka);
			printf("Vehicle Model: %s\n",a.model);
			printf("Daily Price: %d\n",a.fiyat);
			printf("Purchase Date: %d.%d.%d\nDelivery Date: %d.%d.%d\nNumber of Rented Days: %d\nTotal Fee: %d\n",gun1,ay1,yil1,gun2,ay2,yil2,tHesap,tUcret);
		}else{
			printf("There is no rezervation...");
		}
		break;
	}
	fclose(dosya);	
	}
}

int ofislerimiz(){
    system("cls");
    int secim;
    if(dilSecim==0){
	    printf("\t\t\t\t\t\tARA� K�RALAMA");
	    while(secim!=12){
	    printf("\n1 - �stanbul Avc�lar �ubemiz");
	    printf("\n2 - �stanbul Beylikd�z� �ubemiz");
	    printf("\n3 - �stanbul �irinevler �ubemiz");
	    printf("\n4 - �stanbul Esenler �ubemiz");
	    printf("\n5 - �stanbul Kad�k�y �ubemiz");
	    printf("\n6 - �stanbul Tuzla �ubemiz");
	    printf("\n7 - Giresun Bulancak �ubemiz");
	    printf("\n8 - Malatya Do�anyol �ubemiz");
	    printf("\n9 - Tokat Niksar �ubemiz");
	    printf("\n10 - �zmir Bornova �ubemiz");
	    printf("\n11 - Geri D�n");
	    printf("\n12 - ��k�� Yap");
	    printf("\nSe�iminiz: ");
	    scanf("%d",&secim);
	    switch(secim){
	        case 1: printf("\n�stanbul Avc�lar �ubesi �leti�im Bilgileri\n"); printf("Adres : Avc�lar\n"); printf("Telefon : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
	        case 2: printf("\n�stanbul Beylikd�z� �ubesi �leti�im Bilgileri\n"); printf("Adres : Beylikd�z�\n"); printf("Telefon : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
	        case 3: printf("\n�stanbul �irinevler �ubesi �leti�im Bilgileri\n"); printf("Adres : �irinevler\n"); printf("Telefon : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
	        case 4: printf("\n�stanbul Esenler �ubesi �leti�im Bilgileri\n"); printf("Adres : Esenler\n"); printf("Telefon : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
	        case 5: printf("\n�stanbul Kad�k�y �ubesi �leti�im Bilgileri\n"); printf("Adres : Kad�k�y\n"); printf("Telefon : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
	        case 6: printf("\n�stanbul Tuzla �ubesi �leti�im Bilgileri\n"); printf("Adres : Tuzla\n"); printf("Telefon : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
	        case 7: printf("\nGiresun Bulancak �ubesi �leti�im Bilgileri\n"); printf("Adres : Bulancak\n"); printf("Telefon : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
	        case 8: printf("\nMalatya Do�anyol �ubesi �leti�im Bilgileri\n"); printf("Adres : Do�anyol\n"); printf("Telefon : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
	        case 9: printf("\nTokat Niksar �ubesi �leti�im Bilgileri\n"); printf("Adres : Niksar\n"); printf("Telefon : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
	        case 10: printf("\n�zmir Bornova �ubesi �leti�im Bilgileri\n"); printf("Adres : Bornova\n"); printf("Telefon : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
	        case 11: musteriMenu(); break;
	        case 12: printf("��k�� Yap�ld�..."); break;
	        default: printf("Hatal� Se�im Yap�ld�...\n"); break;
	        }
		}
		exit(0);
		return 0;	
	}else{
	int secim;
    printf("\t\t\t\t\t\tRENT A CAR");
    while(secim!=12){
    printf("\n1 - Istanbul Avc�lar Branch");
    printf("\n2 - Istanbul Beylikduzu Branch");
    printf("\n3 - Istanbul Sirinevler Branch");
    printf("\n4 - Istanbul Esenler Branch");
    printf("\n5 - Istanbul Kad�koy Branch");
    printf("\n6 - Istanbul Tuzla Branch");
    printf("\n7 - Giresun Bulancak Branch");
    printf("\n8 - Malatya Doganyol Branch");
    printf("\n9 - Tokat Niksar Branch");
    printf("\n10 - �zmir Bornova Branch");
    printf("\n11 - Return");
    printf("\n12 - Exit");
    printf("\nYour Choice: ");
    scanf("%d",&secim);
    switch(secim){
        case 1: printf("\nIstanbul Avcilar Branch Contact information\n"); printf("Adress : Avc�lar\n"); printf("Contact Number : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
        case 2: printf("\nIstanbul Beylikduzu Branch Contact information\n"); printf("Adress : Beylikduzu\n"); printf("Contact Number : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
        case 3: printf("\nIstanbul Sirinevler Branch Contact information\n"); printf("Adress : S�r�nevler\n"); printf("Contact Number : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
        case 4: printf("\nIstanbul Esenler Branch Contact information\n"); printf("Adress : Esenler\n"); printf("Contact Number : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
        case 5: printf("\nIstanbul Kadikoy Branch Contact information\n"); printf("Adress : Kad�koy\n"); printf("Contact Number : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
        case 6: printf("\nIstanbul Tuzla Branch Contact information\n"); printf("Adress : Tuzla\n"); printf("Contact Number : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
        case 7: printf("\nGiresun Bulancak Branch Contact information\n"); printf("Adress : Bulancak\n"); printf("Contact Number : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
        case 8: printf("\nMalatya Doganyol Branch Contact information\n"); printf("Adress : Doganyol\n"); printf("Contact Number : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
        case 9: printf("\nTokat Niksar Branch Contact information\n"); printf("Adress : Niksar\n"); printf("Contact Number : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
        case 10: printf("\nIzmir Bornova Branch Contact information\n"); printf("Adress : Bornova\n"); printf("Contact Number : 123456789012\n"); printf("Email : arackiralama@arackiralama.com\n"); break;
        case 11: musteriMenu(); break;
        case 12: printf("Exited..."); break;
        default: printf("You Made a Wrong Choice...\n"); break;
		exit(0);
		return 0;
    }
}
}
}
int hakkimizda(){
	system("cls");
	printf("\t\t\t\t\t\tARA� K�RALAMA\n");
	FILE *dosya = fopen("veritabani/hakkimizda.txt","r");
	int secim;
	if(dilSecim==0){
	printf("\n5 Ortak ile 2015'den bu yana hizmet gostermekteyiz.10 Il de subemiz vard�r.Ekonomik s�n�ftan luks s�n�fa birden fazla otomobil,elektrikli otomobil ve VIP ara�larimizla sizlere  "
    "en iyi sekilde hizmet verebilmek i�in yogun ve titiz bir sekilde calismaktay�z. Ister ailenizle bir seyahate gitmek,ister yakin arkadaslarinizla seyahate gitmek i�in isterse de"
    "is ya da seyahat ihtiya�larinizda butcenize uygun araclari subelerimizde bulabilirsiniz.Her turlu elestiri ve onerilerinize acik olan firmamiz sizin desteklerinizle g�nden g�ne"
    "buyumektedir.Internet uzerinden girmis oldugunuz kisisel bilgileriniz firmamiz taraf�ndan guvence altindadir. "
     "+90 531 383 17 76 telefon numaram�zdan diledi�iniz soruyu sorabilir ve ayr�nt�l� bilgi alabilirsiniz firmaiz 7/24 sizlere kaliteli hizmet vermektedir.");	
	while(secim!=2){
	printf("\n\n1 - Geri D�n");
	printf("\n2 - ��k�� Yap");
	printf("\nSe�iminiz: ");
	scanf("%d",&secim);
	switch(secim){
		case 1: musteriMenu(); break;
		case 2: printf("��k�� Yap�ld�..."); break;
		default: printf("Hatal� Se�im Yap�ld�...\n"); break;
		}
	 }
	exit(0);
	return 0;
	}else{
		printf("\nWe have been providing service with 5 partners since 2015. We have branches in 10 provinces. We offer you more than one car from economic class to luxury class, electric cars and VIP vehicles."
		"We work intensively and meticulously to provide the best service. You can find vehicles suitable for your budget in our branches, whether you want to go on a trip with your family, go on a trip with your" 
		"close friends, or for your business or travel needs. Our company is open to all kinds of criticism and suggestions, and with your support, is growing day by day."
		"Your personal information you enter over the internet is secured by our company. "
	     "You can ask any question you want and get detailed information from our phone number +90 531 383 17 76. Our company provides you with quality service 24//7.");
		while(secim!=2){
		printf("\n\n1 - Return");
		printf("\n2 - Exit");
		printf("\nYour Choice: ");
		scanf("%d",&secim);
		switch(secim){
			case 1: musteriMenu(); break;
			case 2: printf("Exited..."); break;
			default: printf("You Made a Wrong Choice...\n"); break;
			}
		}
	exit(0);
	return 0;		
	}
}

int kampanyalar(){
        system("cls");
        int secim;
        if(dilSecim==0){	
		printf("\t\t\t\t\t\tARA� K�RALAMA\n"); 
        printf("\n***Haftal�k Kiralama Kampanyalar�m�z***");
        printf("\n\n - 1 Haftal�k araba kiralama da %%5 indirim!");
        printf("\n - 2 Haftal�k araba kiralama da %%10 indirim!");
        printf("\n - 3 Haftal�k araba kiralama da %%15 indirim!");
        printf("\n - 4 Haftal�k araba kiralama da %%20 indirim!");
        printf("\n\n\n***Anla�mal� Bankalarda Kampanyalar�m�z***");
        printf("\n\n - Yap�Kredi World kredi kartlar�na �zel %%10 indirim!");
        printf("\n - Akbank kredi kartlar�na �zel %%8 indirim!");
        printf("\n - Papara kart�na �zel %%5 cashback!");
        printf("\n\n\n***Ekstra Kampanyalar�m�z***");
        printf("\n\n - �lk defa ara� kiralayacaklara �zel ilk kiralamada Shell Benzin �stasyonlar�nda 250tl indirim kodu!");
        printf("\n - 3 ve daha fazla sefer ara� kiralayan m��terilerimiz i�in K�� Lastiklerinde %%10 indirim!");
        printf("\n - Devaml� m��terilerimize �zel olarak Shell Benzin �stasyonlar�nda her kiralamaya �zel olarak 500tl indirim kodu!");
        while(secim!=2){ 
        printf("\n\n\n1 - Geri D�n"); 
        printf("\n2 - ��k�� Yap"); 
        printf("\nSe�iminiz: "); 
        scanf("%d",&secim);
        switch(secim){
            case 1: musteriMenu(); break;
            case 2: printf("��k�� Yap�ld�..."); break;
            default: printf("Hatal� Se�im Yapt�n�z...\n"); break; 
        	}        	
		}
	exit(0);
	return 0;
	}else{
		printf("\t\t\t\t\t\tRENT A CAR\n"); 
        printf("\n***Our weekly rental discounts***");
        printf("\n\n - 5 percent discount on 1-week car rental ");
        printf("\n - 10 percent discount on 2-week car rental ");
        printf("\n - 15 percent discount on 3-week car rental");
        printf("\n - 20 percent discount on 4-week car rental");
        printf("\n\n\n***Our Campaigns in Contracted Banks***");
        printf("\n\n - 10 percent discount for Yap�Kredi World credit cards!");
        printf("\n - 8 percent discount for Akbank credit cards!");
        printf("\n - 5 percent cashback for Papara cards!");
        printf("\n\n\n***Ekstra Kampanyalar�m�z***");
        printf("***Our Extra Campaigns***");
        printf("\n\n - Special for those who rent a car for the first time 250 TL discount code at Shell Gas Stations for the first rental!");
        printf("\n - 10 percent discount on Winter Tires for our customers who rent a car for 3 or more trips!");
        printf("\n - 500 TL discount code for every rental at Shell Gas Stations, exclusively for our regular customers!");
        while(secim!=2){ 
        printf("\n\n\n1 - Return");
        printf("\n2 - Exit");
        printf("\nYour Choice: ");
        scanf("%d",&secim);
        switch(secim){
            case 1: musteriMenu(); break;
            case 2: printf("Exited..."); break; 
            default: printf("You Made a Wrong Choice...\n"); break;		
		}
	}
	exit(0);
	return 0;     
	}
}
int iletisim(){
	int secim;
	system("cls");
	if(dilSecim==0){
	printf("\t\t\t\t\t\tARA� K�RALAMA\n");	
	printf("\nAra� Kiralama hakk�nda akl�n�za tak�lan sorular i�in ekibimize 7/24 ula�abilirsiniz.");	
	printf("\n\nBize Ula��n");
	printf("\n\nHatt�m�z: 123456790");
	printf("\n\nEposta: arackiralama@arackiralama.com");
	while(secim!=2){
	printf("\n\n1- Geri D�n");
	printf("\n\n2- ��k�� Yap");
	printf("\n\nSe�iminiz: ");
	scanf("%d",&secim);
	switch(secim){	
		case 1: yoneticiMenu(); break;
		case 2: printf("��k�� Yap�ld�..."); break;
		default: printf("Hatal� Se�im Yapt�n�z...\n"); break;
		}		
	}
	exit(0);
	return 0;
	}else{
		
	printf("\t\t\t\t\t\tRENT A CAR\n");	
	printf("\nYou can contact with our team any time for any questions you may have about Car Rental..");	
	printf("\n\nContact us");
	printf("\n\nOur Contact Number: 123456790");
	printf("\n\nEmail: arackiralama@arackiralama.com");
	while(secim!=2){
	printf("\n\n1- Return");
	printf("\n\n2- Exit");
	printf("\n\nYour Choice: ");
	scanf("%d",&secim);
	switch(secim){	
		case 1: yoneticiMenu(); break;
		case 2: printf("Exited..."); break;
		default: printf("You Made a Wrong Choice...\n"); break;
		}
	exit(0);
	return 0;
	}	
}
}

int yoneticiMenu(){
int secim;
	if(dilSecim==0){
        system("cls");
        printf("\t\t\t\t\t\tARA� K�RALAMA\n");
        while(secim!=5){
        printf("1- Araba");
        printf("\n2- M��teriler");
        printf("\n3- Rezervasyonlar");
        printf("\n4- Geri D�n");     
        printf("\n5- ��k�� Yap");
        printf("\nSeciminiz: ");
        scanf("%d",&secim);
        switch(secim) {
            case 1: arabalar(); break;
			case 2: musteriBilgileri(); break;
			case 3: mRezervasyon(); break;       
            case 4: main(); break;
            case 5: printf("��k�� Yap�ld�..."); break;
            default: printf("Hatal� Se�im Yap�ld�...\n"); break;
        	}        	
		}
	exit(0);
	return 0;		
	}
	else{
        system("cls");
        printf("\t\t\t\t\t\tARA� K�RALAMA\n");
        int secim;
        while(secim!=5){
        printf("1- Cars");
        printf("\n2- Customers");
        printf("\n3- Reservations");
        printf("\n4- Return");     
        printf("\n5- Log Out");
        printf("\nYour Choice: ");
        scanf("%d",&secim);
        switch(secim) {
            case 1: arabalar(); break;
			case 2: musteriBilgileri(); break;
			case 3: mRezervasyon(); break;       
            case 4: main(); break;
            case 5: printf("Exited..."); break;
            default: printf("You Made a Wrong Choice...\n"); break;
        	}        	
		}
	exit(0);
	return 0;
	}
}
	
int mRezervasyon(){
	if(dilSecim==0){
		system("cls");
		int secim;
		FILE *dosya = fopen("veritabani/rezervasyon.txt","r");
		if(dosya==NULL){
			printf("Dosya Bulunamad�...");
		}
		printf("Rezervasyon\tID\tKimlik Numaras�\tAd�\t\tSoyad�\t\tDo�um Tarihi\tCep Telefonu\tEmail Adresi\t\tMarka\tModel\tFiyat\tAl�� Tarihi\tTeslim Tarihi\tKiralama G�n\tToplam �cret\n");
		while(!feof(dosya)){
			putchar(getc(dosya));			
		}
		fclose(dosya);
		printf("\n1 - Geri D�n");
		printf("\n2 - ��k�� Yap");
		printf("\nSe�iminiz: ");
		scanf("%d",&secim);
		while(secim!=2){
		switch(secim){
			case 1: main(); break;
			case 2: printf("��k�� Yap�ld�..."); break;
			default: printf("Hatal� Se�im Yap�ld�..."); break;
		}			
	}
	exit(0);
	return 0;		
	}else{
		system("cls");
		int secim;
		FILE *dosya = fopen("veritabani/rezervasyon.txt","r");
		if(dosya==NULL){
			printf("File not found...");
		}
		printf("Reservation\tID\tIdentification Number\tName\t\tSurname\t\tBirthday\tPhone Number\tEmail Adress\t\tBrand\tModel\tPrice\tPurchase Date\tDelivery Date\tRented Days\tTotal Fee\n");
		while(!feof(dosya)){
			putchar(getc(dosya));			
		}
		fclose(dosya);
		printf("\n1 - Geri D�n");
		printf("\n2 - ��k�� Yap");
		printf("\nSe�iminiz: ");
		scanf("%d",&secim);
		while(secim!=2){
		switch(secim){
			case 1: main(); break;
			case 2: printf("��k�� Yap�ld�..."); break;
			default: printf("Hatal� Se�im Yap�ld�..."); break;
		}			
	}
	exit(0);
	return 0;
	}
}

int musteriBilgileri(){
	if(dilSecim==0){
		system("cls");
		int secim;
		FILE *dosya = fopen("veritabani/musteriBilgileri.dat","r+");
		if(dosya==NULL){
			printf("Dosya Bulunamad�...");
		}
		while(fread(&m,sizeof(struct musteri),1,dosya)){
			printf("ID: %d\nKimlik Numaras�: %s\nAd: %s\nSoyad: %s\nDo�um Tarihi: %s\nCep Telefonu: %s\nEmail Adresi: %s\nParola: %s\nKay�t T�r�: %s\nVergi Numaras�: %s\n�irket Ad�: %s\n********************\n"
			,m.mID,m.kimlikNumarasi,m.adi,m.soyadi,m.dogumTarihi,m.cepTelefonu,m.emailAdresi,m.parola,m.kayitTuru,m.vergiNumarasi,m.sirketAdi);
		}
			fclose(dosya);
			printf("\n1 - Geri D�n");
			printf("\n2 - ��k�� Yap");
			printf("\nSe�iminiz: ");
			scanf("%d",&secim);
			while(secim!=2){
			switch(secim){
				case 1: yoneticiMenu(); break;
				case 2: printf("��k�� Yap�ld�..."); break;
				default: printf("Hatal� Se�im Yap�ld�..."); break;
			}			
		}
		exit(0);
		return 0;		
	}else{
	system("cls");
		int secim;
		FILE *dosya = fopen("veritabani/musteriBilgileri.dat","r+");
		if(dosya==NULL){
			printf("File not found...");
		}
		while(fread(&m,sizeof(struct musteri),1,dosya)){
			printf("ID: %d\nIdentification Number: %s\nName: %s\nSurname: %s\nBirthday: %s\nPhone Number: %s\nEmail Adress: %s\nPassword: %s\nRegistration Type: %s\nTax Number: %s\nCompany Name: %s\n********************\n"
			,m.mID,m.kimlikNumarasi,m.adi,m.soyadi,m.dogumTarihi,m.cepTelefonu,m.emailAdresi,m.parola,m.kayitTuru,m.vergiNumarasi,m.sirketAdi);
		}
			fclose(dosya);
			printf("\n1 - Return");
			printf("\n2 - Exit");
			printf("\nYour Choice: ");
			scanf("%d",&secim);
			while(secim!=2){
			switch(secim){
				case 1: yoneticiMenu(); break;
				case 2: printf("Exited..."); break;
				default: printf("You Made a Wrong Choice..."); break;
			}			
		}
		exit(0);
		return 0;
	}
}

int arabalar(){
	if(dilSecim==0){
		system("cls");
		int secim;
		FILE *dosya = fopen("veritabani/arabalar.txt","r");
		if(dosya==NULL){
			printf("Dosya Bulunamad�...");
		}
		printf("ID\tMarka\tModel\tFiyat");
		while(!feof(dosya)){
			fscanf(dosya,"%d\t%s\t%s\t%d\n",&a.ID,a.marka,a.model,&a.fiyat);
			printf("\n%d\t%s\t%s\t%d",a.ID,a.marka,a.model,a.fiyat);
		}
		fclose(dosya);
		printf("\n1 - Geri D�n");
		printf("\n2 - ��k�� Yap");
		printf("\nSe�iminiz: ");
		scanf("%d",&secim);
		while(secim!=2){
		switch(secim){
			case 1: yoneticiMenu(); break;
			case 2: printf("��k�� Yap�ld�..."); break;
			default: printf("Hatal� Se�im Yap�ld�..."); break;
		}			
	}
	exit(0);
	return 0;		
	}else{
		system("cls");
		int secim;
		FILE *dosya = fopen("veritabani/arabalar.txt","r");
		if(dosya==NULL){
			printf("File not found...");
		}
		printf("ID\tBrand\tModel\tPrice\n");
		while(!feof(dosya)){
			fscanf(dosya,"%d\t%s\t%s\t%d\n",&a.ID,a.marka,a.model,&a.fiyat);
			printf("\n%d\t%s\t%s\t%d",a.ID,a.marka,a.model,a.fiyat);
		}
		fclose(dosya);
		printf("\n1 - Return");
		printf("\n2 - Exit");
		printf("\nYour Choice: ");
		scanf("%d",&secim);
		while(secim!=2){
		switch(secim){
			case 1: yoneticiMenu(); break;
			case 2: printf("Exited..."); break;
			default: printf("You Made a Wrong Choice..."); break;
		}			
	}
	exit(0);
	return 0;		
	}
}

int main(){
	setlocale(LC_ALL,"Turkish");
	if(dilSecim==0){
		system("cls");
		printf("\t\t\t\t\t\t\tARA� K�RALAMA\n");
		int secim;
		while(secim!=6){
	printf("                                    			    _._\n");
    printf("\t\t\t                               _.-=\"_-         _\n");
    printf(" \t\t\t                         _.-=\"   _-          | ||\"\"\"\"\"\"---._______     __..\n");
    printf(" \t\t\t             ___.===\"\"\"-.______-,,,,,,,,,,,,`-''----\" \"\"\"\"\"\"       \"\"\"\"\"  __'\n");
    printf("  \t\t\t     __.--\"\"     __        ,'                   o \\           __        [__|\n");
    printf("  \t\t\t__-\"\"=======.--\"\"  \"\"--.=================================.--\"\"  \"\"--.=======:\n");
    printf(" \t\t\t]       [w] : /        \\ : |========================|    : /        \\ :  [w] :\n");
    printf(" \t\t\tV___________:|          |: |========================|    :|          |:   _-\"\n");
    printf(" \t\t\t V__________: \\        / :_|=======================/_____: \\        / :__-\"\n");
    printf(" \t\t\t -----------'  \"\"____\"\"  `-------------------------------'  \"\"____\"\"\n");
		printf("\n1 - Giri� Yap");
		printf("\n2 - Kay�t Ol");
		printf("\n3 - �yesiz Devam Et");
		printf("\n4 - Y�netici Giri�");
		printf("\n5 - Ayarlar");
		printf("\n6 - ��k�� Yap");
		printf("\nSe�iminiz: ");
		scanf("%d",&secim);
		switch(secim){
			case 1: girisYap(); break;
			case 2: kayitOl(); break;
			case 3: musteriMenu(); break;
			case 4: yoneticiGiris(); break;
			case 5: ayarlar(); break;
			case 6: printf("��k�� Yap�ld�..."); break;
			default: printf("Hatal� Se�im Yap�ld�...\n"); break;
			}
		}
	}
	else{
		system("cls");		
		printf("\t\t\t\t\t\t\tARA� K�RALAMA\n");
		int secim;
		while(secim!=6){
	printf("                                    			    _._\n");
	printf("\t\t\t                               _.-=\"_-         _\n");
    printf(" \t\t\t                         _.-=\"   _-          | ||\"\"\"\"\"\"---._______     __..\n");
    printf(" \t\t\t             ___.===\"\"\"-.______-,,,,,,,,,,,,`-''----\" \"\"\"\"\"\"       \"\"\"\"\"  __'\n");
    printf("  \t\t\t     __.--\"\"     __        ,'                   o \\           __        [__|\n");
    printf("  \t\t\t__-\"\"=======.--\"\"  \"\"--.=================================.--\"\"  \"\"--.=======:\n");
    printf(" \t\t\t]       [w] : /        \\ : |========================|    : /        \\ :  [w] :\n");
    printf(" \t\t\tV___________:|          |: |========================|    :|          |:   _-\"\n");
    printf(" \t\t\t V__________: \\        / :_|=======================/_____: \\        / :__-\"\n");
    printf(" \t\t\t -----------'  \"\"____\"\"  `-------------------------------'  \"\"____\"\"\n");
		printf("\n1 - Login");
		printf("\n2 - Register");
		printf("\n3 - Guest");
		printf("\n4 - Admin Login");
		printf("\n5 - Settings");
		printf("\n6 - Log Out");
		printf("\nYour Choice: ");
		scanf("%d",&secim);
		switch(secim){
			case 1: girisYap(); break;
			case 2: kayitOl(); break;
			case 3: musteriMenu(); break;
			case 4: yoneticiGiris(); break;
			case 5: ayarlar(); break;
			case 6: printf("Exited..."); break;
			default: printf("You Made a Wrong Choice...\n"); break;
			}
		}
	}	
	exit(0);
	return 0;
}

