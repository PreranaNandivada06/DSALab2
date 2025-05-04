//to implement singley linked list using classes
#include <iostream>
class sigli
{
    private:
        struct node {
            int data;
            struct node* next;
        };
        struct node* head;
        int c;
    public:
        sigli(){head=NULL;c=0;}
        void inbeg(int value) {
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=value;
            newnode->next=head;
            head= newnode;
            c=c+1;
        }
        void display() {
            struct node* temp;
            temp=head;
            while(temp->next!=NULL){
                printf("%d->",temp->data);
                temp=temp->next;
            }
            printf("%d->",temp->data);
            printf("NULL");
        }
        void inend(int value) {
            if(head==NULL) {
                inbeg(value);
                return;
            }
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            struct node*temp=head;
            newnode->data=value;
            newnode->next=NULL;
            while (temp->next!=NULL) {
                temp=temp->next;
            }
            temp->next=newnode;
            c=c+1;
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
            c=c-1; 
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
            
            while (temp->next!=NULL) {
                
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
            c=c+1;
            return;

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
                struct node* temp=head;

                while (temp->next->next!=NULL) {
                    temp=temp->next;
                }
                free(temp->next);
                temp->next=NULL;
            }
            c=c-1;
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
            while(temp->next!=NULL) {
                if (temp->data==key) {
                    printf("Found");
                    return;
                }
                temp=temp->next;
            }   
            printf("not found");
            
        }
        void revdis() {
            int arr[c];
            int in=c;
            struct node* temp;
            temp=head;
            while(temp->next!=NULL){
                arr[in]=temp->data;
                temp=temp->next;
                in=in-1;
            }
            arr[in]=temp->data;
            for (int i=1;i<=c;i++) {
                printf("%d->",arr[i]);
            }

        }
         void revlink() 
        { 
            struct node *cur=head; 
            struct node *nxt_node= head; 
            struct node *pnode=NULL; 
            while (cur!=NULL) 
            { 
 
                nxt_node=cur->next; 
                cur->next=pnode; 
                pnode=cur; 
                cur=nxt_node; 

        } 

        head=pnode; 
        } 
};

int main() {
    sigli sll;
    int choice=0;
    while(choice!=11){
        printf("\n1.inbeg, 2.inend, 3.inpos,4.delbeg,5.delend,6.delpos,7.search,8.display, 9.revdis, 10.revlink, 11.exit");
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
                sll.revdis();
                break;
            case 10:
                sll.revlink();
                break;
            case 11:
                printf("The end");
                break;
        }
    }
    return 0;
}