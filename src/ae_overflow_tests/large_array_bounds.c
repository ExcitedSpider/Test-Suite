void SAFE_BUFACCESS(void *, unsigned long);
void UNSAFE_BUFACCESS(void *, unsigned long);

int main(void)
{
    int a[400];
    SAFE_BUFACCESS(&a[399], 3);
    UNSAFE_BUFACCESS(&a[400], 3);
    return 0;
}
