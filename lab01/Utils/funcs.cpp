#include "../stdafx.h"
std::string intToString(int x) {
	std::stringstream ss;
	std::string ret;
	ss << x;
	ss >> ret;
	return ret;
}
//already exist std::to_string =!= fuck
std::string getAnswer(std::vector<vb>& vis) {
	result show = get_data(vis);
	std::string num_black = std::to_string(show.num_of_blackhole);
	std::string different_shape = std::to_string(show.num_of_diffshap_blackhole);
	std::string different_size = std::to_string(show.num_of_diffarea_blackhole);
	std::string ret = "num_black:" + num_black + "\n"
		"different_shape:" + different_shape + "\n"
		"different_size:" + different_size + "\n";
	return ret;
}
