#include<string>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<assert.h>
#include<vector>
#include<stack>
#include<set>
#include <stdio.h>
#include<bit>
#include<bitset>
#include<cstdint>
#include<iostream>
using namespace std;

//引用自己的算法库
#include"../../algorithm_code/algorithm_common_template.hpp"
using namespace math_interface;

const int mod = 1e9 + 7;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_value = nums[0];
        vector<int> index_arr(nums.size(),0);
        for (int i = 1; i < nums.size(); ++i) {
            index_arr[i] = i;
            max_value |= nums[i];
        }
        int ans = 0;
        for(int i = 1; i <= nums.size();++i)
            Combine<vector<int>>(index_arr, i, [&](const vector<int>& temp) {
            int value = nums[temp[0]];
            for (int i = 1; i < temp.size(); ++i)
                value |= nums[temp[i]];
            if (value == max_value)
                ++ans;
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
    
    vector<int> mat = { 3,1 };
    Solution s;
    s.countMaxOrSubsets(mat);
    return 0;
}
