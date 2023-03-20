class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        const int flowerbedLength = flowerbed.size();
        flowerbed.emplace(flowerbed.begin(), 0);
        flowerbed.emplace_back(0);
        for (int i = flowerbedLength; i && n; --i)
        {
            if (flowerbed[i - 1] || flowerbed[i] || flowerbed[i + 1])
                continue;
            flowerbed[i] = 1;
            --n;
        }
        return !n;
    }
};
