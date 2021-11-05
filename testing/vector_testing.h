#ifndef MYSTL_VECTOR_TESTING_H
#define MYSTL_VECTOR_TESTING_H

#include <assert.h>
#include <chrono>
#include <random>
#include <vector>
#include "../vector.h"

void TestVector() {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 rnd(seed);
//    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

    /* checking sizes and capacities while doing push_back
     * checking sizes and capacities while doing pop_back
     * */
    {
        std::vector<int32_t> v1;
        MySTD::vector<int32_t> v2;
        size_t n = rnd() % 1000;

        for (size_t i = 0; i < n; ++i) {
            assert(v1.size() == v2.size());
            assert(v1.capacity() == v2.capacity());

            int32_t element_to_add = rnd();
            v1.push_back(element_to_add);
            v2.push_back(element_to_add);
        }
        assert(v1.size() == v2.size());
        assert(v1.capacity() == v2.capacity());

        for (size_t i = 0; i < n; ++i) {
            v1.pop_back();
            v2.pop_back();

            assert(v1.size() == v2.size());
            assert(v1.capacity() == v2.capacity());
        }
    }

};

#endif //MYSTL_VECTOR_TESTING_H
