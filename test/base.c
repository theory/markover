#include <stdio.h>
#include <string.h>
#include "tap.h"
  
int main(void) {
    plan_tests(2);
    ok(1 + 1 == 2, "Basic arithmetic works");
    ok(1 + 1 == 2, "Basic arithmetic fails");
    return exit_status();
}
