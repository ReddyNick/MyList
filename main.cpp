#include <iostream>
#include "My_list.h"
#include "stdio.h"

int Write(MyList::Elem* ptr)
{
    while (ptr != nullptr)
    {
        printf ("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf ("\n");
    return 0;
}
int main()
{

    MyList::list ls = {};
    MyList::Elem ptr = {};

    ls.head->data = 1;

    ls.Insert_after (ls.head, 2);
    ls.Insert_before (ls.head, 3);

    //ls.head = &ptr;
    ls.head->next->prev = &ptr;

    printf ("verificator - %d\n", ls.Verificator());

    ls.Dump();

    //ls.Remove (ls.head->next);

    //printf ("verificator - %d\n", ls.Verificator());

    return 0;
}