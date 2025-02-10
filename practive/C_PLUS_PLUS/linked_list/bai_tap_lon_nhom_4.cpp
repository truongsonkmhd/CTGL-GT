#include <iostream>

using namespace std;

// Khai bao cau truc nut
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Ham them nut vào dau danh sach
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

// Ham them nut vao cuoi danh sach
void addToTail(Node *&pHead, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (pHead == NULL) {
        pHead = newNode;
    } else {
        Node* temp = pHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Ham them nut vao vi tri k
void addToMiddle(Node *&pHead, int value, int k) {
    if (k <= 0) {
        addToHead(pHead, value);
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    Node* temp = pHead;
    for (int i = 0; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        addToTail(pHead, value);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
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
        pHead = NULL; // neu chi co 1 node thi cho pHead = NULL
    }

    delete temp;
}

// Ham xoa nut thu k trong danh sach
void deleteNodeK(Node *&pHead, int k) {
    if (pHead == NULL || k < 0) {
        return;
    }

    Node* temp = pHead;
    for (int i = 0; i < k && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        pHead = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
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

// Ham tim kiem gia tri trong danh sach
void searchValue(Node* pHead, int value) {
    int position = 0;
    bool found = false;
    while (pHead != NULL) {
        if (pHead->data == value) {
            cout << "Gia tri " << value << " duoc tim thay o vi tri " << position << endl;
            found = true;
        }
        pHead = pHead->next;
        position++;
    }
    if (!found) {
        cout << "Gia tri " << value << " khong ton tai trong danh sach." << endl;
    }
}

int main() {
    Node* pHead = NULL;
    int choice;
    int value;
    int k;

    do {
        cout << "Menu:\n";
        cout << "1. Nhap vao mot danh sach\n";
        cout << "2. Hien thi toan bo danh sach\n";
        cout << "3. Dem so nut cua danh sach\n";
        cout << "4. Xoa nut cuoi cua danh sach\n";
        cout << "5. Xoa nut thu k trong danh sach\n";
        cout << "6. Bo sung mot nut moi vao dau danh sach\n";
        cout << "7. Tim va in ra cac nut chia 5 du 3 trong danh sach\n";
        cout << "8. Them nut vao dau danh sach\n";
        cout << "9. Them nut vao cuoi danh sach\n"; 
        cout << "10. Them nut vao vi tri thu k\n";
        cout << "11. Tim kiem node\n";
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
                cout << "Nhap vi tri can xoa (bat dau tu 0): ";
                cin >> k;
                deleteNodeK(pHead, k);
                cout << "Da xoa nut thu " << k << " cua danh sach.\n";
                break;
            case 6:
                cout << "Nhap gia tri can bo sung vao dau danh sach: ";
                cin >> value;
                addToHead(pHead, value);
                cout << "Da bo sung nut moi vao dau danh sach.\n";
                break;
            case 7:
                findAndPrintModuloNodes(pHead);
                break;
            case 8:
                cout << "Nhap gia tri can them vao dau danh sach: ";
                cin >> value;
                addToHead(pHead, value);
                cout << "Da them nut vao dau danh sach.\n";
                break;
            case 9:
                cout << "Nhap gia tri can them vao cuoi danh sach: ";
                cin >> value;
                addToTail(pHead, value);
                cout << "Da them nut vao cuoi danh sach.\n";
                break;
            case 10:
                cout << "Nhap gia tri can them vao danh sach: ";
                cin >> value;
                cout << "Nhap vi tri can them vao danh sach (bat dau tu 0): ";
                cin >> k;
                addToMiddle(pHead, value, k);
                cout << "Da them nut vao giua danh sach.\n";
                break;
            case 11:
                cout << "Nhap gia tri can tim kiem trong danh sach: ";
                cin >> value;
                searchValue(pHead, value);
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
