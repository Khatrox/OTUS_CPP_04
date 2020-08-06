//
// Created by xMellox on 05-Aug-20.
//

#ifndef TEST_PRINT_OTUS_CASE_H
#define TEST_PRINT_OTUS_CASE_H

#include <print_ip.h>

namespace otus
{
    template<typename T>
    void print_ip_with_new_line(T&& arg)
    {
        print_ip(std::forward<T>(arg));
        std::cout << '\n';
    }

    void print_otus_case()
    {
        using namespace std::string_literals;

        print_ip_with_new_line(char(-1));

        print_ip_with_new_line(short(0));

        print_ip_with_new_line(2130706433);

        print_ip_with_new_line(8875824491850138409LL);

        print_ip_with_new_line("1234"s);

        std::vector<int> v{14,21,32,43,441,4422,4423};
        print_ip_with_new_line(v);

        std::list<int> l{0,1,2,3,4,5};
        print_ip_with_new_line(l);

        auto t = std::make_tuple(1,2,3,4,5,6,7,8,9,10);
        print_ip_with_new_line(t);

    }
}

#endif //TEST_PRINT_OTUS_CASE_H
