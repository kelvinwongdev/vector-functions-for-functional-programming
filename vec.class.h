#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

template <typename T>
class Vec
{
public:
    const std::vector<T> &value;
    const int &length;

    Vec(std::vector<T> vector) : value($value), length($length)
    {
        $value = vector;
        $length = vector.size();
    }

    void print()
    {
        if (length > 0)
        {
            std::cout << "{ ";
            std::for_each(value.begin(), value.end(),
                          [](auto &item)
                          { std::cout << item << ", "; });
            std::cout << "\b"
                      << "\b"
                      << " }" << std::endl;
        }
        if (length <= 0)
        {
            std::cout << "{ }" << std::endl;
        }
    }

    template <typename NewVueType, typename Lambda>
    Vec<NewVueType> map(Lambda lambda)
    {
        std::vector<NewVueType> updatedValue;
        std::transform(value.begin(), value.end(), std::back_inserter(updatedValue), lambda);
        Vec<NewVueType> UpdatedVector(updatedValue);
        return UpdatedVector;
    }

    template <typename Lambda>
    Vec filter(Lambda lambda)
    {
        std::vector<T> updatedValue;
        std::copy_if(value.begin(), value.end(), std::back_inserter(updatedValue), lambda);
        Vec UpdatedVector(updatedValue);
        return UpdatedVector;
    }

    Vec slice(int begin = 0, int end = 0)
    {
        end = end >= 0 ? end : value.size() + end;

        bool validCase = begin < end && begin >= 0 && end <= (value.size() - 1);

        if (!validCase)
            begin = end;

        auto beginIndex = value.begin() + begin;
        auto endIndex = value.begin() + end;

        std::vector<T> updatedValue;
        std::copy(beginIndex, endIndex, std::back_inserter(updatedValue));
        Vec UpdatedVector(updatedValue);
        return UpdatedVector;
    }

    void push(T item)
    {
        $value.push_back(item);
        $length = $value.size();
    }

    template <typename Lambda>
    T find(Lambda lambda)
    {
        auto result = std::find_if(value.begin(), value.end(), lambda);
        return *result;
    }

    template <typename Lambda>
    T reduce(Lambda lambda, T initialValue)
    {
        auto result = std::accumulate(value.begin(), value.end(), initialValue, lambda);
        return result;
    }

private:
    std::vector<T> $value;
    int $length;
};