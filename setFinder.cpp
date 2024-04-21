#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans;
        int alzSum = accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int bobSum = accumulate(bobSizes.begin(),bobSizes.end(),0);
        int diff = alzSum - bobSum;

        int compensation = diff / 2;

        multiset<int> bobSet(bobSizes.get_allocator());

        for(int i : aliceSizes){
            if(bobSet.find(i - compensation) != bobSet.end()) {
            //if(find(bobSizes.begin(), bobSizes.end(), i - compensation) != bobSizes.end()) {
                ans.push_back(i);
                ans.push_back(i - compensation);
                return ans;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> aliceSizes = {1, 1};
    vector<int> bobSizes = {2, 2};
    Solution sol;
    vector<int> result = sol.fairCandySwap(aliceSizes, bobSizes);
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}