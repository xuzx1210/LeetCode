class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> result{};
        for (string &token : tokens)
        {
            char op = token.back();
            if (isdigit(op))
            {
                result.emplace(stoi(token));
                continue;
            }
            long long a, b = result.top();
            result.pop();
            a = result.top();
            result.pop();
            if (op == '+')
                result.emplace(a + b);
            else if (op == '-')
                result.emplace(a - b);
            else if (op == '*')
                result.emplace(a * b);
            else
                result.emplace(a / b);
        }
        return result.top();
    }
};
