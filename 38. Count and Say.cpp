class Solution
{
public:
    string countAndSay(int n)
    {
        string result("1");
        for (int t = 1; t < n; ++t)
        {
            stringstream ss;
            ss.clear();
            for (int i = 0; i < result.length();)
            {
                char cur = result[i];
                int count = 1;
                for (int j = i + 1; j < result.length(); ++j)
                    if (result[j] == cur)
                        ++count;
                    else
                        break;
                ss << count << cur;
                i += count;
            }
            ss >> result;
        }
        return result;
    }
};
