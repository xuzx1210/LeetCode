class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0, right = 46341;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            int square = mid * mid;
            if (square < x)
                left = mid + 1;
            else if (x < square)
                right = mid;
            else
                return mid;
        }
        return left - 1;
    }
};
