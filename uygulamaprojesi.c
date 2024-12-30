#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct Araba {
	int numara; 
	char marka[20], model[20], renk[20]; 
	int ucret, durum; 
} araba  ;

void arabaEkle() 
{
	system("cls") ; 
	printf("\nAraba ekleme ekrani \n\n") ; 
	araba a1; 
	int numara =0; 
	FILE *numPtr= fopen("numaralar.dat", "a+b") ; 
	if(numPtr==NULL )
	printf("dosya bulunamadi \n") ; 
	else
	while( fread ( &numara, sizeof(int), 1, numPtr ) !=NULL  ) 
	{	 
	}
	numara++; 
	fwrite(&numara, sizeof(int ), 1, numPtr ); 
	fclose(numPtr) ; 
	a1.numara = numara; 
	printf("Marka      : ") ; scanf(" %[^\n]s", a1.marka ) ; 
	printf("Model(Yil) : ") ; scanf(" %[^\n]s", a1.model ) ; 
	printf("Renk       : ") ; scanf(" %[^\n]s", a1.renk ) ; 
	printf("ucret      : ") ; scanf(" %d", &a1.ucret ) ; 
	a1.durum=0;
	
	FILE *ptr= fopen("arabalar.dat", "a+b") ; 
	fwrite(&a1, sizeof(araba ), 1, ptr ); 
	fclose(ptr) ; 
	printf("Araba kaydi tamam ") ; 		
}

void arabaListele () 
{
	system("cls") ; 
	printf("\nAraba listeleme ekrani \n\n") ; 
	araba a1; 
	FILE *ptr= fopen("arabalar.dat", "r+b") ; 
	printf("%-10s%-20s%-20s%-20s%-10s%-20s\n", "NUMARA", "MARKA", "MODEL", "RENK", "UCRET", "DURUM" ) ; 
	while(  fread  (&a1, sizeof(araba ), 1, ptr ) !=NULL ) 
	{
		printf("%-10d%-20s%-20s%-20s%-10d%-20s\n", a1.numara, a1.marka, a1.model, a1.renk, a1.ucret,  a1.durum==0 ? "GALERIDE" : "SATILDI"  ); 		
	}
	
	fclose(ptr) ; 
	
}



void arabaGuncelle () 
{
	system("cls") ; 
	printf("\nAraba guncelleme ekrani \n\n") ; 
	araba a1; 
	int numara; 
	arabaListele() ;
	printf("Guncellemek istediginiz aracin numarasi :       : ") ; scanf(" %d", &numara  ) ; 
	int sonuc =0, sayac=0; 
	FILE *ptr= fopen("arabalar.dat", "r+b") ; 	
	while(  fread  (&a1, sizeof(araba ), 1, ptr ) !=NULL ) 
	{
		if( numara == a1.numara ) 
		{
			sonuc  = 1; 
			printf("%-10d%-20s%-20s%-20s%-10d%-20s\n", a1.numara, a1.marka, a1.model, a1.renk, a1.ucret,  a1.durum==0 ? "GALERIDE" : "SATILDI"  ); 		
			break; 	
		}
		sayac++; 
	}
	
	if( sonuc==0 ) 
	printf("%d numarali arac kaydi bulunamidi \n", numara ); 
	else
	{
	printf("Marka      : ") ; scanf(" %[^\n]s", a1.marka ) ; 	
	printf("Model(Yil) : ") ; scanf(" %[^\n]s", a1.model ) ; 
	printf("Renk       : ") ; scanf(" %[^\n]s", a1.renk ) ; 
	printf("ucret      : ") ; scanf(" %d", &a1.ucret ) ; 
	a1.durum=0;
	fseek( ptr ,(sayac) * sizeof(araba ), 0 ); 
	fwrite(&a1, sizeof(araba ), 1, ptr ); 		
	printf("Arac bilgileri guncellendi \n") ; 
	}
	fclose(ptr) ; 	
}
void arabaSil() 
{
	system("cls") ; 
	printf("\nAraba Silme ekrani \n\n") ; 
	araba a1; 
	int numara; 
	arabaListele() ;
	printf("Silmek istediginiz aracin numarasi :       : ") ; scanf(" %d", &numara  ) ; 
	int sonuc =0, sayac=0; 
	FILE *ptr= fopen("arabalar.dat", "r+b") ; 	
	while(  fread  (&a1, sizeof(araba ), 1, ptr ) !=NULL ) 
	{
		if( numara == a1.numara ) 
		{
			sonuc= 1; 
			printf("%-10d%-20s%-20s%-20s%-10d%-20s\n", a1.numara, a1.marka, a1.model, a1.renk, a1.ucret,  a1.durum==0 ? "GALERIDE" : "SATILDI"  ); 		
			break; 	
		} 
	}
	
	if( sonuc==0 ) 
	printf("%d numarali arac kaydi bulunamidi \n", numara ); 
	else
	{
	rewind(ptr) ; 
	FILE *yPtr = fopen("yedek.dat", "w+b" ) ;
	
	while(  fread  (&a1, sizeof(araba ), 1, ptr ) !=NULL ) 
	{
		if( numara != a1.numara ) 
		{
			fwrite(&a1, sizeof(araba ), 1, yPtr ); 			
		}
	}
	
	fclose(ptr)   ; 
	fclose(yPtr)  ; 
	remove("arabalar.dat") ; 
	rename("yedek.dat", "arabalar.dat") ; 
	printf("Arac kaydi silindi \n") ; 
	}
	fclose(ptr) ; 		
	
	
}
void arabaSat() 
{
	system("cls") ; 
	printf("\nAraba Satis ekrani \n\n") ; 
	araba a1; 
	int numara; 
	arabaListele() ;
	printf("Satmak istediginiz aracin numarasi :       : ") ; scanf(" %d", &numara  ) ; 
	int sonuc =0, sayac=0; 
	FILE *ptr= fopen("arabalar.dat", "r+b") ; 	
	while(  fread  (&a1, sizeof(araba ), 1, ptr ) !=NULL ) 
	{
		if( numara == a1.numara ) 
		{
			sonuc= 1; 
			printf("%-10d%-20s%-20s%-20s%-10d%-20s\n", a1.numara, a1.marka, a1.model, a1.renk, a1.ucret,  a1.durum==0 ? "GALERIDE" : "SATILDI"  ); 		
			break; 	
		}
		sayac++; 
	}
	
		if( sonuc==0 ) 
		printf("%d numarali arac kaydi bulunamidi \n", numara );
		else if( a1.durum==1 ) 
		{
			printf("Bu arac daha onceden satilmis !, tekrar satis yapamazsiniz \n")  ; 
			
		} 
	else
	{
		
	a1.durum=1;
	fseek( ptr ,(sayac) * sizeof(araba ), 0 ); 
	fwrite(&a1, sizeof(araba ), 1, ptr ); 		
	printf("Arac satisi yapildi \n") ; 
	}
	fclose(ptr) ; 	
	
	
}

