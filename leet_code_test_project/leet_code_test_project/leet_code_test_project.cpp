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

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {

        int max_gcd = numsDivide[0];
        for (auto& v : numsDivide)
            max_gcd = math_interface::gcd<int>(max_gcd,v);

        sort(nums.begin(),nums.end());

        for (int a = 0; a < nums.size(); a++)
        {
            if (max_gcd % nums[a] == 0)
                return a;

            if (nums[a] > max_gcd)
                return -1;
        }
        return -1;
    }
};

int main() {

    Solution solution;
    return 0;
}
