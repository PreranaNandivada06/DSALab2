#include <iostream>
#include <vector>
int main(){
    int t;
    printf("enter no of testcases");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int c=0;
        printf("enter the number of values");
        int n;
        scanf("%d",&n);
        std:: vector <int> myvector(n);
        for (int j=0;j<n;j++){
            int ph;
            scanf("%d",&ph);
            for (unsigned p=0;p<=myvector.size();p++){
                int k=0;

                if (ph==myvector[p]){

                    myvector.erase(myvector.begin(),myvector.begin()+p);


                    c=c+(1);

                    
                }
                k=k+1;
                
            }
            myvector.push_back(ph);
        }
        printf("\n");

        printf("%d",c);
    }
}