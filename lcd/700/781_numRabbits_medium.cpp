//
// Created by nanji on 4/4/21.
//
/**
 * 森林中，每个兔子都有颜色。其中一些兔子（可能是全部）告诉你还有多少其他的兔子和自己有相同的颜色。我们将这些回答放在 answers 数组里。

返回森林中兔子的最少数量。
示例:
输入: answers = [1, 1, 2]
输出: 5
解释:
两只回答了 "1" 的兔子可能有相同的颜色，设为红色。
之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
设回答了 "2" 的兔子为蓝色。
此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。
因此森林中兔子的最少数量是 5: 3 只回答的和 2 只没有回答的。

输入: answers = [10, 10, 10]
输出: 11

输入: answers = []
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rabbits-in-forest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */
#include "vector"
#include "map"

class Solution {
public:
    int numRabbits(std::vector<int> &answers) {
        std::map<int, int> count;
        for (int y : answers) {
            ++count[y];
        }
        int ans = 0;
        for (auto &[y, x] : count) {
            ans += (x + y) / (y + 1) * (y + 1);
        }
        return ans;
    }
};


int main() {
    Solution solve;
//    std::vector<int> vec = {1, 1, 2};
//    std::vector<int> vec = {10, 10, 10};
//    std::vector<int> vec = {1, 0, 1, 0, 0};
    std::vector<int> vec = {0, 1, 0, 2, 0, 1, 0, 2, 1, 1};
    int result = solve.numRabbits(vec);
    printf("%d\n", result);
    return 0;
}
