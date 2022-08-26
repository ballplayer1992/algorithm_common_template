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

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> mt(rows,vector<int>(cols,0));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (matrix[i][j] == '1')
                    mt[i][j] = 1;
        for (int j = 0; j < cols; ++j)
            for (int i = 1; i < rows; ++i)
                if (mt[i][j])
                    mt[i][j] += mt[i - 1][j];
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            vector<int>& temp = mt[i];
            stack<pair<int, int>>st;
            for (int index = 0; index < temp.size(); ++index) {
                int cnt_index = index;
                while (!st.empty() && temp[index] <= temp[st.top().first]) {
                    cnt_index = st.top().second;
                    ans = max(ans, (index - cnt_index + 1) * temp[index]);
                    ans = max(ans,(index - cnt_index)* temp[st.top().first]);
                    st.pop();
                }
                st.push({index,cnt_index});
            }
            if (st.size()) {
                int index = st.top().first;
                while (!st.empty()) {
                    ans = max(ans, (index - st.top().second + 1) * temp[st.top().first]);
                    st.pop();
                }
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
//    vector<vector<char>> in_arr = { 
//{'1','1','1','1','1','1','1','1'},
//{'1','1','1','1','1','1','1','0'},
//{'1','1','1','1','1','1','1','0'},
//{'1','1','1','1','1','0','0','0'},
//{'0','1','1','1','1','0','0','0'} };

    //vector<vector<char>> in_arr = { {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'} };
    vector<vector<char>> in_arr = { {'0','1','1','0','1'},
{'1','1','0','1','0'},
{'0','1','1','1','0'},
{'1','1','1','1','0'},
{'1','1','1','1','1'},
{'0','0','0','0','0'} };

    Solution s;
    s.maximalRectangle(in_arr);
    return 0;
}
