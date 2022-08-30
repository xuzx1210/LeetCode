class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        const int size = citations.size();
        int left = 0, right = size - 1;
        while (left <= right)
        {
            const int middle = (left + right) >> 1;
            if (citations[middle] < size - middle)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return size - left;
    }
};
