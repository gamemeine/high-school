#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define n 200

pair<string, string> t[n];

string getEnding(string a, string b) {
    string h = "";
    for(int i=1; i<=min(a.length(), b.length()); i++) {
        if(a[a.length()-i] != b[b.length()-i]) {
            return h;
        }
        h += a[a.length()-i];
    }
    return h;
}

void z1() {
    cout << "Z1:\n";
    int r = 0;
    bool first = true;
    for(int i=0; i<n; i++) {
        if(t[i].first.length() / t[i].second.length() >= 3 || t[i].second.length() / t[i].first.length() >= 3) {
            r++;
            if(first) {
                cout<< t[i].first << ", " << t[i].second << ", ";
                first = false;
            }
        }
    }
    cout << r << "\n";
}

void z2() {
    cout << "\nZ2:\n";
    for(int i=0; i<n; i++) {
        if(t[i].first == t[i].second.substr(0, t[i].first.length())) {
            cout << t[i].first << ", " << t[i].second << ": " << t[i].second.substr(t[i].first.length(), 50) <<"\n";
        }
    }
}

void z3() {
    cout << "\nZ3:\n";
    vector<pair<int, pair<string, string>>> v;
    for(int i=0; i<n; i++) {
        string e = getEnding(t[i].first, t[i].second);
        if(e != "") {
            v.push_back(make_pair((int)e.length(), t[i]));
        }
    }
    sort(v.rbegin(), v.rend());

    cout << v[0].first << "\n";
    int i=0;
    while(v[i].first == v[0].first) {
        cout << v[i].second.first << ", " << v[i].second.second << "\n"; 
        i++;
    }
}
int main() {

    ifstream iff;
    iff.open("napisy.txt");

    for(int i=0; i<n; i++) {
        string a, b;
        iff >> a >> b;
        t[i] = make_pair(a, b);
    }

    z1();
    z2();
    z3();
}