#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

/* Allocation test function for out of memory */
static void out_of_memory() {
    printf("Out of memory.\n");
    exit(EXIT_FAILURE);
}

/* return number of elements in queue */
int length(QNode* queue) {
    int sum = 0;
    QNode* temp = queue;
    if (queue == NULL) {
        printf("Queue is empty.\n");
        return 0;
    }
    do {
        sum++;
        temp = temp->link;
    } while (temp != queue);

    return sum;
}

/* add element at rear end */
void enqueue(QNode** queue, Data el) {
    QNode* newnode;
    // Allocating new node and testing for out of memory
    if ((newnode = (QNode*) malloc(sizeof (QNode*))) == NULL) {
        out_of_memory();
    }
    newnode->content = el;
    if (*queue == NULL) {
        // queue is empty
        newnode->link = newnode;
    } else {
        // queue is not empty
        newnode->link = (*queue)->link;
        (*queue)->link = newnode;
    }
    *queue = newnode;
}

/* remove and return front element */
Data dequeue(QNode** queue) {
    QNode* temp;
    Data tempdata;
    if (*queue == NULL) {
        printf("Queue is empty.\n");
        return NULL;
    }

    temp = (*queue)->link;
    tempdata = temp->content;
    if (*queue == (*queue)->link) {
        *queue = NULL;
    } else {
        (*queue)->link = temp->link;
    }
    free(temp);
    return tempdata;
}

/* sum values of all data in queue */
int sum(QNode* queue, int (*val)(Data)) {
    int sum = 0;
    QNode* temp = queue;
    if (queue == NULL) {
        printf("Queue is empty.\n");
        return 0;
    }

    do {
        sum = sum + (*val)(temp->content);
        temp = temp->link;
    } while (temp != queue);

    return sum;
}