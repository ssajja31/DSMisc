#include <iostream>
#include <vector>

using namespace std;

int MaxMountainLength(vector<int> &v)
{
    int result = 0;
    int n = v.size() - 1;

    for(int i = 0; i < n; i++)
    {
        int temp = 0;
        bool incFlag = false;
        bool decFlag = false;

        while (i < n && v[i] < v[i+1])
        {
            temp++;
            i++;
            incFlag = true;
        }

        while (i < n && v[i] > v[i+1])
        {
            temp++;
            i++;
            decFlag = true;
        }

        if (temp > result && incFlag && decFlag)
        {
            result = temp;
        }

        if (incFlag || decFlag)
        {
            i--;
        }
    }

    return result == 0 ? result : result + 1;
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

