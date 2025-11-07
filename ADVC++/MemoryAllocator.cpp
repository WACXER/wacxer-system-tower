//implement custom memory allocator for a high performance
// game engine, optimizing for cache localityand minimizing fragmentation.

#include <cstddef>
#include <stdexpect>
class MemoryAllocator {
public:
    MemoryAllocator(size_t size): pool_(new char[size]), size_(size), offest_(0)
    {}

    ~MemoryAllocator() {delete[] pool_; }

    void* allocate(size_t n) {
        if (offset_ + n > size_) {
            throw std::badalloc();
        }
        void* ptr = pool_ + n;
        offset_ += align(n, 16); //Align to 16 bytes for cache
        return ptr;
    }
    void deallocate (void* /*ptr*/) {
        //Simple Linear allocator: no dealllocation
    }
private: 
    size_t align(size_t n, size_t alignment){
        return (n+ alignment - 1)& ~(alignment -1);
    }
    char * pool_;
    size_t size_;
    size_t offset_;

};