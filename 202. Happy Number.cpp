class Solution
{
public:
    bool isHappy(int n)
    {
        set<int> visited({});
        while (n != 1)
        {
            if (visited.find(n) != visited.end())
                return false;
            visited.insert(n);
            int tmp = 0;
            while (n)
            {
                div_t d = div(n, 10);
                tmp += (d.rem * d.rem);
                n = d.quot;
            }
            n = tmp;
        }
        return true;
    }
};
