#include "sp.h"

void sp_cleanup( sp_t* sp )
{
    if ( sp == NULL )   return;
    if ( *sp == NULL )  return;
    if ( (*sp)->ref == 0 ) return;
    (*sp)->ref--;
    if ( ( (*sp)->ref ) == 0 )
    {
        (*sp)->des( (*sp)->ptr );
        free(*sp);
        *sp = NULL;
    }
}

void sp_realloc( sp_t sp, size_t size )
{
    sp->ptr = realloc( sp->ptr, size );
}


