#include<iostream>
#include<sstream>
#include<string>
#include<climits>

using namespace std;

class SingletonClass
{
public:
    
    SingletonClass(const SingletonClass& ) = delete;
    SingletonClass& operator=(const SingletonClass) = delete;
    SingletonClass(const SingletonClass &&) = delete;
    SingletonClass& operator=(const SingletonClass && ) = delete;
    
    static SingletonClass& getInstance()
    {
        static SingletonClass SingletonObject;
        return SingletonObject;
    }
private:
    SingletonClass() { }
};

int main()
{
    SingletonClass& sc = SingletonClass::getInstance();
    cout << &sc << endl;
    SingletonClass& sc1 = SingletonClass::getInstance();
    cout << &sc1 << endl;
    
    SingletonClass &oneMoreVariableRefObject = sc ;
    cout << &oneMoreVariableRefObject << endl ;
    return 0;
}
