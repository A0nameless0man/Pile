#pragma once
#include <iostream>
#include <type_traits>
//#define CONCEPT_OK
namespace Reader
{

using stdIstream = std::basic_istream<char, std::char_traits<char>>;
using stdOstream = std::basic_ostream<char, std::char_traits<char>>;

#ifdef CONCEPT_OK
template <
    typename IS,
    typename T>
concept OperatorReadable = requires(T t, IS is)
{

    is >> t;
};
#endif //CONCEPT_OK
template <
    typename IS,
    typename T>
// requires OperatorReadable<IS, T>
class OperatorReader
{
public:
    T read(IS &is) const
#ifdef CONCEPT_OK
        requires OperatorReadable<IS, T>
#endif //conceptOK
    {
        T t;
        is >> t;
        return t;
    }
};

template <
    typename T,
    template <
        typename IS = stdIstream,
        typename ReaderType = T>
    class Reader,
    template <
        typename OS = stdOstream,
        typename PrinterType = T>
    class Printer>
class InteractiveStreamReader
{
public:
    template <class OS, class IS>
    T read(OS &os, IS &is)
    {
        using RealReader = Reader<OS>;
    }
};

} // namespace Reader
