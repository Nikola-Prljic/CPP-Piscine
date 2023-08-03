#include "Harl.hpp"

Harl::Harl( void ) {}

Harl::~Harl( void ) {}

Harl::lvl Harl::getInput( std::string level )
{
    if ( level == "DEBUG" ) return DEBUG;
    if ( level == "INFO" ) return INFO;
    if ( level == "WARNING" ) return WARNING;
    if ( level == "ERROR" ) return ERROR;
    return DEFAULT;
}

void Harl::complain( std::string level )
{
    switch (getInput(level))
    {
        case DEFAULT:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; break;
        case DEBUG:
            cmd("DEBUG", &Harl::debug);
        case INFO:
            cmd("INFO", &Harl::info);
        case WARNING:
            cmd("WARNING", &Harl::warning);
        case ERROR:
            cmd("ERROR", &Harl::error);
    }
}

void Harl::cmd( std::string type, void(Harl::*func)()){
    std::cout << "[ " << type << " ]" << std::endl;
    (this->*func)();
}

void Harl::debug(){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(){
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(){
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
