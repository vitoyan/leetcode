class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0 || duration < 0)
            return 0;
        
        int timeOfPosinedEnd = 0;
        int poisonedDuration = 0;
        for(int i = 0; i < (int)timeSeries.size(); i++)
        {
            if(timeSeries[i] >= timeOfPosinedEnd)
            {
                poisonedDuration += duration;
                timeOfPosinedEnd = timeSeries[i] + duration;
            }
            else
            {
                int diff = timeOfPosinedEnd - timeSeries[i];
                poisonedDuration += (duration - diff);
                timeOfPosinedEnd += (duration - diff);
            }
        }
        
        return poisonedDuration;
    }
};