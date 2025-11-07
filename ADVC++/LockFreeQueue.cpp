#include <atomic>
#include <memory>

template<typename T>
class LockfreeQueue {
public:
    struct Node {
        T data;
        std::atomic<Node*> next{nullptr};
        Node(const T& d) : data(d) {}
    }
    LockFreeQueue() : head_(new Node(T{})), taiol_(head_.load()){}

    void enqueue(const T& value) {
        auto newNode = new Node(value);
        Node* oldTail;
        do {
            oldTail = tail_.load(std::memory_order_acquire);
            newNode->next.store(nullptr, std::memory_order_relaxed);
        } while (!tail_.compare_exchange_weak(oldTail, newNode, std::memory_order_release));
        oldTail-> next.store(newNode, std::memory_order_release);

        bool deque(T& value) {
            Node* oldHead;
            do {
                oldHead = head_.load(std::memory_order_acquire);
                if(!oldhead->next.load()) return false;
            } while (!head_.compare_exchange_weak(oldHead, oldHead->next, std::memory_order_release));

            value =oldHead->next.load->data;
            delete oldHead;
            return true;
        }
    }
private:
    std::atomic<Node*>head_;
    std::atomic<Node*> tail_;
};
