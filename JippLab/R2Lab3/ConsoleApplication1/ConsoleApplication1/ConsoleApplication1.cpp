// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "zad1.h"

void classLooping() {
    Pen pens[3]{ {2}, {13}, {14} };
    for (int i = 0; i < 3; i++) {
        pens[i].writeColorText("text");
    }
    string ia[2] = { "1", "2"};
    for (Pen* p = pens; p != std::end(pens); ++p) {
        p->writeColorText("abec");
    }
}

void showOptionMenu(){
    cout << "What would you like to do?" << endl;
    cout << "(1) Check if empty" << endl;
    cout << "(2) Check if full" << endl;
    cout << "(3) Push" << endl;
    cout << "(4) Pop" << endl;
    cout << "(5) Exit" << endl;
}

void stackThing() {
    bool isDone = false;
    int option;
    int value;
    MyStack stack;
    cout << "This is stack switch to operate on... stack... one stack" << endl;
    while (!isDone) {
        
        showOptionMenu();
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 1:
            stack.isEmpty();
            break;
        case 2:
            stack.isFull();
            break;
        case 3:
            cout << "Value, please :)" << endl;
            cin >> value;
            stack.push(value);
            break;
        case 4:
            stack.pop();
            break;
        case 5:
            delete &stack;
            break;
        default:
            break;
        }
    }
}

int main()
{
    Human h1("human");
    h1.showName();

    Computer c1(h1);
    c1.showUsername();

    classLooping();

    stackThing();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
