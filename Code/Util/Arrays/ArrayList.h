#pragma once





template <class T>
class ArrayList
{
private:
	T* list;
	long long length;

public:
	ArrayList<T>();
	~ArrayList<T>();

	T& operator[](int i)
	{
		if (i >= length)
		{
			printf("Array index out of bounds\nAtempted to access [%d] but length is %lld", i, length);
			return list[0];
		}
		return list[i];
	}

	void append(T);
	long long size();
	void deleteElement(long);
};






template <class T>
ArrayList<T>::ArrayList()
{
	length = 0;
	list = new T[0];
}
template<class T>
ArrayList<T>::~ArrayList()
{
	delete list;
	list = nullptr;
}



#pragma warning( push )
#pragma warning( disable : 26451 )

template <class T>
void ArrayList<T>::append(T elem)
{
	if (length == 0)
	{
		list = new T[1];
		list[0] = elem;
		length++;
		return;
	}
	T* tmp = new T[length + 1];
	memcpy(tmp, list, length * sizeof(T));
	tmp[length] = elem;
	delete list;
	list = new T[length + 1];
	memcpy(list, tmp, (length + 1) * sizeof(T));
	length++;
}
template <class T>
long long ArrayList<T>::size()
{
	return length;
}

template <class T>
void ArrayList<T>::deleteElement(long index)
{
	if (index >= 0 && index >= length)
	{
		printf("ArrayList index out of bounds: %i, %lli\n", index, length);
		return;
	}


	delete list[index];
	list[index] = nullptr;

	T* tmp = new T[length];
	memcpy(tmp, list, length * sizeof(T));
	delete list;


	list = new T[length - 1];
	if (index >= 1)
	{
		memcpy(list, tmp, (index) * sizeof(T));
	}
	memcpy(list + index, tmp + (index + 1), (length - (index + 1)) * sizeof(T));
	length--;
}


#pragma warning(pop)