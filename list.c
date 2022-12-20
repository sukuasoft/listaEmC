#include "list.h"
#include <stdlib.h>
#include <stdio.h>

LISTA *init()
{
    return (LISTA *)malloc(1);
}

int len(LISTA *list)
{
    return _msize((LISTA *) list) / sizeof(int);
}

void add(LISTA *list, int value)
{
    if (_msize((LISTA *) list) == 1)
    {
        realloc((LISTA *) list, sizeof(int));
        *list = value;
    }

    else
    {
        int size = len((LISTA *) list);
        realloc((LISTA *) list, sizeof(int) * (size + 1));
        *(list + size) = value;
    }
}

int contains(LISTA *list, int value)
{
    for (int x = 0; x < len(list); x++)
    {
        if (*(list + x) == value)
        {
            return 1;
        }
    }

    return 0;
}

int getValue(LISTA *list, int index)
{
    if (len(list) > 0 && len(list) > index)
    {
        return *(list + index);
    }

    else
    {
        return -1;
    }
}

int getIndex(LISTA *list, int value)
{

    for (int x = 0; x < len(list); x++)
    {
        if (list[x] == value)
        {
            return x;
        }
    }

    return -1;
}

void removeValue(LISTA **listPt, int value)
{
    int index = getIndex((LISTA *)*listPt, value);
    if (index >= 0)
    {
        removeByIndex(listPt, index);
    }
    return;
}

void removeByIndex(LISTA **listPt, int index)
{

    LISTA *pt = (LISTA *)*listPt;
    if (len(pt) > 0 && len(pt) > index)
    {
        LISTA *l = init();

        for (int x = 0; x < len(pt); x++)
        {
            if (x != index)
            {
                add(l, pt[x]);
            }
        }

        free(pt);
        *listPt = (LISTA *)l;
    }

    return;
}

void insertValue(LISTA **listPt, int value, int index)
{
    LISTA *list = (LISTA *)*listPt;
    int qtd = len(list);
    if (qtd >= 0 && (qtd > index || index == 0))
    {
        if (qtd == 0)
        {
            add(list, value);
            return;
        }

        LISTA *l = init();
        for (int x = 0, y = 0; x < qtd; y++)
        {
            if (y == index)
            {
                add(l, value);
            }

            else
            {
                add(l, list[x]);
                x++;
            }
        }

        free(list);
        *listPt = (LISTA *)l;
    }
    return;
}

LISTA *reverse(LISTA *lista)
{
    if (len(lista) < 2)
    {
        return NULL;
    }

    LISTA *ls = init();

    for (int x = len(lista) - 1; x >= 0; x--)
    {
        add(ls, getValue(lista, x));
    }

    return ls;
}

// range
/*
void addRange(LISTA *list, LISTA *listRange)
{
    for (int x = 0; x < len(listRange); x++)
    {  
        add(list, getValue(listRange, x));
    }
}

void removeRange(LISTA *list, LISTA *listRange)
{
    for (int x = 0; x < len(listRange); x++)
    {
        removeValue(&list, getValue(listRange, x));
    }
}

void insertRange(LISTA *list, LISTA *listRange, int index)
{
    for (int x = 0; x < len(listRange); x++)
    {
        insertValue(&list, getValue(listRange, x), index);
        index++;
    }
}

LISTA *getRange(LISTA *list, int index, int count)
{
    int qtd = len(list);
    if (qtd == 0 || index >= qtd)
    {
        return NULL;
    }
    LISTA *ls = init();
    int target = 0;
    if (qtd <= index + count)
    {
        target = index + count;
    }
    else
    {
        target = qtd;
    }

    for (int x = index; x < target; x++)
    {
        add(ls, getValue(list, x));
    }

    return ls;
}
*/

//outros

 void clearList(LISTA* list){
   realloc( (LISTA *) list, 1);
 }

 int* listToArray(LISTA* list){
    
    if(len(list) > 0)
    {
          int* items;
         items = (int *) malloc(len(list) * sizeof(int));
         for(int x = 0; x < len(list); x++){
            items[x] = getValue(list, x);
         }
         return items;
    }

    else{
        return NULL;
    }
 }