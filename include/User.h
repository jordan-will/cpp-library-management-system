#ifndef USER_H
#define USER_H

#include <string>

class User{
private:
    int id;
    std::string name;
    std::string email;
public:
    User();
    User(
        int id,
        const std::string& name,
        const std::string& email
    );

    //getters
    int getId() const;
    const std::string& getName() const;
    const std::string& getEmail() const;

    //setters
    void setName(const std::string& name);
    void setEmail(const std::string& email);

    static void validate(
        int id,
        const std::string& name,
        const std::string& email
    );
};

#endif