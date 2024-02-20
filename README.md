# myLittleMalloc

Yash Shah, NetID: yss28
Vedant, NetID: vv277
CS214 Assignment 1 "my little malloc()"

Design:
mymalloc.c
memtest.c
memgrind.c

**MY FREE**********
The myfree() function is responsible for deallocating memory that was previously allocated using mymalloc(). Here's a detailed explanation of what myfree() does:

**Parameters******:
ptr: This is a pointer to the memory block that needs to be deallocated. It should be the same pointer returned by a previous call to mymalloc().
Functionality:

**Validation******: 
The function first checks if the provided pointer ptr is NULL. If it is NULL, it indicates an invalid address, and an error message is printed.

**Coalescing**:After marking the memory block as free, myfree() may perform coalescing. Coalescing is the process of merging adjacent free memory blocks to prevent fragmentation. It helps in optimizing memory usage.
**Error Handling**: If the provided pointer is not NULL but does not point to a valid allocated memory block (e.g., it points to an already freed block), an error message is printed to indicate the issue.

**Coalescing:**

The coalesce() function is called to merge adjacent free memory blocks. It helps in optimizing memory usage by combining contiguous free blocks into larger blocks, reducing fragmentation.
coalesce() merges both the previous and next free blocks with the currently freed block, if available. It iterates over the memory blocks to find adjacent free blocks and merge them.
Error Handling:

myfree() handles potential errors such as attempting to free a NULL pointer or trying to free an already freed memory block.
If the provided pointer is NULL, it prints an error message indicating that an invalid address was passed to myfree().
If the memory block associated with the provided pointer is already freed, it prints an error message indicating that the memory is already free.
    Test Plan (Test# correlates to specific test):

    Test #1: Attempts to allocate a large block of memory (1000 bytes) which is expected to fail due to insufficient memory.
    Test #2: Allocates a small block of memory (120 bytes), fills it with characters, and then frees it to test basic allocation and deallocation functionality.
    Test #3: Attempts to free a memory block twice, which should result in an error since it's not allowed to free the same memory block more than once.
    Test #4: Tests fragmentation by allocating/deallocating memory in fragmented free blocks. Then, it tries allocate a large block to see it succeed after fragmentation.
    Test #5: Allocates multiple memory blocks, fills them with strings, and then frees them to test multiple allocations and deallocations.
    Test #6 - Coalesce: fragmentation by allocating/deallocating memory blocks, allocates a large block which should succeed if the coalesce function merges adjacent free blocks.
    Test #7: Attempts to allocate a large block of memory (1,000,000 bytes) to test the behavior with large allocations.
    Test #8: Allocates memory without freeing it, simulating a memory leak scenario where memory is allocated but never deallocated.
    Test #9: Tests the performance by repeatedly allocating and freeing memory in a loop, evaluating the speed of the memory allocation and deallocation process.

    Avg times for each test:
    Test #1 - Insufficient Memory:  0.00002 seconds
    Test #2 - Simple Allocation and Free:  0.00000 seconds
    Test #3 - Double Free:  0.00001 seconds
    Test #4 - Fragmentation:  0.00000 seconds
    Test #5 - Multiple Allocations:  0.00001 seconds
    Test #6 - Coalesce:  0.00000 seconds
    Test #7 - Large Allocation:  0.00001 seconds
    Test #8 - Memory Leak:  0.00000 seconds
    Test #9 - Performance:  0.00058 seconds
