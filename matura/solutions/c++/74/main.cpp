#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define n 200
string t[n];

bool onlyNumeric(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    return true;
}

bool haveNumeric(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            return true;
    }

    return false;
}

bool haveMini(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            return true;
    }

    return false;
}

bool haveCapital(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            return true;
    }

    return false;
}

bool kolejne(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        string c = s.substr(i, 4);
        sort(c.begin(), c.end());

        bool correct = true;

        for (int j = 1; j < 4; j++)
        {
            if (c[j] != c[j - 1] + 1)
            {
                correct = false;
                break;
            }
        }

        if (correct)
            return true;
    }
    return false;
}

void z1()
{
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (onlyNumeric(t[i]))
            r++;
    }

    cout << r << "\n";
}

void z2()
{
    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back(t[i]);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            cout << v[i] << "\n";
        }
        while (v[i] == v[i + 1])
        {
            i++;
        }
    }
}

void z3()
{
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (kolejne(t[i]))
            r++;
    }

    cout << r << "\n";
}

void z4()
{
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (haveNumeric(t[i]) && haveMini(t[i]) && haveCapital(t[i]))
            r++;
    }

    cout << r;
}

int main()
{
    ifstream iff;
    iff.open("hasla.txt");

    for (int i = 0; i < n; i++)
    {
        iff >> t[i];
    }
    z1();
    z2();
    z3();
    z4();
}