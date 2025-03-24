#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *left, *right; } *root = NULL;

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data; newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(int data) {
    struct node **temp = &root;
    while (*temp) temp = (data > (*temp)->data) ? &(*temp)->right : &(*temp)->left;
    *temp = createNode(data);
}

int search(int key) {
    struct node* temp = root;
    while (temp) {
        if (key == temp->data) return 1;
        temp = (key > temp->data) ? temp->right : temp->left;
    }
    return 0;
}

void inorder(struct node* root) {
    if (!root) return;
    inorder(root->left); printf("%d ", root->data); inorder(root->right);
}

int main() {
    int choice, data;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Inorder\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 4) break;
        if (choice == 1) { printf("Data: "); scanf("%d", &data); insert(data); }
        else if (choice == 2) { printf("Data: "); scanf("%d", &data); printf(search(data) ? "Found\n" : "Not Found\n"); }
        else if (choice == 3) { inorder(root); printf("\n"); }
        else printf("Invalid Choice\n");
    }
    return 0;
}
