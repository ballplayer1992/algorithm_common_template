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

/*
输入：nums = [1, 0, 2, 1, 3]
输出：[3, 3, 2, 2, 1]
1、使用 | 的性质， 如果 a | b == a, 那么 b是被a包含的关系
2、求出 nums[i] 到 nums[nums.size() - 1] 之间 ，或值最大的最短连续子数组

*/

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        vector<pair<int, int>> ors; //存储最大的位或值 + 对应的最小索引
        for (int i = nums.size() - 1; i >= 0; --i) {
            ors.emplace_back(0, i);
            ors[0].first |= nums[i];
            int k = 0;
            for (int j = 1; j < ors.size(); ++j) {
                ors[j].first |= nums[i];
                if (ors[j].first == ors[k].first)
                    ors[k].second = ors[j].second;
                else ors[k++] = ors[j];
            }
            ors.resize(static_cast<size_t>(k) + 1);
            ans[i] = ors[0].second - i + 1;
        }
        return ans;
    }
};

int main() {
    //string test_path = "data_example//example.txt";
    //string data;
    //help_interface::ReadTextFile(test_path, data);
    //help_interface::StringDataToArrayData(data, nums1);
    vector<int> nums = { 1,0,2,1,3 };
    Solution s;
    s.smallestSubarrays(nums);
    return 0;
}
