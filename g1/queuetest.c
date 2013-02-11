#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static void out_of_memory() {
  printf("Out of memory.\n");
  exit(EXIT_FAILURE);
}

int main(){
    Data a_data,b_data,c_data;
    QNode** queue;
    if((queue = (QNode**)malloc(sizeof(QNode**))) == NULL){
        out_of_memory();
    }
    int a = 1;
    int b = 2;
    int c = 3;
    a_data = &a;
    b_data = &b;
    c_data = &c;
    enqueue(queue,a_data);
    printf("Total length is = %d\n",length(*queue));
    enqueue(queue,b_data);
    printf("Total length is = %d\n",length(*queue));
    enqueue(queue,c_data);
    printf("Total length is = %d\n",length(*queue));
    dequeue(queue);
    printf("Total length is = %d\n",length(*queue));
    dequeue(queue);
    printf("Total length is = %d\n",length(*queue));
    dequeue(queue);
    printf("Total length is = %d\n",length(*queue));
}
