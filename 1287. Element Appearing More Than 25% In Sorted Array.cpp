class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int result = -1;
        const int size = arr.size(), quarter = size >> 2;
        for (int i = 0, count = 0; i < size; ++i)
            if (arr[i] != result)
            {
                result = arr[i];
                count = 1;
            }
            else if (quarter < ++count)
                break;
        return result;
    }
};
