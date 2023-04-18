#include "MateriaSource.hpp"

int main( void )
{
    /* IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    AMateria* ice;
    ice = new Ice();
    AMateria* ice1;
    ice1 = new Ice();

    ICharacter *fio = new Character("Fio");
    fio->equip(ice);
    fio->equip(ice1);
    fio->unequip(69);
    fio->use(1, *fio);
    fio->use(69, *fio);
    fio->unequip(1);
    delete fio;
    delete src;
    // AMateria a; should not work ! */


    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    
    return 0;
}