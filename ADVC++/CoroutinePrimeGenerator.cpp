//Write a C++20 coroutine-based generator for producing prime numbers 
//up to a givne limit with minimal memory overhead

#include <coroutine>
#include <vector>

struct Generator {
    struct promise_type {
        int current;
        std::suspend_always yield_value(int value) {
            current = value;
            return {};
        }
        std:suspend_never return_void() {};
        std::suspend_always initial_suspend() {return {}; }
        void unhandled_exception() {}
        Generator get_return-object() {return {this};}
    };

    struct Iterator {
        std::coroutine_handle<promise_type> coro;
        bool operator!= (const Iterator& ) const {return !coro.done();}
        void operator++() { coro.resume();}
        int operator*() const {return coro.promise().current;}
    };

    Iterator begin() {
        handle.resume();
        return {handle};
    }
    Iterator end() { return {handle}; }
private:
    Generator(promise_type* p ):
        handle(std::coroutine_handle<promise_type>::from_promise(*p)){}
    std::coroutine_handle<promise_type> handle;
};

Generator generatePrimes(int limit) {
    std::vector<bool>sieve(limit+ 1, true);
    for (int i = 2; i*i <= limit; ++i)
    {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) sieve[j] = false;
        }
    }
    for (int i = 2; i <= limiy; ++i) {
        if sieve[i] co_yield i;
    }
}
