#include <iostream>
using namespace std;

#define MAX_SIZE 100 // maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE];
    int top; // index of the top element in the stack

public:
    // constructor
    Stack() {
        top = -1; // initializing the top index to -1 
    }

    // function to push an element into the stack
    void push(int value) {
	top++;
        if (top > MAX_SIZE ) {
            cout << "Stack overflow" << endl;
            return;
        }
        
        arr[top] = value;
    }

    // function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }

    // function to return the top element of the stack
    int stackTop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    // function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top== MAX_SIZE;
    }
    // function to print the elements of the stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();//expected output: Stack: 8 10 5 11 15 23 6 18 20 17
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display(); // expected output: Stack: 8 10 5 11 15
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display(); // expected output: Stack: 8 10 5 11 15 4 30 3 1

    return 0;
}
