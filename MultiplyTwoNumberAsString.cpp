/*
Problem Statement-
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

void multiplyString(string a,int l1,string b,int l2,vector<int> &res,int n){
        int index,carry,mul,k=0;
        for(int i=l2;i>=0;i--){
            index=n-k;
            carry=0;
            for(int j=l1;j>=0;j--){
                mul=(b[i]-'0')*(a[j]-'0')+carry+res[index];
                carry=mul/10;
                mul=mul%10;
                res[index]=mul;
                index--;
            }
            if(carry>0)
                res[index]=carry;
            k++;
        }
    }
    string multiply(string num1, string num2) {
        int l1=num1.size(),l2=num2.size();
        int n=l1+l2+1;
        if((l1==1 && num1[0]=='0') || (l2==1 && num2[0]=='0'))
            return "0";
        vector<int> res(n,0);        
        string s="";
        if(l1==0 || l2==0)
            return s;
        if(l2<l1)
            multiplyString(num1,l1-1,num2,l2-1,res,n-1);
        else
            multiplyString(num2,l2-1,num1,l1-1,res,n-1);
        bool start=true;
        for(int i=0;i<n;i++){
            if(res[i]==0 && start)
                continue;
            else{
                start=false;
                s+=to_string(res[i]);
            }
        }
        return s;
    }
