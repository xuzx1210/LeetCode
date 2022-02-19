class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        vector<int> nums({});
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)
            nums.push_back(cur->val);
        int t = nums.size() / k;
        for (int i = 0; i < t; ++i)
            reverse(nums.begin() + i * k, nums.begin() + (i + 1) * k);
        int index = 0;
        ListNode *cur = head;
        for (int i = 0; i < nums.size(); cur = cur->next, ++i)
            cur->val = nums[i];
        return head;
    }
};
