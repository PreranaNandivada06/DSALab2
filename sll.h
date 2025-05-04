#include <iostream>
class sigli
{
    private:
        struct node {
            int data;
            struct node* next;
        };
        struct node* head;

        void inbeg(int value) {
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=value;
            newnode->next=head;
            head= newnode;
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
        
        }
        void inpos(int value,int pos) {
            if (head==NULL) {
                printf("list is empty, position not necessary");
                inbeg(value);
                return;
            }
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
            
            return;

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
    public:
        sigli(){head=NULL;}
        void display() {
            if (head==NULL){
                printf("empty");
                return;
            }
            struct node* temp;
            temp=head;
            while(temp->next!=NULL){
                printf("%d->",temp->data);
                temp=temp->next;
            }
            printf("%d->",temp->data);
            printf("NULL\n");}
        struct node* gethead() {
            return head;
        }
        void insert(int value){
            if (head==NULL) {
                inbeg(value);
                return;
            }
            
            struct node* temp=head;
            struct node* prev=NULL;
            while (temp!=NULL)
            {
                
                if (temp->data<=value){prev=temp; temp=temp->next;}
                else break;
               
            }
            if (prev!=NULL){
                    struct node* newnode=(struct node*)malloc(sizeof(struct node));
                    newnode->data=value;
                    prev->next=newnode;
                    newnode->next=temp;
                    return;
                }
            else{inbeg(value);}
            
            
        }
        sigli* merge(sigli* l1, sigli* l2){
            sigli* nl=new sigli();
            struct node* cur1=l1->head;
            struct node* cur2=l2->head;
            while (cur1!=NULL && cur2!=NULL){
                if (cur1->data<cur2->data){
                    nl->inbeg(cur1->data);
                    cur1=cur1->next;
                }
                else{
                    nl->inbeg(cur2->data);
                    cur2=cur2->next;
                }

            }
            while (cur1!=NULL){
                nl->inbeg(cur1->data);
                cur1=cur1->next;
            }
            while (cur2!=NULL){
                nl->inbeg(cur2->data);
                cur2=cur2->next;
            }
            nl->revlink();
            return nl;
        }

};