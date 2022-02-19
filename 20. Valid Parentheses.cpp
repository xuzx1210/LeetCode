class Solution
{
public:
    bool isValid(string s)
    {
        if (!s.length())
            return true;
        if (s.length() & 1)
            return false;
        unordered_map<char, char> um;
        um.clear();
        um['('] = ')';
        um['{'] = '}';
        um['['] = ']';
        stack<char> bracket;
        while (!bracket.empty())
            bracket.pop();
        for (int i = 0; i < s.length(); ++i)
        {
            char c = s[i];
            if (bracket.empty())
                bracket.push(c);
            else
            {
                if (c == '(' || c == '{' || c == '[')
                    bracket.push(c);
                else
                {
                    if (um[bracket.top()] == c)
                        bracket.pop();
                    else
                        return false;
                }
            }
        }
        return bracket.empty();
    }
};
