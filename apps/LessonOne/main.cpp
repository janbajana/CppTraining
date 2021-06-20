#include <iostream>
#include <string.h>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <utility>

#include "Macros.hpp"
#include "ClassOne.hpp"
#include "TemplateClass.hpp"

using namespace std;

// TODO integrate google test instead.
// https://github.com/kigster/cmake-project-template/blob/master/.gitmodules

// CppCon 2015: Richard Powell “The Importance of Being const"
// https://www.youtube.com/watch?v=Y1KOuFYtTF4

static const char* const HEADER = "\nLessonOne © 2021 Monkey Claps Inc.\n\n";
static const char* const USAGE = "Usage:\n\tdivider <numerator> <denominator>\nDescription:\n\tComputes the result of a fractional division.\n";

static const char* const TESTS[]{
    "validExpression\0",
    "Test2\0"
};

/**
 * Test cons expressions.
 */
void
validExpression()
{
    int a[] = { 1, 2, 3 };

    int* b = a;
    b++;
    *b = 20;

    int const* c = a;
    c++;
    // *c = 20;             //invalid expression

    int* const d = a;
    // d++;                 //invalid expression
    *d = 20;

    int const* const e = a;
    // e++;                 //invalid expression
    // *e = 20;             //invalid expression
    std::cout << "e = " << *e << "\n";

    int i = 3; // i is not declared const
    const int& rci = i;
    const_cast<int&>(rci) = 4; // OK: modifies i
    std::cout << "i = " << i << '\n';
}

/**
 * Test const expression in function.
 */
void
constFunction()
{
    static TemplateClass<float> myVector{ 5, 5, 5 };
    std::cout << "length = " << myVector.length() << '\n';

    // timesCalled is not thread safety. But length() signalizes that function should only read.
    // so mutex has to be added. But mutex is heavy so atomic variable would be better option.
    static const TemplateClass<float> myVector2{ 6, 6, 6 };
    std::cout << "length = " << myVector2.length() << '\n';
}

int
main(int argc, const char* argv[])
{
    std::cout << HEADER;

    // ensure the correct number of parameters are used.
    if (argc < 2)
    {
        cout << USAGE;
        return 1;
    }

    const char* test = argv[1];

    // run a tes.
    if (strcmp(test, TESTS[0]) != 0)
        std::cerr << "The test dos not exist: " << std::string(test) << std::endl;
    else
        std::cout << "Running test: " << std::string(test) << std::endl;

    if (strcmp(test, TESTS[0]) == 0)
    {
        validExpression();

        std::thread refresh_thread = std::thread(
            [&]() {
                std::chrono::milliseconds time(10);
                size_t loops = 4;
                while (loops > 0)
                {
                    std::this_thread::sleep_for(time);
                    std::cout << "refresh_thread" << std::endl;
                    constFunction();
                    --loops;
                }
            });

        std::thread refresh_thread2 = std::thread(
            [&]() {
                std::chrono::milliseconds time(10);
                size_t loops = 4;
                while (loops > 0)
                {
                    std::this_thread::sleep_for(time);
                    std::cout << "refresh_thread2" << std::endl;
                    constFunction();
                    --loops;
                }
            });

        refresh_thread.join();
        refresh_thread2.join();
    }

    std::cout << "\nProgram finished successfully!\n";
    return 0;
}