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
        
        
//        sort(nums1.begin(), nums1.end(), std::less());
        for (int i = 0; i < size; i++) {
            std::cout << "matching " << i << "th ele in Arr2." << std::endl;
            auto it = upper_bound(nums1.begin(), nums1.end(), nums2[i]);
            if (it != nums1.end()) {
                res[i] = *it;
                auto it2 = nums1St.find(*it);
                std::cout << "it2: " << *it2 << std::endl;
                it2 = nums1St.erase(it2);
                if(it2 != nums1St.end()) {
                    std::cout << *it2 << " erase success" << std::endl;
                } else {
                    std::cout << *it2 << " erase failed" << std::endl;
                }
            } else {
                vac.push_back(i);
            }
        }
        std::cout << "vac size: " << vac.size() << std::endl;
        std::cout << "Begin to fill vac with nums1St" << std::endl;
        auto it = nums1St.begin();
        for (auto i : vac) {
            std::cout << "i: " << i << std::endl;
            res[i] = *it;
            std::cout << "it: " << *it << std::endl;
            it = nums1St.erase(it);
//            if(it != nums1St.end()) {
//                std::cout << *it << "erase success" << std::endl;
//            } else {
//                std::cout << *it << "end reached" << std::endl;
////                return res;
//            }
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