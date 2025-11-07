#include <cstring>
#include <atomic>

class String {
public: 
    String(const char* str = ""){
        size_t len = strlen(str);
        if (len <= 15) {
            memccpy(buffer_, str, len+1);
            data_ = buffer_;
        } else {
            data_ new char[len + 1];
            strcpy(data_, str);
            refCount_ = new std::atomic<<size_t>(1)
        }
        size_ = len;
    }

    String(const String& other): data_(other.data_), size_(other.size_),
        refCount_(other.refCount_) {
        if(data_ != buffer_) ++(*refCount_);
        memcpy(buffer_, other.buffer_, 16);
        }
    ~String() {
        if (data_ != buffer_ && --(*refCount_) == 0) {
            delete[] data_;
            delete refCount_;
        }
    }
private:
    char* data_;
    char buffer_[16];
    size_t size_;
    std::atomic<size_t>* refCount_ = nullptr;
}