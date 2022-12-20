#ifndef LIST_H
    #define LIST_H

    typedef int LISTA;
    LISTA* init();
    int len(LISTA* list);
    void add(LISTA* list, int value);
    int contains(LISTA* list, int value);
    int getValue(LISTA* list, int index);
    int getIndex(LISTA* list, int value);
    void removeValue(LISTA** listPt, int value);
    void removeByIndex(LISTA** listPt, int index);
    void insertValue(LISTA** listPt, int value, int index);
    LISTA* reverse(LISTA* lista);

    //RANGE OU SEJA LISTAS

   // void addRange(LISTA* list, LISTA* listRange);
   //  void removeRange(LISTA* list, LISTA* listRange);
    // void insertRange(LISTA* list, LISTA* listRange, int index);
    // LISTA *getRange(LISTA *list, int index, int count);
    

    //outros
    void clearList(LISTA* list);
     int* listToArray(LISTA* list);
#endif