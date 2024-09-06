#include <iostream>
#include <string>
#include <vector>
#include "lcs.h"

/* Longest Common Substring using Dynamic Programming */

std::pair<int, int> lcs(const std::string& str1, const std::string& str2) {
    int size1 = str1.size();
    int size2 = str2.size();

    std::vector<std::vector<int>> dpMatrix(size1 + 1, std::vector<int>(size2 + 1, 0));

    int maxLength = 0;
    int endIndex1 = 0;
    int endIndex2 = 0;

    //As we are creating a matrix and iterating trough the entire matrix
    //we conclude that we have a time and space complexity of:
    //Space complexity: O(mn)
    //Time complexity:  O(mn)
    for (int i = 1; i <= size1; ++i) {
        for (int j = 1; j <= size2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dpMatrix[i][j] = dpMatrix[i - 1][j - 1] + 1;
                //instead of keeping the mazimum value std::max
                //we have to do an if because we also need to update our indexes when we find a new max
                if (dpMatrix[i][j] > maxLength) { 
                    maxLength = dpMatrix[i][j];
                    endIndex1 = i - 1;
                    endIndex2 = j - 1;
                }
            }
            else {
                dpMatrix[i][j] = 0;
            }
        }
    }

    int startIndex1 = endIndex1 - maxLength + 1;
    int startIndex2 = endIndex2 - maxLength + 1;

    return { startIndex1, endIndex1 };
}

void lcsCaller(const std::string& t1, const std::string& t2) {
    auto indices = lcs(t1, t2);

    int startIndex = indices.first;
    int endIndex = indices.second;
    int length = endIndex - startIndex + 1;

    std::cout << "The longest common substring starts at index " << startIndex
        << " and ends at index " << endIndex
        << ", with length: " << length << std::endl;
    std::cout << "Longest common substring: \""
        << t1.substr(startIndex, length) << "\"" << std::endl;
}
