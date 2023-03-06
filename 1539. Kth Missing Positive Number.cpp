class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int previous = 0;
        for (int current : arr)
        {
            const int difference = current - previous - 1;
            if (difference < k)
                k -= difference;
            else
                break;
            previous = current;
        }
        return previous + k;
    }
};
