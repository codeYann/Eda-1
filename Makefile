CC = gcc 
SOURCE_DIR = src
SOURCE_C = $(wildcard $(SOURCE_DIR)/lib/*.c)

Heap:
	$(CC) $(SOURCE_DIR)/tests/Heap_test.c  $(SOURCE_C) -o $(SOURCE_DIR)/tests/heap
	./src/tests/heap
	rm $(SOURCE_DIR)/tests/heap

Insertion:
	$(CC) $(SOURCE_DIR)/tests/Insertion_test.c  $(SOURCE_C) -o $(SOURCE_DIR)/tests/insertion
	./src/tests/insertion
	rm $(SOURCE_DIR)/tests/insertion

Clean: 
	rm $(SOURCE_DIR)/tests/heap
	rm $(SOURCE_DIR)/tests/insertion


