#include <iostream>
#include <range/v3/all.hpp>

#include "range.h"

std::vector<std::string> split(const std::string &str, char delimiter)
{
    return str | ranges::view::split(delimiter);
}

inline void printIp(const ip_t &ip)
{
    std::string out;

    ranges::for_each(ip, [&out](auto ch){out.append(std::to_string(ch)); out.append(".");});

    out.pop_back();

    std::cout << out << std::endl;
}

void printIp(const ip_vector_t &ipVector)
{
    for (const auto &ip : ipVector)
    {
        printIp(ip);
    }
}

void filterAnyAndPrint(const ip_vector_t &ipVector, int arg)
{
    for (const auto &ip : ipVector)
    {
        if (ranges::any_of(ip, [&](int i){return i == arg;}))
        {
            printIp(ip);
        }
    }
}
