#include "../exercise.h"
#include <iostream>
#include <utility>

// DynFibonacci 类
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
    DynFibonacci& operator=(DynFibonacci const &) = delete;

    // 实现移动构造器
    DynFibonacci(DynFibonacci &&other) noexcept : cache(other.cache), cached(other.cached), capacity(other.capacity) {
        other.cache = nullptr;
        other.cached = 0;
        other.capacity = 0;
    }

    // 实现移动赋值运算符
    DynFibonacci& operator=(DynFibonacci &&other) noexcept {
        if (this != &other) { // 避免自移动赋值
            delete[] cache;

            cache = other.cache;
            cached = other.cached;
            capacity = other.capacity;

            other.cache = nullptr;
            other.cached = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 实现正确的缓存优化斐波那契计算
    size_t operator[](int i) {
        if (i >= capacity) {
            ASSERT(false, "Index out of bounds");
        }
        if (i >= cached) {
            for (; cached <= i; ++cached) {
                cache[cached] = cache[cached - 1] + cache[cached - 2];
            }
        }
        return cache[i];
    }

    // const 修饰的重载方法
    size_t operator[](int i) const {
        ASSERT(i < cached, "Index out of bounds");
        return cache[i];
    }

    // 检查对象是否还活着
    bool is_alive() const {
        return cache != nullptr;
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci const fib_ = std::move(fib);
    ASSERT(!fib.is_alive(), "Object moved");
    ASSERT(fib_[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci fib0(6);
    DynFibonacci fib1(12);

    fib0 = std::move(fib1);
    fib0 = std::move(fib0);
    ASSERT(fib0[10] == 55, "fibonacci(10) should be 55");

    return 0;
}
