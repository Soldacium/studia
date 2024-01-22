#pragma once
#include <string>
using namespace std;

class Human
{
private:
    string h_name;

public:
    Human();
    Human(string name);

    void showName();
};

class Computer {
private:
    Human user;

public:
    Computer();
    Computer(Human human);
    Human getUser();
    void setUser(Human user);
    void showUsername();
};

class Pen {
private:
    int color;
    Human user;
public:
    Pen();
    Pen(int color);
    void writeColorText(string text);
};

class MyStack {
private:
    int arr[1000];
    int top;
public:
    MyStack();
    ~MyStack();
    bool isEmpty();
    bool isFull();
    void push(int number);
    void pop();
};