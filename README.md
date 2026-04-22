# Deque (Dynamic Block Array)

## Overview

This project implements a deque (double ended queue) using a dynamic 2D array.

Instead of using one big array, the deque uses multiple fixed size blocks that grow as needed.

## Run

make

./program



## Operations

- Add/remove from front
- Add/remove from back
- Access elements by index
- Grows automatically when needed



## Explanation

- Data is stored in blocks, which are arrays of size 64
- `blockmap` holds pointers to these blocks
- The deque expands by adding new blocks on either side
- If the blockmap fills up, it doubles in size



## Files

- deque.h - class definition
- deque.cpp - implementation
- main.cpp - tests
- Makefile - build instructions



## Testing

The program runs tests that:
- Push thousands of values to front and back
- Pop values from both ends
- Check random access using `[]`
- Empty and refill the deque multiple times
- Writes deque to file twice after different operations for comparison



## Work Division

Lane Campbell
- deque.cpp - 50%
- main.cpp
- Doxygen extras
- General comments

Blaine Smith
- deque.h
- deque.cpp - 50%
- Makefile
- .gitignore
- General comments

TBD
-Extra credit template version


