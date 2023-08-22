#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}nodetype;

int getMiddle(nodetype*);

int main(){
    char ch;
    nodetype *head=NULL;
    do{
        //creating linked list
        nodetype*p;
        p=(nodetype*)malloc(sizeof(nodetype*));
        if(p==NULL){
            printf("Not nough Memory\n");
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
    int ans;
    ans=getMiddle(head);
    printf("%d",ans);
//releasing memory 
     while (head != NULL) {
        nodetype *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
//Function to find middle of a linked list 
int getMiddle(nodetype*hd){
    nodetype*z=hd;
    int counter=0;
    while(z){
        z=z->next;
        counter++;
    }
    z=hd;
    for(int i=0;i<counter/2;i++){
        z=z->next;
    }
    int ans;
    ans=z->info;
    return ans;
}

