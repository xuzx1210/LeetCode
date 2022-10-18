class Solution
{
public:
    string countAndSay(int n)
    {
        string result("1");
        for (int t = 1; t < n; ++t)
        {
            stringstream ss;
            int start = 0, length = result.length();
            for (int i = 1; i < length; ++i)
                if (result[i] != result[start])
                {
                    ss << i - start << result[start];
                    start = i;
                }
            ss << length - start << result[start];
            ss >> result;
        }
        return result;
    }
};
