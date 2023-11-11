#include<iostream>
#include<sstream>
#include<string>
#include<climits>
#include<mutex>
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
        lock_guard<mutex> lock(m);
        static SingletonClass SingletonObject;
        return SingletonObject;
    }
private:
    SingletonClass() { }
/* 
In C++, you can initialize static members at the point of declaration within the class. 
However, if you need more complex initialization logic or if you are dealing with non-trivial types, you might prefer to perform the initialization outside the class definition. 
This is what the line std::mutex SingletonClass::mutex_; does.
/*

    static mutex m; // Mutex initialization 
};a

  /*
  this line initializes the static member mutex_ outside the class. It allocates memory for the mutex_ and constructs the std::mutex object. 
  This initialization typically happens in a source (.cpp) ftile rather than a header file.
   If you were to initialize the mutex_ directly within the class (e.g., static std::mutex mutex_;), it would work, but this initialization would 
occur for every translation unit that includes the header. This can lead to multiple definition errors because the compiler sees multiple definitions of the same static member.
By initializing it outside the class in a single source file, you ensure that there's only one definition of the static member in your program, avoiding linker errors related to multiple definitions.
  */
mutex SingletonClass::m; // 

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

