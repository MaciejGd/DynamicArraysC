#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    size_t capacity;
    size_t item_size;
    void *items;
} Array;

Array array_init(size_t item_size, size_t initial_cap);
void push_back(Array *a, size_t val);
void insert_at(Array *a, size_t index, size_t val);
void fill_array(Array *a, size_t val);
void pop_at(Array *a, size_t index);
void *array_at(const Array a, size_t index);
