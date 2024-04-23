#include <algorithm>
#include <iostream>
#include <omp.h>
#include <vector>

#define THRESHOLD 1000
class Solution {
public:
    int n;
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        //令grumpy的minutes长子数组覆盖的1处对应的customers和最大。
        //修正对应grumpy位，计算满意客户数返回
        n = customers.size();
        std::vector<int> affected(n);
#pragma omp parallel for if(n > THRESHOLD)
        for (int i = 0; i < grumpy.size(); ++i) {//试并行化
            if (grumpy[i] == 1) {
                affected[i] = customers[i]; // 将grumpy为1处的customers值塞进新数组相应位置
            }
        }
        std::vector<int> mostAffectedSubarray = getMostAffectedSubarray(affected, minutes);
        auto maxIt = std::max_element(mostAffectedSubarray.begin(), mostAffectedSubarray.end());
        int bestchoice = maxIt - mostAffectedSubarray.begin();
        for(int i = bestchoice; (i < bestchoice + minutes) && (i < n); ++i) {
            grumpy[i] = 0;
        }
        int satisfied = 0;
        for (int i = 0; i < n; ++i) {
            satisfied += grumpy[i] == 0 ? customers[i] : 0;
        }
        return satisfied;
    }

    std::vector<int> getMostAffectedSubarray(std::vector<int>& affected, int minutes) {
        std::vector<int> start(n);
        int sum = 0;
        for (int i = 0; i < minutes; ++i) {
            sum += affected[i];
        }
        start[0] = sum;
        for (int i = 1; i < n - minutes + 1; ++i) {
            sum = sum - affected[i - 1] + affected[i + minutes - 1];
            start[i] = sum;
        }
        return start;
    }
};

int main() {
    std::vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    std::vector<int> grumpy = {1, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    Solution sol;
    int result = sol.maxSatisfied(customers, grumpy, minutes);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

