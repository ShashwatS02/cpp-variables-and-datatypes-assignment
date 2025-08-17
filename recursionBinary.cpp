#include <bits/stdc++.h>
using namespace std;

bool linearsearch(int arr[], int X, int index, int N) {
    //base case
    if (index == N) return 0;
    if (arr[index] == X) return 1;
    return linearsearch(arr, X, index+1, N);
}

bool Binarysearch(int arr[], int start, int end, int X) {
    if (start > end) return 0;
    int mid = start + (end - start)/2;
    if (arr[mid] == X) return 1;
    else if (arr[mid] < X) return Binarysearch(arr, mid+1, end, X);
    else return Binarysearch(arr, start, mid-1, X);
}

int main() {
    //serching an element
    // int arr[] = {2,3,6,7,1,5};
    // int X = 7;
    // cout << linearsearch(arr, X, 0, 6) << endl;

    //binary search
    int arr[] = {2,4,6,8,10,12};
    int X = 20;
    cout << Binarysearch(arr, 0, 5, X);
}