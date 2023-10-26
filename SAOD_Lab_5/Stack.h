#pragma once
#include <iostream>
using namespace std;

class Stack
{
	class Element
	{
	public:
		Element* prev = nullptr;
		int data = 0;
	};
	Element* head = nullptr;

public:
	void Push(int& n);
	void Delete();
	bool CheckEmpty();
	void Clear();
	int GetElement();
	~Stack();
};

