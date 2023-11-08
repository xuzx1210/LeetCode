class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        return sx == fx && sy == fy && t == 1 ? false : max(abs(sx - fx), abs(sy - fy)) <= t;
    }
};
