#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
class QuanLyHopDong {
private:
    struct HopDong {
        char maHD[20];
        char hoTen[50];
        char loaiHD[30];
        char ngayKy[11];
        char ngayHetHan[11];
        double luong;
        double phuCap;
    };
    HopDong a[100];
    int n;
public:
    // Ham tao
    QuanLyHopDong() {
        n = 0;
    }
    friend int timMa(QuanLyHopDong x, char ma[]);
    friend int soSanhNgay(QuanLyHopDong x, int i, int j);
    // HAM NHAP MANG
    void nhap() {
        cout << "Nhap so luong hop dong: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "\nNhap hop dong thu " << i + 1 << ":\n";
            cout << "Nhap ma hop dong: ";
            cin >> a[i].maHD;
            cout << "Nhap ho ten: ";
            cin.get();
            cin.getline(a[i].hoTen, 50);
            cout << "Nhap loai hop dong: ";
            cin >> a[i].loaiHD;
            cout << "Nhap ngay ky: ";
            cin >> a[i].ngayKy;
            cout << "Nhap ngay het han: ";
            cin >> a[i].ngayHetHan;
            cout << "Nhap luong: ";
            cin >> a[i].luong;
            cout << "Nhap phu cap: ";
            cin >> a[i].phuCap;
        }
    }
    // HAM XUAT MANG
    void xuat() {
        cout << "\n Danh sach hop dong:\n";
        for (int i = 0; i < n; i++) {
            cout << "\nHop dong thu " << i + 1 << ":\n";
            cout << "Ma HD: " << a[i].maHD << endl;
            cout << "Ho ten: " << a[i].hoTen << endl;
            cout << "Loai HD: " << a[i].loaiHD << endl;
            cout << "Ngay ky: " << a[i].ngayKy << endl;
            cout << "Ngay het han: " << a[i].ngayHetHan << endl;
            cout << "Luong: " << a[i].luong << endl;
            cout << "Phu cap: " << a[i].phuCap << endl;
        }
    }
    // HAM CHEN
    void chen() {
        int k;
        cout << "\nNhap vi tri can chen: ";
        cin >> k;
        if (k < 0 || k > n) {
            cout << "Vi tri chen khong hop le!\n";
            return;
        }
        // Dich cac phan tu sang phai
        for (int i = n; i > k; i--) {
            a[i] = a[i - 1];
        }
        cout << "\nNhap hop dong moi:\n";
        cout << "Nhap ma hop dong: ";
        cin >> a[k].maHD;
        cout << "Nhap ho ten: ";
        cin.get();
        cin.getline(a[k].hoTen, 50);
        cout << "Nhap loai hop dong: ";
        cin >> a[k].loaiHD;
        cout << "Nhap ngay ky: ";
        cin >> a[k].ngayKy;
        cout << "Nhap ngay het han: ";
        cin >> a[k].ngayHetHan;
        cout << "Nhap luong: ";
        cin >> a[k].luong;
        cout << "Nhap phu cap: ";
        cin >> a[k].phuCap;
        n++;
        cout << "Da chen thanh cong!\n";
    }
    // HAM XOA
    void xoa() {
        int k;
        cout << "\nNhap vi tri can xoa: ";
        cin >> k;
        if (k < 0 || k >= n) {
            cout << "Vi tri xoa khong hop le!\n";
            return;
        }
        // Dich cac phan tu sang trai
        for (int i = k; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;
        cout << "Da xoa thanh cong!\n";
    }
};
// HAM BAN TIM MA
 int timMa(QuanLyHopDong x, char ma[]) {
    for (int i = 0; i < x.n; i++) {
        if (strcmp(x.a[i].maHD, ma) == 0) {
            return i;
        }
    }
    return -1;
}
// HAM BAN SO SANH NGAy
int soSanhNgay(QuanLyHopDong x, int i, int j) {
    int d1, m1, y1;
    int d2, m2, y2;
    sscanf(x.a[i].ngayHetHan, "%d/%d/%d",&d1, &m1, &y1);
    sscanf(x.a[j].ngayHetHan, "%d/%d/%d", &d2, &m2, &y2);
    if (y1 > y2)
        return 1;
    if (y1 < y2)
        return 0;
    if (m1 > m2)
        return 1;
    if (m1 < m2)
        return 0;
    if (d1 > d2)
        return 1;
    return 0;
}
int main() {
    QuanLyHopDong ql;
    ql.nhap();
    ql.xuat();
    ql.chen();
    cout << "\n sau khi chen: \n";
    ql.xuat();
    ql.xoa();
    cout << "\n sau khi xoa: \n";
    ql.xuat();
    return 0;
}
