#include "manacher.h"
#include <string>

// to compile: g++ main.cpp manacher.cpp -o main
// to run: ./main

// falta hacer que lea los archivos
// falta que imprima los resultados de cada archivo

int main(){
  std::string s = "abacdfgdcabba123321efedcba4567654abcdedcba098890fedcbaabcdefedcba0123210fabacaf";
  manacher(s);
  return 0;
}