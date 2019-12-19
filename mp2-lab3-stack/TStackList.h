#pragma once

template <class T>
struct TNode{
	T val;				//значение
	TNode<T> *pNext;	//указатель на следующий 
};

template <class T>
class TStack {
private:
	TNode<T> *pFirst;	//указатель на вершину
public:
	TStack();							//конструктор
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
TStack<T>::TStack()
{
	pFirst = NULL;
}/*-------------------------------------------------------------------------*/

template <class T>
TStack<T>::TStack(const TStack<T>&p) {
	if (p.pFirst == NULL)
		pFirst = NULL;
	else {
		TNode<T> *a=p.pFirst;
		TNode<T> *t = new TNode<T>;
		t->val = a->val;
		pFirst = t;
		while (a->pNext != NULL) {
			TNode<T> *tmp = new TNode<T>;
			t->pNext = tmp;
			a = a->pNext;
			tmp->val = a->val;
			t = tmp;
		}
		t->pNext = 0;
	}
}/*-------------------------------------------------------------------------*/

template <class T>
TStack<T>::~TStack()
{
	TNode<T> *tmp = pFirst;
	while (pFirst!= NULL){
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}/*-------------------------------------------------------------------------*/

template <class T>
bool TStack<T>::isempty()
{
	if (pFirst == NULL) return true;
	return false;
}/*-------------------------------------------------------------------------*/

template <class T>
bool TStack<T>::isfull()
{
	TNode<T> *p = new TNode<T>;
	if (p) {
		delete p;
		return false;
	}
	return true;
}/*-------------------------------------------------------------------------*/

template <class T>
void TStack<T>::clear()
{
	TNode<T> *tmp = pFirst;
	while (pFirst != NULL) {
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}/*-------------------------------------------------------------------------*/

template <class T>
void TStack<T>::push(const T &a)
{
	if (isfull()) throw "Stack is full";
	TNode<T> *tmp = new TNode<T>;
	tmp->pNext = pFirst;
	tmp->val = a;
	pFirst = tmp;
}/*-------------------------------------------------------------------------*/

template <class T>
T TStack<T>::pop()
{
	if (isempty()) throw "Stack is empty";
	T res = pFirst->val;
	TNode<T> *tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	return res;
}/*-------------------------------------------------------------------------*/

template <class T>
T TStack<T>::top()
{
	if (isempty()) throw "Stack is empty";
	return pFirst->val;
}/*-------------------------------------------------------------------------*/