#ifndef ARRAY
#define ARRAY
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t item_size;
    size_t capacity;
    Allocator *a;
} Array;

Array array_init(size_t item_size, size_t initial_cap);
void push_back(Array *a, size_t val);
void insert_at();

#endif