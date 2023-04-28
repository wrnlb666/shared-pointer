#include "sp.h"
#include <stdio.h>
#include <string.h>

sp_t foo( sp_t ptr )
{
    int* temp = sp_ptr( ptr );

    for ( int i = 0; i < 10; i++ )
    {
        temp[i] = i;
    }
    return ptr;
}

sp_t test()
{
    sp_make( temp, free );
    sp_ptr(temp) = malloc( 12 );

    strcpy( sp_ptr(temp), "Hello World" );

    return sp_return(temp);
}

int main( void )
{
    sp_make( arr, free );
    sp_ptr(arr) = malloc( sizeof(10 ) );

    sp_copy( xx, foo(arr));

    int* temp = sp_ptr( xx );

    for ( int i = 0; i < 10; i++ )
    {
        printf( "%-3d", temp[i] );   
    }
    puts("");
    
    sp_recv(xd) = test();
    puts( sp_ptr(xd) );

    return 0;
}
