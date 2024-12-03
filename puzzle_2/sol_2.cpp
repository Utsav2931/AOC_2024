
#include <bits/stdc++.h>
using namespace std;

vector<int> getValues(string line)
{
	vector<int> values;
	string number = "";
	for (auto c : line)
	{
		if (c == ' ')
		{
			if (number != "")
				values.push_back(stoi(number));
			number = "";
		}
		number += c;
	}
	values.push_back(stoi(number));
	return values;
}

bool checkValid(vector<int> &values)
{
	if (values.size() <= 1)
		return true;

	bool incr = true;
	if (values[1] < values[0])
		incr = false;

	for (int i = 1; i < values.size(); i++)
	{

		if (values[i] == values[i - 1] || abs(values[i] - values[i - 1]) > 3)
			return false;

		if ((values[i] < values[i - 1] && incr) || (values[i] > values[i - 1] && !incr))
			return false;

	}

	return true;
}

int main()
{
	string line;
	ifstream InputFile("input.txt");
	int ans = 0;
	while (getline(InputFile, line))
	{
		vector<int> values = getValues(line);
		for (int i = 0; i < values.size(); i++) {
			int temp = values[i];
			values.erase(values.begin() + i);
			if (checkValid(values)) {
				ans++;
				break;
			}
			values.insert(values.begin() + i, temp);
		}
	}

	cout << ans << endl;
	return 0;
}