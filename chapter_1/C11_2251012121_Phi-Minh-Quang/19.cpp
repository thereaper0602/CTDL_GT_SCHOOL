#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <cstring>
using namespace std;

struct SinhVien
{
	string maSV;
	string hoTen;
	int namSinh;
	string diaChi;
	bool gioiTinh; //nam là true, nữ là false
	double diemTB;
};

struct Node
{
	SinhVien sv;
	Node* link;
};

void init(Node*& first); // Khởi tạo
void addSinhVien(Node*& first, SinhVien& sv); //Thêm 1 sinh viên vào đầu danh sách
void addDanhSachSv(Node*& first); //Thêm danh sách nhiều sinh viên bằng cơm
void addDanhSachSVFile(Node*& first); //Thêm danh sách sinh viên từ file
SinhVien tachThongTinSV(string& line); //Tách thông tin thành sstream để chuyển từ file zô
void process_list(Node* first); //Duyệt danh sách
void giaiPhongDanhSach(Node*& head); //Giải phóng bộ nhớ
Node* LocMaSV(Node* first, string maSV); //Lọc theo mã
void MenuLocSV(int& x); //Menu con
Node* LocHoten(Node* first, string maSV); //Lọc tên
bool containsSubstring(const string& mainString, const string& subString); //Check ký tự string này có tồn tại trong string kia không
Node* LocNamSinh(Node* first, int year); //Lọc theo năm sinh
Node* LocGioiTinh(Node* first, bool gt); //Lọc giới tính
void addSinhVienPoint(Node*& first, int x); //Thêm sinh viên vị trí bất kỳ
void arrangeMaSV(Node*& first); //Sắp xếp mã
void arrangeName(Node*& first); //Sắp xếp tên
void arrangeYear(Node*& first); //Sắp xếp năm sinh
void arrangeGioitinh(Node*& first); //Sắp xếp giới tính
void DeleteSinhVien(Node*& first, int x); //Xóa sinh viên vị trí bất kỳ
void GhiFile(Node* DS); //Lưu file
void SaveFileQuestion(Node* SaveF); //Hỏi nó có muốn lưu file không


int main()
{
	Node* first;
	int x, choose;
	init(first);
	do
	{
		system("cls");
		cout << "----------MENU----------\n"
			<< "1.Nhap danh sach sinh vien tu ban phim\n"
			<< "2.Xuat danh sach sinh vien\n"
			<< "3.Nhap danh sach sinh vien tu file\n"
			<< "4.Loc sinh vien theo yeu cau\n"
			<< "5.Them sinh vien vao vi tri bat ky\n"
			<< "6.Sap xep sinh vien theo yeu cau\n"
			<< "7.Xoa sinh vien theo vi tri yeu cau\n"
			<< "8.Luu file\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			addDanhSachSv(first);
			cout << "Xong!\n";
			break;
		}
		case 2:
		{
			cout << "Danh sach sinh vien\n--------------------\n";
			process_list(first);
			break;
		}
		case 3:
		{
			addDanhSachSVFile(first);
			cout << "Xong!\n";
			break;
		}
		case 4:
		{
			cout << "Ban muon loc sinh vien theo thong tin nao\n";
			MenuLocSV(x);
			switch (x)
			{
			case 1:
			{
				cout << "Nhap ma sinh vien can loc\n";
				string ma;
				cin >> ma;
				cout << "Cac sinh vien co ma sinh vien nhu yeu cau la\n";
				Node* filter = LocMaSV(first, ma);
				if (filter == NULL)
					cout << "None\n";
				else
				{
					process_list(filter);
					SaveFileQuestion(filter);
				}
				giaiPhongDanhSach(filter);
				break;
			}
			case 2:
			{
				cout << "Nhap ten sinh vien can loc\n";
				string name;
				cin.ignore();
				getline(cin, name);
				cout << "Cac sinh vien co ho ten nhu yeu cau la\n";
				Node* filter = LocHoten(first, name);
				if (filter == NULL)
					cout << "None\n";
				else
				{
					process_list(filter);
					SaveFileQuestion(filter);
				}
				giaiPhongDanhSach(filter);
				break;
			}
			case 3:
			{
				cout << "Nhap nam sinh can loc\n";
				int year;
				cin >> year;
				cout << "Cac sinh vien co nam sinh nhu yeu cau la\n";
				Node* filter = LocNamSinh(first, year);
				if (filter == NULL)
					cout << "None\n";
				else
				{
					process_list(filter);
					SaveFileQuestion(filter);
				}
				giaiPhongDanhSach(filter);
				break;
			}
			case 4:
			{
				cout << "Chon gioi tinh can loc(1.Nam 0.Nu)\n";
				bool gt;
				cin >> gt;
				cout << "Cac sinh vien co nam sinh nhu yeu cau la\n";
				Node* filter = LocGioiTinh(first, gt);
				if (filter == NULL)
					cout << "None\n";
				else
				{
					process_list(filter);
					SaveFileQuestion(filter);
				}
				giaiPhongDanhSach(filter);
				break;
			}
			default:
			{
				cout << "Ban khong chon loc cai nao\n";
				break;
			}
			}
			break;
		}
		case 5:
		{
			cout << "Nhap vi tri ban muon chen\n";
			cin >> x;
			addSinhVienPoint(first, x);
			break;
		}
		case 6:
		{
			cout << "Ban muon sap xep theo thong tin nao\n";
			MenuLocSV(x);
			switch (x)
			{
			case 1:
			{
				arrangeMaSV(first);
				SaveFileQuestion(first);
				break;
			}
			case 2:
			{
				arrangeName(first);
				SaveFileQuestion(first);
				break;
			}
			case 3:
			{
				arrangeYear(first);
				SaveFileQuestion(first);
				break;
			}
			case 4:
			{
				arrangeGioitinh(first);
				SaveFileQuestion(first);
				break;
			}
			default:
			{
				cout << "Ban khong chon dung phan\n";
				break;
			}
			}
			cout << "Xuat de kiem tra!\n";
			break;
		}
		case 7:
		{
			cout << "Nhap vi tri can xoa\n";
			cin >> x;
			DeleteSinhVien(first, x);
			break;
		}
		case 8:
		{
			GhiFile(first);
			break;
		}
		default:
		{
			break;
		}
		}
		_getch();
	} while (choose > 0 && choose <= 8);
	giaiPhongDanhSach(first);
	system("pause");
	return 0;
}

