#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mymalloc.h"

#define MEMLENGTH 512

static char memory[MEMLENGTH];

typedef struct Metadata{
    size_t size;
    struct Metadata* next;
    bool isFree;
    char data[1];
} Metadata;

static Metadata* base = (Metadata*) memory;
static Metadata* *end = (char*) &memory[MEMLENGTH];

bool isAdjacentAndFree(Metadata* left, Metadata* right) {
    // Calculate the end address of left and check if it directly precedes right
    char* endOfLeft = ((char*)left) + sizeof(Metadata) + left->size;
    return (endOfLeft == (char*)right) && left->isFree;
}


void mergeBlocks(Metadata* left, Metadata* right) {
    left->size += right->size + sizeof(Metadata); // Include the size of the right block and its header
    left->isFree = true; // Ensure the merged block is marked as free
    left->next = right->next; // Update the next pointer to bypass 'right'
}

Metadata* nextBlock(Metadata* current) {
    if (current->next == NULL) return NULL;
    return current->next;
}


void* mymalloc(size_t size, char* file, int line){
    if (base->size == 0)
        init();
    Metadata* curr = base;
    while (curr){
        if (curr->isFree && curr->size >= size){
            curr->isFree = false;
            if (curr->size > sizeof(Metadata) + size){
                Metadata* temp = (Metadata*) (curr->data + size);
                temp->isFree = true;
                temp->size = curr->size - size - sizeof(Metadata);
                temp->next = curr->next;
                curr->size = size;
                curr->next = temp;
            }
            return curr->data;
        }
        curr = curr->next;
    }
    fprintf(stderr, "Error in %s at line %d: Out of memory.\n", file, line);
    return NULL;

}


void myfree(void* ptr, char* file, int line) {
    if (!ptr) {
        fprintf(stderr, "Error in %s at line %d: Null pointer.\n", file, line);
        return;
    }

    Metadata* metPtr = (Metadata*)((char*)ptr - offsetof(Metadata, data));
    if (metPtr->isFree) {
        fprintf(stderr, "Error in %s at line %d: Double free detected.\n", file, line);
        return;
    }
    metPtr->isFree = true; // Mark the block as free

    // Attempt to merge with next block if it's free
    if (metPtr->next && metPtr->next->isFree) {
        mergeBlocks(metPtr, metPtr->next);
    }

    // Attempt to merge with previous block if it's free
    Metadata* current = base;
    while (current) {
        if (current->next == metPtr && current->isFree) {
            mergeBlocks(current, metPtr);
            break;
        }
        current = current->next;
    }
}

void init(){
    base->isFree = true;
    base->size = MEMLENGTH - sizeof(Metadata);
    base->next = NULL;
}



