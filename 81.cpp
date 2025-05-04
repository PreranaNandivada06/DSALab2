#include <iostream>
int main(){
    int i;
    int c=0;
    printf("how many rounds");
    int rou;
    scanf("%d",&rou);
    int ark[rou];
    for (i=0;i<rou;i++){
        printf("how many towers");
        int tow;
        scanf("%d",&tow);
        int arr[tow];
        for (int j=0;j<tow;j++){
            printf("enter no of block");
            scanf("%d",&arr[j]);
        }
        for(int k=0;k<tow;k++){
            while(arr[0]<arr[k]){
                arr[0]=arr[0]+1;
                arr[k]=arr[k]-1;
            }
            }
        ark[c]=arr[0];
        c=c+1;
    }
    for (i=0;i<rou;i=1+i){
        printf("%d ",ark[i]);
    }

    
}