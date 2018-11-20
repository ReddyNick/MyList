
#ifndef MYLIST_MY_LIST_H
#define MYLIST_MY_LIST_H

#include "stdlib.h"
#include "assert.h"

typedef int Elem_t;

namespace MyList
{

struct Elem
{
    Elem*  prev = nullptr;
    Elem*  next = nullptr;
    Elem_t data = 0;
};

class list
{
public:

    int   size = 1;
    Elem* head = new Elem;
    Elem* tail = head;

   ~list();

    Elem* Insert_after(Elem* elem, Elem_t new_data);
    Elem* Insert_before(Elem* elem, Elem_t new_data);

    int Remove(Elem* elem);
    int Verificator();
    int Dump();
};

}   // MyList


#endif //MYLIST_MY_LIST_H
