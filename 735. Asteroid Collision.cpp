class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> result{-1};
        for (const int asteroid : asteroids)
        {
            if (0 < asteroid)
            {
                result.emplace_back(asteroid);
                continue;
            }
            while (0 < result.back() && result.back() + asteroid < 0)
                result.pop_back();
            if (result.back() + asteroid == 0)
            {
                result.pop_back();
                continue;
            }
            if (result.back() < 0)
                result.emplace_back(asteroid);
        }
        result.erase(result.begin());
        return result;
    }
};
