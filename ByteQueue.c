#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "ByteQueue.h"


ByteQueue Byte_Queue();
ByteQueue_node* malloc_ByteQueue_node(uint8_t);
void ByteQueue_append_left(ByteQueue*, uint8_t);
void ByteQueue_append_right(ByteQueue*, uint8_t);
uint8_t ByteQueue_pop_left(ByteQueue*);
uint8_t ByteQueue_pop_right(ByteQueue*);
uint8_t ByteQueue_peek_left(ByteQueue*);
uint8_t ByteQueue_peek_right(ByteQueue*);
void ByteQueue_free(ByteQueue*);
void ByteQueue_print(ByteQueue*);


ByteQueue Byte_Queue() {
    ByteQueue queue;
    queue.right = NULL;
    queue.left = NULL;
    queue.size = 0;
    queue.append_left = ByteQueue_append_left;
    queue.append_right = ByteQueue_append_right;
    queue.pop_left = ByteQueue_pop_left;
    queue.pop_right = ByteQueue_pop_right;
    queue.peek_left = ByteQueue_peek_left;
    queue.peek_right = ByteQueue_peek_right;
    queue.free = ByteQueue_free;
    queue.print = ByteQueue_print;
    return queue;
}

ByteQueue_node* malloc_ByteQueue_node(uint8_t value) {
    
    ByteQueue_node* node = (ByteQueue_node*)malloc(sizeof(ByteQueue_node));
    node -> value = value;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}


void ByteQueue_append_right(ByteQueue* queue, uint8_t value) {

    ByteQueue_node* node = malloc_ByteQueue_node(value);

    if (queue -> size == 0) {
        queue -> right = node;
        queue -> left = node;
    } else {
        node -> left = queue -> right;
        queue -> right -> right = node;
        queue -> right = node;
    }

    queue -> size += 1;
}

void ByteQueue_append_left(ByteQueue* queue, uint8_t value) {

    ByteQueue_node* node = malloc_ByteQueue_node(value);

    if (queue -> size == 0) {
        queue -> right = node;
        queue -> left = node;
    } else {
        node -> right = queue -> left;
        queue -> left -> left = node;
        queue -> left = node;
    }

    queue -> size += 1;
}

uint8_t ByteQueue_pop_right(ByteQueue* queue) {
    
    if (queue -> size <= 0) {
        return 0;
    }

    ByteQueue_node* del = queue -> right;
    uint8_t value = queue -> right -> value;

    if (queue -> size == 1) {
        queue -> right = NULL;
        queue -> left = NULL;
    } else {
        queue -> right = queue -> right -> left;
        queue -> right -> right = NULL; 
    }
    
    free(del);
    queue -> size -= 1;
    return value;
}

uint8_t ByteQueue_pop_left(ByteQueue* queue) {

    if (queue -> size <= 0) {
        return 0;
    }

    ByteQueue_node* del = queue -> left;
    uint8_t value = queue -> left -> value;

    if (queue -> size == 1) {
        queue -> right = NULL;
        queue -> left = NULL;
    } else {
        queue -> left = queue -> left -> right;
        queue -> left -> left = NULL;        
    }

    free(del);
    queue -> size -= 1;
    return value;
}

uint8_t ByteQueue_peek_right(ByteQueue* queue) {
    if (queue -> size <= 0) {
        return 0;
    }
    return queue -> right -> value;
}

uint8_t ByteQueue_peek_left(ByteQueue* queue) {
    if (queue -> size <= 0) {
        return 0;
    }
    return queue -> left -> value;
}

void ByteQueue_free(ByteQueue* queue) {
    while (queue -> left != NULL) {
        ByteQueue_pop_right(queue);
    }
}

void ByteQueue_print(ByteQueue* queue) {
    uint64_t size = queue -> size;
    ByteQueue_node* node_ptr = queue -> left; 
    printf("left <=> ");
    for (uint64_t i = 0; i < size; i++) {
        printf("%02x <=> ", node_ptr -> value);
        node_ptr = node_ptr -> right;
    }
    printf("right\n");
}