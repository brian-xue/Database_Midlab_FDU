#pragma once
#ifndef TEST_LEGAL_
#define TEST_LEGAL_



#include <string>
#include <regex>
#include <algorithm>

inline bool isValidInput(const std::string& input) {
    // ����Ƿ����������SQL�ؼ���
    std::string lowerInput = input;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
    if (lowerInput.find(" drop ") != std::string::npos ||
        lowerInput.find(" delete ") != std::string::npos ||
        lowerInput.find(" insert ") != std::string::npos ||
        lowerInput.find(" -- ") != std::string::npos) {
        return false;
    }

    // ������ʽģʽ��ֻ���������ĸ�����֡��»��ߺ����ۺ�
    std::regex pattern("^[a-zA-Z0-9_\\- ]+$");
    return std::regex_match(input, pattern);
}

#endif