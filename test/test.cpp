#include "../include/GTestLite.h"
#include <stdexcept>
#include <vector>

// ===== RELATIONAL OPERATORS TESTS =====
TEST(RelationalTest, EqualityOperators) {
    EXPECT_EQ(5, 5);
    ASSERT_EQ(10, 10);
    EXPECT_NE(3, 4);
    ASSERT_NE(7, 8);
}

TEST(RelationalTest, LessThanOperators) {
    EXPECT_LT(1, 10);
    ASSERT_LT(5, 20);
    EXPECT_LE(5, 5);
    ASSERT_LE(3, 5);
}

TEST(RelationalTest, GreaterThanOperators) {
    EXPECT_GT(10, 1);
    ASSERT_GT(20, 5);
    EXPECT_GE(5, 5);
    ASSERT_GE(5, 3);
}

// ===== BOOLEAN ASSERTIONS TESTS =====
TEST(BooleanTest, ExpectTrue) {
    EXPECT_TRUE(true);
    EXPECT_TRUE(1 > 0);
    EXPECT_TRUE(!false);
}

TEST(BooleanTest, AssertTrue) {
    ASSERT_TRUE(true);
    ASSERT_TRUE(10 == 10);
}

TEST(BooleanTest, ExpectFalse) {
    EXPECT_FALSE(false);
    EXPECT_FALSE(1 < 0);
    EXPECT_FALSE(!true);
}

TEST(BooleanTest, AssertFalse) {
    ASSERT_FALSE(false);
    ASSERT_FALSE(10 == 5);
}

// ===== STRING ASSERTIONS TESTS =====
TEST(StringTest, StringEquality) {
    EXPECT_STREQ("hello", "hello");
    ASSERT_STREQ("world", "world");
    
    const char* str1 = "test";
    const char* str2 = "test";
    EXPECT_STREQ(str1, str2);
}

TEST(StringTest, StringCaseInsensitive) {
    EXPECT_STRCASEEQ("HELLO", "hello");
    ASSERT_STRCASEEQ("WORLD", "world");
    EXPECT_STRCASEEQ("TeSt", "tEsT");
}

TEST(StringTest, NullptrHandling) {
    EXPECT_STREQ(nullptr, nullptr);
    ASSERT_STREQ("", "");
}

// ===== EXCEPTION ASSERTIONS TESTS =====
TEST(ExceptionTest, ExpectThrow) {
    EXPECT_THROW(throw std::runtime_error("test error"), std::runtime_error);
    EXPECT_THROW(throw std::logic_error("logic"), std::logic_error);
    EXPECT_THROW(throw std::invalid_argument("invalid"), std::invalid_argument);
}

TEST(ExceptionTest, AssertThrow) {
    ASSERT_THROW(throw std::runtime_error("error"), std::runtime_error);
    ASSERT_THROW(throw std::out_of_range("range"), std::out_of_range);
}

TEST(ExceptionTest, ExpectNoThrow) {
    EXPECT_NO_THROW(int x = 1 + 1);
    EXPECT_NO_THROW(std::string s = "test");
    EXPECT_NO_THROW({ int a = 5; int b = a; });
}

TEST(ExceptionTest, AssertNoThrow) {
    ASSERT_NO_THROW(int y = 2 * 3);
    ASSERT_NO_THROW(double d = 3.14);
}

// ===== FLOATING POINT ASSERTIONS TESTS =====
TEST(FloatingPointTest, Near) {
    EXPECT_NEAR(1.0, 1.0001, 0.001);
    ASSERT_NEAR(3.14, 3.14159, 0.01);
    EXPECT_NEAR(0.0, 0.00001, 0.0001);
}

TEST(FloatingPointTest, DoubleEqual) {
    EXPECT_DOUBLE_EQ(1.0, 1.0);
    ASSERT_DOUBLE_EQ(3.14159, 3.14159);
    EXPECT_DOUBLE_EQ(2.71828, 2.71828);
}

// ===== NEGATIVE TESTS (Expected to Fail) =====
TEST(NegativeTest, FailureWithExpect) {
    EXPECT_EQ(1, 2);
    EXPECT_NE(5, 5);
    EXPECT_LT(10, 1);
    EXPECT_GT(1, 10);
    EXPECT_LE(10, 5);
    EXPECT_GE(3, 5);
}

TEST(NegativeTest, BooleanNegative) {
    EXPECT_TRUE(false);
    EXPECT_FALSE(true);
}

TEST(NegativeTest, StringNegative) {
    EXPECT_STREQ("hello", "world");
    EXPECT_STRCASEEQ("HELLO", "WORLD");
}

TEST(NegativeTest, NumericNegative) {
    EXPECT_NEAR(1.0, 2.0, 0.1);
    EXPECT_DOUBLE_EQ(1.0, 1.1);
}

TEST(NegativeTest, ExceptionNegative) {
    EXPECT_THROW(int x = 1, std::runtime_error);
    EXPECT_NO_THROW(throw std::runtime_error("error"));
}

// ===== EXPECT CONTINUES AFTER FAILURE TESTS =====
TEST(ErrorHandlingTest, ExpectContinuesOnFailure) {
    EXPECT_EQ(1, 2);
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(false);
    EXPECT_TRUE(true);
}

// ===== COMPREHENSIVE COVERAGE TEST =====
TEST(ComprehensiveTest, AllFeatures) {
    // Relational operators
    EXPECT_EQ(5, 5);
    EXPECT_NE(3, 4);
    EXPECT_LT(1, 10);
    EXPECT_GT(10, 1);
    EXPECT_LE(5, 5);
    EXPECT_GE(5, 5);
    
    // Booleans
    EXPECT_TRUE(true);
    EXPECT_FALSE(false);
    
    // Strings
    EXPECT_STREQ("test", "test");
    EXPECT_STRCASEEQ("TEST", "test");
    
    // Numbers
    EXPECT_NEAR(1.0, 1.001, 0.01);
    EXPECT_DOUBLE_EQ(2.0, 2.0);
    
    // Exceptions
    EXPECT_THROW(throw std::runtime_error("e"), std::runtime_error);
    EXPECT_NO_THROW(int x = 1);
}

// ===== FIXTURE-BASED TESTS =====
class MathFixture : public GTestLite::Test {
public:
    void SetUp() override {
        a = 10;
        b = 5;
    }
    void TearDown() override {
        // Cleanup if needed
    }
protected:
    int a, b;
};

TEST_F(MathFixture, Addition) {
    EXPECT_EQ(a + b, 15);
    ASSERT_EQ(a + b, 15);
}

TEST_F(MathFixture, Subtraction) {
    EXPECT_EQ(a - b, 5);
    ASSERT_EQ(a - b, 5);
}

TEST_F(MathFixture, Multiplication) {
    EXPECT_EQ(a * b, 50);
    ASSERT_EQ(a * b, 50);
}

TEST_F(MathFixture, Division) {
    EXPECT_EQ(a / b, 2);
    ASSERT_EQ(a / b, 2);
}

// ===== STRESS TEST (for repeat functionality) =====
TEST(StressTest, RepeatableTest) {
    EXPECT_EQ(42, 42);
}

TEST(StressTest, ConsistentBehavior) {
    int x = 100;
    EXPECT_GT(x, 50);
    EXPECT_LT(x, 150);
}

int main(int argc, char** argv)
{
    return RUN_ALL_TESTS(argc, argv);
}