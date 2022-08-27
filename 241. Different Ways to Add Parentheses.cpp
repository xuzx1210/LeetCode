class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> nums = {};
        vector<char> ops = {};
        // split expression
        int length = expression.length();
        int head = 0;
        for (int i = 0; i < length; ++i)
            if (!isdigit(expression[i]))
            {
                nums.emplace_back(stoi(expression.substr(head, i - head)));
                ops.emplace_back(expression[i]);
                head = i + 1;
            }
        nums.emplace_back(stoi(expression.substr(head, length - head)));
        // dynamic programming
        int size = nums.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(size, vector<int>({})));
        for (int i = 0; i < size; ++i)
            dp[i][i].emplace_back(nums[i]);
        for (int range = 1; range < size; ++range)
            for (int start = 0; start < size - range; ++start)
                for (int cut = start; cut < start + range; ++cut)
                    for (int &a : dp[start][cut])
                        for (int &b : dp[cut + 1][start + range])
                            if (ops[cut] == '+')
                                dp[start][start + range].emplace_back(a + b);
                            else if (ops[cut] == '-')
                                dp[start][start + range].emplace_back(a - b);
                            else
                                dp[start][start + range].emplace_back(a * b);
        return dp.front().back();
    }
};
