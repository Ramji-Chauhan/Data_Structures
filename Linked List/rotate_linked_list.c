#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* next;
}nodetype;

nodetype* rotate(nodetype*,int);
void display(nodetype*);

int main(){
    nodetype*head=NULL;
    char ch;
    do{
        //creating linked list
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
        printf("Do you want to continue to push in linked list\n");
        scanf(" %c",&ch);
    }
    while(ch=='y');
    int pos;
    printf("Enter the position from where you want to rotate linked list\n");
    scanf("%d",&pos);
    head=rotate(head,pos);
    printf("Linked list after roation\n");
    display(head);

    //releasing memory
    while(head!=NULL){
        nodetype*temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}

//Function to rotate linked list
nodetype* rotate(nodetype*hd,int k){
    nodetype*last;
    nodetype*temp=hd;
    int counter=1;
    while(temp->next!=NULL){
        if(counter==k){
            last=temp;
        }
        counter++;
        temp=temp->next;
    }
    if(k<counter){
        temp->next=hd;
        hd=last->next;
        last->next=NULL;
        return hd;
    }
    else{
        return hd;
    }
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