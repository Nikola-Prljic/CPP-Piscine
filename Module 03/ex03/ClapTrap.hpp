#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

# define IS_DEAD 0
# define IS_ALIVE 1

class ClapTrap
{

private:

	bool is_dead( void );
	void remove_ep( void );

public:

	int hp;
	int ep;
	int ad;
	std::string name;

	ClapTrap( std::string _name );
	~ClapTrap();
	void attack( const std::string& target );

	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

};

#endif