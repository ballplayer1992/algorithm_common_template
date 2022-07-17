#pragma once
#include<vector>
#include<string>
#include<stack>
#include<functional>
using namespace std;

namespace k_m_p_interface //kmpƥ���㷨
{
    //https://blog.csdn.net/yutong5818/article/details/81319120
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

namespace monotonic_stack_interface //����ջ
{
    using mono_data = int;
    using mono_array = vector<mono_data>;
    using mono_pair = pair<int, mono_data>; //����(���ڼ�¼����)������ֵ
    using OnProcessOtherThing = std::function<bool(const mono_pair& m_p)>;
    using mono_stack = stack<mono_pair>;
    using mono_vector = vector<mono_pair>;
    /// <summary>
    /// ����ջͨ�ú���
    /// </summary>
    /// <param name="stack_data">ջ����</param>
    /// <param name="index">����Ҫѹջ��mono_array��Ӧ������ֵ</param>
    /// <param name="arr_data">mono_array����</param>
    /// <param name="is_desc">true:����false:����</param>
    /// <returns></returns>
    int MonotonicArr(stack<mono_pair>& stack_data,
        int index, const mono_array& arr_data, OnProcessOtherThing on_data, bool is_desc);
}

namespace math_interface
{
    /// <summary>
    /// �� a �� b �����Լ��
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns>�������Լ��</returns>
    template<class T>
    T gcd(T a,T b)
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
    /// �� a �� b ����С������
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns>�������¹�����</returns>
    template<class T>
    T lcm(T a, T b)
    {
        return a * b / (gcd(a,b));
    }
}