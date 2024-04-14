#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Activity {
    int start;
    int finish;
    int index; 
};

bool cmpft(const Activity &a, const Activity &b) {
    return a.finish < b.finish;
}

void actsel(vector<Activity> &activities) {
    sort(activities.begin(), activities.end(), cmpft);
    vector<Activity> res;
    res.push_back(activities[0]); 
    int lastSelectedIndex = 0;
    for (int i = 1; i < activities.size(); ++i) {
        if (activities[i].start >= activities[lastSelectedIndex].finish) {
            res.push_back(activities[i]);
            lastSelectedIndex = i;
        }
    }
    cout << "Number of activities selected: " << res.size() << endl;
    cout << "Selected activities: ";
    for (const Activity &act : res) {
        cout <<"a"<<act.index << " ";
    }
    cout << endl;
}

int main() {
    // vector<Activity> activities = {
    //     {1, 2, 0},
    //     {5, 7, 1},
    //     {3, 4, 2},
    //     {0, 6, 3},
    //     {5, 10, 4},
    //     {8, 9, 5}
    // };

    vector<Activity> activities;
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;
    activities.resize(n);
    cout<<"Enter start time";
    for (int i = 0; i < n; ++i) {
        activities[i].index = i;
        cin >> activities[i].start;
    }
    cout<<"Enter finish time";
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].finish;
    }
    actsel(activities);

    return 0;
}
