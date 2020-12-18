#pragma once

template<class T>
class List
{
private:
	T* contents = nullptr;
	long long size = 0;

public:
	
	long long length();
	
	

	List(long long);
	List(T*, long long);
	~List();

	List<T>* split(long long);
	T* getRaw();

	T& operator[](int i)
	{
		if (i >= size)
		{
			printf("Array index out of bounds\nAtempted to access [%d] but length is %lld", i, size);
			return contents[0];
		}
		return contents[i];
	}
};


template <class T>
long long List<T>::length()
{
	return size;
}

template<class T>
List<T>::List(long long s)
{
	contents = new T[size];
	size = s;
}


template <class T>
List<T>::List(T* data, long long s)
{
	contents = new T[s];
	memcpy(contents, data, sizeof(T) * s);
	size = s;
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
	long long alength = size - (index + 1);

	T* before = new T[blength];
	T* after  = new T[alength];

	memcpy(before, contents          , sizeof(T) * blength);
	memcpy(after , contents + blength, sizeof(T) * alength);


	List<T>* list = new List<T>(before, blength);

	delete contents;
	contents = after;


	return list;
}

template<class T>
T* List<T>::getRaw()
{
	return contents;
}



