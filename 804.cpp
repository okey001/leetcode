#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
int uniqueMorseRepresentations(char words[100][14], int wordsSize) {
    int i,j,len[26],f[26],ans=0;
    long long *anslist,t;
    char list[26][5]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    for(i=0;i<26;i++)
    {
        f[i]=0;
        len[i]=strlen(list[i]);
        for(j=0;j<len[i];j++)
        {
            f[i]=f[i]<<1;
            if(list[i][j]=='.')f[i]+=1;
        }
    }




    anslist=(long long*)malloc(sizeof(long long)*wordsSize);



    for(i=0;i<wordsSize;i++)
    {
        t=0;
        printf("%s ",words[i]);
        for(j=0;j<strlen(words[i]);j++)
        {
            t<<=len[words[i][j]-'a'];
            t+=f[words[i][j]-'a'];

        }
        anslist[i]=t;

    }



    for(i=0;i<wordsSize;i++)
        for(j=0;j<wordsSize;j++)
            if(anslist[i]<anslist[j]){
                t=anslist[i];
                anslist[i]=anslist[j];
                anslist[j]=t;
            }
    ans=0;
    for(i=0;i<wordsSize;i++)
    {
        if(i==0 || anslist[i-1]!=anslist[i])
            ans++;
    }
    return ans;
}
int main()
{
    int i,ans,n;
    char words[100][14];
    scanf("%d",&n);
    gets(words[0]);
    for(i=0;i<n;i++)
    {
        gets(words[i]);

    }
    ans=uniqueMorseRepresentations(words,n);
    printf("%d",ans);
}
