#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <fstream> 

#include "KMP.h"


//Compute Prefix Function
//Generates the list of how many steps of the pattern can be skipped
//O(m)
vector<int> CPF(string& pattern){
  int m = pattern.size();
  vector<int> prefix(m);
  int k = 0;

  for(int q = 1; q < m; q++){
    while(k > 0 && pattern[k] != pattern[q]){
      k = prefix[k - 1];
    }

    if(pattern[k] == pattern[q]){
      k = k + 1;
    }

    prefix[q] = k;
  }

  return prefix;
}

//KMP Search
//Searches the pattern throughout the text
//O(m + n)
bool KMP(string& text, string& pattern){
  int n = text.size();
  int m = pattern.size();
  vector<int> prefix = CPF(pattern);
  int q = 0;

  for(int i = 0; i < n; i++){
    while(q > 0 && pattern[q] != text[i]){
      q = prefix[q - 1];
    }

    if(pattern[q] == text[i]){
      q = q + 1;
    }

    if(m == q){
      cout << "true " << i - m + 1 << endl;
      return true;
    }
  }

  cout << "false" << endl;
  return false;
}


//Calls all function variations
//O(p(m + n))
void KMPCaller(string& t1, string& t2, string& m1, string& m2, string& m3){
  KMP(t1, m1);
  KMP(t1, m2);
  KMP(t1, m3);
  KMP(t2, m1);
  KMP(t2, m2);
  KMP(t2, m3);

}