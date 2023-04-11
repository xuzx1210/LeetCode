class Solution
{
public:
    int trap(vector<int> &height)
    {
        int result = 0, left = 0, leftMax = 0, right = height.size() - 1, rightMax = 0;
        while (left <= right)
            if (height[left] < height[right])
            {
                leftMax = max(leftMax, height[left]);
                result += leftMax - height[left++];
            }
            else
            {
                rightMax = max(rightMax, height[right]);
                result += rightMax - height[right--];
            }
        return result;
    }
};
