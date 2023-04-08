#include "Harl.hpp"

Harl::Harl( void )
{
    return ;
}

Harl::~Harl( void )
{
    return ;
}


void Harl::complain( std::string level )
{
    cmd("debug", level, &Harl::debug);
    cmd("info", level, &Harl::info);
    cmd("warning", level, &Harl::warning);
    cmd("error", level, &Harl::error);
    return ;
}

void Harl::cmd(std::string compare, std::string level, void(Harl::*func)())
{
    if(compare == level)
        (this->*func)();
    return ;    
}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    return ;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    return ;
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
    return ;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    return ;
}
