#include<string>
#include<map>
#include<algorithm>
#include<assert.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//引用自己的算法库
#include"../../algorithm_code/algorithm_common_template.h"

class Solution {
public:

    int validSubarraySize(vector<int>& nums, int threshold) {
  
        stack<monotonic_stack_interface::mono_pair> stack_data;
        //pair,第一个int表示当前值对应的最小区间，第二个int表示当前值

        for (int i = 0,pos = 0; i < nums.size(); i++)
        {
            if (nums[i] > threshold)
                return 1;

            int value = -1;
            monotonic_stack_interface::MonotonicArr(stack_data, i, nums,[&](const monotonic_stack_interface::mono_pair& m_p) {

                if (threshold / (i - m_p.first) < m_p.second)
                {
                    value = i - m_p.first;
                    return false;
                }
                return true;
            },false);
            
            if (value != -1)
                return value;
        }

        int pos = nums.size();
        while (!stack_data.empty())
        {
            int aver = threshold / (pos - stack_data.top().first);
            if (stack_data.top().second > aver)
                return pos - stack_data.top().first;
            stack_data.pop();
        }

        return -1;

    }
};

int main() {

    vector<int> nums = { 6,5,6,5,8 };
    int threshold = 7;

    Solution solution;
   int value =  solution.validSubarraySize(nums, threshold);

    return 0;
}
