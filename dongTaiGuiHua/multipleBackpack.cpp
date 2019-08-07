#include <iostream>
#include <vector>

using namespace std;

int main() {
	int kindCount = 0;
	int capacity = 0;

	vector<int> cost;
	vector<int> value;
	vector<int> count;

	cost.push_back(0);
	value.push_back(0);
	count.push_back(0);

	

	int costTmp = 0;
	int valueTmp = 0;
	int countTmp = 0;
	int size = 0;
	cin >> capacity >> kindCount;
	vector<int> dp(capacity + 1, 0);
	for (int i = 0; i < kindCount; i++) {
		cin >> countTmp >> costTmp >> valueTmp;
		int k = 1;
		while (countTmp - (1 << (k - 1)) > 0) {
			cost.push_back((1 << (k - 1))*costTmp);
			value.push_back((1 << (k - 1))*valueTmp);
			countTmp = countTmp - (1 << (k - 1));
			k++;
			size++;
		}
		cost.push_back(countTmp * costTmp);
		value.push_back(countTmp * valueTmp);
		size++;
	}

	for (int i = 1; i < cost.size(); i++) {
		for (int j = capacity; j > 0; j--) {
			if (j >= cost[i]) {
				dp[j] = dp[j] > dp[j - cost[i]] + value[i] ? dp[j] : dp[j - cost[i]] + value[i];
			}
		}
	}

	cout << dp[capacity] << endl;

	system("pause");
}