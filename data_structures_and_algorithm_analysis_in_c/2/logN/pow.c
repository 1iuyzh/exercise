long int Pow(long int X, unsigned int N) {
    if (N == 0)
        return 1;
    if (N == 1)
        return X;
    if (N%2 == 0)
        return Pow(X * X, N / 2);
    if (N%2 == 1)
        return Pow(X * X, N / 2) * X;
}