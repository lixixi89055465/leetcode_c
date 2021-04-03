//
// Created by nanji on 4/3/21.
/**
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

 

示例 1：

输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace" ，它的长度为 3 。
示例 2：

输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。
示例 3：

输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
//
#include "string"
#include "vector"

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int len1 = text1.size(), len2 = text2.size(), i = 0, j = 0;
        std::vector<std::vector<int>> dy;
        for (i = 0; i < len1+1; i++) {
            std::vector<int> tmp;
            dy.push_back(tmp);
            for (j = 0; j < len2+1; j++) {
                dy[i].push_back(0);
            }
        }
        for (i = 1; i < len1 + 1; i++) {
            for (j = 1; j < len2 + 1; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dy[i][j] = dy[i - 1][j - 1] + 1;
                } else {
                    dy[i][j] = std::max(dy[i - 1][j], dy[i][j - 1]);
                }
            }
        }
        return dy[len1][len2];
    }
};

int main() {
    Solution solve;
    int result = solve.longestCommonSubsequence("abc", "bec");
    printf("%d\n", result);
    return 0;
}
