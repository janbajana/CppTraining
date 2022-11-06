#pragma once

#include <atomic>
#include <memory>
#include <cmath>
#include <stdio.h>
#include <mutex>

template <typename Scalar>
class TemplateClass
{
public:
    TemplateClass() = default;
    TemplateClass(Scalar _x, Scalar _y, Scalar _z) : x(_x), y(_y), z(_z) {}

    Scalar length() const
    {
        // std::lock_guard<std::mutex> l(mutex);
        ++timesCalled;
        std::cout << "TemplateClass::length() const " << timesCalled << " - ";
        return std::sqrt(x * x + y * y + z * z);
    }

    Scalar length()
    {
        // std::lock_guard<std::mutex> l(mutex);
        ++timesCalled;
        std::cout << "TemplateClass::length() " << timesCalled << " - ";
        return std::sqrt(x * x + y * y + z * z);
    }

    // What compiler does here? Compiler creates name mangled free function.
    // float __ZNK3TemplateClass8lengthEv(TemplateClass const * const this)
    // {
    //     return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    // }

    Scalar getCheckSum() const
    {
        return timesCalled;
    }

private:
    Scalar x;
    Scalar y;
    Scalar z;

    // This code is toxics. This may cause race condition.
    // Because we are writing in "length() const". Const should mean data race free.
    mutable std::atomic<int> timesCalled{ 0 };

    // so we have to add mutex
    // but std::atomic is faster.
    // mutable std::mutex mutex;

    // mutexts and atomics are not copyable. Be aware of it.
};
