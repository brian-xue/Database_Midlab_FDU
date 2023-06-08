#pragma once
#ifndef TEST_LEGAL_
#define TEST_LEGAL_



#include <string>
#include <regex>
#include <algorithm>

inline bool isValidInput(const std::string& input) {
    // 检查是否包含单独的SQL关键字
    std::string lowerInput = input;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
    if (lowerInput.find(" drop ") != std::string::npos ||
        lowerInput.find(" delete ") != std::string::npos ||
        lowerInput.find(" insert ") != std::string::npos ||
        lowerInput.find(" -- ") != std::string::npos) {
        return false;
    }

    // 正则表达式模式，只允许包含字母、数字、下划线和破折号
    std::regex pattern("^[a-zA-Z0-9_\\- ]+$");
    return std::regex_match(input, pattern);
}

#endif