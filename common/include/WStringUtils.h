#pragma once

#include <algorithm>
#include <cstdarg>
#include <cwchar>
#include <string>

namespace WStringUtils {

// Trim whitespace from both ends
inline void trim(std::wstring &str) {
  auto start = std::find_if_not(str.begin(), str.end(), ::iswspace);
  auto end = std::find_if_not(str.rbegin(), str.rend(), ::iswspace).base();
  str = (start < end) ? std::wstring(start, end) : L"";
}

// Remove the last character
inline void removeLastChar(std::wstring &str) {
  if (!str.empty()) {
    str.pop_back();
  }
}

// Format the string with the given arguments
inline std::wstring format(const wchar_t *format, ...) {
  va_list args;
  va_start(args, format);
  wchar_t buffer[2048];
  vswprintf(buffer, sizeof(buffer) / sizeof(wchar_t), format, args);

  va_end(args);
  return std::wstring(buffer);
}

// Compare two wide strings (case-sensitive)
inline int compare(const std::wstring &str1, const std::wstring &str2) {
    return wcscmp(str1.c_str(), str2.c_str());
}

// Compare two wide strings (case-insensitive)
inline int compareNoCase(const std::wstring &str1, const std::wstring &str2) {
  auto it1 = str1.begin();
  auto it2 = str2.begin();

  // Compare character by character, ignoring case
  while (it1 != str1.end() && it2 != str2.end()) {
    wchar_t c1 = towupper(*it1);
    wchar_t c2 = towupper(*it2);

    // If characters differ, return the comparison result
    if (c1 != c2) {
      return (c1 < c2) ? -1 : 1;
    }

    ++it1;
    ++it2;
  }

  // If both strings are the same length, they're equal
  // Otherwise, the shorter string is considered "less than" the longer string
  if (it1 == str1.end() && it2 == str2.end()) {
    return 0;
  }
  return (str1.size() < str2.size()) ? -1 : 1;
}
// Tokenize a wide string based on a delimiter
inline bool nextToken(std::wstring &str, std::wstring &token,
                      const std::wstring &delimiters = L" \t\n") {
  auto start = str.find_first_not_of(delimiters);
  if (start == std::wstring::npos)
    return false;

  auto end = str.find_first_of(delimiters, start);
  token = str.substr(start, end - start);
  str.erase(0, end);
  return true;
}

// Concatenate wide strings (appending one to the other)
inline void concat(std::wstring &str1, const std::wstring &str2) {
  str1.append(str2);
}

// Concatenate a wide character to a string
inline void concat(std::wstring &str, wchar_t c) { str.push_back(c); }

// Convert a wide string to uppercase
inline void toUpperCase(std::wstring &str) {
  std::transform(str.begin(), str.end(), str.begin(), ::towupper);
}

// Convert a wide string to lowercase
inline void toLowerCase(std::wstring &str) {
  std::transform(str.begin(), str.end(), str.begin(), ::towlower);
}

} // namespace WStringUtils