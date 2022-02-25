#include <iostream>
#include <vector>

using namespace std;

int MinSwaps(vector<int> &v, int k)
{
    int count = 0;
    int tempSwaps = 0;
    int totalSwaps;

    for(int i = 0; i < v.size(); i++)
    {
        if (v[i] <= k)
        {
            count++;
        }
    }

    for(int i = 0; i < count; i++)
    {
        if (v[i] > k)
        {
            tempSwaps++;
        }
    }

    totalSwaps = tempSwaps;

    for(int i = 0; i < v.size(); i++)
    {
        int j = i + count;

        if (j >= v.size())
        {
            break;
        }

        if (v[i] > k)
        {
            tempSwaps--;
        }

        if (v[j] > k)
        {
            tempSwaps++;
        }

        totalSwaps = min(totalSwaps, tempSwaps);
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
    cin >> k;

    cout << MinSwaps(v, k) << endl;

    return 0;
}

