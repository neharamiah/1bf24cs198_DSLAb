#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head=NULL;
struct Node *tail=NULL;

void create(int n){
    int i, data;
    struct Node *newNode;

    for (i=1;i<=n;i++){
        printf("Enter data: ");
        scanf("%d",&data);

        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->prev=newNode->next=NULL;

        if (head==NULL){
            head=tail=newNode;

        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;

        }
    }
}

void insertLeft(int target, int data){
    struct Node *newNode, *temp=head;

    while (temp!=NULL && temp->data!=target)
        temp=temp->next;

    if (temp==NULL) {
        printf("Not found");
        return;
    }

    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;

    if (temp->prev==NULL) {
        newNode->prev=NULL;
        newNode->next=temp;
        temp->prev=newNode;
        head=newNode;
        return;
    }

    newNode->next=temp;
    newNode->prev=temp->prev;
    temp->prev->next=newNode;
    temp->prev=newNode;
}

void deleteValue(int value) {
    struct Node *temp=head;


    if (head==NULL) {
        printf("List empty");
        return;
    }

    while (temp!=NULL && temp->data!=value)
        temp=temp->next;

    if (temp==NULL) {
        printf("Value not found");
        return;
    }

    if (temp==head) {
        deleteAtFront();
        return;
    }


    else if (temp==tail) {
        deleteAtEnd();
        return;
    }

    else {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }

    printf("deleted");
}


void deleteAtEnd() {
    struct Node *temp;

    if (tail==NULL) {
        printf("List empty");
        return;
    }

    temp=tail;
    tail=tail->prev;

    if (tail!=NULL)
        tail->next=NULL;

    else
        head=NULL;

    free(temp);
}

void deleteAtFront() {
    struct Node *temp;

    if (head==NULL) {
        printf("List empty");
        return;
    }

    temp=head;
    head=head->next;

    if (head!=NULL)
        head->prev=NULL;

    else
        tail=NULL;

    free(temp);
}


void deleteAtPosition(int pos) {
    struct Node *temp=head;
    int i;

    if (head==NULL) {
        printf("List empty!");
        return;
    }

    if (pos==1) {
        deleteAtFront();
        return;
    }


    for (i=1;i<pos && temp!=NULL;i++)
        temp=temp->next;

    if (temp==NULL) {
        printf("invalid pos");
        return;
    }

    if (temp==tail) {
        deleteAtEnd();
        return;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);

}

void display(){
    struct Node *temp=head;
    while (temp!=NULL){
        printf("%d <->", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int ch,n,data,pos,target;

    while(1){
        printf("\nChoose your option:\n 1. create\n 2. insert at left\n 3. deletevalue\n 4. deleteposition\n 5. display\n 6. exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter no of nodes:  ");
            scanf("%d", &n);
            create(n);
            break;

        case 2:
            printf("Enter data:  \n");
            scanf("%d", &data);
            printf("Enter value before which to be added:  ");
            scanf("%d", &target);
            insertLeft(target,data);
            break;

        case 3:
            printf("Enter data:  ");
            scanf("%d", &data);
            deleteValue(data);
            break;

        case 4:
            printf("Enter pos:  ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice");
        }
    }


    return 0;
}

