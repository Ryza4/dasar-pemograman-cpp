#include <iostream>
#include <queue>
using namespace std;

// Struktur Node
struct Node { 
    int data; 
    Node *left; 
    Node *right; 
}; 
Node *root = NULL, *n = NULL, *temp = NULL;

Node *createNode(int data) { 
    n = new Node; 
    n->data = data; 
    n->left = NULL; 
    n->right = NULL; 
    return n; 
} 

// Fungsi untuk memasukkan node ke kiri dari node tertentu
void insertLeft(Node *parent, int data) {
    if (parent == NULL) {
        cout << "Parent node tidak ditemukan.\n";
        return;
    }
    if (parent->left == NULL) {
        parent->left = createNode(data);
    } else {
        cout << "Node kiri sudah ada.\n";
    }
}

// Fungsi untuk memasukkan node ke kanan dari node tertentu
void insertRight(Node *parent, int data) {
    if (parent == NULL) {
        cout << "Parent node tidak ditemukan.\n";
        return;
    }
    if (parent->right == NULL) {
        parent->right = createNode(data);
    } else {
        cout << "Node kanan sudah ada.\n";
    }
}

// Fungsi untuk mencari node berdasarkan nilai
Node* findNode(Node *root, int data) {
    if (root == NULL) 
        return NULL;
    if (root->data == data) 
        return root;
    Node* leftSearch = findNode(root->left, data);
    if (leftSearch != NULL) 
        return leftSearch;
    return findNode(root->right, data);
}

// Traversal Level Order
void levelOrder(Node *root) { 
    if (root == NULL) return; 
    queue<Node*> q; 
    q.push(root); 
    while (!q.empty()) { 
        cout << q.front()->data << " "; 
        if (q.front()->left != NULL) 
            q.push(q.front()->left); 
        if (q.front()->right != NULL) 
            q.push(q.front()->right); 
        q.pop(); 
    } 
    cout << endl;
} 

// Traversal Preorder
void preOrder(Node *root) { 
    if (root == NULL) return; 
    cout << root->data << " "; 
    preOrder(root->left); 
    preOrder(root->right); 
} 

// Traversal Inorder
void inOrder(Node *root) { 
    if (root == NULL) return; 
    inOrder(root->left); 
    cout << root->data << " "; 
    inOrder(root->right); 
}

// Traversal Postorder
void postOrder(Node *root) { 
    if (root == NULL) return; 
    postOrder(root->left); 
    postOrder(root->right); 
    cout << root->data << " "; 
} 

int main() {
    int pilihan, data, parentData;
    
    // Membuat root manual
    root = createNode(10); // root dengan nilai 10

    do {
        cout << "Menu:\n";
        cout << "1. Tambah Anak Kiri\n";
        cout << "2. Tambah Anak Kanan\n";
        cout << "3. Level Order Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Inorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai parent: ";
                cin >> parentData;
                cout << "Masukkan nilai anak kiri: ";
                cin >> data;
                {
                    Node* parentNode = findNode(root, parentData);
                    insertLeft(parentNode, data);
                }
                break;
            case 2:
                cout << "Masukkan nilai parent: ";
                cin >> parentData;
                cout << "Masukkan nilai anak kanan: ";
                cin >> data;
                {
                    Node* parentNode = findNode(root, parentData);
                    insertRight(parentNode, data);
                }
                break;
            case 3:
                cout << "Level Order Traversal: ";
                levelOrder(root);
                break;
            case 4:
                cout << "Preorder Traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Inorder Traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "Postorder Traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 7:
                cout << "Keluar.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 7);

    return 0;
}
