#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = nullptr, *n = nullptr, *temp = nullptr;

Node* createNode(int data) {
    n = new Node;
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void insert(Node*& root, int data) {
    if (root == nullptr) {
        root = createNode(data);
    } else if (data <= root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

void levelOrder(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        cout << q.front()->data << " ";
        if (q.front()->left != nullptr) q.push(q.front()->left);
        if (q.front()->right != nullptr) q.push(q.front()->right);
        q.pop();
    }
}

void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

bool cari(Node* root, int data) {
    if (root == nullptr)
        return false;
    else if (data < root->data)
        return cari(root->left, data);
    else if (data > root->data)
        return cari(root->right, data);
    else
        return true;
}

Node* cariMin(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

void hapus(Node*& root, int data) {
    if (root == nullptr)
        return;
    else if (data < root->data)
        hapus(root->left, data);
    else if (data > root->data)
        hapus(root->right, data);
    else {
        // kasus I
        if (root->left == nullptr && root->right == nullptr) {
            delete(root);
            root = nullptr;
        }
        // kasus II
        else if (root->left == nullptr) {
            temp = root;
            root = root->right;
            delete(temp);
            temp = nullptr;
        }
        else if (root->right == nullptr) {
            temp = root;
            root = root->left;
            delete(temp);
            temp = nullptr;
        }
        // kasus III
        else {
            temp = cariMin(root->right);
            root->data = temp->data;
            hapus(root->right, temp->data);
        }
    }
}

int main() {
    int choice, data;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Pencarian Data\n";
        cout << "3. Hapus Node\n";
        cout << "4. Binary Tree Traversal\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan [1..5] : ";
        cin >> choice;

        switch (choice) {
        case 1:
        	system("cls");
            cout << "Masukkan nilai untuk node baru: ";
            cin >> data;
            insert(root, data);
            cout << "Node dengan nilai " << data << " telah ditambahkan.\n";
            break;
        case 2:
        	system("cls");
            if (root != nullptr) {
                cout << "Masukkan nilai untuk node yang akan dicari: ";
                cin >> data;
                if (cari(root, data)) {
                    cout << "Node dengan nilai " << data << " ditemukan di BST.\n";
                } else {
                    cout << "Node dengan nilai " << data << " tidak ditemukan di BST.\n";
                }
            } else {
                cout << "Binary Search Tree kosong, tambahkan node terlebih dahulu.\n";
            }
            break;
            system("cls");
        case 3:
            if (root != nullptr) {
                cout << "Masukkan nilai untuk node yang akan dihapus: ";
                cin >> data;
                hapus(root, data);
                cout << "Node dengan nilai " << data << " telah dihapus.\n";
            } else {
                cout << "Binary Search Tree kosong, tambahkan node terlebih dahulu.\n";
            }
            break;
        case 4:
        	system("cls");
            if (root != nullptr) {
                cout << "\nOpsi Traversal Binary Tree:\n";
                cout << "1. Level Order\n";
                cout << "2. Preorder\n";
                cout << "3. Inorder\n";
                cout << "4. Postorder\n";
                cout << "Pilih opsi traversal: ";
                cin >> choice;
                if (choice == 1) {
                    cout << "Traversal Level Order dari BST: ";
                    levelOrder(root);
                    cout << endl;
                } else if (choice == 2) {
                    cout << "Traversal Preorder dari BST: ";
                    preOrder(root);
                    cout << endl;
                } else if (choice == 3) {
                    cout << "Traversal Inorder dari BST: ";
                    inOrder(root);
                    cout << endl;
                } else if (choice == 4) {
                    cout << "Traversal Postorder dari BST: ";
                    postOrder(root);
                    cout << endl;
                } else {
                    cout << "Opsi tidak valid, silakan coba lagi.\n";
                }
            } else {
                cout << "Binary Search Tree kosong, tambahkan node terlebih dahulu.\n";
            }
            break;
        case 5:
        	system("cls");
            cout << "Keluar dari program.\n";
            return 0;
        default:
            cout << "Opsi tidak valid, silakan coba lagi.\n";
        }
    }
}
