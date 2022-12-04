
const int M = 1e9 + 7;
int binExpRecur(int a, int b)
{
    if (b == 0)
        return 1;
    int res = binExpRecur(a, b / 2);
    if (b & 1)
        return (a * ((res * 1LL * res) % M)) % M;
    return (res * 1LL * res) % M;
}
