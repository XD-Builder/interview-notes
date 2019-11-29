// Templates are the foundation of generic programming, which involves writing code in a way that is independent of any particular type.

// A template is a blueprint or formula for creating a generic class or a function. The library containers like iterators and
// algorithms are examples of generic programming and have been developed using template concept.

// There is a single definition of each container, such as vector, but we can define many different kinds of vectors for example, vector <int> or vector <string>.

// You can use templates to define functions as well as classes

// Function Template
// template <class type> ret-type func-name(parameter list) {
//    // body of function
// }

// Class Template
// template <class type> class class-name {
//    ...
// }
// Here, type is the placeholder type name, which will be specified when a class is instantiated.
// You can define more than one generic data type by using a comma-separated list.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

// function template
// template defined with a T as the type returns a constant address of type T.
// It takes two variable passed address to a and b so it can be referenced
// and avoids variables being stored on the stack.
template <typename T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? b : a;
}

// class template
template <class T>
class Stack
{
// private functions declarations
private:
    vector<T> elems; // elements

// public functions declarations
public:
    void push(T const &); // push element
    void pop();           // pop element
    T top() const;        // return top element

    bool empty() const
    { // return true if empty.
        return elems.empty();
    }
};

// Stack class template method definitions
template <class T>
void Stack<T>::push(T const &elem)
{
    // append copy of passed element
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::pop(): empty stack");
    }

    // remove last element
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::top(): empty stack");
    }

    // return copy of last element
    return elems.back();
}

void functionTemplate()
{
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;
}

void classTemplate()
{
    try
    {
        Stack<int> intStack;       // stack of ints
        Stack<string> stringStack; // stack of strings

        // manipulate int stack
        cout << "Push 7 to the stack" << endl;
        intStack.push(7);
        cout << "Top of stack: " << intStack.top() << endl;

        // manipulate string stack
        cout << "Push hello to the string stack" << endl;
        stringStack.push("hello");
        cout << "Top of stringstack: " << stringStack.top() << std::endl;
        cout << "Pop string stack" << endl;
        stringStack.pop();
        cout << "Pop string stack, empty stack should throw exception" << endl;
        stringStack.pop();
    }
    catch (exception const &ex)
    {
        cerr << "Exception: " << ex.what() << endl;
    }
}

int main()
{
    functionTemplate();
    classTemplate();
    return 0;
}