// friends.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include "json.hpp"
#include "Distance.h"
#include "Constant.h"
#include <gtest/gtest.h>

using json = nlohmann::json;

json ReadJsonFile(std::string filename)
{
	try
	{
		std::ifstream json_file(filename);
		if (json_file)
		{
			json json_object;
			json_file >> json_object;
			json_file.close();
			return json_object;
		}
		else
		{
			throw "Unable to open File";
		}


	}
	catch (const std::exception&)
	{
		std::cout << "Unable to open json file";
	}

}

std::map<int, std::string> ReturnResultMap(json json_object, double radius, double party_lat =0.0, double party_long =0.0)
{
	Distance distance_obj;
	std::map<int, std::string> result;
	for (auto& element : json_object) {

		// get latitude then convert to double
		std::string latitude_string = element["latitude"];
		double latitude2 = ::atof(latitude_string.c_str());

		//get longitude then convert to double
		std::string longitude_string = element["longitude"];
		double longitude2 = ::atof(longitude_string.c_str());
		double distance;
		if (party_lat == 0.0 && party_long == 0.0)
		{
			distance = distance_obj.GreatCircle_distance(PARTY_LATITUDE, PARTY_LONGITUTDE, latitude2, longitude2);
		}
		else
		{
			distance = distance_obj.GreatCircle_distance(party_lat, party_long, latitude2, longitude2);
		}

		if (distance < radius)
		{
			int user_id = element["user_id"];
			std::string user_name = element["name"];

			result.insert(std::pair<int, std::string>(user_id, user_name));
		}


	}
	return result;
}

int main(int argc, char* argv[])
{
	if (argc >= 2 && std::string(argv[1]) == "--tests")
	{
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
	else
	{
		json json_object = ReadJsonFile("friends.json");
		std::cout << json_object.dump(4) << std::endl;

		
		

		// resultant map
		std::map<int, std::string> result = ReturnResultMap(json_object, 100);

		// show content
		for (std::map<int, std::string>::iterator it = result.begin(); it != result.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';


	}
	std::getchar();
    return 0;
}

/*
Test cases on Default friend.json file
*/
TEST(TestCase_Default, Default)
{
	json Testjson_object = ReadJsonFile("../testcases/TestJson1.json");
	std::map<int, std::string> check;
	check.insert(std::pair<int, std::string>(4, "Ian"));
	check.insert(std::pair<int, std::string>(5, "Nora"));
	check.insert(std::pair<int, std::string>(6, "Theresa"));
	check.insert(std::pair<int, std::string>(10, "Georgina"));
	check.insert(std::pair<int, std::string>(11, "Richard"));
	check.insert(std::pair<int, std::string>(12, "Chris"));
	check.insert(std::pair<int, std::string>(15, "Michael"));
	check.insert(std::pair<int, std::string>(16, "Ian"));
	check.insert(std::pair<int, std::string>(25, "David"));
	check.insert(std::pair<int, std::string>(31, "Alan"));
	check.insert(std::pair<int, std::string>(39, "Lisa"));

	std::map<int, std::string> TestResult = ReturnResultMap(Testjson_object, 100);
	EXPECT_EQ(check, TestResult);
}

/*
Test cases wiith Small Radius
*/
TEST(TestCase_SmallLong, SmallLong)
{
	json Testjson_object = ReadJsonFile("../testcases/TestJson2.json");
	std::map<int, std::string> check;
	
	check.insert(std::pair<int, std::string>(23, "Ace"));
	check.insert(std::pair<int, std::string>(4, "Debra"));
	check.insert(std::pair<int, std::string>(11, "Ian"));


	std::map<int, std::string> TestResult = ReturnResultMap(Testjson_object, 100, 16.399780, 80.589159);
	EXPECT_EQ(check, TestResult);

	TestResult = ReturnResultMap(Testjson_object, 50, 16.399780, 80.589159);
	EXPECT_EQ(check, TestResult);

}


/*
Test cases on locations in north latitude and east longitude within larger radius.
*/


TEST(TestCase_NorthLargeRadius, NorthLargeRadius)
{
	json Testjson_object = ReadJsonFile("../testcases/TestJson3.json");
	std::map<int, std::string> check;


	check.insert(std::pair<int, std::string>(5, "Ace"));
	check.insert(std::pair<int, std::string>(6, "Ruphy"));
	check.insert(std::pair<int, std::string>(11, "Ian"));
	check.insert(std::pair<int, std::string>(46, "Remedy"));
	check.insert(std::pair<int, std::string>(23, "Debra"));
	check.insert(std::pair<int, std::string>(18, "Ivana"));
	check.insert(std::pair<int, std::string>(17, "Patricia"));


	std::map<int, std::string> TestResult = ReturnResultMap(Testjson_object, 50000, 20.399780, 79.589159);
	EXPECT_EQ(check, TestResult);


}


