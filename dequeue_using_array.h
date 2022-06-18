class Deque {

    int *data;
    int capacity;
    int frontIndex;
    int nextIndex;
    int size = 0;
    
public:
    
    Deque(int length)
    {
        data = new int[length];
        capacity = length;
        frontIndex = -1;
        nextIndex = 0;
        size = 0;
    }

    void insertFront(int val)
    {
        if(size==capacity)
        {
            cout<<"-1"<<endl;
            return;
        }

        else if(frontIndex==(-1))
        {
            frontIndex++;
            data[frontIndex] = val;
            nextIndex++;
            size++;
            return;
        }

        for(int i=nextIndex;i>=0;i--)
        {
            data[i] = data[i-1];
        }

        nextIndex++;
        size++;
    }

    void insertRear(int val)
    {
        if(size==capacity)
        {
            cout<<"-1"<<endl;
            return;
        }

        else if(frontIndex==(-1))
        {
            frontIndex++;
            data[frontIndex] = val;
            nextIndex++;
            size++;
            return;
        }

        data[nextIndex] = val;
        nextIndex++;
        size++;
    }

    void deleteFront()
    {
        if(size==0)
        {
            cout<<"-1"<<endl;
            return;
        }

        else if(size==1)
        {
            nextIndex = 0;
            frontIndex = -1;
            size--;
            return;
        }

        for(int i=1;i<nextIndex;i++)
        {
            data[i] = data[i+1];
        }

        data[frontIndex] = val;

        nextIndex--;
        size--;
    }

    void deleteRear()
    {
        if(size==0)
        {
            cout<<"-1"<<endl;
            return;
        }

        nextIndex--;
        size--;
    }

    int getFront()
    {
        if(size==0)
        {
            return -1;
        }

        return data[frontIndex];
    }

    int getRear()
    {
        if(size==0)
        {
            return -1;
        }

        return data[nextIndex-1];
    }
};