class Solution
{
private:
    bool place(const int index, vector<int> &flowerbed, int &n)
    {
        if (flowerbed[index - 1] || flowerbed[index] || flowerbed[index + 1])
            return false;
        flowerbed[index] = 1;
        return !--n;
    }

public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;
        const int flowerbedLength = flowerbed.size();
        flowerbed.emplace(flowerbed.begin(), 0);
        flowerbed.emplace_back(0);
        for (int i = flowerbedLength; i; --i)
            if (place(i, flowerbed, n))
                return true;
        return false;
    }
};
