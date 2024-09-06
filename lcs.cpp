#include <iostream>
#include <string>
#include <vector>
#include "lcs.h"

/* Longest Common Substring using Dynamic Programming */

// Function to find the longest common substring
// As this function is in charge of finding the lcs in two strings, it will go trought
// both length of the strings, and saving the longest substring found in a dp Matrix in order to
// not repeat the same calculations, thus we can conclude that creating the matrix
// and going trought the strings will be a complexity: s
// Space complexity: O(mn)
// Time complexity:  O(mn)
std::pair<int, int> lcs(const std::string &str1, const std::string &str2) {
    int size1 = str1.size();
    int size2 = str2.size();

    if (size1 == 0 || size2 == 0) {
        return std::make_pair(-1, -1);
    }

    std::vector<std::vector<int>> dpMatrix(size1 + 1, std::vector<int>(size2 + 1, 0));

    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= size1; ++i) {
        for (int j = 1; j <= size2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dpMatrix[i][j] = dpMatrix[i - 1][j - 1] + 1;
                if (dpMatrix[i][j] > maxLength) {
                    //instead of keeping the maximun value with only std::max
                    //we have to do an if, in order to update our max value
                    //and the end index of the substring
                    maxLength = dpMatrix[i][j];
                    endIndex = i - 1;
                }
            } else {
                dpMatrix[i][j] = 0;
            }
        }
    }

    if (maxLength == 0) {
        return std::make_pair(-1, -1);
    }

    int startIndex = endIndex - maxLength + 1;

    return std::make_pair(startIndex, endIndex);
}

// Function to call the lcs function and print the results
void lcsCaller(const std::string &t1, const std::string &t2) {
    std::pair<int, int> indices = lcs(t1, t2);

    int startIndex = indices.first;
    int endIndex = indices.second;

    std::cout << "\nLongest common substring found:" << std::endl;
    if (startIndex == -1) {
        std::cout << "No common substring found" << std::endl;
    } else {
        // Indexes on transmission 1
        std::cout << startIndex << " " << endIndex << std::endl;
    }
}
