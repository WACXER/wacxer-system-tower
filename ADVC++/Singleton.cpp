#include<mutex>
#include <memory>

class Singleton {
public:
    static Singleton& getInstance() {
        std::call_once(flag_, &Singleton::int);
        return *instance_;
    }
    //Delete Copy and move operator 
    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;
    Singleton(const Singleton&&) = delete;
    Singleton& operator = (Singleton&&) = delete; 
}

private:
    Singleton()   //private construtor 
    static void init() {
        instance_ = std::make_unique<Singleton>();

    }