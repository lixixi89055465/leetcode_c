//
// Created by nanji on 4/16/21.
//
/**
 *
 * 87. 扰乱字符串
使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
如果字符串的长度为 1 ，算法停止
如果字符串的长度 > 1 ，执行下述步骤：
在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。

示例 1：

输入：s1 = "great", s2 = "rgeat"
输出：true
解释：s1 上可能发生的一种情形是：
"great" --> "gr/eat" // 在一个随机下标处分割得到两个子字符串
"gr/eat" --> "gr/eat" // 随机决定：「保持这两个子字符串的顺序不变」
"gr/eat" --> "g/r / e/at" // 在子字符串上递归执行此算法。两个子字符串分别在随机下标处进行一轮分割
"g/r / e/at" --> "r/g / e/at" // 随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
"r/g / e/at" --> "r/g / e/ a/t" // 继续递归执行此算法，将 "at" 分割得到 "a/t"
"r/g / e/ a/t" --> "r/g / e/ a/t" // 随机决定：「保持这两个子字符串的顺序不变」
算法终止，结果字符串和 s2 相同，都是 "rgeat"
这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1 的扰乱字符串，返回 true
示例 2：

输入：s1 = "abcde", s2 = "caebd"
输出：false
示例 3：

输入：s1 = "a", s2 = "a"
输出：true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/scramble-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include "string"
#include "vector"

class Solution {
public:
    //输入：s1 = "great", s2 = "rgeat"
    bool isScramble(std::string s1, std::string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        std::string tmp1 = s1, tmp2 = s2;
        std::sort(tmp1.begin(), tmp1.end());
        std::sort(tmp2.begin(), tmp2.end());
        if (tmp1 != tmp2) {
            return false;
        }
        if (tmp1.length() == 1 || tmp1.length() == 2) {
            return true;
        }
        for (int i = 1; i < s1.length(); i++) {
            std::string tmp1_1 = s1.substr(0, i),
                    tmp1_2 = s1.substr(i, s1.length() - i),
                    tmp2_1 = s2.substr(0, i),
                    tmp2_2 = s2.substr(i, s1.length() - i);
//            if (i == 6 && s1.length() == 12) {
//                printf("aa");
//            }
            if (isScramble(tmp1_1, tmp2_1) && isScramble(tmp1_2, tmp2_2)) {
                return true;
            }
//            if (isScramble(tmp1_1, tmp2_2) && isScramble(tmp1_2, tmp2_1)) {
//                return true;
//            }
            tmp2_1 = s2.substr(0, s2.length() - i);
            tmp2_2 = s2.substr(s2.length() - i, i);
            if (isScramble(tmp1_1, tmp2_2) && isScramble(tmp1_2, tmp2_1)) {
                return true;
            }
            if (s1.length() == 27) {
                printf("%d\n", 100);
            }
//            if (isScramble(tmp1_1, tmp2_2) && isScramble(tmp1_2, tmp2_1)) {
//                return true;
//            }

        }
        return false;

    }
};

int main() {
//    std::string s1 = "great", s2 = "rgeat";
//    std::string s1 = "abcde", s2 = "caebd";
//    std::string s1 = "a", s2 = "a";
//    std::string s1 = "abcdbdacbdac", s2 = "bdacabcdbdac";
//    std::string s1 = "abb", s2 = "bab";
    std::string s1 = "abb", s2 = "bba";
//    std::string s1 = "eebaacbcbcadaaedceaaacadccd";
//    std::string s2 = "eadcaacabaddaceacbceaabeccd";
    printf("%d\n", s1.length());
    Solution solve;
    bool result = solve.isScramble(s1, s2);
    printf("result is %d\n", result);
    return 0;
}