class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 1, right = 46341;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            int square = mid * mid;
            if (square < num)
                left = mid + 1;
            else if (square > num)
                right = mid;
            else
                return true;
        }
        return false;
    }
};
