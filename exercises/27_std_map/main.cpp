﻿#include "../exercise.h"
#include <map>

// 检查键是否存在于 std::map 中
template<class k, class v>
bool key_exists(std::map<k, v> const &map, k const &key) {
    // 使用 find 方法检查键是否存在
    return map.find(key) != map.end();
}

// 设置 std::map 中的键值对
template<class k, class v>
void set(std::map<k, v> &map, k key, v value) {
    // 使用 operator[] 进行赋值
    map[key] = value;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    using namespace std::string_literals;

    std::map<std::string, std::string> secrets;

    set(secrets, "hello"s, "world"s);
    ASSERT(key_exists(secrets, "hello"s), "\"hello\" shoud be in `secrets`");
    ASSERT(!key_exists(secrets, "foo"s), "\"foo\" shoud not be in `secrets`");

    set(secrets, "foo"s, "bar"s);
    set(secrets, "Infini"s, "Tensor"s);
    ASSERT(secrets["hello"] == "world", "hello -> world");
    ASSERT(secrets["foo"] == "bar", "foo -> bar");
    ASSERT(secrets["Infini"] == "Tensor", "Infini -> Tensor");

    set(secrets, "hello"s, "developer"s);
    ASSERT(secrets["hello"] == "developer", "hello -> developer");

    return 0;
}
