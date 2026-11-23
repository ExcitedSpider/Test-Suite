/* Pointer counterpart of cmp-int-undef.c (gitea-admin/SVF#21).
 * After `clang -O0 -Xclang -disable-O0-optnone` + `opt -passes=mem2reg`,
 * the uninitialized pointer becomes `icmp ne ptr undef, @object`. An unknown
 * pointer may or may not equal &object, so the result must be exactly [0, 1]. */
#include <stdbool.h>

extern void svf_assert_eq(int, int);

int object;

int main(int argc, char **argv)
{
    int *p;
    /* Materialize the result without a zext, which loses interval precision in AE. */
    int r = (p != &object) ? 1 : 0;
    /* argc is unknown, so expected is the interval [0, 1]. */
    int expected = (argc == 1) ? 1 : 0;
    svf_assert_eq(r, expected);
    return 0;
}
