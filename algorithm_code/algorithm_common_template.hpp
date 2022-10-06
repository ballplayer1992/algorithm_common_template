#pragma once
#include<fstream>
#include<vector>
#include<string>
#include<stack>
#include<functional>
#include<assert.h>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<assert.h>
#include<iostream>
#include<set>
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

    /// <summary>
/// 整数反转(支持负整数和正整数)
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
    int static reverse(int n) {
        bool is_fs = n < 0 ? true : false;
        vector<int> nums;
        while (n != 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        int ans = 0;
        for (auto v : nums) {
            ans *= 10;
            ans += v;
        }
        return is_fs ? -ans : ans;
    }

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

    /// <summary>
    /// 组合算法
    /// </summary>
    /// <typeparam name="T">T可以调入 vector<int> string 等 需要支持下标[]操作及size()函数</typeparam>
    /// <param name="data">数组</param>
    /// <param name="start">默认从数组data索引0开始</param>
    /// <param name="n">数组data容量</param>
    /// <param name="m">从n个数中选取m个</param>
    /// <param name="depth">递归深度，到 m-1停止,因为深度从0计数</param>
    /// <param name="temp">填写方案的容器</param>
    template <typename T>
    void Combine_Inner(T& data, int start, int n, int m,
        int depth, T temp, std::function<void(const T& result)> on_result) {
        if (depth == m - 1) {
            //最内层循环 将 temp加入result
            for (int i = start; i < n - (m - depth - 1); ++i) {
                temp[depth] = data[i];
                on_result(temp);
            }
        }
        else {
            for (int i = start; i < n - (m - depth - 1); ++i) {
                temp[depth] = data[i];//每层输出一个元素
                Combine_Inner(data, i + 1, n, m, depth + 1, temp, on_result);
            }
        }
    }
    //再分装
    template <typename T>
    void Combine(T& data, int m, std::function<void(const T& result)> on_result) {
        assert(m > 0);
        int depth = 0;
        T temp(m, 0);
        Combine_Inner<T>(data, 0, data.size(), m, depth, temp, on_result);
    }

    //从n中取m个数求组合方案总数，递推公式实现
    //用数组存储在之前重复计算的数字，然后就不用重复计算。
    const int mod = 1e9 + 7;
    long long static Combine(long long n, long long m, vector<vector<long>>& result) {
        if (m == 0 || m == n) return 1;
        if (result[n][m] != 0) return result[n][m];
        return result[n][m] = (Combine(n - 1, m, result) + Combine(n - 1, m - 1, result)) % mod;
    }
    long long static Combine(long long n, long long m) {
        vector<vector<long>> result(n + 1, vector<long>(m + 1, 0));
        return Combine(n, m, result);
    }

    //二分查找
    int static BinarySearch(const vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1,mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] < key) low = mid +1;
            else if (arr[mid] > key) high = mid - 1;
            else return mid;
        }
        return -1;
    }

    //快速幂:递归
    double static QuickMul(double x, long long n) {
        if (n == 0) return 1.0;
        long long y = QuickMul(x,n/2);
        return n % 2 == 0 ? y * y : y * y * x;
    }
    double static PowQuickMul(double x, long long n) {
        return n >= 0 ? QuickMul(x, n) : 1.0 / QuickMul(x,-n);
    }
    //快速幂: 迭代方法
    double static QuickMul_d(double x, long long n) {
        double ans = 1.0;
        double x_contribute = x;
        while (n > 0) {
            if (n % 2 == 1) ans *= x_contribute;
            x_contribute *= x_contribute;
            n /= 2;
        }
        return ans;
    }
    double static PowQuickMul_d(double x, long long n) {
        return n >= 0 ? QuickMul_d(x, n) : 1.0 / QuickMul_d(x, -n);
    }
}

namespace binary_interface {
    //<summary>
    //统计一个整形变量二进制下1的个数
    //</summary>
    //<param name="u"></param>
    //<returns></returns>
    unsigned int static __builtin_popcount(unsigned int u) {
        unsigned int ret = 0;
        while (u) {
            u = (u & (u - 1));    // 将 u 最右边的 1 清除
            ret++;
        }
        return ret;
    }

    //位或操作,一个uint型值有32个位，所以最多有32种可能情况
    //位或模板
    //1:求出所有子数组的按位或的结果，以及值等于该结果的子数组的个数
    //求按位或结果等于任意给定数字的子数组的最短长度 / 最长长度
    vector<int> static smallestSubarrays(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        vector<pair<int, int>> ors; //存储最大的位或值 + 对应的最小索引,用于存储遍历过程中生成从不同情况值，最多32种
        for (int i = nums.size() - 1; i >= 0; --i) {
            ors.emplace_back(0, i);
            ors[0].first |= nums[i];
            int k = 0;
            for (int j = 1; j < ors.size(); ++j) { //原地去重方法
                ors[j].first |= nums[i];
                if (ors[j].first == ors[k].first)
                    ors[k].second = ors[j].second; //去除重复情况
                else ors[++k] = ors[j];
            }
            ors.resize(static_cast<size_t>(k) + 1);//执行去重
            ans[i] = ors[0].second - i + 1;
        }
        return ans;
    }

    int static LowBit(int i) {
        return i & -i;//(等效于 i - i & (i - 1))
    }
    //https://blog.csdn.net/ls2868916989/article/details/119268741
    //树状数组或二叉索引树（Binary Indexed Tree），
    //又以其发明者命名为 Fenwick 树。其初衷是解决数据压缩里的累积频率的计算问题，
    //现多用于高效计算数列的前缀和、区间和。它可以以 O(logn) 的时间得到任意前缀和。
    //并同时支持在 O(logn) 时间内支持动态单点值的修改。空间复杂度 O(n)。
    class BIT {
    private:
        vector<int> tree;
    public:
        BIT(int n) :tree(n) {}
        void Update(int i, int val) { //单点更新
            while (i < tree.size()) {
                tree[i] += val;
                i += LowBit(i);
            }
        }
        int Query(int i) {//求区间[1,i]内所有元素和
            int value = 0;
            while (i > 0) {
                value += tree[i];
                i -= LowBit(i);
            }
            return value;
        }
    };

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
