/*
*+
*  Name:
*     fkeymap.c

*  Purpose:
*     Define a FORTRAN 77 interface to the AST KeyMap class.

*  Type of Module:
*     C source file.

*  Description:
*     This file defines FORTRAN 77-callable C functions which provide
*     a public FORTRAN 77 interface to the KeyMap class.

*  Routines Defined:
*     AST_ISAKEYMAP
*     AST_KEYMAP
*     AST_MAPPUT0<X>
*     AST_MAPPUT1<X>
*     AST_MAPGET0<X>
*     AST_MAPGET1<X>
*     AST_MAPREMOVE
*     AST_MAPSIZE
*     AST_MAPLENGTH
*     AST_MAPLENC
*     AST_MAPTYPE
*     AST_MAPKEY

*  Copyright:
*     <COPYRIGHT_STATEMENT>

*  Authors:
*     DSB: D.S. Berry (Starlink)

*  History:
*     13-NOV-2004 (DSB):
*        Original version.
*/

/* Define the astFORTRAN77 macro which prevents error messages from
   AST C functions from reporting the file and line number where the
   error occurred (since these would refer to this file, they would
   not be useful). */
#define astFORTRAN77

/* Header files. */
/* ============= */
#include "f77.h"                 /* FORTRAN <-> C interface macros (SUN/209) */
#include "c2f77.h"               /* F77 <-> C support functions/macros */
#include "error.h"               /* Error reporting facilities */
#include "memory.h"              /* Memory handling facilities */
#include "keymap.h"                 /* C interface to the KeyMap class */

F77_LOGICAL_FUNCTION(ast_isakeymap)( INTEGER(THIS), INTEGER(STATUS) ) {
   GENPTR_INTEGER(THIS)
   F77_LOGICAL_TYPE(RESULT);

   astAt( "AST_ISAKEYMAP", NULL, 0 );
   astWatchSTATUS(
      RESULT = astIsAKeyMap( astI2P( *THIS ) ) ? F77_TRUE : F77_FALSE;
   )
   return RESULT;
}

F77_INTEGER_FUNCTION(ast_keymap)(    CHARACTER(OPTIONS),
                                  INTEGER(STATUS)
                                  TRAIL(OPTIONS) ) {
   GENPTR_CHARACTER(OPTIONS)
   F77_INTEGER_TYPE(RESULT);
   char *options;
   int i;

   astAt( "AST_KEYMAP", NULL, 0 );
   astWatchSTATUS(
      options = astString( OPTIONS, OPTIONS_length );

/* Change ',' to '\n' (see AST_SET in fobject.c for why). */
      if ( astOK ) {
         for ( i = 0; options[ i ]; i++ ) {
            if ( options[ i ] == ',' ) options[ i ] = '\n';
         }
      }
      RESULT = astP2I( astKeyMap( "%s", options ) );
      astFree( options );
   )
   return RESULT;
}

F77_SUBROUTINE(ast_mapput0a)( INTEGER(THIS),
                              CHARACTER(KEY),
                              INTEGER(VALUE),
                              CHARACTER(COMMENT),
                              INTEGER(STATUS)
                              TRAIL(KEY)
                              TRAIL(COMMENT) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(VALUE)
   GENPTR_CHARACTER(COMMENT)
   char *comment, *key;

   astAt( "AST_MAPPUT0A", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      comment = astString( COMMENT, COMMENT_length );
      astMapPut0A( astI2P( *THIS ), key, astI2P( *VALUE ), comment );
      astFree( key );
      astFree( comment );
   )
}

F77_SUBROUTINE(ast_mapput0c)( INTEGER(THIS),
                              CHARACTER(KEY),
                              CHARACTER(VALUE),
                              CHARACTER(COMMENT),
                              INTEGER(STATUS)
                              TRAIL(KEY)
                              TRAIL(VALUE)
                              TRAIL(COMMENT) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_CHARACTER(VALUE)
   GENPTR_CHARACTER(COMMENT)
   char *comment, *value, *key;

   astAt( "AST_MAPPUT0C", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      value = astString( VALUE, VALUE_length );
      comment = astString( COMMENT, COMMENT_length );
      astMapPut0C( astI2P( *THIS ), key, value, comment );
      astFree( key );
      astFree( value );
      astFree( comment );
   )
}

