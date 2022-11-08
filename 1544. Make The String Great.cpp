class Solution
{
public:
    string makeGood(string s)
    {
        for (bool change = true; change;)
        {
            change = false;
            for (int i = s.length() - 2; i >= 0; --i)
                if (s[i] - 'a' == s[i + 1] - 'A' || s[i] - 'A' == s[i + 1] - 'a')
                {
                    s.erase(i, 2);
                    change = true;
                }
        }
        return s;
    }
};
