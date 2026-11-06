#include <algorithm>
#include <iostream>

int clampExposure(int microseconds)
{
    return std::clamp(microseconds, 1000, 50000);
}

int main()
{
    struct TestCase {
        int input;
        int expected;
    };

    const TestCase cases[] = {
        {500,   1000},   // 低于下限
        {1000,  1000},   // 等于下限
        {20000, 20000},  // 正常范围
        {50000, 50000},  // 等于上限
        {60000, 50000},  // 超过上限
    };

    for (const auto& test : cases) {
        const int actual = clampExposure(test.input);

        if (actual != test.expected) {
            std::cerr << "FAILED: input=" << test.input
                      << ", expected=" << test.expected
                      << ", actual=" << actual << '\n';
            return 1;
        }
    }

    std::cout << "All 5 cases passed\n";
    return 0;
}
