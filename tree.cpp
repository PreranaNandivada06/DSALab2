#include <stdio.h>
#include <stdlib.h>

class Tree {
private:
    struct node {
        int data;
        struct node* left;
        struct node* right;
    } *root;

public:
    Tree() {
        root = NULL;
    }

    struct node* insert(struct node* root, int val) {
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
        printf("%d ", root->data);
        inorder(root->right);
    }

    void preorder(struct node* root) {
        if (root == NULL) {
            return;
        }
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(struct node* root) {
        if (root == NULL) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }

    struct node* getroot() {
        return root;
    }

    void updateroot(struct node* r) {
        root = r;
    }

    void insertRoot(int val) {
        root = insert(root, val);
    }
};

int main() {
    Tree tr;
    int choice;
    do {
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int val;
            printf("Enter value to insert: ");
            scanf("%d", &val);
            tr.insertRoot(val);
        }
        else if (choice == 2) {
            printf("Inorder traversal: ");
            tr.inorder(tr.getroot());
            printf("\n");
        }
        else if (choice == 3) {
            printf("Preorder traversal: ");
            tr.preorder(tr.getroot());
            printf("\n");
        }
        else if (choice == 4) {
            printf("Postorder traversal: ");
            tr.postorder(tr.getroot());
            printf("\n");
        }
        else if (choice == 5) {
            printf("Exiting...\n");
        }
    } while (choice != 5);

    return 0;
}
