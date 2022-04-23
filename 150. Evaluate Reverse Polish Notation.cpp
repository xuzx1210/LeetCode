class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> nums;
        while (!nums.empty())
            nums.pop();
        for (string token : tokens)
        {
            if (isdigit(token.back()))
                nums.push(stoi(token));
            else
            {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                switch (token[0])
                {
                case '+':
                    nums.push(a + b);
                    break;
                case '-':
                    nums.push(a - b);
                    break;
                case '*':
                    nums.push(a * b);
                    break;
                case '/':
                    nums.push(a / b);
                    break;
                }
            }
        }
        return nums.top();
    }
};
