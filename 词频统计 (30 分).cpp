#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> words;
int wordNum=0;
void pushMap(string &word,int &connectNum)
{
	if(words[word]==0)
	{
		wordNum++;
		words[word]=1;
	}
	else
		words[word]++;
	word="";
	connectNum=0; 
}
int main()
{
	string str,word;
	int connectNum=0,cutNum=0;
	bool flag=false;//是否输入结束 
	while(cin>>str)
	{
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='#')
			{
				//要将最后一个word存入map 
				if(i==str.length()-1&&connectNum>0)
				{
					pushMap(word,connectNum);
				}
				printf("%d\n",wordNum); 
				int printNum=wordNum/10;
				for(int j=0;j<printNum;j++)
				{
					int maxNum=0;
					string maxStr;
					for(map<string,int>::iterator it=words.begin();it!=words.end();it++)
					{
						if(it->second>maxNum)
						{
							maxNum=it->second;
							maxStr=it->first;
						}
					}
					cout<<maxNum<<':'<<maxStr<<endl;
					words.erase(maxStr);
				}
				
				return 0;
			}
			if(connectNum==15)
			{
				pushMap(word,connectNum);
				break;
			}
			if(str[i]>='A'&&str[i]<='Z')
			{
				word+=str[i]+32;
				connectNum++;
			}
			else if(str[i]>='a'&&str[i]<='z'||str[i]>='0'&&str[i]<='9'||str[i]=='_')
			{
				word+=str[i];
				connectNum++;
			}
			else
			{
				if(connectNum>0)
				{
					pushMap(word,connectNum);
					continue; 
				}	
			}	
			if(i==str.length()-1&&connectNum>0)
			{
				pushMap(word,connectNum);
			}
		}
	}
	return 0;
}

