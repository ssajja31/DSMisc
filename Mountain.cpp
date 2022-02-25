#include <iostream>
#include <vector>

using namespace std;

int MaxMountainLength(vector<int> &v)
{
    int result = 0;

    for(int i = 0; i < v.size() - 1; i++)
    {
        int temp = 0;
        while (v[i] < v[i+1])
        {
            temp++;
            i++;
        }

        while (v[i] > v[i+1])
        {
            temp++;
            i++;
        }

        if (temp > result)
        {
            result = temp;
            i--;
        }
    }

    return result + 1;
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

    cout << MaxMountainLength(v) << endl;

    return 0;
}

