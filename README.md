# myLittleMalloc

Yash Shah, NetID: yss28
Vedant, NetID: vv277
CS214 Assignment 1 "my little malloc()"

Design:
mymalloc.c
Create an array of size 4096 called memory in order to hold values of type char
'0' represents an empty index in our memory array

    initialize()
    Initializes the array to be full of the '0' character

    mymalloc()
    Finds the first available spot in memory and allocates it to an address in memory. the remaining space needed is also removed from the following spaces in the array.
    If information is too large, mymalloc will return with an error message.
    If there is no size, mymalloc will return NULL

    myfree()
    Finds the spot in our memory array converts the following indexes back to '0' therefore freeing all the memory taken up previously
    Returns with an error message if pointer is empty, if the value was returned before or the pointer was called without malloc prior.

    Test Plan:
    Our test plan includes 5 tests tht repeat 50 times each

    Test 1: Allocates a spot in the memory array, right after frees it. repeats 120 times.
    Test 2: Allocates 120 spots in memory. then frees the 120 spots.
    Test 3: Randomly allocates or frees until malloc has been called 120 times. then frees the remainder if any
    Test 4: Gets a random value and creates a char array of that value, afterwards populates the array but frees the array from the back to front
    Test 5: allocates and deallocates 20 piece bits 1000 times.

    Avg times for each test:
    Test 1:  seconds
    Test 2:  seconds
    Test 3:  seconds
    Test 4:  seconds
    Test 5:  seconds
