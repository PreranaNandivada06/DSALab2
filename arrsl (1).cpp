//to implement a stack using a singly linked list
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

    int main(){
        stackl st;
        int choice;
        choice=0;
        while (choice!=4) {
            printf("1.push,2.pop,3.peek,4.exit: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    int value;
                    printf("enter value: ");
                    scanf("%d",&value);
                    st.push(value);
                    break;
                case 2:
                    int ret;
                    ret=st.pop();
                    printf("returned value %d \n",ret);
                    break;
                case 3:
                    int retc;
                    retc=st.peek();
                    if (retc==-1) {
                        break;
                    }
                    printf("returned value %d \n",retc);
                    break;
            }
        }
        return 0;
    }
