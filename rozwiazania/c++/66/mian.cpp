#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define n 1000

int t[n][3];

int sumCyfr(int x) {
	int r = 0;
	while (x) {
		r += x % 10;
		x /= 10;
	}
	return r;
}

bool pierwsza(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

bool pitagoras(int a, int b, int c) {
	vector<int> bk = { a, b, c };
	sort(bk.begin(), bk.end());
	a = bk[0];
	b = bk[1];
	c = bk[2];
	return (a * a) + (b * b) == (c * c);
}

bool trojkat(int a, int b, int c) {
	return (a + b > c && a + c > b && b + c > a);
}

bool z2war(int a, int b, int c) {
	return pierwsza(a) && pierwsza(b) && c == a * b;
}
void z1() {
	cout << "Z1: \n";
	for (int i = 0; i < n; i++) {
		if (sumCyfr(t[i][0]) + sumCyfr(t[i][1]) == t[i][2]) {
			cout << t[i][0] << " ";
			cout << t[i][1] << " ";
			cout << t[i][2] << "\n";
		}
	}
}

void z2() {
	cout << "\nZ2: \n";
	for (int i = 0; i < n; i++) {
		bool war = z2war(t[i][0], t[i][1], t[i][2])
			|| z2war(t[i][0], t[i][2], t[i][1])
			|| z2war(t[i][1], t[i][0], t[i][2])
			|| z2war(t[i][1], t[i][2], t[i][0])
			|| z2war(t[i][2], t[i][0], t[i][1])
			|| z2war(t[i][2], t[i][1], t[i][0]);
		if (war) {
			cout << t[i][0] << " ";
			cout << t[i][1] << " ";
			cout << t[i][2] << "\n";
		}
	}
}

void z3() {
	cout << "\nZ3: \n";
	for (int i = 1; i < n; i++) {
		if (pitagoras(t[i - 1][0], t[i - 1][1], t[i - 1][2]) && pitagoras(t[i][0], t[i][1], t[i][2])) {
			cout << t[i-1][0] << " ";
			cout << t[i-1][1] << " ";
			cout << t[i-1][2] << ", ";
			cout << t[i][0] << " ";
			cout << t[i][1] << " ";
			cout << t[i][2] << "\n";
		}
	}
}

void z4() {
	cout << "\nZ4: \n";
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (trojkat(t[i][0], t[i][1], t[i][2])) {
			r++;
		}
	}

	int mx = -1;

	for (int i = 0; i < n;i++) {
		int j = i;
		while (trojkat(t[j][0], t[j][1], t[j][2])) {
			j++;
		}
		mx = max(mx, j - i);
		i = j;
	}
	cout << r << ", " << mx;
}

int main() {
	ifstream iff;
	iff.open("trojki.txt");

	for (int i = 0; i < n;i++) {
		iff >> t[i][0] >> t[i][1] >> t[i][2];
	}

	z1();
	z2();
	z3();
	z4();
}