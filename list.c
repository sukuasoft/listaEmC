#include "list.h"
#include <stdlib.h>

LISTA* init()
{   
    return (LISTA *) malloc(1);
}
 
void add(LISTA *list, int value)
{
    if (_msize(list) == 1)
    {
        realloc(list, sizeof(int));
        *list = value;
    }

    else
    {
        int len = _msize(list) / sizeof(int);
        realloc(list, sizeof(int) * (len + 1));
        *(list + len) = value;
    }
}

int len(LISTA* list){
    return _msize(list) / sizeof(int);
}

int contains(LISTA* list, int value){
    for(int x = 0; x < len(list); x++){
        if(*(list + x) == value){
            return 1;
        }
    }   

    return 0;
}

int getValue(LISTA* list, int index)
{
    if(len(list) > 0 &&  len(list) > index){
         return *(list + index);
    }

    else {
        return -1;
    }
}

int getIndex(LISTA* list, int value){

    for(int x = 0; x < len(list); x++){
        if(list[x] == value){
              return x;
        }
      
    }

    return -1;
}

void removeValue(LISTA** list, int value){
    int index = getIndex((LISTA *) *list, value);
    if(index >= 0){
       removeByIndex(list, index);
    }
    return;
}

void removeByIndex(LISTA** list, int index){

    LISTA *pt = (LISTA *) *list;
   if(len(pt) > 0 &&  len(pt) > index){
        LISTA* l = init();

        for(int x = 0; x < len(pt); x++){
            if(x != index){
                add(l, pt[x]);
            }
        }
        
        free(pt);
        *list = (LISTA *) l;
   }

   return;
}