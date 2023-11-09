class Solution
{
public:
    int countHomogenous(string s)
    {
        const int length = s.length(), mod = 1000000007;
        int result = 0;
        for (int begin = 0, end = 0; end < length; ++end)
        {
            if (s[begin] != s[end])
                begin = end;
            result = (result + end - begin + 1) % mod;
        }
        return result;
    }
};
