#include<bits/stdc++.h>

using namespace std;

int tu[3], mau[3];

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

void Input(int i) {
    /*
        Input(i) : Ham doc phan so thu i
    */

    cout << "Nhap tu so cua phan so thu " << i << ": ";
    cin >> tu[i];

    cout << "Nhap mau so cua phan so thu " << i << ": ";
    cin >> mau[i];

    while (mau[i] == 0) {
        cout << "Mau so khong hop le. Vui long nhap lai phan so: \n";

        cout << "Nhap tu so cua phan so thu " << i << ": ";
        cin >> tu[i];

        cout << "Nhap mau so cua phan so thu " << i << ": ";
        cin >> mau[i];
    }

    rutGonPhanSo(tu[i], mau[i]);

    if (mau[i] < 0) {
        // Loai bo dau tru
        tu[i] *= -1;
        mau[i] *= -1;
    }
}

int main() {
    Input(1); // Nhap phan so thu nhat
    Input(2); // Nhap phan so thu hai

    if (tu[1] * mau[2] > mau[1] * tu[2]) {
        cout << "Phan so lon nhat la: " << tu[1] << "/" << mau[1] << '\n';
    }
    else if (tu[1] * mau[2] < mau[1] * tu[2]) {
        cout << "Phan so lon nhat la: " << tu[2] << "/" << mau[2] << '\n';
    }
    else {
        cout << "Hai phan so bang nhau la: " << tu[1] << "/" << mau[1] << '\n';
    }

    return 0;
}