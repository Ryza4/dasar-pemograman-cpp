#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Fungsi untuk membersihkan layar
void clearScreen() {
    system("cls");
}

// Struktur untuk node
struct Node {
    string data;
    Node* next;
};

// Kelas untuk mengelola linked list
class LinkedList {
private:
    Node* head;
    string lastDeleted;

public:
    LinkedList() {
        head = NULL;
        lastDeleted = "";
    }

    void insertFront(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertBack(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteFront() {
        if (head == NULL) {
            cout << "List kosong!" << endl;
            return;
        }

        Node* temp = head;
        lastDeleted = temp->data;
        head = head->next;
        delete temp;
    }

    void display() {
        clearScreen();
        if (head == NULL) {
            cout << "List kosong!" << endl;
            return;
        }

        cout << "\n=== DATA LIST ===" << endl;
        Node* temp = head;
        int index = 1;
        while (temp != NULL) {
            cout << "Data ke-" << index << ": " << temp->data << endl;
            temp = temp->next;
            index++;
        }

        if (lastDeleted != "") {
            cout << "\nData yang terakhir dihapus: " << lastDeleted << endl;
        }
    }

    bool isEmpty() {
        return head == NULL;
    }
};

class StackQueue {
private:
    LinkedList list;
    bool firstNodeCreated;

public:
    StackQueue() : firstNodeCreated(false) {}

    void mainMenu() {
        int choice;
        do {
            clearScreen();
            cout << "\n=== MENU UTAMA ===" << endl;
            cout << "1. Create First Node" << endl;
            cout << "2. Stack" << endl;
            cout << "3. Queue" << endl;
            cout << "4. Exit" << endl;
            cout << "Pilihan: ";
            
            if (!(cin >> choice)) {
                cout << "Input tidak valid! Masukkan angka 1-4." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                system("pause");
                continue;
            }

            switch (choice) {
                case 1:
                    createFirstNode();
                    break;
                case 2:
                    stackMenu();
                    break;
                case 3:
                    queueMenu();
                    break;
                case 4:
                    clearScreen();
                    cout << "Program selesai!" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    system("pause");
            }
        } while (choice != 4);
    }

private:
    void stackMenu() {
        if (list.isEmpty() && !firstNodeCreated) {
            clearScreen();
            cout << "Buat node pertama terlebih dahulu!" << endl;
            system("pause");
            return;
        }

        int choice;
        do {
            clearScreen();
            cout << "\n=== MENU STACK ===" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Display" << endl;
            cout << "4. Kembali ke Menu Utama" << endl;
            cout << "Pilihan: ";
            
            if (!(cin >> choice)) {
                cout << "Input tidak valid! Masukkan angka 1-4." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                system("pause");
                continue;
            }

            cin.ignore();

            switch (choice) {
                case 1:
                    {
                        clearScreen();
                        string value;
                        cout << "Masukkan nilai: ";
                        getline(cin, value);
                        list.insertFront(value);
                        cout << "Data berhasil ditambahkan!" << endl;
                        system("pause");
                    }
                    break;
                case 2:
                    clearScreen();
                    list.deleteFront();
                    cout << "Data berhasil dihapus!" << endl;
                    system("pause");
                    break;
                case 3:
                    list.display();
                    system("pause");
                    break;
                case 4:
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    system("pause");
            }
        } while (choice != 4);
    }

    void queueMenu() {
        if (list.isEmpty() && !firstNodeCreated) {
            clearScreen();
            cout << "Buat node pertama terlebih dahulu!" << endl;
            system("pause");
            return;
        }

        int choice;
        do {
            clearScreen();
            cout << "\n=== MENU QUEUE ===" << endl;
            cout << "1. Enqueue" << endl;
            cout << "2. Dequeue" << endl;
            cout << "3. Display" << endl;
            cout << "4. Kembali ke Menu Utama" << endl;
            cout << "Pilihan: ";
            
            if (!(cin >> choice)) {
                cout << "Input tidak valid! Masukkan angka 1-4." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                system("pause");
                continue;
            }

            cin.ignore();

            switch (choice) {
                case 1:
                    {
                        clearScreen();
                        string value;
                        cout << "Masukkan nilai: ";
                        getline(cin, value);
                        list.insertBack(value);
                        cout << "Data berhasil ditambahkan!" << endl;
                        system("pause");
                    }
                    break;
                case 2:
                    clearScreen();
                    list.deleteFront();
                    cout << "Data berhasil dihapus!" << endl;
                    system("pause");
                    break;
                case 3:
                    list.display();
                    system("pause");
                    break;
                case 4:
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    system("pause");
            }
        } while (choice != 4);
    }

    void createFirstNode() {
        clearScreen();
        if (firstNodeCreated) {
            cout << "Node pertama sudah dibuat sebelumnya!" << endl;
            system("pause");
            return;
        }
        string value;
        cout << "Masukkan nilai untuk node pertama: ";
        cin.ignore();
        getline(cin, value);
        list.insertFront(value);
        firstNodeCreated = true;
        cout << "Node pertama berhasil dibuat!" << endl;
        system("pause");
    }
};

int main() {
    StackQueue program;
    program.mainMenu();
    return 0;
}