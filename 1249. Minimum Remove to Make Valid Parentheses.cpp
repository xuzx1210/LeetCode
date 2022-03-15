class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> parentheses;
        while (!parentheses.empty())
            parentheses.pop();
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
                parentheses.push(i);
            else if (s[i] == ')')
            {
                if (parentheses.empty())
                    s[i] = '?';
                else
                    parentheses.pop();
            }
        }
        while (!parentheses.empty())
        {
            s[parentheses.top()] = '?';
            parentheses.pop();
        }
        string result("");
        for (char c : s)
            if (c != '?')
                result.push_back(c);
        return result;
    }
};
