/* 
(Because no virtual → static binding)

If the base function is not virtual, a same-signature function in the derived class HIDES the base one, but does NOT override it.


*/

class ConsoleLogger {
public:
    void Log(std::string message) {
        std::cout << "Console: " << message << std::endl;
    }
};

class FileLogger : public ConsoleLogger {
public:
    void Log(std::string message) {   // same signature, no virtual
        std::ofstream writer("log.txt", std::ios::app);
        writer << message << std::endl;
    }
};
int main()

{
    FileLogger fl;
    fl.Log("Hello");   // FileLogger::Log

    ConsoleLogger cl;
    cl.Log("Hello");   // ConsoleLogger::Log

    ConsoleLogger* ptr = new FileLogger();
    ptr->Log("Hello"); // ConsoleLogger::Log (NOT polymorphic!)

    return 0;
}