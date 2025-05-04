#include <iostream>
class graphm
{
    private:
        int arr[100][100]={0};
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
        int searchtt(int key1){
            struct node* temp=head;
            while(temp->next!=NULL) {
                if (temp->key==key1) {
                    return temp->valu;
                }
                temp=temp->next;
            }   
            return -1;
        }
        void insertP(int val1, int val2){
            int x=searcht(val1);
            int y=searcht(val2);
            if (x!=-1 and y!=-1){
                int wt;
                printf("enter weight");
                scanf("%d", &wt);
                arr[x][y]=wt;
                arr[y][x]=wt;
            }
        }
        void display(){
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
            }
            c=c-1;

        }
        void search(int val1,int val2){
            int x=searcht(val1);
            int y=searcht(val2);
            if (x!=-1 and y!=-1){
             if (arr[x][y]!=0){
                printf("path exists");
                return;
             }
            printf("path does not exist");
            }

        }
       void kruskals() {
    struct nd {
        int from;
        int to;
        int wt;
        bool act;
        struct nd* next;
    } *pd = NULL;

    int k = 0;
    while (k < c) {
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == k+1 && i != j) {
                    
                    struct nd* check = pd;
                    bool skip = false;
                    while (check) {
                        if (check->from == searchtt(i) && check->to == searchtt(j)) {
                            skip = true;
                            break;
                        }
                        check = check->next;
                    }
                    if (skip) continue;

                    
                    struct nd* newnod = (struct nd*)malloc(sizeof(struct nd));
                    newnod->from = searchtt(i);
                    newnod->to = searchtt(j);
                    newnod->wt = arr[i][j];
                    newnod->act = true;
                    newnod->next = pd;
                    pd = newnod;
                }
            }
        }
        k++;
    }

    
    struct nd* temp = pd;
    while (temp!=NULL) {
        printf("%d  %d  %d  %d\n", temp->from, temp->to, temp->wt, temp->act);
        temp = temp->next;
    }
    printf("NULL\n");
}

    };

    int main(){
        graphm hl;
        while(1){
            int ch;
            printf("enter 1. insertN,2.insertP,3. search,4.display,5.kruskals,6.delete 7.exit");
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
                    printf("enter val1 (from) : ");
                    scanf("%d",&val1);
                    printf("enter val2 (to): ");
                    scanf("%d",&val2);
                    hl.insertP(val1, val2);
    
            }
            else if(ch==6){
                int val1;
                int val2;
                    printf("enter val1 to delete (from): ");
                    scanf("%d",&val1);
                    printf("enter val2 to delete(to) : ");
                    scanf("%d",&val2);
                    hl.delet(val1,val2);
                    
            }
            else if(ch==3){
                int val1;
                int val2;
                    printf("enter val1 to search: (from)");
                    scanf("%d",&val1);
                    printf("enter val2 to search: (to)");
                    scanf("%d",&val2);
                    hl.search(val1,val2);
            }
            else if(ch==4){
                hl.display();
            }
            else if(ch==7){
                printf("the end");
                break;
            }
            else if(ch==5){
                hl.kruskals();
            }
        
        }
    }