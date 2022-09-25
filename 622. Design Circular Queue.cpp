class MyCircularQueue
{
private:
    vector<int> circularQueue;
    size_t capacity, size, head, tail;

public:
    MyCircularQueue(int k)
    {
        circularQueue = vector<int>(k);
        capacity = k;
        size = head = tail = 0;
    }
    bool enQueue(int value)
    {
        if (!isFull())
        {
            circularQueue[tail++] = value;
            tail = tail == capacity ? 0 : tail;
            ++size;
            return true;
        }
        return false;
    }
    bool deQueue()
    {
        if (!isEmpty())
        {
            ++head;
            head = head == capacity ? 0 : head;
            --size;
            return true;
        }
        return false;
    }
    int Front()
    {
        return isEmpty() ? -1 : circularQueue[head];
    }
    int Rear()
    {
        return isEmpty() ? -1 : circularQueue[tail ? tail - 1 : capacity - 1];
    }
    bool isEmpty()
    {
        return !size;
    }
    bool isFull()
    {
        return size == capacity;
    }
};
