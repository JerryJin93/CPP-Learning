#include <iostream>
#include <cstdio>
#include <cstring>
#include <Windows.h>

using namespace std;


template <class T>
class Node
{
	public:
		Node *next;
		T data;
};

template <class T>
class LinkedList
{
	private:
		Node<T> *head;

	public:
		LinkedList()
		{
			head = new Node<T>;
			head -> next = NULL;
			head -> data = NULL;
		}

		/*~LinkedList()
		{
			for(int i = 1; i <= getLength(); i++)
			{
				delete getNode(i);
			}
		}*/

		void insertAtTail(T data)
		{
			Node<T> *node = new Node<T>;
			Node<T> *tmp;
			
			tmp = head;
			
			while(tmp -> next != NULL)
			{
				tmp = tmp -> next;
			}
			tmp -> next = node;
			
			node -> data = data;
			node -> next = NULL;
		}

		void insertArray(T data[])
		{
			Node<T> *node = new Node<T>;
		}

		void insertAfter(T data, int position)
		{
			Node<T> *p;
			p = head;
			
			for(int count = 0; count < position; count++)
			{
				if(p -> next != NULL)
				{
					p = p -> next;
				}
				else
				{
					break;
				}
			}
			p -> data = data;

		}

		void deleteNode(int position)
		{
			Node<T> *p, *tmp1, *tmp2;
			p = head;
			int count = 0;
			if(position <= 0)
			{
				cout << "您输入的删除位置有误，不能是负值，必须从1开始！" << endl << endl;
			}
			else
			{
				if(position > 1 && getLength() <= 1)
				{
					if(getLength() == 0)
					{
						cout << "这是一个空表，不需要删除任何数据！" << endl << endl;
					}
					else
					{
						cout << "您输入的删除位置有误。当前表中只有1个元素。确定要删除吗？（Y/N）：" ;
						char option;
						cin >> option;
						if(option == 'Y')
						{
							delete p -> next;
						}
					}
				}
				else if(position == getLength())
				{
					while(p -> next != NULL)
					{
						p = p -> next;
					}
					delete p;
				}
				else
				{
					while(p -> next != NULL)
					{
						tmp1 = p;
						p = p -> next;
						tmp2 = p -> next;
						count++;
						if(count == position)
						{
							tmp1 -> next = tmp2;
							delete p;
							break;
						}
					}
				}
			}
		}

		int indexOf(T data)
		{
			Node<T> *p;
			LinkedList<T> list;
			int position;
			int count = 0;
			int countDuplicated = 0;
			p = head;
			if(checkIfDuplicatedExists())
			{
				while(p -> next != NULL)
				{
					p = p->next;
					count++;
					if(p -> data == data)
					{
						position = count;
						list.insertAtTail(position);
					}
				}
				cout << "您搜索的数据中存在重复，它们在链表中的位置分别是：";
				list.printLinkedList();
			}
			else
			{
				while(p -> next != NULL)
				{
					p = p -> next;
					count++;
					if(p -> data = data)
					{
						break;
					}
				}
				return count;
			}
		}
			

		//时间复杂度较高，有很大的优化空间，在学过“查找”之后再来修改
		bool checkIfDuplicatedExists()
		{
			bool result;
			int count = 0;
			Node<T> *p1, *p2;
			p1= head;
			p2 = head;
			if(head -> next == NULL)
			{
				cout << "链表为空，故而不用检查是否有重复元素！" << endl;
			}
			for(int i = 0; i < getLength(); i++)
			{
				if(p1 -> next != NULL)
				{
					p1 = p1 -> next;
				}
				for(int j = 0; j < getLength(); j++)
				{
					if(p2 -> next != NULL)
					{
						p2 = p2 -> next;
					}
					if(p1 -> data == p2 -> data)
					{
						count++;
						if(count > 1)
						{
							result = true;
							break;
						}
						else
						{
							result = false;
						}
					}
				}
				count = 0;
				p2 = head;
			}
			return result;
		}

		Node<T> *getNode(int position)
		{
			Node<T> *p;
			p = head;
			for(int i = 0; i < position; i++)
			{
				if(p -> next != NULL)
				{
					p = p -> next;
				}
				
			}
			return p;
		}

		T getData(int position)
		{
			Node<T> *p;
			p = head;
			for(int i = 0; i < position; i++)
			{
				if(p -> next != NULL)
				{
					p = p -> next;
				}
				
			}
			return p -> data;
		}

		int getLength()
		{
			Node<T> *p;
			p = head;
			int length = 0;
			while(p -> next != NULL)
			{
				p = p -> next;
				length++;
			}
			return length;
		}

		void printLinkedList()
		{
			Node<T> *p;
			p = head;
			if(p -> next == NULL)
			{
				cout << "链表为空！" << endl << endl;
			}
			while(p-> next != NULL)
			{
				p = p -> next;
				cout << p -> data << " ";
			}
			cout << endl << endl;
		}

		void printNode(int position)
		{
			Node<T> *p;
			p = head;
			if(p -> next == NULL)
			{
				cout << "链表为空！" << endl << endl;
			}
			for(int i = 0; i < position; i++)
			{
				if(p -> next != NULL)
				{
					p = p -> next;
				}
			}
			cout << p -> data << endl;
		}
};