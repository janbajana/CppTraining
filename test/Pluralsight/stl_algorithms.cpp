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
 Beautiful C++: STL Algorithms
 by Kate Gregory

 link: https://app.pluralsight.com/library/courses/beautiful-cplusplus-stl-algorithms/table-of-contents
 file: https://github.com/janbajana/CppTraining
 run: ./test/CppTraining_test --gtest_filter="stl_algorithms.*" 
*/

// C headers
#include <stdio.h>

// C++ headers
#include <algorithm> //< The algorithms library is defined in algorithm  header.
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <iterator>

// GTest headers
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>

/* 
 The standard library has 3 major categories:
  - Collections: vector, map, etc. (containers)
  - Algoritms: find, sort, etc. They work on any container.
  - Iterators: they are almost like pointers but provide significant functionality. Algoritms usually work with iterators.

 Related :
 CppCon 2018: 105 STL Algorithms in Less Than an Hour
 by Jonathan Boccara
  - https://youtu.be/2olsGf6JIkU
 
 Usefull headers you may need if you work with algoritms.
  - <algorithm>
  - <vector> <array> <list> <stack> <map> <queue>
  - <string>
  - <iterator>
  - <utility> <tuple>
  - <numeric>
  - <complex> <math>
  - <regex> <chrono>
*/

static std::vector<int> findData = {
    // clang-format off
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    // clang-format on
};

static std::string dataString{ "Hello I am sentence." };

// == Count elements

static void
fill_vector(std::vector<int>& dest, size_t iters)
{
    dest.reserve(1000);
    for (size_t i = 0; i < iters; i++)
        dest.emplace_back(i);
}

// == Counting and Finding ==

// Count elements which includes a value.
static int
count_custom(const std::vector<int>& argData, const int targetValue)
{
    int count = 0;
    for (const auto element : argData)
    {
        if (element == targetValue)
        {
            count++;
        }
    }
    return count;
}

static void
benchmark_count_with_for(benchmark::State& state)
{
    std::vector<int> v = findData;
    const int targetValue = 2;

    // First do some benchmarks.
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(count_custom(v, targetValue));
    }

    auto result = count_custom(v, targetValue);
    EXPECT_EQ(result, 10);
}

static void
benchmark_count_with_std(benchmark::State& state)
{
    std::vector<int> v = findData;
    const int targetValue = 2;

    // First do some benchmarks.
    for (auto _ : state)
    {
        // To use non member begin and end. It can work for C style arrays as well.
        benchmark::DoNotOptimize(std::count(std::begin(v), std::end(v), targetValue));
    }

    auto result = std::count(std::begin(v), std::end(v), targetValue);
    EXPECT_EQ(result, 10);
}

// Count how many elements are odd. Use for loop.
static int
count_if_custom(const std::vector<int>& argData)
{
    int count = 0;
    for (const auto element : argData)
    {
        if (element % 2 != 0)
        {
            count++;
        }
    }
    return count;
}

static void
benchmark_odd_for(benchmark::State& state)
{
    std::vector<int> v = findData;

    // First do some benchmarks.
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(count_if_custom(v));
    }

    auto result = count_if_custom(v);
    EXPECT_EQ(result, 240);
}

// Count how many elements are odd. Use count_if.
static void
benchmark_odd_std_member(benchmark::State& state)
{
    std::vector<int> v = findData;

    // First do some benchmarks.
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::count_if(v.begin(), v.end(), [](const auto& element) { return element % 2 != 0; }));
    }

    auto result = std::count_if(v.begin(), v.end(), [](const auto& element) { return element % 2 != 0; });
    EXPECT_EQ(result, 240);
}

// == Finding and Searching

