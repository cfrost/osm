#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static void out_of_memory() {
  printf("Out of memory.\n");
  exit(EXIT_FAILURE);
}

/* return number of elements in queue */
int length(QNode* queue){
    int sum = 1;
    QNode* temp = queue;
    if (queue == NULL){
        printf("JA\n");
        return 0;
    }
    
    while(temp->link != queue){
        printf("sum is %d\n",sum);
        sum++;
        temp = temp->link;
    }
    return sum;
/*
    return sum(queue,&const_one);
*/
} 

/* add element at rear end */
void enqueue(QNode** queue, Data el){
    QNode* newnode;
    if ((newnode = (QNode*)malloc(sizeof(QNode*))) == NULL){
        out_of_memory();
    }
    newnode->content = el;
    if (*queue == NULL){
        printf("NULL\n");
        newnode->link = newnode;
    } else {
        newnode->link = (*queue)->link;
        (*queue)->link = newnode;
        printf("onemore\n");
    }
    *queue = newnode;
    printf("Value = %d\n", ((*queue)));
}

/* remove and return front element */
Data dequeue(QNode** queue){
    QNode* temp;
    Data tempdata;
    temp = (*queue)->link;
    (*queue)->link = temp->link;
    tempdata = temp->content;
    free((temp->content));
    //free(temp);
    return tempdata;
}

/* sum values of all data in queue */
int sum(QNode* queue, int (*val)(Data)){
    int sum = 0;
    QNode* temp = queue;
    if (queue == NULL)
        return 0;
    do {
        sum = sum + (*val)(temp->content);
        temp = temp->link;
    }
    while(temp->link != queue);
    return sum;
}

/*
static int const_one (Data d){
    return 1;
} 
*/
