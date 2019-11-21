#pragma once

using namespace std;

template <class T>
class TStack {
private:
	T *arr;
	int size;
	int num;
public:
	TStack(int _size = 10);             //конструктор
	TStack(const TStack <T> &a);        //конструктор копирования
	~TStack();

	bool isempty();                     //проверка на пустоту
	bool isfull();                      //проверка на заполненость
	void clear();                       //очистка стэка
	void push(const T &a);              //добавить элемент в стэк
	T pop();                            //вытолкнуть верхний элемент
	T top();                            //вернуть элемент с вершины стэка
}; 

template <class T>
TStack<T>::TStack(int _size)
{
	if (_size < 0) throw "wrong stack size";
	size = _size;
	arr = new T[size];
	num = -1;
}/*-------------------------------------------------------------------------*/

template <class T>
TStack<T>::TStack(const TStack<T>&a) {
	size = a.size;
	num = a.num;
	arr = new T[size];
	for (int i = 0; i <= num; i++) {
		arr[i] = a.arr[i];
	}
}/*-------------------------------------------------------------------------*/

template <class T>
TStack<T>::~TStack()
{
	delete []arr;
}/*-------------------------------------------------------------------------*/

template <class T>
bool TStack<T>::isempty()
{
	if (num == -1) return true;
	return false;
}/*-------------------------------------------------------------------------*/

template <class T>
bool TStack<T>::isfull()
{
	if (num == size - 1) return true;
	return false;
}/*-------------------------------------------------------------------------*/

template <class T>
void TStack<T>::clear()
{
	num = -1;
}/*-------------------------------------------------------------------------*/

template <class T>
void TStack<T>::push(const T &a)
{
	if (isfull()) throw "Stack is full";
	arr[num + 1] = a;
	num++;
}/*-------------------------------------------------------------------------*/

template <class T>
T TStack<T>::pop()
{
	if (isempty()) throw "Stack is empty";
	num--;
	return arr[num + 1];
}/*-------------------------------------------------------------------------*/

template <class T>
T TStack<T>::top()
{
	if (isempty()) throw "Stack is empty";
	return arr[num];
}/*-------------------------------------------------------------------------*/