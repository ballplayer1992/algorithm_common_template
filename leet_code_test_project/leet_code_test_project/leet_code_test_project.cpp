#include<string>
#include<map>
#include<algorithm>
#include<assert.h>
#include<iostream>
#include<vector>
using namespace std;

//引用自己的算法库
#include"../../algorithm_code/algorithm_common_template.h"

class Solution {
public:

    int validSubarraySize(vector<int>& nums, int threshold) {

        for (int i = 0; i < nums.size(); i++)
        {
            int cal_subsequence_length = threshold / nums[i] + 1;
            double aver_value = threshold / static_cast<double>(cal_subsequence_length);

            int j = i - 1, k = i + 1, count = 1;
            for (bool j_stop = false, k_stop = false; (!j_stop || !k_stop) && cal_subsequence_length <= nums.size() && count < cal_subsequence_length;)
            {
                if (!j_stop && j >= 0 && nums[j] > aver_value)
                {
                    ++count; --j;
                }
                else
                    j_stop = true;

                if (!k_stop && k < nums.size() && nums[k] > aver_value)
                {
                    ++count; ++k;
                }
                else
                    k_stop = true;
            }

            if (count == cal_subsequence_length)
                return cal_subsequence_length;
        }
        return -1;
    }
};

int main() {

    //vector<int> nums = { 373,466,501,884,998,254,12,324,813,601,790,728,754,676,958,505,317,117,727,2,248,305,481,12,394,282,173,623,841,636,500,234,524,501,694,506,312,723,801 };
    //int threshold = 2228;

    //Solution solution;
    //solution.validSubarraySize(nums, threshold);

    string t_arr = { "1234561123458412" };
    string s_arr = { "611" };
    vector<int> next_arr;
    int index = k_m_p_interface::KMPMatchSubSet(t_arr, s_arr);

    return 0;
}
