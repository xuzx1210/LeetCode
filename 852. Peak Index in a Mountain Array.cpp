class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 0, right = arr.size();
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            if (arr[middle] < arr[middle + 1])
                left = middle + 1;
            else
                right = middle;
        }
        return left;
    }
};
