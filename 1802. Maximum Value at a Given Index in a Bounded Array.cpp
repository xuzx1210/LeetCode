class Solution
{
private:
    long long calculateSum(const int n, const int index, const long long height)
    {
        long long result = 0;
        // [0, index)
        if (index < height)
            result += ((height << 1) - index - 1) * index;
        else
            result += (height - 1) * height;
        // [index, n)
        if (n < index + height)
            result += ((height << 1) + index - n + 1) * (n - index);
        else
            result += height * (height + 1);
        return result >> 1;
    }

public:
    int maxValue(int n, int index, int maxSum)
    {
        maxSum -= n;
        long long left = 0, right = INT_MAX;
        while (left < right)
        {
            const long long middle = (left + right) >> 1;
            if (calculateSum(n, index, middle) <= maxSum)
                left = middle + 1;
            else
                right = middle;
        }
        return left;
    }
};
