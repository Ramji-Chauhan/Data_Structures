#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node*next;
}nodetype;

nodetype* deleteMiddleElement(nodetype*);
void display(nodetype*);

int main(){
    char ch;
    nodetype* head=NULL;
    do{
        //creating the linked list
        nodetype*p;
        p=(nodetype*)malloc(sizeof(nodetype*));
        if(p==NULL){
            printf("Not Enough Memory\n");
        }
        else{
            int val;
            printf("Enter the value to push in linked list\n");
            scanf("%d",&val);
            p->info=val;
            p->next=head;
            head=p;
        }
        printf("Do you want to continue to push\n");
        scanf(" %c",&ch);
    }
    while(ch=='y');
    head=deleteMiddleElement(head);
    display(head);
    return 0;
}
//Function to find middle and deleting that middle
nodetype* deleteMiddleElement(nodetype*hd){
    nodetype*cur=hd;
    nodetype*pre;
    int count=0;
    if(hd==NULL){
        return NULL;
    }
    while(cur){
        count++;
        cur=cur->next;
    }
    if(count==1){
        return NULL;
    }
    cur=hd;
    for(int i=0;i<count/2;i++){
        pre=cur;
        cur=cur->next;
    }
    pre->next=cur->next;
    free(cur);
    return hd;
}
//Function to display
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