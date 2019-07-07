#include <codecvt>
#include <locale>
#include "utility.h"

//
// Created by ssbjy-dave on 2019.07.06..
//
namespace utility {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> utf8_utf16_converter;
}
