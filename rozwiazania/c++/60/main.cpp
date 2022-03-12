#include <iostream>
#include <fstream>
#include <vector>
#include "main.h"
using namespace std;
#define n 200
int tab[n];

bool czy18D(int x, vector<int> &d) {
	int c = 0;

	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			c++;
			d.push_back(i);
		}
		if (c > 18) {
			return false;
		}
	}

	if (c == 18) {
		return true;
	}
	return false;
}

bool czyWzgP(int x, int y) {
	for (int i = 2; i <= min(x, y);i++) {
		if (x % i == 0 && y % i == 0) {
			return false;
		}
	}
	return true;
}

void z1() {
	int r = 0;
	int c = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (tab[i] < 1000) {
			r++;

			if (c < 2) {
				cout << tab[i] << ", ";
				c++;
			}
		}
	}
	cout << "\n" << r << "\n";
}

void z2() {
	for (auto h : tab) {
		vector<int> d;
		if (czy18D(h,d)) {
			cout << h << ": ";
			for (auto a : d) {
				cout << a << ", ";
			}
			cout << "\n";
		}
	}
}

void z3() {
	bool d[n][n];
	int mx = -1;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				d[i][j] = true;
			else
				d[i][j] = czyWzgP(tab[i], tab[j]);
		}
	}

	for (int i = 0; i < n;i++) {
		bool a = true;
		for (int j = 0; j < n; j++) {
			if (!d[i][j]) {
				a = false;
				break;
			}	
		}
		if (a) {
			mx = max(mx, tab[i]);
		}
	}
	cout << mx;
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