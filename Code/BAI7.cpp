#include<bits/stdc++.h>

using namespace std;

class HocSinh {
private:

public:
    string hoTen;
    string gioiTinh;
    long double diemToan, diemVan, diemAnh;

    // ham kiem tra ten
    bool checkTen(string s) {
        if (s.size() > 40) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && isalpha(s[i]) == false)
                return false;
        }
        return true;
    }

    // ham kiem tra diem
    bool checkDiem(long double diem) {
        return diem >= 0.0 && diem <= 10.0;
    }

    // Ham nhap thong tin hoc sinh
    void nhapThongTin() {
    
        cout << "Nhap ho va ten : ";

        cin.ignore();
        getline(cin, hoTen);

        while (checkTen(hoTen) == false) {
            cout << "Ten hoc sinh khong hop le! Vui long nhap lai : ";
            cin >> hoTen;
        }
     
        cout << "Nhap diem Toan: ";
        cin >> diemToan;
        while (checkDiem(diemToan) == false) {
            cout << "Diem toan cua hoc sinh khong hop le! Vui long nhap lai : ";
            cin >> diemToan;
        }

        cout << "Nhap diem Van: ";
        cin >> diemVan;
        while (checkDiem(diemVan) == false) {
            cout << "Diem van cua hoc sinh khong hop le! Vui long nhap lai : ";
            cin >> diemVan;
        }

        cout << "Nhap diem Anh: ";
        cin >> diemAnh;
        while (checkDiem(diemAnh) == false) {
            cout << "Diem anh cua hoc sinh khong hop le! Vui long nhap lai : ";
            cin >> diemAnh;
        }
    }

    // Ham tinh diem trung binh
    long double tinhDiemTrungBinh() const {
        return (diemToan * 2 + diemVan + diemAnh) / 4;
    }

    // ham xep loai hoc luc
    string xepLoai(long double diem) const {
        if (diem >= 9.0) return "xuat sac";
        else if (diem >= 8.0) return "gioi";
        else if (diem >= 6.5) return "kha";
        else if (diem >= 5.0) return "trung binh";
        return "yeu";
    }

    // Ham xuat thong tin cua hoc sinh
    void xuatThongTin() const {
        cout << "Thong tin hoc sinh\n";
        cout << "Ho va ten: " << hoTen << '\n';
        cout << "Diem Toan: " << diemToan << '\n';
        cout << "Diem Van : " << diemVan << '\n';
        cout << "Diem Anh : " << diemAnh << '\n';
        cout << "Diem trung binh: " << tinhDiemTrungBinh() << '\n';
        cout << "Hoc luc cua hoc sinh " << hoTen << " la " << xepLoai(tinhDiemTrungBinh()) << '\n';

        cout << '\n';
    }
};

void HSdiemcaonhat(const vector<HocSinh>& hs) {
    vector<string> tenHS;

    long double diem = 0.0;

    for (int i = 0; i < hs.size(); i++) {
        long double diemHS = hs[i].tinhDiemTrungBinh();
        if (diemHS > diem) {
            tenHS.clear();
            diem = diemHS;
            tenHS.push_back(hs[i].hoTen);
        }
        else if (diemHS == diem) {
            tenHS.push_back(hs[i].hoTen);
        }
    }
   
    cout << "Danh sach ten cac hoc sinh co diem trung binh cao nhat : " << '\n';

    for (auto x : tenHS) {
        cout << x << '\n';
    }
}

// ham kiem tra su tuong dong giua 2 xau a va b, khong phan biet ki tu hoa va thuong
bool TuongDong(string a, string b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (toupper(a[i]) != toupper(b[i])) return false;
    }
    return true;
}


// ham tim danh sach hoc sinh lien quan den tu khoa can tim
void HSLienQuan(const vector<HocSinh>& hs, string s) {
    vector<string> tenHS;

    int lenS = s.size(); // Do dai cua tu khoa

    for (int i = 0; i < hs.size(); i++) {
        int lenHS = hs[i].hoTen.size();

        if(lenS > lenHS) continue;
        
        for (int j = 0; j < lenHS; j++) {
            if (TuongDong(hs[i].hoTen.substr(j, lenS), s)) {
                tenHS.push_back(hs[i].hoTen);
                break;
            }
        }
    }
   
    cout << "Danh sach ten cac hoc sinh co lien quan den tu khoa " << s << " la :" << '\n';

    for (auto x : tenHS) {
        cout << x << '\n';
    }
    cout << '\n';
}


void HSdiemtoanthapnhat(const vector<HocSinh>& hs) {
    vector<string> tenHS;

    long double diem = 11.0;

    for (int i = 0; i < hs.size(); i++) {
        long double diemHS = hs[i].diemToan;
        if (diemHS < diem) {
            tenHS.clear();
            diem = diemHS;
            tenHS.push_back(hs[i].hoTen);
        }
        else if (diemHS == diem) {
            tenHS.push_back(hs[i].hoTen);
        }
    }
   
    cout << "Danh sach ten cac hoc sinh co diem toan thap nhat : " << '\n';

    for (auto x : tenHS) {
        cout << x << '\n';
    }
    cout << '\n';
}

int main() {
    int n;
    cout << "So hoc sinh can quan ly thong tin la : ";
    cin >> n;

    vector<HocSinh> hs(n);

    for (int i = 0; i < n; i++) {
        hs[i].nhapThongTin();
    }

    for (int i = 0; i < n; i++) {
        hs[i].xuatThongTin();
    }

    HSdiemcaonhat(hs);


    cout << "Tu khoa de tim kiem thong tin cac hoc sinh la : ";
    string keyWord;
    cin.ignore();
    getline(cin, keyWord);

    HSLienQuan(hs, keyWord);

    HSdiemtoanthapnhat(hs);

    return 0;
}

