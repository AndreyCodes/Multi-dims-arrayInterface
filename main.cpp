#include<iostream>
#include<typeinfo>
#include<type_traits>
#include"derank.hpp"
#include"arr_size.hpp"

using std::size_t;

template<size_t size, size_t ...Sizes>
struct ArrChar
{
    static constexpr size_t dims[size] = {Sizes...};
    static constexpr size_t sz = size;
};

template<class M,size_t k, size_t ...Sizes>
constexpr auto rec()
{
    if constexpr(std::is_array_v<M>)
    {
        return rec<derank_t<M>,k+1,Sizes..., arr_size<M>::size>();
    }
    else
    {
        return ArrChar<k,Sizes...>();
    }
}
template<class M,size_t k = 0, size_t currSize>
void foo(M (&a)[currSize])
{   
    constexpr auto CountOfDimsAndLenghOfDims = rec<std::remove_reference_t<M>,k+1, currSize>();

    //using  CountOfDimsAndSizeOfDims you may go round array.
    //CountOfDimsAndSizeOfDims = {lengOfDims[size], count of dims}
    //DO SOMETHING
    for(auto& el: decltype(CountOfDimsAndLenghOfDims)::dims)
    {
        std::cout << el << ' ';
    }
}
int main()
{  
    char c[23][1][2][3];
    //using mas = int[23][1][2][3];

    //std::cout << test;
    foo(c);
}