void arabaBul () 
{
	system("cls") ; 
	printf("\nAraba Bulma ekrani \n\n") ; 
	araba a1; 
	int numara; 
	arabaListele() ;
	printf("Aradiginiz aracin numarasi :       : ") ; scanf(" %d", &numara  ) ; 
	int sonuc =0, sayac=0; 
	FILE *ptr= fopen("arabalar.dat", "r+b") ; 	
	while(  fread  (&a1, sizeof(araba ), 1, ptr ) !=NULL ) 
	{
		if( numara == a1.numara ) 
		{
			sonuc= 1; 
			printf("%-10d%-20s%-20s%-20s%-10d%-20s\n", a1.numara, a1.marka, a1.model, a1.renk, a1.ucret,  a1.durum==0 ? "GALERIDE" : "SATILDI"  ); 		
			break; 	
		}
		sayac++; 
	}
	
	if( sonuc==0 ) 
	printf("%d numarali arac kaydi bulunamidi \n", numara ); 
	fclose(ptr) ; 	
	
	
}




int yetkiliMenu () 
{

	int secim; 
	printf("\n\tARABA GALERISI OTOMASYONU \n\n") ; 
	printf("1- Araba Ekle  \n") ; 
	printf("2- Araba Guncelle  \n") ; 
	printf("3- Araba Sil  \n") ; 
	printf("4- Araba Sat  \n") ; 
	printf("5- Araba Listele  \n") ; 
	printf("6- Araba Bul   \n") ; 
	printf("0- Cikip Yap   \n") ;  ; 
	printf("Seciminiz : ") ; scanf("%d", &secim  ) ;  
	
	return secim;  	
}


void yetkiliGiris()
{
	int secim= yetkiliMenu (); 
	while( secim !=  0 ) 
	{
		switch(secim )
		{
			case 1: arabaEkle ();  break; 
			case 2: arabaGuncelle ();  break; 
			case 3: arabaSil ();  break; 
			case 4: arabaSat ();  break; 
			case 5: arabaListele ();  break; 
			case 6: arabaBul ();  break; 			
			case 0: break; 
			default : printf("hatali secim ! \n"); break; 
		}
		secim= yetkiliMenu(); 		
	}	
	printf("Cikis yaptiniz... ! \n ") ; 	
}


void girisYap() 
 {
 	system("cls"); 
 	char kullaniciAdi[20], parola[20]; 
 		
 	printf("Kullanici giris ekrani \n") ; 
	printf("\n\tKullanici Adi  :  ") ; scanf(" %[^\n]s",kullaniciAdi  ) ; 
	printf("\n\tParola         :  ") ; scanf(" %[^\n]s",parola  ) ; 
	if(  strcmp(kullaniciAdi, "admin") ==0 && strcmp( parola, "12345" ) ==0 ) 
	{
		system("cls"); 
		printf("\n\tGiris Basarili... \n\n") ; 
			yetkiliGiris() ; 		
	}

	else
	printf("\nHatali kullanici adi veya parola ! \n") ; 	
 }

int menu() 
{

	int secim; 
	printf("\n\tARABA GALERISI OTOMASYONU \n\n") ; 
	printf("1- Giris Yap \n") ; 
	printf("0- Programi Kapat \n" ) ; 
	printf("Seciminiz : ") ; scanf("%d", &secim  ) ;  
	
	return secim;  	
}


int main () 
{
	int secim= menu(); 
	while( secim !=  0 ) 
	{
		switch(secim )
		{
			case 1: girisYap();  break; 
			case 0: break; 
			default : printf("hatali secim ! \n"); break; 
		}
		secim= menu(); 
		
	}
	
	printf("Program kapatiliyor...   \n ") ; 
	
	
	
}
