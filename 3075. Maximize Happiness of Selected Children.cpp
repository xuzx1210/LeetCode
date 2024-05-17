class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long result = 0;
        sort(happiness.rbegin(), happiness.rend());
        for (int i = 0; i < k; ++i)
            result += max(0, happiness[i] - i);
        return result;
    }
};
