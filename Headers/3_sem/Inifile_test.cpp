#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"
#include "Inifile.h"

TEST_CASE("Inifile")
{
    SECTION("read and etc") {
        IniFile cfg("config.ini");
        REQUIRE(cfg.read<bool>("general", "fullscreen") == true);
        REQUIRE(cfg.read<std::string>("player", "name") == "John Doe");
        REQUIRE(cfg.read<int>("player", "x") == 100);
        REQUIRE(cfg.read<int>("player", "y") == 200);
        REQUIRE(cfg.read<int>("player", "z") == 0);
        REQUIRE(cfg.read<int>("player", "z", 500) == 500);
        REQUIRE(cfg.sectionExists("general") == true);
        REQUIRE(cfg.sectionExists("player") == true);
        REQUIRE(cfg.sectionExists("AAAAAA") != true);
        REQUIRE(cfg.keyExists("general", "windowWidth") == true);
        REQUIRE(cfg.keyExists("general", "windowHeight") == true);
        REQUIRE(cfg.keyExists("general", "windowDepth") == false);
        REQUIRE(cfg.keyExists("asdasdadasd", "windowWidth") == false);
    }
    
    SECTION("write") {
        IniFile cfg("config.ini");
        cfg.write<std::string>("player", "name", "Ivan Petrov Vasilevishcyhhsh");
        cfg.write<bool>("player", "bool", true);
        cfg.write<int>("newSection", "value", 137);
        cfg.save("config.ini");
        REQUIRE(cfg.read<std::string>("player", "name") == "Ivan Petrov Vasilevishcyhhsh");
        REQUIRE(cfg.read<bool>("player", "bool") == true);
        REQUIRE(cfg.read<int>("newSection", "value") == 137);
    }
}