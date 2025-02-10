#include
using namespace std;
// đề bài: Nhập vào một cây nhịi phân các số nguyên. Xuất ra màn hình các phần tử của cây nhị phân
// khai báo cấu trúc 1 cái node
struct node
{
    int data; // dữ liệu c ủa node ==> dữ liệu mà node sẽ lưu trữ
    struct node *pLeft; // node liên kết bên trái của cây <=> cây con trái
    struct node *pRight; // node liên kết bên phải của cây <=> cây con phải
};
typedef struct node NODE;
typedef NODE* TREE;

// khởi tạo cây
void KhoiTaoCay(TREE &t)
{
    t = NULL; // cây rỗng 
}

// hàm thêm phần tử x vào cây nhị phân
void ThemNodeVaoCay(TREE &t , int x)
{
    // nếu cây rỗng 
    if(t == NULL)
    {
        NODE *p = new NODE; // khởi tạo 1 cái node để thêm vào cây
        p->data = x; // thêm dữ liệu x vào data
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p; // node p chính là node gốc <=> x chính là node gốc
    }
    else { // cây có tồn tại phần tử 
        // nếu phần tử thêm vào mà nhỏ hơn node gốc ==> thêm nó vào bên trái
        if(t->data  > x)
        {
            ThemNodeVaoCay(t->pLeft, x); // duyệt qua trái để thêm phần tử x
        }
        else if(t->data < x) // nếu phần tử thêm vào mà lớn hơn node gốc => thêm nó vào bên phải, dùng nhỏ hơn x để loại bỏ dấu bằng
        {
            ThemNodeVaoCay(t->pRight , x); // duyệt qua phải để thêm phần tử x
        }
    }
}

void Menu(TREE &t)
{
    while(true)
    {
        cout<<"/n/n/t/t ============ MENU =============";
        cout<<"/n1. Nhap du lieu";
        cout<<"/n2. Xuat du lieu cay";
        cout<<"/n3. Tim kiem phan tu trong cay: "
        cout<<"/n4. ket thuc";
        cout<<"/n/n/t/t ===============================";

        int luaChon;
        cout<<"\nNhap lua chon:";
        cin>>luaChon;
        if(luaChon < 0 || luaChon > 2)
        {
            cout<<"\nLua chon khong hop le";
            system("pause");
        } 
        else if(luaChon == 1)
        {
            int x;
            cout<< "\nNhap so nguyen x: ";
            cin>>x;
            ThemNodeVaoCay(t,x)
        }
        else if(luaChon == 2){
            cout<<"/n/t/t DUYET CAY THEP NLR\n";
            Duyet_NLR(t);
        }
        else if(luaChon == 3){
            int x;
            cout<<"\nNhap phan tu can tim kiem: ";
            cin>>x;
            NODE *p = TimKiem(t,x);
            if(p == NULL){
                cout << "\nPhan tu " << x << " Khong ton tai trong cay";
            }
            else
            {
                cout<< "\nPhan tu" << x << " co ton tai trong cay";
            }
            system("pause")
        }
        else {
            break;
        }
    }
}

// hàm xuất cây nhị phân theo NLR
void Duyet_NLR(TREE t)
{
    //nếu cây còn phần tử thì tiếp tục duyệt
    if(t != NULL)
    {
        cout<< t->data << " "; // xuất dl trong node
        Duyet_NLR(t->pLeft); // duyệt qua trái
        Duyet_NLR(t->pRight); // duyệt qua phải 
    }
}

NODE* TimKiem(TREE t, int x)
{
    if( t == NULL )
    {
        return NULL; 
    }
    else 
    {
        if( x < t -> data )
        {
            TimKiem(t->pLeft , x)
        } else if( x > t-> data)
        {
            TimKiem(t->pRight , x)
        } else  // t->data == x
        {
            return t; // node cần tìm kiếm là t 
        }
    }
}
int main()
{
    TREE t;
    KhoiTaoCay(t);
    Menu(t);
    system("pause");
}