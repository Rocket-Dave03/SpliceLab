#pragma once

template<class T>
class List
{
private:
	T* contents = nullptr;
public:
	long long length = 0;
	

	List(long long);
	List(T*, long long);
	~List();

	List<T>* split(long long);

	T& operator[](int i)
	{
		if (i >= length)
		{
			printf("Array index out of bounds\nAtempted to access [%d] but length is %lld", i, length);
			return contents[0];
		}
		return contents[i];
	}
};




template<class T>
List<T>::List(long long size)
{
	contents = new T[size];
	length = size;
}


template <class T>
List<T>::List(T* data, long long size)
{
	contents = new T[size];
	memcpy(contents, data, sizeof(T) * size);
	length = size;
}

template<class T>
List<T>::~List()
{
	delete contents;
	contents = nullptr;
}


template<class T>
List<T>* List<T>::split(long long index)
{

	long long blength = index + 1;
	long long alength = length - (index + 1);

	T* before = new T[blength];
	T* after  = new T[alength];

	memcpy(before, contents          , sizeof(T) * blength);
	memcpy(after , contents + blength, sizeof(T) * alength);


	List<T>* list = new List<T>(before, blength);

	delete contents;
	contents = after;


	return list;
}
