#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int answer = 0;

bool checkDiff(string a, string b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff++;
    }
    if (diff == 1)
        return true;
    else
        return false;
}

void dfs(string begin, string target, vector<string> words, vector<bool> visit, int cnt) {
    if (begin.compare(target) == 0) {
        answer = min(cnt, answer);
        return;
    }
    for (int i = 0; i < words.size(); ++i) {
        if (visit[i] == false && checkDiff(begin, words[i])) {
            visit[i] = true;
            dfs(words[i], target, words, visit, cnt+1);
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    bool flag = true;
    for (int i = 0; i < words.size(); ++i) {
        if (target.compare(words[i]) == 0)
            flag = false;
    }
    if (flag == true) return 0;
    vector<bool> visit = {};

    for (int i = 0; i < words.size(); ++i) {
        visit.push_back(false);
    }
    answer = words.size()+1;
    dfs(begin, target, words, visit, 0);
    return answer;
}

int main() {
    //string begin = "hit";
    //string target = "cog";
    //vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
    //cout << solution(begin, target, words);

    deque<int> q;
    for (int i = 1; i <= 5; ++i) {
        q.push_back(i);
    }
    for (int i = 0; i < 5; ++i) {
        cout << q[i] << ' ';
    }
}