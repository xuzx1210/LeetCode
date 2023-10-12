class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        const int length = mountainArr.length();
        int left = 1, right = length - 1;
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            if (mountainArr.get(middle) < mountainArr.get(middle + 1))
                left = middle + 1;
            else
                right = middle;
        }
        const int peak = left;
        left = 0;
        right = peak + 1;
        while (left < right)
        {
            const int middle = (left + right) >> 1, curr = mountainArr.get(middle);
            if (curr < target)
                left = middle + 1;
            else if (target < curr)
                right = middle;
            else
                return middle;
        }
        left = peak;
        right = length;
        while (left < right)
        {
            const int middle = (left + right) >> 1, curr = mountainArr.get(middle);
            if (curr > target)
                left = middle + 1;
            else if (target > curr)
                right = middle;
            else
                return middle;
        }
        return -1;
    }
};
