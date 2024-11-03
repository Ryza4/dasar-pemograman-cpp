#include <iostream>
#include <queue>
using namespace std;

// Struktur Node: data - nilai node, left - pointer node kiri, right - pointer node kanan
struct Node{ 
    int data; 
    Node *left; 
    Node *right; 
}; 

Node *root = NULL, *n = NULL, *temp = NULL;

// Fungsi membuat node baru
Node *createNode(int data){ 
    n = new Node; 
    n->data = data; 
    n->left = NULL; 
    n->right = NULL; 
    return n; 
} 

// Fungsi insert node ke BST
void insert(Node *&root, int data){ 
    if (root == NULL) 
        root = createNode(data); 
    else if (data <= root->data) 
        insert(root->left, data); 
    else 
        insert(root->right, data); 
}

// Fungsi menampilkan BST secara level-order
void levelOrder(Node *root){ 
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

// Fungsi menampilkan BST secara pre-order (root-left-right)
void preOrder(Node *root){ 
    if (root == NULL) return; 
    cout << root->data << " "; 
    preOrder(root->left); 
    preOrder(root->right); 
} 

// Fungsi menampilkan BST secara in-order (left-root-right)
void inOrder(Node *root){ 
    if (root == NULL) return; 
    inOrder(root->left); 
    cout << root->data << " "; 
    inOrder(root->right); 
}

// Fungsi menampilkan BST secara post-order (left-right-root)
void postOrder(Node *root){ 
    if (root == NULL) return; 
    postOrder(root->left); 
    postOrder(root->right); 
    cout << root->data << " "; 
} 

// Fungsi mencari node dalam BST
bool cari(Node *root, int data){ 
    if (root == NULL) 
        return false; 
    else if (data < root->data) 
        return cari(root->left, data); 
    else if (data > root->data) 
        return cari(root->right, data); 
    else 
        return true; 
} 

// Fungsi mencari nilai minimum dalam BST
Node *cariMin(Node *root){ 
    if (root == NULL) 
        return NULL; 
    while (root->left != NULL) 
        root = root->left; 
    return root; 
} 

// Fungsi menghapus node dalam BST
void hapus(Node *&root, int data){ 
    if (root == NULL) 
        return; 
    else if (data < root->data) 
        hapus(root->left, data); 
    else if (data > root->data) 
        hapus(root->right, data); 
    else { 
        // Kasus 1: Node tanpa anak
        if (root->left == NULL && root->right == NULL) { 
            delete root; 
            root = NULL; 
        } 
        // Kasus 2: Node dengan satu anak (kanan)
        else if (root->left == NULL) { 
            temp = root; 
            root = root->right; 
            delete temp; 
        } 
        // Kasus 2: Node dengan satu anak (kiri)
        else if (root->right == NULL) { 
            temp = root; 
            root = root->left; 
            delete temp; 
        } 
        // Kasus 3: Node dengan dua anak
        else { 
            temp = cariMin(root->right); 
            root->data = temp->data; 
            hapus(root->right, temp->data); 
        } 
    } 
}

// program utama
int main() {
    int pilihan, data;

    do {
        //menu ineraktif untuk operaso BST(binary search tree)
        cout << "Menu:\n";
        cout << "1. Buat Node Awal\n";
        cout << "2. Tambah Node\n";
        cout << "3. Hapus Node\n";
        cout << "4. Tampilkan Data\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai node awal: ";
                cin >> data;
                insert(root, data); // Menggunakan fungsi insert untuk membuat node awal
                break;
            case 2: {
                int subPilihan;
                cout << "1. Tambah Node di Depan (tidak berlaku untuk BST)\n";
                cout << "2. Tambah Node di Belakang (tidak berlaku untuk BST)\n";
                cout << "3. Tambah Node di Tengah (tidak berlaku untuk BST)\n";
                cout << "4. Batal\n";
                cout << "Masukkan pilihan: ";
                cin >> subPilihan;

                if (subPilihan == 1 || subPilihan == 2 || subPilihan == 3) {
                    cout << "Masukkan nilai: ";
                    cin >> data;
                    insert(root, data); // Semua opsi ini akan menggunakan insert karena BST
                } else {
                    cout << "Batal.\n";
                }
                break;
            }
            case 3:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> data;
                hapus(root, data);
                break;
            case 4: {
                int displayChoice;
                cout << "1. Tampilkan dari Depan (Preorder)\n";
                cout << "2. Tampilkan dari Belakang (Postorder)\n";
                cout << "3. Tampilkan dari Tengah (Inorder)\n";
                cout << "4. Tampilkan Level Order\n";
                cout << "Masukkan pilihan: ";
                cin >> displayChoice;

                switch (displayChoice) {
                    case 1:
                        cout << "Preorder Traversal: ";
                        preOrder(root);
                        cout << endl;
                        break;
                    case 2:
                        cout << "Postorder Traversal: ";
                        postOrder(root);
                        cout << endl;
                        break;
                    case 3:
                        cout << "Inorder Traversal: ";
                        inOrder(root);
                        cout << endl;
                        break;
                    case 4:
                        cout << "Level Order Traversal: ";
                        levelOrder(root);
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                }
                break;
            }
            case 5:
                cout << "Keluar.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}