#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define n 1000

int tab[n];
 
int czn(int x) {
	int d = 2;	
	int lastD = -2;
	int c = 0;
	while (x > 1) {
		if (x % d == 0) {
			if (d % 2 == 0) {
				return false;
			}
			x /= d;
			if (lastD != d) {
				c++;
				lastD = d;
			}
		}
		else
		{
			while (x % d != 0) {
				d++;
			}
		}
	}
	return c == 3;

}

int rNum(int x) {
	int r = 0;
	while (x > 0) {
		r *= 10;
		r += x % 10;
		x /= 10;
	}

	return r;
}

int power(int x) {
	int r = 0;

	int h = x;
	while (h > 9) {
		int a = 1;
		while (h > 0) {
			a *= h % 10;
			h /= 10;
		}
		h = a;
		r++;
	}
	return r;
}

void z1() {
	int r = 0;
	for (auto h : tab) {
		if (czn(h))
			r++;
	}
	cout << r << "\n";
}

void z2() {
	int r = 0;
	for (auto h : tab) {
		int s = h + rNum(h);
		if (rNum(s) == s)
			r++;
	}
	cout << r << "\n";
}

void z3() {
	int p[9] = { 0 };

	int mn = 1000000000;
	int mx = -1;

	for (auto h : tab) {
		int v = power(h);
		if (v < 9)
			p[v]++;

		if (v == 1) {
			mn = min(mn, h);
			mx = max(mx, h);
		}
	}
	for (int i = 1; i <= 8;i++) {
		cout << i << ". " << p[i] << "\n";
	}
	cout << "mn: " << mn << "\n";
	cout << "mx: " << mx;
}

int main() {
	ifstream iff;
	iff.open("liczby.txt");

	for (int i = 0; i < n;i++) {
		iff >> tab[i];
	}
	z1();
	z2();
	z3();
}