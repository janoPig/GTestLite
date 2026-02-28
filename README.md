# GTestLite

[![GTestLite CI](https://github.com/janoPig/GTestLite/actions/workflows/tests.yml/badge.svg)](https://github.com/janoPig/GTestLite/actions/workflows/tests.yml)

Lightweight, single-header C++ unit testing framework with GTest-compatible syntax.

## Quick Start

```cpp
#include "include/GTestLite.h"

TEST(MathTest, Addition) {
    EXPECT_EQ(2 + 2, 4);
}

int main(int argc, char** argv) {
    return RUN_ALL_TESTS(argc, argv);
}
```

Build and run:
```bash
g++ -std=c++17 -I. test.cpp -o runner && ./runner
```

## Assertions

| Type | Macros |
| :--- | :--- |
| **Relational** | `EXPECT_EQ`, `ASSERT_EQ`, `EXPECT_NE`, `ASSERT_NE`, `EXPECT_LT`, `ASSERT_LT`, `EXPECT_GT`, `ASSERT_GT`, `EXPECT_LE`, `ASSERT_LE`, `EXPECT_GE`, `ASSERT_GE` |
| **Boolean** | `EXPECT_TRUE`, `ASSERT_TRUE`, `EXPECT_FALSE`, `ASSERT_FALSE` |
| **String** | `EXPECT_STREQ`, `ASSERT_STREQ`, `EXPECT_STRCASEEQ`, `ASSERT_STRCASEEQ` |
| **Floating-point** | `EXPECT_NEAR`, `ASSERT_NEAR`, `EXPECT_DOUBLE_EQ`, `ASSERT_DOUBLE_EQ` |
| **Exception** | `EXPECT_THROW`, `ASSERT_THROW`, `EXPECT_NO_THROW`, `ASSERT_NO_THROW` |

**Key:** `EXPECT_*` continues on failure, `ASSERT_*` stops.

## Test Fixtures

```cpp
class MyFixture : public GTestLite::Test {
public:
    void SetUp() override { /* setup */ }
    void TearDown() override { /* cleanup */ }
protected:
    int value = 0;
};

TEST_F(MyFixture, TestName) {
    EXPECT_EQ(value, 0);
}
```

## Command Line

| Argument | Example |
| :--- | :--- |
| List tests | `./runner --gtest_list_tests` |
| Filter tests | `./runner --gtest_filter=MathTest` |
| Repeat tests | `./runner --gtest_repeat=5` |
| Shuffle tests | `./runner --gtest_shuffle --gtest_random_seed=42` |
| XML output | `./runner --gtest_output=xml:report.xml` |

## Features

- Zero dependencies (single header)
- Cross-platform (Linux/GCC, Windows/MSVC)
- Familiar GTest API
- XML test reports
- Colored output
