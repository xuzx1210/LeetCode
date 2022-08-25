class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> result(size);
        // left to right
        int product = 1;
        for (int i = 0; i < size; ++i)
        {
            result[i] = product;
            product *= nums[i];
        }
        // right to left
        product = 1;
        for (int i = size - 1; i >= 0; --i)
        {
            result[i] *= product;
            product *= nums[i];
        }
        return result;
    }
};
