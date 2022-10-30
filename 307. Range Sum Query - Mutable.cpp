class NumArray
{
private:
    vector<int> segmentTree;
    int size;

public:
    NumArray(vector<int> &nums)
    {
        size = nums.size();
        segmentTree.resize(size << 1);
        for (int i = 0; i < size; ++i)
            segmentTree[i + size] = nums[i];
        for (int i = size - 1; i; --i)
        {
            int i2 = i << 1;
            segmentTree[i] = segmentTree[i2] + segmentTree[i2 + 1];
        }
    }
    void update(int index, int val)
    {
        int position = index + size;
        const int diff = val - segmentTree[position];
        for (; position; position >>= 1)
            segmentTree[position] += diff;
    }
    int sumRange(int left, int right)
    {
        left += size;
        right += size;
        int sum = 0;
        for (; left <= right; left >>= 1, right >>= 1)
        {
            if (left & 1)
                sum += segmentTree[left++];
            if (!(right & 1))
                sum += segmentTree[right--];
        }
        return sum;
    }
};
