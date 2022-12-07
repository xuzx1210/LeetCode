class Solution
{
private:
    Node *dfs(Node *head)
    { // return the last node of the nested double linked list which starts from head
        Node *last = head;
        for (Node *curr = head; curr; curr = curr->next)
        {
            last = curr; // record the last node
            if (!curr->child)
                continue;
            Node *childLast = dfs(curr->child), *currNext = curr->next;
            curr->next = curr->child;
            curr->child->prev = curr;
            curr->child = nullptr; // reset child pointer
            childLast->next = currNext;
            if (!currNext) // if curr is the last node of the layer
                return childLast;
            currNext->prev = childLast;
            curr = childLast; // skip nodes between curr to childLast
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
