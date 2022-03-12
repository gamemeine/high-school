#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define n 1000

pair<int, string> l1[n];
int l2[n];

int OtoD(string s) {
	int r = 0;
	int m = 1;
	for (int i = s.length() - 1;i >= 0;i--) {
		r += m * (s[i] - '0');
		m *= 8;
	}
	return r;
}

int ile6(string s) {
	int r = 0;
	for (auto h : s) {
		if (h == '6') {
			r++;
		}	
	}

	return r;
}
string toO(int d) {
	string r = "";
	while (d) {
		r += '0' + (d % 8);
		d /= 8;
	}
	reverse(r.begin(), r.end());	
	return r;
}

void z1() {
	int mx = 0;
	int mn = 0;

	for (int i = 0;i < n;i++) {
		if (l1[mx].first < l1[i].first) {
			mx = i;
		}
		if (l1[mn].first > l1[i].first) {
			mn = i;
		}
	}

	cout << "Max: " << l1[mx].second << "\n";
	cout << "Min: " << l1[mn].second << "\n";
}

void z2() {
	int f = l2[0];
	int l = 1;
	int lmx = 1;
	for (int i = 1; i < n;i++) {
		for (int j = i; j < n; j++) {
			if (l2[j] < l2[j - 1]) {
				if(l > lmx) {
					lmx = l;
					f = l2[j - l];
				}
				l = 1;
				i = j;
				break;
			}
			else {
				l++;
			}
		}
	}

	cout << f << ", " << lmx << "\n";
}

void z3() {
	int a = 0;
	int b = 0;

	for (int i = 0; i < n; i++) {
		if (l1[i].first == l2[i]) {
			a++;
		}
		if (l1[i].first > l2[i]) {
			b++;
		}
	}

	cout << "A: " << a << ", B: " << b << "\n";
}

void z4() {
	int a = 0;
	int b = 0;
	for (int i = 0; i < n;i++) {
		a += ile6(to_string(l2[i]));
		b += ile6(toO(l2[i]));
	}
	cout << "Normlanie: " << a << ", Osemkowo: " << b;
}

int main() {
	ifstream iff;
	iff.open("liczby1.txt");

	for (int i = 0; i < n;i++) {
		string h;
		iff >> h;
		l1[i] = make_pair(OtoD(h), h);
	}
	iff.close();
	iff.open("liczby2.txt");

	for (int i = 0; i < n;i++) {
		iff >> l2[i];
	}

	z1();
	z2();
	z3();
	z4();
}