class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        const int size = arr.size();
        if (size == 2)
            return true;
        int minimum = INT_MAX, maximum = INT_MIN;
        for (const int num : arr)
        {
            minimum = min(minimum, num);
            maximum = max(maximum, num);
        }
        const auto [d, remain] = div(maximum - minimum, size - 1);
        if (remain)
            return false;
        for (int i = 0; i < size;)
        {
            if (arr[i] == minimum + d * i)
            {
                ++i;
                continue;
            }
            const auto [index, rem] = div(arr[i] - minimum, d);
            if (rem || index < i || arr[i] == arr[index])
                return false;
            swap(arr[i], arr[index]);
        }
        return true;
    }
};
