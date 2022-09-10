#include<string>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<assert.h>
#include<vector>
#include<stack>
#include<set>
#include <stdio.h>
#include<bit>
#include<bitset>
#include<cstdint>
#include<iostream>
#include<functional>
using namespace std;

//引用自己的算法库
#include"../../algorithm_code/algorithm_common_template.hpp"
using namespace math_interface;

const int mod = 1e9 + 7;

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int d = abs(startPos - endPos);
        if (d > k || d % 2 != k % 2)
            return 0;
        return Combine(k,(k+d)/2);
    }
};

int main() {

    string test_path = "data_example//example.txt";
    string data;
    help_interface::ReadTextFile(test_path, data);
    vector<int> tasks;
    help_interface::StringDataToArrayData(data, tasks);
    
    vector<int> mat = { 3,1 };
    Solution s;
    int ans = s.numberOfWays(989,1000,99);
    return 0;
}
