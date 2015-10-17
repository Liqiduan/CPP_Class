#include "CLibArray.h"

void array_initial(CArray *array)
{

}

int array_capacity(CArray *array)
{
    return array->max_size;
}
int array_size(CArray *array)
{
    return array->used_size;
}

void array_recap(CArray *array, int size);

int *array_at(CArray *array, int index);
void array_append(CArray *array, int element);
void array_insert(CArray *array, int index, int element);

void array_copy(CArray *src, CArray *dst);
bool array_compare(CArray *array1, CArray *array2);

void array_destroy(CArray *array);

