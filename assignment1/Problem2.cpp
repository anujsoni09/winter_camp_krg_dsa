#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
void Union(int arr1[],int arr2[],int m,int n){
     if(m>n){
        int *temp=arr1;
        arr1=arr2;
        arr2=temp;
        swap(m,n);
      }
      sort(arr1,arr1+m);
      for(int i=0; i<m;i++){
        cout<<arr1[i]<<" ";
      }
      for(int i=0; i<n; i++){
        if(binarySearch(arr1,0,m-1,arr2[i])==-1){
            cout<<arr2[i]<<" ";
        }
      }
}

void intersection(int arr1[], int arr2[], int m, int n){
        if(m>n){
        int *temp=arr1;
        arr1=arr2;
        arr2=temp;
        swap(m,n);
      }
      sort(arr1,arr1+m);
       for(int i=0; i<n; i++){
        if(binarySearch(arr1,0,m-1,arr2[i])!=-1){
            cout<<arr2[i]<<" ";
        }
      }  
}

void common(int arr1[],int arr2[], int arr3[], int m, int n, int o){
  int i=0, j=0, k=0;
  sort(arr1,arr1+m);
  sort(arr2,arr2+n);
  sort(arr3,arr3+o);

  while(i<m && j<n && k<o){
    if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
      cout<<arr1[i]<<" ";
      i++;
      j++;
      k++;
    }
    else if (arr1[i]>arr2[j]){
      j++;
    }
    else if(arr2[j]>arr3[k]){
      k++;
    }
  }

}
int main(){
    int arr1[]={2,4,6,7,9,10,11};
    int arr2[]={1,2,4,5,};
    int arr3[]={2,8,10};
    int m=sizeof(arr1)/sizeof(arr1[0]);
    int n=sizeof(arr2)/sizeof(arr2[0]);
    int o=sizeof(arr3)/sizeof(arr3[0]);
    Union(arr1,arr2,m,n);
    cout<<endl;
    intersection(arr1,arr2,m,n);
    cout<<endl;
    common(arr1,arr2,arr3,m,n,o);
}