#include <iostream>
#include<stack>

using namespace std;

struct queue
{
	stack <int> input;
	stack <int> output;
	int SPI = 0;
	int SPO = 0;
	
	void push(int x)
	{
		input.push(x);
		SPI++;
	}

	int pop()
	{
		if (input.empty() and output.empty())
		{
			cout << "empty queue";
		}
		if (SPO == 0)
		{
			SPO = SPI;
			while (SPI > 0)
			{
				output.push(input.top());
				input.pop();
				SPI--;
			}

			int x = output.top();
			output.pop();
			SPO--;
			return x;
		}
		if (SPO != 0)
		{
			int x = output.top();
			output.pop();
			SPO--;
			return x;
		}
	}
};


int main()
{
	queue que;
	que.push(7);
	cout << que.pop();
	que.push(9);
	que.push(1);
	que.push(5);
	cout << que.pop();
	cout << que.pop();
	cout << que.pop();
}
