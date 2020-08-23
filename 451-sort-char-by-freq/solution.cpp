/*

- Store character -> freq in hash table
- in a heap, store char->freq (ordered by freq)
- build the result by popping values from the heap


*/
class Compare {
    public:
        bool operator () (pair<char, int> charFreqA, pair<char, int> charFreqB) {
            return charFreqA.second < charFreqB.second;
        }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charFreqMap;
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        
        string answer;
        
        for (char c : s) {
            charFreqMap[c]++;
        }
        
        for (auto& kvPair: charFreqMap) {
            pq.push(kvPair);
        }
        
        while (!pq.empty()) {
            auto charFreq = pq.top();
            for (int i = 0; i < charFreq.second; i++) {
                answer.push_back(charFreq.first);
            }
            pq.pop();
        }
        
        return answer;
    }
};