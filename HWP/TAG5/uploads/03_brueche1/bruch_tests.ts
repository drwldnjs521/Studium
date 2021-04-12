#include "bruch.h"

// checkmk bruch_tests.ts > bruch_tests.c
// gcc bruch.c bruch_tests.c -o tests -Wall -lm -lpthread -lrt -lcheck -lsubunit -std=c99 -g -fprofile-arcs -ftest-coverage

#test product_positive
    bruch a = { .nenner = 10, .zaehler = 5};
    bruch b = { .nenner = 2, .zaehler = 3};
    bruch c = product(a, b);
    ck_assert_int_eq(c.nenner, a.nenner*b.nenner);
    ck_assert_int_eq(c.zaehler, a.zaehler*b.zaehler);

#test product_negative
    bruch a = { .nenner = 10, .zaehler = 5};
    bruch b = { .nenner = -2, .zaehler = 3};
    bruch c = product(a, b);
    ck_assert_int_eq(c.nenner, a.nenner*b.nenner);
    ck_assert_int_eq(c.zaehler, a.zaehler*b.zaehler);

#test product_zero
    bruch a = { .nenner = 0, .zaehler = 5};
    bruch b = { .nenner = -2, .zaehler = 3};
    bruch c = product(a, b);
    ck_assert_int_eq(c.nenner, a.nenner*b.nenner);
    ck_assert_int_eq(c.zaehler, a.zaehler*b.zaehler);

#test change_nenner
    bruch a = { .nenner = 0, .zaehler = 5};
    set_nenner(&a, 5);
    ck_assert_int_eq(a.nenner, 5);
   
#test do_not_divide_through_zero
    bruch a = { .nenner = 0, .zaehler = 5};
    set_nenner(&a, 0);
    ck_assert_int_ne(a.nenner, 0);

