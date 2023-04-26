#include "sp.h"
#include <stdio.h>
#include <string.h>

void de( void* arr )
{
    free( arr );
}

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
    sp_make( temp, sizeof (char) * 13, de );

    char* x = sp_ptr(temp);
    memcpy( x, "foo", 4 );
    strcpy( x, "foo" );

    return sp_return(temp);
}

int main( void )
{
    sp_make( arr, sizeof (int) * 10, de );

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