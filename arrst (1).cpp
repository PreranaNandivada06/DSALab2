//to implement a stack using a array.
#include <iostream>
class stack
{
    private:
        int arr[5];
        int index;
        int top;
    public:
        stack() {
            index=0;top=0;
        }
        //push function into the stack =>inserts the value at the end of the array and assigns the value to top.
        void push(int value) {
            if (index<5){
                arr[index]=value;
                top=arr[index];
                index=index+1;

            }
            else{
                printf("StackOverflow");
            }
        }
        //peek function return top
        int peek(){
            if(index>0) {
                return top;
            }
            else{
                printf("EmptyStack\n");
                return -1;
            }
        }
        //pop function displays the last inputted value and deletes it from the stack.
        int pop(){
            if (index>0) { 
                index=index-1;
                top=arr[index-1];
                return arr[index];
            }
            else{
                printf("EmptyStack\n");
                return -1;
            }
        }
        

};
int main(){
    stack st;
    int choice;
    choice=0;
    while (choice!=4) {
        printf("1.push,2.pop,3.peek,4.exit : ");
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