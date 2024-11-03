#include <iostream>
using namespace std;

struct Node{ 
int data; 
Node *next; 
Node *prev; 
}; 
Node *n=NULL, *head=NULL, *tail=NULL, *x=NULL;

void buatNodeBaru(int i){ 
n = new Node; 
n->data = i; 
n->prev = NULL; 
head = n; 
tail = n; 
tail->next = NULL; 
}

void tambahDiBelakang(int i){ 
    n = new Node; 
    n->data = i; 
    n->next = NULL;
    
    if (head == NULL) {  // Jika list kosong
        n->prev = NULL;
        head = n;
        tail = n;
    } else {  // Jika list tidak kosong
        n->prev = tail;
        tail->next = n;
        tail = n;
    }
}

void hapusDiBelakang(){ 
x = tail; 
tail = tail->prev; 
tail->next = NULL; 
delete(x); 
x = NULL; 
}

void hapusDiTengah(int i){ 
    // Jika list kosong
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    
    // Cari node dengan nilai yang akan dihapus
    Node *temp = head;
    while (temp != NULL && temp->data != i) {
        temp = temp->next;
    }
    
    // Jika nilai tidak ditemukan
    if (temp == NULL) {
        cout << "Nilai " << i << " tidak ditemukan!" << endl;
        return;
    }
     if (temp == tail) {
        tail = temp->prev;
        tail->next = NULL;
        delete temp;
        return;
    }
    
    // Jika node yang dihapus di tengah
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void tampilDariDepan(){ 
x = head; 
while(x != NULL){ 
cout << x->data << " "; 
x = x->next; 
	} 
}

void tampilDariBelakang(){ 
x = tail; 
while(x != NULL){ 
cout << x->data << " "; 
x = x->prev; 
	} 
}

int main (){
	int data,ch1,ch2,ch3;
	do{
		system("cls");
		cout << "===list menu===" << endl;
		cout << "1. tambah node " << endl;
		cout << "2. hapus node" << endl;
		cout << "3. tampilkan node" << endl;
		cout << "4. exit" << endl;
		cout << "masukkan pilihan [1..4] : ";cin >> ch1;
		
		switch(ch1){
			case 1:
				system("cls");
				cout << "masukkan nilai :";cin >> data;
				tambahDiBelakang(data);
				cout << "nilai " << data << " berhasil dimasukkan " << endl;
				system("pause");
				continue;
				break;
			case 2:
				system("cls");
				cout << "===list menu===" << endl;
				cout << "1. hapus dari belakang " << endl;
				cout << "2. hapus dari tengah" << endl;
				cout << "3. exit" << endl;
				cout << "masukkan pilihan [1..4] : "; cin >> ch2;
				switch(ch2){
					case 1:
						system("cls");
						if (head == NULL) {
				        cout << "List kosong!" << endl;
				        } else {
						cout << "node berhail dihapus " << endl;
						hapusDiBelakang();
					}
						system("pause");
						continue;
						break;
					case 2:
			         system("cls");
			            if (head == NULL) {
			                cout << "List kosong!" << endl;
			            } else {
			                cout << "Data saat ini: ";
			                tampilDariDepan();
			                cout << "\nMasukkan nilai yang akan dihapus: ";
			                cin >> data;
			                hapusDiTengah(data);
			                cout << "Node dengan nilai " << data << " telah dihapus" << endl;
			            }
			            break;
						}
			case 3:
				system("cls");
				cout << "===list menu===" << endl;
				cout << "1. tampilkan descending " << endl;
				cout << "2. tampilkan ascending" << endl;
				cout << "3. exit" << endl;
				cout << "masukkan pilihan [1..4] : "; cin >> ch3;
				switch(ch3){
					case 1:
						system("cls");
						cout << "node : ";
						tampilDariBelakang();
						cout << endl;
						system("pause");
						break;
					case 2:
						system("cls");
						cout << "node : ";
						tampilDariDepan();
						cout << endl;
						system("pause");
						break;
					}	
			case 4:
				break;
			default:
				cout << " inputan tidak valid" << endl;
				break;			
		}
	}while (ch1 != 4);
}