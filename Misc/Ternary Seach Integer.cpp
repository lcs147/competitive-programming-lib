// get min
int lo = 0, hi = 1e9 + 1;
while(lo < hi) {
    int mid = (lo + hi) / 2;
    if(f(mid) < f(mid + 1)) {
        hi = mid;
    } else {
        lo = mid + 1;
    }
}