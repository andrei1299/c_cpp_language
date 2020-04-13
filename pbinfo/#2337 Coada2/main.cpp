#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void reverse_func(char * x)
{
    int end_point = 0;
    while(x[end_point]!=NULL)
        end_point++;
    char aux;
    for(int i = 0;i<end_point/2;i++)
    {
        aux = x[i];
        x[i] = x[end_point-i-1];
        x[end_point-i-1] = aux;
    }
}

int length(char * x)
{
    int x_endpoint = 0;
    while(x[x_endpoint]!=NULL)
        x_endpoint++;
    return x_endpoint;
}

char * addition(char * x,char * y)
{
    int x_length = length(x);
    int y_length = length(y);
    int i;
    int overflow = 0;
    char * sum = (char*)malloc(20);
    int aux;
    for(i = 0;i<x_length && i<y_length;i++)
    {
        aux = (x[i]-'0') + (y[i]-'0') + overflow;
        overflow = aux/10;
        aux%=10;
        sum[i] = aux+'0';
    }
    while(i<x_length)
    {
        aux = (x[i]-'0') + overflow;
        overflow = aux/10;
        aux%=10;
        sum[i] = aux+'0';
        i++;
    }
    while(i<y_length)
    {
        aux = (y[i]-'0') + overflow;
        overflow = aux/10;
        aux%=10;
        sum[i] = aux+'0';
        i++;
    }
    if(overflow == 1)
    {
        sum[i] = '1';
        i++;
    }
    sum[i] = NULL;
    return sum;
}

bool can_sub(char * x, char * y)
{
    int x_len = length(x);
    int y_len = length(y);
    if(x_len < y_len)
        return 0;
    if(x_len > y_len)
        return 1;
    for(int i = x_len-1;i>=0;i--)
    {
        if(x[i]<y[i])
            return 0;
        if(x[i]>y[i])
            return 1;
    }
    return 1;
}

char * substraction(char * x,char * y)
{
    char * sub;
    sub = (char*)malloc(20);
    if(can_sub(x,y))
    {
        for(int i = 0;i<length(x);i++)
            sub[i] = x[i];
        int y_len = length(y);
        int aux;
        for(int i = 0;i<y_len;i++)
        {
            aux = (sub[i]-'0') - (y[i]-'0');
            if(aux < 0)
            {
                int index = i+1;
                while(!(sub[index]-'0'>0))
                    index++;
                sub[index] = sub[index]-1;
                aux+=10;
            }
            sub[i] = aux+'0';
        }
        int i=length(x)-1;
        while(sub[i]=='0')
            i--;
        sub[i+1] = NULL;
    }
    else
        sub[0] = 'X';
    return sub;
}

int main()
{
    ifstream fin("coada2.in");
    ofstream fout("coada2.out");

    char x[20],y[20],z[20];
    fin>>x>>y>>z;
    reverse_func(x);
    reverse_func(y);
    reverse_func(z);
    //cout<<x<<" "<<y<<" "<<z;
    char *raspuns;
    raspuns = addition(y,z);
    reverse_func(raspuns);
    raspuns = substraction(x,y);
    char * aux1;
    aux1 = substraction(y,x);
    char * aux2;
    aux2 = substraction(z,x);
    if(aux1[0]=='X' || aux2[0]=='X')
        cout<<"-1";
    else
    {
        aux1 = addition(y,z);
        aux2 = substraction(aux1,x);
        reverse_func(aux2);
        fout<<aux2;
    }
    //raspuns =

    fin.close();
    fout.close();
    return 0;
}
