void toh(int, char, char, char); 
void (int n, char x, char y, char z) 
{ 
If(n==1) 
{ 
printf(“\nDisk %d-%c to %c”, n,x,y); 
} 
else 
{ 
toh(n-1, x,z,y); 
printf(“\nDisk %d,%c to %c”,n, x,y); 
toh(n-1,z,y,x); 
} 
void main() 
{ 
Int n; 
printf(“Enter the no of Disks”); 
scanf(“%d”,&n); 
toh(n,’A’,’B’,’C’); 
}
