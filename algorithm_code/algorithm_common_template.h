#pragma once
#include<vector>
#include<string>
using namespace std;

namespace k_m_p_interface //kmp匹配算法
{
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
