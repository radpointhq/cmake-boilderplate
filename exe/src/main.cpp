#include <iostream>

#include "lib/lib.h"

int main(int ac, char** av) {
    int ret = foo(ac);

    std::cout<< "AC: " << ac << '\n';
    std::cout<< "foo: " << ret << '\n';
    return 0;
}
