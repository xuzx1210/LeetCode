class Solution
{
public:
    string removeDuplicates(string s)
    {
        const int length = s.length();
        string result;
        for (int i = 0; i < length;)
        {
            result.push_back(s[i++]);
            while (!result.empty() && i < length)
                if (result.back() == s[i])
                {
                    result.pop_back();
                    ++i;
                }
                else
                    break;
        }
        return result;
    }
};
