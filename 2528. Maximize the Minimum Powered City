class Solution {
 public:
  long long maxPower(vector<int>& stations, int r, int k) {
    long left = ranges::min(stations);
    long right = accumulate(stations.begin(), stations.end(), 0L) + k + 1;
    while (left < right) {
      const long mid = (left + right) / 2;
      if (check(stations, r, k, mid))
        left = mid + 1;
      else
        right = mid;
    }
    return left - 1;
  }

 private:
  bool check(vector<int> stations, int r, int additionalStations,
             long minPower) {
    const int n = stations.size();
    long power = accumulate(stations.begin(), stations.begin() + r, 0L);

    for (int i = 0; i < n; ++i) {
      if (i + r < n)
        power += stations[i + r];
      if (power < minPower) {
        const long requiredPower = minPower - power;
        if (requiredPower > additionalStations)
          return false;
        stations[min(n - 1, i + r)] += requiredPower;
        additionalStations -= requiredPower;
        power += requiredPower;
      }
      if (i - r >= 0)
        power -= stations[i - r];
    }
    return true;
  }
};