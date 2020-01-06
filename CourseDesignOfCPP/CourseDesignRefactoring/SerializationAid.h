#pragma once
#include "ThirdPartyLib/json.hpp"
#include <iostream>
using stdIstream = std::basic_istream<char, std::char_traits<char> >;
using stdOstream = std::basic_ostream<char, std::char_traits<char> >;
using json       = nlohmann::json;
#define SerializeWithMethod(js, x, y)    js[#x] = x.y
#define SerializeWithBaseClass(js, x, y) js[#x] = x::y
#define Serialize(js, x)                 js[#x] = x
#define UnSerialize(js, x)               x(js[#x])