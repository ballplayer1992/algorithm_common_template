#pragma once
#include<vector>
#include<string>
using namespace std;

namespace k_m_p_interface //kmpƥ���㷨
{
    /// <summary>
    /// ���� next ����
    /// </summary>
    void MakeNext(const string& char_arr, vector<int>& next_arr);

    /// <summary>
    /// kmp�㷨����ƥ����Ӽ�����������t_arr ���������ֵ
    /// </summary>
    /// <returns></returns>
    int KMPMatchSubSet(const string& t_arr, const string& s_arr);

}
