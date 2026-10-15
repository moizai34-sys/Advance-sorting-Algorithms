#include<iostream>
using namespace std;

void merge(int arr[],int low , int mid, int high){
    int i=low;
    int j=mid+1;
    int k=0;

    int temp[100];
    while (i<=mid && j<=high)
    {
        if (arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
        
    }
    while (i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }

    for(i=low,k=0;i<=high;i++,k++)
    {
        arr[i]=temp[k];
    }
    
    
}

void mergesort(int arr[],int low, int high)
{
    if (low<high)
    {
        int mid=low+(high - low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
    
}
void display_arr(int arr[],int n){

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int arr[6]={12,4,5,21,3,1};
    cout<<"array without sorting:"<<endl;
    display_arr(arr,6);

    cout<<endl<<"Array after sorted:"<<endl;
    mergesort(arr,0,5);
    display_arr(arr,6);


}