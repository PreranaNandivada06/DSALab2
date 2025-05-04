#include <iostream>
class list
{
    private:
        struct node {
            char data;
            struct node* next;
        };
        struct node* head;
        int c;
    public:
        list(){head=NULL;c=0;}
        void push(char value) {
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=value;
            newnode->next=head;
            head= newnode;
            c=c+1;
        }
        char pop(){
            if(head==NULL){
                printf("StackEmpty\n");
                return -1;
            }
            
            struct node *stor;
            char stord;
            stor= head->next;
            stord=head->data;
            free(head);
            head=stor;
            c=c-1; 
            return stord;
        }
        char peek(){
                if(head==NULL){
                    printf("StackEmpty\n");
                    return -1;
                }
                printf("%c",head->data);
                return head->data;
            }
        void display() {
            struct node* temp;
            temp=head;
            while(temp->next!=NULL){
                printf("%s->",temp->data);
                temp=temp->next;
            }
            printf("%s->",temp->data);
            printf("NULL");
        }
        
        
    };   