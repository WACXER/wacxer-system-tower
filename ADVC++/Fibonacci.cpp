//Write a C++ template metaprogramming solution to compute the fibonacci sequence 
//at compile time for any given n < 100;

template<size_t N>
struct Fibonacci {
    static constexpr unsigned long long value = Fibonacci<N-1>::value + 
                                Fibonacci<N-2>::value;

template<>
struct Fibonacci<0> {
    static constexpr unsigned long long value = 0; 
};

template<>
struct Fibonacci<1> {
    static constexpr unsigned long longvalue = 1;
}

constexpr unsigned long long value getFibonacci(size_t n ) {
    return Fibonacci<50>::value; //for n = 50
}
