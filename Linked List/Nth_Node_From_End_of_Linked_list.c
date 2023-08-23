#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node*next;
}nodetype;

int NthNodefromENd(nodetype*,int);

int main(){
    nodetype* head=NULL;
    char ch;
    do{
        //creating linked list
        nodetype*p;
        p=(nodetype*)malloc(sizeof(nodetype*));
        if(p==NULL){
            printf("Not Enough Space\n");
        }
        else{
            int val;
            printf("Enter the value to push in linked list\n");
            scanf("%d",&val);
            p->info=val;
            p->next=head;
            head=p;
        }
        printf("Do you want to continue\n");
        scanf(" %c",&ch);
    }
    while(ch=='y');
    int n;
    printf("Enter the position from last\n");
    scanf("%d",&n);
    int ans=NthNodefromENd(head,n);
    printf("%d",ans);
    return 0;
}
//function to delete nth node from end of linked list
int NthNodefromENd(nodetype*hd,int k){
    nodetype*first=hd;
    nodetype*second=hd;
    for(int i=1;i<k;i++){
        first=first->next;
        if(first==NULL){
            return -1;
        }
    }
    while(first->next){
        first=first->next;
        second=second->next;
    }
    return second->info;

}
