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

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> temp(s.size(),0);
        Difference<vector<int>> difference(temp);
        for (auto& v : shifts) {
            difference.Increment(v[0], v[1], v[2] * 2 - 1);
        }
        vector<int> diff_result(temp.size());
        difference.Result(diff_result);
        for (int i = 0; i < s.size(); ++i) {
            s[i] = ((s[i] - 'a' + diff_result[i]) % 26 + 26) % 26 + 'a';
        }
        return s;
    }
};

int main() {

    //string test_path = "data_example//example.txt";
    //string data;
    //help_interface::ReadTextFile(test_path, data);
    //help_interface::StringDataToArrayData(data, nums1);
    string str = "abc";
    vector<vector<int>> in_arr = { {0, 1, 0}, {1, 2, 1}, {0, 2, 1} };
    Solution s;
    s.shiftingLetters(str, in_arr);
    return 0;
}