// Find number in vector.
static void
benchmark_find_number(benchmark::State& state)
{
    std::vector<int> v;
    fill_vector(v, 1000);
    const int findMe = 5;

    // First do some benchmarks. Change value to see how time changes.
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::find(v.begin(), v.end(), 5));
    }

    // Find the first number.
    auto result = std::find(v.begin(), v.end(), findMe);
    EXPECT_NE(result, v.end());
    if (result != v.end())
    {
        EXPECT_EQ(*result, findMe);
    }

    // Find first odd value.
    result = std::find_if(v.begin(), v.end(), [](auto element) { return element % 2 != 0; });
    EXPECT_NE(result, v.end());
    if (result != v.end())
    {
        EXPECT_EQ(*result, 1);
    }

    // Find first even value.
    result = std::find_if_not(v.begin(), v.end(), [](auto element) { return element % 2 != 0; });
    EXPECT_NE(result, v.end());
    if (result != v.end())
    {
        EXPECT_EQ(*result, 0);
    }

    // Find first found from primes.
    std::vector<int> primes{ 1, 2, 3, 5, 7, 11, 13 };
    result = std::find_first_of(v.begin(), v.end(), primes.begin(), primes.end());
    EXPECT_NE(result, v.end());
    if (result != v.end())
    {
        EXPECT_EQ(*result, 1);
    }

    // Find first foolow by 5,6.
    std::vector<int> subSequence{ 5, 6 };
    result = std::search(v.begin(), v.end(), subSequence.begin(), subSequence.end());
    EXPECT_NE(result, v.end());
    if (result != v.end())
    {
        EXPECT_EQ(*result, 5);
        result++;
        EXPECT_EQ(*result, 6);
        result++;
        EXPECT_EQ(*result, 7);
    }
}

// Find character in string
static void
benchmark_find_string(benchmark::State& state)
{
    std::string s = dataString;
    const char findMe = 'a';

    // First do some benchmarks. Change value to see how time changes.
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::find(s.begin(), s.end(), 'a'));
    }

    auto result = std::find(s.begin(), s.end(), findMe);
    EXPECT_NE(result, s.end());
    if (result != s.end())
    {
        EXPECT_EQ(*result, findMe);
    }

    // Find last sequence of em.
    std::string em = "en";
    result = std::find_end(s.begin(), s.end(), em.begin(), em.end());
    EXPECT_NE(result, s.end());
    if (result != s.end())
    {
        EXPECT_EQ(*result, 'e');
        result++;
        result++;
        EXPECT_EQ(*result, 'c');
    }

    // Search a range for a number of consecutive copies of an element.
    result = std::search_n(s.begin(), s.end(), 2, 'l');
    EXPECT_NE(result, s.end());
    if (result != s.end())
    {
        EXPECT_EQ(*result, 'l');
        result--;
        EXPECT_EQ(*result, 'e');
    }

    // Finds the first two adjacent items that are equal.
    result = std::adjacent_find(s.begin(), s.end());
    EXPECT_NE(result, s.end());
    if (result != s.end())
    {
        EXPECT_EQ(*result, 'l');
        result++;
        EXPECT_EQ(*result, 'l');
    }
}

// == Sorting ==

static std::vector<int> sortData = {
    // clang-format off
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    // clang-format on
};

struct Employee
{
    std::string firstName;
    std::string lastName;
    int salary;

    int getSalary() const { return salary; }
    std::string getSortingName() const { return firstName + "." + lastName; }
};

static std::vector<Employee> staff{
    { "Rick", "Novak", 1001 },
    { "Ronald", "Barr", 1002 },
    { "Susan", "Connor", 1002 },
    { "Roger", "Run", 1008 },
    { "Jeff", "Johnsin", 1000 },
};

static void
benchmark_sort_numbers(benchmark::State& state)
{
    std::vector<int> v = sortData;

    // First do some benchmarks. Change value to see how time changes.
    for (auto _ : state)
    {
        std::sort(std::begin(v), std::end(v));
        EXPECT_EQ(*std::begin(v), -49);
        EXPECT_EQ(*(std::end(v) - 1), 39);
    }

    // Check if it is sorted
    auto isSorted = std::is_sorted(std::begin(v), std::end(v));
    EXPECT_TRUE(isSorted);
    // Check min and max elements is sorted array.
    EXPECT_EQ(*std::begin(v), -49);
    EXPECT_EQ(*(std::end(v) - 1), 39);

    // Check min and max elements is sorted array. The check is faster on sorted elements.
    int min = *std::min_element(std::begin(v), std::end(v));
    int max = *std::max_element(std::begin(v), std::end(v));
    EXPECT_EQ(min, -49);
    EXPECT_EQ(max, 39);

    // Find a first element which is grater then zero.
    int positive = *std::upper_bound(std::begin(v), std::end(v), 0);
    EXPECT_EQ(positive, 1);

    // Sort vector in opposite way;
    std::sort(std::begin(v), std::end(v), [](int element1, int element2) { return element1 > element2; });
    EXPECT_EQ(*std::begin(v), 39);
    EXPECT_EQ(*(std::end(v) - 1), -49);

    // Sort vector in opposite way by absolute value;
    std::sort(std::begin(v), std::end(v), [](int element1, int element2) { return std::abs(element1) > std::abs(element2); });
    EXPECT_EQ(*std::begin(v), -49);
    EXPECT_EQ(*(std::end(v) - 1), 0);
}

