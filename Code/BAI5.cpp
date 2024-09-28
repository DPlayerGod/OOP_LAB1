#include <bits/stdc++.h>

using namespace std;

bool isLeapYear(int year) {
    // ham kiem tra nam Nhuan 
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int daysInMonth(int month, int year) {
    // Ham tra ve so ngay cua mot thang 
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

void nextDay(int day, int month, int year) {
    // Ham tim ra ngay tiep theo cua ngay da cho truoc
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    cout << "Ngay ke tiep: " << day << "/" << month << "/" << year << '\n';
}

void previousDay(int day, int month, int year) {
    // Ham tim ra ngay ket truoc cua ngay da cho truoc
    day--;
    if (day == 0) {
        month--;
        if (month == 0) {
            month = 12;
            year--;
        }
        day = daysInMonth(month, year);
    }
    cout << "Ngay ke truoc: " << day << "/" << month << "/" << year << endl;
}

void dayOfYear(int day, int month, int year) {
    // ham tinh ngay thu bao nhieu trong nam
    int days = 0;
    for (int m = 1; m < month; m++) {
        days += daysInMonth(m, year);
    }
    days += day;
    cout << "Ngay thu " << days << " trong nam" << '\n';
}

int main() {
    int day, month, year;

    cout << "Nhap ngay: ";
    cin >> day;
    cout << "Nhap thang: ";
    cin >> month;
    cout << "Nhap nam: ";
    cin >> year;

    nextDay(day, month, year);

    previousDay(day, month, year);

    dayOfYear(day, month, year);

    return 0;
}