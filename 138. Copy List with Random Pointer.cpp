class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        for (Node *cur = head; cur; cur = cur->next->next)
        {
            Node *tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
        }
        Node *result = head->next;
        for (Node *cur = head; cur; cur = cur->next->next)
            if (cur->random)
                cur->next->random = cur->random->next;
        for (Node *cur = head; cur; cur = cur->next)
        {
            Node *tmp = cur->next;
            cur->next = tmp->next;
            if (tmp->next)
                tmp->next = tmp->next->next;
        }
        return result;
    }
};
