CC = gcc 
SOURCE_DIR = src
SOURCE_C = $(wildcard $(SOURCE_DIR)/lib/*.c)

Heap:
	$(CC) $(SOURCE_DIR)/tests/Heap_test.c  $(SOURCE_C) -o $(SOURCE_DIR)/tests/heap -lm
	./src/tests/heap
	rm $(SOURCE_DIR)/tests/heap

Insertion:
	$(CC) $(SOURCE_DIR)/tests/Insertion_test.c  $(SOURCE_C) -o $(SOURCE_DIR)/tests/insertion -lm
	./src/tests/insertion
	rm $(SOURCE_DIR)/tests/insertion

HeapSort:
	$(CC) $(SOURCE_DIR)/tests/HeapSort_test.c  $(SOURCE_C) -o $(SOURCE_DIR)/tests/heapSort -lm
	./src/tests/heapSort
	rm $(SOURCE_DIR)/tests/heapSort

Sorting:
	$(CC) $(SOURCE_DIR)/tests/Sorting/Sorting.c  $(SOURCE_C) -o $(SOURCE_DIR)/tests/Sorting/Sorting -lm
	./src/tests/Sorting/Sorting
	rm $(SOURCE_DIR)/tests/Sorting/Sorting


HashTable:
	$(CC) $(SOURCE_DIR)/tests/Hashtable_test.c $(SOURCE_C) -o $(SOURCE_DIR)/tests/hash -lm
	./src/tests/hash
	rm $(SOURCE_DIR)/tests/hash

Hashing:
	$(CC) $(SOURCE_DIR)/tests/Hashing/Hashing.c $(SOURCE_C) -o $(SOURCE_DIR)/tests/Hashing/hash -lm
	./src/tests/Hashing/hash
	rm $(SOURCE_DIR)/tests/Hashing/hash
