#include <bits/stdc++.h>
using namespace std;

pair<int, int> getValues (string line) {
	string num1, num2;
	int i = 0;
	while (line[i] != ' ') {
		num1 += line[i];
	  i += 1;
	}

	while (line[i] == ' ')
	{
		i += 1;
	}
	
	while (i < line.size()) {
		num2 += line[i];
		i += 1;
	}

	return {stoi(num1), stoi(num2)};

}

int main() {
	string line;
	ifstream InputFile("input.txt");
	vector<int> list1, list2;
	int ans = 0;

	while (getline (InputFile, line)) {
		// cout << line<<endl;
		pair<int, int> nums = getValues(line);
		// cout<<nums.first<<" "<<nums.second<<endl;
		list1.push_back(nums.first);
		list2.push_back(nums.second);
	}

	sort(list1.begin(), list1.end());
	sort(list2.begin(), list2.end());

	for (int i = 0; i < list1.size(); i++) {
		ans += abs(list1[i] - list2[i]);
	}

	cout<<ans<<endl;

	return 0;
}
