/**
 * @file Solution.cpp
 * @brief Find the longest awesome substring in a given string.
 *
 * A "super awesome substring" is a non-empty substring of 's' that can be made into a palindrome
 * by performing any number of character swaps.
 *
 * Key Concepts:
 * - Super Awesome Substring: A substring that can be rearranged to form a palindrome.
 * - Palindrome: A string that reads the same forward and backward.
 * - Bitmask: A binary number used to track the parity (odd or even counts) of characters.
 *
 * Solution Approach:
 * - Use a bitmask to track the parity of each digit (0-9) seen so far.
 * - Use an unordered map to store the first occurrence of each bitmask.
 * - Iterate through the string, updating the bitmask at each step and checking if the
 *   current bitmask or the bitmask toggled by one bit has been seen before.
 *
 * Details:
 * - Bitmask: 10-bit binary number, each bit represents the parity of digits 0-9.
 * - If all characters except for one have even counts, the string can be rearranged into a palindrome.
 *
 * Implementation Steps:
 * 1. Initialize a bitmask to zero (all characters have even counts).
 * 2. Initialize a hashmap to record the first index of each bitmask.
 * 3. Iterate through the string:
 *    - Toggle the corresponding bit in the bitmask for the current character.
 *    - Check if the current bitmask has been seen before.
 *      - If so, calculate the length of the current super awesome substring.
 *      - If not, store the current index as the first occurrence of this bitmask.
 *    - Check if toggling any single bit of the current bitmask (to allow one odd count) has been seen before.
 *      - If so, update the maximum length if this yields a longer substring.
 * 4. Return the maximum length found.
 *
 * Example Usage:
 * - Input: s = "3242415"
 * - Output: 5 (The substring "24241" can be rearranged to form the palindrome "24142").
 *
 * The code aims to provide an efficient solution using bitwise operations and hashmap.
 */

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * Finds the length of the longest super awesome substring.
     *
     * @param s The input string consisting of digits from '0' to '9'.
     * @return The length of the longest super awesome substring.
     */
    static int longestAwesome(string s) {
        int mask = 0;  // Bitmask to track the parity of digits.
        int maxLength = 0;  // The length of the longest super awesome substring found.
        unordered_map<int, int> firstSeen{{0, -1}};  // Hashmap to store the first occurrence of each bitmask.
        
        for (int i = 0; i < s.size(); ++i) {
            int num = s[i] - '0';  // Convert character to integer.
            mask ^= (1 << num);  // Toggle the bit corresponding to 'num'.
            
            // Check if the current bitmask has been seen before.
            if (firstSeen.count(mask)) {
                maxLength = max(maxLength, i - firstSeen[mask]);
            } else {
                firstSeen[mask] = i;  // Store the index of the first occurrence of this bitmask.
            }
            
            // Check for toggling any single bit of the current bitmask.
            for (int j = 0; j < 10; ++j) {
                int tempMask = mask ^ (1 << j);
                if (firstSeen.count(tempMask)) {
                    maxLength = max(maxLength, i - firstSeen[tempMask]);
                }
            }
        }
        
        return maxLength;  // Return the maximum length found.
    }
};

int main() {
    cout << Solution::longestAwesome("3242415") << endl;  // Should output 5
    return 0;
}
/**
 * 解题思路概述：
 * - 这个问题的核心是识别字符串中可以通过字符交换变为回文的最长子字符串。
 * - 回文的特点是最多只有一个字符出现奇数次，其余都出现偶数次。
 * - 为了追踪字符串中各个数字字符的出现次数的奇偶性，我们使用了一个称为“位掩码”的技术。
 *
 * 位掩码技术应用：
 * - 我们用一个10位的位掩码来追踪0到9每个数字出现的次数的奇偶性。
 * - 每一位的0或1表示对应数字出现次数的奇偶性。1表示奇数次，0表示偶数次。
 * - 通过XOR操作，我们可以方便地更新位掩码，因为XOR同一个数两次会回到原状态。
 *
 * 使用哈希表记录状态：
 * - 我们使用一个哈希表来存储每一种位掩码第一次出现的位置。
 * - 这样，每次更新位掩码后，我们都可以通过查看这个位掩码是否已经出现过来直接判断出从上一次出现该掩码到当前位置的子字符串是否能构成回文。
 *
 * 处理每一个字符：
 * - 对于字符串中的每一个字符，我们都更新当前的位掩码。
 * - 然后，检查当前的位掩码是否已在哈希表中。如果是，那么就可能找到了一个新的最长超赞子字符串。
 * - 此外，我们还会检查当前掩码改变任意一个位（即允许一个字符出现奇数次）的情况，看看是否能构成更长的回文。
 *
 * 总结：
 * - 这种方法的优势在于它的高效性，使用位掩码和哈希表可以在O(n)的时间复杂度内解决问题。
 * - 通过这种方法，我们可以快速地处理大量数据，寻找并确认最长的超赞子字符串。
 */
