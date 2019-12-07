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
template <typename T>
concept MenFnReadable = requires(T t)
{
    t.read();
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

template <class T>
class MemFnReader
{
public:
    template <typename IS>
    T operator()(IS &is) const
    {
        T t;
        t.read(is);
        return t;
    }
    using ReturnType = T;
private:
};


template <typename T>
struct function_traits;
template <typename R, typename... Args>
struct function_traits_helper
{
    using return_type = R;
};
template <typename R, typename... Args>
struct function_traits<R (*)(Args...)> : public function_traits_helper<R, Args...>
{
};
template <typename R, typename... Args>
struct function_traits<R (&)(Args...)> : public function_traits_helper<R, Args...>
{
};
template <typename R, typename... Args>
struct function_traits<R(Args...)> : public function_traits_helper<R, Args...>
{
};
template <typename ClassType, typename R, typename... Args>
struct function_traits<R (ClassType::*)(Args...) const> : public function_traits_helper<R, Args...>
{
    using class_type = ClassType;
};
template <typename T>
struct function_traits : public function_traits<decltype(&T::operator())>
{
};


template <class F>
class FunReader
{
    public:
    using ReturnType = typename function_traits<F>::return_type;
    FunReader(F f):fun(f)
    {
    }
    template<typename IS>
    ReturnType operator()(IS&is)
    {
        return fun(is);
    }
    private:
        F fun;
};

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
