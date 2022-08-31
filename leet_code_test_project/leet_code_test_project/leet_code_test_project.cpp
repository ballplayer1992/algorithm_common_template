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
    int numRollsToTarget(int n, int m, int target) {
        //分组背包  |||| 物品数--->总价值情况数--->决策数
        vector<vector<int>> ans(n+1,vector<int>(target+1,0));
        ans[0][0] = 1;
        for(int i = 1; i <=n; ++i)
            for(int j = 1;j<=target;++j)
                for (int k = 1; k <= m; ++k) {
                    if (j >= k) {
                        ans[i][j] = (ans[i][j] + ans[i - 1][j - k])%mod;
                    }
                }
        return ans[n][target];
    }
};

int main() {

    string test_path = "data_example//example.txt";
    string data;
    help_interface::ReadTextFile(test_path, data);
    vector<int> tasks;
    help_interface::StringDataToArrayData(data, tasks);
    
    Solution s;
    s.numRollsToTarget(30, 30,500);
    return 0;
}
