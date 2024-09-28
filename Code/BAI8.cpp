#include<bits/stdc++.h>

using namespace std;

struct ChuyenBay {
    string maChuyenBay;
    string ngayBay;   //Dinh dang dd/mm/yyyy
    string gioBay;    // Dinh dang hh:mm theo 24 gio
    string noiDi;
    string noiDen;
};

// Kiem tra ma chuyen bay hop le
bool kiemTraMaChuyenBay(const string& maChuyenBay) {
    regex pattern("^[A-Za-z0-9]{1,5}$");// Ma chuyen bay khong chua ky tu dac biet va toi da 5 ky tu
    return regex_match(maChuyenBay, pattern); 
}


// Ham kiem tra nam nhuan
bool laNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

// So ngay cua cac thang 
int laySoNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return laNamNhuan(nam) ? 29 : 28;
        default:
            return 0; //Truong hop thang khong hop le
    }
}


// Kiem tra ngay bay hop le (dd/mm/yyyy)
bool kiemTraNgay(const string& ngayBay) {
    int ngay = stoi(ngayBay.substr(0, 2));
    int thang = stoi(ngayBay.substr(3, 2));
    int nam = stoi(ngayBay.substr(6, 4));

    // Kiem tra nam co hop le ?
    if (nam < 1) return false;

    // Kiem tra thang co hop le
    if (thang < 1 || thang > 12) return false;

    // Kiem tra ngay co hop le
    int soNgayToiDa = laySoNgayTrongThang(thang, nam);
    if (ngay < 1 || ngay > soNgayToiDa) return false;

    return true;
}

// Kiem tra gio bay hop le (hh:mm)
bool kiemTraGioBay(const string& gioBay) {
    regex pattern("^(0[0-9]|1[0-9]|2[0-3]):([0-5][0-9])$");
    return regex_match(gioBay, pattern);
}

// Kiem tra noi di va den (khong chua ky tu dac biet va toi da 20 ky tu)
bool kiemTraNoiDiDen(const string& noi) {
    regex pattern("^[A-Za-z\\s]{1,20}$");
    return regex_match(noi, pattern);
}

// Nhap thong tin chuyen bay
void nhapChuyenBay(ChuyenBay& cb) {
    do {
        cout << "Nhap ma chuyen bay: ";
        cin >> cb.maChuyenBay;
        if (!kiemTraMaChuyenBay(cb.maChuyenBay)) {
            cout << "Ma chuyen bay khong hop le. Hay nhap lai.\n";
        }
    } while (!kiemTraMaChuyenBay(cb.maChuyenBay));

    do {
        cout << "Nhap ngay bay (dd/mm/yyyy): ";
        cin >> cb.ngayBay;
        if (!kiemTraNgay(cb.ngayBay)) {
            cout << "Ngay bay khong hop le. Hay nhap lai.\n";
        }
    } while (!kiemTraNgay(cb.ngayBay));

    do {
        cout << "Nhap gio bay (hh:mm): ";
        cin >> cb.gioBay;
        if (!kiemTraGioBay(cb.gioBay)) {
            cout << "Gio bay khong hop le. Hay nhap lai.\n";
        }
    } while (!kiemTraGioBay(cb.gioBay));

    do {
        cout << "Nhap noi di: ";
        cin.ignore();
        getline(cin, cb.noiDi);
        if (!kiemTraNoiDiDen(cb.noiDi)) {
            cout << "Noi di khong hop le. Hay nhap lai.\n";
        }
    } while (!kiemTraNoiDiDen(cb.noiDi));

    do {
        cout << "Nhap noi den: ";
        getline(cin, cb.noiDen);
        if (!kiemTraNoiDiDen(cb.noiDen)) {
            cout << "Noi den khong hop le. Hay nhap lai.\n";
        }
    } while (!kiemTraNoiDiDen(cb.noiDen));
}

// Xuat thong tin chuyen bay
void xuatChuyenBay(const ChuyenBay& cb) {
    cout << "Ma chuyen bay: " << cb.maChuyenBay << "\n";
    cout << "Ngay bay: " << cb.ngayBay << "\n";
    cout << "Gio bay: " << cb.gioBay << "\n";
    cout << "Noi di: " << cb.noiDi << "\n";
    cout << "Noi den: " << cb.noiDen << "\n";
}

