#include "algorithm_common_template.h"

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
