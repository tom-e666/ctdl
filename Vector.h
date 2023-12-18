#ifndef VECTOR_H
#define VECTOR_H

template <class DataType>
class Vector
{
private:
	DataType *_items;
	int _iCapacity;
	int _iSize;

public:
	Vector()
	{
		_iCapacity = 10000;
		_items = new DataType[_iCapacity];
		_iSize = 0;
	}

	Vector(int maxSize)
	{
		_iCapacity = maxSize ? maxSize > 0 : 10000;
		_items = new DataType[_iCapacity];
		_iSize = 0;
	}

	~Vector()
	{
		delete[] _items;
	}

	bool isEmpty()
	{
		return _iSize == 0;
	}

	bool isFull()
	{
		return _iSize == _iCapacity;
	}

	void push_back(DataType data)
	{
		if (!isFull())
		{
			_items[_iSize++] = data;
		}
	}

	void insert(DataType data, int index)
	{
		if (index >= 0 && index < _iCapacity && !isFull())
		{
			for (int i = _iSize; i > index; --i)
			{
				_items[i] = _items[i - 1];
			}
			_items[index] = data;
			_iSize++;
		}
	}

	void removeAt(int index)
	{
		if (index >= 0 && index < _iCapacity && !isEmpty())
		{
			for (int i = index; i < _iSize - 1; ++i)
			{
				_items[i] = _items[i + 1];
			}
			_iSize--;
		}
	}

	void remove(DataType data)
	{
		int index = find(data);
		if (index < 0)
			return;
		removeAt(index);
	}

	bool contains(DataType data)
	{
		return find(data) != -1;
	}

	int find(DataType data)
	{
		for (int i = 0; i < _iSize; ++i)
		{
			if (_items[i] == data)
			{
				return i;
			}
		}
		return -1;
	}

	void clear()
	{
		for (int i = 0; i < _iSize; ++i)
		{
			_items[i] = DataType(); // Reset to default value
		}
		_iSize = 0;
	}

	int size()
	{
		return _iSize;
	}

	DataType &operator[](int index)
	{
		if (index < 0 || index >= _iSize)
		{
			return _items[_iCapacity - 1];
		}
		return _items[index];
	}
};

#endif // VECTOR_H
