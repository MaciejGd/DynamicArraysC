#include "../lib/dynamic.h"


int main()
{   
    Array arr = array_init(sizeof(int), 10);
    fill_array(&arr, 12);
    push_back(&arr, 123);
    insert_at(&arr, 1, 13);
    pop_at(&arr, 2);
    pop_at(&arr, 2);
    for (int i = 0; i < arr.capacity; i++)
        printf("Element at index: %d :=: %d\n", i, *(int*)array_at(arr, i));
    
    return 0;
}