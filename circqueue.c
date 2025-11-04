#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int rear=-1;
int front=-1;

void enqueue();
void dequeue();
void display();

int main(){
    int ch;
    while (1){
        printf("Enter your choice: 1. Enqueue 2. Dequeue 3. Display 4. Peek 5. Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 5: exit(0); break;
            default: printf("invalid choice\n");
        }
    }
}

void enqueue(){
    int x;
    printf("Enter element: \n");
    scanf("%d",&x);
    if ((front==0 && rear==MAX-1) || (front==rear+1))
        printf("Overflow\n");
    else if (front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear=(rear+1)%MAX;
        queue[rear]=x;
    }
}

void dequeue(){
    if (front==-1 && rear==-1){
        printf("Empty\n");
    }
    else if(front==rear){
        printf("Deleted element: %d\n", queue[front]);
        front=rear=-1;
    }
    else {
        printf("Deleted element: %d\n",queue[front]);
        front=(front+1)%MAX;
    }
}

void display(){
    int i;
    int j;
    if (front==-1 && rear==-1){
        printf("Empty\n");
    }
    else if(front<=rear){
        for(i=front;i<=rear;i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
    else{
        for(i=front;i<MAX;i++){
            printf("%d ", queue[i]);
        }
        for(j=0;j<=rear;j++){
            printf("%d ", queue[j]);
        }
        printf("\n");
    }
}

