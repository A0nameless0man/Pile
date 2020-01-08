#include <array>
#include <optional>
int main()
{
    std::optional<int>                           opt;
    std::optional<std::string>                   opt;
    constexpr std::optional<int>                 opt;
    constexpr std::optional<std::pair<int, int>> xopt;
    std::optional<std::array<int, 10>>           aopt;
    std::optional<int[10]>                       opt;
    std::optional<const int>                     opt;
}

struct myoptional
{
    char[sizeof(T)] mem;
    // T value;
    bool engaged;
}