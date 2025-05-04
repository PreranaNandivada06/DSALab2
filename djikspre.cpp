#include <iostream>
class graph
{
    private:
        const int INF = 10000;  // or INT_MAX 
        struct node {
            int num;
            int d;
            struct node* pat;
            struct node* next;
            bool known;
            int nbrc;
            struct node* *nbr; // list of nbr nodes
            int *wt; // list of wts for nbrs

        }*head;
    public:
        graph(){head=NULL; }
        void insertnd(int nod){
            struct node* newnode=(struct node*)calloc(1, sizeof(struct node));
            newnode->num=nod;
            newnode->next=head;
            head = newnode;
        }

        struct node *find(int nod){
              struct node* temp;
                temp=head;
                while(temp!=NULL){
                    if (temp->num==nod){
                        printf("node found\n");
                        return temp;
                        break;
                    }
                    temp=temp->next;

                }
            return NULL;
        }
        void insertEds(int nod){

            struct node* temp = find(nod);
            int con;
            printf("enter no of nbrs ");
            scanf("%d",&con);
            temp->nbrc=con;
            temp->nbr=(struct node**)malloc(temp->nbrc * sizeof(struct node*));
            temp->wt=(int*)malloc(temp->nbrc * sizeof(int));


            for(int i=0;i<temp->nbrc;i++){
                int edd;
                printf("enter edge to ");
                scanf("%d",&edd);
                int wtt;
                printf("enter wt ");
                scanf("%d",&wtt);
                temp->nbr[i]=find(edd);
                temp->wt[i]=wtt;
            }
        }
        void display(){
            struct node* temp=head;
            while(temp!=NULL){
                printf("%d",temp->num);
                for (int i=0;i<temp->nbrc;i++){
                    printf(";%d (%d) ",temp->nbr[i]->num, temp->wt[i]);
                    

                }
                printf(" NULL\n");
                temp=temp->next;

            }
        }
        void displaydjik(){
            struct node* temp=head;
            printf(" node known d pat \n");
            while(temp!=NULL){
                //for (int i=0;i<temp->nbrc;i++){
                    printf(";%d  %d  %d %d \n",temp->num, temp->known, temp->d, temp->pat!=NULL?temp->pat->num:0);
                    

                //}
                temp=temp->next;

            }
        }
        void djik(struct node* sor){
            struct node* temp=head;
            while(temp!=NULL){
                temp->d=INF;
                temp->known=false;
                temp=temp->next;
            }
            sor->d=0;
            temp=head;
            while (temp!=NULL){
                struct node* temp1;
                for (int i=0; i<temp->nbrc;i++){
                    struct node* temp1=temp->nbr[i];
                    if(temp1->known==false){
                        if (temp->d+temp->wt[i]<temp1->d){
                            temp1->d=temp->d+temp->wt[i];
                            temp1->pat=temp;

                        }
                    }
                }
                temp=temp->next;
            }

            displaydjik();
        }
    

};
int main(){
    graph dj;
    int c;
    while (1) {
        printf("1. enter nodes, 2.enter pats,3.display,4. djik,5. exit");
        scanf("%d",&c);
        if(c==1){
            int value;
                    printf("enter value : ");
                    scanf("%d",&value);
                    dj.insertnd(value);
        }
        else if(c==2){
            int value;
                    printf("enter value : ");
                    scanf("%d",&value);
                    dj.insertEds(value);
        }
        else if(c==3){
            dj.display();
        }
        else if(c==4){
            int value;
                    printf("enter value : ");
                    scanf("%d",&value);
            dj.djik(dj.find(value));
        }
        else if(c==5){
           break; 
        }
    }
    
}