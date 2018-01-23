#include<stdio.h>
#define LEN 256
int main()
{
  FILE * fp;
  int i;
  /*abre el archivo para escribir*/
  fp = fopen("ejemplo.txt", "w");
 
  /*escribe 10 lineas de texto en el archivo*/
  for(i=0; i<10; i++){
	fprintf(fp, "esta es la linea %d\n", i+1);
  }
 
  printf("\nArchivo ejemplo.txt actualizado\n");
  /*cierra el archivo*/
  fclose (fp);
  return 0;
}
