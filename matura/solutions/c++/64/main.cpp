#include <iostream>
#include <fstream>
using namespace std;

#define n 200

string tab[n][21];

bool czyRek(string o[21]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (o[i][j] != o[i][j]
				|| o[i][j] != o[i + 10][j]
				|| o[i][j] != o[i][j + 10]
				|| o[i][j] != o[i + 10][j + 10]) {
				return false;
			}
		}
	}
	return true;
}

pair<int, int> bl(string s[21]) {
	int bw = 0;
	for (int i = 0; i < 20; i++) {
		int o = 0;
		for (int j = 0; j < 20; j++) {
			o += s[i][j] == '1' ? 1 : 0;
		}

		if (o % 2 == 0) {
			if (s[i][20] == '1') {
				bw++;
			}
		}
		else {
			if (s[i][20] == '0') {
				bw++;
			}
		}
	}

	int bk = 0;
	for (int i = 0; i < 20; i++) {
		int o = 0;
		for (int j = 0; j < 20; j++) {
			o += s[j][i] == '1' ? 1 : 0;
		}

		if (o % 2 == 0) {
			if (s[20][i] == '1') {
				bk++;
			}
		}
		else {
			if (s[20][i] == '0') {
				bk++;
			}
		}
	}

	return make_pair(bw, bk);
}

void z1() {
	int r = 0;
	int mx = 0;
	for (auto h : tab) {
		int b = 0;
		int w = 0;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				b += h[i][j] == '1' ? 1 : 0;
				w += h[i][j] == '0' ? 1 : 0;
			}
		}

		if (b > w) {
			r++;
		}

		mx = max(mx, b);
	}
	cout << r << ", " << mx << "\n";
}

void z2() {
	int r = 0;
	bool f = true;
	for (auto h : tab) {
		if (czyRek(h)) {
			if (f) {
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						cout << h[i][j] << " ";
					}
					cout << "\n";
				}
				f = false;
			}
			r++;
		}
	}
	cout << r << "\n";
}

void z3() {
	int d = 0;
	int np = 0;
	int z = 0;
	int mx = 0;
	for (auto h : tab) {
		pair<int, int> b = bl(h);
		if (b.first == 0 && b.second == 0) {
			d++;
		}
		else if (b.first <= 1 && b.second <= 1) {
			np++;
		}
		else
		{
			z++;
		}
		mx = max(mx, b.first + b.second);
	}
	cout << "poprawne: " << d << ", ";
	cout << "naprawialne: " << np << ", ";
	cout << "nienaprawialne: " << z << "\n";
	cout << "max: " << mx << "\n";
}

int main() {
	ifstream iff;
	iff.open("dane_obrazki.txt");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 21; j++) {
			iff >> tab[i][j];
		}
	}

	z1();
	z2();
	z3();
}