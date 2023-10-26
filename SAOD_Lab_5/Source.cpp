#include "Stack.h"

void PrintMemoryUse(int& count, int array[])
{
	for (int i = 0; i < count; i++)
		cout << i + 1 << +" memory use = " << array[i] << endl;
}

int main()
{
	int tmp = 0;
	int tmp2 = 0;
	int* processMemoryUsed = nullptr;
	int processCount = 0;
	Stack stack;
	int totalMemoryUsed = 0;

	while (true)
	{
		cout << "Enter process type count: ";
		cin >> processCount;
		if (processCount >= 1 && processCount < 10000) break;
		cout << "Invalid value" << endl;
	}

	processMemoryUsed = new int[processCount];

	while (tmp2 < processCount)
	{
		system("cls");
		while (true)
		{
			cout << "Enter " << tmp2 + 1 << " process memory use: ";
			cin >> tmp;
			if (tmp > 0 && tmp < 100000)
			{
				processMemoryUsed[tmp2] = tmp;
				tmp2++;
				break;
			}
			cout << "Invalid value" << endl;
		}
	}

	do
	{ 
		system("cls");
		PrintMemoryUse(processCount, processMemoryUsed);
		cout << "Total memory used: " << totalMemoryUsed << endl;
		while (true)
		{
			cout << "Enter process: ";
			cin >> tmp;
			if (tmp > 0 && tmp <= processCount)
			{
				tmp--;
				break;
			}
			cout << "Invalid value" << endl;
		}



		if (!stack.CheckEmpty() || tmp != stack.GetElement())
		{
			stack.Push(tmp);
			totalMemoryUsed += processMemoryUsed[tmp];
		}
		else
		{
			stack.Delete();
			totalMemoryUsed -= processMemoryUsed[tmp];
		}
		
	} while (stack.CheckEmpty());;

	delete[]processMemoryUsed;

	return 0;
}