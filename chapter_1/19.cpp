#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct sinhVien
{
    string maSv, hoTen, diaChi;
    int namSinh;
    bool gioiTinh;
    double diemTB;
    sinhVien *next;
};
typedef sinhVien *sv;



void init(sv &a)
{
    a = NULL;
}

void keyboard(sv &a)
{
    string maSv, hoTen, diaChi;
    int namSinh;
    bool gioiTinh;
    double diemTB;
    cout << "Input ID : ";
    cin >> maSv;
    cin.ignore();
    cout << "Name : ";
    getline(cin, hoTen);
    cout << "Address : ";
    getline(cin, diaChi);
    cout << "Year born : ";
    cin >> namSinh;
    int gender;
    cout << "Choose your gender : " << endl;
    cout << "[1] . Male \t\t [2]. Female" << endl;
    cin >> gender;
    while (gender != 1 && gender != 2)
    {
        cout << "Error" << endl;
        cout << "Input again : ";
        cout << "[1] . Male \t\t [2]. Female" << endl;
        cin >> gender;
    }
    gioiTinh = true ? gender == 1 : gender == 2;
    cout << "GPA : ";
    cin >> diemTB;
    sv insert = new sinhVien;
    insert->maSv = maSv;
    insert->hoTen = hoTen;
    insert->diaChi = diaChi;
    insert->namSinh = namSinh;
    insert->gioiTinh = gioiTinh;
    insert->diemTB = diemTB;
    insert->next = NULL;
    if (a == NULL)
    {
        a = insert;
    }
    else
    {
        sv p = a;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = insert;
    }
}

void create(sv &a, string maSv,string hoTen,string diaChi,int namSinh,bool gioiTinh,double diemTB)
{
    sv insert = new sinhVien;
    insert->maSv = maSv;
    insert->hoTen = hoTen;
    insert->diaChi = diaChi;
    insert->namSinh = namSinh;
    insert->gioiTinh = gioiTinh;
    insert->diemTB = diemTB;
    insert->next = NULL;
    if (a == NULL)
    {
        a = insert;
    }
    else
    {
        sv p = a;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = insert;
    }
}


void fileTXT_2(sv &a, string filename)
{
    ifstream fi(filename);
    if (fi.is_open())
    {
        string line;
        while (getline(fi, line))
        {
            istringstream iss(line);
            string maSv, hoTen, diaChi;
            int namSinh, gender;
            double diemTB;
            bool gioiTinh;

            // Phân tách thông tin bằng dấu '#'
            getline(iss, maSv, '#');
            getline(iss, hoTen, '#');
            getline(iss, diaChi, '#');
            iss >> namSinh;
            iss.ignore();
            iss >> gender;
            gender = 1 ? gioiTinh = true : gioiTinh = false;
            iss.ignore();
            iss >> diemTB;
            
            // Kiểm tra nếu việc đọc giá trị diemTB thành công
            if (!iss.fail())
            {
                create(a,maSv,hoTen,diaChi,namSinh,gioiTinh,diemTB);
            }
            iss.ignore('\n');
        }
        fi.close();
    }
}


void process(sv a)
{
    sv p = a;
    while (p != NULL)
    {
        cout << "ID : " << p->maSv << endl;
        cout << "Name : " << p->hoTen << endl;
        cout << "Address : " << p->diaChi << endl;
        cout << "Born on : " << p->namSinh << endl;
        cout << "Gender : ";
        if (p->gioiTinh == true)
            cout << "Male" << endl;
        else
            cout << "Female " << endl;
        cout << "GPA : " << p->diemTB << endl;
        p = p->next;
    }
    cout << endl;
}

void freeMemory(sv &a)
{
    while (a != NULL)
    {
        sv temp = a;
        a = a->next;
        delete temp;
    }
}




