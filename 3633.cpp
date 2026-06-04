//earliest finish tim efor land and water rides 1
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        int ans = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Case 1: Land ride -> Water ride
                int landFinish = landStartTime[i] + landDuration[i];
                int finishLandWater =
                    max(landFinish, waterStartTime[j]) + waterDuration[j];

                ans = min(ans, finishLandWater);

                // Case 2: Water ride -> Land ride
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int finishWaterLand =
                    max(waterFinish, landStartTime[i]) + landDuration[i];

                ans = min(ans, finishWaterLand);
            }
        }

        return ans;
    }
};

int main(){
    vector<int> landStartTime = {1, 3, 5};
    vector<int> landDuration = {2, 4, 6};
    vector<int> waterStartTime = {2, 4, 6};
    vector<int> waterDuration = {1, 3, 5};
    Solution s;
    cout << s.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl;
    return 0;
}
