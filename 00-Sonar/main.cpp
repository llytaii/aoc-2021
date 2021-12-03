#include <iostream>
#include <fstream>
#include <vector>

size_t sum_of_increases(std::vector<size_t> &input)
{
    size_t sum{0};

    for (size_t i{1}; i < input.size(); ++i)
        if (input[i - 1] < input[i]) ++sum;

    return sum;
}

size_t sum_of_sliding_window_increases(std::vector<size_t> &input)
{
    size_t sliding_window1;
    size_t sliding_window2;
    size_t sum{0};

    for (size_t i{0}; i < input.size(); ++i)
    {
        if (i + 3 == input.size()) break;

        sliding_window1 = input[i] + input[i + 1] + input[i + 2];
        sliding_window2 = input[i + 1] + input[i + 2] + input[i + 3];

        if (sliding_window1 < sliding_window2) ++sum;
    }

    return sum;
}
int main()
{
    std::vector<size_t> input;
    //std::vector<size_t> input {199, 200, 208, 210, 200, 207, 240, 269, 260, 263};

    std::fstream f{"input", std::ios::in};
    if(!f.is_open()) return -1;

    for (size_t tmp; f >> tmp;)
        input.push_back(tmp);


    std::cout << sum_of_increases(input) << std::endl;
    std::cout << sum_of_sliding_window_increases(input) << std::endl;
}