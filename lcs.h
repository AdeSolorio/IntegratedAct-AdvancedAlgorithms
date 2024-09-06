#pragma once
#ifndef LCS_H
#define LCS_H

#include <iostream>
#include <string>
#include <utility>

std::pair<int, int> lcs(const std::string& s1, const std::string& s2);
void lcsCaller(const std::string& t1, const std::string& t2);

#endif // LCS_H