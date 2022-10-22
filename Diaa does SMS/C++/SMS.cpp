#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void pushing(string &sentence, vector<string> &V)
{
    string res = "";
    for(int i = 0 ; i < (int)sentence.size(); i++)
        {
            if(sentence[i] != ',' and sentence[i+1] != '\0')
            {
                res += sentence[i];
            }
            else
            {
                if(sentence[i+1] == '\0'){res += sentence[i];}
                V.push_back(res);
                res = "";
            }
        }
    sentence = "";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("test.txt","r",stdin);

    vector<string> V, city;
    string sentence, res = "";
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> sentence;
        pushing(sentence, V);
    }
    
    cin >> N;
    while (N--)
    {
        cin >> sentence;
        pushing(sentence, city);
    }
    int j = 0;
    int d = 0;
    for(int i = 1; i < (int) city.size(); i+=2)
    {
        for(int k = 0; k < (int) V.size() ;k+=2)
        {
            if ((city[i] == V[k]) == 1)
            {
                cout << V[k] << "," << V[k+1] << "," << city[d] << "\n";
                d += 2;
                j ++;
                break;
            }
        }
    }
    if (j == 0)
    {
        cout << "nomatch" << "\n";
    }
    
}
