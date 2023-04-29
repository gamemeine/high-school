#include <iostream>
#include <fstream>
using namespace std;

string szyfr(string s, int p[], int n) {
    for(int i=0;i<s.length(); i++) {
        swap(s[i], s[p[i%n]-1]);
    }
    return s;
}

string deszyfr(string s, int p[], int n) {
        for(int i=s.length()-1;i>=0; i--) {
        swap(s[i], s[p[i%n]-1]);
    }
    return s;
}
void z1() {
    const int n = 50;
    ifstream iff;
    iff.open("szyfr1.txt");

    string t[6];
    int p[n];
    for(int i=0; i<6; i++) {
        iff >> t[i];
    }
    for(int i=0; i<n; i++) {
        iff >> p[i];
    }

    for(int i=0; i<6; i++) {
        cout << szyfr(t[i], p, n) << "\n";
    }
}

void z2() {
    const int n = 15;
    ifstream iff;
    iff.open("szyfr2.txt");

    string t;
    int p[n];
    iff >> t;
    for(int i=0; i<n; i++) {
        iff >> p[i];
    }
    cout << szyfr(t, p, n) << "\n";
}

void z3() {
    const int n = 6;
    ifstream iff;
    iff.open("szyfr3.txt");

    string t;
    int p[] = {6, 2, 4, 1, 5, 3};
    iff >> t;
    cout << deszyfr(t, p, n) << "\n";
}

int main() {
    // z1();
    // z2();
    z3();
}