#include<iostream>
using namespace std;

int partitionbyend(int arr[], int st, int end)
{
    int mid=st+(end-st)/2;
    int pivot=arr[mid];
    int temp1=arr[mid];
    arr[mid]=arr[end];
    arr[end]=temp1;
    int idx=st-1;
    for(int j=st;j<end;j++)
    {
    
        
        if (arr[j]<=pivot)
        {
            idx++;
            int temp=arr[j];
            arr[j]=arr[idx];
            arr[idx]=temp;
        }
    }
    idx++;
        int temp=arr[end];
        arr[end]=arr[idx];
        arr[idx]=temp;
        return idx;
}
int partitionbymiddle(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];  // Middle element as pivot

    int i = low;
    int j = high;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return i;
}

int partitionbystart(int arr[], int st, int end)
{
    int pivot=arr[st];
    int i=st+1;
    int j=end;
    while(i<=j)
    {
        while (i<=end&&arr[i]<=pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if (i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        
    }
        int temp=arr[st];
        arr[st]=arr[j];
        arr[j]=temp;
        return j;
}
void quicksort(int arr[],int st, int end){

    if(st<end)
    {
        int pivotindx=partitionbystart(arr,st,end);
        quicksort(arr,st,pivotindx-1);
        quicksort(arr,pivotindx+1,end);
    }

}
void display(int arr[],int n)
{
    if(n<0){
        return;
    }
    display(arr,n-1);
    cout<<arr[n]<<" ";
}
int main()
{
    int arr[]={1,4,53,2,1,5};
    int n=6;
    cout<<"Array before sorting:";
    display(arr,n-1);
    cout<<endl<<"Array after sorting:";
    quicksort(arr,0,n-1);
    display(arr,n-1);


}