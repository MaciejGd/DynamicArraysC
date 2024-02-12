#include "../lib/dynamic.h"

Array array_init(size_t item_size, size_t initial_cap)
{   
    return (Array)
    {
        .capacity = initial_cap,
        .item_size = item_size,
        .items = malloc(item_size * initial_cap),
    };
}

//segmentation fault - something to do with my aproach to realloc use
void push_back(Array *a, size_t val)
{   
    if (a->capacity == 0)
    {
        memcpy(a->items, &val, a->item_size);
        a->capacity++;
        return;
    }
    //create temporary pointer bigger than orginal by one item size
    char *temp = malloc((a->item_size)*(a->capacity + 1));
    //copying values to temporary pointer
    memcpy(temp, a->items, a->capacity * a->item_size);
    memcpy(temp+(a->item_size * a->capacity), &val, a->item_size);
    //reallocing memory of array pointer and increasing capacity 
    a->capacity++;
    a->items = realloc(a->items, a->item_size*a->capacity);
    //put the values back to original pointer
    memcpy(a->items, temp, a->capacity * a->item_size);
    //free memory allocated on heap for temporary pointer
    free(temp);
}

void insert_at(Array *a, size_t index, size_t val)
{
    if (index >= a->capacity || index < 0)
    {
        printf("Insertion index %d out of scope\n", index);
        return;
    }
    char *temp = a->items;
    memcpy(temp + (a->item_size * index), &val, a->item_size);
}

void fill_array(Array *a, size_t val)
{   
    int i;
    char *temp = a->items;
    for (i = 0; i < a->capacity; i++)
    {   
        memcpy(temp, &val, a->item_size);
        temp+=a->item_size;
    } 
}

void pop_at(Array *a, size_t index)
{
    //checking if index is in a scope of array
    if (index >= a->capacity || index < 0)
    {
        printf("Index %d out of array scope\n", (int)index);
        return;
    }
    char *head = a->items;
    //creating new pointer for values after removing
    char *temp = (char*)malloc(a->item_size * (a->capacity - 1));
    //adding left from removed element and then right to temp pointer
    memcpy(temp, head, index * a->item_size);
    memcpy(temp+(index*a->item_size), head + (index + 1)*a->item_size, a->item_size * (a->capacity - index - 1));
    //changing size of memory for original pointer
    a->items = realloc(a->items, a->item_size * (a->capacity - 1));
    //copying temp to a->items
    memcpy(a->items, temp, a->item_size * (a->capacity - 1));
    //freeing memory of temp pointer and decreasing capacity of array
    free(temp);
    a->capacity--;
}

void *array_at(const Array a, size_t index)
{   
    char *temp = a.items;
    if (index >= a.capacity || index < 0)
    {   
        printf("Index out of Array scope\n");
        return NULL;
    }
    return temp + (a.item_size * index);
}
