// NhanVien.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// tao lop nhan vien
class NhanVien {
private:
    // thanh phan du lieu/dac trung/thuoc tinh
    string hoTen, doB, queQuan;
    bool gioiTinh;
    int luong;
public:
    // ham thanh phan
    // ham tao khong tham so -- khoi tao gia tri cho doi tuong
    NhanVien() {
        hoTen = "";
        doB = "01/01/1954";
        gioiTinh = true;
        luong = 0;
        queQuan = "";
    }
    // ham tao co tham so -- khoi tao gia tri cho doi tuong
    NhanVien(string hoTen, string doB, string queQuan, bool gioiTinh, int luong) {
        this->hoTen = hoTen;
        this->doB = doB;
        this->queQuan = queQuan;
        this->gioiTinh = gioiTinh;
        this->luong = luong;
    }

    // ham huy
    ~NhanVien() {

    }
    /// Ham NHap DU lieu
    // cach 1: viet ham nhap
    void nhapDL();
    // cach 2: viet toan tu nhap
    friend istream& operator>>(istream& is, NhanVien &nv);
    /// ham hien thi
    // Cach 1: Viet ham hien thi
    void hienThi();
    // Cach 2: Viet toan tu xuat du lieu
    friend ostream& operator<<(ostream& out, NhanVien& nv);

    // ham lay thong tin ve que quan
    string getQueQuan() {
        return queQuan;// tra ve gia tri que quan
    }
    // ham lay thong tin ve luong
    int getLuong() {
        return luong;// tra ve gia tri luong
    }

    // dinh nghia toan tu so sanh 2 nhan vien qua gia tri ve luong
    bool operator>(NhanVien x);

};
// trien khai ham nhap du lieu
void NhanVien::nhapDL() {
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay thang nam sinh: ";
    cin >> doB;
    cout << "Nhap gioi tinh 0-Nam, 1-Nu: ";
    string gt;
    cin >> gt;
    cin.ignore();
    if (gt == "Nam" || gt == "nam") {
        gioiTinh = false;
    }
    else {
        gioiTinh = true;
    }
    cout << "Nhap que quan: ";
    getline(cin, queQuan);
    cout << "Nhap luong: ";
    cin >> luong;
}
// trien khai toan tu nhap du  lieu
istream& operator>>(istream& is, NhanVien& nv) {
    is.ignore();
    cout << "Nhap ho ten: ";
    getline(is, nv.hoTen);
    cout << "Nhap ngay thang nam sinh: ";
    is >> nv.doB;
    cout << "Nhap gioi tinh 0-Nam, 1-Nu: ";
    string gt;
    cin >> gt;
    cin.ignore();
    if (gt == "Nam" || gt == "nam") {
        nv.gioiTinh = false;
    }
    else {
        nv.gioiTinh = true;
    }
    cout << "Nhap que quan: ";
    getline(is, nv.queQuan);
    cout << "Nhap luong: ";
    is >> nv.luong;
    return is;
}

//ham hien thi
void NhanVien::hienThi() {
    cout << "\nHo ten: " << hoTen;
    cout << "\tNgay thang nam sinh : " << doB;
    cout << "\tGioi tinh: " << gioiTinh;
    cout << "\tQue quan: " << queQuan;
    cout << "\tLuong: " << luong;
}

ostream& operator<<(ostream& out, NhanVien& nv) {
    out << "\nHo ten: " << nv.hoTen;
    out << "\tNgay thang nam sinh : " << nv.doB;
    out << "\tGioi tinh: " << nv.gioiTinh;
    out << "\tQue quan: " << nv.queQuan;
    out << "\tLuong: " << nv.luong;
    return out;
}

//ham toan tu so sanh
bool NhanVien::operator>(NhanVien x) {
    if (this->luong > x.luong) {
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    /*
    NhanVien nv;
    //nv.nhapDL();
    cin >> nv;//operator>>(cin, nv);// goi ham
    //nv.hienThi();
    cout << nv;// operator<<(cout, nv)// goi ham
    */
    
    NhanVien dsNV[100];
    int n;// so nhan vien
    cout << "Nhap so nhan vien can quan ly: ";
    cin >> n;
    //1. Nhap du lieu cho n nhan vien
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << "\n";
        //cin >> dsNV[i];// c1: su dung toan tu
        dsNV[i].nhapDL();// c2: goi ham
    }

    // 2. Hien thi nhan vien co que Ha Noi
    // duyet tat ca cac nhan vien
    cout << "Cac nhan vien co que o Ha Noi la: ";
    for (int i = 0; i < n; i++) {
        // kiem tra nhan vien co que o HN ko
        if (dsNV[i].getQueQuan() == "Ha Noi") {
            cout << dsNV[i];//c1: su dung toan tu
            //dsNV[i].hienThi();//c2: goi ham
        }
    }

    // 3. Tính và đưa ra trung bình cộng lương của các nhân viên
    int tongLuong = 0;
    for (int i = 0; i < n; i++) {
        tongLuong += dsNV[i].getLuong();
    }
    cout << "Trung binh luong cua nhan vien la: " << float(tongLuong) / n;//2 -- 10/3=3.3333

    // 4. Sap xep thong thuong
    /*
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dsNV[i].getLuong() > dsNV[j].getLuong()) {
                NhanVien tg;
                tg = dsNV[i];
                dsNV[i] = dsNV[j];
                dsNV[j] = tg;
            }
        }
    }
    */
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dsNV[i] > dsNV[j]) {// or goi ham: dsNV[i].operator>(dsNV[j])
                NhanVien tg;
                tg = dsNV[i];
                dsNV[i] = dsNV[j];
                dsNV[j] = tg;
            }
        }
    }
    cout << "\nDanh sach nhan vien duoc sap xep theo ko giam ve luong la\n";
    for (int i = 0; i < n; i++) {
        dsNV[i].hienThi();//c2: goi ham
    }

    //
    return 0;
}