// Sort employees from Employee struct.
static void
benchmark_sort_employees(benchmark::State& state)
{
    std::vector<Employee> v = staff;

    // First do some benchmarks. Change value to see how time changes.
    for (auto _ : state)
    {
        std::sort(std::begin(v), std::end(v),
                  [](const auto& e1, const auto& e2) { return e1.getSalary() > e2.getSalary(); });
        EXPECT_EQ(std::begin(v)->getSalary(), 1008);
        EXPECT_EQ((std::end(v) - 1)->getSalary(), 1000);
    }

    std::sort(std::begin(v), std::end(v),
              [](const auto& e1, const auto& e2) { return e1.getSortingName() < e2.getSortingName(); });
    EXPECT_EQ(std::begin(v)->getSortingName(), "Jeff.Johnsin");
    EXPECT_EQ((std::end(v) - 1)->getSortingName(), "Susan.Connor");

    // Search for first element x such that i ≤ x
    auto lowerBound = std::lower_bound(std::begin(v), std::end(v), "Jeff.Johnsin",
                                       [](const auto& e1, const std::string& n) { return e1.getSortingName() < n; });
    EXPECT_NE(lowerBound, v.end());
    EXPECT_EQ(lowerBound->getSortingName(), "Jeff.Johnsin");

    // Sorts a range of elements while preserving order between equal elements.
    std::stable_sort(std::begin(v), std::end(v),
                     [](const auto& e1, const auto& e2) { return e1.getSalary() < e2.getSalary(); });
    EXPECT_EQ((std::begin(v) + 2)->getSortingName(), "Ronald.Barr");
}

// == Shuffle elements (randomly re-orders elements in a range)
// == Partial sorting

static void
benchmark_shuffle_numbers(benchmark::State& state)
{
    std::vector<int> v = sortData;

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());

    // First do some benchmarks. Change value to see how time changes.
    for (auto _ : state)
    {
        std::shuffle(std::begin(v), std::end(v), generator);
    }

    // To print uncomment here.
    // std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << "\n";

    // Second parameters use "find" to indicate where sorting ends.
    std::partial_sort(std::begin(v), std::find(std::begin(v), std::end(v), 4), std::end(v));

    // To print uncomment here.
    // std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << "\n";

    int breakpoint = *std::is_sorted_until(std::begin(v), std::end(v));
    (void)breakpoint;
    // std::cout << breakpoint << "\n";

    // Sort and copy only first few elements. This gives you top n elements which are sorted.
    // You can use it for example if you want only top few elements.
    std::vector<int> v2(10);
    std::partial_sort_copy(std::begin(v), std::end(v), std::begin(v2), std::end(v2));
    EXPECT_EQ(*std::begin(v2), -49);
    EXPECT_LT(v2.size(), v.size());

    // To print uncomment here.
    // std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << "\n";
}

// == Nth Element

// Partially sorts the given range making sure that it is partitioned by the given element
// You can find all values better then median and sort them or copy.
static void
benchmark_nth_element(benchmark::State& state)
{
    // First do some benchmarks. Change value to see how time changes.
    for (auto _ : state)
    {
        std::vector<int> v = sortData;
        auto m = v.begin() + v.size() / 2;
        EXPECT_EQ(v[v.size() / 2], -40);
        std::nth_element(v.begin(), m, v.end());
        benchmark::DoNotOptimize(v);
    }
}

// == Comparing and Accumulating (equal(), mismatch()) ==

