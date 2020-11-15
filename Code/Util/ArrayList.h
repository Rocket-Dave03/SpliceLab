#pragma once

template <class T>
class ArrayList
{
private:
	T* list;
	long length;

public:
	ArrayList<T>();
	~ArrayList<T>();

	void append(T);
	int size();
	T get(int);
	void set(int, T);
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
int ArrayList<T>::size()
{
	return length;
}
template <class T>
T ArrayList<T>::get(int index)
{
	return list[index];
}
template<class T>
void ArrayList<T>::set(int index, T value)
{
	list[index] = value;
}


template <class T>
void ArrayList<T>::deleteElement(long index)
{
	if (index >= 0 && index >= length)
	{
		printf( "ArrayList index out of bounds: %i, %i\n", index, length );
		return;
	}


	delete list[index];
	list[index] = nullptr;
	
	T* tmp = new T[length];
	memcpy(tmp,list, length * sizeof(T));
	delete list;
	

	list = new T[length - 1];
	if (index >= 1)
	{
		memcpy(list, tmp, (index) * sizeof(T));
	}
	memcpy(list+index, tmp + (index+ 1), (length-(index+1)) * sizeof(T));
	length--;
}
