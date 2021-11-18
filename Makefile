CC = gcc 
SOURCE_DIR = src
SOURCE_C = $(wildcard $(SOURCE_DIR)/lib/*.c)

Heap:
	$(CC) $(SOURCE_DIR)/tests/Heap_test.c  $(SOURCE_C) -o $(SOURCE_DIR)/tests/heap
	./src/tests/heap

Clean: 
	rm $(SOURCE_DIR)/tests/heap


