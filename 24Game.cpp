class Solution {
public:
    bool valid(double a, double b) {
        return fabs(a + b - 24.0) < 0.0001 or fabs(a - b - 24.0) < 0.0001 or
               fabs(a * b - 24.0) < 0.0001 or (b != 0 and fabs(a / b - 24.0) < 0.0001);
    }
    
    bool valid(double a, double b, double c) {
        return valid(a + b, c) or valid(a, b + c) or valid(a - b, c) or
               valid(a, b - c) or valid(a * b, c) or valid(a, b * c) or
               valid(a / b, c) or valid(a, b / c);
    }
    
    bool get_perm(int idx, vector<double>& cards) {
        if (idx == 4) {
            return valid(cards[0] + cards[1], cards[2], cards[3]) or
                   valid(cards[0], cards[1] + cards[2], cards[3]) or
                   valid(cards[0], cards[1], cards[2] + cards[3]) or
                   valid(cards[0] - cards[1], cards[2], cards[3]) or
                   valid(cards[0], cards[1] - cards[2], cards[3]) or
                   valid(cards[0], cards[1], cards[2] - cards[3]) or
                   valid(cards[0] * cards[1], cards[2], cards[3]) or
                   valid(cards[0], cards[1] * cards[2], cards[3]) or
                   valid(cards[0], cards[1], cards[2] * cards[3]) or
                   valid(cards[0] / cards[1], cards[2], cards[3]) or
                   valid(cards[0], cards[1] / cards[2], cards[3]) or
                   valid(cards[0], cards[1], cards[2] / cards[3]);
        }
        
        bool res = false;
        unordered_set<int> s;
        for (int i = idx; i < 4 and !res; i++) {
            if (s.count(cards[i]))
                continue;
            s.insert(cards[i]);
            swap(cards[idx], cards[i]);
            res |= get_perm(idx + 1, cards);
            swap(cards[idx], cards[i]);
        }
        return res;
    }
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> cards;
        for (auto& x : nums)
            cards.push_back((double)x);
        return get_perm(0, cards);
    }
};

//code (2)

class Solution {
public:
    std::vector<double> available_nums;
    bool bt() {
        if (available_nums.size() == 1) {
            auto v = available_nums.back();
            return abs(v - 24.) < .01;
        }
        for (size_t i = 0; i < available_nums.size(); ++i) {
            for (size_t j = i + 1; j < available_nums.size(); j++)
            {
                auto op1 = available_nums[i];
                auto op2 = available_nums[j];
                available_nums.erase(available_nums.begin() + j);
                available_nums.erase(available_nums.begin() + i);
                auto bt_help = [&](double curr) {
                    available_nums.push_back(curr);
                    if (bt()) return true;
                    available_nums.pop_back();
                    return false;
                };
                if (bt_help(op1 + op2)) return true;
                if (bt_help(op1 - op2)) return true;
                if (bt_help(op2 - op1)) return true;
                if (bt_help(op1 / op2)) return true;
                if (bt_help(op2 / op1)) return true;
                if (bt_help(op2 * op1)) return true;
                available_nums.insert(available_nums.begin() + i, op1);
                available_nums.insert(available_nums.begin() + j, op2);
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        for (const auto card : cards) {
            available_nums.push_back(card);
        }
        return bt();
    }
};
