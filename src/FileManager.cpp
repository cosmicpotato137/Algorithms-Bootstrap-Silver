#include "CoreDefines.h"
#include "Cows.h"


bool TestData(std::string filepath, std::string outputpath)
{
	std::ifstream file(filepath);
	std::ifstream output(outputpath);

	if (file.fail())
	{
		std::cout << "Failed to open " << filepath << std::endl;
		return false;
	}
	if (output.fail())
	{
		std::cout << "Failed to open " << outputpath << std::endl;
		return false;
	}

	std::vector<Fence> fences;
	std::string int1;
	std::string int2;

	file >> int1;
	file >> int2;
	int numcows = stoi(int1);
	int numfences = stoi(int2);

	while (!file.eof())
	{
		int1;
		file >> int1;
		int2;
		file >> int2;
		fences.push_back(Fence{ stoi(int1), stoi(int2) });
	}

	output >> int1;
	int answer = stoi(int1);

	int d = FindDistance(numcows, fences);

	if (d == answer)
		std::cout << "SUCCESS" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;

	std::cout << "Files: " << filepath << ", " << outputpath << std::endl;
	std::cout << "Cows: " << numcows << " Fences: " << numfences << std::endl;
	std::cout << "Expected: " << answer << " Result: " << d << std::endl;

	return d == answer;
}

void AllTest(std::string folder)
{
	if (!exists(folder))
		return;

	std::map<std::string, std::pair<std::string, std::string>> files;
	for (const auto& file : directory_iterator(folder))
	{
		std::string path = file.path().string();
		std::string base_filename = path.substr(path.find_last_of("/\\") + 1);
		std::string::size_type const p(base_filename.find_last_of('.'));
		std::string file_without_extension = base_filename.substr(0, p);

		if (files.find(file_without_extension) == files.end())
			files[file_without_extension] = std::pair<std::string, std::string>{ "","" };
		if (path.substr(path.size() - 3, 3) == ".in")
			files[file_without_extension].first = path;
		else if (path.substr(path.size() - 4, 4) == ".out")
			files[file_without_extension].second = path;
		else
			std::cout << "Invalid file found in test folder: " << path << std::endl;
	}

	auto iter = files.begin();
	while (iter != files.end())
	{
		auto inout = iter->second;
		TestData(inout.first, inout.second);
		std::cout << "\n";
		++iter;
	}
}
