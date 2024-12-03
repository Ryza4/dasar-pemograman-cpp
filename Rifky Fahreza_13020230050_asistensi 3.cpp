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

int main(){
	int choice,data;
	
	do{
	menu:
	cout << "menu binary search tree : " << endl;
	cout << "1. insert data " << endl;
	cout << "2. hapus data" << endl;
	cout << "3. cari data " << endl;
	cout << "4. traversal " << endl;
	cout << "5. keluar " << endl;
	cout << "pilihan: "; cin >> choice;
	cin.clear();
	cin.ignore();
	
	switch(choice){
		case 1:
			system("cls");
			cout << "masukkan data : "; cin >> data;
			insert(root, data);
			cout << "node dengan nilai " << data << " berhasil dimasukkan!" << endl;
			break;
		case 2:
			system("cls");
			cout << "masukkan data : "; cin >> data;
			hapus(root, data);
			cout << "node dengan nilai " << data << " berhasil dihapus!" << endl;
			break;
		case 3:
			system("cls");
			cout << "masukkan data yang ingin dicari : "; cin >> data;
			if (cari(root, data)){
			cout << "node dengan nilai " << data << " ditemukan!" << endl;
			} else {
				cout << "data tidak ditemukan!" << endl;
			}
			break;
		case 4:
			system("cls");
			cout << "pilih jenis traversal : " << endl;
			cout << "1. level order traversal " << endl;
			cout << "2. preorder traversal" << endl;
			cout << "3. inorder traversal" << endl;
			cout << "4. postorder traversal " << endl;
			cout << "5. kembali ke menu utama" << endl;
			cout << "pilihan: "; cin >> choice;
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
                } else if(choice == 5){
                    goto menu ;
                } else {
                    cout << "Opsi tidak valid, silakan coba lagi.\n";
                } 
            }
	}while(choice != 5);
}