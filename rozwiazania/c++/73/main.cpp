#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define n 1876 

string t[n];

bool czyKolejneTakieSame(string s) {
    for(int i=1; i<s.length(); i++) {
        if(s[i] == s[i-1])
            return true;
    }
    return false;
}

bool czySpolgloska(char c) {
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        return false;
    return true;
}

string najPodslowo(string s) {
    string mx = "";
    for(int i=0; i<s.length(); i++) {
        string h = "";
        for(int j=i; j<s.length(); j++) {
            if(!czySpolgloska(s[j])) {
                if(h.length() > mx.length())
                    mx = h;

                j = i;
                break;
            }
            h += s[j];
        }
    }
    return mx;
}

void z2() {
    int w['Z'+1] = {0};
    double a = 0;
    for(int i=0; i<n; i++) {
        string s = t[i];

        for(int j=0; j<s.length(); j++) {
            w[s[j]]++;
            a++;
        } 
    }

    for(int i='A'; i<='Z';i++) {
        cout << (char)i << ": " << w[i];
        float f = w[i]/a * 100;
        printf(" (%.2f%)\n", f);
    }
}
void z1() {
    int r = 0;
    for(int i=0; i<n; i++) {
        if(czyKolejneTakieSame(t[i]))
            r++;
    }
    cout << r << "\n";
}

void z3() {
    vector<pair<int, string>> v;
    for(int i=0; i<n; i++) {
        string h =najPodslowo(t[i]);
        v.push_back(make_pair(h.length(), h));
    } 

    sort(v.rbegin(), v.rend());
    cout << v[0].first << ", ";

    bool first = true;
    int r = 0;
    for(int i=0; i<n; i++) {
        string h =najPodslowo(t[i]);
        if(h.length() == v[0].first) {
            if(first) {
                cout << t[i] << ", ";
                first = false;     
            }
            r++;
        }
    }
    cout << r;
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