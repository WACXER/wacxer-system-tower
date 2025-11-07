//develop a task to generate all valid arithmetic expressions 
//evaluating to a target vaklue in c++ 

#include <vector>
#include <string>

std::vector<std::string> addOperators(const std::string& num, int target) {
    std::vector<std::string> result;
    std::function<void(int, long long,  std::string)> backtrack = [&] 
        (int idx, long long curr, long long prev, std::string expr) {
            if (idx == num.size()) {
                if(curr == target) result.push_back(expr);
                return;
            }
            for (int i = idx; i < num.size(); ++i) {
                if (i > idx && num[idx] == '0') break; //Avoid  leading zeros 
                std::string part = num.substr(idx, i - idx + 1);
                long long val = std::stoll(part);
                if(idx == 0) {
                    backtrack(i + 1, val, val, part);
                } else {
                    backtrack(i + 1, curr + val, val, expr + "+" part);
                    backtrack(i + 1, curr - val, -val, expr + "-" + part);
                    backtrack(i + 1, curr - prev + prev * val, prev * val, expr +"*", part);
                }
            }
        };
        backtrack(0, 0, 0, "");
        return result;
}