vi mobius(maxn + 1, 1);
L(i, 2, maxn) {
    if (mobius[i]) {
        mobius[i] = -mobius[i];
        for (int j = i + i; j <= maxn; j += i) mobius[j] += mobius[i];
    }
}
