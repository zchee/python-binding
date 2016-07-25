// clang++ --std=c++14 concat.cpp -I. -o concat -lconcat
#include <vector>
#include <string>
#include <iostream>
#include "libconcat.h"

int main() {
    std::string s_in {"Hello "};
    std::vector<char> v_in {'W', 'o', 'r', 'l', 'd'};
    std::vector<char> v_out(11);

    GoString go_s_in{&s_in[0], static_cast<GoInt>(s_in.size())};
    GoSlice go_v_in{
        v_in.data(),
        static_cast<GoInt>(v_in.size()),
        static_cast<GoInt>(v_in.size()),
    };
    GoSlice go_v_out{
        v_out.data(),
        static_cast<GoInt>(v_out.size()),
        static_cast<GoInt>(v_out.size()),
    };

    Concat(go_s_in, go_v_in, go_v_out);

    for(auto& c : v_out) {
        std::cout << c;
    }
    std::cout << '\n';
}
