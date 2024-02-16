#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    size_t capacity;
    size_t item_size;
    void *items;
} Array;

//checking if memory has been allocated successfully
int allocate_error(const void *mem, char *prompt);
//initialization of Array
Array array_init(size_t item_size, size_t initial_cap);
//fill array with wanted value
void fill_array(Array *a, size_t val);
//add element to the back of array
void push_back(Array *a, size_t val);
//change value of element at wanted index
void insert_at(Array *a, size_t index, size_t val);
//expand array by adding value at wanted index
void add_at_index(Array *a, size_t index, size_t val);
//erase element of array at wanted index
void pop_at(Array *a, size_t index);
//get element of array at index
void *array_at(const Array a, size_t index);