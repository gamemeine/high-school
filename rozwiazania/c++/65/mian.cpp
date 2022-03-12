#include <iostream>
#include <fstream>
using namespace std;
#define n 1000
pair<int, int> tab[n];

bool czySkr(int a, int b) {
	for (int i = 2; i <= min(a, b); i++) {
		if (a % i == 0 && b % i == 0) {
			return true;
		}
	}
	return false;
}

pair<int, int> skr(int a, int b) {
	for (int i = 2; i <= min(a, b); i++) {
		while (a % i == 0 && b % i == 0) {
			a /= i;
			b /= i;
		}
	}
	return make_pair(a, b);
}

void z1() {
	pair<int, int> mn = make_pair(100000000, 100000);

	for (int i = 0; i < n; i++) {
		if ((float)mn.first / (float)mn.second >= (float)tab[i].first / (float)tab[i].second) {
			if ((float)mn.first / (float)mn.second == (float)tab[i].first / (float)tab[i].second) {
				if (tab[i].second < mn.second) {
					mn = tab[i];
				}
			}
			else {
				mn = tab[i];
			}
		}
	}
	cout << mn.first << ", " << mn.second << "\n";
}

void z2() {
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (!czySkr(tab[i].first, tab[i].second)) {
			r++;
		}
	}
	cout << r << "\n";
}

void z3() {
	int r = 0;
	for (int i = 0; i < n; i++) {
		r += skr(tab[i].first, tab[i].second).first;
	}
	cout << r << "\n";
}

void z4() {
	int b = 2 * 2 * 3 * 3 * 5 * 5 * 7 * 7 * 13;
	int r = 0;
	for (int i = 0; i < n; i++) {
		int a = tab[i].first;
		a *= b / tab[i].second;
		r += a;
	}
	cout << r;
}

int main() {
	ifstream iff;
	iff.open("dane_ulamki.txt");
	for (int i = 0; i < n;i++) {
		int a, b;
		iff >> a >> b;
		tab[i] = make_pair(a, b);
	}
	z1();
	z2();
	z3();
	z4();
}