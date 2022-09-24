#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<assert.h>
#include<iostream>
#include<vector>
#include<stack>
#include<set>
using namespace std;

//引用自己的算法库
#include"../../algorithm_code/algorithm_common_template.hpp"
using namespace math_interface;

/*
输入：nums = [1, 0, 2, 1, 3]
输出：[3, 3, 2, 2, 1]
1、使用 | 的性质， 如果 a | b == a, 那么 b是被a包含的关系
2、求出 nums[i] 到 nums[nums.size() - 1] 之间 ，或值最大的最短连续子数组

*/

class Solution {
public:
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        int row = plate.size(), col = plate[0].size();
        vector<vector<int>> ans;
        function<void(int, int, int, int, int, bool&, int, int)> dfs = [&](
            int fi, int fj, int ci, int cj, int depth, bool& find, int i, int j) {
            if (ci < 0 || ci >= row || cj < 0 || cj >= col || depth > num || find)
                return;
            int dx = fi - ci, dy = fj - cj;
            if (plate[ci][cj] == 'O' && depth <= num) {
                ans.push_back({ i, j });
                find = true;
            }
            else if (plate[ci][cj] == '.') {
                if (dx == -1) dfs(ci, cj, ci + 1, cj, depth + 1, find, i, j);
                else if (dx == 1)dfs(ci, cj, ci - 1, cj, depth + 1, find, i, j);
                else if (dy == -1)dfs(ci, cj, ci, cj + 1, depth + 1, find, i, j);
                else if (dy == 1)  dfs(ci, cj, ci, cj - 1, depth + 1, find, i, j);
            }
            else if (plate[ci][cj] == 'W') {
                if (dx == -1) dfs(ci, cj, ci, cj + 1, depth + 1, find, i, j);
                else if (dx == 1)dfs(ci, cj, ci, cj - 1, depth + 1, find, i, j);
                else if (dy == -1)dfs(ci, cj, ci - 1, cj, depth + 1, find, i, j);
                else if (dy == 1)  dfs(ci, cj, ci + 1, cj, depth + 1, find, i, j);
            }
            else if (plate[ci][cj] == 'E') {
                if (dx == -1) dfs(ci, cj, ci, cj - 1, depth + 1, find, i, j);
                else if (dx == 1) dfs(ci, cj, ci, cj + 1, depth + 1, find, i, j);
                else if (dy == -1) dfs(ci, cj, ci + 1, cj, depth + 1, find, i, j);
                else if (dy == 1)dfs(ci, cj, ci - 1, cj, depth + 1, find, i, j);
            }
        };

        for (int i = 1; i < row - 1; ++i) {
            if (plate[i][0] == '.') {
                bool find = false;
                dfs(i, -1, i, 0, 0, find, i, 0);
            }
            if (plate[i][col - 1] == '.') {
                bool find = false;
                dfs(i, col, i, col - 1, 0, find, i, col - 1);
            }
        }
        for (int j = 1; j < col - 1; ++j) {
            if (plate[0][j] == '.') {
                bool find = false;
                dfs(-1, j, 0, j, 0, find, 0, j);
            }
            if (plate[row - 1][j] == '.') {
                bool find = false;
                dfs(row, j, row - 1, j, 0, find, row - 1, j);
            }
        }
        return ans;
    }
};

int main() {
    //string test_path = "data_example//example.txt";
    //string data;
    //help_interface::ReadTextFile(test_path, data);
    //help_interface::StringDataToArrayData(data, nums1);
    //vector<string> ball = { "..E.",".EOW","..W." };
    vector<string> ball = { ".....","..E..",".WO..","....." };
    Solution s;
    s.ballGame(5, ball);
    return 0;
}
