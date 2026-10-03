#pragma once
#include <string>

struct SystemInfo {
    std::string id;
    std::string idLike;
    std::string versionId;
    std::string prettyName;
};

SystemInfo detectSystem();
