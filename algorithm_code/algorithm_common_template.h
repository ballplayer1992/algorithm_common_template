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
}
