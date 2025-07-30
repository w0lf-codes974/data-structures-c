#ifndef ARRAYLIST_H
#define ARRAYLIST_H

struct arraylist {
    int* array;
    int count;
    int capacity;
};

struct arraylist* arraylist_create(int capacity);
void arraylist_add(struct arraylist* arrayList, int newValue);
void arraylist_add_at_index(struct arraylist* arrayList, int newValue, int index);
void arraylist_remove(struct arraylist* arrayList);
void arraylist_remove_at_index(struct arraylist* arrayList, int index);
void arraylist_display(struct arraylist* arrayList);
void arraylist_delete(struct arraylist** arrayListParent);

int arraylist_is_defined(struct arraylist* arraylist);

#endif ARRAYLIST_H