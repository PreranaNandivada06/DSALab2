#include <iostream>
class stackl
{
    private:
        struct node {
            int data;
            struct node* next;
        };
        struct node* head;
        int c;
    public:
        stackl(){head=NULL;c=0;}
        void push(int value) {
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=value;
            newnode->next=head;
            head= newnode;
            c=c+1;
        }
        int pop(){
            if(head==NULL){
                printf("StackEmpty\n");
                return -1;
            }
            
            struct node *stor;
            int stord;
            stor= head->next;
            stord=head->data;
            free(head);
            head=stor;
            c=c-1; 
            return stord;
        }
        int peek(){
                if(head==NULL){
                    printf("StackEmpty\n");
                    return -1;
                }
                return head->data;
            }
        
    };   