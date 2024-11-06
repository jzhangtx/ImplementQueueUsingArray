// ImplementQueueUsingArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#ifdef __VECTOR_ALLOWED__
#include <vector>

class Queue {
public:
	Queue(int capacity)
		: m_Capacity(capacity)
	{
		m_Queue.reserve(capacity);
	}

	bool isEmpty()
	{
		return m_Queue.size() == 0;
	}

	int size()
	{
		return static_cast<int>(m_Queue.size());
	}

	int front()
	{
		if (isEmpty())
			return -1;

		return m_Queue[0];
	}

	int back()
	{
		if (isEmpty())
			return -1;

		return m_Queue[m_Queue.size() - 1];
	}

	void push(int element)
	{
		if (static_cast<size_t>(m_Capacity) == m_Queue.size())
			throw std::runtime_error("The queue is full, cannot add an element!");

		m_Queue.push_back(element);
	}

	void pop()
	{
		m_Queue.erase(m_Queue.begin());
	}

private:
	int m_Capacity;
	std::vector<int> m_Queue;
};

#else
class Queue {
public:
	Queue (int capacity)
		: m_Capacity(capacity)
		, m_Size(0)
	{
		m_pQueue = new int[capacity];
	}

	~Queue()
	{
		delete[] m_pQueue;
	}

	bool isEmpty()
	{
		return m_Size == 0;
	}
	
	int size()
	{
		return m_Size;
	}
	
	int front()
	{
		if (isEmpty())
			return -1;

		return m_pQueue[0];	
	}
	
	int back()
	{
		if (isEmpty())
			return -1;
		
		return m_pQueue[m_Size - 1];
	}
	
	void push(int element)
	{
		if (m_Size == m_Capacity)
			throw std::runtime_error("The queue is full, cannot add an element!");

		m_pQueue[m_Size++] = element;		
	}
	
	void pop()
	{
		for (int i = 0; i < m_Size - 1; i++)
			m_pQueue[i] = m_pQueue[i + 1];
		m_Size--;
	}

	
private:
	int m_Capacity;
	int* m_pQueue;
	int m_Size;
};

#endif

int main()
{
	Queue q(10);
	int i = 0;
	bool finished = false;

	while (!finished)
	{
		std::cout << q.front() << " " << q.back() << " ";
		std::cout << (q.isEmpty() ? "true" : "false") << " " << q.size() << std::endl;
		switch (i++)
		{
		case 0:
			q.push(5);
			break;

		case 1:
			q.push(6);
			break;

		case 2:
			q.push(7);
			break;

		case 3:
		case 4:
		case 5:
			q.pop();
			break;

		default:
			finished = true;
		}
	}
}
