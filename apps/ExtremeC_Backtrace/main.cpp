#include <iostream>
#include <string.h>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <utility>

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

#include "Macros.hpp"
#include "TemplateClass.hpp"

using namespace std;

static const char* const HEADER = "\nLessonOne © 2021 Monkey Claps Inc.\n\n";
static const char* const USAGE = "Usage:\n\tdivider <numerator> <denominator>\nDescription:\n\tComputes the result of a fractional division.\n";

static const char* const TESTS[]{
    "validExpression\0",
    "Test2\0"
};

void
createCrash()
{
    std::cout << "nullPointer" << std::endl;

    TemplateClass<float>* myVector = nullptr;
    if (myVector == nullptr)
        std::cout << "is null: " << std::endl;

    std::cout << "length = " << myVector->length() << '\n';

}

int
main(int argc, const char* argv[])
{
    signal(SIGSEGV, handler);   // install our handler
    std::cout << HEADER;

    createCrash();

    std::cout << "\nProgram finished successfully!\n";
    return 0;
}