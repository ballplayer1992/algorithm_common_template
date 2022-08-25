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
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                if (matrix[i][j] == '1') {
                    int cnt = 1,k = j+1;
                    for (; k < cols; ++k)
                        if (matrix[i][k] == '1')
                            ++cnt;
                        else break;

                    vector<int> size_array(cnt,0);
                    int min_value = INT_MAX;
                    for (int n = j; n < cols && n < k; ++n) {
                        int cnt = 1;
                        for (int m = i + 1; m < rows; ++m)
                            if (matrix[m][n] == '1')
                                ++cnt;
                            else break;
                        size_array[k - n - 1] = cnt;
                    }

                    stack<int> st;
                    for (int index = 0; index < size_array.size(); ++index) {
                        while (!st.empty() && size_array[index] > size_array[st.top()]) {
                            
                        }
                    }


                    ans = max(min_value * cnt, ans);
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
    vector<vector<char>> in_arr = { 
{'1','1','1','1','1','1','1','1'},
{'1','1','1','1','1','1','1','0'},
{'1','1','1','1','1','1','1','0'},
{'1','1','1','1','1','0','0','0'},
{'0','1','1','1','1','0','0','0'} };
    Solution s;
    s.maximalRectangle(in_arr);
    return 0;
}
