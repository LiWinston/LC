#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isHangDuo;
    int shorter;
    int longer;
    // vector<vector<int>> defaulmat;
    // vector<vector<int>>& mmat = defaulmat;
    vector<int *> sortingWorkspace;
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
        // this->mmat = std::move(mat);
        int hang = mat.size();
        int lie = mat[0].size();
        bool isHangDuo = (hang - lie) >= 0;
        shorter = isHangDuo ? lie : hang;
        longer = isHangDuo ? hang : lie;
        sortingWorkspace.reserve(shorter);
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
        sortingWorkspace.clear();
        for (; i < shorter && j < shorter; ++i, ++j) {
            sortingWorkspace.push_back(&mat[i][j]);
        }
        auto cmp = [](const int *a, const int *b) { return *a >= *b; };
        stable_sort(sortingWorkspace.begin(), sortingWorkspace.end(), cmp);
        sortingValWorkspace.resize(sortingWorkspace.size());
        // sortingValWorkspace.clear();
        for (int v = sortingWorkspace.size() - 1; v >= 0; --v) {
            cout << *sortingWorkspace[v] << " ";
            sortingValWorkspace[v] = *sortingWorkspace[v];
        }

        --i;
        --j;
        for (int k = 0; k < sortingValWorkspace.size(); ++k, --i, --j) {
            mat[i][j] = (sortingValWorkspace[k]); // 更新 mat 中的对角线元素
        }
        cout << endl;
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

    return 0;
}
