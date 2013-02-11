#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static void out_of_memory() {
  printf("Out of memory.\n");
  exit(EXIT_FAILURE);
}

/* return number of elements in queue */
int length(QNode* queue){
    int sum = 0;
    QNode* temp = queue;
    if (queue == NULL){
        printf("Queue is empty.\n");
        return 0;
    }
    do{
        sum++;
        temp = temp->link;
    } while(temp != queue);
    
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
        newnode->link = newnode;
    } else {
        newnode->link = (*queue)->link;
        (*queue)->link = newnode;
    }
    *queue = newnode;
}

/* remove and return front element */
Data dequeue(QNode** queue){
    QNode* temp;
    Data tempdata;
    if(*queue == NULL){
        printf("Queue is empty.\n");
        return NULL;
    }
    if(*queue == (*queue)->link){
        tempdata = (*queue)->content;
        free(*queue);
        *queue = NULL; 
    } else {
        temp = (*queue)->link;
        (*queue)->link = temp->link; 
        tempdata = temp->content;
        free(temp);
    }
    //free((temp->content));
    
    return tempdata;
}

/* sum values of all data in queue */
int sum(QNode* queue, int (*val)(Data)){
    int sum = 0;
    QNode* temp = queue;
    if (queue == NULL){
        printf("Queue is empty.\n");
        return 0;
    }
    
    do{
        sum = sum + (*val)(temp->content);
        temp = temp->link;
    } while(temp != queue);
    
    return sum;
}

/*
static int const_one (Data d){
    return 1;
} 
*/
