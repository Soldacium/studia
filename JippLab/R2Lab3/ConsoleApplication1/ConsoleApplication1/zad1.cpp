#include <string>
#include <iostream>
#include"zad1.h"
#include <windows.h>
using namespace std;

Human::Human() {

}

Human::Human(string name)
{
	this->h_name = name;
}

void Human::showName()
{
	cout << this->h_name << endl;
}

Computer::Computer()
{
}

Computer::Computer(Human human)
{
	this->user = human;
}

Human Computer::getUser()
{
	return this->user;
}

void Computer::setUser(Human user)
{
	this->user = user;
}

void Computer::showUsername()
{
	this->user.showName();
}

Pen::Pen()
{
}

Pen::Pen(int color)
{
	this->color = color;
}

void Pen::writeColorText(string text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, this->color);
	cout << text << endl;
	SetConsoleTextAttribute(hConsole, 7);
}

MyStack::MyStack()
{
	top = 0;
}

MyStack::~MyStack()
{
	cout << "Done with the MyStack" << endl;
	delete &arr;
}

bool MyStack::isEmpty()
{
	return (top == -1);
}

bool MyStack::isFull()
{
	return (top == 999);
}

void MyStack::push(int number)
{
	if (!isFull()) {
		top++;
		arr[top] = number;
	}
	else {
		cout << "Stack is full." << endl;
	}
}

void MyStack::pop()
{
	if (!isEmpty()) {
		int poppedElement = arr[top];
		top--;
		cout << "Popped element: " << poppedElement << " from the Stack.\n";
	}
	else {
		cout << "Stack is empty. Cannot pop from an empty MyStack.\n";
	}
}