static std::vector<int> compareDataA = {
    // clang-format off
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 1, 2, 3, 4, 5, 6, 7, 8,
    // clang-format on
};

static std::vector<int> compareDataB = {
    // clang-format off
    -40, -410, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 1, 2, 3, 4, 5, 6, 7, 8,
    // clang-format on
};

static void
benchmark_comparing_elements(benchmark::State& state)
{
    std::vector<int> vA = compareDataA;
    std::vector<int> vB = compareDataB;

    // First do some benchmarks. Change value to see how time changes.
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::equal(std::begin(vA), std::end(vA), std::begin(vB), std::end(vB)));
    }

    bool same = std::equal(std::begin(vA), std::end(vA), std::begin(vB), std::end(vB));
    EXPECT_FALSE(same);

    auto firstChange = std::mismatch(std::begin(vA), std::end(vA), std::begin(vB));
    EXPECT_EQ(*firstChange.first, -41);
    EXPECT_EQ(*firstChange.second, -410);

    auto distance = firstChange.first - std::begin(vA);
    EXPECT_EQ(distance, 1);
}

static std::vector<int> accumulateData = {
    // clang-format off
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 1, 2, 3, 4, 5, 6, 7, 8,
    // clang-format on
};

// = Total the elements (accumulate())

static void
benchmark_total_elements(benchmark::State& state)
{
    std::vector<int> v = accumulateData;

    // First do some benchmarks. Change value to see how time changes.
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(std::accumulate(std::begin(v), std::end(v), 0));
    }

    auto sum = std::accumulate(std::begin(v), std::end(v), 0);
    EXPECT_EQ(sum, 181);

    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    EXPECT_EQ(product, 1921056768);

    product = std::accumulate(v.begin(), v.end(), 1, [](int total, int i) { return total * i; });
    EXPECT_EQ(product, 1921056768);

    std::vector<std::string> words{ "one", "two", "three" };
    std::string allWords = std::accumulate(words.begin(), words.end(), std::string{});
    EXPECT_EQ(allWords.size(), 11);
}

static void
benchmark_for_each_iterators(benchmark::State& /* state */)
{
    std::vector<int> v = accumulateData;

    // First do some benchmarks. Change value to see how time changes.

    for (auto it = std::begin(v); it != std::end(v); it++)
    {
        *it = 0;
    }

    EXPECT_EQ(*std::begin(v), 0);

    // Probably best option iterate over entire collection.
    for (auto& i : v)
    {
        i = 1;
    }

    EXPECT_EQ(*std::begin(v), 1);

    // Very usefull if you do not want to iterate over entire collection.
    v = accumulateData;
    auto startIt = std::find(v.begin(), v.end(), 18);
    std::for_each(startIt, v.end(), [](int& element) { element = 2; });

    EXPECT_EQ(*std::begin(v), 10);
    EXPECT_EQ(*(std::end(v) - 1), 2);
}

// == Generating and Manipulating Collections ==

static std::vector<int> copyData = {
    // clang-format off
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8,
    // clang-format on
};

// == Copying (copy(), copy_if(), copy_n(), copy_backward())

static void
benchmark_copy_elements(benchmark::State& state)
{
    std::vector<int> v = copyData;

    // First do some benchmarks. Change value to see how time changes.
    for (auto _ : state)
    {
        std::vector<int> v2(v.size());
        benchmark::DoNotOptimize(std::copy(std::begin(v), std::end(v), std::begin(v2)));
        EXPECT_EQ(*std::begin(v), *std::begin(v2));
        // It is basically teh same as std::vector<int> v2 = v;
    }

    // Find element and copy until you reach the end iterator.
    std::vector<int> v3(v.size());
    auto position = std::find(std::begin(v), std::end(v), 27);
    std::copy(std::begin(v), position, std::begin(v3));
    EXPECT_EQ(*std::begin(v), *std::begin(v3));
    EXPECT_EQ(*(position - 1), 26);
    EXPECT_EQ(*(position), 27);
    EXPECT_EQ(*(std::begin(v3) + (position - std::begin(v))), 0);
    EXPECT_EQ(*(std::begin(v3) + (position - std::begin(v) - 1)), 26);

    // COpy only elements which fit requirement.
    std::vector<int> v4(v.size());
    std::copy_if(std::begin(v), std::end(v), std::begin(v4), [](int element) { return element % 2 == 0; });
    EXPECT_EQ(*std::begin(v), *std::begin(v4));
    EXPECT_NE(*(std::begin(v) + 1), *(std::begin(v4) + 1));

    // Copy with the same collection. Works well if there is no overlap.
    position = std::find(std::begin(v4), std::end(v4), 26);
    std::copy(std::begin(v4), position + 1, position + 1);
    EXPECT_EQ(*(std::begin(v4) + (position - std::begin(v4) + 1)), -40);
    EXPECT_EQ(*(position), 26);

    // Use copy_backward to cope back previoues elements. Order is not changed.
    // To avoid collisions if source and destination is the same memory.
    std::copy_backward(std::begin(v), std::end(v), std::end(v4));
    bool same = std::equal(std::begin(v), std::end(v), std::begin(v4), std::end(v4));
    EXPECT_TRUE(same);
}

