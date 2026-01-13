#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
// Logger class 
class Logger
{
  private:
      Logger()
      {
          logFile.open("logfile.log", std::ios::app);
          if(!logFile.is_open())
          {
              std::cerr << "file cannot be open" << endl;
              abort();
          }
      }
      Logger(const Logger&) = delete;
      Logger(Logger&&) = delete ;
      Logger& operator = (const Logger &) = delete;
      Logger&& operator =(Logger&&) = delete;
      
      static Logger* loggingInstance;
      std::ofstream logFile;
      static std::once_flag flag;
      
  public:
      static Logger * getInstance()
      {
          
          std::call_once(flag, []
          {
              loggingInstance = new Logger;
          });
          return loggingInstance;
      }
      
      void log_message(string message)
      {
          static std::mutex writeMutex;
          std::lock_guard<mutex> lock(writeMutex);
          logFile << message << endl;
      }
};
Logger * Logger::loggingInstance = nullptr;
std::once_flag Logger::flag;

// Thread function 
void worker(string message)
{
    Logger *log = Logger::getInstance();
    log->log_message(message);
}

int main()
{
    std::vector<thread> threads;
    for (int i =0; i<=10; i++)
    {
        threads.push_back(thread(worker, "Hello I am Thread " + to_string(i)));
    }
    for (auto &th : threads)
    {
        th.join();
    }
    return 0;
}
