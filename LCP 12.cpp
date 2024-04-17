#include <iostream>
#include <vector>
#include <numeric> // for accumulate
#include <cmath> // for floor
#include <queue> // for priority_queue

using namespace std;

class Solution {
public:
    int n = 0;
    int minTime(vector<int>& time, int mDays) {
        int maxPossibleTime = accumulate(time.begin(),time.end(),0);
        n = time.size();
        //二分蓝红分界、蓝：小于待求 红：大于等于待求 ∴返回值： 红边界
        int l = -1, r = maxPossibleTime;
        int mid = 0;
        while(l + 1 != r){
            mid = floor((l + r) / 2);
            cout << "mid: " << mid << endl;
            cout << "l: " << l << endl;
            cout << "r: " << r << endl;
            if(!check(time, mDays, mid)){//if判断 应当表示蓝色区，即m不足时
                l = mid;
                cout << "l = mid = " << mid << endl;
            }else{
                r = mid;
                cout << "r = mid = " << mid << endl;
            }
            cout << endl;
        }
        cout << "return r;"<< r << "now l: " << l << "now r: " << r << endl;
        return r;
    }
    
    bool check(vector<int>& time, int mDays, int testSum){
        int days = 1;//1 d at least
        priority_queue<int, std::vector<int>, std::greater<int>> pq;
        auto dailySum = 0;
        bool exemption = true;//ask YANG
        for(int i = 0; i < n; ++i){
            pq.push(time[i]);
            dailySum += time[i];
            if(dailySum > testSum){
                if(exemption){
                    cout << "dailySum: " << dailySum << endl;
                    dailySum -= pq.top();
                    cout << "use exemption for time: " << pq.top() << endl;
                    cout << "dailySum - pq.top() = " << dailySum << endl;
                    exemption = false;
                    cout << "exemption = false" << endl;
                }else{
                    dailySum = 0;
                    // pq.clear();
                    while (!pq.empty()) {
                        pq.pop();
                    }
                    days ++;
                    exemption = true;
                    //Important: Back to retry current question
                    --i;
                }
            }
        }
        //双重否定表肯定，应返回恰好或有余 消耗days少于等于被测t
        bool res = days <= mDays;
        cout << mDays << " Days enough for MaxTime: " << testSum << " ? " << (res ? "Yes" : "No") << endl;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> time = {1,2,7,4,7,7};
    int m = 2;
    int expected = 7;
    
    int result = sol.minTime(time, m);
    //乱码需要解决
    
    cout << "test res: " << result << endl;
    cout << "expect " << expected << endl;
    
    if (result == expected) {
        cout << "P" << endl;
    } else {
        cout << "NP" << endl;
    }
    
    return 0;
}