#if !defined( ERROR_INCLUDED )   /* Include this file only once */
#define ERROR_INCLUDED 1
/*
*+
*  Name:
*     error.h

*  Purpose:
*     Define the interface to the Error module.

*  Description:
*     This module defines functions which implement error handling and
*     reporting of error messages from within the AST library. A
*     simple public interface is included to allow the AST error
*     status to be tested and cleared after an error.
*
*     Note that this module is not a class implementation, although it
*     resembles one.

*  Functions Defined:
*     Public:
*        astSetStatus
*           Set the AST error status to an explicit value.
*        astWatch
*           Identify a new error status variable for the AST library.
*
*     Protected:
*        astAt
*           Store a routine, file and line number context in case of error.
*        astError
*           Set the AST error status and report an error message.
*        astReporting
*           Controls the reporting of error messages.

*  Macros Defined:
*     Public:
*        astClearStatus
*           Clear an AST error condition.
*        astOK
*           Test whether AST routines have been successful.
*        astStatus
*           Obtain the AST error status value.
*
*     Protected:
*        AST__FAC
*           A "facility" number unique to this library.

*  Copyright:
*     <COPYRIGHT_STATEMENT>

*  Authors:
*     RFWS: R.F. Warren-Smith (Starlink)

*  History:
*     2-JAN-1996 (RFWS):
*        Original version.
*     26-JAN-1996 (RFWS):
*        Added function interfaces.
*     14-JUN-1996 (RFWS):
*        Added AST__FAC and astAt.
*     20-JUN-1996 (RFWS):
*        Added astSetStatus.
*     16-JUL-1996 (RFWS):
*        Added astWatch.
*     18-MAR-1998 (RFWS):
*        Make interface available for writing foreign language and
*        graphics interfaces, etc.
*     27-NOV-2002 (DSB):
*        Added astReporting.
*-
*/

/* Macros. */
/* ======= */
/* Define a facility number that is unique to this library. */
#if defined(astCLASS)            /* Protected */
#define AST__FAC (1521)
#endif

/* Function prototypes. */
/* ==================== */
/* Prototypes for the functions provided by this module. */
int *astWatch_( int * );
int astOK_( void );
int astStatus_( void );
void astClearStatus_( void );
void astSetStatus_( int );

#if defined(astCLASS) || 1       /* Nominally protected, but available for */
                                 /* use in developing (e.g.) foreign */
                                 /* language or graphics interfaces. */
void astAt_( const char *, const char *, int, int );
void astError_( int, const char *, ... );
int astReporting_( int );
#endif

/* Function interfaces. */
/* ==================== */
/* These wrap up the functions defined by this module to make them
   easier to use. */
#define astClearStatus astClearStatus_()
#define astOK astOK_()
#define astSetStatus(status) astSetStatus_(status)
#define astStatus astStatus_()
#define astWatch(status_address) astWatch_(status_address)

#if defined(astCLASS) 
#define astAt(routine,file,line) astAt_(routine,file,line,0)
#else
#define astAt(routine,file,line) astAt_(routine,file,line,1)
#endif

#if defined(astCLASS) || 1       /* Nominally protected, but available for */
                                 /* use in developing (e.g.) foreign */
                                 /* language or graphics interfaces. */
#define astError astError_
#define astReporting astReporting_
#endif
#endif