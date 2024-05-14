#ifndef MENU_H
#define MENU_H

#include "algorithms.h"

enum MenuElement {
    InsertSort,
    SelectionSort,
    BubbleSort,
    Quicksort,
    Shellsort,
    Heapsort,
    End
};

void print_menu();

#endif
