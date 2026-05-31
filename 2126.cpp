// destroying asteroids 
// You are given an integer array asteroids of length n. 
// Each integer represents the size of an asteroid.
// positive values mean right-moving asteroids and negative values mean left-moving asteroids. 
// When two asteroids meet, the smaller one explodes unless both are the same size, in which case both explode.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, std::vector<int>& asteroids) {
        // Sort the asteroids in ascending order
        std::sort(asteroids.begin(), asteroids.end());

        // Use long long for current_mass to prevent overflow
        long long current_mass = mass;

        // Iterate through the sorted asteroids
        for (int asteroid_mass : asteroids) {
            // If current_mass is less than the asteroid's mass, the planet is destroyed
            if (current_mass < asteroid_mass) {
                return false;
            }
            // Otherwise, the asteroid is destroyed, and its mass is added to the planet
            current_mass += asteroid_mass;
        }

        // If all asteroids were destroyed, return true
        return true;
    }
};

int main(){
    Solution s;
    int mass = 10;
    vector<int> asteroids = {3,9,2,3,10};
    cout << s.asteroidsDestroyed(mass, asteroids) << endl;
}