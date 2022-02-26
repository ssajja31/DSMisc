#include <iostream>
#include <vector>
#include <map>

using namespace std;

int MinSwapsToSortArray(vector<int> &v)
{
    int totalSwaps = 0;
    map<int, int> m;
    map<int, int> :: iterator it;
    vector<bool> visited(v.size(), 0);

    for(int i = 0; i < v.size(); i++)
    {
        m[v[i]] = i;
    }

    for(it = m.begin(); it != m.end(); it++)
    {
        if (it->first != it->second && visited[it->first] == 0)
        {
            int cycleSize = 0;
            int i = it->first;

            while (visited[i] != 1)
            {
                visited[i] = 1;
                cycleSize++;
                i = m[i];
            }

            totalSwaps += (cycleSize - 1);
        }
    }

    return totalSwaps;
}

int main()
{
    int n, k;
    cin >> n;
    
    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << MinSwapsToSortArray(v) << endl;

    return 0;
}

