

#ifndef __CLIBARRAY__
#define __CLIBARRAY__


typedef struct Element_Struct
{
    unsigned int data;
    Element_Struct* last, *next;
}Element_t;

typedef struct
{
    unsigned int max_size;
    unsigned int used_size;
    Element_t head;
}CArray;

void array_initial(CArray *array);

int array_capacity(CArray *array);
int array_size(CArray *array);

void array_recap(CArray *array, int size);

int *array_at(CArray *array, int index);
void array_append(CArray *array, int element);
void array_insert(CArray *array, int index, int element);

void array_copy(CArray *src, CArray *dst);
bool array_compare(CArray *array1, CArray *array2);

void array_destroy(CArray *array);


#endif

