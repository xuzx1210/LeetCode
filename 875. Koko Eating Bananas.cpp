class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            int hours = 0;
            for (const int pile : piles)
            {
                const div_t d = div(pile, middle);
                hours += d.quot;
                if (d.rem)
                    ++hours;
            }
            if (h < hours)
                left = middle + 1;
            else
                right = middle;
        }
        return left;
    }
};
