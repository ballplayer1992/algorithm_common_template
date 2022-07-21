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
    int largestRectangleArea(vector<int>& heights) {
        monotonic_stack_interface::mono_stack stack_data;
        int max_area = 0;
        for (int a = 0; a < heights.size(); a++)
        {
            int count_eat_index = 0;
            while (!stack_data.empty() && heights[a] < stack_data.top().second.value)
            {
                int current_area = (a - stack_data.top().first + stack_data.top().second.back_data) * stack_data.top().second.value;
                current_area = max(current_area, heights[a] * ((a - stack_data.top().first) + 1));
                if (current_area > max_area)
                    max_area = current_area;
                count_eat_index = (a - stack_data.top().first) + stack_data.top().second.back_data;
                stack_data.pop();
            }
            stack_data.push({ a,{heights[a],count_eat_index} });
        }
        int index = stack_data.top().first + 1;
        while (!stack_data.empty())
        {
            int current_area = (index - stack_data.top().first + stack_data.top().second.back_data) * stack_data.top().second.value;
            if (current_area > max_area)
                max_area = current_area;
            stack_data.pop();
        }
        return max_area;
    }
};

int main() {

    vector<int> height_arr = { 4,2,3 };
    Solution solution;
    solution.largestRectangleArea(height_arr);
    return 0;
}
