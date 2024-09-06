#include <iostream>
using namespace std; 

#include <fstream> 
#include <string>

#include "manacher.h"
#include "KMP.h"
#include "lcs.h"

// to compile: g++ main.cpp KMP.cpp manacher.cpp lcs.cpp -o main
// to run: ./main

int main(){
  // Reading the transmission1 file
  ifstream transmission1("transmission1.txt"); 
  if (!transmission1.is_open()) { 
    cerr << "Error opening the transmission1 file!" << endl; 
    return 1; 
  } 
  string t1;
  string line;
  while (getline(transmission1, line)) { 
    t1 += line;
  } 
  transmission1.close();


  // Reading the transmission2 file
  ifstream transmission2("transmission2.txt"); 
  if (!transmission2.is_open()) { 
    cerr << "Error opening the transmission2 file!" << endl; 
    return 1; 
  } 
  string t2;
  string line2;
  while (getline(transmission2, line2)) { 
    t2 += line2;
  } 
  transmission2.close();


  // Reading the mCode1 file
  ifstream mCode1("mCode1.txt"); 
  if (!mCode1.is_open()) { 
    cerr << "Error opening the mCode1 file!" << endl; 
    return 1; 
  } 
  string m1;
  string line3;
  while (getline(mCode1, line3)) { 
    m1 += line3;
  } 
  mCode1.close();


  // Reading the mCode2 file
  ifstream mCode2("mCode2.txt"); 
  if (!mCode2.is_open()) { 
    cerr << "Error opening the mCode2 file!" << endl; 
    return 1; 
  } 
  string m2;
  string line4;
  while (getline(mCode2, line4)) { 
    m2 += line4;
  } 
  mCode2.close();


  // Reading the mCode3 file
  ifstream mCode3("mCode3.txt"); 
  if (!mCode3.is_open()) { 
    cerr << "Error opening the mCode3 file!" << endl; 
    return 1; 
  } 
  string m3;
  string line5;
  while (getline(mCode3, line5)) { 
    m3 += line5;
  } 
  mCode3.close();

  // Searching for the malicious code in the transmission
  KMPCaller(t1, t2, m1, m2, m3);

  // Searching for the longest palindrome's position
  manacherCaller(t1, t2);

  // Searching for the longest common substring in the transmission
  lcsCaller(t1, t2);

  return 0;
}