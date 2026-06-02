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
