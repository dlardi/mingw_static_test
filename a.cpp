#include "static_object.h"
#include "externs.h"

void test()
{
    StaticObject<int>::getInstance() = 1;
}
