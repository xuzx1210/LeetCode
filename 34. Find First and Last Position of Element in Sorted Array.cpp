class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int index = -1;
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (left + right) >> 1;
            if (target < nums[mid])
                right = mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
            {
                index = mid;
                break;
            }
        }
        if (index == -1)
            return {-1, -1};
        int start = 0, end = nums.size() - 1;
        if (nums[0] == target)
            start = 0;
        else
        {
            left = 0, right = index;
            while (left < right)
            {
                int mid = (left + right) >> 1;
                if (nums[mid] == target)
                {
                    if (nums[mid - 1] == target)
                        right = mid;
                    else
                    {
                        start = mid;
                        break;
                    }
                }
                else
                {
                    if (nums[mid + 1] == target)
                    {
                        start = mid + 1;
                        break;
                    }
                    else
                        left = mid + 1;
                }
            }
        }
        if (nums[nums.size() - 1] == target)
            end = nums.size() - 1;
        else
        {
            left = index, right = nums.size();
            while (left < right)
            {
                int mid = (left + right) >> 1;
                if (nums[mid] == target)
                {
                    if (nums[mid + 1] == target)
                        left = mid + 1;
                    else
                    {
                        end = mid;
                        break;
                    }
                }
                else
                {
                    if (nums[mid - 1] == target)
                    {
                        end = mid - 1;
                        break;
                    }
                    else
                        right = mid;
                }
            }
        }
        return {start, end};
    }
};
