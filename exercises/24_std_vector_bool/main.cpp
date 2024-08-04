#include "../exercise.h"
#include <vector>

int main(int argc, char **argv) {
    std::vector<bool> vec(100, true); 
    ASSERT(vec[0], "Make this assertion pass.");
    ASSERT(vec[99], "Make this assertion pass.");
    ASSERT(vec.size() == 100, "Make this assertion pass.");

    // NOTICE: 平台相关！注意 CI:Ubuntu 上的值。
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;
    ASSERT(sizeof(vec) == 32, "Fill in the correct value."); // 确认sizeof(std::vector<bool>)为32

    {
        vec[20] = false;
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`.");
    }

    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value.");
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`.");
    }

    {
        vec[30] = false; 
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`.");
    }

    return 0;
}
