#include<iostream>
#include<string>
using namespace std;
int main()
{
string  s1,s3;
char  s2[40];
cout<<"请输入任意三个姓名："<<endl;
getline(cin,s1); //可以含有空格字符
cin.getline(s2,40); //可以含有空格字符
cin>>s3;  // 不可以含有空格字符
cout<<"下面输出姓名："<<endl;
cout<<s1.size()<<endl;
cout<<s2<<endl;
cout<<s3<<endl;
}