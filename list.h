#ifndef LIST_H
    #define LIST_H

    typedef int LISTA;
    LISTA* init();
    void add(LISTA* list, int value);
    int len(LISTA* list);
    int contains(LISTA* list, int value);
    int getValue(LISTA* list, int index);
    int getIndex(LISTA* list, int value);
    void removeValue(LISTA** list, int value);
    void removeByIndex(LISTA** list, int index);
#endif