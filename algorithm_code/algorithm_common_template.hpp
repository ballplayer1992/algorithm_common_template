#pragma once
#include<fstream>
#include<vector>
#include<string>
#include<stack>
#include<functional>
using namespace std;

namespace help_interface {

    void ReadTextFile(const string& str_path, string& str_data);
    void StringDataToArrayData(const string& str_data, vector<int>& nums);
}

namespace k_m_p_interface //kmp匹配算法
{
    //https://blog.csdn.net/yutong5818/article/details/81319120
    /// <summary>
    /// 计算 next 数组
    /// </summary>
    void MakeNext(const string& char_arr, vector<int>& next_arr);

    /// <summary>
    /// kmp算法计算匹配的子集，返回所在t_arr 数组的索引值
    /// </summary>
    /// <returns></returns>
    int KMPMatchSubSet(const string& t_arr, const string& s_arr);

}

namespace monotonic_stack_interface //单调栈
{
    struct data
    {
        int value = 0; //数组下标对应的值
        int back_data = 0;//存储当前变量的可用的历史变化数据
        data() {}
        data(int v, int c_d) { value = v; back_data = c_d; }
    };

    using mono_data = struct data;
    using mono_array = vector<mono_data>;
    using mono_pair = pair<int, mono_data>; //索引(用于记录区间)，数组值
    using OnProcessOtherThing = std::function<bool(const mono_pair& m_p)>;
    using mono_stack = stack<mono_pair>;
    using mono_vector = vector<mono_pair>;
}

namespace math_interface
{
    /// <summary>
    /// 10进制转N进制
    /// </summary>
    /// <param name="uiSrc">10进制数</param>
    /// <param name="iBase">n进制</param>
    /// <param name="pOutStr">字符串结果返回</param>
    /// <returns></returns>
    int static Base10ToBaseN(unsigned int uiSrc, int iBase, char* pOutStr) {
        unsigned char ABCchane[37] = { 'A','B','C','D','E','F','G','H','I','J','K',
        'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
        unsigned int divide_num = uiSrc, left_num = 0;
        unsigned char pResult[100] = { 0 };
        int i = 0, j = 0;
        while (1) {
            left_num = divide_num % iBase;
            divide_num = divide_num / iBase;
            if (left_num > 9)
                pResult[i] = left_num - 10 + 'A';
            else
                pResult[i] = left_num + '0';
            if (divide_num == 0)
                break;
            i++;
        }
        for (j = 0; j <= i; j++)
            *(pOutStr + j) = pResult[i - j];
        return 0;
    }

    /// <summary>
    /// 求 a 和 b 的最大公约数
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns>返回最大公约数</returns>
    template<class T>
    T gcd(T a, T b)
    {
        T r;
        while (a)
        {
            r = b % a;
            b = a;
            a = r;
        }
        return b;
    }

    /// <summary>
    /// 求 a 和 b 的最小公倍数
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns>返回最新公倍数</returns>
    template<class T>
    T lcm(T a, T b)
    {
        return a * b / (gcd(a, b));
    }

    /// <summary>
    /// 差分数组模版
    /// </summary>
    template<class stl_container>
    class Difference {
    private:
        stl_container diff_;
    public:
        /// 初始化差分数组
        Difference(const stl_container& in) {
            assert(in.size() > 0);
            diff_.resize(in.size());
            diff_[0] = in[0];
            for (int i = 1; i < in.size(); ++i)
                diff_[i] = in[i] - in[i - 1];
        }
        //对区间 [i,j]增加 val(val可以是负数)
        void Increment(int i, int j, int val) {
            diff_[i] += val;
            if (j + 1 < diff_.size())
                diff_[j + 1] -= val;
        }
        //返回区间内值修改后的结果
        void Result(stl_container& source_arr) {
            //求前缀和
            source_arr[0] = diff_[0];
            for (int i = 1; i < diff_.size(); ++i) {
                source_arr[i] = diff_[i] + source_arr[i - 1];
            }
        }
    };

    //分组背包
    //f[i][j] 表示考虑前i个物品组，凑成价值为j的方案数。
    int static numRollsToTarget(int n, int m, int target) { //求方案为target的最大组合数
        const int mod = 1e9 + 7;
        vector<vector<int>> f(n + 1, vector<int>(target + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i)// 枚举物品组（每个骰子）
            for (int j = 1; j <= target; ++j)  // 枚举背包容量（所掷得的总点数）
                for (int k = 1; k <= m; ++k) {// 枚举决策（当前骰子所掷得的点数）
                    if (j >= k) {
                        f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
                    }
                }
        return f[n][target];
    }
}

namespace data_struct_interface {

    struct Node {
        bool visited = false;
        int node_id = -1;
        vector<Node*> children_arr;
    };

    void static BFS(Node* current_node) {//通用广搜
        stack<Node*> stack_node;
        stack_node.push(current_node);
        int layer = 0;
        while (!stack_node.empty()) {
            Node* n = stack_node.top();
            n->visited = true;
            stack_node.pop();
            layer++;
            for (auto v : n->children_arr) {
                if (!v->visited)
                    stack_node.push(v);
            }
        }
    }
}
