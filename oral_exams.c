#include <stdio.h>    
#include <stdlib.h>    

long int minu( long int a,  long int b);    
long int gcd(  long int a,  long int b);    
long int lcm(  long int a,  long int b);    
long int mod(  long int a,  long int b);    

void quickSort(  long int num_st_per_cycle2,  long int fin[2][num_st_per_cycle2],  long int s,  long int r);  
long int partition(  long int num_st_per_cycle2,  long int fin[2][num_st_per_cycle2],   long int s,  long int r);  

int main(int argc, char **argv)    
{    

long int N,K;    
scanf("%ld%ld",&N,&K);    
long int d[N];    
scanf("%ld",&d[0]);    
long int current_lcm=d[0];     
long int minimum=d[0];  
long int serv=0;  

for (long int i=1; i<N; i++) 
{    
	scanf("%ld",&d[i]);    
	current_lcm=lcm (d[i],current_lcm);    
	if (d[i]<=minimum) 
		{
		minimum=d[i]; 
		serv=i;
		}  
}    
//Got lcm of all the numbers given in the array in order to calculate the service priority   
//skip the 'cycles' not needed.    
//current_lcm = time for a complete cycle      

long int num_st_per_cycle=0;  
//number of students that are serviced for every cycle


for (  long int i=0; i<N; i++) {    
num_st_per_cycle+=current_lcm / d[i];    
}    
long int num_st_per_cycle2=num_st_per_cycle;  
//num_st_per_cycle is K mod pos or equivalently starting point for each individual

long int upoloipo=mod (K,num_st_per_cycle);    
long int piliko=K/num_st_per_cycle;    


long int final[2][num_st_per_cycle];    
long int l=0;    
long int j=0;    

for (  long  int su=0; su<num_st_per_cycle; su++)    
final[0][su]=final[1][su]=0;    
long int indv_strt=0;    
while (j<num_st_per_cycle && l<N) {    
final[0][j]=l;    

indv_strt+=d[l];    
final[1][j]+=indv_strt;    
j++;    
if(indv_strt>=current_lcm) {

l++; indv_strt=0;}    
}    

for ( long int n=0; n<num_st_per_cycle; n++)    
{    
final[1][n]-=d[final[0][n]];        
}       
 
quickSort ( num_st_per_cycle2 , final , 0 ,num_st_per_cycle-1 );  

long int search=final[1][upoloipo-1];  
long int found=0;  
long int mat[num_st_per_cycle];  
long int position;  
for (  long int i=0; i<num_st_per_cycle; i++) mat[i]=-1;  
int jr=0;  
for (  long int i=0; i<minu(num_st_per_cycle,upoloipo-1+N); i++) {  
if (final[1][i]==search) {  
if (found==0) {found=1; position=i;}  
mat[jr]=final[0][i];   
jr++;}  
}  

for ( long int i=0; i<jr-1; i++) {  
for (int kl=0; kl<jr-i-1; kl++) {  
if (mat[kl]>mat[kl+1]) {  long int te=mat[kl]; mat[kl]=mat[kl+1]; mat[kl+1]=te; }  
}  
}  

long int answer;  
long int tim;  

if (upoloipo!=0)    
{    
answer = mat[upoloipo-position-1] +1;  
tim= final[1][upoloipo-1]+d[answer-1]+piliko*current_lcm;  

}    

else     
{    
answer=serv+1;   
tim=piliko*current_lcm;    
}    
printf("%ld% ld\n",answer,tim);   

return 0;    
}    

long int mod( long int a,  long int b)     
{    
long int result=a-(a/b)*b;    
return result;    
}    

long int gcd(  long int a,  long int b)    
{    
while (b != 0)    
{    
a %= b;    
a ^= b;    
b ^= a;    
a ^= b;    
}    

return a;    
}    

long int lcm(  long int a,  long int b)    
{    
return a / gcd(a, b) * b;    
}    

void quickSort(  long int num_st_per_cycle2,unsigned  long long int fin[2][num_st_per_cycle2],  long int s,  long int r)  
{  
long int f;  

if( s < r )   
{  
// divide and conquer method  
f = partition(num_st_per_cycle2, fin, s, r);  
quickSort(num_st_per_cycle2, fin, s, f-1);  
quickSort(num_st_per_cycle2, fin, f+1, r);  
}  

}  

long int partition(  long int num_st_per_cycle2,  long int fin[2][num_st_per_cycle2],  long int s, long int r) {  
long int partition(  long int num_st_per_cycle2,  long int fin[2][num_st_per_cycle2],  long int s, long int r) {  

long int pivot, i, f, t,t2;  
pivot = fin[1][s];  
i = s; f = r+1;  

while( 1)  
{  
do ++i; while( fin[1][i] <= pivot && i <= r );  
do --f; while( fin[1][f] > pivot );  
if( i >= f ) break;  
if (fin[1][i]!=fin[1][f])  
{ t = fin[0][i]; fin[0][i] = fin[0][f]; fin[0][f] = t;  
t2 = fin[1][i]; fin[1][i] = fin[1][f]; fin[1][f] = t2;  
}  
else {  
if (fin[0][i]<fin[0][f]) { t = fin[0][i]; fin[0][i] = fin[0][f]; fin[0][f] = t;  
t2 = fin[1][i]; fin[1][i] = fin[1][f]; fin[1][f] = t2;  
}   
}  

}  
if (fin[1][s]!=fin[1][f])  
{  
t = fin[0][s]; fin[0][s] = fin[0][f]; fin[0][f] = t;  
t2 = fin[1][s]; fin[1][s] = fin[1][f]; fin[1][f] = t2;  

}  
else { if (fin[0][s]<fin[0][f])  
{  
t = fin[0][s]; fin[0][s] = fin[0][f]; fin[0][f] = t;  
t2 = fin[1][s]; fin[1][s] = fin[1][f]; fin[1][f] = t2;  

}  

}  
return f;  
}  


long int minu(  long int a ,  long int b) {  
if (a>b) return a;  
else return b;  
}  
