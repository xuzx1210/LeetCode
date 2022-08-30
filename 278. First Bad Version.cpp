class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n;
        while (left < right)
        {
            const int middle = left + ((right - left) >> 1);
            if (isBadVersion(middle))
                right = middle;
            else
                left = middle + 1;
        }
        return left;
    }
};
