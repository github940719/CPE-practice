#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool isPrime(int n) {
    if (n < 2) {
        return false ;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false ;
        }
    }
    return true ;
}


bool reverse_prime(int n) {
    string s = to_string(n) ;
    reverse(s.begin(), s.end()) ;
    int reverse_n = stoi(s) ;
    return (n != reverse_n && isPrime(reverse_n)) ;
}


int main() {
    int n ;
    while (cin >> n) {
        if (!isPrime(n)) {
            cout << n << " is not prime.\n" ;
        }
        else if (!reverse_prime(n)) {
            cout << n << " is prime.\n" ;
        }
        else {
            cout << n << " is emirp.\n" ;
        }
    }
}