int power(int x, int n) {
    int ret = 1;
    for (int i = 0; i < n; i++) {
        ret = ret * x;
    }
    return ret;
}

int power2(int a0 /* x */, int a1 /* n */) {
    int t0 = 0;
    int t1 = a0;
    a0 = 1;
    while (!(t0 >= a1)) {
        a0 = a0 * t1;
        t0++;
    }
    return a0;
}
