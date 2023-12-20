#include "User.hpp"
#include <iostream>
#include "../zadatak1/MojVektor.hpp"

User::User(std::string name, std::string lname, int id)
    : Name_{name}, LastName_{lname}, id_{id} {}
