#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Struktur ADT DynamicArray
typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

// Prototipe fungsi
void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, int value);
void dArray_popBack(DynamicArray *darray);
int  dArray_back(DynamicArray *darray);
int dArray_getAt(DynamicArray *darray, unsigned index);
void dArray_insertAt(DynamicArray *darray, unsigned index, int value);
void dArray_removeAt(DynamicArray *darray, unsigned index);

// Fungsi main
int main(int argc, char const *argv[]) {
    // Buat objek DynamicArray
    DynamicArray myArray;

    // PENTING! Jangan lupa diinisialisasi
    dArray_init(&myArray);

    // Sebagai indeks
    int i = 0;
    int n, k;
    scanf("%d %d", &n, &k);
    
    if(k > 0)
    {
        for(i = 1; i <= n; i++)
        {
            dArray_pushBack(&myArray, i);
        }
    
        int index = 0;
        for(i = 1; i < n; i++)
        {
            index += k;
        
            if(index >= myArray._size)
                index = (index)%(myArray._size);
        
            printf("%d ", dArray_getAt(&myArray, index));
            dArray_removeAt(&myArray, index);
        }
        printf("~ %d", dArray_back(&myArray));
        dArray_popBack(&myArray);
    }
    if(k < 0)
    {
        for(i = n; i >= 1; i--)
        {
            dArray_pushBack(&myArray, i);
        }
    
        int index = -1;
        k = abs(k);
        for(i = 1; i < n; i++)
        {
            index += k;
        
            if(index >= myArray._size)
                index = (index)%(myArray._size);
        
            printf("%d ", dArray_getAt(&myArray, index));
            dArray_removeAt(&myArray, index);
        }
        printf("~ %d", dArray_back(&myArray));
        dArray_popBack(&myArray);
    }
    

    return 0;
}

// Inisialisasi Dynamic Array
void dArray_init(DynamicArray *darray) {
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int *)malloc(sizeof(int) * 2);
}

// Fungsi pushBack
void dArray_pushBack(DynamicArray *darray, int value) {
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int *)malloc(sizeof(int) * darray->_capacity);

        for (it = 0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];

        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}

//Fungsi popBack
void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--;
    else return;
}

//FungsiBack
int dArray_back(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    else return 0;
}

// Fungsi insertAt
void dArray_insertAt(DynamicArray *darray, unsigned index, int value) {
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int *)malloc(sizeof(int) * darray->_capacity);

        for (it = 0; it <= darray->_size; ++it)
            newArr[it] = darray->_arr[it];

        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    int i;
    for (i = darray->_size++; i > index; i--)
        darray->_arr[i] = darray->_arr[i - 1];

    darray->_arr[index] = value;
}

// Memastikan size
bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

// Fungsi removeAt
void dArray_removeAt(DynamicArray *darray, unsigned index) {
    if (index != darray->_size) {
        unsigned it;

        for (it = index + 1; it < darray->_size; ++it)
            darray->_arr[it - 1] = darray->_arr[it];
    }
    darray->_size--;
}

// Fungsi getAt
int dArray_getAt(DynamicArray *darray, unsigned index) {
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size - 1];
        else
            return darray->_arr[index];
    }
    return 0;
}
