class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        const int size = letters.size();
        int left = 0, right = size;
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            const char cur = letters[middle];
            if (cur <= target)
                left = middle + 1;
            else
                right = middle;
        }
        if (left == size)
            left = 0;
        return letters[left];
    }
};
