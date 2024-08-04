#include "../exercise.h"
#include <iostream>

class Fibonacci {
    size_t cache[16];
    int cached;

public:
    // 实现构造器，初始化 cache 和 cached
    Fibonacci() : cache{0, 1}, cached(2) {
        // 初始化前两个斐波那契数
        for (int i = 2; i < 16; ++i) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
    }

    // 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        if (i < cached) {
            return cache[i];
        }
        for (; cached <= i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
