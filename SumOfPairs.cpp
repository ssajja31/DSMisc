#include <iostream>
#include <vector>
#include <map>

using namespace std;

void SumOfPairs(vector<int> &v)
{
    map<int, pair<int, int>> m;
    map<int, pair<int, int>> :: iterator it;

    for(int i = 0; i < v.size(); i++)
    {
        bool flag = 0;
        for(int j = i + 1; j < v.size(); j++)
        {
            int sum = v[i] + v[j];

            it = m.find(sum);
            
            if (it == m.end())
            {
                pair<int, int> p;
                p.first = v[i];
                p.second = v[j];

                m[sum] = p;
            }
            else
            {
                cout << m[sum].first << " " << m[sum].second << " " << v[i] << " " << v[j] << endl;
                flag = 1;
                break;
            }
        }

        if(flag)
        {
            break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    SumOfPairs(v);
    return 0;
}

