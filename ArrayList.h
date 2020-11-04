#pragma once

template <class T>
class ArrayList
{
private:
	T* list;
	int length;

public:
	ArrayList();
	~ArrayList();

	void append(T);
	int size();
};






template <class T>
ArrayList<T>::ArrayList()
{
	length = 0;
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

