#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double a[6][5];

double f(double x) {
    int i = 0;
    if(x < 1.0f) {
        i = 1;
    }

    if(x < 2.0f) {
        i = 2;
    }

    if(x < 3.0f) {
        i = 3;
    }

    if(x < 4.0f) {
        i = 4;
    }

    if(x < 5.0f) {
        i = 5;
    }

    return a[i][1] + (a[i][2] * x) + (a[i][3] * x * x) + (a[i][4] * x * x * x);
}

void z1() {
    printf("%.5f", f(1.5));
}


int main() {
    ifstream iff;
    iff.open("funkcja.txt");

    for(int i=1; i<=5; i++) {
        for(int j=1; j<=4; j++) {
            iff >> a[i][j];
        }
    }
    z1();
}