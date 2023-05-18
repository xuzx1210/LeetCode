class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        const int n = nums.size();
        int minimum = INT_MAX;
        for (int num : nums)
            minimum = min(minimum, num);
        int result = 0;
        for (int num : nums)
            result += num - minimum;
        return result;
    }
};
