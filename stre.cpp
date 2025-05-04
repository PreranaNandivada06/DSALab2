#include <iostream>
int main(){
    int t;
    printf("enter the number of testcases");
    scanf("%d",&t);
    if( 1<=t){
        if(t<=1000){
    for (int i=0; i<t;i++){
        int n;
        printf("enter the length of the arr");
        scanf("%d",&n);
        int arr[n+1];
        for (int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        for (int k=0;k<n;k++){
            int max=0;
            int key=arr[k];
            for(int b=0;b<n;b++){
                if (arr[b]!=key){
                    if (arr[b]>max){
                        max=arr[b];
                    }
                }
            }
            printf(" %d ",key-max);
            
        }
        printf("\n");


        
    }
}
}
}