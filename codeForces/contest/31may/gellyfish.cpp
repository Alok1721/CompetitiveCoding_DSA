#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        
        // Calculate turns needed for direct attacks
        long long gellyfish_turns_to_kill_flower = b;
        long long flower_turns_to_kill_gellyfish = a;
        
        // Calculate turns needed to kill knights
        long long gellyfish_turns_to_kill_flower_knight = d;
        long long flower_turns_to_kill_gellyfish_knight = c;
        
        // Strategy 1: Gellyfish attacks Flower directly
        // Gellyfish needs 'b' turns, Flower needs 'a' turns
        // Since Gellyfish goes first, Gellyfish wins if b <= a
        bool gellyfish_wins_direct = (gellyfish_turns_to_kill_flower <= flower_turns_to_kill_gellyfish);
        
        // Strategy 2: Consider knight elimination
        // If Gellyfish eliminates Flower's knight first, then attacks Flower
        // Total turns for Gellyfish: d + b
        // Flower can attack Gellyfish during these turns, but needs to consider when knight dies
        
        // If Flower's knight dies, Flower can't attack anymore
        // So we need to check if Flower can kill Gellyfish before her knight dies
        
        // More precise analysis:
        // Gellyfish goes on turns 1, 3, 5, ...
        // Flower goes on turns 2, 4, 6, ...
        
        // Case 1: Gellyfish attacks Flower directly
        // Gellyfish wins if he can kill Flower before Flower kills him
        // Since Gellyfish goes first, he wins if ceil(b/1) <= ceil(a/1) and he moves first
        // This means b <= a
        
        // Case 2: Gellyfish kills Flower's knight first, then Flower
        // Time to kill knight: d turns (on turns 1, 3, 5, ..., until knight dies)
        // After knight dies, Flower can't attack back
        // So Gellyfish needs d turns to kill knight, then b more turns to kill Flower
        // During the first d turns, Flower attacks floor(d/2) times (if knight alive on even turns)
        // We need to check if Gellyfish survives this
        
        long long flower_attacks_while_knight_dies = (gellyfish_turns_to_kill_flower_knight + 1) / 2;
        bool gellyfish_survives_knight_phase = (a > flower_attacks_while_knight_dies);
        
        // If Gellyfish can survive killing the knight, he wins
        // Otherwise, check direct attack
        
        bool gellyfish_wins;
        if (gellyfish_survives_knight_phase) {
            gellyfish_wins = true;
        } else {
            // Must rely on direct attack strategy
            gellyfish_wins = gellyfish_wins_direct;
        }
        
        if (gellyfish_wins) {
            cout << "Gellyfish\n";
        } else {
            cout << "Flower\n";
        }
    }
    
    return 0;
}