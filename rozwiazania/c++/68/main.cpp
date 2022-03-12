#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define n 1000

pair<string, string> t[n];

bool czyAnagram(string a, string b) {
	if (a.length() != b.length())
		return false;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	return a == b;
}
bool takieSameLitery(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a[0] == a[a.length() - 1] &&  b[0] == b[b.length() - 1];
}

void z1() {
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (takieSameLitery(t[i].first, t[i].second) && czyAnagram(t[i].first, t[i].second))
			r++;
	}
	cout << r << "\n";
}

void z2() {
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (czyAnagram(t[i].first, t[i].second)) {
			r++;
		}
	}
	cout << r << "\n";
}

void z3() {
	vector<string> s;
	int mx = 0;
	for (int i = 0; i < n;i++) {
		s.push_back(t[i].first);
		s.push_back(t[i].second);
	}

	for (int i = 0; i < 2 * n;i++) {
		int k = 0;
		for (int j = 0; j < 2 * n; j++) {
			if (czyAnagram(s[i], s[j])) {
				k++;
			}
		}
		mx = max(mx, k);
	}
	cout << mx;
}


int main() {
	ifstream iff;
	iff.open("dane_napisy.txt");

	for (int i = 0; i < n;i++) {
		iff >> t[i].first >> t[i].second;
	}

	z1();
	z2();
	z3();
}