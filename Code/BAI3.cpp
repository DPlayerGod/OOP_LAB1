#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tu; 
    int mau;

public:
    PhanSo() {
        tu = 0;
        mau = 1;
    }

    PhanSo(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
    }

    void nhap() {
        // Ham nhap phan so
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;

        while (mau == 0) {
            cout << "Mau so khong hop le. Vui long nhap lai mau so: ";
            cin >> mau;
        }
    }

    void xuat() const {
        // ham xuat phan so
        if (mau == 1) {
            cout << tu;
            return;
        }
        cout << tu << "/" << mau;
    }

    void rutGon() {
        // ham rut gon phan so
        int ucln = timUCLN(tu, mau);
        tu /= ucln;
        mau /= ucln;
    }

    int timUCLN(int a, int b) {
        // ham tim uoc chung lon nhat cua va b
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    PhanSo cong(const PhanSo& ps) {
        // ham cong hai phan so
        PhanSo kq;
        kq.tu = tu * ps.mau + ps.tu * mau;
        kq.mau = mau * ps.mau;
        kq.rutGon();
        return kq;
    }

    PhanSo tru(const PhanSo& ps) {
        // ham tru hai phan so
        PhanSo kq;
        kq.tu = tu * ps.mau - ps.tu * mau;
        kq.mau = mau * ps.mau;
        kq.rutGon();
        return kq;
    }

    PhanSo nhan(const PhanSo& ps) {
        // ham nhan hai phan so
        PhanSo kq;
        kq.tu = tu * ps.tu;
        kq.mau = mau * ps.mau;
        kq.rutGon();
        return kq;
    }

    PhanSo chia(const PhanSo& ps) {
        // ham chia hai phan so
        PhanSo kq;
        kq.tu = tu * ps.mau;
        kq.mau = mau * ps.tu;
        kq.rutGon();
        return kq;
    }
};


int main() {
    PhanSo ps1, ps2;
    
    cout << "Nhap phan so thu nhat \n";
    ps1.nhap();
    
    cout << "Nhap phan so thu hai: \n";
    ps2.nhap();
    
    PhanSo tong = ps1.cong(ps2);
    PhanSo hieu = ps1.tru(ps2);
    PhanSo tich = ps1.nhan(ps2);
    PhanSo thuong = ps1.chia(ps2);
    
    cout << "\nKet qua tinh duoc: \n";
    cout << "Tong: ";
    tong.xuat();
    
    cout << "\nHieu: ";
    hieu.xuat();
    
    cout << "\nTich: ";
    tich.xuat();
    
    cout << "\nThuong: ";
    thuong.xuat();
    
    return 0;
}