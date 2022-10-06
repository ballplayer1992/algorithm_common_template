#include"../../algorithm_code/algorithm_common_template.hpp"//引用自己的算法库
using namespace math_interface;
using namespace binary_interface;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        for (int i = 0; i < nums1.size(); ++i) nums1[i] = nums1[i] - nums2[i];
        vector<int> arr = nums1;
        sort(arr.begin(), arr.end(), less<int>());
        long long ans = 0;
        BIT bit(arr.size()+1);
        for (int v : nums1) {
            //从树状数组中查找出 <= v+diff 有多少个元素  离散化处理
           int num = upper_bound(arr.begin(), arr.end(), v + diff) - arr.begin();
           ans += bit.Query(num);
           //插入当前元素索引到树状数组(如果存在相同，始终取最前面的索引(类似于相同值压缩处理))
           bit.Update(lower_bound(arr.begin(), arr.end(), v) - arr.begin()+1, 1);
        }
        return ans;
    }
};
int main() {
	Solution s;
    vector<int> nums1 = { 3,2,5 },nums2 = { 2,2,1 };
    s.numberOfPairs(nums1,nums2,1);
    return 0;
}
