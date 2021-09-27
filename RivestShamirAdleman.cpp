/*

Maitreya Kanitkar
BE-IT   8084

ICS Assignment 2 : RSA Algorithm

*/

#include<iostream>
#include<math.h>
using namespace std;

class rsa
{
    int p, q;
    long msg, encrypted, decrypted, enc;
    
    public:
    void pipeline()
    {
        input();
        algorithm();
        output();
    }

    void input()
    {
        cout<<"Enter the value of p : ";
        cin>>p;

        cout<<"Enter the value of q : ";
        cin>>q;

        cout<<"Enter the message : ";
        cin>>msg;
    }

    int gcd(int a, int b)
    {
        if(a==0)
        return b;
        return gcd(b%a, a);
    }

    void algorithm()
    {
        double n, phi, e=1, g, d1=1, d2;
        n=p*q;
        phi=(p-1)*(q-1);

        do
        {
            e++;
            g=gcd(e,phi);
        }
        while(e<phi && g!=1);

        d2=1/e;
        d1=fmod(d2, phi);

        encrypted=pow(msg, e);
        decrypted=pow(encrypted, d1);

        encrypted=fmod((encrypted), n);
        decrypted=fmod((decrypted), n);
    }

    void output()
    {
        cout<<endl<<"Original message : "<<msg;
        cout<<endl<<"Encrypted message : "<<encrypted;
        cout<<endl<<"Decrypted message : "<<decrypted;
    }
};

int main()
{
    rsa obj;
    obj.pipeline();
    return 0;
}



/*

OUTPUT:-

Enter the value of p : 3
Enter the value of q : 7
Enter the message : 12

Original message : 12
Encrypted message : 3
Decrypted message : 12

*/