

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



//queue struct yapisi

struct Kuyruk
{
	int on, arka,boyut;
	unsigned kapasite;
	int* dizi;
};


//creating queue

struct Kuyruk* KuyrukYarat(unsigned kapasite)
{
	struct Kuyruk* queue = (struct Kuyruk*) malloc(sizeof(struct Kuyruk));
	queue->kapasite =kapasite;
	queue->on = queue->boyut = 0;
	queue->arka = kapasite - 1; // Kuyruktan bas elemani silerken lazım olacak
	queue->dizi = (int*) malloc(queue->kapasite * sizeof(int));
	return queue;
}

// when queue size is equal to capasity than queue is full

int isFull(struct Kuyruk* queue)
{ return (queue->boyut == queue->kapasite); }


// queue size = 0 when queue is empty

int isEmpty(struct Kuyruk* queue)
{ return (queue->boyut == 0); }


//Using this func to adding element in queue

void ekle(struct Kuyruk* queue, int item)
{
	if (isFull(queue))
		return;
	queue->arka = (queue->arka + 1)%queue->kapasite;
	queue->dizi[queue->arka] = item;
	queue->boyut = queue->boyut + 1;
	printf("%d kuyruka eklendi\n", item);
}


//deleting first in the queue because of firs in firs out rule

int sil(struct Kuyruk* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->dizi[queue->on];
	queue->on = (queue->on + 1)%queue->kapasite;
	queue->boyut = queue->boyut - 1;
	return item;
}


//this function is returning first element in the queue

int front(struct Kuyruk* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->dizi[queue->on];
}

int main(){

	 // dos  = çikolata dagitilacak ogrenci sayisi
	// hkos = her kuyruktaki ogrenci sayisi
   // mec = mutlu edecek cikolata sayisi
  // dequeue ve enqueue işlemleri; sil ve ekle fonksiyonları olarak adlandırıldı

	int mec,dos,hkos,x=0,i=1,toplam=0;

	puts("we have 3 queues in total");

	printf("How many student ");		scanf("%d",&dos);

	printf("Total students in per queues ");	scanf("%d",&hkos);

	struct Kuyruk* kuyruk1 = KuyrukYarat(hkos);
	struct Kuyruk* kuyruk2 = KuyrukYarat(hkos);
	struct Kuyruk* kuyruk3 = KuyrukYarat(hkos);
	struct Kuyruk* kuyruk4 = KuyrukYarat(hkos);

	puts("Can you give me chocolates pieces will be happy per students: ");

	while(x<hkos){
	scanf("%d",&mec);
	ekle(kuyruk1,mec);
	ekle(kuyruk2,mec);
	ekle(kuyruk3,mec);
	ekle(kuyruk4,9);
	x++;
	}



	toplam+=front(kuyruk1);
	printf("%d added sum from queue1 =  \n",front(kuyruk1));
	sil(kuyruk1);

while(i<dos){

if(front(kuyruk1)<front(kuyruk2)){

	toplam+=front(kuyruk1);
	printf("%d added sum from kuyruk1 =  \n",front(kuyruk1));
	sil(kuyruk1);
	 i++;
	}
else{

	toplam+=front(kuyruk2);
	printf("%d added sum from kuyruk2 =  \n",front(kuyruk2));
	sil(kuyruk2);
	i++;
  
	if(i<dos){
		if(front(kuyruk2)<front(kuyruk3)){
			toplam+=front(kuyruk2);
			printf("%d added sum from kuyruk2 =\n",front(kuyruk2));
			sil(kuyruk2);
			i++;
			}
			}
		if(i<dos){
		if(front(kuyruk2)>front(kuyruk3)){
					toplam+=front(kuyruk3);
					printf("%d added sum from kuyruk3 = \n",front(kuyruk3));
					sil(kuyruk3);
					i++;}
if(i<dos){
        if(front(kuyruk3)<front(kuyruk4)){
			toplam+=front(kuyruk3);
			printf("%d added sum from kuyruk3 =",front(kuyruk3));

			i++;
			}
		}
		}
	}
	}

	printf("Toplam=%d",toplam);

	return 0;
	}
