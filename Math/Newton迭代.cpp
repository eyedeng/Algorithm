#define EPS 0.000001
// X^2 = a
// 迭代:X_i+1 = (X_i + a/X_i)/2
double nsqrt(double a)
{
    double x = a,tx;
    while(abs(tx - x) > EPS)
    {
        //printf("%f  %f\n",x ,(x + a/x) / 2.0f);
        tx = x;
        x = (x + a/x) / 2.0f;
        printf("%f\n", x);
    }
    return x;
}
int main()
{
    //cout<<0x5f375a86;
    cout<<nsqrt(2.0);
    return 0;
}