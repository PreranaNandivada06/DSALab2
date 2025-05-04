#include <iostream>
class graph
{
    private:
        struct node {
            int data;
            struct node* next;
        }*head1;
        struct graphNd{
            int dat;
            struct node* nbr;
            struct graphNd* next;
        }*head;
        int c;
    public:
        graph(){head=NULL;c=0;head1=NULL;}
        void insertgNode(int value){
            struct graphNd* newnode=(struct graphNd*)malloc(sizeof(struct graphNd));
            newnode->dat=value;
            newnode->nbr=NULL;
            newnode->next=head;
            head= newnode;
            c=c+1;
        }
        struct node* searchNd(int nod){
                
                struct graphNd* temp;
                temp=head;
                while(temp!=NULL){
                if (temp->dat==nod){
                    printf("node found");
                    return temp->nbr;
                    break;
                }
                temp=temp->next;

            }
            return NULL;
        }

       void searchpath(int nod, int path) {   
            struct graphNd* temp = head;
            while (temp != NULL) {
                if (temp->dat == nod) {
                    printf("node found\n");
                    struct node* temp1 = temp->nbr;
                    while (temp1 != NULL) {
                        if (temp1->data == path) {
                            printf("path found\n");
                            return;  
                        }
                        temp1 = temp1->next;
                    }
                    printf("path not found\n");  
                    return;
                }
                temp = temp->next;
            }
            printf("node not found\n");  
        }

        void insertpath(int nod, int value){
            struct graphNd* temp = head;
            while(temp != NULL){
                if (temp->dat == nod){
                    struct node* newnode = (struct node*)malloc(sizeof(struct node));
                    newnode->data = value;
                    newnode->next = temp->nbr;
                    temp->nbr = newnode;
                    return;
                }
                temp = temp->next;
            }
        }
        void delpat(int path) {
    struct graphNd* temp = head;
    while (temp != NULL) {
        struct node* temp1 = temp->nbr;
        
        if (temp1 != NULL && temp1->data == path) {
            // First neighbor matches
            temp->nbr = temp1->next;
            free(temp1);
            printf("path deleted\n");
            return;
        }

        while (temp1 != NULL && temp1->next != NULL) {
            if (temp1->next->data == path) {
                struct node* toDelete = temp1->next;
                temp1->next = temp1->next->next;
                free(toDelete);
                printf("path deleted\n");
                return;
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    printf("path not found\n");
}

void delpat(int nod, int path) {   
    struct graphNd* temp = head;
    while (temp != NULL) {
        if (temp->dat == nod) { 
            struct node* temp1 = temp->nbr;
            
            if (temp1 != NULL && temp1->data == path) {
                temp->nbr = temp1->next;
                free(temp1);
                return;
            }
            
            while (temp1 != NULL && temp1->next != NULL) {
                if (temp1->next->data == path) {
                    struct node* toDelete = temp1->next;
                    temp1->next = temp1->next->next;
                    free(toDelete);
                   
                    return;
                }
                temp1 = temp1->next;
            }
            printf("path not found from given node\n");
            return;
        }
        temp = temp->next;
    }
    printf("node not found\n");
}


        void delet(){
            if (head==NULL) {
                printf("nodes is` empty, cannot delete values");
                return;
            }
            else if (head->next==NULL) {
                printf("only one node, no need for position");
                
            }
            int pos;
            printf("enter node : ");
            scanf("%d", &pos);
            struct graphNd*temp=head;
            printf("Checkpoint 1\n");
            while (temp->next!=NULL) {
                printf("into the loop\n");
                if(pos==temp->dat){
                    struct graphNd *str;
                    str= head->next;
                    free(head);
                    head=str; 
                    delpat(pos);
                    return;
                }
                else if (pos==temp->next->dat) {
                    printf("if cond");
                    struct graphNd *str;
                    str= temp->next->next;
                    free(temp->next);
                    temp->next=str;
                    delpat(pos);
                    return;
                }
                else {
                    printf("else cond\n");
                    temp=temp->next;
                    
                }
            }

            c=c-1;
            return;

        
        }
        
        
        void display(){
            struct graphNd* temp;
            temp=head;
            while(temp!=NULL){
                printf("%d->",temp->dat);
                struct node* temp1;
                temp1=temp->nbr;
                while(temp1!=NULL){
                    printf("%d->",temp1->data);
                    temp1=temp1->next;
                }
                /*printf("%d->",temp1->data);*/
                printf("NULL\n");
                temp=temp->next;

            }
            /*printf("%d->",temp->dat);*/
            printf("NULL\n");
        
        }

        
    };

    int main(){
        graph hl;
        while(1){
            int ch;
            printf("enter 1. insertnd,2.insertpath,3.searchnode ,4.display,5.searchpath, 6.delete,7.deletpat, 8.exit");
            scanf("%d",&ch);
            if (ch==1){
                int value;
                    printf("enter value : ");
                    scanf("%d",&value);
                    hl.insertgNode(value);
    
            }
            if (ch==2){
                int value;
                int nod;
                    printf("enter value : ");
                    scanf("%d",&value);
                    printf("enter nod : ");
                    scanf("%d",&nod);


                    hl.insertpath(nod, value);
    
            }

            else if(ch==6){

                    hl.delet();
                    //printf("returned value %d", x);
            }
            else if(ch==3){
                int value;
                    printf("enter value to search : ");
                    scanf("%d",&value);
                    hl.searchNd(value);
            }
            else if(ch==5){
                int value;
                int val2;
                    printf("enter node to search : ");
                    scanf("%d",&value);
                    printf("enter path to search : ");
                    scanf("%d",&val2);
                    hl.searchpath(value,val2);
            }
            else if(ch==4){
                hl.display();
            }
            else if(ch==8){
                printf("the end");
                break;
            }
             else if(ch==7){
                int value;
                int nod;
                    printf("enter value : ");
                    scanf("%d",&value);
                    printf("enter nod : ");
                    scanf("%d",&nod);


                    hl.delpat(nod, value);
            }
            

        
        }
    }