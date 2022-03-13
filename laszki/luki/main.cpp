#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define n 1000
int t[n];

void z1(ofstream &off) {
    int mx = t[0];
    int mn = t[0];
    for(int i=1; i<n;i++) {
        int l = abs(t[i] - t[i-1]);
        mx = max(mx, l);
        mn = min(mn, l);
    }
    off << "min: " << mn;
    off << ", max: " << mx << "\n";
}

void z2(ofstream &off) {
    pair<int, pair<int, int>> mx = make_pair(-1, make_pair(-1, -1));
    for(int i=0; i<n-1;i++) {
        int p = t[i];
        int l = 1;
        int r = abs(t[i+1]-t[i]);

        for(int j=i+1; j<n;j++) {
            int h = abs(t[j]-t[j-1]);
            if(h != r || j == n - 1) {
                if(l > mx.first) {
                    mx = make_pair(l, make_pair(p, t[j-1]));
                }
                break;
            }
            else {
                l++;
            }
        }
    }
    off << "dlugosc: " << mx.first;
    off << ", pierwsza: " << mx.second.first;
    off << ", ostatnia: " << mx.second.second << "\n"; 
}

void z3(ofstream &off) {
    vector<pair<int, int>> l;

    for(int i=1; i<n;i++) {
        int r = abs(t[i]-t[i-1]);

        bool e = false;
        for(int j=0; j<l.size(); j++) {
            if(l[j].second == r) {
                l[j].first ++;
                e = true;
                break;
            }
        }

        if(!e) 
            l.push_back(make_pair(1, r));
    }

    sort(l.rbegin(), l.rend());
    off << "krotnosc: " <<l[0].first << "\n";

    for(int i=0; i<l.size();i++) {
        if(l[i].first != l[0].first) 
            break;
        off << l[i].second << ", ";
    }
}

int main() {
    ifstream iff;
    ofstream off;
    iff.open("dane4.txt");
    off.open("wyniki4.txt");

    for(int i=0; i<n; i++) {
        iff >> t[i];
    }

    off << "1.\n";
    z1(off);
    off << "2.\n";
    z2(off);
    off << "3.\n";
    z3(off);

}