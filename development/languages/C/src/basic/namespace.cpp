// A namespace is designed to overcome this difficulty and is used as additional information to differentiate
// similar functions, classes, variables etc. with the same name available in different libraries.
// Using namespace, you can define the context in which names are defined. In essence, a namespace defines a scope.

// Def Namespace
// namespace namespace_name {
//    //code declarations
// }

// To call the namespace-enabled version of either function or variable, prepend (::) the namespace name as follows
// name::code;  // code could be variable or function.

// You can also avoid prepending of namespaces with the using namespace directive.
// This directive tells the compiler that the subsequent code is making use of names in the specified namespace

// The ‘using’ directive can also be used to refer to a particular item within a namespace.
// using std::cout;

#include <iostream>
using namespace std;

// first name space
namespace first_space
{
void func()
{
    cout << "Inside first_space" << endl;
}
} // namespace first_space

// second name space
namespace second_space
{
void func()
{
    cout << "Inside second_space" << endl;
}
} // namespace second_space

// second name space
namespace second_space
{
void func2()
{
    cout << "Inside second_space func2" << endl;
}
void func3();
namespace inner
{
void func()
{
    cout << "Inside second_space inner func" << endl;
}
} // namespace inner
} // namespace second_space

void second_space::func3()
{
    cout << "Inside second_space func3" << endl;
}

int main()
{
    // Calls function from first name space.
    first_space::func();
    using namespace first_space;
    func();
    // Calls function from second name space.
    second_space::func();
    second_space::func2();
    second_space::func3();
    second_space::inner::func();

    return 0;
}