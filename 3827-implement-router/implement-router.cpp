#include <bits/stdc++.h>
using namespace std;

class Router {
private:
    int memoryLimit;
    deque<array<int, 3>> packets; // store [source, destination, timestamp]
    unordered_set<string> packetSet; // for duplicate detection
    unordered_map<int, vector<int>> destMap; // destination -> timestamps (sorted)
    
    // Helper to build unique key for (src, dest, ts)
    string makeKey(int s, int d, int t) {
        return to_string(s) + "|" + to_string(d) + "|" + to_string(t);
    }

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (packetSet.count(key)) return false; // duplicate
        
        // If memory full, evict oldest packet
        if ((int)packets.size() == memoryLimit) {
            auto old = packets.front();
            packets.pop_front();
            string oldKey = makeKey(old[0], old[1], old[2]);
            packetSet.erase(oldKey);
            
            // Remove from destMap
            auto &vec = destMap[old[1]];
            // Since timestamps are unique in a queue, erase first match
            auto it = lower_bound(vec.begin(), vec.end(), old[2]);
            if (it != vec.end() && *it == old[2]) vec.erase(it);
        }
        
        // Add new packet
        packets.push_back({source, destination, timestamp});
        packetSet.insert(key);
        destMap[destination].push_back(timestamp); // timestamps inserted in sorted order
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packets.empty()) return {};
        
        auto pkt = packets.front();
        packets.pop_front();
        
        string key = makeKey(pkt[0], pkt[1], pkt[2]);
        packetSet.erase(key);
        
        // Remove from destMap
        auto &vec = destMap[pkt[1]];
        auto it = lower_bound(vec.begin(), vec.end(), pkt[2]);
        if (it != vec.end() && *it == pkt[2]) vec.erase(it);
        
        return {pkt[0], pkt[1], pkt[2]};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (!destMap.count(destination)) return 0;
        auto &vec = destMap[destination];
        
        // Binary search range [startTime, endTime]
        auto lo = lower_bound(vec.begin(), vec.end(), startTime);
        auto hi = upper_bound(vec.begin(), vec.end(), endTime);
        return hi - lo;
    }
};