F77_SUBROUTINE(ast_mapput0i)( INTEGER(THIS),
                              CHARACTER(KEY),
                              INTEGER(VALUE),
                              CHARACTER(COMMENT),
                              INTEGER(STATUS)
                              TRAIL(KEY)
                              TRAIL(COMMENT) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(VALUE)
   GENPTR_CHARACTER(COMMENT)
   char *comment, *key;

   astAt( "AST_MAPPUT0I", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      comment = astString( COMMENT, COMMENT_length );
      astMapPut0I( astI2P( *THIS ), key, *VALUE, comment );
      astFree( key );
      astFree( comment );
   )
}

F77_SUBROUTINE(ast_mapput0d)( INTEGER(THIS),
                              CHARACTER(KEY),
                              DOUBLE(VALUE),
                              CHARACTER(COMMENT),
                              INTEGER(STATUS)
                              TRAIL(KEY)
                              TRAIL(COMMENT) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_DOUBLE(VALUE)
   GENPTR_CHARACTER(COMMENT)
   char *comment, *key;

   astAt( "AST_MAPPUT0D", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      comment = astString( COMMENT, COMMENT_length );
      astMapPut0D( astI2P( *THIS ), key, *VALUE, comment );
      astFree( key );
      astFree( comment );
   )
}

F77_SUBROUTINE(ast_mapput1a)( INTEGER(THIS),
                              CHARACTER(KEY),
                              INTEGER(SIZE),
                              INTEGER_ARRAY(VALUE),
                              CHARACTER(COMMENT),
                              INTEGER(STATUS)
                              TRAIL(KEY)
                              TRAIL(COMMENT) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(SIZE)
   GENPTR_INTEGER_ARRAY(VALUE)
   GENPTR_CHARACTER(COMMENT)
   char *comment, *key;
   AstObject **values;
   int i;

   astAt( "AST_MAPPUT1A", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      comment = astString( COMMENT, COMMENT_length );

      values = astMalloc( sizeof( AstObject * )*(size_t)( *SIZE ));
      if( astOK ) {
         for( i = 0; i < *SIZE; i++ ) {
            values[ i ] = astI2P( VALUE[ i ] );
         }
      }

      astMapPut1A( astI2P( *THIS ), key, *SIZE, values, comment );
      astFree( values );
      astFree( key );
      astFree( comment );
   )
}

F77_SUBROUTINE(ast_mapput1c)( INTEGER(THIS),
                              CHARACTER(KEY),
                              INTEGER(SIZE),
                              CHARACTER_ARRAY(VALUE),
                              CHARACTER(COMMENT),
                              INTEGER(STATUS)
                              TRAIL(KEY)
                              TRAIL(VALUE)
                              TRAIL(COMMENT) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(SIZE)
   GENPTR_CHARACTER_ARRAY(VALUE)
   GENPTR_CHARACTER(COMMENT)
   char *comment, *key;
   const char **values;
   int i;

   astAt( "AST_MAPPUT1C", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      comment = astString( COMMENT, COMMENT_length );

      values = astMalloc( sizeof( const char * )*(size_t)( *SIZE ));
      if( astOK ) {
         for( i = 0; i < *SIZE; i++ ) {
            values[ i ] = astString( VALUE + i*VALUE_length, VALUE_length );
         }
      }

      astMapPut1C( astI2P( *THIS ), key, *SIZE, values, comment );

      if( astOK ) {
         for( i = 0; i < *SIZE; i++ ) astFree( (void *) values[ i ] );
      }
      astFree( (void *) values );
      astFree( key );
      astFree( comment );
   )
}



F77_SUBROUTINE(ast_mapput1i)( INTEGER(THIS),
                              CHARACTER(KEY),
                              INTEGER(SIZE),
                              INTEGER_ARRAY(VALUE),
                              CHARACTER(COMMENT),
                              INTEGER(STATUS)
                              TRAIL(KEY)
                              TRAIL(COMMENT) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(SIZE)
   GENPTR_INTEGER_ARRAY(VALUE)
   GENPTR_CHARACTER(COMMENT)
   char *comment, *key;

   astAt( "AST_MAPPUT1I", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      comment = astString( COMMENT, COMMENT_length );
      astMapPut1I( astI2P( *THIS ), key, *SIZE, VALUE, comment );
      astFree( key );
      astFree( comment );
   )
}


