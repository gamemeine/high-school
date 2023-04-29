#include <iostream>
#include <fstream>
using namespace std;
#define n 805

string t[n];

string szyfr(string s, int a, int b) {
    string r = "";
    for(int i=0;i<s.length(); i++) {
        int c = s[i]-'a';
        c *= a;
        c += b;

        if(c > 25)
            c %= 26;
        
        r += 'a' + c;
    }
    return r;
}

pair<int, int> znajdzKlucz(string a, string b) {
    for(int i=0; i<=25;i++) {
        for(int j=0; j<=25;j++) {
            if(szyfr(a, i, j) == b)
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

void z1() {
    cout << "Z1:\n";
    for(int i=0; i<n; i++) {
        string s = t[i];
        if(s[0] == 'd' && s[s.length()-1] == 'd')
            cout << s << "\n";
    }
}

void z2() {
    cout << "\nZ2:\n";
    for(int i=0; i<n; i++) {
        string s = t[i];

        if(s.length()>= 10) {
            string h  = szyfr(s, 5, 2);
            cout << h << "\n";
        }
    }
}

void z3() {
    cout << "\nZ3:\n";

    ifstream iff;
    iff.open("probka.txt");
    for(int i=0; i<5; i++) {
        string a, b;
        iff >> a >> b;

        pair<int,int> ks = znajdzKlucz(a, b);
        pair<int,int> kds = znajdzKlucz(b, a);

        cout << "szyfrujacy: " << ks.first <<", " << ks.second;
        cout << ", deszyfrujacy: " << kds.first << ", " << kds.second <<"\n";
    }
}

int main() {
    ifstream iff;
    iff.open("tekst.txt");

    for(int i=0; i<n;i++) {
        iff >> t[i];
    }

    z1();
    z2();
    z3();
}
