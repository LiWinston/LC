#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX
#include <string>
using namespace std;

class Solution {
public:
    int minCharacters(string a, string b) {
        int m = a.size(), n = b.size();

        int acnt[26] = {0}, bcnt[26] = {0};
        for (char c : a) acnt[c - 'a']++;
        for (char c : b) bcnt[c - 'a']++;

        int asum = 0, bsum = 0;

        int asamll = INT_MAX, bsamll = INT_MAX, equal = INT_MAX;
        for (int i = 0; i < 25; ++i) {
            asum += acnt[i];
            bsum += bcnt[i];

            asamll = min(asamll, m - asum + bsum);
            bsamll = min(bsamll, n - bsum + asum);
            equal = min(equal, m + n - acnt[i] - bcnt[i]);
        }
        equal = min(equal, m + n - acnt[25] - bcnt[25]);

        return min(min(asamll, bsamll), equal);
    }
};

void testSolution() {
    Solution sol;

    // 使用 push_back 初始化 vector
    vector<pair<string, string> > testCases;
    testCases.push_back(make_pair("aba", "caa"));
    testCases.push_back(make_pair("dabadd", "cda"));
    testCases.push_back(make_pair("abc", "def"));
    testCases.push_back(make_pair("aaa", "bbb"));
    testCases.push_back(make_pair("xyz", "xyz"));
    testCases.push_back(make_pair("a", "b"));

    // 使用 push_back 初始化 vector
    vector<int> expectedResults;
    expectedResults.push_back(2);
    expectedResults.push_back(3);
    expectedResults.push_back(3);
    expectedResults.push_back(3);
    expectedResults.push_back(0);
    expectedResults.push_back(1);

    for (size_t i = 0; i < testCases.size(); ++i) {
        const string& a = testCases[i].first;
        const string& b = testCases[i].second;
        int result = sol.minCharacters(a, b);
        cout << "Test case " << i + 1 << " with a = " << a << " and b = " << b << " : ";
        if (result == expectedResults[i]) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed (Expected " << expectedResults[i] << ", got " << result << ")" << endl;
        }
    }
}

int main() {
    testSolution();
    return 0;
}
