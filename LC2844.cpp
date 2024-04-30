#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        auto cmp = [](int a, int b) { return a > b; };
        priority_queue<int, vector<int>, decltype(cmp)> res(cmp);
    
        if(num == "0") return 0;
        //5结尾 允许25 75，0结尾 允许00 50
        vector<int> v; v.reserve(num.size());
        for(char ch : num) {
            v.push_back(ch - '0');
        }
        auto itt = v.rbegin();
        auto possileRes = 0;
        auto baseEnd = 0;
        for(auto it = itt; it != v.rend(); ++it,++baseEnd){
            possileRes = baseEnd;
            while(it != v.rend()){
                if(*it != 5 && *it != 0){
                    ++possileRes;++it;
                    continue;
                }
                break;
            }
            int end = *it;
            for(; it != v.rend(); ++possileRes,++it){
                if((end == 0 && (*it == 5 || *it == 0)) || (end == 5 && (*it == 2 || *it == 7))) {
                    res.push(possileRes);
                }
            }
        }
        return res.top();
    }
};


int main() {
    Solution solution;

    // 第一个测试用例
    string num1 = "100100100";
    cout << solution.minimumOperations(num1) << endl;

    // 第二个测试用例
    string num2 = "1001001001";
    cout << solution.minimumOperations(num2) << endl;

    return 0;
}