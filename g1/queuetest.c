#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static void out_of_memory() {
  printf("Out of memory.\n");
  exit(EXIT_FAILURE);
}

static int const_one(){
    return 1;
}

static int mult_one(Data d){
    return *(int*)d * 2;
}


int main(){
    Data a_data,b_data,c_data;
    QNode** queue;
    if((queue = (QNode**)malloc(sizeof(QNode**))) == NULL){
        out_of_memory();
    }
    // Data Initializing
    int a = 1;
    int b = 2;
    int c = 3;
    a_data = &a;
    b_data = &b;
    c_data = &c;
    
    // Add elements to queue and print length
    enqueue(queue,a_data);
    printf("Total length is = %d\n",length(*queue));
    enqueue(queue,b_data);
    printf("Total length is = %d\n",length(*queue));
    enqueue(queue,c_data);
    printf("Total length is = %d\n",length(*queue));
    // Apply sum function
    printf("Total sum of function const_one is = %d\n",sum(*queue,&const_one));
    printf("Total sum of function mult_one is = %d\n",sum(*queue,&mult_one));
    // Remove element from queue and print lenth
    dequeue(queue);
    printf("Total length is = %d\n",length(*queue));
    dequeue(queue);
    printf("Total length is = %d\n",length(*queue));
    dequeue(queue);
    printf("Total length is = %d\n",length(*queue));
    dequeue(queue);
    printf("Total length is = %d\n",length(*queue));
    
    free(queue);
}
