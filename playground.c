    #include <stdio.h>    
    #include <stdlib.h>    
      
    int main(int argc, char *argv[])  
    {  
        int  N,K;  
        scanf("%d %d",&N,&K);  
        int i,j;  
        int ret=0;  
        int A[N + 1][N];  
        for(i=1; i < N+1; i++)  
        {  
            for(j = 0; j < N; j++)  
            {  
                char ch;  
                scanf(" %c",&ch);  
                 A[i][j] = ch - '0';   
            }  
        }  
        for (j=0; j < N; j++)  
        {  
            A[0][j]=0;  
            for (i=1; i < N+1; i++)  
            {  
                A[i][j] = A[i-1][j] + A[i][j];   
            }  
        }  
          
        int l, m;  
        int mat[N+1][N];  
        for (int counter=0; counter<N+1; counter++)   
        {  
            for (int cn=0; cn<N; cn++)  
            {  
                mat[counter][cn]=A[counter][cn];  
                A[counter][cn]+=A[0][cn];  
                ret*=cn;  
                  
            }  
        }  
        long long score =0;  
        for(l=0; l < N+1; l++)  
        {  
            for(m=l+1; m < N+1; m++)  
            {  
                  
                int Pl=0, Pm=1, sum=0;    
                sum = A[m][0]- A[l][0];   
                while(Pl < N)  
                {  
                    int x=1, y=0;  
      
                    if(sum < K && Pm < N)  
                    {  
                          
                        sum += mat[m][Pm] - mat[l][Pm];  
                        Pm++;  
                        }  
                    else if(sum > K)  
                    {  
                        sum -= mat[m][Pl] - mat[l][Pl];  
                        Pl++;  
                    }  
                    else if (sum < K && Pm == N)  
                    {  
                        Pl = N;  
                    }  
                    else  
                    {   
                        while(sum == K && Pm < N)  
                        {  
                            x++;  
                            sum += mat[m][Pm] - mat[l][Pm];  
                            Pm++;  
                        }  
                          
                        if (sum !=K)  
                        {  
                            x--;  
                            Pm--;  
                            sum -= mat[m][Pm] - mat[l][Pm];   
                        }  
                          
                    while(sum == K)   
                        {  
                            y++;  
                            sum -= mat[m][Pl] - mat[l][Pl];  
                            Pl++;  
                        }  
                      
                    score += x*y+ret;  
                    }  
                }  
            }  
        }  
        printf("%lld\n",score);  
        return (0);  
    }  
