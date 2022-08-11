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

class Solution {
public:
    bool validPartition(vector<int>& a) {
        vector<bool> dp(a.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] == a[i - 1] && dp[i - 1] || i > 1 && dp[i - 2] && (a[i] == a[i - 1] && a[i - 1] == a[i - 2]
                || a[i] == a[i - 1] + 1 && a[i - 1] == a[i - 2] + 1))
                dp[i + 1] = true;
        }
        return dp[a.size()];
    }
};

int main() {

    //string test_path = "data_example//example.txt";
    //string data;
    //help_interface::ReadTextFile(test_path, data);

    vector<int> nums1 = { 993335,993336,993337,993338,993339,993340,993341 };

    //help_interface::StringDataToArrayData(data, nums1);

    Solution solution;
    solution.validPartition(nums1);
    return 0;
}
