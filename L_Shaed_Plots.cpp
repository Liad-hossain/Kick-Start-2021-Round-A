//Author:Md. Liad Hossain
//KUET ECE 2K18

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define lld long long int
#define ulld unsigned long long int
#define vl vector<lld>
#define vll vector<pair<lld, lld>>
#define ff first
#define ss second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define pof pop_front
#define pob pop_back
#define fbo find_by_order
#define ofk order_of_key
#define fo(i, a, b) for (lld i = a; i <= b; i++)
#define FOR(i, n) for (lld i = 0; i < n; i++)
#define F0R(j, n) for (lld j = 1; j <= n; j++)
#define ROF(i, n) for (lld i = n - 1; i >= 0; i--)
#define R0F(i, n) for (lld i = n; i >= 1; i--)
#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define rs random_shuffle
#define yes printf("YES\n")
#define no printf("NO\n")
#define mod 1000000007LL
#define setbit __builtin_popcount
#define elif else if
#define mem(a) memset(a,0,sizeof(a));
#define pi 2 * acos(0.0)
#define inf 9000000000000000000LL
#define T            \
    int t;           \
    scanf("%d", &t); \
    while (t--)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void read(int &x)
{
    scanf("%d", &x);
}
void read(lld &x)
{
    scanf("%I64d", &x);
}
void read(lld &a, lld &b)
{
    scanf("%I64d %I64d", &a, &b);
}
void read(lld &a, lld &b, lld &c)
{
    scanf("%I64d %I64d %I64d", &a, &b, &c);
}
void read(lld &a, lld &b, lld &c, lld &d)
{
    scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
}
void read(double &x)
{
    scanf("%lf", &x);
}
void read(char &x)
{
    scanf("%s", x);
}
void read(string &x)
{
    char y[1000006];
    scanf("%s", &y);
    x = y;
}
 
void print(lld x, bool flag = false)
{
    if (flag)
        printf("%I64d ", x);
    else
        printf("%I64d\n", x);
}
void print(int x, bool flag = false)
{
    if (flag)
        printf("%d ", x);
    else
        printf("%d\n", x);
}
void print(double x, bool flag = false)
{
    if (flag)
        printf("%0.14lf ", x);
    else
        printf("%0.14lf\n", x);
}
void print(char x)
{
    printf("%c\n", x);
}
 
void print(string x)
{
    for (lld i = 0; i < x.size(); i++)
    {
        printf("%c", x[i]);
    }
    printf("\n");
}
//knight moves...
//lld dx[]={-1,-2,-2,-1,1,2,2,1};
//lld dy[]={-2,-1,1,2,2,1,-1,-2};
const lld mx=1001;
lld grid[1001][1001];
lld upp[mx][mx],downn[mx][mx],leftt[mx][mx],rightt[mx][mx];

void getdown(lld r,lld c,lld pos1,lld pos2)
{
    if(grid[pos1][pos2]==0)
    {
        downn[pos1][pos2]=0;
        return;
    }

    if(downn[pos1][pos2]==0)
    {
        lld cnt=0;
        while(pos1>0)
        {
            if(grid[pos1][pos2]==0)break;
            cnt++;
            downn[pos1][pos2]=cnt;
            pos1--;
        }
    }
}

void getleft(lld r,lld c,lld pos1,lld pos2)
{
    if(grid[pos1][pos2]==0)
    {
        leftt[pos1][pos2]=0;
        return;
    }

    if(leftt[pos1][pos2]==0)
    {
        lld cnt=0;
        while(pos2<=c)
        {
            if(grid[pos1][pos2]==0)break;
            cnt++;
            leftt[pos1][pos2]=cnt;
            pos2++;
        }
    }
}

void getright(lld r,lld c,lld pos1,lld pos2)
{
    if(grid[pos1][pos2]==0)
    {
        rightt[pos1][pos2]=0;
        return;
    }

    if(rightt[pos1][pos2]==0)
    {
        lld cnt=0;
        while(pos2>0)
        {
            if(grid[pos1][pos2]==0)break;
            rightt[pos1][pos2]=++cnt;
            pos2--;
        }
    }
}


lld getval(lld lo,lld hi,lld reach)
{
    lld ans=-1;
    while(lo<=hi)
    {
        lld mid=(lo+hi)/2;
        if(mid*2<=reach)
        {
            ans=mid;
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }

    return ans;
}

int main()
{
/*#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif*/
lld test=0;
    T
    {
        mem(upp);
        mem(downn);
        mem(leftt);
        mem(rightt);
        lld r,c;
        cin>>r>>c;
        F0R(i,r)
        {
            F0R(j,c)
            {
                cin>>grid[i][j];
            }
        }   
        F0R(i,r)
        {
            F0R(j,c)
            {
                getleft(r,c,i,j);
                if(grid[i][j]==0)upp[i][j]=0;
                else
                {
                    if(upp[i][j]==0)
                    {
                        lld pos1=i,pos2=j;
                        lld cnt=0;
                        while(pos1<=r && grid[pos1][pos2]==1)
                        {
                            cnt++;
                            upp[pos1][pos2]=cnt;
                            pos1++;
                        }
                    }
                }
            }
        }

        for(lld i=r;i>0;i--)
        {
            for(lld j=c;j>0;j--)
            {
                getdown(r,c,i,j);
                getright(r,c,i,j);
            }
        }


        lld anser=0;
        F0R(i,r)
        {
            F0R(j,c)
            {
                lld ans=0;
                lld val1=upp[i][j];
                lld val2=downn[i][j];
                lld val3=leftt[i][j];
                lld val4=rightt[i][j];
                //cout<<val1<<" "<<val2<<" "<<val3<<" "<<val4<<endl;
                if(val3>=2)
                {
                    lld tmp=getval(2,val3,val1);
                    if(tmp!=-1)ans+=(tmp-1);
                    tmp=getval(2,val3,val2);
                    if(tmp!=-1)ans+=(tmp-1);
                }

                if(val4>=2)
                {
                    lld tmp=getval(2,val4,val1);
                    if(tmp!=-1)ans+=(tmp-1);
                    tmp=getval(2,val4,val2);
                    if(tmp!=-1)ans+=(tmp-1);
                }
                
                if(val1>=2)
                {
                    lld tmp=getval(2,val1,val3);
                    if(tmp!=-1)ans+=(tmp-1);
                    tmp=getval(2,val1,val4);
                    if(tmp!=-1)ans+=(tmp-1);
                }

                if(val2>=2)
                {
                    lld tmp=getval(2,val2,val3);
                    if(tmp!=-1)ans+=(tmp-1);
                    tmp=getval(2,val2,val4);
                    if(tmp!=-1)ans+=(tmp-1);
                }

                //cout<<ans<<" ";
                anser+=ans;
            }
            //cout<<endl;
            
        }
        cout<<"Case #"<<++test<<": "<<anser<<endl;
    }
    cerr << "time taken : " << (float)clock() / (float)CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
