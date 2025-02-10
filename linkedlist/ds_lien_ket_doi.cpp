#include <iostream>

using namespace std;

// Khai báo cấu trúc nút
struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* makeNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

int count(Node* pHead) {
    int dem = 0;
    while (pHead != nullptr) {
        ++dem;
        pHead = pHead->next;
    }
    return dem;
}

// Thêm 1 phần tử vào đầu
void addToHead(Node *&pHead, int value) {
    Node* newNode = makeNode(value);

    if (pHead != nullptr) {
        pHead->prev = newNode;
        newNode->next = pHead;
    }

    pHead = newNode;
}

void addToLast(Node *&pHead, int value) {
    Node* newNode = makeNode(value);
    if (pHead == nullptr) {
        pHead = newNode;
        return;
    }

    Node* temp = pHead;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void addToCenter(Node *&pHead, int value, int k) {
    int n = count(pHead);
    if (k < 1 || k > n + 1) {
        cout << "Vi tri chen khong hop le!\n";
        return;
    }

    if (k == 1) {
        addToHead(pHead, value);
        return;
    }

    Node* temp = pHead;
    for (int i = 1; i < k - 1; i++) {
        temp = temp->next;
    }

    Node* newNode = makeNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Hàm để in danh sách liên kết
void printList(Node* pHead) {
    Node* temp = pHead;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Hàm main để kiểm tra các chức năng
int main() {
    Node* pHead = nullptr;

    addToHead(pHead, 1);
    addToHead(pHead, 2);
    addToHead(pHead, 3);
    addToLast(pHead, 4);
    addToLast(pHead, 5);

    cout << "Danh sach lien ket sau khi them vao dau va cuoi: ";
    printList(pHead);

    addToCenter(pHead, 6, 3);
    cout << "Danh sach lien ket sau khi them vao vi tri thu 3: ";
    printList(pHead);

    return 0;
}
