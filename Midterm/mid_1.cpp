#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

struct node{
    int val;
    node* next;
};typedef node* nd;

void init(nd &a){ a = NULL;}

void input(nd &a,int x){
    nd insert = new node;
    insert->val = x;
    insert->next = NULL;
    if(a==NULL) a = insert;
    else{
        nd p = a;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = insert;
    }
}

void readFile(string filename){
    ifstream fi(filename);
    if(fi.is_open()){
        int n;
        fi >> n;
        int a[n];
        for(int i = 0;i<n;i++){
            fi >> a[i];
        }
        for(int i = 0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << "\n";
        cout << "Doc file thanh cong" << endl;
        fi.close();
    }
    else cout << "Khong the mo file" << endl;
}

void process(nd a){
    if(a!=NULL){
        nd p = a;
        while(p!=NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    else cout << "Danh sach chua co phan tu " << endl;
}

void inputFromfile(nd &a,string fileName){
    ifstream fi(fileName);
    if(fi.is_open()){
        int n;
        fi >> n;
        int arr[n];
    for(int i = 0;i<n;i++){
        fi >> arr[i];
    }
    cout << "Them phan tu thanh cong " << endl;
    fi.close();
    for(int i = 0;i<n;i++){
        input(a,arr[i]);
    }
    }
    else cout << "Nhap du lieu khong thanh cong" << endl;
}

void selectionSortIncrease(vector<int> &v){
    for(int i = 0;i<v.size()-1;i++){
        int min = i;
        for(int j = i+1;j<v.size();j++){
            if(v[min] > v[j]){
                min = j;
            }
        }
        swap(v[min],v[i]);
    }
}

void selectionSortDecrease(vector<int> &v){
    for(int i = 0;i<v.size()-1;i++){
        int min = i;
        for(int j = i+1;j<v.size();j++){
            if(v[min] < v[j]){
                min = j;
            }
        }
        swap(v[min],v[i]);
    }
}


void insertionSort(vector<int> &v){
    for(int i = 1;i<v.size();i++){
        int j = i-1;
        int x = v[i];
        while(j>=0 && v[j] > x){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
}

void interchangeSort(vector<int> &v){
    for(int i = 0;i<v.size()-1;i++){
        for(int j = 0;j < v.size();j++){
            if(v[i] > v[j]) swap(v[i],v[j]);
        }
    }
}

void bubbleSort(vector<int> &v){
    for(int i = v.size()-1;i>=0;i--){
        for(int j = v.size()-2;j>=0;j--){
            if(v[i] < v[j]) swap(v[i],v[j]);
        }
    }
}

void mergeIncrease(vector<int> &v,int l,int m,int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> x(n1);
    vector<int> y(n2);

    for (int i = 0; i < n1; i++) {
        x[i] = v[l + i];
    }
    for (int j = 0; j < n2; j++) {
        y[j] = v[m + 1 + j];
    }
    int i = 0,j = 0,k = l;
    while(i<x.size() || j < y.size()){
        if(x[i] < y[j]){
            v[k] = x[i];
            i++;
        }
        else{
            v[k] = y[j];
            j++;
        }
        k++;
    }
    while(i<x.size()){
        v[k] = x[i];
        i++;k++;
    }
    while(j<y.size()){
        v[k] = y[j];
        j++;k++;
    }
}

void mergeDecrease(vector<int> &v,int l,int m,int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> x(n1);
    vector<int> y(n2);

    for (int i = 0; i < n1; i++) {
        x[i] = v[l + i];
    }
    for (int j = 0; j < n2; j++) {
        y[j] = v[m + 1 + j];
    }
    int i = 0,j = 0,k = l;
    while(i<x.size() || j < y.size()){
        if(x[i] > y[j]){
            v[k] = x[i];
            i++;
        }
        else{
            v[k] = y[j];
            j++;
        }
        k++;
    }
    while(i<x.size()){
        v[k] = x[i];
        i++;k++;
    }
    while(j<y.size()){
        v[k] = y[j];
        j++;k++;
    }
}

void mergeSortIncrease(vector<int> &v,int l,int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSortIncrease(v,l,m);
        mergeSortIncrease(v,m+1,r);
        mergeIncrease(v,l,m,r);
    }
}

void mergeSortDecrease(vector<int> &v,int l,int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSortDecrease(v,l,m);
        mergeSortDecrease(v,m+1,r);
        mergeDecrease(v,l,m,r);
    }
}

void sortIncrease(nd &a){
    vector<int> v;
    nd p = a;
    while(p!=NULL){
        v.push_back(p->val);
        p = p->next;
    }
    nd newList = new node;
    init(newList);
    selectionSortIncrease(v);
    for(auto x : v){
        input(newList,x);
    }
    while(a!=NULL) 
    {
        a = a->next;
    }
    a = newList;
}

void sortDecrease(nd &a){
    vector<int> v;
    nd p = a;
    while(p!=NULL){
        v.push_back(p->val);
        p = p->next;
    }
    nd newList = new node;
    init(newList);
    selectionSortDecrease(v);
    for(auto x : v){
        input(newList,x);
    }
    while(a!=NULL) {a = a->next;}
    a = newList;
}

void menu(){
    cout << "-----Chuong trinh quan ly so nguyen-----" << endl;
    cout << "[1] . Doc du lieu tu file" << endl;
    cout << "[2] . Them cac phan tu vao cuoi dslk" << endl;
    cout << "[3] . Xuat gia tri " << endl;
    cout << "[4] . Sap xep danh sach " << endl;
    cout << "[5] . Thoat" << endl;
    cout << "----------------------------------------" << endl;
    cout << "\n"; 
}
int main(){
    system("cls");
    nd list = new node;
    init(list);
    int choose;
    do
    {
        menu();
        cout << "Nhap lua chon cua ban : ";cin >> choose;
        while(choose < 1 || choose > 5){
            cout << "***Khong co lua chon phu hop***" << endl;
            cout << "Nhap lua chon cua ban : ";cin >> choose; 
        }
        switch (choose)
        {
        case 1:{
            system("cls");
            readFile("input.txt");
            break;
        }
        case 2:{
            system("cls");
            inputFromfile(list,"input.txt");
            break;
        }
        case 3:{
            system("cls");
            cout << "Danh sach hien tai" << endl;
            process(list);
            break;
        }
        case 4:{
            system("cls");
            int sortType;
            cout << "Chon kieu sap xep\n [1] . Tang dan \t [2] . Giam dan \n";
            cout << "Chon : ";cin >> sortType;
            while(sortType < 1 || sortType > 2){
                cout << "Error\n";
                cout << "Nhap lai : ";cin >> sortType;
            }
            if(sortType==1){
                sortIncrease(list);
                cout << "Danh sach sau khi sap xep tang dan " << endl;
                process(list);
            }
            else{
                sortDecrease(list);
                cout << "Danh sach sau khi sap xep giam dan " << endl;
                process(list);
            }
            break;
        }
        }
        if(choose==5) break;
    } while (choose >=1 && choose <=5);
    system("cls");
    cout << "Bye" << endl;
    return 0;
}