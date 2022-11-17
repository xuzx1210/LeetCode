class Solution
{
private:
    const vector<int> original;
    const int size;

public:
    Solution(vector<int> &nums) : original(nums), size(nums.size())
    {
    }
    vector<int> reset()
    {
        return original;
    }
    vector<int> shuffle()
    {
        vector<int> result(original);
        for (int i = size - 1; i; --i)
            swap(result[i], result[rand() % (i + 1)]);
        return result;
    }
};
