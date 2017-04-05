//用两个栈实现一个队列
# include <iostream>
# include <stack>
using namespace std;

template<typename T> class CQueue
{
public:
	CQueue(){};
	~CQueue(){};

	void AppendTail(const T & node);
	T DeleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};


template<typename T> void CQueue<T>::AppendTail(const T & element)
{
	stack1.push(element);
}

template<typename T> T CQueue<T>::DeleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T & data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size() == 0)
		throw new exception("queue is empty");

	T head = stack2.top();
	stack2.pop();

	return head;
}

int main()
{
	CQueue<char> queue;
	queue.AppendTail('a');
	queue.AppendTail('b');
	cout << queue.DeleteHead() << endl;
	queue.AppendTail('c');
	queue.AppendTail('d');
	cout << queue.DeleteHead() << endl;
	queue.AppendTail('e');
	cout << queue.DeleteHead() << endl;
	cout << queue.DeleteHead() << endl;
	return 0;
}