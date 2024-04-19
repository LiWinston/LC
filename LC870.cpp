#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

class Solution {
public:
    static std::vector<int> advantageCount(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::multiset<int> nums1St(nums1.begin(), nums1.end());
        int size = nums1.size();
        std::vector<int> res(size);
        std::vector<int> vac;
        
        for (int i = 0; i < size; i++) {
            auto it = nums1St.upper_bound(nums2[i]);
            if (it != nums1St.end()) {
                res[i] = *it;
                nums1St.erase(it);
            } else {
                vac.push_back(i);
            }
        }
        std::vector<int> remain(nums1St.begin(), nums1St.end());
        auto it = remain.begin();
//        auto it = nums1St.begin();
        for (auto i : vac) {
            res[i] = *it;
            it = std::next(it);
        }
        return res;
    }
};

int main() {
    std::vector<int> nums1 = {2,0,4,1,2};
    std::vector<int> nums2 = {1,3,0,0,2};
    
    Solution sol;
    std::vector<int> result = sol.advantageCount(nums1, nums2);
    
    std::cout << "Result: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}