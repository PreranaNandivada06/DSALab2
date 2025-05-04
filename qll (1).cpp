#include <iostream>
class queue
{
    private:
        struct node {
            int data;
            struct node* next;
        }*rear;
        struct node* front;

        int c;
    public:
        queue(){front=NULL;c=0;rear=NULL;}
        void enque(int value) {
            if(front==NULL) {
                struct node* newnode=(struct node*)malloc(sizeof(struct node));
                 newnode->data=value;
                 newnode->next=front;
                 front= newnode;
                 rear=newnode;
                 c=c+1;
                return;
            }
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            struct node*temp=front;
            newnode->data=value;
            newnode->next=NULL;
            while (temp->next!=NULL) {
                temp=temp->next;
            }
            temp->next=newnode;
            c=c+1;
        }
        int deque(){
            if(front==NULL){
                printf("list empty, add values");
                return -1;
            }
            
            struct node *str;
            str= front->next;
            int x=front->data;
            free(front);
            front=str;
            c=c-1; 
            return x;

        }
        int peek(){
            if(front==NULL){
                printf("StackEmpty\n");
                return -1;
            }
            struct node*temp=front;
            while (temp->next!=NULL) {
                temp=temp->next;
            }
            return front->data;
        }


    };
    int main(){
        queue st;
        int choice;
        choice=0;
        while (choice!=4) {
            printf("1.enqueue,2.dequeue,3.peek,4.exit");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    int value;
                    printf("enter value: ");
                    scanf("%d",&value);
                    st.enque(value);
                    break;
                case 2:
                    int ret;
                    ret=st.deque();
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