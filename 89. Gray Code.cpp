class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result({0});
        int head = 1;
        for (int i = 1; i <= n; ++i)
        {
            vector<int> tmp(result);
            reverse(tmp.begin(), tmp.end());
            for (int j = 0; j < tmp.size(); ++j)
                tmp[j] += head;
            result.insert(result.end(), tmp.begin(), tmp.end());
            head <<= 1;
        }
        return result;
    }
};
