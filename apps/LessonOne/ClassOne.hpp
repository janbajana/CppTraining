#pragma once

#include <memory>

class ClassOne
{
public:
    using Ptr = std::unique_ptr<ClassOne>;
    static Ptr create();

    ~ClassOne();

private:
    bool init();
    ClassOne();
};
