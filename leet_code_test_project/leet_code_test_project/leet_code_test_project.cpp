#include"../../algorithm_code/algorithm_common_template.hpp"//引用自己的算法库
using namespace math_interface;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int ans = 1;
        for (int i = 0,k = 0; i < nums.size(); ++i) {
            ms.insert(nums[i]);
            while (abs(*ms.begin() - *ms.rbegin()) > limit)
                ms.erase(ms.find(nums[k++]));
            ans = max(ans,i - k + 1);
        }
        return ans;
    }
};

int main() {
    //string test_path = "data_example//example.txt";
    //string data;
    //help_interface::ReadTextFile(test_path, data);
    //help_interface::StringDataToArrayData(data, nums1);
    vector<int> in = { 4,2,2,2,4,4,2,2 };
    Solution s;
    s.longestSubarray(in,0);
    return 0;
}
