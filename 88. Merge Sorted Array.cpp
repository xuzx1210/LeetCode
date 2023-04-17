class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = m - 1, j = n - 1, index = m + n - 1; index >= 0; --index)
            if (i < 0)
                nums1[index] = nums2[j--];
            else if (j < 0)
                nums1[index] = nums1[i--];
            else
                nums1[index] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
};
