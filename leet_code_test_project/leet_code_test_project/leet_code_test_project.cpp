#include<string>
#include<map>
#include<unordered_map>
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

const int mod = 1e9 + 7;

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        vector<int> col_array(mat[0].size(),0);
        for (int i = 0; i < col_array.size(); ++i)
            col_array[i] = i;
        int ans = 0;
        Combine<vector<int>>(col_array, cols, [&](const vector<int>& result) {
            vector<vector<int>> temp = mat;
            for (int i = 0; i < result.size(); ++i)
                for (int row = 0; row < mat.size(); ++row)
                    temp[row][result[i]] = 0;
            int max_value = 0;
            for (int i = 0; i < mat.size(); ++i) {
                int cnt = 0;
                for (int j = 0; j < mat[0].size(); ++j)
                    cnt += temp[i][j];
                if (cnt == 0)
                    max_value++;
            }
            ans = max(ans, max_value);
            });
        return ans;
    }
};

int main() {

    string test_path = "data_example//example.txt";
    string data;
    help_interface::ReadTextFile(test_path, data);
    vector<int> tasks;
    help_interface::StringDataToArrayData(data, tasks);
    
    vector<vector<int>> mat = { {0,0,0},{1,0,1},{0,1,1},{0,0,1} }; int cols = 2;
    Solution s;
    s.maximumRows(mat, cols);
    return 0;
}
