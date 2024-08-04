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
    }

    // 禁用复制构造器
    DynFibonacci(DynFibonacci const &) = delete;

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

    // const 修饰的重载方法
    size_t get(int i) const {
        if (i <= cached) {
            return cache[i];
        }
        ASSERT(false, "i out of range");
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    DynFibonacci const &fib_ = fib;  // 引用现有对象而不是复制
    ASSERT(fib_.get(10) == fib.get(10), "Object cloned");
    return 0;
}
