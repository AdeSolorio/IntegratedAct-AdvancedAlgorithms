#include "manacher.h"
#include <fstream> 
#include <iostream>
#include <string>
using namespace std; 

// to compile: g++ main.cpp manacher.cpp -o main
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

  // Searching for the longest palindrome's position
  cout << "Longest palindrome's position:" << endl;
  cout << "\nTransmission 1:" << endl;
  cout << t1 << endl;
  manacher(t1);

  cout << "\nTransmission 2:" << endl;
  cout << t2 << endl;
  manacher(t2);

  return 0;
}