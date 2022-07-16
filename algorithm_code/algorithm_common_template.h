#pragma once
#include<vector>
#include<string>
#include<stack>
#include<functional>
using namespace std;

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
    using mono_data = int;
    using mono_array = vector<mono_data>;
    using mono_pair = pair<int, mono_data>; //索引(用于记录区间)，数组值
    using OnProcessOtherThing = std::function<bool(const mono_pair& m_p)>;
    using mono_stack = stack<mono_pair>;
    using mono_vector = vector<mono_pair>;
    /// <summary>
    /// 单调栈通用函数
    /// </summary>
    /// <param name="stack_data">栈对象</param>
    /// <param name="index">传入要压栈的mono_array对应的索引值</param>
    /// <param name="arr_data">mono_array对象</param>
    /// <param name="is_desc">true:降序，false:升序</param>
    /// <returns></returns>
    int MonotonicArr(stack<mono_pair>& stack_data,
        int index, const mono_array& arr_data, OnProcessOtherThing on_data, bool is_desc);
}