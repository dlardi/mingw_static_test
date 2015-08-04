#include "a.h"
#include "static_object.h"
#include "externs.h"

#include <iostream>

int main()
{
    std::cout << StaticObject<int>::getInstance() << std::endl;

    test();

    std::cout << StaticObject<int>::getInstance() << std::endl;

    return 0;
}
