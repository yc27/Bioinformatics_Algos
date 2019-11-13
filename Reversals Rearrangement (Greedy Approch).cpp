#include<bits/stdc++.h>
using namespace std;

vector<int> Reverse(vector<int> vec, int st, int en)
{
    int n = en - st + 1;

    for(int i = 0; i < (n+1)/2; ++i)
    {
        swap(vec[st+i], vec[en-i]);

        vec[st+i] = -(vec[st+i]);
        if(st+i == en-i)
            continue;
        vec[en-i] = -(vec[en-i]);
    }
    return vec;
}

void printVector(int n, vector<int> vec)
{
    for(int i = 0; i < n; ++i)
        cout << vec[i] << " ";
    cout << endl;
}

void reorder(int n, vector<int> vec)
{
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(abs(vec[i]) != i+1)
        {
            for(int j = i+1; j < n; ++j)
            {
                if(abs(vec[j]) == i+1)
                {
                    ++cnt;
                    vec = Reverse(vec, i, j);
                    printVector(n, vec);
                    break;
                }
            }
        }
        if(vec[i] < 0)
        {
            ++cnt;
            vec[i] = -(vec[i]);
            printVector(n, vec);
        }
    }

    cout << "Total Steps: "  << cnt << endl;
}

int main()
{
    vector<int> vec;
    int n, x;

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> x;
        vec.push_back(x);
    }

    reorder(n, vec);
}

/*
6
3 -4 1 -2 5 -6
*/
