#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

// Definition for a binary tree node.
template<typename T>
struct TreeNode {
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(T x, TreeNode<T>* left, TreeNode<T>* right) : val(x), left(left), right(right) {}
};

template<typename T>
class Solution {
public:
    TreeNode<T>* createTree(vector<string>& nodes) {
        if (nodes.empty()) return nullptr;
        if (nodes[0] == "null") return nullptr;

        TreeNode<T>* root = new TreeNode<T>(stoi(nodes[0]));
        queue<TreeNode<T>*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode<T>* curr = q.front();
            q.pop();
            if (i < nodes.size() && nodes[i] != "null") {
                curr->left = new TreeNode<T>(stoi(nodes[i]));
                q.push(curr->left);
            }
            ++i;
            if (i < nodes.size() && nodes[i] != "null") {
                curr->right = new TreeNode<T>(stoi(nodes[i]));
                q.push(curr->right);
            }
            ++i;
        }
        return root;
    }

    TreeNode<T>* createTreeFromLevelOrder(vector<T>& nums) {
        vector<string> nodes;
        for (T num : nums) {
            nodes.push_back(num == numeric_limits<T>::min() ? "null" : to_string(num));
        }
        return createTree(nodes);
    }
};

int main() {
    Solution<int> solution;
    vector<int> nums = {1, 2, numeric_limits<int>::min(), 3, numeric_limits<int>::min(), 4, numeric_limits<int>::min(), 5};
    TreeNode<int>* root = solution.createTreeFromLevelOrder(nums);

    // 测试代码，遍历二叉树，打印结果
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode<int>* curr = q.front();
        q.pop();
        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;

    return 0;
}
