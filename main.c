#include  <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <malloc.h>

void exibir(LISTA* lista);
int main(){

    system("cls");
    //inicializando a lista
   // int *p = malloc(1);

    LISTA *lista = init();

    /*
    for (int x = 1; x <= 10; x++)
    {
        add(lista, x);
    }
    
    for (int x = 0; x < len(lista); x++)
    {
        //printf("%d\n", *(p + x)); pode ser desse jeito ou desse abaixo
        printf("%d\n", lista[x]);
    
    }
    */


   /*
        testando outras funcionalidades
  

      for (int x = 1; x <= 10; x++)
    {
        add(lista, x);
    }

    for(int x= 0; x < len(lista); x++){
        int value = getValue(lista, x);
        if(value % 2 != 0){
            removeValue(&lista, value);
        }
    }

    for(int x = 0; x < len(lista); x++){
        printf("%d\n", getValue(lista, x));
    }
     */

   for (int x = 1; x <= 10; x++)
    {
        
        add(lista, x);
    }

    LISTA* l=init();
    add(l, 24);
    add(l, 28);
    add(l, 33);
  //  add(l, 34);

  //  printf("---");
  //  printf("lista size: %d", sizeof(lista) / sizeof(int));
    printf("--\n");
    addRange(lista,l);
    system("cls");
    exibir(lista);
    return 0;
}

void exibir(LISTA* lista){
       for(int x = 0; x < len(lista); x++){
        printf("%d\n", getValue(lista, x));
    }
    return;
}