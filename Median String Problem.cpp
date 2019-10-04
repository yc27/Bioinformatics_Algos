#include<bits/stdc++.h>
using namespace std;

int n, k, t;
vector<string> dna, kmers;
vector<pair<string, int> > temp, ans;
string nucltd = "ACGT";

void generate_k_mar(int i, string str)
{
    if(i == k)
    {
        kmers.push_back(str);
        return;
    }

    for(int in = 0; in < 4; ++in)
        generate_k_mar(i+1, str+nucltd[in]);
}

int calc_distance(string kmer)
{
    temp.clear();

    string str, motif;
    int distance = 0, d, cnt;

    for(int i = 0; i < t; ++i)
    {
        d = n;
        motif = "";
        for(int j = 0; j+k <= n; ++j)
        {
            cnt = 0;
            str = "";
            for(int in = 0; in < k; ++in)
            {
                str += dna[i][j+in];
                if(dna[i][j+in] != kmer[in])
                    ++cnt;
            }
            if(cnt < d)
            {
                d = cnt;
                motif = str;
            }
        }
        distance += d;
        temp.push_back( {motif, d} );
    }

    return distance;
}

int main()
{
    int best_distance, distance;
    string str;

    cin >> n >> t >> k;
    for(int i = 0; i < t; ++i)
    {
        cin >> str;
        dna.push_back(str);
    }

    generate_k_mar(0, "");
    best_distance = t*n;
    for(int i = 0; i < kmers.size(); ++i)
    {
        distance = calc_distance(kmers[i]);
        if(distance < best_distance)
        {
            best_distance = distance;
            ans.clear();
            for(int j = 0; j < temp.size(); ++j)
                ans.push_back( {temp[j].first, temp[j].second} );

        }
    }

    for(auto it : ans)
        cout << it.first << " " << it.second << endl;

}


/*
10 5 3
TTACCTTAAC
GATATCTGTC
ACGGCGTTCG
CCCTAAAGAG
CGTCAGAGGT
*/
