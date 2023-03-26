#include<iostream>
using namespace std;




/*here the num is copy not an i1
but in second one num is refrence variable of i1
as the refrence value increases the i1 increases
only the name is changes,address is same,no new 
memory creates,passed by refrence
return type can also refrence varibale but in local varibale return 
it is bad pratice*/
int reference_variable(int num){
    num++;
    return(num);
}
int reference_variable_1(int &num){
    cout<<"the address of num is "<<(int)&num<<endl;
    num++;
    return(num);
}
int& reference_variable_2(int &num){
    int a=num;
    int& ans=a;    
    return ans;
}   








/*quick sort method(imp) 
arragment of pivot point,count all small element for pivot 
position then swap of pivot poisition then contion of small 
and greater.
*/
int partition(int arr[],int start,int end){
    int pivot=arr[start];
    int right_position=0;
    for(int i=start+1;i<=end;i++){ 
        if(arr[i]<=pivot)
        right_position++;
    }
    int pivotindex=start+right_position;
    swap(arr[start],arr[pivotindex]);
    int i=start,j=end;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }    
    }
    return(pivotindex);
}
void quick_sort(int arr[],int start,int end){
    if(start>=end)
        return;
    int p=partition(arr,start,end);
    quick_sort(arr,start,p-1);
    quick_sort(arr,p+1,end);
}




