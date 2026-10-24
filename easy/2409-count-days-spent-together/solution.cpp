class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrive_month_alice=stoi(arriveAlice.substr(0,2));
        int leave_month_alice=stoi(leaveAlice.substr(0,2));

        int arrive_month_bob=stoi(arriveBob.substr(0,2));
        int leave_month_bob=stoi(leaveBob.substr(0,2));

        int arrive_day_alice=stoi(arriveAlice.substr(3,2));
        int leave_day_alice=stoi(leaveAlice.substr(3,2));

        int arrive_day_bob=stoi(arriveBob.substr(3,2));
        int leave_day_bob=stoi(leaveBob.substr(3,2));

        unordered_map<int, int> mp = {
            {1, 31},
            {2, 28},
            {3, 31},
            {4, 30},
            {5, 31},
            {6, 30},
            {7, 31},
            {8, 31},
            {9, 30},
            {10, 31},
            {11, 30},
            {12, 31}
        };

        int ans=0;
        for(int month=1;month<=12;month++){
            for(int day=1;day<=mp[month];day++){
                bool alice =
                        (month > arrive_month_alice ||
                        (month == arrive_month_alice && day >= arrive_day_alice)) &&
                        (month < leave_month_alice ||
                        (month == leave_month_alice && day <= leave_day_alice));

                bool bob =
                        (month > arrive_month_bob ||
                        (month == arrive_month_bob && day >= arrive_day_bob)) &&
                        (month < leave_month_bob ||
                        (month == leave_month_bob && day <= leave_day_bob));

                    if (alice && bob) ans++;
            }
        }

        return ans;
    }
};