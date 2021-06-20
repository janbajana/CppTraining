#include <iostream>
#include <string.h>
#include <stdio.h>

#include "Macros.hpp"
#include "ClassOne.hpp"
#include "TemplateClass.hpp"

using namespace std;

// TODO integrate google test instead.

// CppCon 2015: Richard Powell “The Importance of Being const"
// https://www.youtube.com/watch?v=Y1KOuFYtTF4

void validExpression();

static const char *const HEADER = "\nLessonOne © 2021 Monkey Claps Inc.\n\n";
static const char *const USAGE = "Usage:\n\tdivider <numerator> <denominator>\nDescription:\n\tComputes the result of a fractional division.\n";

static const char *const TESTS[]{
    "validExpression\0",
    "Test2\0"};

void validExpression()
{
    int a[] = {1, 2, 3};

    int *b = a;
    b++;
    *b = 20;

    int const *c = a;
    c++;
    // *c = 20;             //invalid expression

    int *const d = a;
    // d++;                 //invalid expression
    *d = 20;

    int const *const e = a;
    // e++;                 //invalid expression
    // *e = 20;             //invalid expression
    std::cout << *e << "\n";
}

int main(int argc, const char *argv[])
{
    std::cout << HEADER;

    // ensure the correct number of parameters are used.
    if (argc < 2)
    {
        cout << USAGE;
        return 1;
    }

    const char *test = argv[1];

    TemplateClass<float> myVector;

    // run a tes.
    std::cout << "Running test: " << std::string(test) << std::endl;

    if (strcmp(test, TESTS[0]) == 0)
    {
        validExpression();
    }

    // use arv here
    CT_UNUSED(myVector);

    std::cout << "Program finished successfully!\n";
    return 0;
}