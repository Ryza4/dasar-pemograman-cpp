#include <iostream>
#include <string>
#include <cstdlib> // Untuk system("cls")
#include <algorithm> // Untuk sort()
#include <vector> // Untuk menyimpan data buku sementara
using namespace std;

struct Buku {
    string kategori;
    string judul;
    string pengarang;
    Buku* next;
    Buku* prev;
};

Buku *head = NULL, *tail = NULL, *n = NULL, *x = NULL;

void tambahBuku(string kategori, string judul, string pengarang) {
    n = new Buku;
    n->kategori = kategori;
    n->judul = judul;
    n->pengarang = pengarang;
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

void hapusBuku(string kategori, string judul) {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    Buku* temp = head;
    while (temp != NULL) {
        if (temp->kategori == kategori && temp->judul == judul) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            } else {
                tail = temp->prev;
            }

            delete temp;
            cout << "Buku dengan kategori '" << kategori << "' dan judul '" << judul << "' berhasil dihapus!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Buku tidak ditemukan!" << endl;
}

void cariBuku(string kataKunci) {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    Buku* temp = head;
    bool ditemukan = false;
    while (temp != NULL) {
        if (temp->kategori == kataKunci || temp->judul == kataKunci || temp->pengarang == kataKunci) {
            cout << "Kategori: " << temp->kategori << ", Judul: " << temp->judul << ", Pengarang: " << temp->pengarang << endl;
            ditemukan = true;
        }
        temp = temp->next;
    }
    if (!ditemukan) {
        cout << "Buku dengan kata kunci '" << kataKunci << "' tidak ditemukan!" << endl;
    }
}

void tampilkanListBerdasarkanKategori() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    string kategori;
    cout << "Masukkan kategori yang ingin ditampilkan: ";
    getline(cin, kategori);

    Buku* temp = head;
    while (temp != NULL) {
        if (temp->kategori == kategori) {
            cout << "Kategori: " << temp->kategori << ", Judul: " << temp->judul << ", Pengarang: " << temp->pengarang << endl;
        }
        temp = temp->next;
    }
}

void tampilkanListAscending() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    vector<Buku*> bukuList;
    Buku* temp = head;
    while (temp != NULL) {
        bukuList.push_back(temp);
        temp = temp->next;
    }

    sort(bukuList.begin(), bukuList.end(), [](Buku* a, Buku* b) { return a->judul < b->judul; });

    for (Buku* b : bukuList) {
        cout << "Kategori: " << b->kategori << ", Judul: " << b->judul << ", Pengarang: " << b->pengarang << endl;
    }
}

void tampilkanListDescending() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    vector<Buku*> bukuList;
    Buku* temp = head;
    while (temp != NULL) {
        bukuList.push_back(temp);
        temp = temp->next;
    }

    sort(bukuList.begin(), bukuList.end(), [](Buku* a, Buku* b) { return a->judul > b->judul; });

    for (Buku* b : bukuList) {
        cout << "Kategori: " << b->kategori << ", Judul: " << b->judul << ", Pengarang: " << b->pengarang << endl;
    }
}

int main() {
    int choice;
    string kategori, judul, pengarang, kataKunci;
    do {
        system("cls"); // Membersihkan layar setiap kali kembali ke menu utama
        cout << "Nama   : Rifky Fahreza" << endl;
        cout << "Stambuk: 13020230050" << endl;
        cout << "===================\n" << endl;
        cout << "Program Manajemen Perpustakaan" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Hapus Buku" << endl;
        cout << "3. Tampilkan List Data Buku Berdasarkan Kategori" << endl;
        cout << "4. Tampilkan List Data Buku Secara Ascending" << endl;
        cout << "5. Tampilkan List Data Buku Secara Descending" << endl;
        cout << "6. Cari Buku" << endl;
        cout << "7. Keluar" << endl;
        cout << "Masukkan pilihan [1..7]: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                system("cls");
                cout << "Masukkan Kategori: ";
                getline(cin, kategori);
                cout << "Masukkan Judul: ";
                getline(cin, judul);
                cout << "Masukkan Pengarang: ";
                getline(cin, pengarang);
                tambahBuku(kategori, judul, pengarang);
                system("pause");
                break;
            case 2:
                system("cls");
                cout << "Masukkan Kategori Buku yang akan dihapus: ";
                getline(cin, kategori);
                cout << "Masukkan Judul Buku yang akan dihapus: ";
                getline(cin, judul);
                hapusBuku(kategori, judul);
                system("pause");
                break;
            case 3:
                system("cls");
                tampilkanListBerdasarkanKategori();
                system("pause");
                break;
            case 4:
                system("cls");
                tampilkanListAscending();
                system("pause");
                break;
            case 5:
                system("cls");
                tampilkanListDescending();
                system("pause");
                break;
            case 6:
                system("cls");
                cout << "Masukkan kata kunci pencarian (kategori, judul, atau pengarang): ";
                getline(cin, kataKunci);
                cariBuku(kataKunci);
                system("pause");
                break;
            case 7:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 7);
    return 0;
}
