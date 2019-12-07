#pragma once
#include <iostream>
#include <type_traits>
#include <functional>
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
    T operator()(IS &is) const
#ifdef CONCEPT_OK
        requires OperatorReadable<IS, T>
#endif //conceptOK
    {
        T t;
        is >> t;
        return t;
    }
    using ReturnType = T;
};


template <typename F,class T>
class MemFnReader
{
public:
    MemFnReader(F f) :fun(f)
    {}
    template <typename IS>
    T operator()(IS &is) const
    {
        T t;
        return fun(t, is);
    }
    using ReturnType = T;
private:
    F fun;
};
template <typename F>
MemFnReader(F)->MemFnReader<F, typename F::result_type>;

template <
    typename T,
    class Reader //,
    //template <typename> class Rrinter
    >
class InteractiveStreamReader
{
public:
    InteractiveStreamReader(Reader givenReader) : reader(givenReader)
    {
    }
    InteractiveStreamReader() : reader(Reader()) {}
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
        return reader(is);
    }
    Reader reader;
    //Printer<T> printer;
};
template <class X>
InteractiveStreamReader(X)->InteractiveStreamReader<typename X::ReturnType, X>;
} // namespace Reader