void init(Node*& first)
{
	first = NULL;
}

void addSinhVien(Node*& first, SinhVien& sv)
{
	Node* tempNode = new Node;
	tempNode->sv = sv;
	tempNode->link = first;
	first = tempNode;
}

void addDanhSachSv(Node*& first)
{
	int n;
	cout << "Nhap so luong sinh vien trong danh sach\n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		SinhVien sv;
		cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
		cout << "Nhap ma so sinh vien\n";
		cin >> sv.maSV;
		cout << "Nhap ho va ten sinh vien\n";
		cin.ignore();
		getline(cin, sv.hoTen);
		cout << "Nam sinh: ";
		cin >> sv.namSinh;
		cout << "Dia chi: ";
		cin.ignore();
		getline(cin, sv.diaChi);
		cout << "Gioi tinh (1: Nam, 0: Nu): ";
		cin >> sv.gioiTinh;
		cout << "Diem trung binh: ";
		cin >> sv.diemTB;

		addSinhVien(first, sv);
	}
}

void process_list(Node* first)
{
	Node* p = first;
	while (p != NULL)
	{
		cout << "Ma so sinh vien: " << p->sv.maSV << endl;
		cout << "Ho va ten: " << p->sv.hoTen << endl;
		cout << "Nam sinh " << p->sv.namSinh << endl;
		cout << "Dia chi: " << p->sv.diaChi << endl;
		cout << "Gioi tinh: " << (p->sv.gioiTinh ? "Nam " : "Nu ") << endl;
		cout << "Diem trung binh: " << p->sv.diemTB << endl;
		cout << "----------O_O----------\n";
		p = p->link;
	}
}

void giaiPhongDanhSach(Node*& head)
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current;
		current = current->link;
		delete temp;
	}
	head = nullptr;
}

SinhVien tachThongTinSV(string& line)
{
	string str;
	SinhVien sv;
	istringstream iss(line);
	getline(iss, sv.maSV, ',');
	getline(iss, sv.hoTen, ',');
	iss >> sv.namSinh;
	iss.ignore();
	getline(iss, sv.diaChi, ',');
	getline(iss, str, ',');
	str == "Nam" ? sv.gioiTinh = 1 : sv.gioiTinh = 0;
	iss >> sv.diemTB;
	iss.clear();
	return sv;
}

void addDanhSachSVFile(Node*& first)
{
	ifstream infile;
	infile.open("DanhsachSV.txt");
	if (!infile.is_open())
	{
		cout << "Khong the mo tap tin " << endl;
		return;
	}

	string line;
	while (getline(infile, line))
	{
		SinhVien sv = tachThongTinSV(line);
		addSinhVien(first, sv);
	}

	infile.close();

}

Node* LocMaSV(Node* first, string maSV)
{
	Node* Filter = NULL;
	Node* p = first;
	while (p != NULL)
	{
		SinhVien sv = p->sv;
		if (p->sv.maSV == maSV)
			addSinhVien(Filter, sv);
		p = p->link;
	}
	return Filter;
}

Node* LocHoten(Node* first, string name)
{
	Node* Filter = NULL;
	Node* p = first;
	while (p != NULL)
	{
		SinhVien sv = p->sv;
		if (containsSubstring(p->sv.hoTen, name))
		{
			addSinhVien(Filter, sv);
		}
		p = p->link;
	}
	return Filter;
}

Node* LocNamSinh(Node* first, int year)
{
	Node* Filter = NULL;
	Node* p = first;
	while (p != NULL)
	{
		SinhVien sv = p->sv;
		if (p->sv.namSinh == year)
			addSinhVien(Filter, sv);
		p = p->link;
	}
	return Filter;
}

Node* LocGioiTinh(Node* first, bool gt)
{
	Node* Filter = NULL;
	Node* p = first;
	while (p != NULL)
	{
		SinhVien sv = p->sv;
		if (p->sv.gioiTinh == gt)
			addSinhVien(Filter, sv);
		p = p->link;
	}
	return Filter;
}

