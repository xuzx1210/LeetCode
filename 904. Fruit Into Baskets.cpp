class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        const int size = fruits.size();
        unordered_map<int, int> counter{};
        int left = 0, right = 0;
        for (; right < size; ++right)
        {
            ++counter[fruits[right]];
            if (counter.size() > 2)
            {
                --counter[fruits[left]];
                if (counter[fruits[left]] == 0)
                    counter.erase(fruits[left]);
                ++left;
            }
        }
        return right - left;
    }
};
