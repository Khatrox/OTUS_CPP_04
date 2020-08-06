//
// Created by xMellox on 05-Aug-20.
//

#ifndef TEST_PRINT_IP_H
#define TEST_PRINT_IP_H

#include <iostream>
#include <own_type_traits.h>
#include <endianess.h>
#include <tuple>

namespace otus
{
    /*!
     * Specialization for Integral types
     */
    template<typename T,
            typename = std::enable_if_t<std::is_integral_v<T>>
    >
    void print_ip(T var, std::ostream& stream = std::cout)
    {
        T var_copy;
        if(!IsThatBigEndian())
        {
            var_copy = SwapEndian(var);
        }
        else
        {
            var_copy = var;
        }

        union
        {
            T var;
            unsigned char byte_array[sizeof(T)];
        } u;

        u.var = var_copy;
        auto byte_size = sizeof(T);
        auto last_index = byte_size - 1;

        for(std::size_t i{}; i < byte_size; ++i)
        {
            stream << static_cast<unsigned int>(u.byte_array[i]);
            if(i != last_index)
            {
                stream << '.';
            }
        }
    }

    /*!
    * Specialization for String\n
    */
    template<typename T,
            typename = std::enable_if_t<is_string_v<T>>
    >
    void print_ip(const T& var, std::ostream& stream = std::cout)
    {
        stream << var;
    }

    /*!
   * Specialization for Container types
   */
    template<template<class,class> class T,
            typename Type,
            typename Alloc = std::allocator<Type>,
            typename = std::enable_if_t<is_container_v<T<Type,Alloc>>>
    >
    void print_ip(const T<Type,Alloc> container, std::ostream& stream = std::cout)
    {
        for(auto it = std::cbegin(container); it != std::cend(container); ++it)
        {
            stream << *it;
            if(!(std::next(it) == std::cend(container)))
            {
                stream << '.';
            }
        }
    }

    /*!
     * Middle part of print_tuple recursion
     */
    template<std::size_t Index,
            std::size_t TupleSize,
            typename T
    >
    void print_tuple(const T& tuple, std::ostream& stream = std::cout)
    {
        stream << std::get<Index>(tuple);

        if constexpr ((Index + 1) < TupleSize)
        {
            stream << '.';
            print_tuple<Index + 1,TupleSize>(tuple,stream);
        }
    }

    /*!
     * Specialization for Tuple\n
     * Start of recursion\n
     * @tparam T - check other types for equality to that param
     */
    template<template<class...> class T,
            typename ...Args,
            typename = std::enable_if_t<is_tuple_v<T<Args...>> && are_template_params_equal_v<Args...>>
    >
    void print_ip(const T<Args...>& tuple,std::ostream& stream = std::cout)
    {
        print_tuple<0, std::tuple_size_v<T<Args...>>>(tuple,stream);
    }

}
#endif //TEST_PRINT_IP_H
