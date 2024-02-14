#include<stdio.h>
#include<stdlib.h>
#include "mymalloc.h"

#define MEMLENGTH 512
static double memory[MEMLENGTH];

typedef struct Metadata { 
    size_t size;
    int isAllocated;
    Metadata* next;
} Metadata;

void *mymalloc(size_t requestSize, const char *file, int line)
{
    
}



