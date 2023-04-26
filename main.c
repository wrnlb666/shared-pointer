#include "sp.h"
#include <stdio.h>

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

    return 0;
}