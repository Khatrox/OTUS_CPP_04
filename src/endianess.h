//
// Created by xMellox on 05-Aug-20.
//

#ifndef TEST_ENDIANESS_H
#define TEST_ENDIANESS_H

namespace otus
{
    using byte = unsigned char;

    bool IsThatBigEndian() noexcept
    {
        short val = 1;
        auto val_p = reinterpret_cast<byte*>(&val);

        return *val_p == 0;
    }

    template<typename T>
    T SwapEndian(T var) noexcept
    {
        union
        {
            T var;
            unsigned char byte_array[sizeof(T)];
        } source, ret_val;

        source.var = var;

        for(std::size_t i{}; i < sizeof(T); ++i)
        {
            ret_val.byte_array[i] = source.byte_array[sizeof(T) - i - 1];
        }

        return ret_val.var;
    }
}

#endif //TEST_ENDIANESS_H
