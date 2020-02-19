#include <dlist.h>
#include <iostream>

int main( )
{
    constexpr long size = 12;
    getit::rlist<int, size> rl;
    for ( int i = 0; i < size; ++i )
	rl.push( i );

    std::cout << rl << std::endl;

    std::cout << rl.pop() << std::endl;
    std::cout << rl.pop() << std::endl;
    std::cout << rl.pop() << std::endl;
    std::cout << rl.pop() << std::endl;

    std::cout << rl << std::endl;
    std::cout << rl.pop() << std::endl;
    std::cout << rl << std::endl;

    std::cout << rl.pop() << std::endl;
    std::cout << rl << std::endl;
    std::cout << rl.pop() << std::endl;
    std::cout << rl << std::endl;
    std::cout << rl.pop() << std::endl;
    std::cout << rl << std::endl;
    std::cout << rl.pop() << std::endl;
    std::cout << rl << std::endl;


    return 0;

}



