#include<bits/stdc++.h>

using namespace std;

long double sin(long double x, long double epsilon) {
    long double sum = x;
    long double term = x;
    long long n = 1;
    long long sign = -1;
    
    while (abs(term) >= epsilon) {
        term *=  x * x / ((n + 1) * (n + 2));
        sum += sign * term;
        n += 2;
        sign *= -1;
    }
    
    return sum;
}

int main() {
    long double x, epsilon = 0.00001;
    
    cout << "Nhap gia tri x: ";
    cin >> x;
    
    long double result = sin(x, epsilon);
    
    cout << "sin(" << x << ") = ";
    cout << setprecision(5) << fixed << result;
    
    return 0;
}