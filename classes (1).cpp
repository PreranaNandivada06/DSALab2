# include <iostream>
class shapearea
{
    private:
    int len;
    int bre;
    int hei;
    public:
    shapearea()
    {len=1;bre=1;hei=1;}
    void setlen(int temp){len=temp;}
    void setbre(int temp){bre=temp;}
    void sethei(int temp){hei=temp;}
    int square(){return len*len;}
    int cube(){return 6*len*len;}
    int rect(){return len*bre;}
    int cuboid(){return 2*(len*bre+len*hei+bre*hei);}
    

};
int main(){
    int choice;
    while (1)
    {
        printf("enter 1 for square, 2 for cube, 3 for rectangle, 4 for cuboid, 5 for exit ");
        scanf("%d",&choice);
        shapearea obj;
        if (choice==1)
        {
            shapearea obj;
            int temp1;
            printf("side ");
            scanf( "%d",&temp1);
            obj.setlen(temp1);
            printf("%d",obj.square());
        }
        else if(choice==2)
        {
            shapearea obj;
            int temp1;
            printf("side ");
            scanf( "%d",&temp1);
            obj.setlen(temp1);
            printf("%d",obj.cube());

        }
        else if(choice==3)
        {
            shapearea obj;
            int temp1,temp2;
            printf("length ");
            scanf( "%d",&temp1);
            obj.setlen(temp1);
            printf("breath ");
            scanf( "%d",&temp2);
            obj.setbre(temp2);
            printf("%d",obj.rect());

        }
        else if(choice==4)
        {
            shapearea obj;
            int temp1,temp2,temp3;
            printf("length ");
            scanf( "%d",&temp1);
            obj.setlen(temp1);
            printf("breath ");
            scanf( "%d",&temp2);
            obj.setbre(temp2);
            printf("height ");
            scanf( "%d",&temp3);
            obj.setbre(temp3);
            printf("%d",obj.cuboid());
        }
        else if(choice==5)
        {
            printf("the end\n");
            break;
        }
}
return 0;
}