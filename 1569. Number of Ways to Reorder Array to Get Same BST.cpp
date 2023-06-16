class Solution
{
private:
    int mod;
    vector<vector<int>> pascal;
    long long dfs(const vector<int> &nums)
    {
        const int size = nums.size();
        if (size <= 2)
            return 1;
        vector<int> left{}, right{};
        for (int i = 1; i < size; ++i)
            (nums[i] < nums[0] ? left : right).emplace_back(nums[i]);
        return dfs(left) * dfs(right) % mod * pascal[left.size()][right.size()] % mod;
    }

public:
    int numOfWays(vector<int> &nums)
    {
        const int size = nums.size();
        mod = 1000000007;
        pascal.resize(size, vector<int>(size, 1));
        for (int startI = 2; startI < size; ++startI)
            for (int index = 1; index < startI; ++index)
            {
                const int i = startI - index, j = index;
                pascal[i][j] = (pascal[i][j - 1] + pascal[i - 1][j]) % mod;
            }
        return dfs(nums) - 1;
    }
};
