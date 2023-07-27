//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=1;i<n;i++){
            int p = (i-1)/2,c=i;
            while(c and arr[c]>arr[p]){
                swap(arr[c],arr[p]);
                c=p;p=(c-1)/2;
            }
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>0;i--){   // poping elements from heap
            swap(arr[0],arr[i]);
            int p=0;
            while(p<i){
                int l = 2*p+1,r=2*p+2;
                if(l<i and r<i){
                    int b = (arr[l]>arr[r])? l:r;
                    if(arr[p]<arr[b]){
                        swap(arr[p],arr[b]);
                        p = b;
                    }
                    else break;
                }
                else if(l<i and arr[l]>arr[p]){
                    swap(arr[p],arr[l]);
                    p = l;
                }
                else if(r<i and arr[r]>arr[p]){
                    swap(arr[p],arr[r]);
                    p = r;
                }
                else break;
            }
        }
    }
};



//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends