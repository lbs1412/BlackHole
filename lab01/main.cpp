#include "stdafx.h"
namespace {
	void loadConfig(Config& config);
	void displayInfo();

}

int main(){
	Config config;
	loadConfig(config);
	displayInfo();
	Application app(config);
	app.runLoop();
	return 0;
}


namespace {

	void loadConfig(Config& config)
	{
		std::ifstream configFile("config");
		std::string key;
		if (configFile.is_open()) {
			while (configFile >> key) {
				if (key == "windowssize") {
					configFile >> config.windowX >> config.windowY;
					std::cout << "Window Size: "
						<< config.windowX << " " << config.windowY
						<< std::endl;
				}
				else if (key == "combs") {
					configFile >> config.rows >> config.cols;
					std::cout << "combs: "
						<< config.rows << " " << config.cols
						<< std::endl;
				}
				else if (key == "combsize") {
					configFile >> config.rect_width >> config.rect_height;
					std::cout << "combsize: "
						<< config.rect_width << " " << config.rect_height
						<< std::endl;
				}
				else if (key == "textpos") {
					configFile >> config.textX >> config.textY;
					std::cout << "textpos: "
						<< config.textX << " " << config.textY
						<< std::endl;
				}
			}
		}
		else {
			std::cerr << "Error: Could not find config file! Using defaults" << std::endl;
		}
	}
	void displayInfo() {
		std::ifstream inFile;
		inFile.open("Res/info");
		std::string line;
		while (std::getline(inFile, line)){
			std::cout << line << "\n";
		}
	}
}
