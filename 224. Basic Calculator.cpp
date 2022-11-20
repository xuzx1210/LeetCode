class Solution
{
private:
    int dfs(const string &s, int &index)
    { // evaluate result between '(' and ')'
        int result = 0;
        bool positive = true;
        for (; index < s.length(); ++index)
        {
            char cur = s[index];
            if (isdigit(cur))
            {
                int tmp = 0;
                while (index < s.length())
                    if (isdigit(s[index]))
                        tmp = tmp * 10 + (s[index++] - '0');
                    else
                        break;
                result += positive ? tmp : -tmp;
                --index;
            }
            else if (cur == '+')
                positive = true;
            else if (cur == '-')
                positive = false;
            else if (cur == '(')
            {
                int bracket = dfs(s, ++index);
                result += positive ? bracket : -bracket;
            }
            else if (cur == ')')
                break;
        }
        return result;
    }

public:
    int calculate(string s)
    {
        int index = 0;
        return dfs(s, index);
    }
};
