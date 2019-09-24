#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
#include<charconv>
#include <array>
#include<map>
#include<unordered_map>

template<class T_1 ,class T_2>
std::string format(std::map<T_1, T_2> map);

template<class T>
std::string format(T dat);

template<>
std::string format(std::string string);


