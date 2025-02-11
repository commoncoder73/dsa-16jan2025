// https://leetcode.com/problems/keys-and-rooms/description/
#include <bits/stdc++.h>

using namespace std;

void dfs(int roomNum, vector<vector<int>>& rooms, vector<bool>& visited) {
    visited[roomNum] = true;
    for(auto unlockableRoom: rooms[roomNum]) {
        if (!visited[unlockableRoom]) {
            dfs(unlockableRoom, rooms, visited);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> visited(rooms.size(), false);
    dfs(0, rooms, visited);

    for(auto isRoomUnlocked: visited) {
        if (!isRoomUnlocked) {
            return false;
        }
    }
    return true;
}


// void dfs(int roomNum, vector<vector<int>>& rooms, unordered_set<int>& unvisited) {
//     unvisited.erase(roomNum);
//     for(auto unlockableRoom: rooms[roomNum]) {
//         if (unvisited.find(roomNum) != unvisited.end()) {
//             dfs(unlockableRoom, rooms, visited);
//         }
//     }
// }

// bool canVisitAllRooms(vector<vector<int>>& rooms) {
//     unordered_set<int> unvisited;
//     for(int i=0; i<rooms.size(); i++) {
//         unvisited.insert(i);
//     }

//     dfs(0, rooms, unvisited);

//     return unvisited.empty();
// }

