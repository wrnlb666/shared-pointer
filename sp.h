#ifndef __SP_H__
#define __SP_H__

#ifndef __GNUC__
    #error This Library needs the compiler to support GNU C to function. 
#endif  // __GNUC__

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

typedef struct sp_t *sp_t;

// return the raw pointer of the shared pointer
#define sp_ptr( /* sp_t */ src )

// make a `sp_t` that is called "name" that user has inputted. 
// name should not be declared before
// size should be in bytes
// destructor is a function that will be used to free the object
#define sp_make( /* undeclared sp_t */ name, /* size_t */ size, /* void (*)(void*) */ destructor )

// copy constructor? When build a new shared pointer upon existing pointer, use `sp_copy`
// The only exception is when build a new shared pointer upon the returned `sp_t` from a function returned by `sp_return`
// Detail will be shown later
#define sp_copy( /* undeclared sp_t */ dest, /* sp_t */ src )

// When returning a shared pointer that is constructed inside the current function, use the syntax `return sp_return(sp)`
// Note that when receiving the shared pointer, you should use `sp_recv` but not `sp_copy`
#define sp_return( /* sp_t */ src )

// used to receive the shared pointer returned from `sp_return`, have the syntax `sp_recv(sp) = foo()`
#define sp_recv( /* undeclared sp_t */ dest )

// used to realloc `size` bytes of memory. 
void sp_realloc( sp_t sp, size_t size );








struct sp_t
{
    void*   ptr;
    void    (*des)(void*);
    int     ref;
};
void sp_cleanup( sp_t* sp );


#undef sp_ptr
#define sp_ptr( src )                                   \
src->ptr


#undef sp_make
#define sp_make( name, size, destructor )               \
__attribute__(( cleanup( sp_cleanup ) ))                \
sp_t name = malloc( sizeof ( struct sp_t ) );           \
name->ptr   = malloc( size );                           \
name->des   = destructor;                               \
name->ref   = 1


#undef sp_copy
#define sp_copy( dest, src )                            \
__attribute__(( cleanup( sp_cleanup ) ))                \
sp_t dest = src;                                        \
dest->ref++


#undef sp_return
#define sp_return( src )                                \
( ++src->ref, src )


#undef sp_recv
#define sp_recv( dest )                                 \
__attribute__(( cleanup( sp_cleanup ) ))                \
sp_t dest 


#endif  // __SP_H__
