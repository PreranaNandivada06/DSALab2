#include <iostream>
class Tree {
    private:
        struct node {
            int data;
            struct node* left;
            struct node* right;
        }*root,*head;

    public:
        Tree(){
            head=NULL;
            root=NULL;
            
        }
        struct node* insert(struct node* root,int val){
            if (root==NULL){
                struct node* newnode=(struct node*)malloc(sizeof(struct node));
                newnode->data=val;
                newnode->left=NULL;
                newnode->right=NULL;
                root=newnode;
                return root;

            }
            if (val<root->data){
                root->left=insert(root->left,val);
            }
            else{
                root->right=insert(root->right,val);
            }

            return root;
        }
        void inorder(struct node* root) {
            if (root==NULL){
                return;
            }
            else {
                inorder(root->left);
                printf("%d ",root->data);
                inorder(root->right);
            }
        }
        void postorder(struct node* root) {
            if (root==NULL){
                return;
            }
            else {
                postorder(root->left);
                postorder(root->right);
                printf("%d ",root->data);
            }
        }
        void preorder(struct node* root) {
            if (root==NULL){
                return;
            }
            else {
                printf("%d ",root->data);
                preorder(root->left);
                preorder(root->right);
            }
        }
        struct node* ret(){
            return root;
        }
        void insertroot( int value){
            root=insert(root,value);
        }
        int sear(int key){
            int c=0;
            if (root==NULL){
                printf("empty list");
                return 0;

            }
            while (root->left!=NULL and root->left!=NULL )
            {
                if (root->data==key){
                    return 1;
                }
            
                else{
                    if (key<root->data){
                        root=root->right;
                    }
                    else{
                        root=root->left;
                    }
                }
            }

        }


};
int main(){
    Tree tr;
    while(1){
        printf("1.insert, 2.inorder,3.preorder, 4.postorder ,5.search 6.exit");
        int ch;
        scanf ("%d",&ch);
        if (ch==1){
            int val;
            printf("enter value");
            scanf("%d",&val);
            tr.insertroot(val);
        }
        else if(ch==2){
            printf("inorder");
            tr.inorder(tr.ret());

        }
        else if(ch==3){
            printf("preorder");
            tr.preorder(tr.ret());
        }
        else if(ch==4){
            printf("postorder");
            tr.postorder(tr.ret());
            
        }
        else if(ch==5){
            int val;
            printf("enter value");
            scanf("%d",&val);
            int ret;
            ret=tr.sear(val);
            if(ret==1){
                printf("found");
            }
            else{
                printf("not found");
            }
        }
        else if(ch==6){
            printf("end");
            break;
        }

    }

    


}