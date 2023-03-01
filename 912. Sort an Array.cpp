class Solution
{
private:
    void mergeSort(const vector<int>::iterator begin, const vector<int>::iterator end)
    {
        const int diff = end - begin;
        if (diff < 2)
            return;
        const vector<int>::iterator middle = begin + (diff >> 1);
        mergeSort(begin, middle);
        mergeSort(middle, end);
        const vector<int> left(begin, middle), right(middle, end);
        merge(left.begin(), left.end(), right.begin(), right.end(), begin);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums.begin(), nums.end());
        return nums;
    }
};
