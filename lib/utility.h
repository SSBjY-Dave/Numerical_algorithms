//
// Created by ssbjy-dave on 2019.07.06..
//

#pragma once
#include <string>
#include <codecvt>
#include <locale>

namespace utility {
    extern std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> utf8_utf16_converter;
}