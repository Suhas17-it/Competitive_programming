#include <bits/stdc++.h>
using namespace std;

struct NumberStrategy {
    virtual ~NumberStrategy() = default;
    virtual int choose_one(int lo, int hi) = 0;
};


class RandomNumberStrategy : public NumberStrategy {
public:
    RandomNumberStrategy() : rng(random_device{}()) {}
    int choose_one(int lo, int hi) override {
        uniform_int_distribution<int> dist(lo, hi);
        return dist(rng);
    }
private:
    mt19937 rng;
};

class FixedNumberStrategy : public NumberStrategy {
public:
    FixedNumberStrategy(const vector<int>& seq) : seq(seq), idx(0) {}
    int choose_one(int lo, int hi) override {
        if (seq.empty()) return lo; 
        int v = seq[idx % seq.size()];
        idx++;
        if (v < lo) return lo;
        if (v > hi) return hi;
        return v;
    }
private:
    vector<int> seq;
    size_t idx;
};

class SubsetNumberStrategy : public NumberStrategy {
public:
    SubsetNumberStrategy(const vector<int>& allowed) : allowed(allowed), rng(random_device{}()) {}
    int choose_one(int lo, int hi) override {
        vector<int> choices;
        for (int v : allowed) if (v >= lo && v <= hi) choices.push_back(v);
        if (choices.empty()) {
            // fallback to uniform in [lo,hi]
            uniform_int_distribution<int> dist(lo, hi);
            return dist(rng);
        }
        uniform_int_distribution<size_t> dist(0, choices.size() - 1);
        return choices[dist(rng)];
    }
private:
    vector<int> allowed;
    mt19937 rng;
};


class ScoreGame {
public:
  
    ScoreGame(int target, int balls, int max_run,
              shared_ptr<NumberStrategy> batsman,
              shared_ptr<NumberStrategy> bowler)
        : target(target), balls(balls), max_run(max_run),
          batsman(std::move(batsman)), bowler(std::move(bowler)) {}

    bool play() {
        int sum = 0;
        for (int i = 0; i < balls; ++i) {
            int bat_choice = batsman->choose_one(0, max_run);
            int bowl_choice = bowler->choose_one(0, max_run);
            cout << "ball " << (i + 1) << ": batsman " << bat_choice
                 << " bowler " << bowl_choice << '\n';

            if (bat_choice == bowl_choice) {
                cout << "out\n";
                return false; 
            }

            sum += bat_choice;
            cout << "score " << sum << '\n';

            if (sum >= target) {
                cout << "won\n";
                return true;
            }
        }

        if (sum >= target) {
            cout << "won\n";
            return true;
        } else {
            cout << "no\n";
            return false;
        }
    }

private:
    int target;
    int balls;
    int max_run;
    shared_ptr<NumberStrategy> batsman;
    shared_ptr<NumberStrategy> bowler;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int target;
    int batsman_type = 0;
    if (!(cin >> target >> batsman_type)) return 0;

    shared_ptr<NumberStrategy> batsman;
    if (batsman_type == 0) {
        // type 0: can score any run 0..6
        batsman = make_shared<RandomNumberStrategy>();
    } else if (batsman_type == 1) {
        // type 1: can score only 0,4,6
        batsman = make_shared<SubsetNumberStrategy>(vector<int>{0,4,6});
    } else {
        // unknown type: default to type 0 behavior
        batsman = make_shared<RandomNumberStrategy>();
    }

    auto bowler  = make_shared<RandomNumberStrategy>();

    const int total_balls = 12;
    const int max_run = 6; 

    ScoreGame game(target, total_balls, max_run, batsman, bowler);
    game.play();
    return 0;
}