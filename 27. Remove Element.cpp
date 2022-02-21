class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == val)
            {
                bool found = false;
                for (int j = i + 1; j < nums.size(); ++j)
                    if (nums[j] != val)
                    {
                        swap(nums[i], nums[j]);
                        found = true;
                        break;
                    }
                if (!found)
                    return i;
            }
        return nums.size();
    }
};
