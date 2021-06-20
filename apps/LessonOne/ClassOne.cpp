#include <vector>
#include <string>
#include <iostream>
#include <string.h>

#include "ClassOne.hpp"

ClassOne::ClassOne() = default;

ClassOne::~ClassOne()
{

}

ClassOne::Ptr
ClassOne::create()
{
    ClassOne::Ptr ret{ new ClassOne{} };
    if (ret->init())
        return ret;
    else
        return nullptr;
}

bool
ClassOne::init()
{
    return true;
}