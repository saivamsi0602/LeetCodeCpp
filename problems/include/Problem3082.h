#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod = 7+(1e9);
        vector<vector<vector<long long>>> memo(n,vector<vector<long long>>(1+n,vector<long long>(k+1,-1)));

        function<long long(int,int,int)> dp = [&](int index, int len, int total)->long long{
            if(total==0) return len==0?1:0;
            if(index<0 || len<0 || total<0) return 0;
            if(memo[index][len][total]!=-1) return memo[index][len][total];
            long long res = (dp(index-1,len-1,total-nums[index])+dp(index-1,len,total))%mod;
            return memo[index][len][total]=res;
        };
        for(int len=n;len>0;len--)
            dp(n-1,len,k);
        long long res = 0;

        for(int len=1;len<=n;len++){
            int rem = n-len;
            long long a = 2, p=1;
            while (rem)
            {
                if(rem&1) p = (p*a)%mod;
                a = (a*a)%mod;
                rem>>=1;
            }
            res = (res+memo[n-1][len][k]*p)%mod;
        }
        return res;
    }
};