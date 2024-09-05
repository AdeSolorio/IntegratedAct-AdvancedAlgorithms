#ifndef KMP_H
#define KMP_H

#include <string>
#include <vector>

std::vector<int> CPF(std::string& pattern);
bool KMP(std::string& text, std::string& pattern);
void KMPCaller(std::string& t1, std::string& t2, std::string& m1, std::string& m2, std::string& m3);

#endif // KMP_H