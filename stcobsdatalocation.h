#if !defined( STCOBSDATALOCATION_INCLUDED ) /* Include this file only once */
#define STCOBSDATALOCATION_INCLUDED
/*
*+
*  Name:
*     stcobsdatalocation.h

*  Type:
*     C include file.

*  Purpose:
*     Define the interface to the StcObsDataLocation class.

*  Invocation:
*     #include "stcobsdatalocation.h"

*  Description:
*     This include file defines the interface to the StcObsDataLocation class 
*     and provides the type definitions, function prototypes and macros,
*     etc.  needed to use this class.
*
*     The StcObsDataLocation class is a sub-class of Stc used to describe 
*     the an observation contained in some VO resource.
*
*     See http://hea-www.harvard.edu/~arots/nvometa/STC.html

*  Inheritance:
*     The StcObsDataLocation class inherits from the Stc class.

*  Feature Test Macros:
*     astCLASS
*        If the astCLASS macro is undefined, only public symbols are
*        made available, otherwise protected symbols (for use in other
*        class implementations) are defined. This macro also affects
*        the reporting of error context information, which is only
*        provided for external calls to the AST library.

*  Copyright:
*     <COPYRIGHT_STATEMENT>

*  Licence:
*     This program is free software; you can redistribute it and/or
*     modify it under the terms of the GNU General Public Licence as
*     published by the Free Software Foundation; either version 2 of
*     the Licence, or (at your option) any later version.
*     
*     This program is distributed in the hope that it will be
*     useful,but WITHOUT ANY WARRANTY; without even the implied
*     warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
*     PURPOSE. See the GNU General Public Licence for more details.
*     
*     You should have received a copy of the GNU General Public Licence
*     along with this program; if not, write to the Free Software
*     Foundation, Inc., 59 Temple Place,Suite 330, Boston, MA
*     02111-1307, USA

*  Authors:
*     DSB: David S. Berry (Starlink)

*  History:
*     25-APR-2005 (DSB):
*        Original version.
*-
*/

/* Include files. */
/* ============== */
/* Interface definitions. */
/* ---------------------- */
#include "stc.h"                 /* Coordinate stcs (parent class) */
#include "pointlist.h"           /* Points within coordinate systems */

#if defined(astCLASS)            /* Protected */
#include "channel.h"             /* I/O channels */
#endif

/* C header files. */
/* --------------- */
#if defined(astCLASS)            /* Protected */
#include <stddef.h>
#endif

/* Type Definitions. */
/* ================= */
/* StcObsDataLocation structure. */
/* ----------------------------- */
/* This structure contains all information that is unique to each object in
   the class (e.g. its instance variables). */
typedef struct AstStcObsDataLocation {

/* Attributes inherited from the parent class. */
   AstStc stc;             /* Parent class structure */

/* Attributes specific to the StcObsDataLOcation class. */
   AstPointList *obs;      /* Observatory position */

} AstStcObsDataLocation;

/* Virtual function table. */
/* ----------------------- */
/* This table contains all information that is the same for all
   objects in the class (e.g. pointers to its virtual functions). */
#if defined(astCLASS)            /* Protected */
typedef struct AstStcObsDataLocationVtab {

/* Properties (e.g. methods) inherited from the parent class. */
   AstStcVtab stc_vtab;    /* Parent class virtual function table */

/* Unique flag value to determine class membership. */
   int *check;                   /* Check value */

/* Properties (e.g. methods) specific to this class. */
   void (* StcSetObs)( AstStcObsDataLocation *, AstPointList * );

} AstStcObsDataLocationVtab;
#endif

/* Function prototypes. */
/* ==================== */
/* Prototypes for standard class functions. */
/* ---------------------------------------- */
astPROTO_CHECK(StcObsDataLocation)          /* Check class membership */
astPROTO_ISA(StcObsDataLocation)            /* Test class membership */

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
AstStcObsDataLocation *astStcObsDataLocation_( void *, int, AstKeyMap **, const char *, ... );
#else
AstStcObsDataLocation *astStcObsDataLocationId_( void *, int, AstKeyMap **, const char *, ... );
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
AstStcObsDataLocation *astInitStcObsDataLocation_( void *, size_t, int, AstStcObsDataLocationVtab *, const char *, AstRegion *, int, AstKeyMap ** );

/* Vtab initialiser. */
void astInitStcObsDataLocationVtab_( AstStcObsDataLocationVtab *, const char * );

/* Loader. */
AstStcObsDataLocation *astLoadStcObsDataLocation_( void *, size_t, AstStcObsDataLocationVtab *,
                                   const char *, AstChannel * );

#endif

/* Prototypes for member functions. */
/* -------------------------------- */


#if defined(astCLASS)            /* Protected */
void astStcSetObs_( AstStcObsDataLocation *, AstPointList * );
#endif

/* Function interfaces. */
/* ==================== */
/* These macros are wrap-ups for the functions defined by this class
   to make them easier to invoke (e.g. to avoid type mis-matches when
   passing pointers to objects from derived classes). */

/* Interfaces to standard class functions. */
/* --------------------------------------- */
/* Some of these functions provide validation, so we cannot use them
   to validate their own arguments. We must use a cast when passing
   object pointers (so that they can accept objects from derived
   classes). */

/* Check class membership. */
#define astCheckStcObsDataLocation(this) astINVOKE_CHECK(StcObsDataLocation,this)

/* Test class membership. */
#define astIsAStcObsDataLocation(this) astINVOKE_ISA(StcObsDataLocation,this)

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
#define astStcObsDataLocation astINVOKE(F,astStcObsDataLocation_)
#else
#define astStcObsDataLocation astINVOKE(F,astStcObsDataLocationId_)
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
#define astInitStcObsDataLocation(mem,size,init,vtab,name,region,ncoords,coords) \
astINVOKE(O,astInitStcObsDataLocation_(mem,size,init,vtab,name,region,ncoords,coords))

/* Vtab Initialiser. */
#define astInitStcObsDataLocationVtab(vtab,name) astINVOKE(V,astInitStcObsDataLocationVtab_(vtab,name))
/* Loader. */
#define astLoadStcObsDataLocation(mem,size,vtab,name,channel) \
astINVOKE(O,astLoadStcObsDataLocation_(mem,size,vtab,name,astCheckChannel(channel)))
#endif

/* Interfaces to public member functions. */
/* -------------------------------------- */
/* Here we make use of astCheckStcObsDataLocation to validate StcObsDataLocation pointers
   before use.  This provides a contextual error report if a pointer
   to the wrong sort of Object is supplied. */

#if defined(astCLASS)            /* Protected */
#define astStcSetObs(this,obs) \
astINVOKE(V,astStcSetObs_(astCheckStcObsDataLocation(this),obs?astCheckPointList(obs):NULL))
#endif
#endif
