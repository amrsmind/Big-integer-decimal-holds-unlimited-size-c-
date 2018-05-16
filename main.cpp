#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ostream>
#include <cstdlib>

using namespace std;

class BigDecimalInt{
private:
    string bigint;
public:
    //default constructor

    BigDecimalInt(){
    bigint = "";
    }
    //take string input constructor

    BigDecimalInt(string decStr){
        //making sure that the use enters only numbers
        int decStrstize = decStr.size();
        int counter = 0;
        for (int i=0;i<decStrstize;i++){
        if(((decStr[i]<='9' && decStr[i]>='0' ) || decStr[0]=='-')){
            counter++;
            //cout <<"true"<<endl;
            }
        else {break;}
            }
        if(counter == decStrstize){
            bigint = decStr;
        }
        else{
        cout <<"your input is wrong"<<endl;
        exit(0);
        }}
        //take int input constructor
    BigDecimalInt(int decInt){
         stringstream ss;
         ss << decInt;
         bigint = ss.str();
    }
    int size(){
    return bigint.size();
    }
////////////////////////////////////////////////////////////////////////
/////addition function //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

    string bignumber(string s1,string s2){
        //putting zeros at the shorter number

        int s1size = s1.size();
        int s2size = s2.size();
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
//        if (s1[s1size-1] == '-') cout <<"yarb"<<endl;s1.pop_back();cout <<"";cout <<s1<<endl;subtractbignumber(s2,s1);
if(s1[s1size-1] == '-' && s2[s2size-1] == '-'){

    s1.pop_back();
    s2.pop_back();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    string temp1 = bignumber(s1,s2);
    reverse(temp1.begin(),temp1.end());
    temp1 +='-';
    reverse(temp1.begin(),temp1.end());
    return temp1;
}
            else if (s1[s1size-1] == '-'){
                        s1.pop_back();
                        reverse(s1.begin(),s1.end());
                        reverse(s2.begin(),s2.end());
//                        cout <<"s1 : "<<s1<<endl;
                        return subtractbignumber(s2,s1);}

        else if((s2[s2size-1] == '-')){
            s2.pop_back();
            reverse(s1.begin(),s1.end());
            reverse(s2.begin(),s2.end());
            return subtractbignumber(s1,s2);
            }
        else{
        if (s1size>s2size){
          int numzeros = s1size - s2size;
          while(numzeros!=0){
            s2.push_back('0');
            numzeros--;}
          s2size = s1size;}

        else if(s2size>s1size){
            int numzeros = s2size-s1size;
            while (numzeros!=0){
                s1.push_back('0');
                numzeros--;}
            s1size = s2size;}
          /////////////
          //ready to add
string sum = "";
int carry = 0;
int num;
for(int i=0;i<s1size;i++){
    num = ((s1[i] - '0') + (s2[i] - '0') + carry);
    //cout <<"num " <<num<<endl;
    sum.push_back(num%10+'0');
    carry = num/10;
    //cout <<i<<"    "<<carry<<endl;
    //cout <<"sum string : "<<sum<<endl;
}
if (carry){
    sum.push_back(carry+'0');
    //cout <<"carry t7t "<<carry<<endl;
  //  cout <<"sum string t7t "<<sum<<endl;

}
reverse(sum.begin(),sum.end());

return sum;}
}
////////////////////////////////////////////////////////////////////////
/////subtraction function //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
string subtractbignumber(string s1,string s2){
        //putting zeros at the shorter number
        int s1size = s1.size();
        int s2size = s2.size();
        //cout <<"s1size : "<<s1size<<"s2size : "<<s2size<<endl;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());

        if(s1[s1size-1] == '-' && s2[s2size-1] == '-'){

    s1.pop_back();
    s2.pop_back();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    return subtractbignumber(s2,s1);
}
        else if(s1[s1size-1]=='-'){
           s1.pop_back();
           reverse(s1.begin(),s1.end());
           reverse(s2.begin(),s2.end());
           string temp = bignumber(s1,s2);
           reverse(temp.begin(),temp.end());
           temp +='-';
           reverse(temp.begin(),temp.end());
           return temp;
        }
        else if(s2[s1size-1]=='-'){
           s2.pop_back();
           reverse(s1.begin(),s1.end());
           reverse(s2.begin(),s2.end());
           return bignumber(s1,s2);

        }
        else{
//        cout <<"s1 : "<<s1<<"s2 : "<<s2<<endl;
        if (s1size>s2size){
          int numzeros = s1size - s2size;
          while(numzeros!=0){
            s2.push_back('0');
            numzeros--;}
          s2size = s1size;}

        else if(s2size>s1size){
            int numzeros = s2size-s1size;
            while (numzeros!=0){
                s1.push_back('0');
                numzeros--;}
            s1size = s2size;}
          /////////////
          //ready to subtract

//cout <<"s1 : "<<s1<<"s2 :  "<<s2<<endl;
if (s1[s1size-1] >= s2[s1size-1]){
        string subtr = "";
string negative = "";
int fornextstate = 0;
int num;
for(int i=0;i<s1size-1;i++){
        if(((s1[i]-'0')-fornextstate)>=(s2[i]-'0')){
    num = ((s1[i] - '0') - fornextstate) - (s2[i] - '0');
    //cout <<"num " <<num<<endl;
    subtr.push_back(num+'0');
    fornextstate = 0;
        }
        else if(((s1[i]-'0')-fornextstate)<(s2[i]-'0')){
            num = (((s1[i] - '0') - fornextstate +10) - (s2[i] - '0'));
            subtr.push_back(num+'0');
            //cout <<"num : "<<num<<endl;
            fornextstate = 1;
        }
    //cout <<i<<"    "<<carry<<endl;
    //cout <<"subtr string : "<<subtr<<endl;
}
if(((s1[s1size-1]-'0')-fornextstate)>=(s2[s1size-1]-'0')){
         num = ((s1[s1size-1] - '0') - fornextstate) - (s2[s1size-1] - '0');
    //cout <<"num " <<num<<endl;
    subtr.push_back(num+'0');
    fornextstate = 0;
    reverse(subtr.begin(),subtr.end());


}
else if(((s1[s1size-1]-'0')-fornextstate)<(s2[s1size-1]-'0')){
    num = (s2[s1size-1] - '0') - ((s1[s1size-1] - '0') - fornextstate);
    subtr.push_back(num+'0');
    subtr += '-';
    reverse(subtr.begin(),subtr.end());
}
//cout <<"subtr : "<<subtr<<endl;
return subtr;}
else{
    string subtr = "";
string negative = "";
int fornextstate = 0;
int num;
string temp;
temp = s1;
s1 = s2;
s2 = temp;
for(int i=0;i<s1size-1;i++){
        if(((s1[i]-'0')-fornextstate)>=(s2[i]-'0')){
    num = ((s1[i] - '0') - fornextstate) - (s2[i] - '0');
    //cout <<"num " <<num<<endl;
    subtr.push_back(num+'0');
    fornextstate = 0;
        }
        else if(((s1[i]-'0')-fornextstate)<(s2[i]-'0')){
            num = (((s1[i] - '0') - fornextstate +10) - (s2[i] - '0'));
            subtr.push_back(num+'0');
            //cout <<"num : "<<num<<endl;
            fornextstate = 1;
        }
    //cout <<i<<"    "<<carry<<endl;
    //cout <<"subtr string : "<<subtr<<endl;
}
if(((s1[s1size-1]-'0')-fornextstate)>=(s2[s1size-1]-'0')){
         num = ((s1[s1size-1] - '0') - fornextstate) - (s2[s1size-1] - '0');
    //cout <<"num " <<num<<endl;
    subtr.push_back(num+'0');
    fornextstate = 0;
    subtr+= '-';
    reverse(subtr.begin(),subtr.end());


}
else if(((s1[s1size-1]-'0')-fornextstate)<(s2[s1size-1]-'0')){
    num = (s2[s1size-1] - '0') - ((s1[s1size-1] - '0') - fornextstate);
    subtr.push_back(num+'0');
    subtr += '-';
    reverse(subtr.begin(),subtr.end());
}


return subtr;


}
}}
////////////////////////////////////////////////////////////////////////
/////end of subtraction function //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

////operators////

BigDecimalInt operator+(const BigDecimalInt &bo){
BigDecimalInt result;
result.bigint = bignumber(bigint,bo.bigint);
return result;
}
BigDecimalInt operator-(const BigDecimalInt &temp){
BigDecimalInt result;
result.bigint = subtractbignumber(bigint,temp.bigint);
return result;
}

/*
string operator+(BigDecimalInt bo){

return bignumber(bigint,bo.bigint);

}*/

BigDecimalInt operator=(const BigDecimalInt &bo){
bigint = bo.bigint;
return *this;
}


friend ostream& operator<<(ostream &os,const BigDecimalInt &bo){
os<<bo.bigint;
return os;
}
};


int main()
{
    //BigDecimalInt num("6");
    BigDecimalInt num1("1213215315314978");
    BigDecimalInt num2("31399999910");
    BigDecimalInt n1("-3");
    BigDecimalInt n2("-10");
    BigDecimalInt n3("100");
    BigDecimalInt num3 = num1+num2;
    BigDecimalInt result1 = n1 + n2;
    cout <<num3<<endl;
    cout <<result1<<endl;
    //cout <<num3<<endl;
    BigDecimalInt num4 = num2-num1;
    cout <<num4<<endl;
    cout <<n1-n2<<endl;
    cout <<n1+n2<<endl;
    cout <<n2-n1<<endl;

    return 0;
}
