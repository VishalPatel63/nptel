#include<bits/stdc++.h>
using namespace std;
int reversort(vector<int>& arr) {
    int total_cost = 0;
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

         reverse(arr.begin()+i, arr.begin()+min_index +1);
        total_cost += (min_index - i + 1);
    }
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return total_cost;
}
int main()
{
    vector<int> v = {1, 8, 2, 7, 3, 6, 4, 5};
    // vector<int> v = {1, 8, 2, 7, 3, 6, 4, 5};
    cout<<"cost: "<<reversort(v)<<endl;
    return 0;
}