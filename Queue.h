#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 10000
#include <stdexcept>
template <class DataType>
class Queue
{
private:
    DataType *_array;
    int _iCapacity;
    int _iFront;
    int _iRear;

public:
    Queue()
    {
        _iCapacity = MAX_SIZE;
        _array = new DataType[_iCapacity];
        _iFront = -1;
        _iRear = -1;
    }

    Queue(int maxSize)
    {
        _iCapacity = maxSize > 0 ? maxSize : MAX_SIZE;
        _array = new DataType[_iCapacity];
        _iFront = -1;
        _iRear = -1;
    }

    ~Queue()
    {
        delete[] _array;
    }

    bool isEmpty()
    {
        return _iFront == -1;
    }

    bool isFull()
    {
        return _iRear - _iFront == _iCapacity - 1;
    }

    void push(DataType data)
    {
        if (isFull())
        {
            return;
        }
        if (_iRear == _iCapacity - 1)
        {
            for (int i = _iFront; i < _iCapacity; i++)
            {
                _array[i - _iFront] = _array[i];
            }
            _iRear -= (_iFront + 1);
            _iFront = 0;
        }
        _array[++_iRear] = data;
        if (_iFront == -1)
        {
            _iFront = 0;
        }
    }

    DataType pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Queue is empty");
        }
        DataType item = _array[_iFront];
        _iFront = (_iFront == _iRear) ? -1 : _iFront + 1;
        return item;
    }
    DataType front()
    {
        if (isEmpty())
        {
            return DataType();
        }
        return _array[_iFront];
    }
    void clear()
    {
        _iFront = -1;
        _iRear = -1;
    }

    int size()
    {
        return isEmpty() ? 0 : _iRear - _iFront + 1;
    }
};

#endif // QUEUE_H
