class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        nums.clear();
        while (true)
        {
            if (nums1.empty())
            {
                if (nums2.empty())
                    break;
                nums.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
            else
            {
                if (nums2.empty())
                {
                    nums.push_back(nums1[0]);
                    nums1.erase(nums1.begin());
                }
                else
                {
                    if (nums1[0] < nums2[0])
                    {
                        nums.push_back(nums1[0]);
                        nums1.erase(nums1.begin());
                    }
                    else
                    {
                        nums.push_back(nums2[0]);
                        nums2.erase(nums2.begin());
                    }
                }
            }
        }
        if (nums.size() & 1)
            return nums[nums.size() >> 1];
        return (nums[nums.size() >> 1] + nums[(nums.size() >> 1) - 1]) / 2.0;
    }
};
