#include <stack> 
#include <iostream>
using namespace std;
#include "treeexp.h"6

int main() {
    Tree tr;
    int choice;
    do {
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5.ExpTree\n Exit\n");
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
            char arr[1000];
            printf("enter expression");
            scanf("%s",arr);
            tr.conexptree(arr);
            
        }
        else if (choice == 6) {
            printf("Exiting...\n");
        }
    } while (choice != 6);

    return 0;
}

