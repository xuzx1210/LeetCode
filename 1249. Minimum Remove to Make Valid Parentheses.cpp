class Solution
{
private:
    void parenthesesCheck(string &s, const char left, const char right)
    {
        string result{};
        int parentheses = 0;
        for (const char c : s)
        {
            if (c == right && parentheses == 0)
                continue;
            if (c == left)
                ++parentheses;
            if (c == right)
                --parentheses;
            result.push_back(c);
        }
        s = result;
    }

public:
    string minRemoveToMakeValid(string s)
    {
        parenthesesCheck(s, '(', ')');
        reverse(s.begin(), s.end());
        parenthesesCheck(s, ')', '(');
        reverse(s.begin(), s.end());
        return s;
    }
};
