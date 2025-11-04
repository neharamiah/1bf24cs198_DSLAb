#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int queue[MAX];
int rear=-1;
int front=-1;

void enqueue();
void dequeue();
void display();
void peek();

int main(){
    int ch;
    while (1){
        printf("Enter your choice: \n1. Enqueue \n2. Dequeue \n3. Display \n4. Peek \n5. Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: exit(0);
            default: printf("invalid choice\n\n\n");
        }
    }
}

void enqueue(){
    int x;
    printf("Enter element: \n");
    scanf("%d",&x);
    if (rear==MAX-1)
        printf("Overflow\n\n\n");
    else if (front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else
        queue[++rear]=x;
}

void dequeue(){

    if (front==-1 && rear==-1){
        printf("Empty\n\n\n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else    printf(" deleted item is %d\n\n\n",queue[front++]);
}

void display(){
    int i;
    if (front==-1 && rear==-1){
        printf("Empty\n");
    }
    else{
        printf("Queue contains: ");
        for(i=front;i<=rear;i++){

            printf("%d  ", queue[i]);

        }
        printf("\n\n\n");
    }
}

void peek(){
    if (front==-1 && rear==-1){
        printf("Empty\n\n\n");
    }
    else
        printf("%d\n\n\n", queue[front]);

}
