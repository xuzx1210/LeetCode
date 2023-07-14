class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        vector<int> maxLength(20001, 0);
        int result = 1;
        for (const int num : arr)
        {
            const int curr = num + 10000, prev = curr - difference, prevLength = (prev < 0 || 20000 < prev) ? 0 : maxLength[prev];
            maxLength[curr] = max(maxLength[curr], prevLength + 1);
            result = max(result, maxLength[curr]);
        }
        return result;
    }
};
