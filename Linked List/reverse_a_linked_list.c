#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node*next;
}nodetype;

nodetype* reverse(nodetype*);
void display(nodetype*);

int main(){
    nodetype*head=NULL;
    char ch;
    //creating linked list
    do{
        nodetype*p;
        p=(nodetype*)malloc(sizeof(nodetype*));
        if(p==NULL){
            printf("Not Enough Memory\n");
        }
        else{
            int val;
            printf("Enter value to push in linked list\n");
            scanf("%d",&val);
            p->info=val;
            p->next=head;
            head=p;
        }
        printf("Do you want to push\n");
        scanf(" %c",&ch);
    }
    while(ch=='y');
    head=reverse(head);
    printf("Reversed Linked List id\n");
    display(head);

    //releasing memory
    while(head!=NULL){
        nodetype*temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}

//Function to reverse the linked list
nodetype* reverse(nodetype*hd){
    nodetype*temp;
    nodetype*pre=NULL;
    nodetype*cur=hd;
    while(cur!=NULL){
        temp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=temp;
    }
    return pre;
}

//Funtion to display linked list
void display(nodetype*hd){
    if(hd==NULL){
        printf("Stack is Empty\n");
    }
    else{
        while(hd!=NULL){
            printf("%d ",hd->info);
            hd=hd->next;
        }
    }
}