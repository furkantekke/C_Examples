#include<stdio.h>

#define w 10

int sayi,kap,agirlik[w],para[w],i;


int toplam=0;
int max(int a,int b)
{
  if(a>b)
    return a;
  else
    return b;
}

void giris(){

  printf("Girilecek kac esya var = ");
  scanf("%d",&sayi);
  printf("cantanin kapasitesi = ");
  scanf("%d",&kap);
  for(i = 1; i<=sayi; i++){
    printf("%d. esyanin agirligini giriniz: ",i);
    scanf("%d",&agirlik[i]);
    printf("%d. esyanin degerini giriniz: ",i);
    scanf("%d",&para[i]);
  }
}


void canta(int a,int b,int c[],int d[])
{
  int v[50][50],x[10],i,j; //yeni matrisi yarat
  for(i=0;i<=a;i++)
  v[0][i]=0;

  for(i=1;i<=b;i++)
  {
    for(j=0;j<=a;j++)
    {
      if(j>=c[i])
      v[i][j]=max(v[i-1][j],v[i-1][j-c[i]]+d[i]); //matris degerleri max a gönder.
      else
      v[i][j]=v[i-1][j];
    }
  }

  for(i=1;i<=b;i++)
  x[i]=0;
  i=b;
  j=a;
  while(i>0 && j>0)
  {
    if(v[i][j]!=v[i-1][j]) // karsilastirma islemi
    {
      x[i]=1; //Cantadaki degerleri 1 basiyor..
      j=j-c[i];
    }
    i--;
  }
  printf("\nCantanin icindekiler:\n");

  for(i=1;i<=b;i++)
  {
    if(x[i]==1)
    {
      printf("%d. den =1\t",i); //cantada olacak kumeleri basıyor.
      toplam=toplam+d[i];
    }
    else
    printf("%d. den =0\t",i);
  }
  printf("\nToplam = %d\n",toplam); //toplam max parayı
}

int main()
{
  giris();
  canta(kap,sayi,agirlik,para);
  return 0;
}
