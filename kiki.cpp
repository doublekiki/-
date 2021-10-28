#include <bits/stdc++.h>
using namespace std;
int pc[41][11];
int pcn[11][41];
void init()
{
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=40;j++)
		{
			pcn[i][j]=j;
		}
	}
}
struct information
{
    int a[11];
    int bt[11]={};
    string name;
	int num; 
}s[41];
int maxt[11]={0},maxn[11]={},maxts[11]={},maxns[11]={};
int main()
{
    for(int i=1;i<=40;i++)
    {
        for(int j=1;j<=10;j++)
        {
        	//printf("请你输入第%d个要投的星\n",j);
            cin>>s[i].a[j];
            s[s[i].a[j]].bt[j]++;
        }
    }
    for(int i=1;i<=10;i++)
    {
    	maxn[i]=maxt[i]=maxts[i]=maxns[i]=-100;
    }
    for(int i=1;i<=40;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(s[i].bt[j]>maxt[j]&&i!=0)
            {
            	maxts[j]=maxt[j];
            	maxns[j]=maxn[j];
                maxt[j]=s[i].bt[j];
                maxn[j]=i;
            }
        }
    }
    
    for(int i=1;i<=10;i++)
    {
        cout<<maxn[i]<<" "<<maxns[i]<<endl;
        for(int j=1;j<=40;j++)
        {
        	pc[j][i]=s[j].bt[i]; 
		}
        /*
        freopen("tpjg.txt","w",stdout);
        for(int i=1;i<=40;i++)
        {
        	pc1[i]=s[i].bt[1];
        	pc2[i]=s[i].bt[2];
        	pc3[i]=s[i].bt[3];
        	pc4[i]=s[i].bt[4];
        	pc5[i]=s[i].bt[5];
        	pc6[i]=s[i].bt[6];
        	pc7[i]=s[i].bt[7];
        	pc8[i]=s[i].bt[8];
        	pc9[i]=s[i].bt[9];
        	pc10[i]=s[i].bt[10];
		}
		sort(pc1+1,pc1+41);
		sort(pc2+1,pc2+41);
		sort(pc3+1,pc3+41);
		sort(pc4+1,pc4+41);
		sort(pc5+1,pc5+41);
		sort(pc6+1,pc6+41);
		sort(pc7+1,pc7+41);
		sort(pc8+1,pc8+41);
		sort(pc9+1,pc9+41);
		sort(pc10+1,pc10+41);
		*/
    }
    /*
    for(int i=1;i<=40;i++)
    {
    	cout<<pc1[i]<<" "
    	<<pc2[i]<<" "
    	<<pc3[i]<<" "
    	<<pc4[i]<<" "
    	<<pc5[i]<<" "
    	<<pc6[i]<<" "
    	<<pc7[i]<<" "
    	<<pc8[i]<<" "
    	<<pc9[i]<<" "
    	<<pc10[i]<<endl; 
    	
	}
	*/
	init(); 
	for(int i=1;i<=40;i++)
	{
		for(int j=1;j<=10;j++)
		{
			for(int k=2;k<=10;k++)
			{
				if(pc[i][k]>pc[i][k-1])
				{
					int ls=pc[i][k-1];
					pc[i][k-1]=pc[i][k];
					pc[i][k]=ls;
					ls=pcn[i][k-1];
					pcn[i][k-1]=pcn[i][k];
					pcn[i][k]=ls;
				}
			}
		} 
	}
	freopen("tpjg.txt","w",stdout);
	for(int i=1;i<=40;i++)
	{
		for(int j=1;j<=10;j++)
		{
			cout<<pc[i][j]<<" "<<pcn[j][i]<<"		";
		}
		cout<<endl;
	}
}
