#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool checkAnswer(const std::string &str1, const std::string &str2){
	//.............
	return str1 == str2;
}


bool predictAnswer(){
	std::fstream in1("output1.txt", std::ios_base::in);
	std::fstream in2("output2.txt", std::ios_base::in);
	std::string str1, str2;
	while(getline(in1,str1) && getline(in2, str2)){
		if(!checkAnswer(str1, str2)){
			return false;
		}
		str1 = str2 = "";
	}
	in1.close();
	in2.close();
	return str1 == str2;
}

int main()
{
	system("g++ solve.cpp -o solve");
	system("g++ stupid.cpp -o stupid");
	system("g++ gen.cpp -o gen");
	while(true)
	{
		system("./gen > input.txt");
		system("./solve < input.txt > output1.txt");
		system("./stupid < input.txt > output2.txt");
		if(predictAnswer())
		{
			std::cout << "Passed!!!\n";
		}
		else
		{
			std::cout << "Wrong Answer!!!\nTest: ";
			std::string str;
			std::fstream in1("input.txt", std::ios_base::in);
			while(getline(in1,str)){
				std::cout << str;
			}
			in1.close();
			break;
		}
	}
	return 0;
}
