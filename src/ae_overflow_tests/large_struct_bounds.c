void SAFE_BUFACCESS(void *, unsigned long);
void UNSAFE_BUFACCESS(void *, unsigned long);

struct Large { char pad[1200]; int tail; } g;

int main(void)
{
    SAFE_BUFACCESS(&g.tail, 3);
    UNSAFE_BUFACCESS((char *)&g + sizeof(g), 0);
    return 0;
}
