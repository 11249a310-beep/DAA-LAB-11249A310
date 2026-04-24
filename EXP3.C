void perm(int arr[], int start, int stop) 
{ 
int temp; 
If(start==stop) 
{ 
for (int i=0;i<stop;i++) printf(“\t%d”,arr[i]); 
printf(“\n”); 
} 
Else 
{ 
for(int i=start;i<stop;i++) 
{ 
temp=arr[i]; 
arr[i]=arr[start]; 
a[start]=temp; 
perm(arr,start+1;stop); 
temp=arr[i]; 
arr[i]=arr[start]; 
a[start]=temp; 
} 
} 
} 
void main() 
{ 
int n, I,a[10]; 
printf(“Enter total no element”); 
scanf(“%d”,&n); 
for(i=0;i<n;i++) 
scanf(“%d”,&a[i]); 
perm(a, 0,n); 
} 
