#pragma once
//#include<Windows.h>
#include<iostream>
#include<sstream>
#include<string>
#include<charconv>
#include <array>
#include<map>
#include<unordered_map>

template<class Key, class Val,class Map = std::map<Key,Val> >
std::string formatMap(const Map& map);

template<class T>
std::string format(const T& dat);

template<>
std::string format(const std::string& string);

template<>
std::string format(const char& c);

template<class Key, class Val, class Is = std::istream, class Map = std::map<Key, Val> >
Is& deFormatMap(Is& is, Map& map);

template<class T,class Is = std::istream>
Is & deFormat(Is & is, T& t);

template<class Is = std::istream>
Is & deFormat(Is & is, char& c);

//template<class Key,class Val,class Is = std::istream>
//Is& deFormat(Is& is, std::map<Key, Val>& map);

template<class Is = std::istream>
Is & deFormat(Is & is, std::string& str);
