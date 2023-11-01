#include "dlist.h"
#include "polynomials.h"

int main() {
    Mylist<int> list1;
    
    list1.AddElementStart(1);
    list1.AddElementStart(2);
    list1.AddElementStart(3);
    
    Mylist<int>::Iterator it;
    
    list1.AddElementPos(4,list1.begin());
    list1.RmElementPos(++list1.begin());
    
    
    for (it = list1.begin(); it != list1.end(); ++it) {
        printf("%d ", *it);
    }
    
    printf("\n");
    
    Mylist<char> list2;
    
    list2.AddElementStart('a');
    list2.AddElementStart('b');
    list2.AddElementStart('c');
    
    Mylist<char>::Iterator it2;
    
    list2.AddElementPos('d',list2.begin());
    list2.RmElementPos(++list2.begin());
    
    for (it2 = list2.begin(); it2 != list2.end(); ++it2) {
        printf("%c ", *it2);
    }
    
    Mylist<char> list3;
    
    list3.AddElementStart('e');
    list3.AddElementStart('g');
    list3.AddElementStart('f');
    printf("\n");
    printf("\n");
    
    Mylist< Mylist<char> > list4;
    
    list4.AddElementEnd(list2);
    list4.AddElementEnd(list3);

    Mylist< Mylist<char> >::Iterator it4;
    Mylist<char> list;
    
    for (it4 = list4.begin(); it4 != list4.end(); ++it4) {
        list = *it4;
        Mylist< char >::Iterator it;
        for (it = list.begin(); it != list.end(); ++it) {
            printf("%c ", *it);
        }
        printf("\n");
    }
    
    return 0;
}


