#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define n 100

vector<int> tab[n];
bool thd[1000000] = { false };


bool czyA(vector<int> c) {
	int r = c[1] - c[0];
	for (int i = 1; i < c.size();i++) {
		if (c[i] - c[i - 1] != r)
			return false;
	}
	return true;
}

void z1() {
	int r = 0;
	int mx = -1;
	for (int i = 0; i < n; i++) {
		if (czyA(tab[i])) {
			r++;
			mx = max(mx, tab[i][1] - tab[i][0]);
		}
			
	}
	cout << r << ", " << mx << "\n";
}

void z2() {
	for (int i = 0; i < n; i++) {
		for (int h = tab[i].size() - 1; h >= 0; h--) {
			if (thd[tab[i][h]])
			{
				cout << tab[i][h] << "\n";
				break;
			}
		}
	}
}

int blad(vector<int> c) {
	int l = c.size();
	if (c[3] - c[2] == c[2] - c[1] && c[2] - c[1] != c[1] - c[0])
		return c[0];

	if (c[l - 3] - c[l - 4] == c[l - 2] - c[l - 3] && c[l - 2] - c[l - 3] != c[l - 1] - c[l - 2])
		return c[l - 1];

	for (int i = 1; i < l - 1;i++) {
		if ((c[i - 1] + c[i + 1]) != c[i])
			return c[i];
	}
}

void z3() {
	ifstream iff;
	iff.open("bledne.txt");

	for (int i = 0; i < 20;i++) {
		int l;
		iff >> l;

		vector<int> c;
		while(l) {
			int h;
			iff >> h;
			c.push_back(h);
			--l;
		}

		cout << blad(c) << "\n";
	}
}


int main() {
	ifstream iff;
	iff.open("ciagi.txt");

	for (int i = 0; i < n; i++) {
		int l = 0;
		iff >> l;
		for (int j = 0; j < l; j++) {
			int h;
			iff >> h;
			tab[i].push_back(h);
		}
	}

	for (int i = 0; i < 100; i++) {
		thd[i * i * i] = true;
	}

	z1();
	z2();
	z3();
}