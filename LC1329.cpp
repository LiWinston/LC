#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHangDuo;
    int hang;
    int lie;
    int shorter;
    int longer;
    vector<int> sortingValWorkspace;
    static void visualizeMatrix(const vector<vector<int>>& mat) {
        for (const auto& row : mat) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    vector<vector<int> > diagonalSort(vector<vector<int> > &mat) {
        hang = mat.size();
        lie = mat[0].size();
        bool isHangDuo = (hang - lie) >= 0;
        shorter = isHangDuo ? lie : hang;
        longer = isHangDuo ? hang : lie;
        sortingValWorkspace.reserve(shorter);

        for (int s = 0; s < hang; ++s) {
            singleDiagonalSort(mat, s, 0);
        }
        for (int r = 1; r < lie; ++r) {
            singleDiagonalSort(mat, 0, r);
        }
        return mat;
    }

    void singleDiagonalSort(vector<vector<int> > &mat, int i, int j) {
        sortingValWorkspace.clear();
        for (; i < hang && j < lie; ++i, ++j) {
            sortingValWorkspace.push_back(mat[i][j]);
        }
        auto cmp = [](int a, int b) { return a >= b; };
        stable_sort(sortingValWorkspace.begin(), sortingValWorkspace.end(), cmp);

        --i;
        --j;
        for (int k = 0; k < sortingValWorkspace.size(); ++k, --i, --j) {
            mat[i][j] = sortingValWorkspace[k]; // 更新 mat 中的对角线元素
        }
    }
};


int main() {
    Solution solution;

    // 第一个测试用例
    vector<vector<int>> mat1 = {
        {3, 3, 1, 1},
        {2, 2, 1, 2},
        {1, 1, 1, 2}
    };
    cout << "Original Matrix 1:" << endl;
    solution.visualizeMatrix(mat1);
    vector<vector<int>> result1 = solution.diagonalSort(mat1);
    cout << "Sorted Matrix 1:" << endl;
    solution.visualizeMatrix(result1);
    cout << "Test Case 1:" << endl;
    if (result1 == vector<vector<int>>{{1, 1, 1, 1}, {1, 2, 2, 2}, {1, 2, 3, 3}}) {
        cout << "Passed" << endl<< endl;
    } else {
        cout << "Failed" << endl<< endl;
    }

    // 第二个测试用例
    vector<vector<int>> mat2 = {
        {11, 25, 66, 1, 69, 7},
        {23, 55, 17, 45, 15, 52},
        {75, 31, 36, 44, 58, 8},
        {22, 27, 33, 25, 68, 4},
        {84, 28, 14, 11, 5, 50}
    };
    cout << "Original Matrix 2:" << endl;
    solution.visualizeMatrix(mat2);
    vector<vector<int>> result2 = solution.diagonalSort(mat2);
    cout << "Sorted Matrix 2:" << endl;
    solution.visualizeMatrix(result2);
    cout << "Test Case 2:" << endl;
    if (result2 == vector<vector<int>>{{5, 17, 4, 1, 52, 7}, {11, 11, 25, 45, 8, 69},
                                       {14, 23, 25, 44, 58, 15}, {22, 27, 31, 36, 50, 66},
                                       {84, 28, 75, 33, 55, 68}}) {
        cout << "Passed" << endl<< endl;
                                       } else {
                                           cout << "Failed" << endl<< endl;
                                       }

    return 0;
}
