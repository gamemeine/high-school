#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tf[50];

int f(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	return f(n - 1) + f(n - 2);
}

bool isPrime(int x) {
	for (int i = 2; i * i < x;i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

string toBin(int x) {
	string h;
	while (x) {
		h += '0'+(x % 2);
		x /= 2;
	}
	reverse(h.begin(), h.end());
	return h;
}

int cO(string s) {
	int r = 0; 
	for (int i = 0; i < s.length();i++) {
		r += s[i] == '1' ? 1 : 0;
	}
	return r;
}

void z1() {
	cout << "Zadanie 1\n";
	for (int i = 10; i <= 40; i += 10) {
		cout << tf[i] << "\n";
	}
}

void z2() {
	cout << "\nZadanie 2\n";
	for (int i = 2; i <= 40;i++) {
		int h = tf[i];
		if (isPrime(h)) {
			cout << h << "\n";
		}
	}
}

void z3() {
	cout << "\nZadanie 3\n";
	vector<string> v;
	for (int i = 1; i <= 40; i++) {
		v.push_back(toBin(tf[i]));
	}
	
	for (int i = 0; i < 40;i++) {
		for (int j = 0; j < v[39].length() - v[i].length();j++) {
			cout << "0";
		}
		cout << v[i] << "\n";
	}
}

void z4() {
	cout << "\nZadanie 4\n";
	for (int i = 1; i <= 40; i++) {
		string h = toBin(tf[i]);
		if (cO(h) == 6) {
			cout << h << "\n";
		}
	}
}

int main() {
	for (int i = 1; i <= 40; i++) {
		tf[i] = f(i);
	}
	
	z1();
	z2();
	z3();
	z4();
}