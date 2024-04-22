//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST(isleap, functions) {
    try {
        IsLeap(-1);
    } catch (...) {}
    ASSERT_FALSE(IsLeap(23));
    ASSERT_TRUE(IsLeap(4));
    ASSERT_FALSE(IsLeap(100));
    ASSERT_TRUE(IsLeap(400));
}

TEST(getmonthday, functions) {
    try {
        GetMonthDays(2000, -1);
    } catch (...) {}
    ASSERT_TRUE(GetMonthDays(1930, 2) == 30);
    ASSERT_TRUE(GetMonthDays(1940, 2) == 29);
    ASSERT_TRUE(GetMonthDays(1941, 2) == 28);
    ASSERT_TRUE(GetMonthDays(1940, 4) == 30);
    ASSERT_TRUE(GetMonthDays(1940, 1) == 31);
}
