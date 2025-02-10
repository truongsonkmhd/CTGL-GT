/*
========================================= ĐỀ SỐ 04 =========================================
Viết chương trình xây dựng và quản lý danh sách liên kết đôi. Thành phần quản lý gồm
con trỏ pHead trỏ vào đầu danh sách. Trường info của các nút chứa giá trị nguyên.
Hiển thị menu thực hiện các chức năng sau (mỗi chức năng thực hiện bằng hàm).
1. Nhập vào một danh sách
2. Hiển thị toàn bộ danh sách
3. Đếm số nút của danh sách
4. Xóa nút cuối của danh sách
5. Bổ sung một nút mới với thông tin x vào đầu danh sách
6. Tìm và in ra các nút chia 5 dư 3 trong danh sách.
*/

#include <iostream>

using namespace std;

// Khai báo cấu trúc nút
struct Node {
    int data;
    Node* prev;
    Node* next;
};


// Ham them nut vào đau danh sach(Ham nhap vao 1 danh sach)
void addToHead(Node *&pHead, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = pHead;

    if (pHead != NULL) {
        pHead->prev = newNode;
    }

    pHead = newNode;
}

// Ham hien thi toan bo danh sach
void displayList(Node* pHead) {
    cout << "Danh sach: ";
    while (pHead != NULL) {
        cout << pHead->data << " ";
        pHead = pHead->next;
    }
    cout << endl;
}

// ham dem so nut cua danh sach
int countNodes(Node* pHead) {
    int count = 0;
    while (pHead != NULL) {
        count++;
        pHead = pHead->next;
    }
    return count;
}

// Ham xoa node cuoi cua danh sach
void deleteLastNode(Node *&pHead) {
    if (pHead == NULL) {
        return;
    }

    Node* temp = pHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        pHead = NULL;
    }

    delete temp;
}

// Ham tim va in ra cac nut chia 5 du 3 trong danh sach
void findAndPrintModuloNodes(Node* pHead) {
    cout << "Cac nut chia 5 du 3: ";
    while (pHead != NULL) {
        if (pHead->data % 5 == 3) {
            cout << pHead->data << " ";
        }
        pHead = pHead->next;
    }
    cout << endl;
}

int main() {
    Node* pHead = NULL;
    int choice;
    int value;

    do {
        cout << "Menu:\n";
        cout << "1. Nhap vao mot danh sach\n";
        cout << "2. Hien thi toan bo danh sach\n";
        cout << "3. Dem so nut cua danh sach\n";
        cout << "4. Xoa nut cuoi cua danh sach\n";
        cout << "5. Bo sung mot nut moi vao dau danh sach\n";
        cout << "6. Tim va in ra cac nut chia 5 du 3 trong danh sach\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap vao mot danh sach. Nhap -1 de ket thuc.\n";
                while (true) {
                    cout << "Nhap gia tri: ";
                    cin >> value;
                    if (value == -1) {
                        break;
                    }
                    addToHead(pHead, value);
                }
                break;
            case 2:
                displayList(pHead);
                break;
            case 3:
                cout << "So nut cua danh sach: " << countNodes(pHead) << endl;
                break;
            case 4:
                deleteLastNode(pHead);
                cout << "Da xoa nut cuoi cua danh sach.\n";
                break;
            case 5:
                cout << "Nhap gia tri can bo sung vao dau danh sach: ";
                cin >> value;
                addToHead(pHead, value);
                cout << "Da bo sung nut moi vao dau danh sach.\n";
                break;
            case 6:
                findAndPrintModuloNodes(pHead);
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 0);

    return 0;
}