F77_SUBROUTINE(ast_mapput1d)( INTEGER(THIS),
                              CHARACTER(KEY),
                              INTEGER(SIZE),
                              DOUBLE_ARRAY(VALUE),
                              CHARACTER(COMMENT),
                              INTEGER(STATUS)
                              TRAIL(KEY)
                              TRAIL(COMMENT) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(SIZE)
   GENPTR_DOUBLE_ARRAY(VALUE)
   GENPTR_CHARACTER(COMMENT)
   char *comment, *key;

   astAt( "AST_MAPPUT1D", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      comment = astString( COMMENT, COMMENT_length );
      astMapPut1D( astI2P( *THIS ), key, *SIZE, VALUE, comment );
      astFree( key );
      astFree( comment );
   )
}


F77_LOGICAL_FUNCTION(ast_mapget0i)( INTEGER(THIS),
                                    CHARACTER(KEY),
                                    INTEGER(VALUE),
                                    INTEGER(STATUS)
                                    TRAIL(KEY) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(VALUE)
   F77_LOGICAL_TYPE(RESULT);
   char *key;

   astAt( "AST_MAPGET0I", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      RESULT = astMapGet0I( astI2P( *THIS ), key, VALUE ) ? F77_TRUE : F77_FALSE;
      astFree( key );
   )
   return RESULT;
}

F77_LOGICAL_FUNCTION(ast_mapget0d)( INTEGER(THIS),
                                    CHARACTER(KEY),
                                    DOUBLE(VALUE),
                                    INTEGER(STATUS)
                                    TRAIL(KEY) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_DOUBLE(VALUE)
   F77_LOGICAL_TYPE(RESULT);
   char *key;

   astAt( "AST_MAPGET0D", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      RESULT = astMapGet0D( astI2P( *THIS ), key, VALUE ) ? F77_TRUE : F77_FALSE;
      astFree( key );
   )
   return RESULT;
}

F77_LOGICAL_FUNCTION(ast_mapget0c)( INTEGER(THIS),
                                    CHARACTER(KEY),
                                    CHARACTER(VALUE),
                                    INTEGER(L),
                                    INTEGER(STATUS)
                                    TRAIL(KEY)
                                    TRAIL(VALUE) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_CHARACTER(VALUE)
   GENPTR_INTEGER(L)
   F77_LOGICAL_TYPE(RESULT);
   char *key;
   const char *value;
   int i;

   astAt( "AST_MAPGET0C", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      value = NULL;
      RESULT = astMapGet0C( astI2P( *THIS ), key, &value ) ? F77_TRUE : F77_FALSE;
      astFree( key );
      if( value ) {
         for( i = 0; value[ i ] && ( i < VALUE_length ); i++ ) {
            VALUE[ i ] = value[ i ];
         }
         *L = i;
      } else {
         *L = 0;
      }
   )
   return RESULT;
}

F77_LOGICAL_FUNCTION(ast_mapget0a)( INTEGER(THIS),
                                    CHARACTER(KEY),
                                    INTEGER(VALUE),
                                    INTEGER(STATUS)
                                    TRAIL(KEY) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(VALUE)
   F77_LOGICAL_TYPE(RESULT);
   char *key;
   AstObject *value;

   astAt( "AST_MAPGET0A", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      RESULT = astMapGet0A( astI2P( *THIS ), key, &value ) ? F77_TRUE : F77_FALSE;
      astFree( key );
      *VALUE = astP2I( value );
   )
   return RESULT;
}

