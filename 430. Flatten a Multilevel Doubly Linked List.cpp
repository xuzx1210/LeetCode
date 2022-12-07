class Solution
{
private:
    Node *dfs(Node *head)
    { // return the last node of the nested double linked list which starts from head
        Node *last = head;
        for (Node *cur = head; cur; cur = cur->next)
        {
            last = cur; // record the last node
            if (!cur->child)
                continue;
            Node *childLast = dfs(cur->child), *curNext = cur->next;
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = nullptr; // reset child pointer
            childLast->next = curNext;
            if (!curNext) // if current node is the last node of the layer
                return childLast;
            curNext->prev = childLast;
            cur = childLast; // skip nodes between cur to last
        }
        return last;
    }

public:
    Node *flatten(Node *head)
    {
        dfs(head);
        return head;
    }
};
