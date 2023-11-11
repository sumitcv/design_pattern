#include<iostream>
#include<sstream>
#include<string>
#include<climits>

using namespace std;

class SingletonClass
{
public:
    static SingletonClass * SingletonObject;
    
    static SingletonClass* getInstance()
    {
        if (SingletonObject == nullptr)
            SingletonObject = new SingletonClass();
        return SingletonObject;
    }
private:
    SingletonClass() {}
    SingletonClass(const SingletonClass& ) = delete;
    SingletonClass& operator=(const SingletonClass) = delete;
    SingletonClass(const SingletonClass &&) = delete;
    SingletonClass& operator=(const SingletonClass && ) = delete;
};
SingletonClass * SingletonClass::SingletonObject = nullptr;

int main()
{
    SingletonClass* sc = SingletonClass::getInstance();
    cout << "Address of sc: " << sc << endl;
    SingletonClass* sc1 = SingletonClass::getInstance();
    cout << "Address of sc1: " << sc1 << endl;
    
    SingletonClass * sscc = sc; 
    cout << "Address of sscc: " << sscc << endl;
    return 0;
}

