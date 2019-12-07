#pragma once
#include <iostream>
#include <type_traits>
//#define CONCEPT_OK
namespace Reader
{

using stdIstream = std::basic_istream<char, std::char_traits<char>>;
using stdOstream = std::basic_ostream<char, std::char_traits<char>>;

#ifdef CONCEPT_OK
template <typename IS, typename T>
concept OperatorReadable = requires(T t, IS is)
{

    is >> t;
};
#endif //CONCEPT_OK

template <typename T>
// requires OperatorReadable<IS, T>
class OperatorReader
{
public:
    template <typename IS>
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
    template <typename> class Reader>
class InteractiveStreamReader
{
public:
    InteractiveStreamReader(Reader<T> givenReader) : reader(givenReader)
    {
    }
    InteractiveStreamReader() : reader(Reader<T>()){}
    template <
        class OS,
        class IS /*,
        template <
            typename OS = stdOstream,
            typename PrinterType = T>
        class Printer*/
        >
    T read(OS &os, IS &is)
    {
        os << " ";
        return reader.read(is);
    }
    Reader<T> reader;
};

} // namespace Reader
