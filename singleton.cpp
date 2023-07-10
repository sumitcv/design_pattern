#include <iostream>
using namespace std;
class Singleton
{
    private:
        Singleton() {};
        Singleton(Singleton& ) = delete;
		Singleton operator=(Singleton&) = delete;
        
    public:
		static Singleton * instance;
        static Singleton * getInstance();

		void foo() { cout << "test object" << endl;}
};

Singleton * Singleton::instance = nullptr;
//Singleton * getInstance()
Singleton * Singleton::getInstance()
        {
			if (Singleton::instance ==  nullptr)
			{
				Singleton::instance = new Singleton();
			}
			return Singleton::instance;
		}

int main()
{
  // Singleton * s = new Singleton(); // not work 
  Singleton* ss = Singleton::getInstance();
  Singleton* aa = Singleton::getInstance();
  cout << ss << endl;
  cout << aa << endl;

  return 0;
}