void traversal(sv a)
{
    int n;
    cout << "[1] . Sort by name " << endl;
    cout << "[2] .Sort by ID " << endl;
    cout << "[3] .Sort by year " << endl;
    cout << "[4] .Sort by address " << endl;
    cout << "[5] .Sort by GPA " << endl;
    cout << "Choose one option : ";
    cin >> n;
    while (n < 1 || n > 5)
    {
        cout << "Error" << endl;
        cout << "Choose your option : ";
        cin >> n;
    }
    switch (n)
    {
    case 1:
    {
        int i = 1;
        sv p = a;
        while (p != NULL)
        {
            cout << i << " . " << p->hoTen << endl;
            i++;
            p = p->next;
        }
        break;
    }
    case 2:
    {
        int i = 1;
        sv p = a;
        while (p != NULL)
        {
            cout << i << " . " << p->maSv << endl;
            i++;
            p = p->next;
        }
        break;
    }
    case 3:
    {
        int i = 1;
        sv p = a;
        while (p != NULL)
        {
            cout << i << " . " << p->namSinh << endl;
            i++;
            p = p->next;
        }
        break;
    }
    case 4:
    {
        int i = 1;
        sv p = a;
        while (p != NULL)
        {
            cout << i << " . " << p->diaChi << endl;
            i++;
            p = p->next;
        }
        break;
    }
    case 5:
    {
        int i = 1;
        sv p = a;
        while (p != NULL)
        {
            cout << i << " . " << p->diemTB << endl;
            i++;
            p = p->next;
        }
        break;
    }
    }
}

int count(sv a)
{
    sv p = a;
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

void insertPos(sv &a)
{
    int pos;
    cout << "Input the position you want to insert : ";
    cin >> pos;
    while (pos < 0 || pos > count(a) + 1)
    {
        cout << "Error" << endl;
        cout << "Input the position you want to insert : ";
        cin >> pos;
    }
    string maSv, hoTen, diaChi;
    int namSinh;
    bool gioiTinh;
    double diemTB;
    cout << "Input ID : ";
    cin >> maSv;
    cin.ignore();
    cout << "Name : ";
    getline(cin, hoTen);
    cout << "Address : ";
    getline(cin, diaChi);
    cout << "Year born : ";
    cin >> namSinh;
    int gender;
    cout << "Choose your gender : " << endl;
    cout << "[1] . Male \t\t [2]. Female" << endl;
    cin >> gender;
    while (gender != 1 && gender != 2)
    {
        cout << "Error" << endl;
        cout << "Input again : ";
        cout << "[1] . Male \t\t [2]. Female" << endl;
        cin >> gender;
    }
    gioiTinh = true ? gender == 1 : gender == 2;
    cout << "GPA : ";
    cin >> diemTB;
    sv insert = new sinhVien;
    insert->maSv = maSv;
    insert->hoTen = hoTen;
    insert->diaChi = diaChi;
    insert->namSinh = namSinh;
    insert->gioiTinh = gioiTinh;
    insert->diemTB = diemTB;
    insert->next = NULL;
    if (a == NULL)
    {
        a = insert;
    }
    else
    {
        sv p = a;
        sv q = NULL;
        int i = 1;
        while (p != NULL && i < pos)
        {
            i++;
            q = p;
            p = p->next;
        }
        q->next = insert;
        insert->next = p;
    }
}

void delete_sv(sv &a)
{
    if (a != NULL)
    {
        string id;
        cout << "Input the student's id to delete : ";
        cin >> id;
        sv p = a;
        sv q = NULL;
        while (p != NULL && p->maSv != id)
        {
            q = p;
            p = p->next;
        }
        if (q == NULL)
        {
            a = a->next;
        }
        else if (p == NULL)
        {
            q->next = NULL;
        }
        else
        {
            q->next = p->next;
        }
        delete p;
    }
}

int main()
{
    system("cls");
    sv a = new sinhVien;
    init(a);
    int choose;
    do
    {
        cout << "Chon cach thuc nhap thong tin " << endl;
        cout << "[1] . Nhap tu ban phim\t[2]. Nhap tu file txt\t[3].Thoat" << endl; 
        cin >> choose;
        if (choose==1)
        {
            keyboard(a);
            process(a);
        }
        else if(choose==2)
        {
            fileTXT_2(a, "SinhVien.txt");
            process(a);
        }
        else if(choose==3)
        {
            break;
        }
        
    } while (choose>=1 && choose<=3);

    
    return 0;
}