#include <iostream>
class graphm
{
    private:
        int arr[1000][1000]={0};
        int c;
        int no;
        struct node {
            int key;
            int valu;
            struct node* next;
        }*head;
    public:
        graphm(){c=0;}
        void insertN(int val){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->valu=val;
            newnode->key=c;
            newnode->next=head;
            head= newnode;
            c=c+1;

        }
        int searcht(int key1){
            struct node* temp=head;
            while(temp->next!=NULL) {
                if (temp->valu==key1) {
                    return temp->key;
                }
                temp=temp->next;
            }   
            return -1;
        }
        void insertP(int val1, int val2){
            int x=searcht(val1);
            int y=searcht(val2);
            if (x!=-1 and y!=-1){
                arr[x][y]=1;
                arr[y][x]=1;
            }
        }
        void display(){
            /*struct node* temp;
            temp=head;
            while(temp->next!=NULL){
                printf("%d ",temp->valu);
                temp=temp->next;
            }
            printf("%d ",temp->valu);*/
            for (int i=0;i<c;i++){
                for(int j=0;j<c;j++){
                    printf("%d ",arr[i][j]);
                }
                printf("\n");
            }
        }
        void delet(int val1,int val2){
            int x=searcht(val1);
            int y=searcht(val2);
            if (x!=-1 and y!=-1){
                arr[x][y]=0;
                arr[y][x]=0;
            }

        }
        void search(int val1,int val2){
            int x=searcht(val1);
            int y=searcht(val2);
            if (x!=-1 and y!=-1){
             if (arr[x][y]==1 and arr[y][x]==1){
                printf("path exists");
                return;
             }
            printf("path does not exist");
            }

        }
    };

    int main(){
        graphm hl;
        while(1){
            int ch;
            printf("enter 1. insertN,2.insertP, 6.delete,3. search,4.display, 5.exit");
            scanf("%d",&ch);
            if (ch==1){
                int value;
                    printf("enter value : ");
                    scanf("%d",&value);
                    hl.insertN(value);
    
            }
            else if (ch==2){
                int val1;
                int val2;
                    printf("enter val1 : ");
                    scanf("%d",&val1);
                    printf("enter val2 : ");
                    scanf("%d",&val2);
                    hl.insertP(val1, val2);
    
            }
            else if(ch==6){
                int val1;
                int val2;
                    printf("enter val1 to delete : ");
                    scanf("%d",&val1);
                    printf("enter val2 to delete : ");
                    scanf("%d",&val2);
                    hl.delet(val1,val2);
                    
            }
            else if(ch==3){
                int val1;
                int val2;
                    printf("enter val1 to search: ");
                    scanf("%d",&val1);
                    printf("enter val2 to search: ");
                    scanf("%d",&val2);
                    hl.search(val1,val2);
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