// = Noncopyable types. You can use move();
// Move invalidate original elements. But we know that :).

// = Remove elements (remove(), remove_if(), erase())
static std::vector<int> removeData = {
    // clang-format off
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    // clang-format on
};

static void
benchmark_remove_elements(benchmark::State& state)
{
    std::vector<int> v = removeData;

    for (auto _ : state)
    {
        std::vector<int> v2 = copyData;
        benchmark::DoNotOptimize(std::remove(std::begin(v), std::end(v), -40));
        EXPECT_EQ(v2.size(), copyData.size());
    }

    // Remove elements with specific value.
    auto newEndIter = std::remove(std::begin(v), std::end(v), 30);
    int logicalSize = newEndIter - v.begin();
    EXPECT_EQ(v.size(), removeData.size());
    EXPECT_EQ(logicalSize, v.size() - 1);

    // Erase from new end to the end of source.
    v.erase(newEndIter, std::end(v));
    EXPECT_EQ(v.size() + 1, removeData.size());
    EXPECT_EQ(*std::begin(v), *(std::begin(removeData) + 1));

    // Remove all odd numbers and erase rest of the array
    // If you have more complex data type, erase will destruct old objects.
    v = removeData;
    newEndIter = std::remove_if(std::begin(v), std::end(v), [](int val) { return val % 2 != 0; });
    v.erase(newEndIter, std::end(v));
    EXPECT_EQ(v.size(), removeData.size() / 2);
}

// = Creating and Filling Collections (fill(), fill_n(), iota(), generate(), generate_n())

static void
benchmark_create_fill_collections(benchmark::State& /* state */)
{
    std::vector<int> v(400);

    // Fill vector with 1
    std::fill(std::begin(v), std::end(v), 1);
    EXPECT_EQ(*std::begin(v), 1);

    // Fill first 200 elements with 2
    std::fill_n(std::begin(v), 200, 2);
    EXPECT_EQ(*(std::begin(v) + 199), 2);
    EXPECT_EQ(*(std::begin(v) + 200), 1);

    // Fill incremented value
    std::iota(std::begin(v), std::end(v), 1);
    EXPECT_EQ(*std::begin(v), 1);
    EXPECT_EQ(*(std::end(v) - 1), 400);

    // Generate custom vlaues
    int index = 200;
    std::generate(std::begin(v), std::end(v), [&index]() { return index--; });
    EXPECT_EQ(*std::begin(v), 200);
    EXPECT_EQ(*(std::end(v) - 1), -199);

    std::vector<int> v2(400);
    index = 1;
    std::generate_n(std::begin(v2), 10, [&index]() { return index *= 2; });
    EXPECT_EQ(*std::begin(v2), std::pow(2, 1));
    EXPECT_EQ(*(std::begin(v2) + 9), std::pow(2, 10));
    EXPECT_EQ(*(std::begin(v2) + 10), 0);
}

// = Replace, Transform values (replace(), replace_if())

static std::vector<int> transformData = {
    // clang-format off
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    // clang-format on
};

