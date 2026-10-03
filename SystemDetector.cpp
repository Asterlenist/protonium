#include "SystemDetector.h"
#include <fstream>
#include <iostream>
#include <map>

std::string trimQuotes(const std::string& str) {
    if (str.length() < 2) return str;
    char first = str.front();
    char last = str.back();
    if ((first == '"' && last == '"') || (first == '\'' && last == '\'')) {
        return str.substr(1, str.length() - 2);
    }
    return str;
}

SystemInfo detectSystem() {
    SystemInfo info;
    std::map<std::string, std::string> data;
    
    std::string paths[] = {"/etc/os-release", "/usr/lib/os-release"};
    std::ifstream file;
    
    for (const auto& path : paths) {
        file.open(path);
        if (file.is_open()) break;
    }

    if (!file.is_open()) {
        std::cerr << "Cannot read os-release\n";
        info.id = "unknown";
        return info;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        size_t pos = line.find('=');
        if (pos == std::string::npos) continue;
        
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        data[key] = trimQuotes(value);
    }

    if (data.count("ID"))          info.id = data["ID"];
    if (data.count("ID_LIKE"))     info.idLike = data["ID_LIKE"];
    if (data.count("VERSION_ID"))  info.versionId = data["VERSION_ID"];
    if (data.count("PRETTY_NAME")) info.prettyName = data["PRETTY_NAME"];
    
    return info;
}
