#include <iostream>
#include <fstream>
#include <string>
#include "58.h"
using namespace std;

#define n 1095

int s_1[n][2];
int s_2[n][2];
int s_3[n][2];

int toDec(string val,int b) {
	int r = 0;
	int m = 1;

	for (int i = val.length() - 1; i >= 0; i--) {
		if (val[i] == '-') {
			r *= -1;
		}
		else {
			r += (val[i] - '0') * m;
			m *= b;
		}
	}
	return r;
}

string toBin(int val) {
	string r = "";
	bool neg = val < 0;
	val = abs(val);

	while (val) {
		r += to_string(val % 2);
		val /= 2;
	}
	reverse(r.begin(), r.end());

	if (neg) {
		return "-" + r;
	}

	return r;
}

void z1() {
	int mn_s_1 = 398;
	int mn_s_2 = 398;
	int mn_s_3 = 398;
	for (int i = 0; i < n;i++) {
		mn_s_1 = min(mn_s_1, s_1[i][1]);
		mn_s_2 = min(mn_s_2, s_2[i][1]);
		mn_s_3 = min(mn_s_3, s_3[i][1]);
	}
	cout << "1. " << toBin(mn_s_1) << "\n";
	cout << "2. " << toBin(mn_s_2) << "\n";
	cout << "3. " << toBin(mn_s_3) << "\n";
}

void z2() {
	int c = 0;

	for (int i = 0; i < n; i++) {
		if ((s_1[i][0] - 12) % 24 != 0 && (s_2[i][0] - 12) % 24 != 0 && (s_3[i][0] - 12) % 24 != 0) {
			c++;
		}
	}

	cout << c << "\n";
}

void z3() {
	int mx_s_1 = -123456;
	int mx_s_2 = -123456;
	int mx_s_3 = -123456;

	int c = 0;

	for (int i = 0; i < n;i++) {
		bool r_s_1 = s_1[i][1] > mx_s_1;
		bool r_s_2 = s_2[i][1] > mx_s_2;
		bool r_s_3 = s_3[i][1] > mx_s_3;

		if (r_s_1 || r_s_2 || r_s_3) {
			c++;
		}

		mx_s_1 = max(mx_s_1, s_1[i][1]);
		mx_s_2 = max(mx_s_2, s_2[i][1]);
		mx_s_3 = max(mx_s_3, s_3[i][1]);
	}

	cout << c << "\n";
}

void z4() {

	int mx = -38912;
	for (int i = 0; i < n - 1;i++) {
		for (int j = i + 1; j < n;j++) {
			float r = (s_1[i][1] - s_1[j][1]) * (s_1[i][1] - s_1[j][1]);
			int v = ceil(r / abs(i - j));
			mx = max(mx, v);
		}
	}

	cout << mx;
}

int main() {
	ifstream iff;

	iff.open("dane_systemy1.txt");
	int i = 0;
	while (iff) {
		string h;
		string v;
		iff >> h >> v;
		s_1[i][0] = toDec(h, 2);
		s_1[i][1] = toDec(v, 2);
		i++;
	}
	iff.close();
	iff.open("dane_systemy2.txt");
	i = 0;
	while (iff) {
		string h;
		string v;
		iff >> h >> v;
		s_2[i][0] = toDec(h, 4);
		s_2[i][1] = toDec(v, 4);
		i++;
	}
	iff.close();
	iff.open("dane_systemy3.txt");
	i = 0;
	while (iff) {
		string h;
		string v;
		iff >> h >> v;
		s_3[i][0] = toDec(h, 8);
		s_3[i][1] = toDec(v, 8);
		i++;
	}

	z1();
	z2();
	z3();
	z4();
}