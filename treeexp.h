#include <stack> 
#include <iostream>
using namespace std;

class Tree {
private:
    struct node {
        char data;
        struct node* left;
        struct node* right;
    } *root;

public:
    Tree() {
        root = NULL;
    }

    struct node* insert(struct node* root, char val) {
        if (root == NULL) {
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = val;
            newnode->left = NULL;
            newnode->right = NULL;
            return newnode;  // return new node when root is NULL
        }

        int cho;
        printf("Enter 1 for left, 2 for right: ");
        scanf("%d", &cho);

        if (cho == 1) {
            root->left = insert(root->left, val);
        } else if (cho == 2) {
            root->right = insert(root->right, val);
        }

        return root;  // return the root after insertion
    }

    void inorder(struct node* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }

    void preorder(struct node* root) {
        if (root == NULL) {
            return;
        }
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(struct node* root) {
        if (root == NULL) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }

    struct node* getroot() {
        return root;
    }


    void insertRoot(int val) {
        root = insert(root, val);
    }
    void conexptree(char* arr){
        stack<struct node*> st;
        int i=0;
        struct node* stor1;
        struct node* stor2;
        while(arr[i]!='\0'){
            struct node* newnode =(struct node*)calloc(1,sizeof(struct node));
            newnode->data=arr[i];
            root=newnode;
            if (arr[i]=='^' ||arr[i]=='+' ||arr[i]=='-'||arr[i]=='*'||arr[i]=='/' ){
                stor1=st.top();
                st.pop();
                stor2=st.top();
                st.pop();
                newnode->left=stor1;
                newnode->right=stor2;
                

            }
            st.push(newnode);
            i=i+1;   
        }
    }
};
