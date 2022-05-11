class Solution
{
public:
    int countVowelStrings(int n)
    {
        vector<int> result = {1, 1, 1, 1, 1};
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j < 5; ++j)
                result[j] += result[j - 1];
        return result.back();
    }
};