static void
benchmark_replace_tranform_values(benchmark::State& /* state */)
{
    std::vector<int> v = copyData;

    // Replace all values 30 with 0
    std::replace(std::begin(v), std::end(v), 30, 0);
    auto result = std::find(v.begin(), v.end(), 30);
    EXPECT_EQ(result, v.end());

    // Repplace all values lower then 20
    std::replace_if(v.begin(), v.end(),
                    std::bind(std::less<int>(), std::placeholders::_1, 20), 20);
    result = std::find_if(v.begin(), v.end(), [](auto i) { return i < 20; });
    EXPECT_EQ(result, v.end());

    // Repplace all values lower then 30 with lambda
    std::replace_if(
        v.begin(), v.end(), [](int i) { return i < 30; }, 30);
    result = std::find_if(v.begin(), v.end(), [](auto i) { return i < 30; });
    EXPECT_EQ(result, v.end());

    // Transform values (replace(), replace_if()), do something to every element in a range
    // Put the result back into the same collection or into a diffrent one.

    v = transformData;
    std::vector<int> v2(v.size());
    std::transform(v.begin(), v.end(), v2.begin(), [](int i) { return i * 2; });
    EXPECT_EQ(*v.begin() * 2, *v2.begin());

    // Two starting points will be sent to lambda. Result is going to be put into each element of v2.
    std::transform(v.begin(), v.end() - 1, v.begin() + 1, v2.begin(), [](int i1, int i2) { return i1 + i2; });
    EXPECT_EQ(*v.begin() + *(v.begin() + 1), *v2.begin());

    // To print shuffled array.
    // std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << "\n";
}

// = Elimenate Duplicates (unique())
// Removes consecutive duplicate elements in a range

static std::vector<int> duplicatesData = {
    // clang-format off
    30, 30, 32, 33, 33, 35, 36, 36, 38, 38, 20, 20, 22, 22, 24, 24, 26, 27, 28, 29, 10, 11, 12, 12, 12, 15, 16, 17, 17, 17, 0, 1, 2, 3, 3, 3, 3, 7, 8, 9
    // clang-format on
};

static void
benchmark_eliminate_duplicates(benchmark::State& state)
{
    // Benchmark
    for (auto _ : state)
    {
        std::vector<int> v2 = copyData;

        // First sort data to put consecutive together.
        std::sort(std::begin(v2), std::end(v2));

        // Remove consecutive (adjacent) duplicates.
        auto last = std::unique(v2.begin(), v2.end());
        benchmark::DoNotOptimize(last);
        benchmark::DoNotOptimize(v2.erase(last, v2.end()));
    }

    std::vector<int> v = copyData;

    // First sort data to put consecutive together.
    std::sort(std::begin(v), std::end(v));

    // Remove consecutive (adjacent) duplicates.
    auto last = std::unique(v.begin(), v.end());
    EXPECT_NE(last, v.end());
    v.erase(last, v.end());

    // Check there are no consecutive numbers.
    last = std::adjacent_find(v.begin(), v.end());
    EXPECT_EQ(last, v.end());

    // To print uncomment here.
    // std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << "\n";
}

// = Reserving and Swapping (reverse(), iter_swap(), revers_copy())

static const std::string sentence = "Hello, world.";

static void
benchmark_reverse_elements(benchmark::State& /* state */)
{
    std::string s = sentence;

    // Reverse the string. Easy !!!
    std::reverse(std::begin(s), std::end(s));
    EXPECT_EQ(s, ".dlrow ,olleH");

    std::iter_swap(std::begin(s), std::end(s) - 1);
    EXPECT_EQ(s, "Hdlrow ,olle.");

    std::string s2;
    s2.resize(s.size());
    std::reverse_copy(std::begin(s), std::end(s), std::begin(s2));
    std::iter_swap(std::begin(s2), std::end(s2) - 1);
    EXPECT_EQ(s2, sentence);
}

// == Using The Power of Iterators ==
// Inserting iterators (back_inserter, front_inserter)

