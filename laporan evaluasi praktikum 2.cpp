#include <iostream>
using namespace std;

class Node {
public:
    int data;Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SingleLinkedList {
private:
    Node* head;
    int last_deleted;

public:
    SingleLinkedList() {
        head = nullptr;
        last_deleted = -1; // Use -1 to indicate no node has been deleted yet
    }

    void insert_front(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void insert_back(int data) {
        if (!head) {
            cout << "Node belum tersedia. Harap buat node terlebih dahulu." << endl;
            return;
        }
        Node* new_node = new Node(data);
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    void insert_middle(int data, int after_data) {
        if (!head) {
            cout << "Node belum tersedia. Harap buat node terlebih dahulu." << endl;
            return;
        }
        Node* new_node = new Node(data);
        Node* current = head;
        while (current) {
            if (current->data == after_data) {
                new_node->next = current->next;
                current->next = new_node;
                return;
            }
            current = current->next;
        }
        cout << "Nilai tidak ditemukan. Penginputan gagal." << endl;
    }

    void delete_front() {
        if (!head) {
            cout << "List kosong." << endl;
            return;
        }
        last_deleted = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void delete_back() {
        if (!head) {
            cout << "List kosong." << endl;
            return;
        }
        if (!head->next) {
            last_deleted = head->data;
            delete head;
            head = nullptr;
            return;
        }
        Node* second_last = head;
        while (second_last->next->next) {
            second_last = second_last->next;
        }
        last_deleted = second_last->next->data;
        delete second_last->next;
        second_last->next = nullptr;
    }

    void delete_middle(int data) {
        if (!head) {
            cout << "List kosong." << endl;
            return;
        }
        Node* temp = head;
        if (temp != nullptr && temp->data == data) {
            last_deleted = temp->data;
            head = temp->next;
            delete temp;
            return;
        }
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node tidak ditemukan." << endl;
            return;
        }
        last_deleted = temp->data;
        prev->next = temp->next;
        delete temp;
    }

    void display() {
        if (!head) {
            cout << "Tidak ada node untuk ditampilkan." << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "None" << endl;
        if (last_deleted != -1) {
            cout << "Node yang terakhir dihapus: " << last_deleted << endl;
        }
    }

    void menu() {
        int choice, data, after_data;
        while (true) {
            cout << "\nMenu" << endl;
            cout << "1. Buat Node Baru" << endl;
            cout << "2. Tambah Node" << endl;
            cout << "3. Hapus Node" << endl;
            cout << "4. Tampilkan seluruh Node" << endl;
            cout << "5. keluar" << endl;
            cout << "Masukkan pilihan: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> data;
                insert_front(data);
                break;
            case 2:
                if (head == nullptr) {
                    cout << "Node belum tersedia. Harap buat node terlebih dahulu." << endl;
                    break;
                }
                cout << "\nTambahkan Node di:" << endl;
                cout << "1. Depan" << endl;
                cout << "2. Belakang" << endl;
                cout << "3. Tengah" << endl;
                cout << "4. Batal" << endl;
                cin >> choice;
                if (choice == 4) {
                    cout << "Batal" << endl;
                    break;
                }
                cout << "Masukkan nilai: ";
                cin >> data;
                if (choice == 1) {
                    insert_front(data);
                } else if (choice == 2) {
                    insert_back(data);
                } else if (choice == 3) {
                    cout << "Masukkan nilai setelah nilai: ";
                    cin >> after_data;
                    insert_middle(data, after_data);
                } else {
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                }
                break;
            case 3:
                cout << "\nHapus Node di:" << endl;
                cout << "1. Hapus node di depan" << endl;
                cout << "2. Hapus node di belakang" << endl;
                cout << "3. Hapus node di tengah" << endl;
                cout << "4. Batal" << endl;
                cin >> choice;
                if (choice == 4) {
                    cout << "Batal" << endl;
                    break;
                }
                if (choice == 1) {
                    delete_front();
                } else if (choice == 2) {
                    delete_back();
                } else if (choice == 3) {
                    cout << "Masukkan nilai node yang akan dihapus: ";
                    cin >> data;
                    delete_middle(data);
                } else {
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                }
                break;
            case 4:
                display();
                break;
            case 5:
                return;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
    }
};

int main() {
    SingleLinkedList sll;
    sll.menu();
    return 0;
}
