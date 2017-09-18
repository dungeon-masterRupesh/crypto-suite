#include <iostream>     // std::cout
#include <cstddef>      // std::size_t
#include <cmath>        // std::sqrt(double)
#include <valarray>
using namespace std;

void modulo_addition(){
long long int a, b, c;
cout<<"MODULO ADDITION:"<<endl;
cout<<"\n";
cout<<"\t"<<"Enter the First no.(max 18 digits): ";
cin>>a;
cout<<endl;
cout<<"\t"<<"Enter the Second no.(max 18 digits): ";
cin>>b;
cout<<endl;
cout<<"\t"<<"Enter the Divisor(max 18 digits): ";
cin>>c;
cout<<endl;
long long int r=((a%c)+(b%c))%c;
cout<<"\t"<<"Your Modulo Addition Result: ";
cout<<"("<<a<<" + "<<b<<")"<<" % "<<c<<" = "<<r<<endl;
return;
}
void modulo_multiplication(){
long long int a, b, c;
cout<<"MODULO MULTIPLICATION:"<<endl;
cout<<"\n";
cout<<"\t"<<"Enter the First no.(max 9 digits): ";
cin>>a;
cout<<endl;
cout<<"\t"<<"Enter the Second no.(max 9 digits): ";
cin>>b;
cout<<endl;
cout<<"\t"<<"Enter the Divisor(max 9 digits): ";
cin>>c;
cout<<endl;
long long int r=((a%c)*(b%c))%c;
cout<<"\t"<<"Your Modulo Multiplication Result: ";
cout<<"("<<a<<" * "<<b<<")"<<" % "<<c<<" = "<<r<<endl;
return;
}
void modulo_exponentiation(){
long long int a, b, c;
cout<<"MODULO EXPONENTIATION:"<<endl;
cout<<"\n";
cout<<"\t"<<"Enter the Base(max 9 digits): ";
cin>>a;
cout<<endl;
cout<<"\t"<<"Enter the Exponent(max 9 digits): ";
cin>>b;
cout<<endl;
cout<<"\t"<<"Enter the Divisor(max 9 digits): ";
cin>>c;
cout<<endl;
long long int temp=a%c, result=1, sum=0, r=b;
    for(int i=0; i<b; i++){
        if(r%2==1){
            result=(result*temp)%c;
            sum=sum+pow(2,i);
            r=(r-1)/2;
        }
        else r=r/2;
        if(sum==b)
        break;
        temp=(temp*temp)%c;
    }
cout<<"\t"<<"Your Modulo Exponentiation Result: ";
cout<<"("<<a<<"^"<<b<<")"<<"%"<<c<<"="<<result<<endl;
return;
}
void gcd(){
int n;
cout<<"GREATEST COMMON DIVISOR:"<<endl;
cout<<"\n";
cout<<"\t"<<"Enter the no. of integers(N) for which Greatest Common Divisor is to be calculated: ";
cin>>n;
cout<<endl;
long long int num[n];
cout<<"\t"<<"Enter the "<<n<<" integers(max 15 digits) with spaces in between: ";
for(int i=0; i<n; i++){
    cin>>num[i];
}
cout<<endl;
for(int i=0; i<n; i++){
while(num[i]%num[0]!=0){
long long int r=num[i]%num[0];
num[i]=num[0];
num[0]=r;
}
}
cout<<"\t"<<"Greatest Common Divisor of the "<<n<<" integers is: "<<num[0]<<endl;
return;
}
long long int modulo_exponent(long long int a, long long int b, long long int c){
long long int temp=a%c, result=1, sum=0, r=b;
    for(int i=0; i<b; i++){
        if(r%2==1){
            result=(result*temp)%c;
            sum=sum+pow(2,i);
            r=(r-1)/2;
        }
        else r=r/2;
        if(sum==b)
        break;
        temp=(temp*temp)%c;
    }
return result;
}
long long int inv_mod(long long int a,long long int b){
    long long int c=b;
    long long int old_a=0 ,new_a=1,old_b=1,new_b=0;
    while(b%a!=0){
            long long int q=b/a,tempo=b%a,temp_b,temp_a ;
    temp_b=old_b-new_b*q;
    old_b=new_b;
    new_b=temp_b;
    temp_a=old_a-new_a*q;
    old_a=new_a;
    new_a=temp_a;
    b=a;
    a=tempo;

    }
    if(new_a<0)new_a=c+new_a;
    return new_a;

}
void inverse_modulation(){
    long long int aa,ab,ac;
    cout<<"INVERSE MODULATION OF FIRST NUMBER WITH RESPECT TO SECOND NUMBER(both numbers should be CO-PRIME to each other)"<<endl<<"\n";
    cout<<"Enter the first number (max. 18 digit)  ";
    cin>>aa;
    cout<<"\n";
    cout<<"Enter the second number (max. 18 digit)  ";
    cin>>ab;
    cout<<"\n";
    ac=inv_mod(aa,ab);
    cout<<"Your result is  "<<ac<<endl;
    return;
}
long long int bas=(7331*7321);
void rsa_key(){long long int key,prikey;
    cout<<"\n"<<"Welcome to RSA key generation centre"<<endl;
    cout<<"\n";
    cout<<"Enter the public key whose private key is to be issued ";cin>>key;cout<<endl;
    long long int secret=7330*7320;
    prikey=inv_mod(key,secret);
    cout<<"The private key is "<<prikey<<endl;
    return;

    }

