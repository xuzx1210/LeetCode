class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        map<int, bool> exist;
        for (int &num : nums)
            exist[num] = true;
        for (auto it = exist.rbegin(); it != exist.rend(); ++it)
            if (it->second && exist[-it->first])
                return it->first;
        return -1;
    }
};