F77_LOGICAL_FUNCTION(ast_mapget1i)( INTEGER(THIS),
                                    CHARACTER(KEY),
                                    INTEGER(MXVAL),
                                    INTEGER(NVAL),
                                    INTEGER_ARRAY(VALUE),
                                    INTEGER(STATUS)
                                    TRAIL(KEY) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(MXVAL)
   GENPTR_INTEGER(NVAL)
   GENPTR_INTEGER_ARRAY(VALUE)
   F77_LOGICAL_TYPE(RESULT);
   char *key;

   astAt( "AST_MAPGET1I", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      RESULT = astMapGet1I( astI2P( *THIS ), key, *MXVAL, NVAL, VALUE ) ? F77_TRUE : F77_FALSE;
      astFree( key );
   )
   return RESULT;
}


F77_LOGICAL_FUNCTION(ast_mapget1d)( INTEGER(THIS),
                                    CHARACTER(KEY),
                                    INTEGER(MXVAL),
                                    INTEGER(NVAL),
                                    DOUBLE_ARRAY(VALUE),
                                    INTEGER(STATUS)
                                    TRAIL(KEY) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(MXVAL)
   GENPTR_INTEGER(NVAL)
   GENPTR_DOUBLE_ARRAY(VALUE)
   F77_LOGICAL_TYPE(RESULT);
   char *key;

   astAt( "AST_MAPGET1I", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      RESULT = astMapGet1D( astI2P( *THIS ), key, *MXVAL, NVAL, VALUE ) ? F77_TRUE : F77_FALSE;
      astFree( key );
   )
   return RESULT;
}


F77_LOGICAL_FUNCTION(ast_mapget1a)( INTEGER(THIS),
                                    CHARACTER(KEY),
                                    INTEGER(MXVAL),
                                    INTEGER(NVAL),
                                    INTEGER_ARRAY(VALUE),
                                    INTEGER(STATUS)
                                    TRAIL(KEY) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(MXVAL)
   GENPTR_INTEGER(NVAL)
   GENPTR_INTEGER_ARRAY(VALUE)
   F77_LOGICAL_TYPE(RESULT);
   char *key;
   AstObject **values;
   int i;

   values = astMalloc( sizeof( AstObject *)*(size_t) *MXVAL );

   astAt( "AST_MAPGET1A", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      RESULT = astMapGet1A( astI2P( *THIS ), key, *MXVAL, NVAL, values ) ? F77_TRUE : F77_FALSE;
      astFree( key );

      for( i = 0; i < *NVAL; i++ ) VALUE[ i ] = astP2I( values[ i ] );
      astFree( values );

   )
   return RESULT;
}


F77_LOGICAL_FUNCTION(ast_mapget1c)( INTEGER(THIS),
                                    CHARACTER(KEY),
                                    INTEGER(MXVAL),
                                    INTEGER(NVAL),
                                    CHARACTER_ARRAY(VALUE),
                                    INTEGER(STATUS)
                                    TRAIL(KEY)
                                    TRAIL(VALUE) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   GENPTR_INTEGER(MXVAL)
   GENPTR_INTEGER(NVAL)
   GENPTR_CHARACTER_ARRAY(VALUE)
   F77_LOGICAL_TYPE(RESULT);
   char *key;
   char *values, *c, *d;
   int i, j, term;

   values = astMalloc( sizeof( char )*(size_t) (*MXVAL)*( VALUE_length + 1 ) );

   astAt( "AST_MAPGET1A", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      RESULT = astMapGet1C( astI2P( *THIS ), key, VALUE_length + 1, *MXVAL, 
                            NVAL, values ) ? F77_TRUE : F77_FALSE;
      astFree( key );

/* Loop round each string value returned in the array */
      c = values;
      d = VALUE;
      for( i = 0; i < *NVAL; i++ ) {

/* Loop round each of character in the "i"th element of the returned
   array. Copy characters from the work array until a terminating null is
   found. Replace this null by a space and replace all subsequent
   characters by spaces up to the end of the returned array element. */
         term = 0;
         for( j = 0; j < VALUE_length; j++, d++, c++ ) {
            if( term ) {
               *d = ' ';
            } else if( (*d = *c) == 0 ) {
               *d = ' ';
               term = 1;
            } 
         }

/* Skip over the extra character at the end of each element in the work 
   array. */
         c++;

      }
      astFree( values );

   )
   return RESULT;
}


