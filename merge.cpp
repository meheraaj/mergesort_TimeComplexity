
#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right)
{
    vector<int> temp;
    int i = left;
    int j = mid;

    while (i < mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i < mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k <= right - left; ++k)
    {
        arr[left + k] = temp[k];
    }
}

void merge_sort(vector<int>& arr, int left, int right)
{

    if (left >= right)
        return;

    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

int main()
{
    ifstream inputFile("input.txt");
    vector<int> arr;
    int num;

    if (!inputFile)
    {
        cerr << "Error: Unable to open input.txt" << endl;
        return 1;
    }

    int n;
    cin >> n;
    int x = 0;
    while (inputFile >> num)
    {
        x++;
        if(x >= n)
            break;
        arr.push_back(num);
    }
    inputFile.close();
    cout << "Time taken for " << n << " inputs : " ;
    time_t st = clock();
    merge_sort(arr, 0, arr.size()-1);
    time_t en = clock();

double time_taken = double(en - st) / CLOCKS_PER_SEC;
    cout << time_taken << endl;




    return 0;
}
