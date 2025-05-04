#include <iostream>
class rrs
{
    private:
        struct node {
            int id;
            int data;
            struct node* next;
        }*head,*tail;
        int c;

    public:
        rrs()
        {head=NULL;tail=NULL;c=0;}
        void insert(int sno, int val) {
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=val;
            newnode->id=sno;
            if (head==NULL) {
                newnode->next=head;
                head=newnode;
                tail=newnode;
                return;
            }
            
            newnode->next=head;
            struct node* temp;
            
            tail->next=newnode;
            head=newnode;
            c=c+1;
            return;
        }
        void execute(int val){
            struct node* temp=head;
            struct node* prev;
            while (c>0) {
                if (temp->data>0){
                    if ((temp->data)>val){
                    temp->data=temp->data-val;
                    }
                    else {
                        temp->data=0;
                        
                    }
                    printf("job%d, %d\n",temp->id,temp->data);
    
                    prev=temp;
                    temp=temp->next;
                }
                else {
                    printf("completed job%d\n",temp->id);
                    struct node *stor;
                    stor= temp->next;
                    free(temp);
                    prev->next=stor;
                    c=c-1;
                    return;
                }
            }
        }
        
};