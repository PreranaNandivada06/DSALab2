#include <iostream>
class hashl
{
    private:
        
        int arr[20]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    public:
        
        void insert(int value){
            printf("ch1");
            int rval;
            rval=value%20;
            printf("ch2");
            int i=rval+1;
            if (arr[rval]==-1){
                arr[rval]=value;
            }
            else{
                while (arr[i]!=-1){
                    i=i+1;
                }
                arr[i]=value;
            }

        }
        int search(int key){
            int rval;
            rval=key%20;
            while(arr[rval]!=-1){
                if (arr[rval]==key){
                    printf("Found\n");
                    return rval;

                }
                rval=rval+1;
            }
            printf("not found\n");
            return -1;
        }

        int delet(int key){
            int x=search( key);
            if (x==-1){
                printf("number not available\n");
                return -1;
            }
            int stor=arr[x];
            arr[x]=-1;
            return stor;
        }
        void display(){
            for (int i=0;i<20;i++){
                if (arr[i]!=-1){
                    printf("%d: %d",i,arr[i]);
                }
            }
        }
};
int main(){
    hashl hl;
    while(1){
        int ch;
        printf("enter 1. insert,2.delete,3. search,4.display, 5.exit");
        scanf("%d",&ch);
        if (ch==1){
            int value;
                printf("enter value : ");
                scanf("%d",&value);
                hl.insert(value);

        }
        else if(ch==2){
            int value;
                printf("enter value to delete : ");
                scanf("%d",&value);
                int x;
                x=hl.delet(value);
                printf("returned value %d", x);
        }
        else if(ch==3){
            int value;
                printf("enter value to search : ");
                scanf("%d",&value);
                hl.search(value);
        }
        else if(ch==4){
            hl.display();
        }
        else if(ch==5){
            printf("the end");
            break;
        }
    }
}