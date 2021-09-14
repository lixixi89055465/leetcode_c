//
// Created by nanji on 9/14/21.
//
/**
 * Description

Tom是一个非常有创业精神的人，由于大学学的是汽车制造专业，所以毕业后他用有限的资金开了一家汽车零件加工厂，专门为汽车制造商制造零件。由于资金有限，他只能先购买一台加工机器。现在他却遇到了麻烦，多家汽车制造商需要他加工一些不同零件（由于厂家和零件不同，所以给的加工费也不同），而且不同厂家对于不同零件的加工时间要求不同（有些加工时间要求甚至是冲突的，但开始和结束时间相同不算冲突）。
　　Tom当然希望能把所有的零件都加工完，以得到更多的加工费，但当一些零件的加工时间要求有冲突时，在某个时间内
他只能选择某种零件加工（因为他只有一台机器），为了赚得尽量多的加工费，Tom不知如何进行取舍。
　　现在请你帮Tom设计一个程序，合理选择部分（或全部）零件进行加工，使得得到最大的加工费。

Input

第一行是一个整数n(n<=30000)，表示共有n个零件须加工。
接下来的n行中，每行有3个整数，分别表示每个零件加工的时间要求。
第一个表示开始时间，第二个表示该零件加工的结束时间，第三个表示加工该零件可以得到的加工费。
注：数据中的每个数值不会超过100000.

Output

输出一个整数，表示Tom可以得到的最大加工费。

Sample Input


3
1  3  10
4  6  20
2  5  25
Sample Output


30
 */
#include<iostream>
using namespace std;

struct node{
    int a,b,v;
}val[30010];
int dp[30010];
int n;
int cmp(const void *a,const void *b ){
    node *p1=(node*)a;
    node *p2=(node*)b;

    if(p1->b==p2->b){
        return p1->a>p2->a?1:-1;
    }

    return p1->b>p2->b?1:-1;
}
void solve(){
    int i,k;
    int ans;
    dp[1]=val[1].v;   ans=dp[1];
    for(i=2;i<=n;i++){
        dp[i]=val[i].v;
        for(k=1;k<i;k++){
            if(val[i].a>=val[k].b){
                if(dp[i]<dp[k]+val[i].v)
                    dp[i]=dp[k]+val[i].v;
            }
            else break;

        }
        if(dp[i]>ans)
            ans=dp[i];
    }
    cout<<ans<<endl;

}
//int main(){
//    int i;
//    int ans=0;
//
//    cin>>n;
//    for(i=1;i<=n;i++){
//        cin>>val[i].a>>val[i].b>>val[i].v;
//    }
//    qsort(val,n+1,sizeof(val[0]),cmp);
//
//    solve();
//
//    return 0;
//
//
//}
int main() {
    int n = 3;
    std::vector<std::vector<int>> nums;
    nums.push_back({1, 3, 10});
    nums.push_back({4, 6, 20});
    nums.push_back({2, 5, 25});
    printf("%d", nums[0][0]);
    return 0;
}

