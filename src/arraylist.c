#include "../include/arraylist.h"
#include <stdlib.h>

struct arraylist* arraylist_create(int capacity) {
    if(capacity < 0) {
        printf("Array list capacity must be greater than 0.\n");
        return NULL;
    }

    struct arraylist* newArrayList = (struct arraylist*) malloc(sizeof(struct arraylist));

    if(newArrayList == NULL) {
        printf("Could not create arraylist.\n");
        return NULL;
    }

    newArrayList->array = (int*) malloc(sizeof(int) * capacity);

    if(newArrayList->array == NULL) {
        printf("Could not allocate memory for arraylist.\n");
        free(newArrayList);
        newArrayList = NULL;
        return NULL;
    }

    newArrayList->count = 0;
    newArrayList->capacity = capacity;

    return newArrayList;
}

void arraylist_add(struct arraylist* arrayList, int newValue) {
    if(!arraylist_is_defined(arrayList)) {
        printf("Array list is not defined.\n");
        return;
    }

    if(arrayList->count == arrayList->capacity) {
        printf("Array list is full.\n");
        return;
    }

    if(arrayList->count < 0 || arrayList->count > arrayList->capacity) {
        printf("Array list count value is faulty.\n");
        return;
    }

    arrayList->array[arrayList->count] = newValue;
    arrayList->count++;

    return;
}

void arraylist_add_at_index(struct arraylist* arrayList, int newValue, int index);
void arraylist_remove(struct arraylist* arrayList);
void arraylist_remove_at_index(struct arraylist* arrayList, int index);
void arraylist_display(struct arraylist* arrayList);
void arraylist_delete(struct arraylist** arrayListParent);

int arraylist_is_defined(struct arraylist* arraylist) {
    if(arraylist == NULL) {
        return 0;
    }

    return 1;
}