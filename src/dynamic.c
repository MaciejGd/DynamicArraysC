#include "../lib/dynamic.h"

int allocate_error(const void *mem, char *prompt)
{
    if (mem == NULL)
    {
        printf(prompt);
        return 1;
    }
    return 0;
}

Array array_init(size_t item_size, size_t initial_cap)
{   
    return (Array)
    {
        .capacity = initial_cap,
        .item_size = item_size,
        .items = malloc(item_size * initial_cap),
    };
}

void fill_array(Array *a, size_t val)
{   
    int i;
    char *temp = a->items;
    //iterating over a->items and putting value in
    for (i = 0; i < a->capacity; i++)
    {   
        memcpy(temp, &val, a->item_size);
        temp+=a->item_size;
    } 
}

void push_back(Array *a, size_t val)
{   
    if (a->capacity == 0)
    {
        memcpy(a->items, &val, a->item_size);
        a->capacity++;
        return;
    }
    a->capacity++;
    //resizing a->items
    a->items = realloc(a->items, a->item_size*a->capacity);
    //checking for allocation error
    if (allocate_error(a->items, "Failed to reallocate memory for a->items using push_back()\n")) return;
    //putting value at the end of a->items
    memcpy(a->items + (a->item_size * (a->capacity - 1)), &val, a->item_size);
}

void insert_at(Array *a, size_t index, size_t val)
{
    if (index >= a->capacity || index < 0)
    {
        printf("Insertion index %lld out of array length\n", index);
        return;
    }
    //putting value at desired position
    memcpy(a->items + (a->item_size * index), &val, a->item_size);
}

void add_at_index(Array *a, size_t index, size_t val)
{
    if (index >= a->capacity || index < 0)
    {
        printf("Index %lld out of array length\n", index);
        return;
    }
    //resize a->items
    a->items = realloc(a->items, a->item_size * (a->capacity + 1));
    //move every element right from index by one and then add val into index
    memcpy(a->items + (a->item_size * (index + 1)), a->items + a->item_size * index, a->item_size * (a->capacity - index));
    memcpy(a->items + a->item_size * index, &val, a->item_size);
    //capacity of array increased
    a->capacity++;
}



void pop_at(Array *a, size_t index)
{
    //checking if index is in a scope of array
    if (index >= a->capacity || index < 0)
    {
        printf("Index %d out of array scope\n", (int)index);
        return;
    }
    //moving items from index + 1 to end one place left
    memcpy(a->items + (a->item_size * index), a->items + (a->item_size * (index + 1)), a->item_size * (a->capacity - index - 1));
    a->capacity--;
    //changing a->items size
    a->items = realloc(a->items, a->item_size * a->capacity);
    //checking for allocate error 
    if (allocate_error(a->items, "Failed to reallocate memory for a->items using pop_back()")) return;
}

void *array_at(const Array a, size_t index)
{   
    if (index >= a.capacity || index < 0)
    {   
        printf("Index out of Array scope\n");
        return NULL;
    }
    return a.items + (a.item_size * index);
}
