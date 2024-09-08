#include "Open.h"
Open::Open(ShapeFactory* fact, const char* fileInfo) : Command(fact,fileInfo){
	execute();
}

void Open::execute() {
    std::ifstream fileInfo("info.txt");
    if (!fileInfo) {
        return;
    }
    char filePath[100];
    fileInfo >> filePath;
    Serialiser(*fact, filePath);
    fileInfo.close();
}