// Tim kiem chuyen bay theo ma chuyen bay
ChuyenBay* timChuyenBayTheoMa(vector<ChuyenBay>& danhSach, const string& maChuyenBay) {
    for (auto& cb : danhSach) {
        if (cb.maChuyenBay == maChuyenBay) {
            return &cb;
        }
    }
    return nullptr;
}

// Sap xep cac chuyen bay
void sapXepChuyenBay(vector<ChuyenBay>& danhSach) {
    sort(danhSach.begin(), danhSach.end(), [](const ChuyenBay& a, const ChuyenBay& b) {
        string tmpA = a.ngayBay, tmpB = b.ngayBay;
        int ngayA = stoi(tmpA.substr(0, 2)), ngayB = stoi(tmpB.substr(0, 2));
        int thangA = stoi(tmpA.substr(3, 2)), thangB = stoi(tmpB.substr(3, 2));
        int namA = stoi(tmpA.substr(6, 4)), namB = stoi(tmpB.substr(6, 4));

        if (tmpA == tmpB) return a.gioBay < b.gioBay;
        if (namA == namB && thangA == thangB) return ngayA < ngayB;
        if (namA == namB) return thangA < thangB;
        return namA < namB;
    });
}

// Hien thi cac chuyen tu mot dia diem trong ngay
void lietKeChuyenBayTheoNoiDiNgay(const vector<ChuyenBay>& danhSach, const string& noiDi, const string& ngay) {
    for (const auto& cb : danhSach) {
        if (cb.noiDi == noiDi && cb.ngayBay == ngay) {
            xuatChuyenBay(cb);
            cout << "-----------------\n";
        }
    }
}

// Dem so luong chuyen bay tu mot noi di den mot noi den nhat dinh
int demChuyenBay(const vector<ChuyenBay>& danhSach, const string& noiDi, const string& noiDen) {
    int dem = 0;
    for (const auto& cb : danhSach) {
        if (cb.noiDi == noiDi && cb.noiDen == noiDen) {
            dem++;
        }
    }
    return dem;
}

// Ham chinh
int main() {
    vector<ChuyenBay> danhSachChuyenBay;
    int luaChon;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap thong tin chuyen bay\n";
        cout << "2. Xuat danh sach chuyen bay\n";
        cout << "3. Tim kiem chuyen bay theo ma\n";
        cout << "4. Sap xep chuyen bay theo ngay gio khoi hanh\n";
        cout << "5. Liet ke chuyen bay theo noi di va ngay\n";
        cout << "6. Dem so luong chuyen bay theo noi di va noi den\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> luaChon;

        if (luaChon == 1) {
            ChuyenBay cb;
            nhapChuyenBay(cb);
            danhSachChuyenBay.push_back(cb);
        } else if (luaChon == 2) {
            for (const auto& cb : danhSachChuyenBay) {
                xuatChuyenBay(cb);
                cout << "-----------------\n";
            }
        } else if (luaChon == 3) {
            string maChuyenBay;
            cout << "Nhap ma chuyen bay can tim: ";
            cin >> maChuyenBay;
            ChuyenBay* cb = timChuyenBayTheoMa(danhSachChuyenBay, maChuyenBay);
            if (cb) {
                xuatChuyenBay(*cb);
            } else {
                cout << "Khong tim thay chuyen bay co ma " << maChuyenBay << "\n";
            }
        } else if (luaChon == 4) {
            sapXepChuyenBay(danhSachChuyenBay);
            cout << "Danh sach chuyen bay da duoc sap xep.\n";
        } else if (luaChon == 5) {
            string noiDi, ngay;
            cout << "Nhap noi di: ";
            cin.ignore();
            getline(cin, noiDi);
            cout << "Nhap ngay bay (dd/mm/yyyy): ";
            cin >> ngay;
            lietKeChuyenBayTheoNoiDiNgay(danhSachChuyenBay, noiDi, ngay);
        } else if (luaChon == 6) {
            string noiDi, noiDen;
            cout << "Nhap noi di: ";
            cin.ignore();
            getline(cin, noiDi);
            cout << "Nhap noi den: ";
            getline(cin, noiDen);
            int soChuyenBay = demChuyenBay(danhSachChuyenBay, noiDi, noiDen);
            cout << "So luong chuyen bay tu " << noiDi << " den " << noiDen << ": " << soChuyenBay << "\n";
        }
    } while (luaChon != 0);

    return 0;
}
