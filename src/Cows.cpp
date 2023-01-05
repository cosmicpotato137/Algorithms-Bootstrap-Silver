#include "CoreDefines.h"

// we can test that a given solution works greedily by taking 
// the first open position at a distance Dwe see for each cow
// expects the distance to check, the number of cows, and a 
// list of fences ordered by start point
bool CheckDistance(int d, int cows, std::vector<Fence> fences)
{
	int j = 0;
	int i = 0; // keep track of i globally to handle close together pastures
	for each (Fence f in fences)
	{
		for (i = std::max(i, f.first); i <= f.second; i += d)
		{
			j++;
			if (cows <= j)
				return true; // could fit more cows
		}
	}

	return false; // too many cows!
}

int FindDistance(int cows, std::vector<Fence> fences)
{
	// sort the fences from least to greatest
	sort(fences.begin(), fences.end());

	// closest and farthest fence posts
	int amin = fences[0].first;
	int bmax = fences[fences.size() - 1].second;

	// possible range for d
	int a = 1;
	int b = (bmax - amin) / (cows - 1);
	int d = 0;
	int res = -1;

	while (a <= b)
	{
		// take the midpoint of the possible range for d
		d = (a + b) / 2;
		bool val = CheckDistance(d, cows, fences);

		// set the new min and max values
		if (val)
		{
			res = d; // only set the result if we know CheckDistance returned true
			a = d + 1;
		}
		else
			b = d - 1;
	}

	return res;
}
