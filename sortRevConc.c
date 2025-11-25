#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head1=NULL,*head2=NULL,*head=NULL;

struct Node* create(int n){
    struct Node *head=NULL,*newNode, *temp=NULL;
    int data,i;

    if (n<=0){
        printf("No of nodes should be greater than zero");
        return NULL;
    }

    for (i=1;i<=n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        if (newNode==NULL){
            printf("failed to allocate memory\n");
            return NULL;
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
    return head;
}

void display(struct Node *head){
    struct Node *temp=head;

    if (head == NULL){
        printf("list empty\n");
        return;
    }

    printf("list: \n");
    while (temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void sort(struct Node *head){
    struct Node *i, *j;
    int tempData;

    if (head==NULL){
        printf("Empty");
        return;
    }

    for (i=head;i->next!=NULL;i=i->next){
        for (j=i->next;j!=NULL;j=j->next){
            if (i->data>j->data){
                tempData=i->data;
                i->data=j->data;
                j->data=tempData;
            }
        }
    }
    printf("sorted\n");
}

struct Node *reverse(struct Node *head){
    struct Node *prev=NULL, *curr=head, *next=NULL;

    while (curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    printf("Reversed\n");
    return prev;
}

struct Node *concatenate(struct Node *head1,struct Node *head2){
    struct Node *temp;

    if (head1==NULL) return head2;
    if (head2==NULL) return head1;

    temp=head1;
    while (temp->next!=NULL)
        temp=temp->next;
    temp->next=head2;

    printf("concatenated\n");
    return head1;
}

int main(){
    int choice,n1,n2;

    while(1){
        printf("Enterchoice 1.create list1\n 2. create list2\n 3. Display list1\n 4. Display list2\n 5. sort list1\n 6. sort list 2\n 7. concatenate two lists\n 8. display concatenated list\n 9. exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter number of nodes for first list: ");
                scanf("%d",&n1);
                head1=create(n1);
                break;

            case 2:
                printf("Enter number of nodes for second list: ");
                scanf("%d",&n2);
                head2=create(n2);
                break;

            case 3:
                printf("First Linked List: ");
                display(head1);
                break;

            case 4:
                printf("Second Linked List: ");
                display(head2);
                break;

            case 5:
                sort(head1);
                break;

            case 6:
                sort(head2);
                break;

            case 7:
                head1=concatenate(head1,head2);
                head2=NULL;
                break;

            case 8:
                printf("Concatenated Linked List: ");
                display(head1);
                break;

            case 9:
                printf("Exiting program\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again\n");
        }
    }
    return 0;
}
