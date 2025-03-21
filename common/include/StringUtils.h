#pragma once

#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <cstdarg>

namespace StringUtils {

// Trims leading and trailing whitespace
inline void trim(std::string& str) {
    const auto start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) {
        str.clear();
        return;
    }
    const auto end = str.find_last_not_of(" \t\n\r");
    str = str.substr(start, end - start + 1);
}

// Converts the string to lowercase
inline void toLower(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
}

// Remove the last character of the string (if exists)
inline void removeLastChar(std::string& str) {
    if (!str.empty()) {
        str.pop_back();
    }
}

// Compares two strings case-sensitively
inline int compare(const std::string& str1, const std::string& str2) {
    return str1.compare(str2);
}

// Compares two strings case-insensitively
inline int compareNoCase(const std::string& str1, const std::string& str2) {
    std::string lowerStr1 = str1;
    std::string lowerStr2 = str2;
    toLower(lowerStr1);
    toLower(lowerStr2);
    return lowerStr1.compare(lowerStr2);
}

// Checks if the string starts with the given substring
inline bool startsWith(const std::string& str, const std::string& prefix) {
    return str.substr(0, prefix.size()) == prefix;
}

// Checks if the string starts with the given substring (case insensitive)
inline bool startsWithNoCase(const std::string& str, const std::string& prefix) {
    std::string lowerStr = str;
    std::string lowerPrefix = prefix;
    toLower(lowerStr);
    toLower(lowerPrefix);
    return lowerStr.substr(0, lowerPrefix.size()) == lowerPrefix;
}

// Checks if the string ends with the given substring
inline bool endsWith(const std::string& str, const std::string& suffix) {
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

// Checks if the string ends with the given substring (case insensitive)
inline bool endsWithNoCase(const std::string& str, const std::string& suffix) {
    std::string lowerStr = str;
    std::string lowerSuffix = suffix;
    toLower(lowerStr);
    toLower(lowerSuffix);
    return lowerStr.size() >= lowerSuffix.size() &&
           lowerStr.compare(lowerStr.size() - lowerSuffix.size(), lowerSuffix.size(), lowerSuffix) == 0;
}

// Finds the first occurrence of a character in the string
inline const char* find(const std::string& str, char c) {
    return std::find(str.begin(), str.end(), c) != str.end() ? &str[0] : nullptr;
}

// Finds the last occurrence of a character in the string
inline const char* reverseFind(const std::string& str, char ch) {
    size_t pos = str.rfind(ch);
    if (pos != std::string::npos) {
        return &str[pos];
    }
    return nullptr;
}

// Formats a string with a format string and additional arguments (like printf)
inline std::string format(const char* format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[2048];
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    return std::string(buffer);
}

// Returns true if the string is "NONE" (case insensitive)
inline bool isNone(const std::string& str) {
    return compareNoCase(str, "NONE") == 0;
}

// Extracts the next token from the string, delimited by the given separators
inline bool nextToken(std::string& str, std::string& token, const char* seps = " \t\n\r") {
    size_t start = str.find_first_not_of(seps);
    if (start == std::string::npos) return false;

    size_t end = str.find_first_of(seps, start);
    token = str.substr(start, end - start);
    str = (end == std::string::npos) ? "" : str.substr(end);
    return true;
}

} // namespace StringUtils