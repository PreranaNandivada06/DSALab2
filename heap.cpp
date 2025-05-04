#include <iostream>
class maxheap{
    private:
        int n;
        int arr[100];
        int c;

    public:
        maxheap(){
            n=1;c=1;
        }
        void heapify(int value){
            int p;
            if (c%2!=0) p=c+1;
            else p=c;
            if (arr[p/2]<value && p/2!=0){
                arr[c]=arr[p/2];
                arr[p/2]=value;
            }
        /*   for (int i=c;i>0;i--){
                int k;
                if(i!=0) p=i+1;
                else p=i;
                if(arr[k/2]<value && k/2!=0){
                    arr[i]=arr[k/2];
                    arr[k/2]=value;

            }*/
        }
        void setn(int value){
            n=value;
        }
        void insert(int value){
            int p;
            if (c%2!=0) p=c+1;
            else p=c;
            if (arr[p/2]>=value){
                arr[c]=value;
            }
            else{
                heapify(value);
            }
            c=c+1;
        }
        void display(){
            for (int i=0;i<n;i++){
               printf("%d ",arr[i+1]);

            }
        }
        void search(int key){
            for (int i=0;i<n;i++){
                if( key==arr[i+1]){
                    printf("found");
                    return;

                }
            }
                    printf("not found");
                
 
             
        }
    };
int main(){
    maxheap mh;
    int ch=0;
    int n;
    while(ch!=6){
        printf("1.insert,2.delete,3.display,4.search,5.sort,6.exit");
        scanf("%d",&ch);
        if (ch==1){
            printf("enter how many elements");
            scanf("%d",&n);
            mh.setn(n);
            for (int i=0;i<n;i++){
                int val;
                printf("enter val");
                scanf("%d", &val);
                mh.insert(val);

            }
        }
        else if(ch==3){
            mh.display();
        }
        else if(ch==4){
            int key;
                printf("enter key");
                scanf("%d", &key);
            mh.search(key);
         }
        else if (ch==6){
            printf("ending");
            break;
        }
    }
    
}