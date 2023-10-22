class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        const int size = nums.size();
        int result = nums[k];
        for (int i = k, j = k, minimum = nums[k]; 0 <= i || j < size;)
        {
            if (i == 0 && j == size - 1)
                break;
            if (i == 0 || nums[i - 1] < nums[j + 1])
                minimum = min(minimum, nums[++j]);
            else
                minimum = min(minimum, nums[--i]);
            result = max(result, minimum * (j - i + 1));
        }
        return result;
    }
};
