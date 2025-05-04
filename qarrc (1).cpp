#include <iostream>
class queue
{
    private:
        int arr[5];
        int index;
        int front;
        int rear;
    public:
        queue(){
            arr[5]=-1;
            index=0;front=0;rear=0;
        }
        void enque(int num){
            if (index<5) {
                arr[index]=num;
                index++;
                rear=index;
            }
            else if(front!=-1 && rear!=-1){
                printf("cant add anymore delete\n");
            }
            else{
                index=1;
                enque(num);
            } 
        }
        int deque(){
            if (index>0 && front<5) {
                int x;
                x=arr[0];
                arr[0]=-1;
                front=front+1;
                
                return x;
            }
            else{
                printf("cant delete anymore add\n");
                front=1;
                return -1;
            }

        }
        int peek(){
            if(index>0) {
                return arr[front];
            }
            else{
                printf("EmptyStack\n");
                return -1;
            }
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