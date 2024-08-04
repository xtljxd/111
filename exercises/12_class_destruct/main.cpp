#include "../exercise.h"
#include <iostream>

class DynFibonacci {
    size_t *cache;
    int cached;
    int capacity;

public:
    // 实现动态设置容量的构造器
    DynFibonacci(int capacity) : cache(new size_t[capacity]), cached(2), capacity(capacity) {
        cache[0] = 0;
        cache[1] = 1;
        // 初始化缓存的前两个斐波那契数
        for (int i = 2; i < capacity; ++i) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
    }

    // 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        if (i < cached) {
            return cache[i];
        }
        for (; cached <= i && cached < capacity; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
