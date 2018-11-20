#include "My_list.h"
#include "stdio.h"
using namespace MyList;

Elem* list::Insert_after(Elem* elem, Elem_t new_data)
{
    assert (elem != nullptr);

    Elem* new_elem = new Elem;

    new_elem->next = elem->next;
    new_elem->prev = elem;
        elem->next = new_elem;

    new_elem->data = new_data;

    if (new_elem->next == nullptr)
              tail = new_elem;

    size++;
    return new_elem;
}

Elem* list::Insert_before(Elem* elem, Elem_t new_data)
{

    assert (elem != nullptr);

    Elem* new_elem = new Elem;

    new_elem->prev = elem->prev;
    new_elem->next = elem;
        elem->prev = new_elem;

    new_elem->data = new_data;

    if (new_elem->prev == nullptr)
              head = new_elem;

    size += 1;
    return new_elem;
}

int list::Remove(Elem *elem)
{

    assert (elem != nullptr);
    assert (size != 1);

    // if delete head
    if (elem->prev == nullptr)
    {
        elem->next->prev = nullptr;
        head = elem->next;

        size--;
        delete[] elem;
        return 0;
    }

    // if delete tail
    if (elem->next == nullptr)
    {
        elem->prev->next = nullptr;
        tail = elem->prev;

        size--;
        delete[] elem;
        return 0;
    }

    elem->prev->next = elem->next;
    elem->next->prev = elem->prev;

    size--;
    delete[] elem;
    return 0;
}

list::~list()
{
    while (size > 0)
    {
        Elem* tmp = head;

        head = head->next;

        delete[] tmp;
        size--;
    }
}

int list::Verificator()
{
    //check size
    if (size < 1) return 1;

    // check head and tail
    if (head->prev != nullptr || tail->next != nullptr)
        return 3;

    //go through elems
    Elem* ptr = head;
    int sz = 1;

    for ( ; ptr != tail && sz < size; sz++)
    {
        if (ptr == nullptr) return 5;

        if (ptr->next != nullptr)
        {
            if (ptr->next->prev != ptr) return 3;
        }
        else
        {
            if (ptr != tail) return 4;
        }

        ptr = ptr->next;
    }

    // check that tail is on the size^th place
    if (sz != size || ptr != tail) return 2;

    return 0;
}

int list::Dump()
{
    Elem* ptr = head;

    assert (head != nullptr && tail != nullptr);
    printf ("size: %d\n", size);

    printf ("head: addres: %p, data: %d, prev: %p, next %p\n",
             head, head->data, head->prev, head->next);

    printf ("tail: addres: %p, data: %d, prev: %p, next %p\n\n",
             tail, tail->data, tail->prev, tail->next);

    for (int i = 1; i <= size && ptr != nullptr; i++ )
    {
        printf ("%d: addres: %p, data: %d, prev: %p, next %p\n",
                 i, ptr, ptr->data, ptr->prev, ptr->next);
        ptr = ptr->next;
    }

    return 0;
}
