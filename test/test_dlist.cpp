#define BOOST_TEST_MODULE pushpop
#include <dlist.h>
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE( pushpop1 )
{
    constexpr long size = 12;
    getit::rlist<int, size> rl;
    for ( int i = 0; i < size; ++i )
	rl.push( i );
    

    BOOST_CHECK( rl.pop() == 11 );       
    BOOST_CHECK( rl.pop() != 11 );       


    BOOST_REQUIRE( rl.pop() == 9 );       
    BOOST_REQUIRE( rl.pop() != 9 );       
    

}

class value
{
    int val;
    public:
	value() = default;
	value( int i ): val(i) {}
	~value( ) = default;
	bool operator == (int i) {return i == val;}
	bool operator != (int i) {return i != val;}
};

BOOST_AUTO_TEST_CASE( pushpop2 )
{
    constexpr long size = 12;
    getit::rlist<value, size> rl;
    for ( int i = 0; i < size; ++i )
	rl.push( i );
    

    BOOST_CHECK( rl.pop() == 11 );       
    BOOST_CHECK( rl.pop() == 11 );       

    BOOST_REQUIRE( rl.pop() == 9 );       
    BOOST_REQUIRE( rl.pop() == 9 );       
    
}


/*
    BOOST_CHECK( add( 2,2 ) == 4 );    						// #1 continues on error
    BOOST_REQUIRE( add( 2,2 ) == 4 );      					// #2 throws on error
    if( add( 2,2 ) != 4 ) BOOST_ERROR( "Ouch..." );            			// #3 continues on error
    if( add( 2,2 ) != 4 ) BOOST_FAIL( "Ouch..." );             			// #4 throws on error
    if( add( 2,2 ) != 4 ) throw "Ouch..."; 					// #5 throws on error
    BOOST_CHECK_MESSAGE( add( 2,2 ) == 4, "add(..) result: " << add( 2,2 ) ); 	// #6 continues on error
    BOOST_CHECK_EQUAL( add( 2,2 ), 4 );	  					// #7 continues on error
*/
