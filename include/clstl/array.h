#ifndef ARRAY_H
#define ARRAY_H

#pragma once

#include <clstl/types.h>
#include <stdarg.h>
#include <cstring>

namespace clstl {

    template<typename T, uint N>
    struct array {

    private:
        T m_Data[N];

    public:

        uint size = N;

        array() = default;

        array(T data, ...) {

            va_list arglist;
            va_start(arglist, data);

            m_Data[0] = data;
            for (uint i = 1; i < N; i++) {
                m_Data[i] = va_arg(arglist, T);
            }

        }

        array(const array<T, N>& other) {

            std::memcpy(m_Data, other.m_Data, sizeof(T) * N);

        }

        array(T* data) {
            std::memcpy(m_Data, data, sizeof(T) * N);
        }

        T& at(uint index) { return m_Data[index]; }
        T& operator[](uint index) { return this->at(index); }
        
        void operator=(const array<T, N>& other) {
            std::memcpy(m_Data, other.data, sizeof(T) * N);
        }

        void set_data(T* data) {
            std::memcpy(m_Data, data, sizeof(T) * N);
        }

    };

}

#endif