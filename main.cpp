#include <iostream>
#include <map>
#include <cpr/cpr.h>

int main() {
    std::string strUrl = "http://httpbin.org/";

    std::map<std::string, cpr::Response(*)(cpr::Url&)> methods;
    methods["get"]    = static_cast<cpr::Response(*)(cpr::Url&)>(&cpr::Get);
    methods["post"]   = static_cast<cpr::Response(*)(cpr::Url&)>(&cpr::Post);
    methods["put"]    = static_cast<cpr::Response(*)(cpr::Url&)>(&cpr::Put);
    methods["delete"] = static_cast<cpr::Response(*)(cpr::Url&)>(&cpr::Delete);
    methods["patch"]  = static_cast<cpr::Response(*)(cpr::Url&)>(&cpr::Patch);

    std::cout << "Available commands:\n"
                 "get, post, put, delete, patch, exit.\n";

    while (true) {
        std::cout << "Enter command:" << std::endl;
        std::string command;
        std::cin >> command;

        if (command == "exit") return 0;

        auto method = methods.find(command);
        if (method != methods.end()) {
            cpr::Url url{strUrl + command};
            cpr::Response response = method->second(url);
            std::cout << response.status_code << std::endl;
            std::cout << response.text << std::endl;
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }
}
