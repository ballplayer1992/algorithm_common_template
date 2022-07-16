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

    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nums_temp = nums;
        nums_temp.insert(nums_temp.end(),nums.begin(),nums.end());

        vector<int> answer(nums.size(),-1);

        monotonic_stack_interface::mono_stack stack_data;

        for (int i = 0; i < nums_temp.size(); i++)
        {
            while (!stack_data.empty() && nums_temp[i] > stack_data.top().second)
            {
                answer[stack_data.top().first % nums.size()] = nums_temp[i];
                stack_data.pop();
            }
            stack_data.push({i,nums_temp[i]});
        }
        return answer;
    }

    int maxWidthRamp(vector<int>& nums) {

        monotonic_stack_interface::mono_vector stack_data;
        stack_data.push_back({ 0,nums[0] });

        int max_width = 0,index = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            index = stack_data.size() - 1;
            if (nums[i] < stack_data[index].second)
                stack_data.push_back({ i,nums[i] });
            else
            while (index >= 0 && nums[i] >= stack_data[index].second)
            {
                max_width = max(max_width,i - stack_data[index].first);
                index--;
            }
        }
        return max_width;
    }

};

int main() {

    vector<int> nums = { 6,0,8,2,1,5 };
    int threshold = 7;

    Solution solution;
    solution.maxWidthRamp(nums);
    return 0;
}
