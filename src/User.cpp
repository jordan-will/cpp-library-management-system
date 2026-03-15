#include "User.h"
#include <stdexcept>

User::User() : id(0){}
User::User(
    int id,
    const std::string& name,
    const std::string& email
): id(id), name(name), email(email){
    validate(id, name, email);
}

//getters
int User::getId() const {
    return id;
}

const std::string& User::getEmail() const{
    return email;
}

const std::string& User::getName() const {
    return name;
} 

//setters
void User::setName(const std::string& name){
    if(name.empty()){
        throw std::runtime_error("Name cannot bee empty");
    }
    this->name = name;
}

void User::setEmail(const std::string& email){
    if(email.empty()){
        throw std::runtime_error("Email cannot be empty");
    }
    this->email = email;
}

//validation
void User::validate(
    int id,
    const std::string& name,
    const std::string& email
){
    if(id <= 0){
        throw std::runtime_error("Invalid user Id");
    }
    if(name.empty()){
        throw std::runtime_error("Name cannot be empty");
    }
    if(email.empty()){
        throw std::runtime_error("Email cannot be empty");
    }
}