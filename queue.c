#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value){
    if (rear == SIZE -1){
        printf("%d stack overflow\n",value);
    }
    else{
        if(front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("%d enqued to queue\n",value);
    }
    
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("queue underflow\n");
    }
    else{
        printf("dequeue from queue\n",queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("queue is empty\n");
    }else{
        printf("queue elements\n");
        for(int i = front; i <= rear; i++){
            printf("%d ",queue[i]);
        }
    }
}

int main(){
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);

    dequeue();
    display();
}