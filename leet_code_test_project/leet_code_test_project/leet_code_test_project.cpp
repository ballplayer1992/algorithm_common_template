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
#include"../../algorithm_code/algorithm_common_template.h"

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<int> node_in_array(edges.size(), 0);
        vector<bool> visit_flag(edges.size(), false);

        for (int i = 0; i < edges.size(); i++)
            if (edges[i] != -1)
                node_in_array[edges[i]]++; //记录入边数量

        vector<int> no_in_edge_node;
        for (int i = 0; i < node_in_array.size(); i++)
            if (node_in_array[i] == 0)
                no_in_edge_node.push_back(i);

        //拆除所有没有入边的节点
        int count = 0;
        while (!no_in_edge_node.empty()) {
            int index = no_in_edge_node.back();
            no_in_edge_node.pop_back();
            if (index != -1 && node_in_array[index] >= 0 && --node_in_array[index] <= 0) {
                no_in_edge_node.push_back(edges[index]);
                visit_flag[index] = true;
                count++;
            }
        }

        if (count == edges.size())
            return -1;

        int ans = 0;

        for (int i = 0; i < node_in_array.size(); i++) {
            if (visit_flag[i])
                continue;
            vector<int> index_queue(1, i);
            int layer = 0;
            while (!index_queue.empty()) {
                int index = index_queue[0];
                index_queue.erase(index_queue.begin());
                if (index == i && layer != 0)
                    break;

                layer++;
                visit_flag[index] = true;
                index_queue.push_back(edges[index]);
            }
            ans = max(ans, layer);
        }
        return ans;
    }
};

int main() {

    string test_path = "data_example//example.txt";
    string data;
    help_interface::ReadTextFile(test_path, data);

    vector<int> nums1;

    help_interface::StringDataToArrayData(data, nums1);

    Solution solution;
    solution.longestCycle(nums1);
    return 0;
}
