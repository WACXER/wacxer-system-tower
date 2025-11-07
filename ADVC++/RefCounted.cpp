//Create a type-safe, generic container class that supports both 
//intrusive and non-intrusive 

#include <memory>
#include <atomic>

template<typename T>
class RefCounted {
public:
    void addRef() { ++refCount_; }
    void release() { if (--refCount_ == 0) delete this; }
protected:
    RefCounted() : refCount_(1) {
        virtual ~RefCounted() = default;
    }
private: 
    std::atomic<size_t> refCount_;
};

template<typename T>
class Container {
public:
    explicit Container(T* ptr): ptr_(ptr, [](T* p){}) {
        if (auto* rc = dynamic_cast<RefCounted<T>*>(ptr)) rc-> addRef();
    }
    ~Container() {
        if (auto* rc dynamic_cast<RefCounted<T>*>(ptr_.get())) rc-> release()
    }
private:
    std::unique_ptr<T, void(*)(T*)> ptr_;
}
