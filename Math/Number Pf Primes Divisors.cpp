const int bigN = 2e7;
vector<int> pr;
vector<int> lp(bigN + 1);
vector<int> np(bigN + 1);
{
    for(int i = 2; i <= bigN; i++) {
        if(lp[i] != 0) continue;
        lp[i] = i;
        for(int j = i * i; j <= bigN; j += i) {
            if(lp[j] == 0) lp[j] = i;
        }
    }
    for(int i = 2; i <= bigN; i++) {
        int nxt = i / lp[i];
        np[i] = np[nxt];
        if(lp[i] != lp[nxt]) np[i]++;
    }
}