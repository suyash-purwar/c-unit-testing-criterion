#include <string.h>
#include <criterion/criterion.h>

Test(test_strlen, test1) {
  cr_assert(strlen("Hello") == 5);
}