void rsa_encrypt(){
    cout<<"RSA encyption"<<"\n";
    cout<<"\n"<<"For this project the value of modulo base for RSA is kept as "<<bas<<endl;
    cout<<"\n";
    long long int message,encrypt,key;
    cout<<"Enter the value of the public key ";
    cin>>key;cout<<endl;
    cout<<"Enter the number to be secured ";
    cin>>message;cout<<endl;
    encrypt=modulo_exponent(message,key,bas);
    cout<<"Your encrypted code is "<<encrypt<<endl;
    return;
}
void rsa_decrypt(){
        cout<<"RSA decryption"<<endl;
        long long int key, encrypt,message;
        cout<<"\n"<<"For this project the value of modulo base for RSA is kept as "<<bas<<endl;
        cout<<"\n";
        cout<<"Enter the private key ";
        cin>>key;cout<<"\n";
        cout<<"Enter the encypted code ";
        cin>>encrypt;cout<<endl;
        message=modulo_exponent(encrypt,key,bas);
        cout<<"Your decrypted message is "<<message<<endl;
        return;
}
void rsa_crypto(){
    cout<<"Welcome to RSA cryptographic world"<<endl;
    cout<<"\n";
    cout<<"Here we have tried to encrypt a number less than "<<bas<<endl;
    cout<<"\n";
    bool choice=true;int n;
   while(choice){ cout<<"Choose your option"<<endl;
    cout<<"\t"<<"1. RSA encyption"<<endl;
    cout<<"\t"<<"2. RSA decryption"<<endl;
    cout<<"\t"<<"3. RSA key generation (This function is password protected)"<<endl;
    cout<<"\n";
    cout<<"Enter your option ";
    cin>>n;cout<<"\n";
    if(n==1)rsa_encrypt();
    else if(n==2)rsa_decrypt();
    else if(n==3){string password;
        cout<<"Enter your password"<<endl;
        cin>>password;
        if(password=="cs101")rsa_key();
        else cout<<"Invalid password.... ";
    }
    else cout<<"Invalid choice";
    cout<<"\n"<<"Do you want to continue( enter '1' for YES and '0' for NO)"<<endl;
    cin>>choice;
    cout<<"\n";
   }
}
bool generate_check(long long int i,long long int n){
    long long int a=n-1,b=n-1,j=2,prfac[a],count=0;
    while(b!=1){
        if(b%j==0){
            prfac[count]=j;
            count++;
            while(b%j==0)b=b/j;

        }j++;
    }
    bool res=(modulo_exponent(i,a,n)==1);
    j=0;
    while (res){
        res=(res&&(modulo_exponent(i,a/prfac[j],n)!=1));
        if(j==count-1)break;
        else j++;
    }
    return res;
}

void dis_log(){
    cout<<"DISCRETE LOGARITHM:"<<endl;
    long long int R, a, c;
    cout<<"\n\t";
    cout<<"Remainder=(Base^discrete log) mod Divisor"<<endl;
    cout<<"\n";
    cout<<"\t"<<"Enter the Divisor: ";
    cin>>c;
    cout<<endl;
    cout<<"\t"<<"Enter the Base: ";
    cin>>a;
    cout<<endl;
    cout<<"\t"<<"Enter the Remainder(less than the divisor): ";
    cin>>R;
    cout<<endl;
    if (generate_check(a, c)){
    long long int m, result, b;
    m=sqrt(c)+1;
    long long int arr[m];
    b=inv_mod(modulo_exponent(a,m,c), c);
    for(long long int i=0; i<=m; i++){
        arr[i]=modulo_exponent(a, i, c);
    }
    long long int i, j, matc;
    for(i=0; i<=m; i++){
        matc = (R* modulo_exponent(b,i,c))%c;
        for(j=0; j<=m; j++){
            if(matc==arr[j])
                break;
        }
        if(((R%c)*modulo_exponent(b, m*i, c))%c==arr[j])
                break;
    }
    result=m*i+j;
    cout<<"the exponent is: "<<result<<endl;
    }
    else cout<<"It is not a generaror of the function"<<endl;
}

void gener(){long long int n;
    cout<<"Enter the prime number whose generators are to be found  ";
    cin>>n; cout<<endl;
    for(long long int a=2;a<n;a++){
        if(generate_check(a,n))cout<<a<<endl;
    }
}

int main()
{
    bool choice=true;
    while(choice){
    int n;
    cout<<"Choose what you want:"<<endl;
    cout<<"\t"<<"1.Modulo Addition"<<endl;
    cout<<"\t"<<"2.Modulo Multiplication"<<endl;
    cout<<"\t"<<"3.Modulo Exponentiation"<<endl;
    cout<<"\t"<<"4.Greatest Common Divisor of N integers"<<endl;
    cout<<"\t"<<"5.Inverse modulation "<<endl;
    cout<<"\t"<<"6.RSA cryptography "<<endl;
    cout<<"\t"<<"7.Discrete Logarithm"<<endl;
    cout<<"\t"<<"8.Generators of a prime number"<<endl;
    cout<<"\n";
    cout<<"Enter the no. corresponding to the above Functions: ";
    cin>>n;
    cout<<endl;
    cout<<"\n";
    if(n==1)
    modulo_addition();
    else if(n==2)
    modulo_multiplication();
    else if(n==3)
    modulo_exponentiation();
    else if(n==4)
    gcd();
    else if (n==5)inverse_modulation();
    else if (n==6)rsa_crypto();
    else if(n==7)dis_log();
    else if (n==8)gener();
    else
        cout<<"INVALID CHOICE"<<endl;
    cout<<"\n";
    cout<<"Do you want to continue?( enter '1' for 'YES' & '0' for 'NO'): ";
    cin>>choice;
    cout<<endl;
    }
    cout<<"\n"<<"\t"<<"\t"<<"BYE BYE";
    return 0;
}
