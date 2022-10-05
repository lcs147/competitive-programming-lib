const int bigN = 2e7;
vector<int> pr;
vector<int> lp(bigN + 1);
{
    for(int i = 2; i <= bigN; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= bigN; j++)
            lp[i * pr[j]] = pr[j];
    }
}