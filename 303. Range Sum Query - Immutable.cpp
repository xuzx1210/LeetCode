class NumArray
{
private:
    vector<int> numArray;

public:
    NumArray(vector<int> &nums)
    {
        int size = nums.size();
        numArray = vector<int>(size + 1, 0);
        for (int i = 0; i < size; ++i)
            numArray[i + 1] = numArray[i] + nums[i];
    }
    int sumRange(int left, int right)
    {
        return numArray[right + 1] - numArray[left];
    }
};
