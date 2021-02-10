#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//esto es lo que estara en la cola
typedef struct listitem {
	struct listitem *next; //puntero del primer item
 	struct listitem * prev; //puntero del item previo
	int data; //some data
}LISTITEM;

//este es el header de la cola
typedef struct {
	struct  listitem *first; //puntero del item primero
	struct listitem *last; //puntero del item  ultimo
}LISTHDR;

LISTHDR head;

//esto pone un item al final de la cola
void enqueue(LISTITEM *item){
	LISTITEM *temp;

	temp = head.last; //el ultimo item en la cola y  se lo queda
	head.last = item; //pone el item en la cola al final
	item->prev = temp; //enlace atras hacia el item viejo
	item->next = (LISTITEM*)&head; // pone el enlace hacia delante del nuevo item
	temp->next = item; //y finalmente pone el enlace hacia delante del viejo 'ultimo' item para encontrar uno nuevo
}

//remueve un item al frente de la cola - retorna el item o NULL si ya no hay mas items
LISTITEM *dequeue(){
	LISTITEM *temp;
	temp = head.first; //obtiene el primer item
	if(temp == (LISTITEM*)&head){ //si el encabezado de la cola apunta asi misma ...
		temp = NULL; //...entonces la cola esta vacia
	}
	else {
		head.first = temp->next; //y pone el header de la cola al punto del segundo item
		head.first->prev = (LISTITEM*)&head;
	}
	return temp;
}


int main(){
	LISTITEM *temp;
	//primero, haz una cola vacia
	//la cual es una cola donde el header apunta asi mismo y donde no tiene items
	head.first = (LISTITEM*)&head;
	head.last = (LISTITEM*)&head;

		for(int i = 0; i < 10; i++){ //poner datos en la cola
			temp = malloc(sizeof(LISTITEM)); //espacio en la memoria para el nuevo item en la cola
			temp->data = i; //pone los datos del item en el contador del for para poder ver donde esta en la cola
			enqueue(temp); //los pone en la cola
			}

	printf("primer item = %d\n", head.first->data);
	printf("ultimo item = %d\n\n", head.last->data);

	//ahora vamos a sacar los elementos de la cola empezando por el final, osea por el ultimo datos de la cola
		
		do {
			 //continua hasta que la cola este vacia

			temp = dequeue(); //si la cola esta vacia nos regresara un NULL
			if(temp != NULL) {
				printf("data is %d\n", temp->data);
				free(temp); //llamamos 'free' para limpiar memoria
				}
		}while(temp != NULL);
		return(0);
}
