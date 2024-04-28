#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int finish;
    int index;
};

vector<int> selectActivities(vector<Activity>& activities) {
    vector<int> selectedActivities;
    int n = activities.size();
    if (n <= 0) {
        return selectedActivities;
    }
    sort(activities.begin(), activities.end(), [](const Activity& a, const Activity& b) {
        return a.finish < b.finish;
    });
    selectedActivities.push_back(activities[0].index);
    int prevFinishTime = activities[0].finish;
    for (int i = 1; i < n; ++i) {
        if (activities[i].start >= prevFinishTime) {
            selectedActivities.push_back(activities[i].index);
            prevFinishTime = activities[i].finish;
        }
    }
    return selectedActivities;
}

int main() {
    int n;
    cin >> n;
    vector<Activity> activities(n);
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].start;
        activities[i].index = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].finish;
    }
    vector<int> selected = selectActivities(activities);
    cout << selected.size() << endl;
    for (int i = 0; i < selected.size(); ++i) {
        cout << "a" << selected[i] << " ";
    }
    cout << endl;
}
