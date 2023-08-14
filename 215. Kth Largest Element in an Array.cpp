class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        vector<int>::iterator it = nums.end() - k;
        nth_element(nums.begin(), it, nums.end());
        return *it;
    }
};
