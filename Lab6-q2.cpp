#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top; // pointer to the top node in the stack

public:
    // constructor
    Stack() {
        top = nullptr; // initialize the top pointer to null (empty stack)
    }

    // function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Error: Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // function to return the top element of the stack
    int stackTop() {
        if (top == nullptr) {
            cout << "Error: Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
    // function to print the elements of the stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
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
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display(); 
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    return 0;
}
