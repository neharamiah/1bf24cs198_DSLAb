#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top=-1;

void push(char ch);
char pop();
char peek();
void inToPost(char infix[], char postfix[]);
int precedence(char o);
int associativity(char o);

//main
int main(){
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);
    inToPost(infix, postfix);
    printf("Converted postfix expression : %s", postfix);
    return 0;
}

//push
void push(char ch){
    if (top==MAX-1){
        printf("stack overflow");
        return;
    }
    stack[++top]=ch;
}

//pop
char pop(){
    if (top==-1){
        printf("stack underflow");
        return 0;
    }
    return stack[top--];
}

//infix to postfix
void inToPost(char infix[], char postfix[]){
    int i,j=0;
    char ch;
    for(i=0;infix[i]!='\0';i++){
        ch=infix[i];

        if (isalnum(ch))
            postfix[j++]=ch;

        else if (ch=='(')
            push(ch);

        else if(ch==')'){
            while (peek()!='('){
                postfix[j++]=pop();
                pop();
            }
        }

        else{
            while (top!=-1 && ((precedence(peek())>precedence(ch)) || (precedence(peek())==precedence(ch) && associativity(ch)==0))){
                postfix[j++]=pop();
            }
            push(ch);
        }
    }

        while (top!=-1){
            postfix[j++]=pop();

        }

        postfix[j]='\0';
    }




//precedence
int precedence(char o){
    switch(o){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '(':
        return 0;


    }
    return -1;

}

//associativity
int associativity(char o){
    if (o=='^'){
        return 1;
    }
    return 0;

}

//peek
char peek(){
    if (top==-1){
        printf("stack underflow");
        return 0;
    }
    return stack[top];
}
