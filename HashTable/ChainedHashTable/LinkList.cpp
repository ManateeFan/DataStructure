#include "LinkList.h"

template<typename T>
LinkList<T>::LinkList():head(new Item<T>), length(0)
{
	head->next = nullptr;
}

template<typename T>
LinkList<T>::~LinkList()
{
	if (length != 0)
	{
		Item<T>* p = head->next;
		Item<T>* del = head->next;
		while (del)
		{
			del = p->next;
			delete p;
			p = del;
		}
	}
	delete head;
}

template<typename T>
void LinkList<T>::InsertItem(Item<T>* newItem)
{
	newItem->next = head->next;
	head->next = newItem;
	length++;
}

template<typename T>
void LinkList<T>::RemoveItem(std::string const& itemKey)
{
	Item<T>* del = head->next;
	Item<T>* p = head->next;
	while (del)
	{
		del = p->next;
		if (del->key == itemKey)
		{
			p->next = del->next;
			delete del;
			length--;
			break;
		}
		p = del;
	}
}

template<typename T>
Item<T>* LinkList<T>::GetItem(std::string const& itemKey) const
{
	Item<T>* p = head->next;
	while (p)
	{
		if (p->key == itemKey)
			return p;
	}
	return nullptr;
}

template<typename T>
int LinkList<T>::Length() const
{
	return length;
}
