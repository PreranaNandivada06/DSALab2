#include <iostream>

void palin(int*);
void armst(int*);
void pernum(int*);
int count(int*);
int main()
{
    while(1)
    {
        int *choice;
        choice=(int*)malloc(sizeof(int));
        printf("enter 1 for palindrome, 2 for armstrong, 3 for perfect number 4 for exit ");
        scanf("%d",choice);
        if (*choice==1)
        {
            int* num;
            num=(int*)malloc(sizeof(int));
            printf("enter number ");
            scanf("%d",num);
            palin(num);

        }
        else if (*choice==2)
        {
            int* num;
            num=(int*)malloc(sizeof(int));
            printf("enter number ");
            scanf("%d",num);
            armst(num);
        }
        else if (*choice==3)
        {
            int* num;
            num=(int*)malloc(sizeof(int));
            printf("enter number ");
            scanf("%d",num);
            pernum(num);
        }
        else if (*choice==4)
        {
            break;
        }
    }
    return 0;
}

void palin(int* num)
{
printf("begin palindrome check\n");
int *len;
len=(int*)malloc(sizeof(int));
*len=count(num);
char *arr=(char*)malloc((*len+1) *sizeof(char));
sprintf(arr,"%d", *num);
int *si;
si=(int*)malloc(sizeof(int));
*si=*len;
int *i;
i=(int*)malloc(sizeof(int));
for (*i=0;*i<=*len;*i=*i+1){
    if (arr[*i]!=arr[*si]){
        printf("not a palindrome\n");
        return;
    }
    else{
        *si=*si-1;
    }

}
printf("is a palindrome\n");
return;
}


void armst(int* num){
printf("begin armstrong check\n");
int *len;
len=(int*)malloc(sizeof(int));
*len=count(num);
int *num3,*num5,*num2;
num3=(int*)malloc(sizeof(int));
num5=(int*)malloc(sizeof(int));
num2=(int*)malloc(sizeof(int));
*num3=0;
*num5=*num;
int *pl;
pl=(int*)malloc(sizeof(int));
*pl=*len;
int *i;
i=(int*)malloc(sizeof(int));
for(*i=*len;*i>=0;*i=*i-1){
    *num2=*num;
    *num=*num%10;
    int *num6;
    num6=(int*)malloc(sizeof(int));
    *num6=1;
    int *j;
    j=(int*)malloc(sizeof(int));
    for (*j=*pl;*j>=0;*j=*j-1){
        *num6=(*num6)*(*num);
    }
    *num3=*num3+*num6;
    *len=*len-1;
    *num=*num2/10;
}
if (*num3==*num5){
    printf("yes armstrong\n");
}
else{
    printf("not armstrong\n");
}




}
void pernum(int* num){
printf("begin perfect number check\n");
int *sum1;

sum1=(int*)malloc(sizeof(int));
*sum1=0;
int *i;
i=(int*)malloc(sizeof(int));
for (*i=1;*i<(*num);*i=*i+1){
    
    if (*num%*i==0)
    {

        *sum1=(*sum1)+(*i);
    }
}
if (*num==*sum1){
    printf("yes perfect number\n");
}
else{
    printf("no, not perfect\n");
}


}
int count(int *num){
    int *y;
    y=(int*)malloc(sizeof(int));
    *y=10;
    int *len;
    len=(int*)malloc(sizeof(int));
    *len=0;
    while(1){
        if(*num<*y){
            return *len;
        }
        else
        {
            (*y)=(*y)*10;
            *len=*len+1;
        }
    }
}