F77_SUBROUTINE(ast_mapremove)( INTEGER(THIS),
                               CHARACTER(KEY),
                               INTEGER(STATUS)
                               TRAIL(KEY) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   char *key;

   astAt( "AST_MAPREMOVE", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      astMapRemove( astI2P( *THIS ), key );
      astFree( key );
   )
}

F77_INTEGER_FUNCTION(ast_mapsize)( INTEGER(THIS), INTEGER(STATUS) ) {
   GENPTR_INTEGER(THIS)
   F77_INTEGER_TYPE(RESULT);

   astAt( "AST_MAPSIZE", NULL, 0 );
   astWatchSTATUS(
      RESULT = astMapSize( astI2P( *THIS ) );
   )
   return RESULT;
}

F77_INTEGER_FUNCTION(ast_maplength)( INTEGER(THIS), 
                                     CHARACTER(KEY),
                                     INTEGER(STATUS)
                                     TRAIL(KEY) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   F77_INTEGER_TYPE(RESULT);
   char *key;

   astAt( "AST_MAPLENGTH", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      RESULT = astMapLength( astI2P( *THIS ), key );
      astFree( key );
   )
   return RESULT;
}

F77_INTEGER_FUNCTION(ast_maplenc)( INTEGER(THIS), 
                                   CHARACTER(KEY),
                                   INTEGER(STATUS)
                                   TRAIL(KEY) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   F77_INTEGER_TYPE(RESULT);
   char *key;

   astAt( "AST_MAPLENGTH", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      RESULT = astMapLenC( astI2P( *THIS ), key );
      astFree( key );
   )
   return RESULT;
}

F77_INTEGER_FUNCTION(ast_maptype)( INTEGER(THIS), 
                                   CHARACTER(KEY),
                                   INTEGER(STATUS)
                                   TRAIL(KEY) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   F77_INTEGER_TYPE(RESULT);
   char *key;

   astAt( "AST_MAPLENGTH", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      RESULT = astMapType( astI2P( *THIS ), key );
      astFree( key );
   )
   return RESULT;
}

F77_LOGICAL_FUNCTION(ast_maphaskey)( INTEGER(THIS), 
                                     CHARACTER(KEY),
                                     INTEGER(STATUS)
                                     TRAIL(KEY) ) {
   GENPTR_INTEGER(THIS)
   GENPTR_CHARACTER(KEY)
   F77_LOGICAL_TYPE(RESULT);
   char *key;

   astAt( "AST_MAPHASKEY", NULL, 0 );
   astWatchSTATUS(
      key = astString( KEY, KEY_length );
      RESULT = astMapHasKey( astI2P( *THIS ), key ) ? F77_TRUE : F77_FALSE;

      astFree( key );
   )
   return RESULT;
}

/* NO_CHAR_FUNCTION indicates that the f77.h method of returning a
   character result doesn't work, so add an extra argument instead and
   wrap this function up in a normal FORTRAN 77 function (in the file
   keymap.f). */
#if NO_CHAR_FUNCTION
F77_SUBROUTINE(ast_mapkey_a)( CHARACTER(RESULT),
#else
F77_SUBROUTINE(ast_mapkey)( CHARACTER_RETURN_VALUE(RESULT),
#endif
                          INTEGER(THIS),
                          INTEGER(INDEX),
#if NO_CHAR_FUNCTION
                          INTEGER(STATUS)
                          TRAIL(RESULT) ) {
#else
                          INTEGER(STATUS) ) {
#endif
   GENPTR_CHARACTER(RESULT)
   GENPTR_INTEGER(THIS)
   GENPTR_INTEGER(INDEX)
   const char *result; 
   int i;

   astAt( "AST_MAPKEY", NULL, 0 );
   astWatchSTATUS(
      result = astMapKey( astI2P( *THIS ), *INDEX - 1 );
      i = 0;
      if ( astOK ) {             /* Copy result */
         for ( ; result[ i ] && i < RESULT_length; i++ ) {
            RESULT[ i ] = result[ i ];
         }
      }
      while ( i < RESULT_length ) RESULT[ i++ ] = ' '; /* Pad with blanks */
   )
}



