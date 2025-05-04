//to implement doubley linked list using classes
#include <iostream>
class dolli{
    private:
        struct node{
            struct node* prev;
            int data;
            struct node* next;}*head,*tail;
        int c;
    public:
        dolli(){head=NULL;c=0;tail=NULL;}
        void inbeg(int value) {
            struct node* newnode=( node*) malloc(sizeof( node));
            
            if (head==NULL) {
                newnode->data=value;
                newnode->prev=NULL;
                newnode->next=NULL;
                head=newnode;
                tail=newnode;
                return;
            }
            newnode->data=value;
            head->prev=newnode;
            newnode->next=head;
            newnode->prev=NULL;
            
            head=newnode;

        }
        void disp() {
            struct node* temp=head;
            while (temp->next!=NULL){
                printf("%d->",temp->data);
                temp=temp->next;
            }
            
            
            printf("%d",temp->data);
            printf("\n");
            
            while (temp->prev!=NULL) {
                printf("%d->",temp->data);
                temp=temp->prev;
            }
            printf("%d",temp->data);
        }
        void delbeg(){
            if(head==NULL){
                printf("list empty, add values");
                return;
            }
            
            struct node *str;
            str= head->next;
            free(head);
            head=str;
            head->prev=NULL;
            c=c-1; 
        }
        void delend() {
            if (head==NULL) {
                printf("list is empty, cant delete values");
                return;
            }
            else if (head->next==NULL) {
                delbeg();
            }
            else {
                //struct node* temp=head;

                //while (temp->next->next!=NULL) {
                    //temp=temp->next;
                //}
                tail->prev->next=NULL;
                free(tail);
                
            }
            c=c-1;
        }
        void inend(int value) {
            if(head==NULL) {
                    inbeg(value);
                    return;
                }
                struct node* newnode=(struct node*)malloc(sizeof(struct node));
                //struct node*temp=head;
                newnode->data=value;
                newnode->next=NULL;
                //while (temp->next!=NULL) {
                //  temp=temp->next;
                //}
                tail->next=newnode;
                newnode->prev=tail;
                tail=newnode;
                c=c+1;
            }
        void search() {
            printf("enter key to search");
            int key;
            scanf("%d",&key);
            struct node* temp=head;
            while(temp!=NULL) {
                if (temp->data==key) {
                    printf("Found\n");
                    return;
                }
                temp=temp->next;
            }   
            printf("not found\n");
            
        }
        void inpos(int value) {
            if (head==NULL) {
                printf("list is empty, position not necessary");
                inbeg(value);
                return;
            }
            int pos;
            printf("enter position : ");
            scanf("%d", &pos);
            int co=1;
            pos=pos-1;
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            struct node*temp=head;
            struct node* stor;
            while (temp->next!=NULL) {
                
                if (co==pos) {
                    
                    newnode->data=value;
                    newnode->next=temp->next;
                    stor=temp->next;
                    temp->next=newnode;
                    newnode->prev=temp;
                    stor->prev=newnode;
                    c=c+1;
                    
                    return;
                }
                else {
                    
                    temp=temp->next;
                    co=co+1;
                }
            }
            inend(value);
            return;

        }
        void delpos() {
            if (head==NULL) {
                printf("list is empty, cannot delete values");
                return;
            }
            else if (head->next==NULL) {
                printf("only one digit, no need for position");
                delbeg();
            }
            int pos;
            printf("enter position : ");
            scanf("%d", &pos);
            int co=1;
            pos=pos-1;
            struct node*temp=head;
            
            while (temp->next!=NULL) {
                
                if (co==pos) {
                   
                    struct node *str;
                    str= temp->next->next;
                    free(temp->next);
                    temp->next=str;
                    str->prev=temp;
                    c=c-1;
                    return;
                }
                else {
                    
                    temp=temp->next;
                    co=co+1;
                }
            }
            delend();
            return;
        }
};
int main(){
    dolli dll;
    int choice=0;
    while(choice!=9){
        printf("\n1.inbeg, 2.inend, 3.inpos,4.delbeg,5.delend,6.delpos,7.search,8.display, 9.exit");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                int value;
                printf("enter value : ");
                scanf("%d",&value);
                dll.inbeg(value);
                break;
            case 2:
                int valu;
                printf("enter value : ");
                scanf("%d",&valu);
                dll.inend(valu);
                break;
            case 3:
                int val;
                printf("enter value : ");
                scanf("%d",&val);
                dll.inpos(val);
                break;
            case 4:
                dll.delbeg();
                break;
            case 5:
                dll.delend();
                break;
            case 6:
                dll.delpos();
                break;
            case 7:
                dll.search();
                break;
            case 8:
                dll.disp();
                break;
            case 9:
                printf("The end");
                break;
        }
    }

    return 0;
}