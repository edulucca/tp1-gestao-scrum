#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Email {
    private:
        string email;
        bool validar(const string&) const;
    public:
        void setEmail(string);
        string getEmail() const;
};
