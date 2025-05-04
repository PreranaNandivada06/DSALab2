#include <iostream>
int main(){
    int t;
    printf("enter the number of testcases");
    scanf("%d",&t);
    if( 1<=t){
        if(t<=250){
    for (int i=0; i<t;i++){
        int k,q;
        printf("enter k(length of sequence) and q(no of values)");
        scanf("%d %d",&k,&q);
        int arra[k];
        int arrn[q];
        for (int j=0;j<k;j++){
            scanf("%d",&arra[j]);
        }
        for (int l=0;l<q;l++){
            scanf("%d",&arrn[l]);
        }
        for (int l=0;l<q;l++){ 
            while(arrn[l]>=arra[0]) 
            {
            for (int j=0;j<k;j++){
                if(arrn[l]>=arra[j]){
                    arrn[l]=arrn[l]-1;
                }
        
        }
    
    }
}

for (int l=0;l<q;l++){
    printf("%d",arrn[l]);
}
        
        

        
    }
}
}
}