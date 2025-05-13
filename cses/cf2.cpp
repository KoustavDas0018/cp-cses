#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++) cin>>a[i];
    int largest=-1,secondLargest=-1;
    for(int i=0;i<n;i++){
        if(a[i]>largest){
            largest=a[i];
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]>secondLargest && a[i]!=largest){
            secondLargest=a[i];
        }
    }
    cout<<"Second Largest Element is : "<<secondLargest<<endl;
    return 0;
}