#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define n 1000

string t[n];

void getG(string a, vector<string> &g) {
	for (int i = 1; i < a.length(); i++) {
		if (a[i] == 'A' && a[i - 1] == 'A') {
			string h = "A";
			for (int j = i; j < a.length(); j++) {
				h += a[j];
				if (a[j] == 'B' && a[j - 1] == 'B') {
					break;
				}
			}
			if (h[h.length() - 1] == 'B' && h[h.length() - 2] == 'B') {
				g.push_back(h);
			}
			
		}
	}
}

void z1() {
	int tab[501] = { 0 };

	for (int i = 0; i < n; i++) {
		tab[t[i].length()]++;
	}

	int r = 0;
	int mx = -1;
	for (int i = 1; i <= 500; i++) {
		if (tab[i] > 0)
			r++;

		mx = max(mx, tab[i]);
	}
	cout << r << ", " << mx << "\n";
}


void z2() {
	int r = 0;

	for (int i = 0; i < n; i++) {
		vector<string> g;
		getG(t[i], g);

		for (int i = 0; i < g.size(); i++) {
			for (int j = 0; j < g[i].length(); j++) {
				if (g[i].substr(j, 5) == "BCDDC") {
					r++;
					break;
				}
			}
		}
	}

	cout << r << "\n";
}

void z3() {
	int mxC = 0;
	int mxL = 0;

	for (int i = 0; i < n; i++) {
		vector<string> g;
		getG(t[i], g);

		mxC = max(mxC, (int)g.size() - 1);
		for (int j = 0; j < g.size(); j++) {
			mxL = max(mxL, (int)g[j].size() - 1);
		}
	}
	cout << "max geny: " << mxC << ", max dlugosc: " << mxL << "\n";
}

void z4() {
	int o = 0;
	int so = 0;


	for (int i = 0; i < n; i++) {
		string a = t[i];
		string b = t[i];
		reverse(b.begin(), b.end());

		if (a == b) {
			so++;
		}

		vector<string> ag;
		vector <string> bg;

		getG(a, ag);
		getG(b, bg);

		sort(ag.begin(), ag.end());
		sort(bg.begin(), bg.end());

		if (ag == bg) {
			o++;
		}
	}

	cout << "odpornych: " << o << ", silnie odpornych: " << so;
}

int main() {

	ifstream iff;
	iff.open("dane_geny.txt");

	for (int i = 0; i < n; i++) {
		iff >> t[i];
	}
	z1();
	z2();
	z3();
	z4();
}