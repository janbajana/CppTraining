/* Copyright (c) 2021-2021
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/* 
 GoingNative 2013 C++ Seasoning
 by 

 link: https://youtu.be/W2tWOdzgXHA

 GoingNative 2013 Inheritance Is The Base Class of Evil
 by

 link: https://youtu.be/2bLkxj6EVoM

 Back to the Basics! Essentials of Modern C++ Style
 by Herb Sutter 

 link: https://youtu.be/xnqTKD8uD64

 file: https://github.com/janbajana/going_native
 run: ./test/going_native 

 Book suggestions:
 - Effective Modern C++
 - by Scott Meyers
 - suggested in: https://youtu.be/xnqTKD8uD64 (1:29)

 - A Tour of C++ (C++ In Depth SERIES)
 - by Bjarne Stroustrup
 - suggested in: 
*/

// TODO

// C++ headers
#include <memory>
#include <algorithm>
#include <vector>
#include <string>

#include <iostream>
#include <iomanip>

#include <gtest/gtest.h>

// == Back to the Basics! Essentials of Modern C++ Style ==

template <class Container, class Value>
void
append_unique(Container& c, Value v)
{
    if (std::find(std::begin(c), std::end(c), v) == std::end(c))
        c.push_back(std::move(v));
    assert(c.size() != 0);
}

TEST(back_to_the_basics, use_auto)
{
    std::vector<int> v;
    append_unique(v, 2);
    EXPECT_EQ(v.size(), 1);
}

// User Defined Literals in C++

namespace {
// KiloGram
long double operator"" _kg(long double x)
{
    return x * 1000;
}

// Gram
long double operator"" _g(long double x)
{
    return x;
}

// MiliGram
long double operator"" _mg(long double x)
{
    return x / 1000;
}
}

TEST(back_to_the_basics, user_defined_literals)
{
    long double weight = 3.6_kg;
    EXPECT_FLOAT_EQ(weight, 3600);

    weight = 3.8_mg;
    EXPECT_FLOAT_EQ(weight, 0.0038);

    weight = 3.9_g;
    EXPECT_FLOAT_EQ(weight, 3.9);

    auto x = 42;    //< int
    auto x2 = 42.f; //< float
    auto x3 = 42ul; //< unsigned long
    // auto x4 = "42"s; //< string literal operator
    (void)x;
    (void)x2;
    (void)x3;
}

// Optimise for rvalue with moving semantic

class Employee
{
    std::string mName;

public:
    // For constructor it may be good to pass values by copy as rvalue optimisation.
    // We are constracking strings here not reusing capacity.
    // We should not use const ref ref.
    Employee(std::string name) : mName(std::move(name)) { printf("Employee construct \n"); }

    // It may do memory allocation to extend mName if the memory is lower then source.
    // After that it just copy, what is very fast.
    // Copy on small strings is very fast.
    // This is good optin generally.
    void setName(const std::string& name)
    {
        mName = name;
        printf("Employee::setName const ref \n");
    }

    // Optimise for rvalues.
    // There is one downside for this.
    // This should not throw exception because we are not doing ny heat allocation.
    // This is also good option as optimisation. 
    // Do not use const std::string&& name, it may create a copy!!!
    // First 2 are general default advice.
    void setName(std::string&& name) noexcept
    {
        mName = std::move(name);
        printf("Employee::setName ref ref move \n");
    }

    // Pass by value and move to the object.
    // This will perform copy from lvalue during passing value. Tha is why it may throw exception (noexcept is not correct).
    // void setName(std::string name) noexcept
    // {
    //     mName = std::move(name);
    //     printf("Employee::setName value \n");
    // }

    // Use forward. Only when you know what you are doing. :)
    // This dos not accept string literals.
    // void setName(std::string&& name) noexcept
    // {
    //     mName = std::forward<std::string>(name);
    //     printf("Employee::setName ref ref forward \n");
    // }

    // What is a T&&? A forwarding reference.
};

TEST(back_to_the_basics, moving_semantic)
{
    Employee e("empty");
    std::string name1 = "Jan";
    std::string name2 = "Peter";
    const std::string name3 = "Ondrej";

    e.setName(name1);
    printf(" - name: %s \n", name1.c_str());

    e.setName(std::move(name2));
    printf(" - name: %s \n", name2.c_str());

    e.setName(std::move(name3));
    printf(" - name: %s \n", name3.c_str());
}

// = use tuple for mutiple return values;

// operator overloading.
