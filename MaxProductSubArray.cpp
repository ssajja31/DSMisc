#include <iostream>
#include <vector>

using namespace std;

int maxProdSubArray(vector<int> &v)
{
    int maxProd = v[0];
    int mini = maxProd;
    int maxi = maxProd;

    for(int i = 1; i < v.size(); i++)
    {
        int mini1 = mini * v[i];
        int maxi1 = maxi * v[i];

        maxi = max(max(mini1, maxi1), v[i]);
        mini = min(min(mini1, maxi1), v[i]);

        if(maxProd < maxi)
        {
            maxProd = maxi;        
        }
    }

    return maxProd;
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


    cout << maxProdSubArray(v) << endl;

    return 0;
}

