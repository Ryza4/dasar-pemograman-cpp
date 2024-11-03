#include <iostream>
#include <queue>
using namespace std;

//struck node
struct Node{ 
int data; 
Node *left; 
Node *right; 
}; 
Node *root=NULL, *n=NULL, *temp=NULL;

Node *createNode(int data){ 
n = new Node; 
n->data = data; 
n->left = NULL; 
n->right = NULL; 
return n; 
} 

void insert(Node *&root, int data){ 
if (root==NULL) 
root = createNode(data); 
else if (data <= root->data) 
insert(root->left, data); 
else if (data > root->data) 
insert(root->right, data); 
}

void levelOrder(Node *root){ 
if (root==NULL) return; 
queue<Node*> q; 
q.push(root); 
while(!q.empty()){ 
cout << q.front()->data << " "; 
if(q.front()->left != NULL) 
q.push(q.front()->left); 
if(q.front()->right != NULL) 
q.push(q.front()->right); 
q.pop(); 
} 
} 

void preOrder(Node *root){ 
if (root==NULL) return; 
cout << root->data << " "; 
preOrder(root->left); 
preOrder(root->right); 
} 

void inOrder(Node *root){ 
if (root==NULL) return; 
inOrder(root->left); 
cout << root->data << " "; 
inOrder(root->right); 
}

void postOrder(Node *root){ 
if (root==NULL) return; 
postOrder(root->left); 
postOrder(root->right); 
cout << root->data << " "; 
} 

bool cari(Node *root, int data){ 
if (root==NULL) 
return false; 
else if(data < root->data) 
return cari(root->left, data); 
else if(data > root->data) 
return cari(root->right, data); 
else 
return true; 
} 

Node *cariMin(Node *root){ 
if (root==NULL) 
return NULL; 
while(root->left != NULL) 
root = root->left; 
return root; 
} 

void hapus(Node *&root, int data){ 
if (root==NULL) 
return; 
else if(data < root->data) 
return hapus(root->left, data); 
else if(data > root->data) 
return hapus(root->right, data); 
else{ 
// kasus I 
if (root->left == NULL && root->right == NULL){ 
delete(root); 
root=NULL; 
} 
// kasus II 
else if (root->left == NULL){ 
temp = root; 
root = root->right; 
delete(temp); 
temp=NULL; 
} 
else if (root->right == NULL){ 
temp = root; 
root = root->left; 
delete(temp); 
temp=NULL; 
} 
// kasus III 
else{ 
temp = cariMin(root->right); 
root->data = temp->data; 
hapus(root->right, root->data); 
} 
} 

int main() {
    int pilihan, data;

    do {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Level Order Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Inorder Traversal\n";
        cout << "7. Postorder Traversal\n";
        cout << "8. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> data;
                insert(root, data);
                break;
            case 2:
                cout << "Masukkan nilai yang dicari: ";
                cin >> data;
                if (search(root, data))
                    cout << "Data ditemukan.\n";
                else
                    cout << "Data tidak ditemukan.\n";
                break;
            case 3:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> data;
                deleteNode(root, data);
                break;
            case 4:
                cout << "Level Order Traversal: ";
                levelOrder(root);
                break;
            case 5:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 7:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 8:
                cout << "Keluar.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 8);

    return 0;
}
