int atoi(const char *str) {
    long int res = 0;
    bool minus = false;
    int c;

    while (*str == ' ')
        ++str;
    
    if (*str == '+' || *str == '-') {
        if (*str == '-')
            minus = true;
        ++str;
    }

    while (*str >= '0' && *str <= '9') {
        c = *str - '0';
        res = res * 10 + c;
        ++str;
    }
    return minus ? -res : res;
}