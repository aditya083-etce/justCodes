  #include <iostream>
#include <vector>
using namespace std;

int getPivot(int s, int e)
{
    return (s + e) / 2;
}

int partition(vector<int> &v, int s, int e)
{
    int pivot = getPivot(s, e);
    swap(v[pivot], v[e]);
    int j = 0;
    for (int i = 0; i < e; i++)
    {
        if (v[i] <= v[e])
        {
            swap(v[i], v[j]);
            j++;
        }
    }
    swap(v[j], v[e]);
    return j;
}

int quickSort(vector<int> &v, int s, int e, int k)
{
    int pivot = partition(v, s, e);
    if (k == pivot){
        return v[k];
    }
    quickSort(v, s, pivot - 1);
    quickSort(v, pivot + 1, e);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    quickSort(v, 0, n - 1);

    for (auto x : v)
        cout << x << " ";
    cout << "\n";
    return 0;
} 