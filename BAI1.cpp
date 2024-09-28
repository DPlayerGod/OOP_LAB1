#include<bits/stdc++.h>

using namespace std;

int ucln(int a, int b) {
    /*
        ucln(a, b) : Ham tim uoc chung lon nhat cua hai so a, b
    */
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void rutGonPhanSo(int &tu, int &mau) {
    /*
        rutGonPhanSo(tu, mau) : Ham rut gon phan so
    */
    int ucln_ = ucln(tu, mau);
    tu /= ucln_;
    mau /= ucln_;
}

int main() {
    int tu, mau;
    cout << "Nhap tu so: ";
    cin >> tu;
    cout << "Nhap mau so: ";
    cin >> mau;

    while (mau == 0) {
        cout << "Mau so khong hop le. Vui long nhap lai phan so: \n";
        
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
    }

    rutGonPhanSo(tu, mau);

    cout << "Phan so toi gian la: " << tu << "/" << mau << '\n';

    return 0;
}