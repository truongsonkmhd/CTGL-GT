#include <iostream>

using namespace std;

typedef struct Node
{
    int data; // dữ liệu chứa trong 1 cái node
    struct Node* next; // Con trỏ dùng để liên kết giữa các node với nhau
} Node;

// Hàm khởi tạo một node mới
Node* khoiTaoNode(int x)
{
    Node* newNode = new Node();
    if (newNode == NULL)
    {
        cout << "\nKhong du bo nho de cap phat !";
        return NULL;
    }

    newNode->data = x; // gán x cho data
    newNode->next = NULL;
    return newNode;
}

// Hàm duyệt và xuất danh sách liên kết đơn
void duyet(Node* pHead)
{
    while (pHead != NULL)
    {
        cout << pHead->data << " ";
        pHead = pHead->next;
    }
}


// Hàm đếm số lượng node trong danh sách liên kết đơn
int count(Node* pHead)
{
    int dem = 0;
    while (pHead != NULL)
    {
        ++dem;
        pHead = pHead->next;
    }
    return dem;
}

// Hàm chèn một node vào đầu danh sách liên kết đơn
void InsertFirstForAll(Node **pHead, int x)
{
    Node* newNode = khoiTaoNode(x); // mot con trỏ mới
    // buoc1: Phan next cua newNode => head
    newNode->next = *pHead; // dia chi cua node head trong dslk
    // buoc2: cap nhat node head (cho con trỏ mới gán vào pHead)
    *pHead = newNode;
}

void InsertFirstForCcongcong(Node *&pHead, int x)// c ko dung dc vi không tham chiếu được
{
    Node *newNode = khoiTaoNode(x); 
    newNode->next = pHead; 
    pHead = newNode;
}

void InsertLastForAll(Node **head , int x)
{
    Node *newNode = khoiTaoNode(x);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void InsertLastForCcongcong(Node *&pHead, int x)
{
    Node *newNode = khoiTaoNode(x);
    if (pHead == NULL)
    {
        pHead = newNode;
        return;
    }
    Node *temp = pHead;
    while (temp->next != NULL) //  duyệt đến node cuối
    {
        temp = temp->next;
    }
    // nối vào cuối danh sách
    temp->next = newNode;
}

void InsertAny(Node **pHead, int k , int x){ 
    int n = count(*pHead);
    if(k < 1 || k > n){
        cout<<"Vi tri chen khong hop le !\n";
        return;
    }

    if(k == 1){
        InsertFirstForAll(pHead , x) ; return;
    }

    Node *temp = *pHead;
    for(int i = 1; i < k - 2 ; i++){ // duyệt để đến vtri k - 1
        temp = temp->next; // địa chỉ của node k(temp->next = value của node k - 1)
    }
    //temp : k - 1
    Node *newNode = khoiTaoNode(x);
    newNode->next = temp->next; // gán value của newNode  = địa chỉ của temp 
    temp->next = newNode; // gán value của newNode = địa chỉ của  temp - 1
}

void deleteFirst(Node **pHead){
    if(*pHead == NULL) return;
    Node *temp = *pHead;
    *pHead = (*pHead)->next; // Fix this line
    delete temp;
}

void deleteLast(Node **pHead){
    if(*pHead == NULL) return;
    Node *temp = *pHead;
    if(temp->next == NULL) //check TH dslk có 1 nút để bên dưới có thể thực thi temp->next->next 
    {
        *pHead = NULL;
        delete temp;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node *last = temp->next; 
    temp->next = NULL;
    delete last;
}

void deleteCenter(Node **head, int k){
    int n = count(*pHead);
    if(k < 1 || k > n) return; // ko xoá
    if( k == 1) deleteFirst(head);
    else{
        Node *temp = *head;
        for(int i = 1; i <= k - 2 ; i++) // duyện đến phần tử k - 1 thì dừng
        {
            temp = temp->next; // node thu k -1
        }
        // temp: k - 1
        Node *kth = temp->next; // node thu k
        // cho k - 1 => kết nối với node thứ k + 1
        temp->next = kth->next;
        delete kth;
    }
}
int main()
{
    Node *head = NULL;

    while(1){
        cout<< "==============================================\n";
        cout<< "1. Them vao dau\n";
        cout<< "2. Them vao cuoi\n";
        cout<< "3. Them vao giua\n";
        cout<< "4. Xoa phan tu dau\n";
        cout<< "5. Xoa phan tu cuoi\n";
        cout<< "6. Xoa phan tu giua\n";
        cout<< "7. Duyet\n";
        cout<< "0. Thoat !\n";
        cout<< "==============================================\n";
        cout<< "Nhap lua chon: ";
        int lc; cin>>lc;
        if(lc == 1){
            int x ; cout << "Nhap x :" ; cin>>x;
            InsertFirstForCcongcong(head , x);
        } else if(lc == 2){
            int x; cout<<"Nhap x :"; cin>>x;
            InsertLastForCcongcong(head , x);
        } else if(lc == 3) {
            int x; cout<<"Nhap x :"; cin>>x;
            int k; cout<<"Nhap k :"; cin>>k;
            InsertAny(&head ,k , x);
        } else if(lc == 4) {
            deleteFirst(&head);
        } else if(lc == 5) {
            deleteLast(&head);
        } else if(lc == 6) {
            int k; cout<<"Nhap k :"; cin>>k;
            deleteCenter(&head , k);
        } else if(lc == 7) {
            duyet(head);
            cout << endl;
        } else {
            break;
        }
    }
    return 0;
}