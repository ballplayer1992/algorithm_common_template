#include "algorithm_common_template.h"
namespace help_interface {
    void ReadTextFile(const std::string& str_path, std::string& str_data)
    {
        std::ifstream inData(str_path, std::ios::binary);
        std::getline(inData, str_data, (char)EOF);
        inData.close();
    }

    void StringDataToArrayData(const string& str_data, vector<int>& nums) {

        string temp = str_data;
        temp.replace(temp.find('['), 1, "");
        temp.replace(temp.find(']'), 1, "");

        string current_number;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] != ',') {
                current_number.push_back(temp[i]);
                if (i == temp.size() - 1)
                    nums.push_back(atol(current_number.c_str()));
            }
            else {
                nums.push_back(atol(current_number.c_str()));
                current_number = "";
            }
        }
    }
}



namespace k_m_p_interface
{
    void MakeNext(const string& char_arr, vector<int>& next_arr)
    {
        const int char_length = char_arr.size();
        next_arr.resize(char_length, 0);

        for (int i = 1, k = 0; i < char_length; i++)
        {
            while (k > 0 && char_arr[k] != char_arr[i])
                k = next_arr[k - 1];
            next_arr[i] = char_arr[k] == char_arr[i] ? ++k : k;
        }
    }
    int KMPMatchSubSet(const string& t_arr, const string& s_arr)
    {
        const int size_t_arr = t_arr.size();
        const int size_s_arr = s_arr.size();

        vector<int> next_arr(size_s_arr, 0);
        MakeNext(s_arr, next_arr);

        for (int i = 0, j = 0; i < size_t_arr; i++)
        {
            while (j > 0 && t_arr[i] != s_arr[j])
                j = next_arr[j - 1];

            if (t_arr[i] == s_arr[j])
                j++;
            if (j == size_s_arr)
                return i - j + 1;
        }
        return -1;
    }
}

namespace monotonic_stack_interface //单调栈
{
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

    //int MonotonicArr(stack<mono_pair>& stack_data, int index, const mono_array& arr_data, OnProcessOtherThing on_data, bool is_desc)
    //{
    //    int pos = index;
    //    while (!stack_data.empty())
    //    {
    //        mono_data current_data = stack_data.top().second;
    //        bool meet_condition = is_desc ? arr_data[index] >= current_data : arr_data[index] <= current_data;

    //        if (!meet_condition || (meet_condition && !on_data(stack_data.top()))) //不满足排序要求 或者 满足排序要求但事务处理后返回false
    //            break;

    //        pos = stack_data.top().first;
    //        stack_data.pop();
    //    }
    //    stack_data.push({ pos,arr_data[index] });
    //    return pos;
    //}
}
