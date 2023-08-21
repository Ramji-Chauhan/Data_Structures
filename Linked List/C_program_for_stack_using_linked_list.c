#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* next;
} nodetype;

nodetype* push(nodetype*top);
nodetype* pop(nodetype*top);
void display(nodetype*top);

int main(){
    nodetype*top=NULL;
    int option;
    char ch;
    do{
        printf("Enter you choice: 1.Push 2.Pop 3.Display\n");
        scanf("%d",&option);
        switch(option){
            case 1:
            top=push(top);
            break;
            case 2:
            top=pop(top);
            break;
            case 3:
            display(top);
            break;
            default:
            printf("Wrong choice\n");
        }
        printf("Do you want to continue:\n");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }
    while(ch=='y');
    return 0;
}

//Function to create linked list
nodetype* push(nodetype*tp){
    nodetype*p;
    p=(nodetype*)malloc(sizeof(nodetype*));
    if(p==NULL){
        printf("Not Enough Memoery\n");
    }
    else{
        int val;
        printf("Enter value to push:\n");
        scanf("%d",&val);
        p->info=val;
        p->next=tp;
        tp=p;
    }
    return tp;
}

//Function to pop from linked list
nodetype* pop(nodetype*tp){
    nodetype*temp=tp;
    if(tp==NULL){
        printf("Stack is Empty\n");
    }
    else{
        tp=tp->next;
        free(temp);
        printf("Successfully Poped\n");
    }
    return tp;
}

//Function to display
void display(nodetype*tp){
    if(tp==NULL){
        printf("Stack is Empty\n");
    }
    else{
        while(tp!=NULL){
            printf("%d ",tp->info);
            tp=tp->next;
        }
    }
}

