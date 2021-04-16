
#define SOMESTRING "Hello World!"
#include <string>
#include <vector>
unsigned int sizeInBytes = 10;
//std::vector<const char*> buildVector() {
//    std::vector<const char*> vec;
//    vec.push_back(SOMESTRING);
//    return vec;
//}

//std::vector<const char*> buffer(sizeInBytes + 1);
std::vector <std::string> buffer(sizeInBytes + 1);
