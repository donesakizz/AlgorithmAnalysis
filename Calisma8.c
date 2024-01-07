#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

int max(int num1, int num2);

int CUT_ROD(int p[],int n);
int BOTTOMUP_CUT_ROD(int p[], int n);

int main()
{
	int p[10] = {1,5,8,9,10,17,17,20,24,30}; // 10'dan büyük çubukların satış fiyatı 0.
	printf("Uzunlugu belirtiniz: ");
	int uzunluk;
	scanf("%d",&uzunluk);
	printf("Maksimum kazanc (Dynamic Programming): %d\n",BOTTOMUP_CUT_ROD(p,uzunluk));
	printf("Maksimum kazanc (CUT_ROD): %d\n",CUT_ROD(p,uzunluk));
	return 0;
}

int max(int num1,int num2)
{
	if(num1 >= num2)
		return num1;
	return num2;
}

int CUT_ROD(int p[],int n)
{
    if(n==0){
        return 0;
    }
    int i;
    int q =INT_MIN;
    int temp;
    for(i=1; i<=n; i++){
            if(i<=10)
            temp = p[i-1];
             else
                temp=0;
        q = max(q,temp+ CUT_ROD(p , n-i));
        //return q;
    }

	return q;
}

int BOTTOMUP_CUT_ROD(int p[], int n)
{
    int r[n+1];
    r[0]=0;
    int j,q,i,temp;

    for(j =1; j<=n ;j++){
        q = INT_MIN;

    for( i =1 ;i<=j ;i++)
        {

            if(i<=10)
            temp =p[i+1];
            else
                temp =0;
        q=max(q, temp +r[j-i]);
        }
        r[j]=q;
    }

	return r[n];
}
