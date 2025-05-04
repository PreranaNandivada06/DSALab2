#include <iostream>
class list
{
    private:
    int arr[5];
    int index;
    public:
    list()
    {
        index=0;
    }
    void inend(int num) {
        if (index<5) {
            arr[index]=num;
            index++;
        }
        else{
            printf("cant add anymore delete\n");
        }
    }
    void display() {
        for (int i=0; i<index;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    int search(int num) {
        for (int i=0; i<index;i++) {
            if (num==arr[i])
            {
                printf("found \n");
                return i;          
            }
        }
        printf("not found\n");
    }
    int delend() {
        if (index>0){
            
            index=index-1;
            return arr[index-1];
        }
        else{
            printf("list is empty,please add elements\n");
        }
    }

    void inbeg(int num) {
        if (index<5) {
            for (int i=index-1; i>=0;i--){
                arr[i+1]=arr[i];
            }
            arr[0]=num;
            index=index+1;
        }
        else{
            printf("cant add anymore, delete\n");
        }

    }
    int delbeg() {
        if (index>0) {
            for (int i=0; i<index;i++){
                arr[i]=arr[i+1];
            }
            index=index-1;
            return arr[0];
        }
        else{
            printf("list is empty,please add elements\n");
        }
    }
    void inpos(int in, int num) {
        if (in>0 && in<index) {
            if (index<5) {
                for (int i=index-1; i>=in;i--){
                    arr[i+1]=arr[i];
                }
                arr[in]=num;
                index=index+1;
            }
            else{
                printf("cant add anymore, delete\n");
            }
        }
        else {
            printf("index doesnt exist\n");
        }

    }
    int delpos(int in) {
        if (in>0 && in<index) {
            if (index>0) {
                for (int i=in; i<index;i++){
                    arr[i]=arr[i+1];
                }
                index=index-1;
                int y=arr[in];
                return y;
            }
            else{
                printf("list is empty,please add elements\n");
            }
        }
        else {
            printf("index doesnt exist\n");
        }
    }
    void rotate()
    {
        int num=arr[index-1];
        for (int i=index-1; i>=0;i--){
                arr[i+1]=arr[i];
            }
            arr[0]=num;
            
    }


};
int main()
{
    
    list lis;
    while(1){
        int choice;
        printf("1.inbeg, 2.inend, 3.inpos,4.delbeg,5.delend,6.delpos,7.search,8.display, 9.rotate, 10.exit ");
        scanf("%d",&choice);
        if (choice==1)
        {
            
            int num;
            printf("enter number ");
            scanf("%d",&num);
            lis.inbeg(num);
        }
        else if(choice==2)
        {
            int num;
            printf("enter number ");
            scanf("%d",&num);
            lis.inend(num);
        }
        else if(choice==3)
        {
            int num;
            printf("enter number ");
            scanf("%d",&num);
            int in;
            printf("enter index ");
            scanf("%d",&in);
            lis.inpos(in,num);
        }
        else if(choice==4)
        {
            int y=lis.delbeg();
            printf("popped value %d\n",y);
        }
        else if(choice==5)
        {
            int y=lis.delend();
            printf("popped value %d\n", y);
        }
        else if(choice==6)
        {
            int in;
            printf("enter index ");
            scanf("%d",&in);
            int y=lis.delpos(in);
            printf("popped value %d\n", y);

        }
        else if(choice==7)
        {
            int num;
            printf("enter number ");
            scanf("%d",&num);
            int y=lis.search(num);
            printf("searched index %d", y);
        }
        else if(choice==8)
        {
            lis.display();
        }
        else if(choice==9)
        {
            lis.rotate();
        }
        else if(choice==10)
        {
            printf("the end\n");
            break;
        }

    }
    /*lis.inend(5);
    lis.inend(6);
    lis.inend(8);
    lis.display();
    lis.search(5);
    lis.search(8);
    lis.delend();
    lis.display();
    lis.inend(15);
    lis.display();
    return 0;*/
}