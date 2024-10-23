 #include <stdio.h>
#include <stdlib.h>

 
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to search for a node in the binary search tree
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    }

    return searchNode(root->right, data);
}

// Function to find the minimum value node
struct Node* findMinNode(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to display the menu options
void displayMenu() {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert a node\n");
    printf("2. Delete a node\n");
    printf("3. Search for a node\n");
    printf("4. Inorder Traversal\n");
    printf("5. Preorder Traversal\n");
    printf("6. Postorder Traversal\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    struct Node* searchResult;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert a node
                printf("Enter the number to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("Node %d inserted successfully.\n", data);
                break;

            case 2:
                // Delete a node
                printf("Enter the number to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Node %d deleted (if it was present).\n", data);
                break;

            case 3:
                // Search for a node
                printf("Enter the number to search: ");
                scanf("%d", &data);
                searchResult = searchNode(root, data);
                if (searchResult != NULL) {
                    printf("Node %d found in the binary search tree.\n", data);
                } else {
                    printf("Node %d not found in the binary search tree.\n", data);
                }
                break;

            case 4:
                // Inorder traversal
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                // Preorder traversal
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 6:
                // Postorder traversal
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 7:
                // Exit
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
