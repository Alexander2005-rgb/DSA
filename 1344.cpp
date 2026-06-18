class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Calculate the angle of the hour hand
        // 360 degrees in 12 hours, so 30 degrees per hour
        // 30 degrees per hour, and 0.5 degrees per minute (30/60)
        double hourAngle = (hour % 12 + minutes / 60.0) * 30;

        // Calculate the angle of the minute hand
        // 360 degrees in 60 minutes, so 6 degrees per minute
        double minuteAngle = minutes * 6;

        // Calculate the absolute difference between the angles
        double diff = abs(hourAngle - minuteAngle);

        // Return the smaller angle
        return min(diff, 360 - diff);
    }
};