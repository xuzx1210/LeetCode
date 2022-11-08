class Solution
{
public:
    string makeGood(string s)
    {
        string result;
        int length = s.length();
        for (int i = 0; i < length;)
        {
            result.push_back(s[i++]);
            while (!result.empty() && i < length)
            {
                char back = result.back();
                if (back - 'a' == s[i] - 'A' || back - 'A' == s[i] - 'a')
                {
                    result.pop_back();
                    ++i;
                }
                else
                    break;
            }
        }
        return result;
    }
};
