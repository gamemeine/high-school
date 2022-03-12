#include <iostream>
#include <fstream>
using namespace std;

#define n 1000

string tab[n];

bool czy2cykliczny(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[i + (s.length() / 2)])
			return false;
	}
	return true;
}

bool czyNieObokSiebie(string s) {
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '1' && s[i - 1] == '1')
			return false;
	}
	return true;
}

bool czyPierwsza(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int toDec(string s) {
	int r = 0;
	int m = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		r += (s[i] - '0') * m;
		m *= 2;
	}
	return r;
}

void z1() {
	for (int i = 0; i < n;i++) {
		if (tab[i].length() % 2 != 0)
			continue;
		if (czy2cykliczny(tab[i]))
			cout << tab[i] << "\n";
	}
	cout << "\n";
}

void z2() {
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (czyNieObokSiebie(tab[i]))
			r++;
	}
	cout << r << "\n";
}

void z3() {
	int r = 0;
	int mn = 10000000;
	int mx = -1;
	for (int i = 0; i < n;i++) {
		int h = toDec(tab[i]);

		for (int j = 2; j * j <= h; j++) {
			if (h % j == 0) {
				if (czyPierwsza(j) && czyPierwsza(h / j)) {
					r++;
					mx = max(mx, h);
					mn = min(mn, h);
					break;
				}
			}
		}
	}
	cout << r << ", max: " << mx << ", min: " << mn;
}

int main() {
	ifstream iff;
	iff.open("ciagi.txt");
	for (int i = 0; i < n; i++) {
		iff >> tab[i];
	}

	z1();
	z2();
	z3();
}