void MenuLocSV(int& x)
{
	cout << "1. Ma sinh vien\n"
		<< "2. Ho va ten\n"
		<< "3. Nam sinh\n"
		<< "4. Gioi tinh\n";
	cin >> x;
	system("cls");
}

bool containsSubstring(const string& mainString, const string& subString) {
	return mainString.find(subString) != string::npos;
}

void addSinhVienPoint(Node*& first, int x)
{
	Node* p = first;
	Node* temp = new Node;
	Node* q = new Node;
	SinhVien sv;
	cout << "Nhap ma so sinh vien\n";
	cin >> sv.maSV;
	cout << "Nhap ho va ten sinh vien\n";
	cin.ignore();
	getline(cin, sv.hoTen);
	cout << "Nam sinh: ";
	cin >> sv.namSinh;
	cout << "Dia chi: ";
	cin.ignore();
	getline(cin, sv.diaChi);
	cout << "Gioi tinh (1: Nam, 0: Nu): ";
	cin >> sv.gioiTinh;
	cout << "Diem trung binh: ";
	cin >> sv.diemTB;
	q->sv = sv;
	if (p != NULL)
	{
		while (p != NULL && x > 1)
		{
			temp = p;
			p = p->link;
			x--;
		}
		q->link = p;
		temp->link = q;
	}
	else
	{
		q->link = first;
		first = q;
	}
}

void arrangeMaSV(Node*& first)
{
	Node* p = first;
	while (p != NULL)
	{
		Node* minNode = p;
		Node* temp = minNode->link;
		while (temp != NULL)
		{
			if (temp->sv.maSV < minNode->sv.maSV)
			{
				minNode = temp;
			}
			temp = temp->link;
		}
		if (minNode != p)
		{
			SinhVien changeTemp = p->sv;
			p->sv = minNode->sv;
			minNode->sv = changeTemp;
		}
		p = p->link;
	}
}

void arrangeName(Node*& first)
{
	Node* p = first;
	while (p != NULL)
	{
		Node* minNode = p;
		Node* temp = minNode->link;
		while (temp != NULL)
		{
			if (temp->sv.hoTen < minNode->sv.hoTen)
			{
				minNode = temp;
			}
			temp = temp->link;
		}
		if (minNode != p)
		{
			SinhVien changeTemp = p->sv;
			p->sv = minNode->sv;
			minNode->sv = changeTemp;
		}
		p = p->link;
	}
}

void arrangeYear(Node*& first)
{
	Node* p = first;
	while (p != NULL)
	{
		Node* minNode = p;
		Node* temp = minNode->link;
		while (temp != NULL)
		{
			if (temp->sv.namSinh < minNode->sv.namSinh)
			{
				minNode = temp;
			}
			temp = temp->link;
		}
		if (minNode != p)
		{
			SinhVien changeTemp = p->sv;
			p->sv = minNode->sv;
			minNode->sv = changeTemp;
		}
		p = p->link;
	}
}

void arrangeGioitinh(Node*& first)
{
	Node* p = first;
	while (p != NULL)
	{
		Node* minNode = p;
		Node* temp = minNode->link;
		while (temp != NULL)
		{
			if (temp->sv.gioiTinh < minNode->sv.gioiTinh)
			{
				minNode = temp;
			}
			temp = temp->link;
		}
		if (minNode != p)
		{
			SinhVien changeTemp = p->sv;
			p->sv = minNode->sv;
			minNode->sv = changeTemp;
		}
		p = p->link;
	}
}

void DeleteSinhVien(Node*& first, int x)
{
	Node* p = first;
	if (p == NULL)
	{
		cout << "Danh sach sinh vien rong\n";
		return;
	}

	while (p != NULL && x > 1)
	{
		x--;
		p = p->link;
	}

	if (x != 1)
		cout << "Vi tri ban chon khong co gi de xoa\n";
	else
	{
		if (p == first)
		{
			first = first->link;
			delete p;
		}
		else
		{
			Node* q = first;
			while (q->link != p)
			{
				q = q->link;
			}
			q->link = p->link;
			delete p;
		}
	}
}

void GhiFile(Node* DS)
{
	Node* p = DS;
	ofstream outfile;
	outfile.open("Ketqua.txt");
	if (outfile.is_open())
	{
		while (p != NULL)
		{
			outfile << p->sv.maSV << "," << p->sv.hoTen << "," << p->sv.namSinh << "," << p->sv.diaChi << "," << (p->sv.gioiTinh == 1 ? "Nam," : "Nu,") << p->sv.diemTB << endl;
			p = p->link;
		}
		cout << "Ghi file thanh cong\n";
	}
	outfile.close();
}

void SaveFileQuestion(Node* SaveF)
{
	_getch();
	system("cls");
	cout << "Ban co muon luu danh sach nay vao File?\nLuu(0)\nKhongLuu(Bam so bat ky)\n";
	bool Save;
	cin >> Save;
	if (!Save)
		GhiFile(SaveF);
	else
		return;
}