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
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int j = i - 1,value = nums[i];
            for (; j >= 0; --j)
                if ((value & nums[j]) == 0)
                    value |= nums[j];
                else 
                    break;
            ans = max(ans, i - j);
        }
        return ans;
    }

};

int main() {

    string test_path = "data_example//example.txt";
    string data;
    help_interface::ReadTextFile(test_path, data);
    vector<int> tasks;
    help_interface::StringDataToArrayData(data, tasks);
    
    vector<int> nums = { 893803453, 60543633, 85309607, 348377798, 696815256, 916582942, 991112444, 736712017, 916399634, 744677522, 274332240, 119047370, 542000876, 256170455, 16, 8192, 2, 8, 96, 128, 135168, 67108864, 171021977, 498052009, 509664323, 119776370, 938908623, 387770982, 863736718, 622916572, 773798777, 252211255, 972969388, 247290894, 341468520, 185997261, 621380930, 426480917 };
    Solution s;
    s.longestNiceSubarray(nums);
    return 0;
}
