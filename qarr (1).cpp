#include <iostream>
class queue
{
    private:
        int arr[5];
        int index;
        int top;
    public:
        queue(){
            index=0;top=0;
        }
        void enque(int num){
            if (index<5) {
                arr[index]=num;
                index++;
            }
            else{
                printf("cant add anymore delete\n");
            }
        }
        int deque(){
            if (index>0) {
                int x;
                x=arr[0];
                for (int i=0; i<index;i++){
                    arr[i]=arr[i+1];
                }
                index=index-1;
                return x;
            }
            else{
                printf("cant delete anymore add\n");
                return -1;
            }

        }
        int peek(){
            if(index>0) {
                return arr[0];
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