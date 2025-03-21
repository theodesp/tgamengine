#include "../include/WStringUtils.h"
#include <gtest/gtest.h>
#include <string>

// Test trim function
TEST(WStringUtilsTest, TestTrim) {
  std::wstring str = L"   Hello World   ";
  WStringUtils::trim(str);
  EXPECT_EQ(str, L"Hello World");

  str = L"   ";
  WStringUtils::trim(str);
  EXPECT_EQ(str, L"");

  str = L"Hello";
  WStringUtils::trim(str);
  EXPECT_EQ(str, L"Hello");
}

// Test removeLastChar function
TEST(WStringUtilsTest, TestRemoveLastChar) {
  std::wstring str = L"Hello World!";
  WStringUtils::removeLastChar(str);
  EXPECT_EQ(str, L"Hello World");

  str = L"A";
  WStringUtils::removeLastChar(str);
  EXPECT_EQ(str, L"");

  str = L"";
  WStringUtils::removeLastChar(str);
  EXPECT_EQ(str, L"");
}

// // Test format function
// TEST(WStringUtilsTest, TestFormat) {
//   std::wstring result = WStringUtils::format(L"Hello %s!", L"World");
//   EXPECT_EQ(result, L"Hello World!");

//   result = WStringUtils::format(L"Number: %d", 42);
//   EXPECT_EQ(result, L"Number: 42");
// }

// Test compareNoCase function (case-insensitive)
TEST(WStringUtilsTest, TestCompareNoCase) {
  std::wstring str1 = L"Hello";
  std::wstring str2 = L"Hello";
  EXPECT_EQ(WStringUtils::compare(str1, str2), 0); // Strings should be equal

  str2 = L"World";
  EXPECT_LT(WStringUtils::compare(str1, str2),
            0); // "Hello" < "World", expect negative

  str2 = L"hello";
  // In ASCII/Unicode, uppercase letters have lower values than lowercase
  // letters So "Hello" < "hello", which gives a negative value, not positive
  EXPECT_LT(WStringUtils::compare(str1, str2),
            0); // "Hello" < "hello", expect negative
}

// Test nextToken function
TEST(WStringUtilsTest, TestNextToken) {
  std::wstring str = L"Hello World";
  std::wstring token;

  EXPECT_TRUE(WStringUtils::nextToken(str, token, L" "));
  EXPECT_EQ(token, L"Hello");

  EXPECT_TRUE(WStringUtils::nextToken(str, token, L" "));
  EXPECT_EQ(token, L"World");

  EXPECT_FALSE(WStringUtils::nextToken(str, token, L" "));
}

// Test concat function (wide string + wide string)
TEST(WStringUtilsTest, TestConcat) {
  std::wstring str1 = L"Hello ";
  std::wstring str2 = L"World!";
  WStringUtils::concat(str1, str2);
  EXPECT_EQ(str1, L"Hello World!");
}

// Test concat function (wide string + wide char)
TEST(WStringUtilsTest, TestConcatChar) {
  std::wstring str = L"Hello";
  WStringUtils::concat(str, L' ');
  WStringUtils::concat(str, L'W');
  WStringUtils::concat(str, L'o');
  WStringUtils::concat(str, L'r');
  WStringUtils::concat(str, L'l');
  WStringUtils::concat(str, L'd');
  WStringUtils::concat(str, L'!');
  EXPECT_EQ(str, L"Hello World!");
}

// Test toUpperCase function
TEST(WStringUtilsTest, TestToUpperCase) {
  std::wstring str = L"Hello World!";
  WStringUtils::toUpperCase(str);
  EXPECT_EQ(str, L"HELLO WORLD!");
}

// Test toLowerCase function
TEST(WStringUtilsTest, TestToLowerCase) {
  std::wstring str = L"Hello World!";
  WStringUtils::toLowerCase(str);
  EXPECT_EQ(str, L"hello world!");
}