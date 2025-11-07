//Manachers algorithm for efficiency 
#include <string>
#include <vector>

std::string longestPalindrome(const std::string& s ) {
    std::string t = "#";
    for (char c: s ) t += c, t += '#';
    int n = t.size();
    std::vector<int> p(n, 0);
    int center = 0, right = 0;

    for (int i = 0; i < n; ++i) {
        if (i < right) p[i] = std::min(right-i, p[2 * center - i]);
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t [i - p[i] - 1]== t[i + p[i] + 1]) 
        {
            ++p[i];
        }
        if (i + p[i] > right ) {
            center = i;
            right = i + p[i];
        }
    }

    int maxLen = 0,  maxCenter = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            maxCenter = i;
        }
    }

    int start = (maxCenter- maxLen) / 2;
    return s.substr(start, maxlen);
}