#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : _target(target), AForm(145, 137, "ShrubberyCreationForm")
{
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return ;
}

void ShrubberyCreationForm::createFile( std::string target_name, std::string write_in_file ) const
{
    std::fstream form;

    form.open( target_name += "_shrubbery", std::ios::out );
	if (!form)
		std::cout << "Error: File not created!";
    else
    {
        form << write_in_file;
        form.close();
    }
    return ;
}

std::string makeTreeLine(int space, int star)
{
    int i;
    std::string line;

    for(i = 0; i < space; i++)
        line.append(" ");
    for(i = 0; i < star; i++)
        line.append("*");
    line += '\n';
    return line;
}

std::string makeOneTree()
{
    std::string tree;
    int star = 12;
    int space = 1;

    for(int i = 0; i < 7; i++)
    {
        tree += makeTreeLine(star--, space);
        space += 2;
    }
    tree += makeTreeLine(11, 3);
    tree += makeTreeLine(11, 3);
    tree += '\n';
    return tree;
}

std::string ShrubberyCreationForm::writeAsciiTree( int how_much ) const
{
    std::string tree;

    for(int i = 0; i < how_much; i++)
        tree += makeOneTree();
    return tree;
}

void ShrubberyCreationForm::execute( const Bureaucrat& executor ) const
{
    try{
        isExecutable( executor );
        if( getIsSigned() == false)
            throw AForm::NotSigned();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    createFile(_target, writeAsciiTree(7));
    return ;
}