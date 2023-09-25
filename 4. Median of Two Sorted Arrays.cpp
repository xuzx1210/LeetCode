class Solution
{
private:
    int m, n;
    int findKth(const vector<int> &nums1, const int index1, const vector<int> &nums2, const int index2, const int k)
    {
        if (m <= index1)
            return nums2[index2 + k];
        if (n <= index2)
            return nums1[index1 + k];
        if (k == 0)
            return min(nums1[index1], nums2[index2]);
        if (k == 1)
        {
            if (index1 + 1 < m && nums1[index1 + 1] < nums2[index2])
                return nums1[index1 + 1];
            if (index2 + 1 < n && nums2[index2 + 1] < nums1[index1])
                return nums2[index2 + 1];
            return max(nums1[index1], nums2[index2]);
        }
        const int half = k >> 1;
        const int middle1 = index1 + half < m ? nums1[index1 + half] : INT_MAX;
        const int middle2 = index2 + half < n ? nums2[index2 + half] : INT_MAX;
        return middle1 < middle2 ? findKth(nums1, index1 + half, nums2, index2, k - half) : findKth(nums1, index1, nums2, index2 + half, k - half);
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        m = nums1.size();
        n = nums2.size();
        return (findKth(nums1, 0, nums2, 0, (m + n - 1) >> 1) + findKth(nums1, 0, nums2, 0, (m + n) >> 1)) / 2.0;
    }
};
