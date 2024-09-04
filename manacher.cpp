#include "manacher.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string turnOdd(string &s){
    string oddString = "@#";

    for (int i = 0; i < s.length(); i++){
        oddString += s[i];
        oddString += "#";
    }

    oddString += "$";
    return oddString;
}


void manacher(string &s){
    string pString = turnOdd(s);
    int c = 0, r = 0;

    int n = pString.length();
    
    vector<int> p(n);

    for (int i = 1; i < n-1; i++){
        int mirror = 2 * c - i;

        if (r > i){
            p[i] = min(r-i, p[mirror]);
        } else {
            p[i] = 0;
        }

        while (pString[i + 1 + p[i]] == pString[i - 1 - p[i]]){
            p[i]++;
        }

        if (i + p[i] > r){
            c = i;
            r = i + p[i];
        }

    }

    int lengthL = 0;
    int centerL = 0;

    for (int i = 1; i < n - 1; i++){
        if (p[i] > lengthL){
            lengthL = p[i];
            centerL = i;
        }
    }

    int start = ((centerL - 1 - lengthL) / 2) + 1;
    int end = start + lengthL - 1;
    cout << start << " " << end << endl;
}