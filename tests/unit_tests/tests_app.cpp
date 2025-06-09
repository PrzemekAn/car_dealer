#include "app.h"
#include <gtest/gtest.h>

#if 1
TEST(App, run){
    App app;
    app.run("./tests/unit_tests/cars.csv");
}

#endif