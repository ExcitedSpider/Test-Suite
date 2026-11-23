/* Reproducer for an icmp over an integer undef operand (gitea-admin/SVF#21).
 * The uninitialized local only becomes a literal `undef` operand after
 * `clang -O0 -Xclang -disable-O0-optnone` + `opt -passes=mem2reg,lower-switch`;
 * the stock generate_bc.sh pipeline leaves optnone on main, which blocks
 * mem2reg, so this case then only guards the load-based compare. */
#include <stdbool.h>

extern void svf_assert(bool);

int main(void)
{
    int x;
    /* Materialize the result without a zext, which loses interval precision in AE. */
    int r = (x != 0) ? 1 : 0;
    svf_assert(r >= 0 && r <= 1);
    return 0;
}
