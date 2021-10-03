#ifndef ARR_SIZE
#define ARR_SIZE
#include<type_traits>

template<class T>
struct arr_size
{
    static constexpr std::size_t size = 0;
    using type = arr_size;
    constexpr operator std::size_t() const noexcept {return 0;}
    constexpr std::size_t operator()() const noexcept{return 0;}
};

template<class T, std::size_t N>
struct arr_size<T[N]>
{
    static constexpr std::size_t size = N;
    using type = arr_size;
    constexpr operator std::size_t() const noexcept {return size;}
    constexpr std::size_t operator()() const noexcept{return size;}
};
#endif