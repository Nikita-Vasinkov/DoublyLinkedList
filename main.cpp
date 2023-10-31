#include "dlist.h"

int main() {
    Mylist<int> list;
    
    list.AddElementStart(1);
    list.AddElementStart(2);
    list.AddElementStart(3);
    
    Mylist<int>::Iterator it;
    
    list.AddElementPos(4,list.begin());
    list.RmElementPos(list.end());

    
    for (it = list.begin(); it != list.end(); ++it) {
        printf("%d ", *it);
    }

    return 0;
}


