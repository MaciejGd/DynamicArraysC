#include "../lib/dynamic.h"

int main()
{   
    Array arr = array_init(sizeof(int), 10);
    fill_array(&arr, 2);
    push_back(&arr, 12);
    pop_at(&arr, 1);
    pop_at(&arr, 2);
    insert_at(&arr, 1, 123);
    add_at_index(&arr, 2, 45);
    for (int i = 0; i < arr.capacity; i++)
    {
        printf("Index: %d -> value: %d\n", i, *(int*)array_at(arr, i));
    }
    return 0;
}