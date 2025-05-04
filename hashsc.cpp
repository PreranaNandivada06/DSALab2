#include <iostream>
class hashsc
{
    private:
        
    struct node {
        int data;
        struct node* next;
    }*head;
    struct node* arr[20]={NULL};
    public:
        hashsc(){
            head=NULL;
        }
        
        void insert(int value){
            printf("ch1");
            int rval;
            rval=value%20;
            if (arr[rval]==NULL){
                struct node* newnode=(struct node*)malloc(sizeof(struct node));
                newnode->data=value;
                newnode->next=head;
                head= newnode;
                arr[rval]=head;
            }
            else{
                struct node* newnode=(struct node*)malloc(sizeof(struct node));
                newnode->data=value;
                newnode->next=arr[rval];
                head= newnode;
                arr[rval]=head;
            }
        }
        void display(){
            for (int i=0;i<20;i++){
                {
                    if (arr[i]!=NULL)
                        {struct node* temp;
                        temp=arr[i];
                        printf("\n%d\n ",i);
                        while(temp!=NULL){
                            if ((temp->data-i)%20!=0){
                                break;
                            }
                            printf("%d->",temp->data);
                            temp=temp->next;
                        }
                        //printf("%d->",temp->data);
                        printf("NULL\n");
                    }
                }
            }
        }
        struct node* search(int key){
            int rval;
            rval=key%20;
            struct node* temp=arr[rval];
                        while(temp!=NULL){
                            if (key==temp->data){
                                printf("Found\n");
                                return arr[rval];
                            }
                            temp=temp->next;
                        }
                        printf("Not found\n");
                        return NULL;
        }
        int delet(int key){
            struct node* tempo=search(key);
            if (tempo==NULL){
                printf("value not present\n");
                return -1;
            }
            else{
                struct node* temp=tempo;
                while(temp->next!=NULL){
                    if (key==temp->next->data){
                        int stor=temp->next->data;
                        struct node *str;
                        str= temp->next->next;
                        free(temp->next);
                        temp->next=str;
                        return stor;
                        
                    }
                    temp=temp->next;
                }
                
            }
            struct node* tempi=tempo;
                if (key==tempi->data){
                    int s=tempi->data;
                    struct node *str;
                    str= tempi->next;
                    free(tempi);
                    tempo=str;

                    //insert(ss);
                    return s;
                }
            return -1;
        }
         
};
int main(){
    hashsc hl;
    while(1){
        int ch;
        printf("enter 1. insert,2.delete,3. search,4.display, 5.exit");
        scanf("%d",&ch);
        if (ch==1){
            int value;
                printf("enter value : ");
                scanf("%d",&value);
                hl.insert(value);

        }
        else if(ch==2){
            int value;
                printf("enter value to delete : ");
                scanf("%d",&value);
                int x;
                x=hl.delet(value);
                printf("returned value %d", x);
        }
        else if(ch==3){
            int value;
                printf("enter value to search : ");
                scanf("%d",&value);
                hl.search(value);
        }
        else if(ch==4){
            hl.display();
        }
        else if(ch==5){
            printf("the end");
            break;
        }
    
    }
}