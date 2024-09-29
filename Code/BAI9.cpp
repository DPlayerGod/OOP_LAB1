#include<bits/stdc++.h>

using namespace std;

struct SoTietKiem {
    string maSo;
    string loaiTietKiem;
    string hoTenKhachHang;
    string CMND;
    string ngayMoSo;
    double soTienGui;
};

// Kiem tra Ma so
bool kiemTraMaSo(const string& maSo) {
    regex pattern("^[A-Za-z0-9]{1,5}$");
    return regex_match(maSo, pattern);
}

// Kiem tra CMND (9 hoac 12 chu so)
bool kiemTraCMND(const string& cmnd) {
    regex pattern("^\\d{9}$|^\\d{12}$");
    return regex_match(cmnd, pattern);
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
bool kiemTraNgay(const string& ngayMoSo) {
    int ngay = stoi(ngayMoSo.substr(0, 2));
    int thang = stoi(ngayMoSo.substr(3, 2));
    int nam = stoi(ngayMoSo.substr(6, 4));

    // Kiem tra nam co hop le ?
    if (nam < 1) return false;

    // Kiem tra thang co hop le
    if (thang < 1 || thang > 12) return false;

    // Kiem tra ngay co hop le
    int soNgayToiDa = laySoNgayTrongThang(thang, nam);
    if (ngay < 1 || ngay > soNgayToiDa) return false;

    return true;
}

// Nhap thong tin cua so tiet kiem 

void nhapSoTietKiem(SoTietKiem& stk) {
    do {
        cout << "Nhap ma so: ";
        cin >> stk.maSo;
        if (!kiemTraMaSo(stk.maSo)) {
            cout << "Ma so khong hop le. Hay nhap lai.\n";
        }
    } while (!kiemTraMaSo(stk.maSo));

    cout << "Nhap loai tiet kiem (toi da 10 ky tu): ";
    cin.ignore();
    getline(cin, stk.loaiTietKiem);

    do {
        cout << "Nhap ho ten khach hang (toi da 30 ky tu): ";
        getline(cin, stk.hoTenKhachHang);
        if (!regex_match(stk.hoTenKhachHang, regex("^[A-Za-z\\s]{1,30}$"))) {
            cout << "Ho ten khong hop le. Hay nhap lai.\n";
        }
    } while (!regex_match(stk.hoTenKhachHang, regex("^[A-Za-z\\s]{1,30}$")));

    do {
        cout << "Nhap CMND (9 hoac 12 chu so): ";
        cin >> stk.CMND;
        if (!kiemTraCMND(stk.CMND)) {
            cout << "CMND khong hop le. Hay nhap lai.\n";
        }
    } while (!kiemTraCMND(stk.CMND));

    do {
        cout << "Nhap ngay mo so (dd/mm/yyyy): ";
        cin >> stk.ngayMoSo;
        if (!kiemTraNgay(stk.ngayMoSo)) {
            cout << "Ngay mo so khong hop le. Hay nhap lai.\n";
        }
    } while (!kiemTraNgay(stk.ngayMoSo));

    do {
        cout << "Nhap so tien gui: ";
        cin >> stk.soTienGui;
        if (stk.soTienGui <= 0) {
            cout << "So tien gui phai lon hon 0. Hay nhap lai.\n";
        }
    } while (stk.soTienGui <= 0);
}

// Xuat thong tin so tiet kiem
void xuatSoTietKiem(const SoTietKiem& stk) {
    cout << "Ma so: " << stk.maSo << "\n";
    cout << "Loai tiet kiem: " << stk.loaiTietKiem << "\n";
    cout << "Ho ten khach hang: " << stk.hoTenKhachHang << "\n";
    cout << "CMND: " << stk.CMND << "\n";
    cout << "Ngay mo so: " << stk.ngayMoSo << "\n";
    cout << "So tien gui: " << stk.soTienGui << "\n";
}

// Cap nhat lai suat va tinh toan lai dua tren loai tiet kiem va thoi gian

double tinhLaiSuat(const SoTietKiem& stk, double laiSuat) {
    if (stk.loaiTietKiem == "ngan han") {
        return stk.soTienGui * (laiSuat / 100) * (6.0 / 12.0); // Gia su thoi han khong qua 6 thang
    } else if (stk.loaiTietKiem == "dai han") {
        return stk.soTienGui * (laiSuat / 100); // Thoi gian lon hon 6 thang
    }
    return 0.0;
}

// Tinh lai dua tren thoi gian gui
double tinhTienLaiTheoThoiGian(const SoTietKiem& stk, double laiSuat) {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    // Gia su ngay hien tai la 26/09/2024
    int namHienTai = 2024;
    int thangHienTai = 9;
    int ngayHienTai = 26;

    // Ngay mo so co dang dd/mm/yyyy
    int ngay, thang, nam;
    sscanf(stk.ngayMoSo.c_str(), "%d/%d/%d", &ngay, &thang, &nam);

    // Tinh toan so thang da gui tien
    int soThangGui = (namHienTai - nam) * 12 + (thangHienTai - thang);
    return stk.soTienGui * (laiSuat / 100) * (soThangGui / 12.0);
}

// Tim kiem so tiet kiem theo CMND hoac Ma so
SoTietKiem* timKiemSoTietKiem(vector<SoTietKiem>& danhSach, const string& keyword) {
    for (auto& stk : danhSach) {
        if (stk.CMND == keyword || stk.maSo == keyword) {
            return &stk;
        }
    }
    return NULL;
}

// Kiem tra ngay nao lon hon
bool CheckNgayLonHon(const string& tmpA, const string& tmpB) {
    int ngayA = stoi(tmpA.substr(0, 2)), ngayB = stoi(tmpB.substr(0, 2));
    int thangA = stoi(tmpA.substr(3, 2)), thangB = stoi(tmpB.substr(3, 2));
    int namA = stoi(tmpA.substr(6, 4)), namB = stoi(tmpB.substr(6, 4));

    if (namA == namB && thangA == thangB) return ngayA < ngayB;
    if (namA == namB) return thangA < thangB;
    return namA < namB;
}

// Liet ke tat ca so tiet kiem duoc mo trong mot khoang thoi gian nhat dinh
void lietKeSoTietKiemTheoKhoangThoiGian(const vector<SoTietKiem>& danhSach, const string& ngayBatDau, const string& ngayKetThuc) {
    for (const auto& stk : danhSach) {
        if (CheckNgayLonHon(ngayBatDau, stk.ngayMoSo) && CheckNgayLonHon(stk.ngayMoSo, ngayKetThuc)) {
            xuatSoTietKiem(stk);
            cout << "-----------------\n";
        }
    }
}

// Sap xep so tiet kiem theo so tien giam dan
void sapXepTheoSoTien(vector<SoTietKiem>& danhSach) {
    sort(danhSach.begin(), danhSach.end(), [](const SoTietKiem& a, const SoTietKiem& b) {
        return a.soTienGui > b.soTienGui;
    });
}

// Sap xep so tiet kiem theo ngay mo so
void sapXepTheoNgayMoSo(vector<SoTietKiem>& danhSach) {
    sort(danhSach.begin(), danhSach.end(), [](const SoTietKiem& a, const SoTietKiem& b) {
        string tmpA = a.ngayMoSo, tmpB = b.ngayMoSo;
        int ngayA = stoi(tmpA.substr(0, 2)), ngayB = stoi(tmpB.substr(0, 2));
        int thangA = stoi(tmpA.substr(3, 2)), thangB = stoi(tmpB.substr(3, 2));
        int namA = stoi(tmpA.substr(6, 4)), namB = stoi(tmpB.substr(6, 4));

        if (namA == namB && thangA == thangB) return ngayA < ngayB;
        if (namA == namB) return thangA < thangB;
        return namA < namB;
    });
}

// Hàm chính
int main() {
    vector<SoTietKiem> danhSachSoTietKiem;
    int luaChon;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap thong tin so tiet kiem\n";
        cout << "2. Xuat danh sach so tiet kiem\n";
        cout << "3. Tim kiem so tiet kiem theo CMND hoac ma so\n";
        cout << "4. Cap nhat lai suat va tinh toan tien lai\n";
        cout << "5. Liet ke so tiet kiem theo khoang thoi gian\n";
        cout << "6. Sap xep danh sach theo so tien gui giam dan\n";
        cout << "7. Sap xep danh sach theo ngay mo so tang dan\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> luaChon;

        if (luaChon == 1) {
            SoTietKiem stk;
            nhapSoTietKiem(stk);
            danhSachSoTietKiem.push_back(stk);
        } else if (luaChon == 2) {
            for (const auto& stk : danhSachSoTietKiem) {
                xuatSoTietKiem(stk);
                cout << "-----------------\n";
            }
        } else if (luaChon == 3) {
            string keyword;
            cout << "Nhap CMND hoac ma so can tim: ";
            cin >> keyword;
            SoTietKiem* stk = timKiemSoTietKiem(danhSachSoTietKiem, keyword);
            if (stk) {
                xuatSoTietKiem(*stk);
            } else {
                cout << "Khong tim thay so tiet kiem.\n";
            }
        } else if (luaChon == 4) {
            string maSo;
            cout << "Nhap ma so can cap nhat lai suat: ";
            cin >> maSo;
            SoTietKiem* stk = timKiemSoTietKiem(danhSachSoTietKiem, maSo);
            if (stk) {
            double laiSuat;
            cout << "Nhap lai suat (%/nam): ";
            cin >> laiSuat;
            double tienLai = tinhLaiSuat(*stk, laiSuat);
            cout << "Tien lai duoc tinh la: " << tienLai << "\n";
        } else {
            cout << "Khong tim thay so tiet kiem.\n";
        }
        } else if (luaChon == 5) {
            string ngayBatDau, ngayKetThuc;
            cout << "Nhap ngay bat dau (dd/mm/yyyy): ";
            cin >> ngayBatDau;
            cout << "Nhap ngay ket thuc (dd/mm/yyyy): ";
            cin >> ngayKetThuc;
            lietKeSoTietKiemTheoKhoangThoiGian(danhSachSoTietKiem, ngayBatDau, ngayKetThuc);
        } else if (luaChon == 6) {
            sapXepTheoSoTien(danhSachSoTietKiem);
            cout << "Da sap xep danh sach theo so tien gui giam dan.\n";
        } else if (luaChon == 7) {
            sapXepTheoNgayMoSo(danhSachSoTietKiem);
            cout << "Da sap xep danh sach theo ngay mo so tang dan.\n";
        }
    }  while (luaChon != 0);

    return 0;
}