int main(){

    /*time complexity
    it is amount of time taken by an algorithm to run
    as a function of length of input inn code
    for the betterment of programme and comparision of algo
    big o notation(upper band,wrost case),theta(for avg case),omega(lower band)
    o(1)->constant time,o(n)->linear timme,log time->o(log(n)),qud time->o(n^2),etc
    constnt time is when there is fixed amount
    linear time when there is n time simmilar to others.o(n) is best time complexity
    */
     /*the space complexity is the varibale space  
    taken by the code,mostly in vector space complexity 
    varyies..the complexity of o(logn)is best then the o(n)*/


    int arr_0[9]={1,4,7,2,10,14,23,13,11};
    int max=arr_0[0]; 
    for(int i=0;i<sizeof(arr_0)/sizeof(int);i++){
        if(arr_0[i]>max)
            max=arr_0[i];
    }    
    cout<<"the max value of array is "<<max<<endl;
    cout<<"the time complexity is o(1)->wrost case"<<endl;
            




    /*linear search
    linear search is the method to search the element in 
    array in the linear way go to each elemnet and check it is
    same or not,here the sorted array is not required*/
    int key_ls;
    int arr_ls[]={5,7,2,3,9,10,23};
    cout<<"enter the key ";
    cin>>key_ls;
    int i_ls;
    for(i_ls=0;i_ls<sizeof(arr_ls)/sizeof(int);i_ls++){
        if(arr_ls[i_ls]==key_ls){
            cout<<"the key is found "<<endl;
            break;
        }    
    }    
    if(i_ls==sizeof(arr_ls)/sizeof(int))
    cout<<"the key is not found "<<endl;
    cout<<"the time complexity is o(n) when size is n"<<endl;




    /*binary seaarch
    this is used for reducing the time complexity,the condi
    -tionn in this that the array must be sorted,we check mid
    elemnet if found then return,else move left right acc to key
    and mid.this increasing order we can say monotonic fun 
    there is no effect that either array size is even or odd
    some time mid value is out of range then we use (s+(e-s)/2)
    its complexity comes by N,N/2,----N/(2^n)=1 so by this 
    N=2^n whichm mkes log(N) as n comparision*/
    int arr_bs[]={1,6,7,34,56,78,90,100,102};
    int key_bs;
    cout<<"enter the key ";
    cin>>key_bs;
    int start_bs=0;
    int end_bs=sizeof(arr_bs)/sizeof(int)-1;
    while(start_bs<=end_bs){
        int mid=(start_bs+end_bs)/2;
        if(key_bs==arr_bs[mid]){
            cout<<"the key is found at index "<<mid<<endl;
            break;
        }
        if(key_bs>arr_bs[mid])
            start_bs=mid+1;
        if(key_bs<arr_bs[mid])
            end_bs=mid-1;
    }
    if(start_bs>end_bs)
    cout<<"the key is not found "<<endl;
    cout<<"here the time complexity is o(logn) if there is n elements "<<endl;
    cout<<endl<<endl;



     /*first and last element in sorted array
       total no of apperenace =last-first+1;
    here the sorted array is hint that binary search is used
    we have to find the first and last element poisition
    of given key,this we have to do two times as of first
    and last*/
    int arr_fl[]={2,3,3,3,4,5,5,5,5,7,8,8};
    int key_fl,ans_fl_f,ans_fl_l;
    cout<<"enter the key or element ";
    cin>>key_fl;
    int start_fl=0;
    int end_fl=(sizeof(arr_fl)/sizeof(int))-1;
    while(start_fl<=end_fl){
        int mid=(start_fl+end_fl)/2;
        if(arr_fl[mid]==key_fl){
            ans_fl_f=mid;
            end_fl=mid-1;
        }
        if(arr_fl[mid]>key_fl)
            end_fl=mid-1;
        if(arr_fl[mid]<key_fl)
            start_fl=mid+1;
    }
    start_fl=0;
    end_fl=(sizeof(arr_fl)/sizeof(int))-1;
    while(start_fl<=end_fl){
        int mid=(start_fl+end_fl)/2;
        if(arr_fl[mid]==key_fl){
            ans_fl_l=mid;
            start_fl=mid+1;
        }
        if(arr_fl[mid]>key_fl)
            end_fl=mid-1;
        if(arr_fl[mid]<key_fl)
            start_fl=mid+1;
    }
    cout<<"the first poistion is "<<ans_fl_f<<endl;
    cout<<"the last poistion is "<<ans_fl_l<<endl;
    cout<<endl<<endl;




    /*pair
    syntax: pair<int,int> p; as we can send any value
    if we return pair then the two value returns but in printing
    we have to print individual like p.first and p.second 
    simillary for scanning also*/
    pair<int,int> p;
    p.first=12;
    p.second=14;
    cout<<p.first<<" "<<p.second;
    cout<<endl<<endl;




    /*peak index in mountain array
    in this the arrays in the mountain form where
    elements are in creasing order then decreasing we have
    to find the topmost element index.here in this we only 
    playing with the value of mid*/
    int arr_m[]={4,5,10,4,1};
    int start_m=0;
    int end_m=(sizeof(arr_m)/sizeof(int))-1;
    while(start_m<end_m){
        int mid=(start_m+end_m)/2;
        if(arr_m[mid]<arr_m[mid+1])
            start_m=mid+1;
        if(arr_m[mid]>arr_m[mid+1])
            end_m=mid;
    }
    cout<<"the mountain element is "<<start_m;
    cout<<endl<<endl;
    



    /*pivot point
    pivot in an array is the smallest element in an 
    array simillarly the mountain index we can find pivot
    in this we also play with mid amd moving of the start 
    and end value,pivot is different for different person*/
    int arr_p[]={12,4,2,1,0,5,7,8,10};
    int start_p=0;
    int end_p=(sizeof(arr_p)/sizeof(int))-1;
    while(start_p<end_p){
        int mid=(start_p+end_p)/2;
        if(arr_p[mid]<arr_p[mid+1])
            end_p=mid;
        if(arr_p[mid]>arr_p[mid+1])
            start_p=mid+1;
    }
    cout<<"the pivot point is "<<start_p;
    cout<<endl<<endl;










    /*reference variable
    same memory but different name and having same address ,only name is diff
    creating for the refrencing variable syntax-> int& j=i;
    j is known as refrence variable of i;
    here j is the refrence varibale i++,j++ has same meaning
    need of this is in function*/
    int i=5;
    int &j=i;
    cout<<i<<" "<<j<<endl;
    cout<<i++<<endl;
    cout<<j++<<endl;
    cout<<i++<<" "<<j++<<endl;
    cout<<"address of i "<<(int)&i<<endl;
    cout<<"address of j "<<(int)&j<<endl;
    cout<<i+j<<" "<<2*i<<endl;
    /*the use of refrence variable in the function
    return by refrence is also a drawback
    */
    int i1=5;
    cout<<"before value of i1 "<<i1<<endl;
    reference_variable(i1);
    cout<<"after value of i1 "<<i1<<endl;
    reference_variable_1(i1);
    cout<<"address of i1 is "<<(int)&i1<<endl;
    cout<<"after value of i1 "<<i1<<endl;
    cout<<"value is "<<reference_variable_2(i1)<<endl;
    
    



    /*dynamic memory of array
    array runtime taking the n is bad pratice arr[n]
    the size must be known at the compile time as it rashes mmany times;
    there was stack and heap,stack memory will not able to expand at runtime
    due to its small size(stack is small and heap is larger)
    heap memory is used whenn new keyword is used
    stack memory is static allocation while heap is dynamic memo allocation
    in the heap there is no name only address
    with the help of pointer the address is stored and accessed
    this pointer was formed in stack memory
    pointer in array : arr[i]=*(arr+i);
    pointer generally takes 4 or 8 bytes
    */
    /*main diference in static and dynamic is size as dynamic 
    requies more memory as pointer extra then static one*/    
    char name='s';
    char *ch = new char;
    cout<<"sizeof the pointer "<<sizeof(ch)<<endl;
    cout<<"size of "<<sizeof(name)<<endl;
    int n;
    cout<<"enter the value of n ";
    cin>>n;
    int *arr=new int[n];
    cout<<"enter the elements ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        cout<<*(arr+i)<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl<<endl;    
    



    /*the most funny thin is,there are staic and dynamic
    the memory creates then release(scope) this run again and again
    the memory of stack releases byt not of heap after scope so 
    when memory full of heap then sysytm crahes,in static memory automatically 
    cleans,so memory is cleaned of heap by delete keyword 
    int *i=new int then delete syntax : delete i;
    int *arr=new int[] delete syntax : delete []arr;
    */
    // while(true){
    //     int i=5;
    // }

    // while(true){
    //     int *p=new int;
    // }
    

    




    /*merge sort
    in this the array divide into two parts and then sorted each
    then mergeing of both sorted array this is known by merge two
    sorted array*/

    





    /*quick sort(sortning algo)
    array used to get sorted with this algo,it says that put an
    element on right place and then place smaller elemnet on left
    and bigger element on the right hand side.there was creation 
    of partition,it is two step process-.partition and then recussion
    */
    int arr_qs[]={3,5,1,8,2,4};
    quick_sort(arr_qs,0,sizeof(arr_qs)/sizeof(int)-1);
    for(int i=0;i<sizeof(arr_qs)/sizeof(int);i++){
        cout<<arr_qs[i]<<" ";
    }
    cout<<endl<<endl;































    return 0;
}
