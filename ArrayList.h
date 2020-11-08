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
	void deleteAll();
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
void ArrayList<T>::deleteAll()
{
	if ( std::is_pointer<T>::value == true)
	{
		for (int i = 0; i < length;i++)
		{
			delete list[i];
		}
	}
}
