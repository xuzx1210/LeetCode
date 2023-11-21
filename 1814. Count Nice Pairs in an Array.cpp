class Solution
{
private:
    int rev(int x)
    {
        int result = 0;
        while (x)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }

public:
    int countNicePairs(vector<int> &nums)
    {
        int result = 0;
        const int mod = 1000000007;
        unordered_map<int, int> counter{};
        for (const int num : nums)
            result = (result + counter[num - rev(num)]++) % mod;
        return result;
    }
};
