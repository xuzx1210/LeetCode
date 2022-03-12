class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        vector<Node *> list({});
        for (Node *cur = head; cur; cur = cur->next)
            list.push_back(cur);
        const int size = list.size();
        vector<int> randomIndex(size, -1);
        for (int i = 0; i < size; ++i)
            randomIndex[i] = list[i]->random ? find(list.begin(), list.end(), list[i]->random) - list.begin() : -1;
        vector<Node *> result(size, nullptr);
        for (int i = 0; i < size; ++i)
        {
            Node *tmp = new Node(list[i]->val);
            result[i] = tmp;
        }
        for (int i = 0; i < size - 1; ++i)
        {
            result[i]->next = result[i + 1];
            int index = randomIndex[i];
            result[i]->random = index == -1 ? nullptr : result[index];
        }
        result.back()->next = nullptr;
        int backIndex = randomIndex.back();
        result.back()->random = backIndex == -1 ? nullptr : result[backIndex];
        return result[0];
    }
};
