//
// Created by xMellox on 05-Aug-20.
//

#ifndef TEST_OWN_TYPE_TRAITS_H
#define TEST_OWN_TYPE_TRAITS_H

#include <list>
#include <vector>
#include <string>

template<typename T>
struct is_string
{
    static constexpr bool value = false;
};

template<>
struct is_string<std::string>
{
    static constexpr bool value = true;
};

template<typename ...Args>
struct is_container
{
    static constexpr bool value = false;
};

template<typename ...Args>
struct is_container<std::vector<Args...>>
{
static constexpr bool value = true;
};

template<typename ...Args>
struct is_container<std::list<Args...>>
{
static constexpr bool value = true;
};

template<typename ...Args>
struct is_tuple
{
    static constexpr bool value = false;
};

template<typename ...Args>
struct is_tuple<std::tuple<Args...>>
{
    static constexpr bool value = true;
};

template<typename CheckType, typename T, typename ...Args>
struct are_template_params_equal
{
    static constexpr bool value()
    {
        if (std::is_same_v<CheckType, T>)
        {
            return are_template_params_equal<CheckType,Args...>::value();
        }
        else
        {
            return false;
        }
    }
};

template<typename CheckType, typename T>
struct are_template_params_equal<CheckType,T>
{
    static constexpr bool value()
    {
        return std::is_same_v<CheckType, T>;
    }
};

template<typename T>
struct are_template_params_equal<T,T>
{
    static constexpr bool value()
    {
        return true;
    }
};

template<typename T>
constexpr bool is_string_v = is_string<T>::value;

template<typename ...Args>
constexpr bool is_container_v = is_container<Args...>::value;

template<typename ...Args>
constexpr bool is_tuple_v = is_tuple<Args...>::value;

template<typename ...Args>
constexpr bool are_template_params_equal_v = are_template_params_equal<Args...>::value();

#endif //TEST_OWN_TYPE_TRAITS_H
