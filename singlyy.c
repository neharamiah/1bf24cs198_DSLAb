#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void create(int n){
    struct Node *newNode, *temp;
    int data,i;

    if (n<=0){
        printf("No of nodes should be greater than zero");
        return;

    }

    for (i=1;i<=n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        if (newNode==NULL){
            printf("failed to allocate memory\n");
            return;
        }

        printf("Enter data\n");
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=NULL;

        if (head==NULL){
            head=newNode;
        }else {
            temp->next=newNode;
        }
        temp = newNode;

    }

    printf("created successfully\n");
}



void insertBeginning( int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->next=head;
        head=newNode;
        printf("successfully inserted at begining\n");

}

void insertEnd(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->next=NULL;

        if (head==NULL){
            head=newNode;
        }else{
            struct Node *temp=head;
            while(temp->next!=NULL) temp=temp->next;

            temp->next=newNode;
        }
        printf("successfully inserted at end\n");

}

void insert(int data, int pos){
    int i;
    struct Node *newNode,*temp=head;

    if (pos<1){
        printf("invalid pos\n"); return;
    }

    if (pos==1){
        insertBeginning(data);
        return;
    }

    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;

    for (i=1;i<pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }
    if (temp==NULL){
        printf("Position out of range\n");
        free(newNode);
    }else{
        newNode->next=temp->next;
        temp->next=newNode;
        printf("successfully inserted at posiiton\n");
    }

}

void deleteFirst(){
    struct Node *temp;

    if (head==NULL){
        printf("List is Empty\n");
        return;
    }

    temp=head;
    head=head->next;
    printf("Deleted!\n");
    free(temp);
}

void deleteLast(){
    struct Node *temp,*prev;
    if (head==NULL){
        printf("List is Empty\n");
        return;
    }
    if (head->next==NULL){
        printf("Deleted!\n");
        free(head);
        head=NULL;
        return;
    }
    temp=head;
    while(temp->next !=NULL){
        prev=temp;
        temp=temp->next;

    }
    printf("Deleted!\n");
    prev->next=NULL;
    free(temp);
}

void deleteSpecific(int value){
    struct Node *temp=head,*prev=NULL;
    if (head==NULL){
        printf("List is Empty\n");
        return;
    }
    if( head->data==value){
        head=head->next;
        printf("Deleted!\n");
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=value){
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL){
        printf("Element not found");
        return;
    }
    prev->next=temp->next;
    printf("Deleted!\n");
    free(temp);

}
void display(){
    struct Node *temp=head;
    if (head==NULL){
        printf("list empty\n");
        return;
    }

    printf("list: \n");
        while (temp!=NULL){
            printf("%d ->",temp->data);
            temp=temp->next;
        }
        printf("NULL");
}


int main(){
    int ch,n,data,pos;

    while(1){
        printf("\nChoose your option:\n 1. create\n 2. insert at beginning\n 3. insert at end\n 4. insert at any position\n 5.Delete from beginning\n 6.Delete from last\n 7. Delete specific\n 8. display\n 9. exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter no of nodes:  ");
            scanf("%d", &n);
            create(n);
            break;

        case 2:
            printf("Enter data:  ");
            scanf("%d", &data);
            insertBeginning(data);
            break;

        case 3:
            printf("Enter data:  ");
            scanf("%d", &data);
            insertEnd(data);
            break;

        case 4:
            printf("Enter data and pos:  ");
            scanf("%d %d", &data, &pos);
            insert(data,pos);
            break;

        case 5:
            deleteFirst();
            break;

        case 6:
            deleteLast();
            break;

        case 7:
            printf("Enter data to delete:  ");
            scanf("%d", &data);
            deleteSpecific(data);
            break;

        case 8:
            display();
            break;

        case 9:
            exit(0);

        default:
            printf("Invalid choice");
        }
    }


    return 0;
}
