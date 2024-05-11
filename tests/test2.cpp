#include <gtest/gtest.h>
#include <QString>

int add(int a, int b)
{
    return a + b;
}

TEST(MathTest, AddTest)
{
    int result = add(2, 3);
    ASSERT_EQ(result, 5);
}

TEST(StringTest, ToUpperTest)
{
    QString str = "hello world";
    QString result = str.toUpper();
    ASSERT_EQ(result, "HELLO WORLD");
}

TEST(StringTest, ConcatenateTest)
{
    QString str1 = "hello";
    QString str2 = "world";
    QString result = str1 + " " + str2;
    ASSERT_EQ(result, "hello world");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}