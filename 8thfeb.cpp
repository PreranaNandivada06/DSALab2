//implementation of singly linked list
#include <iostream>

class cll {
    private:
        struct node{
            int data;
            struct node* next;}*head,*tail;
            int c;
    public:
        cll(){
            head=NULL;c=0;tail=NULL;
        }
     void inbeg(int value) {
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=value;
            if (head==NULL) {
                newnode->next=head;
                head=newnode;
                tail=newnode;
                c=c+1;
                return;
            }
            
            newnode->next=head;
            struct node* temp;
            
            tail->next=newnode;
            head=newnode;
            return;

            
        }
        void display() {
            struct node* temp;
            temp=head;
            while(temp!=tail){
                printf("%d->",temp->data);
                temp=temp->next;
            }
            printf("%d->",temp->data);
            printf("NULL\n");
        }
        void inend(int value) {
            if(head==NULL) {
                inbeg(value);
                return;
            }
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            struct node*temp=head;
            newnode->data=value;
            newnode->next=head;
            tail->next=newnode;
            tail=newnode;
            c=c+1;
        }
        void delbeg(){
            if(head==NULL){
                printf("list empty, add values\n");
                return;
            }
            
            struct node *str;
            str= head->next;
            free(head);
            head=str;
            tail->next=head;
            c=c-1; 
        }
        void inpos(int value) {
            if (head==NULL) {
                printf("list is empty, position not necessary\n");
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
            
            while (temp!=tail) {
                
                if (co==pos) {
                    
                    newnode->data=value;
                    newnode->next=temp->next;
                    temp->next=newnode;
                    return;
                }
                else {
                    
                    temp=temp->next;
                    co=co+1;
                }
            }
            inend(value);//in case index too big.
            return;

        }
        void delend() {
            if (head==NULL) {
                printf("list is empty, cant delete values\n");
                return;
            }
            else if (head->next==NULL) {
                delbeg();
            }
            else {
                struct node* temp=head;

                while (temp->next!=tail) {
                    temp=temp->next;
                }
                free(tail);
                temp->next=head;
                tail=temp;
            }
            c=c-1;
        }
        void delpos() {
            if (head==NULL) {
                printf("list is empty, cannot delete values\n");
                return;
            }
            else if (head->next==NULL) {
                printf("only one digit, no need for position\n");
                delbeg();
            }
            int pos;
            printf("enter position : ");
            scanf("%d", &pos);
            int co=1;
            pos=pos-1;
            struct node*temp=head;
            
            while (temp!=tail) {
                
                if (co==pos) {
                   
                    struct node *str;
                    str= temp->next->next;
                    free(temp->next);
                    temp->next=str;
                    return;
                }
                else {
                    
                    temp=temp->next;
                    co=co+1;
                }
            }
            c=c-1;
            return;

        }
        void search() {
            printf("enter key to search");
            int key;
            scanf("%d",&key);
            struct node* temp=head;
            while(temp!=tail) {
                if (temp->data==key) {
                    printf("Found\n");
                    return;
                }
                temp=temp->next;
            }   
            printf("not found\n");
            
        }
        
        
};

int main() {
    cll sll;
    int choice=0;
    while(choice!=9){
        printf("1.inbeg, 2.inend, 3.inpos,4.delbeg,5.delend,6.delpos,7.search,8.display, 9.exit");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                int value;
                printf("enter value : ");
                scanf("%d",&value);
                sll.inbeg(value);
                break;
            case 2:
                int valu;
                printf("enter value : ");
                scanf("%d",&valu);
                sll.inend(valu);
                break;
            case 3:
                int val;
                printf("enter value : ");
                scanf("%d",&val);
                sll.inpos(val);
                break;
            case 4:
                sll.delbeg();
                break;
            case 5:
                sll.delend();
                break;
            case 6:
                sll.delpos();
                break;
            case 7:
                sll.search();
                break;
            case 8:
                sll.display();
                break;
            case 9:
                printf("The end");
                break;
        }
    }
    return 0;
}