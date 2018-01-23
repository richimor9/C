#include <stdio.h>

main()
{
  int a; 
  int *p;

 printf("Ingrese un valor entero para la variable:\n");
 scanf("%d",&a);
 while(a < 0)
 {
	printf("error, el valor debe ser mayor a cero.\n");
	scanf("%d", &a);
 }

 printf("a=%d\n", a);
 printf("La direccion de a es %p\n", &a);
 printf("*p=%p\n", p); //la direccion que guarda p
 //imprime valor guardado en la direccion a la que apunta p
 printf("a=%d\n",*p);
 /*imprime el valor guardado en la direccion a la que apunta p*/
 printf("a=%d\n", *p);
 printf("el tamaño de *p es %d\n", sizeof(p));
 
 return;
 }


				
