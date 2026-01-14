
// Simple Observer Design Pattern
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Observer
{
public:
    virtual void notify(std::string title) =0;
    virtual ~Observer() {}
};

class Producer
{
    std::vector<Observer*> subscriber;
    
public:
    void register_subscriber(Observer* sub)
    {
        subscriber.push_back(sub);
    }
    
    void publish(string name)
    {
        cout << "Publishing video .. : " << name << endl;
        for(auto& s : subscriber)
        {
            s->notify(name);
        }
    }
};

class User: public Observer
{
    string name;
public:
    User(string n): name(n){}
    void notify(string n)
    {
        cout << "new video has been released - " << n << endl;
    }
};

int main()
{
    User user1("Ram");
    User user2("Shayam");
    
    Producer p;
    p.register_subscriber(&user1);
    p.register_subscriber(&user2);
    p.publish("Bangalore to Hyderabad Video");
    
    return 0;
}
