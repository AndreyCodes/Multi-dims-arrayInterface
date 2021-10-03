#ifndef DERANK_HPP
#define DERANK_HPP
#include<cstddef>

template<class T>
struct derank
{
    using type = T;
};
template<class T>
struct derank<T[]>
{
    using type = T;
};

template<class T, std::size_t N>
struct derank<T[N]>
{
    using type = T;
};

template<class T>
using derank_t = typename derank<T>::type;

#endif