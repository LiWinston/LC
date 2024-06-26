// Description: LeeCode 2370. Longest Ideal String
/*给你一个由小写字母组成的字符串 s ，和一个整数 k 。如果满足下述条件，则可以将字符串 t 视作是 理想字符串 ：

t 是字符串 s 的一个子序列。
t 中每两个 相邻 字母在字母表中位次的绝对差值小于或等于 k 。
返回 最长 理想字符串的长度。

字符串的子序列同样是一个字符串，并且子序列还满足：可以经由其他字符串删除某些字符（也可以不删除）但不改变剩余字符的顺序得到。

注意：字母表顺序不会循环。例如，'a' 和 'z' 在字母表中位次的绝对差值是 25 ，而不是 1 。
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        int ans = 0;

        return ans;
    }
};
int main() {
    Solution sol;

    std::string s1 = "acfgbd";
    int k1 = 2;
    std::cout << "Test Case 1: " << sol.longestIdealString(s1, k1) << std::endl;

    std::string s2 = "abcd";
    int k2 = 3;
    std::cout << "Test Case 2: " << sol.longestIdealString(s2, k2) << std::endl;

    return 0;
}