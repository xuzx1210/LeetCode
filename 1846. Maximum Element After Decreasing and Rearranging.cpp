class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int result = 0;
        sort(arr.begin(), arr.end());
        for (const int num : arr)
            result = min(result + 1, num);
        return result;
    }
};