static void
benchmark_insert_elements(benchmark::State& /* state */)
{
    // We have empty vector now.
    std::vector<int> v;

    // Fill first 200 elements with 2
    std::fill_n(std::back_inserter(v), 200, 2);
    EXPECT_EQ(*(std::begin(v)), 2);
    EXPECT_EQ(*(std::begin(v) + 199), 2);
    EXPECT_EQ(v.size(), 200);

    v.clear();
    std::generate_n(std::back_inserter(v), 200, [index = 0]() mutable { return index++; });
    EXPECT_EQ(*(std::begin(v)), 0);
    EXPECT_EQ(*(std::begin(v) + 199), 199);
    EXPECT_EQ(v.size(), 200);

    std::vector<int> v2;
    std::transform(v.begin(), v.end(), std::back_inserter(v2), [](int i) { return i * 2; });
    EXPECT_EQ(*v.begin() * 2, *v2.begin());
    EXPECT_EQ(*(v.begin()++) * 2, *(v2.begin()++));
    EXPECT_EQ(*(v.begin() + 5) * 2, *(v2.begin() + 5));
    EXPECT_EQ(v.size(), v2.size());

    // Is a number in first half?
    auto result = std::find(v.begin(), v.end(), 5);
    EXPECT_NE(result, v.end());
    if (result != v.end())
    {
        // Distance from the begin should be shorter.
        EXPECT_LT(result - std::begin(v), std::end(v) - result);
    }

    // Reverse copy to a new string without preallocating.
    std::string s = sentence;
    std::string s2;
    std::reverse_copy(std::begin(s), std::end(s), std::back_inserter(s2));
    EXPECT_EQ(s2, ".dlrow ,olleH");
}

// == Unexpectedly Useful Operations ==
// = Rotate elements. You can take an element and move to to another row.

static const std::vector<int> rotateData = {
    // clang-format off
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    // clang-format on
};

static void
benchmark_rotate_elements(benchmark::State& /* state */)
{
    std::vector<int> v = rotateData;

    // Find elements and move it on a diffrent position.
    // The beginning of the original range;
    auto elIt1 = std::find(v.begin(), v.end(), 2);
    // The element that should appear at the beginning of the rotated range
    auto elIt2 = std::find(v.begin(), v.end(), 6);
    EXPECT_NE(elIt1, v.end());
    EXPECT_NE(elIt2, v.end());

    // Rotate with the end of the original range in elIt2 + 1.
    // TODO learn here more.
    std::rotate(elIt1, elIt2, elIt2 + 1);
    EXPECT_EQ(v[2], 6);
    EXPECT_EQ(v[3], 2);

    // TODO std::stable_partition
    // TODO https://www.youtube.com/watch?v=W2tWOdzgXHA

    // To print uncomment here.
    // std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << "\n";
}

static constexpr int iterations = 100000;

BENCHMARK(benchmark_count_with_for)->Iterations(iterations);
BENCHMARK(benchmark_count_with_std)->Iterations(iterations);

BENCHMARK(benchmark_odd_for)->Iterations(iterations);
BENCHMARK(benchmark_odd_std_member)->Iterations(iterations);

BENCHMARK(benchmark_find_number)->Iterations(iterations);
BENCHMARK(benchmark_find_string)->Iterations(iterations);

BENCHMARK(benchmark_sort_numbers)->Iterations(iterations);
BENCHMARK(benchmark_sort_employees)->Iterations(iterations);

BENCHMARK(benchmark_shuffle_numbers)->Iterations(iterations);
BENCHMARK(benchmark_nth_element)->Iterations(iterations);

BENCHMARK(benchmark_comparing_elements)->Iterations(iterations);
BENCHMARK(benchmark_total_elements)->Iterations(iterations);
BENCHMARK(benchmark_for_each_iterators)->Iterations(iterations);

BENCHMARK(benchmark_copy_elements)->Iterations(iterations);
BENCHMARK(benchmark_remove_elements)->Iterations(iterations);

BENCHMARK(benchmark_create_fill_collections)->Iterations(iterations);
BENCHMARK(benchmark_replace_tranform_values)->Iterations(iterations);
BENCHMARK(benchmark_eliminate_duplicates)->Iterations(iterations);
BENCHMARK(benchmark_reverse_elements)->Iterations(iterations);

BENCHMARK(benchmark_insert_elements)->Iterations(iterations);
BENCHMARK(benchmark_rotate_elements)->Iterations(iterations);

BENCHMARK_MAIN();
