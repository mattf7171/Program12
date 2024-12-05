#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insertNode(Node* current, int value) {
        if (!current) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertNode(current->left, value);
        } else {
            current->right = insertNode(current->right, value);
        }

        return current;
    }

    void preorderTraversal(Node* current) {
        if (current) {
            cout << current->data << " ";
            preorderTraversal(current->left);
            preorderTraversal(current->right);
        }
    }

    void inorderTraversal(Node* current) {
        if (current) {
            inorderTraversal(current->left);
            cout << current->data << " ";
            inorderTraversal(current->right);
        }
    }

    void postorderTraversal(Node* current) {
        if (current) {
            postorderTraversal(current->left);
            postorderTraversal(current->right);
            cout << current->data << " ";
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void printPreorder() {
        preorderTraversal(root);
        cout << endl;
    }

    void printInorder() {
        inorderTraversal(root);
        cout << endl;
    }

    void printPostorder() {
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    int values[] = {50, 75, 25, 15, 60, 35, 90, 42, 20, 27, 5, 55, 95, 80, 70};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        tree.insert(values[i]);
    }

    cout << "Preorder: ";
    tree.printPreorder();

    cout << "Inorder: ";
    tree.printInorder();

    cout << "Postorder: ";
    tree.printPostorder();

    return 0;
}

