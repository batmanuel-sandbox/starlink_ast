/*
*class++
*  Name:
*     Plot

*  Purpose:
*     Provide facilities for graphical output.

*  Constructor Function:
c     astPlot
f     AST_PLOT

*  Description:
*     This class provides facilities for producing graphical output.
*     A Plot is a specialised form of FrameSet, in which the base
*     Frame describes a "graphical" coordinate system and is
*     associated with a rectangular plotting area in the underlying
*     graphics system. This plotting area is where graphical output
*     appears. It is defined when the Plot is created.
*
*     The current Frame of a Plot describes a "physical" coordinate
*     system, which is the coordinate system in which plotting
*     operations are specified. The results of each plotting operation
*     are automatically transformed into graphical coordinates so as
*     to appear in the plotting area (subject to any clipping which
*     may be in effect).
*
*     Because the Mapping between physical and graphical coordinates
*     may often be non-linear, or even discontinuous, most plotting
*     does not result in simple straight lines. The basic plotting
*     element is therefore not a straight line, but a geodesic curve
c     (see astCurve and astPolyCurve). A Plot also provides facilities for 
c     drawing markers or symbols (astMark), text (astText) and grid lines
c     (astGridLine). It is also possible to draw curvilinear axes with
c     optional coordinate grids (astGrid).
f     (see AST_CURVE and AST_POLYCURVE). A Plot also provides facilities 
f     for drawing markers or symbols (AST_MARK), text (AST_TEXT) and grid 
f     lines (AST_GRIDLINE). It is also possible to draw curvilinear axes
f     with optional coordinate grids (AST_GRID).
*     A range of Plot attributes is available to allow precise control
*     over the appearance of graphical output produced by these
c     functions.
f     routines.
*
*     You may select different physical coordinate systems in which to
*     plot (including the native graphical coordinate system itself)
*     by selecting different Frames as the current Frame of a Plot,
*     using its Current attribute.  You may also set up clipping (see
c     astClip) to limit the extent of any plotting you perform, and
f     AST_CLIP) to limit the extent of any plotting you perform, and
*     this may be done in any of the coordinate systems associated
*     with the Plot, not necessarily the one you are plotting in.
*
*     Like any FrameSet, a Plot may also be used as a Frame. In this
*     case, it behaves like its current Frame, which describes the
*     physical coordinate system.
*
*     When used as a Mapping, a Plot describes the inter-relation
*     between graphical coordinates (its base Frame) and physical
*     coordinates (its current Frame).  It differs from a normal
*     FrameSet, however, in that an attempt to transform points which
*     lie in clipped areas of the Plot will result in bad coordinate
*     values (AST__BAD).

*  Inheritance:
*     The Plot class inherits from the FrameSet class.

*  Attributes:
*     In addition to those attributes common to all FrameSets, every
*     Plot also has the following attributes:
*
*     - Border: Draw a border around valid regions of a Plot?
*     - ClipOp: Combine Plot clipping limits using a boolean OR?
*     - Colour(element): Colour index for a Plot element
*     - DrawAxes: Draw axes for a Plot?
*     - DrawTitle: Draw a title for a Plot?
*     - Edge(axis): Which edges to label in a Plot
*     - Font(element): Character font for a Plot element
*     - Gap(axis): Interval between major axis values of a Plot
*     - Grid: Draw grid lines for a Plot?
*     - LabelAt(axis): Where to place numerical labels for a Plot
*     - LabelUnits(axis): Use axis unit descriptions in a Plot?
*     - LabelUp(axis): Draw numerical Plot labels upright?
*     - Labelling: Label and tick placement option for a Plot
*     - MajTickLen(axis): Length of major tick marks for a Plot
*     - MinTickLen(axis): Length of minor tick marks for a Plot
*     - MinTick(axis): Density of minor tick marks for a Plot
*     - NumLab(axis): Draw numerical axis labels for a Plot?
*     - NumLabGap(axis): Spacing of numerical axis labels for a Plot
*     - Size(element): Character size for a Plot element
*     - Style(element): Line style for a Plot element
*     - TextLab(axis): Draw descriptive axis labels for a Plot?
*     - TextLabGap(axis): Spacing of descriptive axis labels for a Plot
*     - TickAll: Draw tick marks on all edges of a Plot?
*     - TitleGap: Vertical spacing for a Plot title
*     - Tol: Plotting tolerance
*     - Width(element): Line width for a Plot element

*  Functions:
c     In addition to those functions applicable to all FrameSets, the
c     following functions may also be applied to all Plots:
f     In addition to those routines applicable to all FrameSets, the
f     following routines may also be applied to all Plots:
*
c     - astBorder: Draw a border around valid regions of a Plot
c     - astClip: Set up or remove clipping for a Plot
c     - astCurve: Draw a geodesic curve
c     - astGrid: Draw a set of labelled coordinate axes
c     - astGridLine: Draw a grid line (or axis) for a Plot
c     - astMark: Draw a set of markers for a Plot
c     - astPolyCurve: Draw a series of connected geodesic curves
c     - astText: Draw a text string for a Plot
f     - AST_BORDER: Draw a border around valid regions of a Plot
f     - AST_CLIP: Set up or remove clipping for a Plot
f     - AST_CURVE: Draw a geodesic curve
f     - AST_GRID: Draw a set of labelled coordinate axes
f     - AST_GRIDLINE: Draw a grid line (or axis) for a Plot
f     - AST_MARK: Draw a set of markers for a Plot
f     - AST_POLYCURVE: Draw a series of connected geodesic curves
f     - AST_TEXT: Draw a text string for a Plot

*  Graphical Elements:
*     The colour index, character font, character size, line style and
*     line width used for plotting can be set independently for
*     various elements of the graphical output produced by a Plot.
*     The different graphical elements are identified by appending the
*     following strings as subscripts to the Plot attributes
*     Colour(element), Font(element), Size(element), Style(element)
*     and Width(element). These strings are case-insensitive and
*     unambiguous abbreviations may be used:
*
c     - Border: The Plot border drawn using astBorder or astGrid
f     - Border: The Plot border drawn using AST_BORDER or AST_GRID
c     - Grid: Grid lines drawn using astGridLine or astGrid
f     - Grid: Grid lines drawn using AST_GRIDLINE or AST_GRID
c     - Curves: Geodesic curves drawn using astCurve or astPolyCurve
f     - Curves: Geodesic curves drawn using AST_CURVE or AST_POLYCURVE
c     - NumLab: Numerical axis labels drawn using astGrid
f     - NumLab: Numerical axis labels drawn using AST_GRID
c     - TextLab: Descriptive axis labels drawn using astGrid
f     - TextLab: Descriptive axis labels drawn using AST_GRID
c     - Title: The Plot title drawn using astGrid
f     - Title: The Plot title drawn using AST_GRID
c     - Markers: Graphical markers (symbols) drawn using astMark
f     - Markers: Graphical markers (symbols) drawn using AST_MARK
c     - Strings: Text strings drawn using astText
f     - Strings: Text strings drawn using AST_TEXT
c     - Ticks: Tick marks (both major and minor) drawn using astGrid
f     - Ticks: Tick marks (both major and minor) drawn using AST_GRID
c     - Axes: Axis lines drawn through tick marks within the plotting area
c       using astGrid
f     - Axes: Axis lines drawn through tick marks within the plotting area
f     using AST_GRID

*  Copyright:
*     <COPYRIGHT_STATEMENT>

*  Authors:
*     DSB: D.S. Berry (Starlink)
*     RFWS: R.F. Warren-Smith (Starlink)

*  History:
*     18-SEP-1996 (DSB):
*        Original version.
*     25-FEB-1997 (RFWS):
*        Tidied all public prologues.
*     18-AUG-1997 (DSB):
*        Changes made to ensure that the first label on each axis is 
*        never abbreviated, and to avoid segmentation violation when NumLab
*        is set to zero.
*     1-SEP-1997 (DSB):
*        astGetGap changed so that it returns the default value which will 
*        be used (instead of AST__BAD) if no value has been set for Gap.
*        The Border attribute modified so that it is off (zero) by default.
*     19-SEP-1997 (DSB):
*        o  Check that something has been plotted before using the bounding
*        box to determine title and label positions. 
*        o  Fixed bug which caused a tick mark at the pole to be draw at
*        a random angle.
*        o  The size of the increment used to determine the tangent to a grid
*        line at the position to a label has been reduced to make sure the
*        labls are drawn parallel to grid line.
*        o  Correct the logic for catering with reversed axes when determining
*        the displacement of a label's reference point from the associated 
*        axis.
*        o  Corrected logic which determined if two numerical labels overlap.
*        o  Corrected logic for determining when to abbreviate numerical
*        labels.
*        o  Use of strtok replaced by local function FindWord.
*        o  Correct logic which determines which side of the axis to draw
*        tick marks when using interior labelling.
*        o  If the base Frame of the FrameSet supplied to astPlot has more 
*        than 2 axes, then use a sub-frame formed from the first two axes, 
*        instead of simply reporting an error.
*        o  If the current Frame of the Plot supplied to astGrid or
*        astBorder has more than 2 axes, then use a sub-frame formed from
*        the first two axes, instead of simply reporting an error.
*        o  Default for Border is now to draw the border if exterior 
*        Labelling is used, but not to draw it if interior labelling is
*        used. 
*        o  Public astGet function now returns actual used values for all
*        attributes. Protected astGetXyz functions still return the requested 
*        value (which may differ from the used value), or the "unset" value 
*        if no value has been set for the attribute.
*        o  The defaults for Edge now depend on Labelling. If exterior
*        labelling was requested but cannot be produced using defaults of
*        Edge(1)=Bottom and Edge(2)=Left, then these default Edge values 
*        are swapped. If exterior labelling is still not possible, the
*        original default Edge values are re-instated.
*        o  Unset attributes which use dynamic defaults are now flagged as 
*        "unhelpful" in the dump function.
*        o  Added attribute Escape which allows text strings to include
*        escape sequences (see function GrText). This attribute and
*        associated functionality is currently not available for use, search 
*        for all occurences of ENABLE-ESCAPE for instructions on how to 
*        enable the facilities.
*        o  Strings now used instead of integers to represent "choice" 
*        attributes externally (eg Edge and Labelling).
*     24-NOV-1997 (DSB):
*        o  Fixed bug in function Grid which caused units to be included in
*        SkyFrame axis labels by default.
*        o  Replaced calls to DrawText by calls to astGText, and replaced
*        references to "U" and "D" justifications by "T" and "B". This 
*        stops labels drifting to the bottom left when GAIA zooms.
*     23-MAR-1998 (DSB):
*        Added extra checks on global status into routine Grid to avoid
*        segmentation violations occuring due to null pointers being used.
*     10-JUN-1998 (DSB):
*        Modify DrawTicks so that ticks are drawn closer to singularities
*        than previously. Also normalise this constraint to the screen size
*        rather than the length of a major tick mark.
*     28-OCT-1998 (DSB):
*        o  Added method astPolyCurve. 
*        o  Extract the Current Frame from the Plot prior to using Frame 
*        methods such as astOffset, astNorm, etc.
*        o  PlotLabel modified to ensure labels are abbreviated even if
*        they are next to the "root" label (i.e. the label with most
*        trailing zeros).
*        o  Modified description of Width attribute. Width no longer gives
*        the absolute line width in inches. Instead it is a scale factor,
*        where 1.0 corresponds to a "typical thin line" on the device.
*        o  Modified LabelUnits attribute so that the default value is zero
*        for SkyAxes and non-zero for other Axes.
*     10-DEC-1998 (DSB):
*        Modified all calls to the "pow" maths function to avoid using
*        literal constants as arguments. This seems to cause segmentation
*        violations on some systems.
*     16-JUL-1999 (DSB):
*        Fixed memory leaks in EdgeCrossings and EdgeLabels.
*     16-SEP-1999 (DSB):
*        Avoid writing out clipping limits if they are undefined.
*     12-OCT-1999 (DSB):
*        o  Modified use of the NumLab attribute so that setting it to zero 
*        does not prevent exterior labels from being produced.
*        o  Allow length of tick marks to be specified separately for
*        both axes.
*class--
*/

/* Module Macros. */
/* ============== */
/* Set the name of the class we are implementing. This indicates to the header
   files that define class interfaces that they should make "protected"
   symbols available. */
#define astCLASS Plot

/* Macros which return the maximum and minimum of two values. */
#define MAX(aa,bb) ((aa)>(bb)?(aa):(bb))
#define MIN(aa,bb) ((aa)<(bb)?(aa):(bb))

/* Macros to check for equality of floating point values. */
#define EQUAL(aa,bb) (fabs((aa)-(bb))<=1.0E5*MAX((fabs(aa)+fabs(bb))*DBL_EPSILON,DBL_MIN))

/* Values for constants used in this class. */
#define CRV_NSEG       14 /* No. of curve segments drawn by function Crv */
#define CRV_NPNT       15 /* CRV_NSEG plus one */
#define CRV_MXBRK     100 /* Max. no. of breaks allowed in a plotted curve */
#define CRV_MXENT      10 /* Max. no. of recursive entries into function Crv */
#define POLY_MAX     1000 /* Max. no. of points in a poly line */
#define MAJTICKS_OPT   10 /* Optimum number of major axiss or grid lines */
#define MAJTICKS_MAX   14 /* Max. number of major ticks or grid lines */
#define MAJTICKS_MIN    6 /* Min. number of major ticks or grid lines */
#define EDGETICKS_DIM 100 /* No. of edge samples used to find tick marks */
#define BORDER_ID       0 /* Id for astBorder curves */
#define GRIDLINE_ID     1 /* Id for astGridLine curves */
#define CURVE_ID        2 /* Id for astCurve or astPolyCurve curves */
#define NUMLABS_ID      3 /* Id for numerical labels */
#define TEXTLABS_ID     4 /* Id for textual axis labels */
#define TITLE_ID        5 /* Id for textual title */
#define MARKS_ID        6 /* Id for marks drawn by astMark */
#define TEXT_ID         7 /* Id for text strings drawn by astText */
#define TICKS_ID        8 /* Id for major and minor tick marks */
#define AXIS_ID         9 /* Id for axes through interior tick marks */
#define LEFT            0 /* Id for the left edge of the plotting area */
#define TOP             1 /* Id for the top edge of the plotting area */
#define RIGHT           2 /* Id for the right edge of the plotting area */
#define BOTTOM          3 /* Id for the bottom edge of the plotting area */

/*
*
*  Name:
*     MAKE_CLEAR

*  Purpose:
*     Implement a method to clear a single value in a multi-valued attribute.

*  Type:
*     Private macro.

*  Synopsis:
*     #include "plot.h"
*     MAKE_CLEAR(attr,component,assign,nval)

*  Class Membership:
*     Defined by the Plot class.

*  Description:
*     This macro expands to an implementation of a private member function of
*     the form:
*
*        static void Clear<Attribute>( AstPlot *this, int axis )
*
*     and an external interface function of the form:
*
*        void astClear<Attribute>_( AstPlot *this, int axis )
*
*     which implement a method for clearing a single value in a specified 
*     multi-valued attribute for an axis of a Plot.

*  Parameters:
*     attr
*        The name of the attribute to be cleared, as it appears in the function
*        name (e.g. Label in "astClearLabelAt").
*     component
*        The name of the class structure component that holds the attribute
*        value.
*     assign
*        An expression that evaluates to the value to assign to the component
*        to clear its value.
*     nval
*        Specifies the number of values in the multi-valued attribute. The
*        "axis" values supplied to the created function should be in the
*        range zero to (nval - 1).

*  Notes:
*     -  To avoid problems with some compilers, you should not leave any white
*     space around the macro arguments.
*
*/

/* Define the macro. */
#define MAKE_CLEAR(attr,component,assign,nval) \
\
/* Private member function. */ \
/* ------------------------ */ \
static void Clear##attr( AstPlot *this, int axis ) { \
\
/* Check the global error status. */ \
   if ( !astOK ) return; \
\
/* Validate the axis index. */ \
   if( axis < 0 || axis >= nval ){ \
      astError( AST__AXIIN, "%s(%s): Index (%d) is invalid for attribute " \
                #attr " - it should be in the range 1 to %d.", \
                "astClear" #attr, astGetClass( this ), \
                axis + 1, nval ); \
\
/* Assign the "clear" value. */ \
   } else { \
      this->component[ axis ] = (assign); \
   } \
} \
\
/* External interface. */ \
/* ------------------- */ \
void astClear##attr##_( AstPlot *this, int axis ) { \
\
/* Check the global error status. */ \
   if ( !astOK ) return; \
\
/* Invoke the required method via the virtual function table. */ \
   (**astMEMBER(this,Plot,Clear##attr))( this, axis ); \
}   


/*
*
*  Name:
*     MAKE_GET

*  Purpose:
*     Implement a method to get a single value in a multi-valued attribute.

*  Type:
*     Private macro.

*  Synopsis:
*     #include "plot.h"
*     MAKE_GET(attr,type,bad_value,assign,nval)

*  Class Membership:
*     Defined by the Plot class.

*  Description:
*     This macro expands to an implementation of a private member function of
*     the form:
*
*        static <Type> Get<Attribute>( AstPlot *this, int axis )
*
*     and an external interface function of the form:
*
*        <Type> astGet<Attribute>_( AstPlot *this, int axis )
*
*     which implement a method for getting a single value from a specified 
*     multi-valued attribute for an axis of a Plot.

*  Parameters:
*     attr
*        The name of the attribute whose value is to be obtained, as it
*        appears in the function name (e.g. Label in "astGetLabel").
*     type
*        The C type of the attribute.
*     bad_value
*        A constant value to return if the global error status is set, or if
*        the function fails.
*     assign
*        An expression that evaluates to the value to be returned. This can
*        use the string "axis" to represent the zero-based value index.
*     nval
*        Specifies the number of values in the multi-valued attribute. The
*        "axis" values supplied to the created function should be in the
*        range zero to (nval - 1).

*  Notes:
*     -  To avoid problems with some compilers, you should not leave any white
*     space around the macro arguments.
*
*/

/* Define the macro. */
#define MAKE_GET(attr,type,bad_value,assign,nval) \
\
/* Private member function. */ \
/* ------------------------ */ \
static type Get##attr( AstPlot *this, int axis ) { \
   type result;                  /* Result to be returned */ \
\
/* Check the global error status. */ \
   if ( !astOK ) return (bad_value); \
\
/* Validate the axis index. */ \
   if( axis < 0 || axis >= nval ){ \
      astError( AST__AXIIN, "%s(%s): Index (%d) is invalid for attribute " \
                #attr " - it should be in the range 1 to %d.", \
                "astGet" #attr, astGetClass( this ), \
                axis + 1, nval ); \
\
/* Assign the result value. */ \
   } else { \
      result = (assign); \
   } \
\
/* Check for errors and clear the result if necessary. */ \
   if ( !astOK ) result = (bad_value); \
\
/* Return the result. */ \
   return result; \
} \
/* External interface. */ \
/* ------------------- */  \
type astGet##attr##_( AstPlot *this, int axis ) { \
\
/* Check the global error status. */ \
   if ( !astOK ) return (bad_value); \
\
/* Invoke the required method via the virtual function table. */ \
   return (**astMEMBER(this,Plot,Get##attr))( this, axis ); \
}

/*
*
*  Name:
*     MAKE_SET

*  Purpose:
*     Implement a method to set a single value in a multi-valued attribute 
*     for a Plot.

*  Type:
*     Private macro.

*  Synopsis:
*     #include "plot.h"
*     MAKE_SET(attr,type,component,assign,nval)

*  Class Membership:
*     Defined by the Plot class.

*  Description:
*     This macro expands to an implementation of a private member function of
*     the form:
*
*        static void Set<Attribute>( AstPlot *this, int axis, <Type> value )
*
*     and an external interface function of the form:
*
*        void astSet<Attribute>_( AstPlot *this, int axis, <Type> value )
*
*     which implement a method for setting a single value in a specified
*     multi-valued attribute for a Plot.

*  Parameters:
*      attr
*         The name of the attribute to be set, as it appears in the function
*         name (e.g. Label in "astSetLabelAt").
*      type
*         The C type of the attribute.
*      component
*         The name of the class structure component that holds the attribute
*         value.
*      assign
*         An expression that evaluates to the value to be assigned to the
*         component.
*      nval
*         Specifies the number of values in the multi-valued attribute. The
*         "axis" values supplied to the created function should be in the
*         range zero to (nval - 1).

*  Notes:
*     -  To avoid problems with some compilers, you should not leave any white
*     space around the macro arguments.
*-
*/

/* Define the macro. */
#define MAKE_SET(attr,type,component,assign,nval) \
\
/* Private member function. */ \
/* ------------------------ */ \
static void Set##attr( AstPlot *this, int axis, type value ) { \
\
/* Check the global error status. */ \
   if ( !astOK ) return; \
\
/* Validate the axis index. */ \
   if( axis < 0 || axis >= nval ){ \
      astError( AST__AXIIN, "%s(%s): Index (%d) is invalid for attribute " \
                #attr " - it should be in the range 1 to %d.", \
                "astSet" #attr, astGetClass( this ), \
                axis + 1, nval ); \
\
/* Store the new value in the structure component. */ \
   } else { \
      this->component[ axis ] = (assign); \
   } \
} \
\
/* External interface. */ \
/* ------------------- */ \
void astSet##attr##_( AstPlot *this, int axis, type value ) { \
\
/* Check the global error status. */ \
   if ( !astOK ) return; \
\
/* Invoke the required method via the virtual function table. */ \
   (**astMEMBER(this,Plot,Set##attr))( this, axis, value ); \
}

/*
*
*  Name:
*     MAKE_TEST

*  Purpose:
*     Implement a method to test if a single value has been set in a 
*     multi-valued attribute for a class.

*  Type:
*     Private macro.

*  Synopsis:
*     #include "plot.h"
*     MAKE_TEST(attr,assign,nval)

*  Class Membership:
*     Defined by the Plot class.

*  Description:
*     This macro expands to an implementation of a private member function of
*     the form:
*
*        static int Test<Attribute>( AstPlot *this, int axis )
*
*     and an external interface function of the form:
*
*        int astTest<Attribute>_( AstPlot *this, int axis )
*
*     which implement a method for testing if a single value in a specified 
*     multi-valued attribute has been set for a class.

*  Parameters:
*      attr
*         The name of the attribute to be tested, as it appears in the function
*         name (e.g. Label in "astTestLabelAt").
*      assign
*         An expression that evaluates to 0 or 1, to be used as the returned
*         value. This can use the string "axis" to represent the zero-based
*         index of the value within the attribute.
*      nval
*         Specifies the number of values in the multi-valued attribute. The
*         "axis" values supplied to the created function should be in the
*         range zero to (nval - 1).

*  Notes:
*     -  To avoid problems with some compilers, you should not leave any white
*     space around the macro arguments.
*-
*/

/* Define the macro. */
#define MAKE_TEST(attr,assign,nval) \
\
/* Private member function. */ \
/* ------------------------ */ \
static int Test##attr( AstPlot *this, int axis ) { \
   int result;                   /* Value to return */ \
\
/* Check the global error status. */ \
   if ( !astOK ) return 0; \
\
\
/* Validate the axis index. */ \
   if( axis < 0 || axis >= nval ){ \
      astError( AST__AXIIN, "%s(%s): Index (%d) is invalid for attribute " \
                #attr " - it should be in the range 1 to %d.", \
                "astTest" #attr, astGetClass( this ), \
                axis + 1, nval ); \
\
/* Assign the result value. */ \
   } else { \
      result = (assign); \
   } \
\
/* Check for errors and clear the result if necessary. */ \
   if ( !astOK ) result = 0; \
\
/* Return the result. */ \
   return result; \
} \
/* External interface. */ \
/* ------------------- */ \
int astTest##attr##_( AstPlot *this, int axis ) { \
\
/* Check the global error status. */ \
   if ( !astOK ) return 0; \
\
/* Invoke the required method via the virtual function table. */ \
   return (**astMEMBER(this,Plot,Test##attr))( this, axis ); \
}

/*
*
*  Name:
*     MAKE_GET3

*  Purpose:
*     Implement a method to get a single value in a multi-valued attribute.

*  Type:
*     Private macro.

*  Synopsis:
*     MAKE_GET3(attr,type,bad_value,assign,nval)

*  Class Membership:
*     Defined by the Plot class.

*  Description:
*     This macro expands to an implementation of a private member function of
*     the form:
*
*        static <Type> Get<Attribute>( AstPlot *this, int axis )
*
*     which implements a method for getting a single value from a specified 
*     multi-valued attribute for an axis of a Plot. Note, no public
*     interface function is created.
*
*     The value returned is the value which would actually be used if
*     astGrid was called with the current set of Plot attributes. This
*     includes calculating any dynamic defaults which would be used, and is
*     consequently rather slow.

*  Parameters:
*     attr
*        The name of the attribute whose value is to be obtained, as it
*        appears in the function name (e.g. Label in "astGetLabel").
*     type
*        The C type of the attribute.
*     bad_value
*        A constant value to return if the global error status is set, or if
*        the function fails.
*     assign
*        An expression that evaluates to the value to be returned. This can
*        use the string "axis" to represent the zero-based value index.
*     nval
*        Specifies the number of values in the multi-valued attribute. The
*        "axis" values supplied to the created function should be in the
*        range zero to (nval - 1).

*  Notes:
*     -  To avoid problems with some compilers, you should not leave any white
*     space around the macro arguments.
*
*/

/* Define the macro. */
#define MAKE_GET3(attr,type,bad_value,assign,nval) \
\
/* Private member function. */ \
/* ------------------------ */ \
static type Get##attr( AstPlot *, int ); \
static type Get##attr( AstPlot *this, int axis ) { \
   type result;                  /* Result to be returned */ \
\
/* Check the global error status. */ \
   if ( !astOK ) return (bad_value); \
\
/* Validate the axis index. */ \
   if( axis < 0 || axis >= nval ){ \
      astError( AST__AXIIN, "%s(%s): Index (%d) is invalid for attribute " \
                #attr " - it should be in the range 1 to %d.", \
                "astGet" #attr, astGetClass( this ), \
                axis + 1, nval ); \
\
/* Re-calculate dynamic defaults by going through the motions of drawing \
   the grid. Nothing is actually drawn because we set the protected \
   attribute Ink to zero first. The calculated values are stored in the \
   Plot structure. */ \
   } else { \
      astSetInk( this, 0 ); \
      astGrid( this ); \
      astClearInk( this ); \
\
/* Assign the result value. */ \
      result = (assign); \
   } \
\
/* Check for errors and clear the result if necessary. */ \
   if ( !astOK ) result = (bad_value); \
\
/* Return the result. */ \
   return result; \
} 

/*
*
*  Name:
*     MAKE_SET3

*  Purpose:
*     Implement a method to set a single value in a multi-valued attribute 
*     for a Plot. This is identical to MAKE_SET except that no external 
*     interface function is created.

*  Type:
*     Private macro.

*  Synopsis:
*     MAKE_SET3(attr,type,component,assign,nval)

*  Class Membership:
*     Defined by the Plot class.

*  Description:
*     This macro expands to an implementation of a private member function of
*     the form:
*
*        static void Set<Attribute>( AstPlot *this, int axis, <Type> value )
*
*     which implements a method for setting a single value in a specified
*     multi-valued attribute for a Plot.

*  Parameters:
*      attr
*         The name of the attribute to be set, as it appears in the function
*         name (e.g. Label in "astSetLabelAt").
*      type
*         The C type of the attribute.
*      component
*         The name of the class structure component that holds the attribute
*         value.
*      assign
*         An expression that evaluates to the value to be assigned to the
*         component.
*      nval
*         Specifies the number of values in the multi-valued attribute. The
*         "axis" values supplied to the created function should be in the
*         range zero to (nval - 1).

*  Notes:
*     -  To avoid problems with some compilers, you should not leave any white
*     space around the macro arguments.
*-
*/

/* Define the macro. */
#define MAKE_SET3(attr,type,component,assign,nval) \
\
/* Private member function. */ \
/* ------------------------ */ \
static void Set##attr( AstPlot *, int, type ); \
static void Set##attr( AstPlot *this, int axis, type value ) { \
\
/* Check the global error status. */ \
   if ( !astOK ) return; \
\
/* Validate the axis index. */ \
   if( axis < 0 || axis >= nval ){ \
      astError( AST__AXIIN, "%s(%s): Index (%d) is invalid for attribute " \
                #attr " - it should be in the range 1 to %d.", \
                "astSet" #attr, astGetClass( this ), \
                axis + 1, nval ); \
\
/* Store the new value in the structure component. */ \
   } else { \
      this->component[ axis ] = (assign); \
   } \
} 

/*
*+
*  Name:
*     MAKE_GET2

*  Purpose:
*     Implement a method to get an attribute value for a class. 

*  Type:
*     Protected macro.

*  Synopsis:
*     MAKE_GET2(class,attribute,type,bad_value,assign)

*  Class Membership:
*     Defined by the Plot class.

*  Description:
*     This macro expands to an implementation of a private member function of
*     the form:
*
*        static <Type> Get<Attribute>( Ast<Class> *this )
*
*     which implement a method for getting a specified attribute value for a
*     class. Note, no public interface function is created.
*
*     The value returned is the value which would actually be used if
*     astGrid was called with the current set of Plot attributes. This
*     includes calculating any dynamic defaults which would be used, and is
*     consequently rather slow.

*  Parameters:
*     class
*        The name (not the type) of the class to which the attribute belongs.
*     attribute
*        The name of the attribute whose value is to be obtained, as it
*        appears in the function name (e.g. Label in "astGetLabel").
*     type
*        The C type of the attribute.
*     bad_value
*        A constant value to return if the global error status is set, or if
*        the function fails.
*     assign
*        An expression that evaluates to the value to be returned.

*  Notes:
*     -  To avoid problems with some compilers, you should not leave any white
*     space around the macro arguments.
*-
*/

/* Define the macro. */
#define MAKE_GET2(class,attribute,type,bad_value,assign) \
\
/* Private member function. */ \
/* ------------------------ */ \
static type Get##attribute( Ast##class * ); \
static type Get##attribute( Ast##class *this ) { \
   type result;                  /* Result to be returned */ \
\
/* Check the global error status. */ \
   if ( !astOK ) return (bad_value); \
\
/* Re-calculate dynamic defaults by going through the motions of drawing \
   the grid. Nothing is actually drawn because we set the protected \
   attribute Ink to zero first. The calculated values are stored in the \
   Plot structure. */ \
   astSetInk( this, 0 ); \
   astGrid( this ); \
   astClearInk( this ); \
\
/* Assign the result value. */ \
   result = (assign); \
\
/* Check for errors and clear the result if necessary. */ \
   if ( !astOK ) result = (bad_value); \
\
/* Return the result. */ \
   return result; \
}

/*
*+
*  Name:
*     MAKE_SET2

*  Purpose:
*     Implement a method to set an attribute value for a class. This
*     is identical to astMAKE_SET except that it does not create an
*     external interface function, and it does create a private function
*     prototype.

*  Type:
*     Protected macro.

*  Synopsis:
*     MAKE_SET2(class,attribute,type,component,assign)

*  Class Membership:
*     Defined by the Plot class.

*  Description:
*     This macro expands to an implementation of a private member function of
*     the form:
*
*        static void Set<Attribute>( Ast<Class> *this, <Type> value )
*
*     which implements a method for setting a specified attribute value for a
*     class.

*  Parameters:
*      class
*         The name (not the type) of the class to which the attribute belongs.
*      attribute
*         The name of the attribute to be set, as it appears in the function
*         name (e.g. Label in "astSetLabel").
*      type
*         The C type of the attribute.
*      component
*         The name of the class structure component that holds the attribute
*         value.
*      assign
*         An expression that evaluates to the value to be assigned to the
*         component.

*  Notes:
*     - To avoid problems with some compilers, you should not leave
*     any white space around the macro arguments.
*-
*/

/* Define the macro. */
#define MAKE_SET2(class,attribute,type,component,assign) \
\
/* Private member function. */ \
/* ------------------------ */ \
static void Set##attribute( Ast##class *, type ); \
static void Set##attribute( Ast##class *this, type value ) { \
\
/* Check the global error status. */ \
   if ( !astOK ) return; \
\
/* Store the new value in the structure component. */ \
   this->component = (assign); \
} 


/* Header files. */
/* ============= */
/* Interface definitions. */
/* ---------------------- */
#include "channel.h"             /* I/O channels */
#include "cmpmap.h"              /* Compound mapping class */
#include "error.h"               /* Error reporting facilities */
#include "frame.h"               /* Coordinate frame descriptions */
#include "frameset.h"            /* Parent FrameSet class */
#include "grf.h"                 /* Low-level graphics interface */
#include "memory.h"              /* Memory allocation facilities */
#include "object.h"              /* Base Object class */ 
#include "plot.h"                /* Interface definition for this class */
#include "pointset.h"            /* Class holding lists of positions */
#include "skyaxis.h"             /* Sky coordinate axes */
#include "skyframe.h"            /* Sky coordinate frames */
#include "winmap.h"              /* Scale and shift mappings */
#include "wcsmap.h"              /* FITS-WCS projectsions */
#include "permmap.h"             /* Axis permutations */


/* Error code definitions. */
/* ----------------------- */
#include "ast_err.h"             /* AST error codes */

/* C header files. */
/* --------------- */
#include <ctype.h>
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/* Module Type Definitions */
/* ======================= */
typedef struct LabelList {
   double index;
   char *text;
   double x;
   double y;
   char *just;
   double upx;
   double upy;
   double val;
} LabelList;

/* Structure holding information about curves drawn by astGridLine and 
   astCurve. */
typedef struct CurveData{
   int out;          /* Was the curve completely outside the clipping area? */
   int nbrk;         /* The number of breaks in the curve. */
   float xbrk[ CRV_MXBRK ];  /* Graphics X coordinate at each break. */
   float ybrk[ CRV_MXBRK ];  /* Graphics Y coordinate at each break. */
   float vxbrk[ CRV_MXBRK ]; /* X comp. of unit tangent vector */
   float vybrk[ CRV_MXBRK ]; /* Y comp. of unit tangent vector */
   float length;     /* Drawn length of the curve in graphics coordinates */
} CurveData;

/* Structure to hold information about tick marks for a single axis. */
typedef struct TickInfo{
   int nmajor;               /* No. of major tick marks */
   int nminor;               /* No. of minor tick marks */
   double *ticks;            /* Pointer to array of major tick mark values */
   char **labels;            /* Pointer to array of major tick mark labels */
   double *start;            /* Start pos'n on other axis for each curve section */
   double *length;           /* Length on other axis of each curve section */
   int nsect;                /* No. of sections in curve */
   char *fmt;                /* Pointer to format string used to create labels */
} TickInfo;

/* Module Variables. */
/* ================= */
/* Define the class virtual function table and its initialisation flag as
   static variables. */
static AstPlotVtab class_vtab; /* Virtual function table */
static int class_init = 0;       /* Virtual function table initialised? */

/* Pointers to parent class methods which are extended by this class. */
static void (* parent_removeframe)( AstFrameSet *, int );
static AstPointSet *(* parent_transform)( AstMapping *, AstPointSet *, int,
                                          AstPointSet * );
static const char *(* parent_getattrib)( AstObject *, const char * );
static int (* parent_testattrib)( AstObject *, const char * );
static void (* parent_clearattrib)( AstObject *, const char * );
static void (* parent_setattrib)( AstObject *, const char * );

/* Variables used to pass information to the curve drawing functions. See 
   the prologues of functions Crv and CrvLine for details. */
static double Crv_limit;
static double Crv_tol;
static double Crv_ux0;
static double Crv_uy0;
static double Crv_vxl;
static double Crv_vyl;
static double Crv_xhi;
static double Crv_xl;
static double Crv_xlo;
static double Crv_yhi;
static double Crv_yl;
static double Crv_ylo;
static float *Crv_vxbrk;
static float *Crv_vybrk;
static float *Crv_xbrk;
static float *Crv_ybrk;
static float Crv_len;
static int Crv_ink;
static int Crv_nbrk;
static int Crv_nent = 0;
static int Crv_out;
static void (*Crv_map)( int, double *, double *, double *, const char *, const char * );

/* The lower and upper bounds of the graphics coordinates enclosing all
   lines and numerical labels. */
static float Box_lbnd[ 2 ] = {FLT_MAX, FLT_MAX };
static float Box_ubnd[ 2 ] = {FLT_MIN, FLT_MIN };

/* Variables used to stored buffered poly lines (see functions Opoly, Bpoly
   and Apoly). */
static float Poly_x[ POLY_MAX ];
static float Poly_y[ POLY_MAX ];
static int   Poly_n;

/* Variables used by function Map1. See the prologue of Map1 for details. */
static int           Map1_ncoord;       
static AstPlot      *Map1_plot = NULL; 
static AstMapping   *Map1_map = NULL; 
static AstFrame     *Map1_frame = NULL; 
static const double *Map1_origin = NULL; 
static double        Map1_scale;
static int           Map1_axis;
static int           Map1_norm;

/* Variables used by function Map2. See the prologue of Map2 for details. */
static int           Map2_ncoord;       
static AstPlot      *Map2_plot = NULL; 
static AstMapping   *Map2_map = NULL; 
static double        Map2_x0;
static double        Map2_y0;
static double        Map2_deltax;
static double        Map2_deltay;

/* Variables used by function Map3. See the prologue of Map3 for details. */
static int           Map3_ncoord;       
static AstPlot      *Map3_plot = NULL; 
static AstMapping   *Map3_map = NULL; 
static AstFrame     *Map3_frame = NULL; 
static const double *Map3_origin = NULL; 
static const double *Map3_end = NULL; 
static double        Map3_scale;

/* A structure which stores information about the breaks in the last curve
   drawn using the public methods "astGridLine" and "astCurve". */
static CurveData Curve_data;

/* Strings giving the label for the graphics items corresponding to
   BORDER_ID, GRIDLINE_ID, etc. */
static char *GrfLabels = "Border Grid Curves NumLab TextLab Title "
                         "Markers Strings Ticks Axes";

/* Text values used to represent edges externally. */
static const char *xedge[4] = { "left", "top", "right", "bottom" };

/* Text values used to represent Labelling externally. */
static const char *xlbling[2] = { "interior", "exterior" };

/* Prototypes for Private Member Functions. */
/* ======================================== */
static double GetTol( AstPlot * );
static int TestTol( AstPlot * );
static void ClearTol( AstPlot * );
static void SetTol( AstPlot *, double );

static int GetGrid( AstPlot * );
static int TestGrid( AstPlot * );
static void ClearGrid( AstPlot * );
static void SetGrid( AstPlot *, int );

static int GetTickAll( AstPlot * );
static int TestTickAll( AstPlot * );
static void ClearTickAll( AstPlot * );
static void SetTickAll( AstPlot *, int );

static int GetBorder( AstPlot * );
static int TestBorder( AstPlot * );
static void ClearBorder( AstPlot * );
static void SetBorder( AstPlot *, int );

static int GetInk( AstPlot * );
static int TestInk( AstPlot * );
static void ClearInk( AstPlot * );
static void SetInk( AstPlot *, int );

static int GetClipOp( AstPlot * );
static int TestClipOp( AstPlot * );
static void ClearClipOp( AstPlot * );
static void SetClipOp( AstPlot *, int );

static int GetDrawTitle( AstPlot * );
static int TestDrawTitle( AstPlot * );
static void ClearDrawTitle( AstPlot * );
static void SetDrawTitle( AstPlot *, int );

static int GetDrawAxes( AstPlot * );
static int TestDrawAxes( AstPlot * );
static void ClearDrawAxes( AstPlot * );
static void SetDrawAxes( AstPlot *, int );

static int GetEscape( AstPlot * );
static int TestEscape( AstPlot * );
static void ClearEscape( AstPlot * );
static void SetEscape( AstPlot *, int );

static double GetLabelAt( AstPlot *, int );
static int TestLabelAt( AstPlot *, int );
static void ClearLabelAt( AstPlot *, int );
static void SetLabelAt( AstPlot *, int, double );

static double GetNumLabGap( AstPlot *, int );
static int TestNumLabGap( AstPlot *, int );
static void ClearNumLabGap( AstPlot *, int );
static void SetNumLabGap( AstPlot *, int, double );

static double GetTextLabGap( AstPlot *, int );
static int TestTextLabGap( AstPlot *, int );
static void ClearTextLabGap( AstPlot *, int );
static void SetTextLabGap( AstPlot *, int, double );

static double GetCentre( AstPlot *, int );
static int TestCentre( AstPlot *, int );
static void ClearCentre( AstPlot *, int );
static void SetCentre( AstPlot *, int, double );

static double GetGap( AstPlot *, int );
static int TestGap( AstPlot *, int );
static void ClearGap( AstPlot *, int );
static void SetGap( AstPlot *, int, double );

static int GetLabelling( AstPlot *  );
static int TestLabelling( AstPlot * );
static void ClearLabelling( AstPlot * );
static void SetLabelling( AstPlot *, int );

static double GetMajTickLen( AstPlot *, int );
static int TestMajTickLen( AstPlot *, int );
static void ClearMajTickLen( AstPlot *, int );
static void SetMajTickLen( AstPlot *, int, double );

static double GetTitleGap( AstPlot * );
static int TestTitleGap( AstPlot * );
static void ClearTitleGap( AstPlot * );
static void SetTitleGap( AstPlot *, double );

static double GetMinTickLen( AstPlot *, int );
static int TestMinTickLen( AstPlot *, int );
static void ClearMinTickLen( AstPlot *, int );
static void SetMinTickLen( AstPlot *, int, double );

static int GetEdge( AstPlot *, int );
static int TestEdge( AstPlot *, int );
static void ClearEdge( AstPlot *, int );
static void SetEdge( AstPlot *, int, int );

static int GetLabelUp( AstPlot *, int );
static int TestLabelUp( AstPlot *, int );
static void ClearLabelUp( AstPlot *, int );
static void SetLabelUp( AstPlot *, int, int );

static int GetNumLab( AstPlot *, int );
static int TestNumLab( AstPlot *, int );
static void ClearNumLab( AstPlot *, int );
static void SetNumLab( AstPlot *, int, int );

static int GetMinTick( AstPlot *, int );
static int TestMinTick( AstPlot *, int );
static void ClearMinTick( AstPlot *, int );
static void SetMinTick( AstPlot *, int, int );

static int GetTextLab( AstPlot *, int );
static int TestTextLab( AstPlot *, int );
static void ClearTextLab( AstPlot *, int );
static void SetTextLab( AstPlot *, int, int );

static int GetLabelUnits( AstPlot *, int );
static int TestLabelUnits( AstPlot *, int );
static void ClearLabelUnits( AstPlot *, int );
static void SetLabelUnits( AstPlot *, int, int );

static int GetStyle( AstPlot *, int );
static int TestStyle( AstPlot *, int );
static void ClearStyle( AstPlot *, int );
static void SetStyle( AstPlot *, int, int );

static int GetFont( AstPlot *, int );
static int TestFont( AstPlot *, int );
static void ClearFont( AstPlot *, int );
static void SetFont( AstPlot *, int, int );

static int GetColour( AstPlot *, int );
static int TestColour( AstPlot *, int );
static void ClearColour( AstPlot *, int );
static void SetColour( AstPlot *, int, int );

static double GetWidth( AstPlot *, int );
static int TestWidth( AstPlot *, int );
static void ClearWidth( AstPlot *, int );
static void SetWidth( AstPlot *, int, double );

static double GetSize( AstPlot *, int );
static int TestSize( AstPlot *, int );
static void ClearSize( AstPlot *, int );
static void SetSize( AstPlot *, int, double );

static const char *GetAttrib( AstObject *, const char * );
static int TestAttrib( AstObject *, const char * );
static void ClearAttrib( AstObject *, const char * );
static void SetAttrib( AstObject *, const char * );

static AstFrameSet *Fset2D( AstFrameSet *, int );
static AstPointSet *DefGap( AstPlot *, double *, int *, double *, int *, const char *, const char * );
static AstPointSet *Trans( AstPlot *, AstFrame *, AstMapping *, AstPointSet *, int, AstPointSet *, int, const char *, const char * );
static AstPointSet *Transform( AstMapping *, AstPointSet *, int, AstPointSet * );
static CurveData **CleanCdata( CurveData ** );
static CurveData **DrawGrid( AstPlot *, TickInfo **, int, const char *, const char * );
static TickInfo **CleanGrid( TickInfo ** );
static TickInfo **GridLines( AstPlot *, double *, double *, int *, const char *, const char * );
static TickInfo *TickMarks( AstPlot *, int, double *, double *, int *, const char *, const char * );
static char **CheckLabels2( AstFrame *, int, double *, int, char ** );
static char *FindWord( char *, const char *, const char ** );
static char *GrfItem( int, const char * );
static double **MakeGrid( AstPlot *, AstFrame *, AstMapping *, int, double, double, double, double, int, AstPointSet **, AstPointSet**, int, const char *, const char * );
static double GetTicks( AstPlot *, int, double *, double, double **, int *, int *, int, int *, const char *, const char * );
static double GoodGrid( AstPlot *, int *, AstPointSet **, AstPointSet **, const char *, const char * );
static int Border( AstPlot * );
static int Boundary( AstPlot *, const char *, const char * );
static int BoxCheck( float *, float *, float *, float * );
static int BoxText( AstPlot *, int, const char *, float, float, const char *, float, float, float *, float *, const char *, const char * );
static int CheckLabels( AstFrame *, int, double *, int, char ** );
static int ChrLen( const char * );
static int Compare_LL( const void *, const void * );
static int Compared( const void *, const void * );
static int CountGood( int, double * );
static int Cross( float, float, float, float, float, float, float, float );
static int CvBrk( AstPlot *, int, double *, double *, double * );
#if 0
/* ENABLE-ESCAPE - Add the following prototype when escape sequences
   are enabled. */
static int DrawText( AstPlot *, int, const char *, float, float, const char *, float, float, const char *, const char * );
#endif
static int EdgeCrossings( AstPlot *, int, int, double, double *, double **, const char *, const char * );
static int EdgeLabels( AstPlot *, int, TickInfo **, CurveData **, const char *, const char * );
static int FindMajTicks( AstFrame *, int, double, double , double *, int, double *, double ** );
static int FullForm( const char *, const char *, const char *, const char *, const char * );
static int FindString( int, const char *[], const char *, const char *, const char *, const char * );
static int GVec( AstPlot *, AstMapping *, double *, int, double, AstPointSet **, AstPointSet **, double *, double *, double *, double *, int *, const char *, const char *);
static int GrText( AstPlot *, int, const char *, int, int, float, float, float, float, float *, float *, const char *, const char * );
static int Inside( int, float *, float *, float, float);
static int Overlap( AstPlot *, int, const char *, float, float, const char *, float, float, float **, const char *, const char *);
static int Ustrcmp( const char *, const char * );
static int Ustrncmp( const char *, const char *, size_t );
static void AddCdt( CurveData *, CurveData *, const char *, const char * );
static void Apoly( float, float, const char *, const char * );
static void AxPlot( AstPlot *, int, const double *, double, int, CurveData *, int, const char *, const char * );
static void Bpoly( float, float, const char *, const char * );
static void Clip( AstPlot *, int, const double [], const double [] );
static void Copy( const AstObject *, AstObject * );
static void Crv( double *, double *, double *, const char *, const char * );
static void CrvLine( double, double, double, double, const char *, const char * );
static void Curve( AstPlot *, const double [], const double [] );
static void CurvePlot( AstPlot *, const double *, const double *, int , CurveData *, const char *, const char * );
static void Delete( AstObject * );
static void DrawAxis( AstPlot *, TickInfo **, double *, double *, const char *, const char *);
static void DrawTicks( AstPlot *, TickInfo **, int, double *, double *, const char *, const char * );
static void Dump( AstObject *, AstChannel * );
static void GraphGrid( int, double, double, double, double, double ** );
static void Grid( AstPlot * );
static void GridLine( AstPlot *, int, const double [], double );
static void InitVtab( AstPlotVtab * );
static void Labelat( AstPlot *, TickInfo **, CurveData **, double *, const char *, const char * );
static void Labels( AstPlot *, TickInfo **, CurveData **, double *, double *, const char *, const char * );
static void LinePlot( AstPlot *, double, double, double, double, int, CurveData *, const char *, const char * );
static void Map1( int, double *, double *, double *, const char *, const char * );
static void Map2( int, double *, double *, double *, const char *, const char * );
static void Map3( int, double *, double *, double *, const char *, const char * );
static void Mark( AstPlot *, int, int, int, const double (*)[], int );
static void Opoly( const char *, const char * );
static void PlotLabels( AstPlot *, AstFrame *, int, LabelList *, char *, int, float **, const char *, const char *);
static void PolyCurve( AstPlot *, int, int, int, const double (*)[] );
static void RemoveFrame( AstFrameSet *, int );
static void Text( AstPlot *, const char *, const double [], const float [2], const char *);
static void TextLabels( AstPlot *, int, int *, const char *, const char *);
static void Ticker( AstPlot *, int, int, double, double *, double, const char *, const char *);
static void TraceBorder( double **, double **, int, int *, const char *, const char * );
void GrfAttrs( AstPlot *, int, int, int );

/* Functions which access class attributes. */
/* =======================================  */
/* Implement member functions to access the attributes associated with this
   class using the macros defined for this purpose in the "object.h" file. For
   a description of each attribute, see the class interface (in the associated
   .h file). */

/* Tol. */
/* ---- */
/*
*att++
*  Name:
*     Tol

*  Purpose:
*     Plotting tolerance.

*  Type:
*     Public attribute.

*  Synopsis:
*     Floating point.

*  Description:
*     This attribute specifies the plotting tolerance (or resolution)
*     to be used for the graphical output produced by a Plot.  Smaller
*     values will result in smoother and more accurate curves being
*     drawn, but may slow down the plotting process. Conversely,
*     larger values may speed up the plotting process in cases where
*     high resolution is not required.
*
*     The Tol value should be given as a fraction of the minimum
*     dimension of the plotting area, and should lie in the range
c     from 1.0e-7 to 1.0. By default, a value of 0.001 is used.
f     from 1.0E-7 to 1.0. By default, a value of 0.001 is used.

*  Applicability:
*     Plot
*        All Plots have this attribute.
*att--
*/
/* The plotting tolerance. Has a value of -1.0 when not set yielding a 
default value of 0.001. Usable values are in the range 1.0E-7 to 1.0. */
astMAKE_CLEAR(Plot,Tol,tol,-1.0)
astMAKE_GET(Plot,Tol,double,0.001,(this->tol == -1.0 ? 0.001 : this->tol))
astMAKE_SET(Plot,Tol,double,tol,MIN(MAX(value,1.0E-7),1.0))
astMAKE_TEST(Plot,Tol,( this->tol != -1.0 ))

/* Grid. */
/* ----- */
/*
*att++
*  Name:
*     Grid

*  Purpose:
*     Draw grid lines for a Plot?

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer (boolean).

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     whether grid lines (a grid of curves marking the "major" values
*     on each axis) are drawn across the plotting area.
*
*     If the Grid value of a Plot is non-zero, then grid lines will be
*     drawn. Otherwise, short tick marks on the axes are used to mark
*     the major axis values.  The default behaviour is to use tick
*     marks if the entire plotting area is filled by valid physical
*     coordinates, but to draw grid lines otherwise.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - The spacing between major axis values, which determines the
*     spacing of grid lines, may be set using the Gap(axis) attribute.
*att--
*/
/* If non-zero use lines instead of tick marks in a coordinate grid. Has a 
value of -1 when not set yielding a default value of 0. */
astMAKE_CLEAR(Plot,Grid,grid,-1)
astMAKE_GET(Plot,Grid,int,0,(this->grid == -1 ? 0 : this->grid))
astMAKE_SET(Plot,Grid,int,grid,( value ? 1 : 0 ))
astMAKE_TEST(Plot,Grid,( this->grid != -1 ))

MAKE_GET2(Plot,UsedGrid,int,0,this->ugrid)
MAKE_SET2(Plot,UsedGrid,int,ugrid,( value ? 1 : 0 ))

/* TickAll */
/* ------- */
/*
*att++
*  Name:
*     TickAll

*  Purpose:
*     Draw tick marks on all edges of a Plot?

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer (boolean).

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     whether tick marks should be drawn on all edges of a Plot.
*
*     If the TickAll value of a Plot is non-zero (the default), then
*     tick marks will be drawn on all edges of the Plot. Otherwise,
*     they will be drawn only on those edges where the numerical and
*     descriptive axis labels are drawn (see the Edge(axis)
*     attribute).

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - In some circumstances, numerical labels and tick marks are
*     drawn along grid lines inside the plotting area, rather than
*     around its edges (see the Labelling attribute).  In this case,
*     the value of the TickAll attribute is ignored.
*att--
*/
/* If non-zero put tick marks on opposite edges. Has a value of -1 when not 
set yielding a default value of 1. */
astMAKE_CLEAR(Plot,TickAll,tickall,-1)
astMAKE_GET(Plot,TickAll,int,1,(this->tickall == -1 ? 1 : this->tickall))
astMAKE_SET(Plot,TickAll,int,tickall,( value ? 1 : 0 ))
astMAKE_TEST(Plot,TickAll,( this->tickall != -1 ))

/*
*att++
*  Name:
*     Border

*  Purpose:
*     Draw a border around valid regions of a Plot?

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer (boolean).

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     whether a border is drawn around regions corresponding to the
c     valid physical coordinates of a Plot (c.f. astBorder).
f     valid physical coordinates of a Plot (c.f. AST_BORDER).
*
*     If the Border value of a Plot is non-zero, then this border will
*     be drawn as part of the grid. Otherwise, the border is not drawn
*     (although axis labels and tick marks will still appear, unless
*     other relevant Plot attributes indicate that they should
*     not). The default behaviour is to draw the border if tick marks
*     and numerical labels will be drawn around the edges of the
*     plotting area (see the Labelling attribute), but to omit it
*     otherwise.

*  Applicability:
*     Plot
*        All Plots have this attribute.
*att--
*/
/* If non-zero draw the border. Has a value of -1 when not set, yeilding
   a default of 1. */
astMAKE_CLEAR(Plot,Border,border,-1)
astMAKE_SET(Plot,Border,int,border,( value ? 1 : 0 ))
astMAKE_TEST(Plot,Border,( this->border != -1 ))
astMAKE_GET(Plot,Border,int,1,(this->border == -1 ? 1 : this->border))

MAKE_SET2(Plot,UsedBorder,int,uborder,( value ? 1 : 0 ))
MAKE_GET2(Plot,UsedBorder,int,1,this->uborder)

/* ClipOp */
/* ------ */
/*
*att++
*  Name:
*     ClipOp

*  Purpose:
*     Combine Plot clipping limits using a boolean OR?

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer (boolean).

*  Description:
*     This attribute controls how the clipping limits specified for
c     each axis of a Plot (using the astClip function) are
f     each axis of a Plot (using the AST_CLIP routine) are
*     combined. This, in turn, determines which parts of the graphical
*     output will be visible.
*
*     If the ClipOp attribute of a Plot is zero (the default),
*     graphical output is visible only if it satisfies the clipping
*     limits on all the axes of the clipping Frame (a boolean
*     AND). Otherwise, if ClipOp is non-zero, output is visible if it
*     satisfies the clipping limits on one or more axes (a boolean
*     OR).
*
*     An important use of this attribute is to allow areas of a Plot
*     to be left clear (e.g. as a background for some text). To
*     achieve this, the lower and upper clipping bounds supplied to
c     astClip should be reversed, and the ClipOp attribute of the
f     AST_CLIP should be reversed, and the ClipOp attribute of the
*     Plot should be set to a non-zero value.

*  Applicability:
*     Plot
*        All Plots have this attribute.
*att--
*/
/* If non-zero only 1axis need be within the clipping bounds to avoid a
point being clipped. Otherwise, all axes must be within bounds. */
astMAKE_CLEAR(Plot,ClipOp,clipop,-1)
astMAKE_GET(Plot,ClipOp,int,0,(this->clipop == -1 ? 0 : this->clipop))
astMAKE_SET(Plot,ClipOp,int,clipop,( value ? 1 : 0 ))
astMAKE_TEST(Plot,ClipOp,( this->clipop != -1 ))

/* DrawTitle */
/* --------- */
/*
*att++
*  Name:
*     DrawTitle

*  Purpose:
*     Draw a title for a Plot?

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer (boolean).

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     whether a title is drawn.
*
*     If the DrawTitle value of a Plot is non-zero (the default), then
*     the title will be drawn, otherwise it will be omitted.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - The text used for the title is obtained from the Plot's Title
*     attribute.
*     - The vertical placement of the title can be controlled using
*     the TitleGap attribute.
*att--
*/
/* If non-zero add a title to the grid. Has a value of -1 when not 
set yielding a default value of 1. */
astMAKE_CLEAR(Plot,DrawTitle,drawtitle,-1)
astMAKE_GET(Plot,DrawTitle,int,1,(this->drawtitle == -1 ? 1 : this->drawtitle))
astMAKE_SET(Plot,DrawTitle,int,drawtitle,( value ? 1 : 0 ))
astMAKE_TEST(Plot,DrawTitle,( this->drawtitle != -1 ))

/* LabelUp. */
/* -------  */
/*
*att++
*  Name:
*     LabelUp(axis)

*  Purpose:
*     Draw numerical Plot labels upright?

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer (boolean). 

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     whether the numerical labels for each axis of a Plot should be
*     drawn upright or not. It takes a separate value for each
*     physical axis of a Plot so that, for instance, the setting
*     "LabelUp(2)=1" specifies that numerical labels for the second
*     axis should be drawn upright.
*
*     If the LabelUp value of a Plot axis is non-zero, it causes
*     numerical labels for that axis to be plotted upright (i.e. as
*     normal, horizontal text), otherwise (the default) these labels
*     rotate to follow the axis to which they apply.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - In some circumstances, numerical labels and tick marks are
*     drawn around the edges of the plotting area (see the Labelling
*     attribute).  In this case, the value of the LabelUp attribute is
*     ignored.
*     - If no axis is specified, (e.g. "LabelUp" instead of
*     "LabelUp(2)"), then a "set" or "clear" operation will affect the
*     attribute value of all the Plot axes, while a "get" or "test"
*     operation will use just the LabelUp(1) value.
*att--
*/
/* Are numerical labels to be displayed on each axis? Has a value of -1 when 
not set yielding a value of 1 (yes) for both axes. */
MAKE_CLEAR(LabelUp,labelup,-1,2)
MAKE_GET(LabelUp,int,0,( this->labelup[axis] == -1 ? 0 : this->labelup[axis] ),2)
MAKE_TEST(LabelUp,( this->labelup[axis] != -1 ),2)
MAKE_SET(LabelUp,int,labelup,( value ? 1 : 0 ),2)

/* DrawAxes */
/* -------- */
/*
*att++
*  Name:
*     DrawAxes

*  Purpose:
*     Draw axes for a Plot?

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer (boolean).

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     whether curves representing coordinate axes should be drawn.
*
*     If drawn, these axis lines will pass through any tick marks
*     associated with numerical labels drawn to mark values on the
*     axes. The location of these tick marks and labels (and hence the
*     axis lines) is determined by the Plot's LabelAt(axis) attribute.
*
*     If the DrawAxes value of a Plot is non-zero (the default), then
*     axis lines will be drawn, otherwise they will be omitted.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - Axis lines are drawn independently of any coordinate grid
*     lines (see the Grid attribute) so grid lines may be used to
*     substitute for axis lines if required.
*     - In some circumstances, numerical labels and tick marks are
*     drawn around the edges of the plotting area (see the Labelling
*     attribute).  In this case, the value of the DrawAxes attribute
*     is ignored.
*att--
*/
/* If non-zero draw a curve through the tick marks. Has a value of -1
   when not set yielding a default value of 1. */
astMAKE_CLEAR(Plot,DrawAxes,drawaxes,-1)
astMAKE_GET(Plot,DrawAxes,int,1,(this->drawaxes == -1 ? 1 : this->drawaxes))
astMAKE_SET(Plot,DrawAxes,int,drawaxes,( value ? 1 : 0 ))
astMAKE_TEST(Plot,DrawAxes,( this->drawaxes != -1 ))


/* Escape. */
/* ------- */

/* The facilities for including escape sequences in formated strings and
   axis values are not yet available in AST. Until they are, this attribute 
   is not made available to the public. When required, add "*att++" and
   "*att--" at the start and end of the prologue, and reinstate the
   correct call to astMAKE_GET which follows. (ENABLE-ESCAPE) */

/*
*  Name:
*     Escape

*  Purpose:
*     Interpret escape sequences within text strings?

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer (boolean).

*  Description:
*     This attribute controls the appearance of text strings and
c     numerical labels drawn by the astGrid and astText functions,
f     numerical labels drawn by the AST_GRID and AST_TEXT functions,
*     by determining if any escape sequences contained within the strings
*     should be used to control the appearance of the text, or should
*     be printed literally. 
*
*     If the Escape value of a Plot is one (the default), then any
*     escape sequences in text strings produce the effects described
*     below when printed. Otherwise, they are printed literally.

*  Escape Sequences:
*     Escape sequences are introduced into the text string by a percent 
*     "%" character. Any unrecognised, illegal or incomplete escape sequences 
*     are printed literally. The following escape sequences are 
*     currently recognised ("..." represents a string of one or more 
*     decimal digits):
*
*       %%      - Print a literal "%" character.
*
*       %^...+  - Draw subsequent characters as super-scripts. The digits
*                 "..." give the distance from the base-line of "normal" 
*                 text to the base-line of the super-script text, scaled 
*                 so that a value of "100" corresponds to the height of 
*                 "normal" text.
*       %^+     - Draw subsequent characters with the normal base-line.
*
*       %v...+  - Draw subsequent characters as sub-scripts. The digits
*                 "..." give the distance from the base-line of "normal" 
*                 text to the base-line of the sub-script text, scaled 
*                 so that a value of "100" corresponds to the height of 
*                 "normal" text.
*
*       %v+     - Draw subsequent characters with the normal base-line
*                 (equivalent to %^+).
*
*       %>...+  - Leave a gap before drawing subsequent characters.
*                 The digits "..." give the size of the gap, scaled 
*                 so that a value of "100" corresponds to the height of 
*                 "normal" text.
*
*       %s...+  - Change the Size attribute for subsequent characters. The
*                 digits "..." give the new Size as a fraction of the 
*                 "normal" Size, scaled so that a value of "100" corresponds 
*                 to 1.0;
*
*       %s+     - Reset the Size attribute to its "normal" value.
*
*       %w...+  - Change the Width attribute for subsequent characters. The
*                 digits "..." give the new width as a fraction of the 
*                 "normal" Width, scaled so that a value of "100" corresponds 
*                 to 1.0;
*
*       %w+     - Reset the Wize attribute to its "normal" value.
*
*       %f...+  - Change the Font attribute for subsequent characters. The
*                 digits "..." give the new Font value.
*
*       %f+     - Reset the Font attribute to its "normal" value.
*
*       %c...+  - Change the Colour attribute for subsequent characters. The
*                 digits "..." give the new Colour value.
*
*       %c+     - Reset the Colour attribute to its "normal" value.
*
*       %t...+  - Change the Style attribute for subsequent characters. The
*                 digits "..." give the new Style value.
*
*       %t+     - Reset the Style attribute to its "normal" value.
*
*       %+      - Reset all attributes to their "normal" values.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*/
/* Has a value of -1 when not set yeilding a default of 1. */

/* Use the following call to astMAKE_GET once the Escape attribute has
   been enabled (ENABLE-ESCAPE). 
astMAKE_GET(Plot,Escape,int,1,(this->escape == -1 ? 1 : this->escape))
   */

astMAKE_GET(Plot,Escape,int,0,0)
astMAKE_CLEAR(Plot,Escape,escape,-1)
astMAKE_SET(Plot,Escape,int,escape,( value ? 1 : 0 ))
astMAKE_TEST(Plot,Escape,( this->escape != -1 ))

/* LabelAt(axis). */
/* -------------- */
/*
*att++
*  Name:
*     LabelAt(axis)

*  Purpose:
*     Where to place numerical labels for a Plot

*  Type:
*     Public attribute.

*  Synopsis:
*     Floating point.

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     where numerical axis labels and associated tick marks are
*     placed.  It takes a separate value for each physical axis of a
*     Plot so that, for instance, the setting "LabelAt(2)=10.0"
*     specifies where the numerical labels and tick marks for the
*     second axis should be drawn.
*
*     For each axis, the LabelAt value gives the value on the other
*     axis at which numerical labels and tick marks should be placed
c     (remember that Plots suitable for use with astGrid may only
f     (remember that Plots suitable for use with AST_GRID may only
*     have two axes).  For example, in a celestial (RA,Dec) coordinate
*     system, LabelAt(1) gives a Dec value which defines a line (of
*     constant Dec) along which the numerical RA labels and their
*     associated tick marks will be drawn. Similarly, LabelAt(2) gives
*     the RA value at which the Dec labels and ticks will be drawn.
*
*     The default bahaviour is for the Plot to generate its own
*     position for numerical labels and tick marks.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - The LabelAt value should use the same units as are used
*     internally for storing coordinate values on the appropriate
*     axis. For example, with a celestial coordinate system, the
*     LabelAt value should be in radians, not hours or degrees.
*     - Normally, the LabelAt value also determines where the lines
*     representing coordinate axes will be drawn, so that the tick
*     marks will lie on these lines (but also see the DrawAxes
*     attribute).
*     - In some circumstances, numerical labels and tick marks are
*     drawn around the edges of the plotting area (see the Labelling
*     attribute).  In this case, the value of the LabelAt attribute is
*     ignored.
*att--
*/
/* The constant value on the other axis at which to place labels for
   each axis. */
MAKE_CLEAR(LabelAt,labelat,AST__BAD,2)
MAKE_GET(LabelAt,double,AST__BAD,this->labelat[axis],2)
MAKE_SET(LabelAt,double,labelat,value,2)
MAKE_TEST(LabelAt,( this->labelat[axis] != AST__BAD ),2)

MAKE_GET3(UsedLabelAt,double,AST__BAD,this->ulblat[axis],2)
MAKE_SET3(UsedLabelAt,double,ulblat,value,2)

/* Centre(axis). */
/* ------------ */
/* A value at which to place a tick mark. Other ticks marks are spaced at
regular distances from this one. AST__BAD is stored if no value is supplied, 
resulting in Plot choosing its own value. */
MAKE_CLEAR(Centre,centre,AST__BAD,2)
MAKE_GET(Centre,double,AST__BAD,this->centre[axis],2)
MAKE_SET(Centre,double,centre,value,2)
MAKE_TEST(Centre,( this->centre[axis] != AST__BAD ),2)

MAKE_GET3(UsedCentre,double,AST__BAD,this->ucentre[axis],2)
MAKE_SET3(UsedCentre,double,ucentre,value,2)

/* Ink */
/* --- */
/* A protected attribute indicating if astGrid should draw using visible
ink. The unset value is -1, yeilding a default value of 1. */
astMAKE_CLEAR(Plot,Ink,ink,-1)
astMAKE_GET(Plot,Ink,int,1,(this->ink == -1 ? 1 : this->ink))
astMAKE_SET(Plot,Ink,int,ink,( value ? 1 : 0 ))
astMAKE_TEST(Plot,Ink,( this->ink != -1 ))

/* Gap(axis). */
/* ---------- */
/*
*att++
*  Name:
*     Gap(axis)

*  Purpose:
*     Interval between major axis values of a Plot.

*  Type:
*     Public attribute.

*  Synopsis:
*     Floating point.

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     the interval between the "major" axis values of a Plot, at which
*     (for example) major tick marks are drawn. It takes a separate
*     value for each physical axis of the Plot so that, for instance,
*     the setting "Gap(2)=3.0" specifies the interval between major
*     values along the second axis.
*
*     The Gap value supplied will usually be rounded to the nearest
*     "nice" value, suitable (e.g.) for generating axis labels, before
*     use. To avoid this "nicing" you should set an explicit format
*     for the axis using the Format(axis) or Digits/Digits(axis)
*     attribute. The default behaviour is for the Plot to generate its
*     own Gap value when required, based on the range of axis values
*     to be represented.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - The Gap value should use the same units as are used internally
*     for storing coordinate values on the corresponding axis. For
*     example, with a celestial coordinate system, the Gap value
*     should be in radians, not hours or degrees.
*     - If no axis is specified, (e.g. "Gap" instead of "Gap(2)"),
*     then a "set" or "clear" operation will affect the attribute
*     value of all the Plot axes, while a "get" or "test" operation
*     will use just the Gap(1) value.
*att--
*/
/* The gap between tick marks on each axis. AST__BAD is stored if no
value has been supplied, resulting in default values being found. */
MAKE_CLEAR(Gap,gap,AST__BAD,2)
MAKE_SET(Gap,double,gap,value,2)
MAKE_TEST(Gap,( this->gap[axis] != AST__BAD ),2)
MAKE_GET(Gap,double,AST__BAD,this->gap[axis],2)

MAKE_SET3(UsedGap,double,ugap,value,2)
MAKE_GET3(UsedGap,double,AST__BAD,this->ugap[axis],2)

/* MajTickLen. */
/* ----------- */
/*
*att++
*  Name:
*     MajTickLen(axis)

*  Purpose:
*     Length of major tick marks for a Plot.

*  Type:
*     Public attribute.

*  Synopsis:
*     Floating point.

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     the length of the major tick marks drawn on the axes of a Plot.
*     It takes a separate value for each physical axis of the Plot so 
*     that, for instance, the setting "MajTickLen(2)=0" specifies the 
*     length of the major tick marks drawn on the second axis.
*
*     The MajTickLen value should be given as a fraction of the
*     minimum dimension of the plotting area. Negative values cause
*     major tick marks to be placed on the outside of the
*     corresponding grid line or axis (but subject to any clipping
*     imposed by the underlying graphics system), while positive
*     values cause them to be placed on the inside.
*
*     The default behaviour depends on whether a coordinate grid is
*     drawn inside the plotting area (see the Grid attribute). If so,
*     the default MajTickLen value is zero (so that major ticks are
*     not drawn), otherwise the default is +0.015.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - If no axis is specified, (e.g. "MajTickLen" instead of 
*     "MajTickLen(2)"), then a "set" or "clear" operation will affect 
*     the attribute value of all the Plot axes, while a "get" or "test" 
*     operation will use just the MajTickLen(1) value.

*att--
*/
/* Fractional length of major tick marks. Has a value of AST__BAD when not 
set yielding a default value of 0.015. */
MAKE_CLEAR(MajTickLen,majticklen,AST__BAD,2)
MAKE_SET(MajTickLen,double,majticklen,value,2)
MAKE_TEST(MajTickLen,( this->majticklen[axis] != AST__BAD ),2)
MAKE_GET(MajTickLen,double,0.0,( this->majticklen[axis] == AST__BAD ? 0.015 : this->majticklen[axis]),2)

MAKE_SET3(UsedMajTickLen,double,umjtkln,value,2)
MAKE_GET3(UsedMajTickLen,double,0.0,this->umjtkln[axis],2)

/* TitleGap. */
/* --------- */
/*
*att++
*  Name:
*     TitleGap

*  Purpose:
*     Vertical spacing for a Plot title.

*  Type:
*     Public attribute.

*  Synopsis:
*     Floating point.

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     where the title of a Plot is drawn.
*
*     Its value gives the spacing between the bottom edge of the title 
*     and the top edge of a bounding box containing all the other parts 
*     of the annotated grid. Positive values cause the title to be
*     drawn outside the box, while negative values cause it to be drawn 
*     inside.
*
*     The TitleGap value should be given as a fraction of the minimum
*     dimension of the plotting area, the default value being +0.05.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - The text used for the title is obtained from the Plot's Title
*     attribute.
*att--
*/
/* Fractional gap between titile and top edge. Has a value of AST__BAD when 
not set yielding a default value of 0.05. */
astMAKE_CLEAR(Plot,TitleGap,titlegap,AST__BAD)
astMAKE_GET(Plot,TitleGap,double,0.0,( this->titlegap == AST__BAD ? 0.05 : this->titlegap))
astMAKE_SET(Plot,TitleGap,double,titlegap,value)
astMAKE_TEST(Plot,TitleGap,( this->titlegap != AST__BAD ))

/* MinTickLen. */
/* ----------- */
/*
*att++
*  Name:
*     MinTickLen(axis)

*  Purpose:
*     Length of minor tick marks for a Plot.

*  Type:
*     Public attribute.

*  Synopsis:
*     Floating point.

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     the length of the minor tick marks drawn on the axes of a Plot.
*     It takes a separate value for each physical axis of the Plot so 
*     that, for instance, the setting "MinTickLen(2)=0" specifies the 
*     length of the minor tick marks drawn on the second axis.
*
*     The MinTickLen value should be given as a fraction of the
*     minimum dimension of the plotting area. Negative values cause
*     minor tick marks to be placed on the outside of the
*     corresponding grid line or axis (but subject to any clipping
*     imposed by the underlying graphics system), while positive
*     values cause them to be placed on the inside.
*
*     The default value is +0.007.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - The number of minor tick marks drawn is determined by the
*     Plot's MinTick(axis) attribute.
*     - If no axis is specified, (e.g. "MinTickLen" instead of 
*     "MinTickLen(2)"), then a "set" or "clear" operation will affect 
*     the attribute value of all the Plot axes, while a "get" or "test" 
*     operation will use just the MinTickLen(1) value.

*att--
*/
/* Fractional length of minor tick marks. Has a value of AST__BAD when not 
set yielding a default value of 0.007. */
MAKE_CLEAR(MinTickLen,minticklen,AST__BAD,2)
MAKE_SET(MinTickLen,double,minticklen,value,2)
MAKE_TEST(MinTickLen,( this->minticklen[axis] != AST__BAD ),2)
MAKE_GET(MinTickLen,double,0.0,( this->minticklen[axis] == AST__BAD ? 0.007 : this->minticklen[axis]),2)

/* Labelling. */
/* ---------- */
/*
*att++
*  Name:
*     Labelling

*  Purpose:
*     Label and tick placement option for a Plot.

*  Type:
*     Public attribute.

*  Synopsis:
*     String.

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     the strategy for placing numerical labels and tick marks for a Plot.
*
*     If the Labelling value of a Plot is "exterior" (the default), then 
*     numerical labels and their associated tick marks are placed
*     around the edges of the plotting area, if possible. If this is
*     not possible, or if the Labelling value is "interior", then they
*     are placed along grid lines inside the plotting area.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - The LabelAt(axis) attribute may be used to determine the exact
*     placement of labels and tick marks that are drawn inside the
*     plotting area.
*att--
*/
astMAKE_CLEAR(Plot,Labelling,labelling,-9999)
astMAKE_SET(Plot,Labelling,int,labelling,(value?1:0))
astMAKE_TEST(Plot,Labelling,( this->labelling != -9999 ))
astMAKE_GET(Plot,Labelling,int,0,(this->labelling == -9999 ? 0 : this->labelling))

MAKE_SET2(Plot,UsedLabelling,int,ulbling,(value?1:0))
MAKE_GET2(Plot,UsedLabelling,int,0,this->ulbling)

/* Edge. */
/* ----- */
/*
*att++
*  Name:
*     Edge(axis)

*  Purpose:
*     Which edges to label in a Plot

*  Type:
*     Public attribute.

*  Synopsis:
*     String.

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     which edges of a Plot are used for displaying numerical and
*     descriptive axis labels. It takes a separate value for each
*     physical axis of the Plot so that, for instance, the setting
*     "Edge(2)=left" specifies which edge to use to display labels for
*     the second axis.
*
*     The values "left", "top", "right" and "bottom" (or any
*     abbreviation) can be supplied for this attribute. The default is
*     usually "bottom" for the first axis and "left" for the second
*     axis. However, if exterior labelling was requested (see the
*     Labelling attribute) but cannot be produced using these default
*     Edge values, then the default values will be swapped if this
*     enables exterior labelling to be produced.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - In some circumstances, numerical labels will be drawn along
*     internal grid lines instead of at the edges of the plotting area
*     (see the Labelling attribute). In this case, the Edge attribute
*     only affects the placement of the descriptive labels (these are
*     drawn at the edges of the plotting area, rather than along the
*     axis lines).
*att--
*/
/* The edges of the plotting area on which to place numerical labels
   for axes 0 and 1. Has a value of -1 when not set yielding a value
   of 3 (the bottom edge) for axis 0 and 0 (the left-hand edge) for
   axis 1. */
MAKE_CLEAR(Edge,edge,-1,2)
MAKE_GET(Edge,int,0,( this->edge[axis] == -1 ? (axis?LEFT:BOTTOM) : this->edge[axis] ),2)
MAKE_SET(Edge,int,edge,(abs( value % 4 )),2)
MAKE_TEST(Edge,( this->edge[axis] != -1 ),2)

MAKE_GET3(UsedEdge,int,0,this->uedge[axis],2)
MAKE_SET3(UsedEdge,int,uedge,(abs( value % 4 )),2)

/* NumLab. */
/* -------- */
/*
*att++
*  Name:
*     NumLab(axis)

*  Purpose:
*     Draw numerical axis labels for a Plot?

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer (boolean). 

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     whether labels should be drawn to represent the numerical values
*     along each axis of a Plot. It takes a separate value for each
*     physical axis of a Plot so that, for instance, the setting
*     "NumLab(2)=1" specifies that numerical labels should be drawn
*     for the second axis.
*
*     If the NumLab value of a Plot axis is non-zero (the default),
*     then numerical labels will be drawn for that axis, otherwise
*     they will be omitted.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - The drawing of associated descriptive axis labels for a Plot
*     (describing the quantity being plotted along each axis) is
*     controlled by the TextLab(axis) attribute.
*     - If no axis is specified, (e.g. "NumLab" instead of
*     "NumLab(2)"), then a "set" or "clear" operation will affect the
*     attribute value of all the Plot axes, while a "get" or "test"
*     operation will use just the NumLab(1) value.
*att--
*/
/* Are numerical labels to be displayed on each axis? Has a value of
   -1 when not set yielding a value of 1 (yes) for both axes. */
MAKE_CLEAR(NumLab,numlab,-1,2)
MAKE_GET(NumLab,int,1,( this->numlab[axis] == -1 ? 1 : this->numlab[axis] ),2)
MAKE_TEST(NumLab,( this->numlab[axis] != -1 ),2)
MAKE_SET(NumLab,int,numlab,( value ? 1 : 0 ),2)

/* NumLabGap. */
/* --------- */
/*
*att++
*  Name:
*     NumLabGap(axis)

*  Purpose:
*     Spacing of numerical labels for a Plot.

*  Type:
*     Public attribute.

*  Synopsis:
*     Floating point.

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     where numerical axis labels are placed relative to the axes they
*     describe.  It takes a separate value for each physical axis of a
*     Plot so that, for instance, the setting "NumLabGap(2)=-0.01"
*     specifies where the numerical label for the second axis should
*     be drawn.
*
*     For each axis, the NumLabGap value gives the spacing between the
*     axis line (or edge of the plotting area, if appropriate) and the
*     nearest edge of the corresponding numerical axis
*     labels. Positive values cause the descriptive label to be placed
*     on the opposite side of the line to the default tick marks,
*     while negative values cause it to be placed on the same side.
*
*     The NumLabGap value should be given as a fraction of the minimum
*     dimension of the plotting area, the default value being +0.01.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - If no axis is specified, (e.g. "NumLabGap" instead of
*     "NumLabGap(2)"), then a "set" or "clear" operation will affect
*     the attribute value of all the Plot axes, while a "get" or
*     "test" operation will use just the NumLabGap(1) value.
*att--
*/
/* Fractional spacing between numeric labels and axes. Has a value of AST__BAD 
when not set yielding a default value of 0.01. */
MAKE_CLEAR(NumLabGap,numlabgap,AST__BAD,2)
MAKE_GET(NumLabGap,double,0.0,( this->numlabgap[ axis ] == AST__BAD ? 0.01 : this->numlabgap[axis]),2)
MAKE_SET(NumLabGap,double,numlabgap,value,2)
MAKE_TEST(NumLabGap,( this->numlabgap[axis] != AST__BAD ),2)

/* MinTick. */
/* -------- */
/*
*att++
*  Name:
*     MinTick(axis)

*  Purpose:
*     Density of minor tick marks for a Plot.

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer. 

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     the density of minor tick marks which appear between the major
*     axis values of a Plot. It takes a separate value for each
*     physical axis of a Plot so that, for instance, the setting
*     "MinTick(2)=2" specifies the density of minor tick marks along
*     the second axis.
*
*     The value supplied should be the number of minor divisions
*     required between each pair of major axis values, this being one
*     more than the number of minor tick marks to be drawn.  By
*     default, a value is chosen that depends on the gap between major
*     axis values and the nature of the axis.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - If no axis is specified, (e.g. "MinTick" instead of
*     "MinTick(2)"), then a "set" or "clear" operation will affect
*     the attribute value of all the Plot axes, while a "get" or
*     "test" operation will use just the MinTick(1) value.
*att--
*/
/* How many divisions are there between major tick marks? Has a value
of -1 when not set yielding a value of 1 for both axes. */
MAKE_CLEAR(MinTick,mintick,-1,2)
MAKE_GET(MinTick,int,1,( this->mintick[axis] == -1 ? 1 : this->mintick[axis] ),2)
MAKE_TEST(MinTick,( this->mintick[axis] != -1 ),2)
MAKE_SET(MinTick,int,mintick,( (value < 1)? 1 : value ),2)

MAKE_GET3(UsedMinTick,int,1,this->umintk[axis],2)
MAKE_SET3(UsedMinTick,int,umintk,( (value < 1)? 1 : value ),2)

/* TextLab. */
/* --------- */
/*
*att++
*  Name:
*     TextLab(axis)

*  Purpose:
*     Draw descriptive axis labels for a Plot?

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer (boolean). 

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     whether textual labels should be drawn to describe the quantity
*     being represented on each axis of a Plot. It takes a separate
*     value for each physical axis of a Plot so that, for instance,
*     the setting "TextLab(2)=1" specifies that descriptive labels
*     should be drawn for the second axis.
*
*     If the TextLab value of a Plot axis is non-zero, then
*     descriptive labels will be drawn for that axis, otherwise they
*     will be omitted. The default behaviour is to draw descriptive
*     labels if tick marks and numerical labels are being drawn around
*     the edges of the plotting area (see the Labelling attribute),
*     but to omit them otherwise.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - The text used for the descriptive labels is derived from the
*     Plot's Label(axis) attribute, together with its Unit(axis)
*     attribute if appropriate (see the LabelUnits(axis) attribute).
*     - The drawing of numerical axis labels for a Plot (which
*     indicate values on the axis) is controlled by the NumLab(axis)
*     attribute.
*     - If no axis is specified, (e.g. "TextLab" instead of
*     "TextLab(2)"), then a "set" or "clear" operation will affect
*     the attribute value of all the Plot axes, while a "get" or
*     "test" operation will use just the TextLab(1) value.
*att--
*/
/* Are textual labels to be displayed on each axis? Has a value of -1
   when not set yielding a value of 1 (yes) for both axes. */
MAKE_CLEAR(TextLab,textlab,-1,2)
MAKE_GET(TextLab,int,1,( this->textlab[axis] == -1 ? 1 : this->textlab[axis] ),2)
MAKE_TEST(TextLab,( this->textlab[axis] != -1 ),2)
MAKE_SET(TextLab,int,textlab,( value ? 1 : 0 ),2)

MAKE_GET3(UsedTextLab,int,1,this->utxtlb[axis],2)
MAKE_SET3(UsedTextLab,int,utxtlb,( value ? 1 : 0 ),2)

/* TextLabGap. */
/* ----------- */
/*
*att++
*  Name:
*     TextLabGap(axis)

*  Purpose:
*     Spacing of descriptive axis labels for a Plot.

*  Type:
*     Public attribute.

*  Synopsis:
*     Floating point.

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     where descriptive axis labels are placed relative to the axes they
*     describe.  It takes a separate value for each physical axis of a
*     Plot so that, for instance, the setting "TextLabGap(2)=0.01"
*     specifies where the descriptive label for the second axis should
*     be drawn.
*
*     For each axis, the TextLabGap value gives the spacing between the
*     descriptive label and the edge of a box enclosing all other parts
*     of the annotated grid (excluding other descriptive labels). The gap
*     is measured to the nearest edge of the label (i.e. the top or the 
*     bottom). Positive values cause the descriptive label to be placed 
*     outside the bounding box, while negative values cause it to be placed
*     inside.
*
*     The TextLabGap value should be given as a fraction of the minimum
*     dimension of the plotting area, the default value being +0.01.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - If drawn, descriptive labels are always placed at the edges of
*     the plotting area, even although the corresponding numerical
*     labels may be drawn along axis lines in the interior of the
*     plotting area (see the Labelling attribute).
*     - If no axis is specified, (e.g. "TextLabGap" instead of
*     "TextLabGap(2)"), then a "set" or "clear" operation will affect
*     the attribute value of all the Plot axes, while a "get" or
*     "test" operation will use just the TextLabGap(1) value.
*att--
*/
/* Fractional spacing between numeric labels and axes. Has a value of AST__BAD 
when not set yielding a default value of 0.01. */
MAKE_CLEAR(TextLabGap,textlabgap,AST__BAD,2)
MAKE_GET(TextLabGap,double,0.0,( this->textlabgap[ axis ] == AST__BAD ? 0.01 : this->textlabgap[axis]),2)
MAKE_SET(TextLabGap,double,textlabgap,value,2)
MAKE_TEST(TextLabGap,( this->textlabgap[axis] != AST__BAD ),2)

/* LabelUnits. */
/* ----------- */
/*
*att++
*  Name:
*     LabelUnits(axis)

*  Purpose:
*     Use axis unit descriptions in a Plot?

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer (boolean).

*  Description:
*     This attribute controls the appearance of an annotated
c     coordinate grid (drawn with the astGrid function) by determining
f     coordinate grid (drawn with the AST_GRID routine) by determining
*     whether the descriptive labels drawn for each axis of a Plot
*     should include a description of the units being used on the
*     axis.  It takes a separate value for each physical axis of a
*     Plot so that, for instance, the setting "LabelUnits(2)=1"
*     specifies that a unit description should be included in the
*     label for the second axis.
*
*     If the LabelUnits value of a Plot axis is non-zero, a unit
*     description will be included in the descriptive label for that
*     axis, otherwise it will be omitted.  The default behaviour is to
*     include a unit description unless the current Frame of the Plot
*     is a SkyFrame (i.e. a celestial coordinate system), in which
*     case it is omitted.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - The text used for the unit description is obtained from the
*     Plot's Unit(axis) attribute.
*     - If no axis is specified, (e.g. "LabelUnits" instead of
*     "LabelUnits(2)"), then a "set" or "clear" operation will affect
*     the attribute value of all the Plot axes, while a "get" or
*     "test" operation will use just the LabelUnits(1) value.
*     - If the current Frame of the Plot is not a SkyFrame, but includes
*     axes which were extracted from a SkyFrame, then the default behaviour
*     is to include a unit description only for those axes which were not
*     extracted from a SkyFrame.
*att--
*/
/* Are textual labels to include a string describing the axis units? Has a 
value of -1 when not set yielding a default of 1. */
MAKE_CLEAR(LabelUnits,labelunits,-1,2)
MAKE_GET(LabelUnits,int,1,( this->labelunits[axis] == -1 ? 1 : this->labelunits[axis] ),2)
MAKE_TEST(LabelUnits,( this->labelunits[axis] != -1 ),2)
MAKE_SET(LabelUnits,int,labelunits,( value ? 1 : 0 ),2)

MAKE_GET3(UsedLabelUnits,int,1,this->ulbunit[axis],2)
MAKE_SET3(UsedLabelUnits,int,ulbunit,( value ? 1 : 0 ),2)

/* Style. */
/* ------ */
/*
*att++
*  Name:
*     Style(element)

*  Purpose:
*     Line style for a Plot element.

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer.

*  Description:
*     This attribute determines the line style used when drawing each
*     element of graphical output produced by a Plot. It takes a
*     separate value for each graphical element so that, for instance,
*     the setting "Style(border)=2" causes the Plot border to be drawn
*     using line style 2 (which might result in, say, a dashed line).
*
*     The range of integer line styles available and their appearance
*     is determined by the underlying graphics system.  The default
*     behaviour is for all graphical elements to be drawn using the
*     default line style supplied by this graphics system (normally,
*     this is likely to give a solid line).

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - For a list of the graphical elements available, see the
*     description of the Plot class.
*     - If no graphical element is specified, (e.g. "Style" instead of
*     "Style(border)"), then a "set" or "clear" operation will affect
*     the attribute value of all graphical elements, while a "get" or
*     "test" operation will use just the Style(Border) value.
*att--
*/
/* Line styles. Has a value of -1 when not set yielding a default of 1. */
MAKE_CLEAR(Style,style,-1,AST__NPID)
MAKE_GET(Style,int,1,( this->style[axis] == -1 ? 1 : this->style[axis] ),AST__NPID)
MAKE_TEST(Style,( this->style[axis] != -1 ),AST__NPID)
MAKE_SET(Style,int,style,value,AST__NPID)

/* Font. */
/* ----- */
/*
*att++
*  Name:
*     Font(element)

*  Purpose:
*     Character font for a Plot element.

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer.

*  Description:
*     This attribute determines the character font index used when
*     drawing each element of graphical output produced by a Plot. It
*     takes a separate value for each graphical element so that, for
*     instance, the setting "Font(title)=2" causes the Plot title to
*     be drawn using font number 2.
*
*     The range of integer font indices available and the appearance
*     of the resulting text is determined by the underlying graphics
*     system.  The default behaviour is for all graphical elements to
*     be drawn using the default font supplied by this graphics
*     system.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - For a list of the graphical elements available, see the
*     description of the Plot class.
*     - If no graphical element is specified, (e.g. "Font" instead
*     of "Font(title)"), then a "set" or "clear" operation will
*     affect the attribute value of all graphical elements, while a
*     "get" or "test" operation will use just the Font(TextLab)
*     value.
*att--
*/
/* Character fonts. Has a value of -1 when not set yielding a default of 1. */
MAKE_CLEAR(Font,font,-1,AST__NPID)
MAKE_GET(Font,int,1,( this->font[axis] == -1 ? 1 : this->font[axis] ),AST__NPID)
MAKE_TEST(Font,( this->font[axis] != -1 ),AST__NPID)
MAKE_SET(Font,int,font,value,AST__NPID)

/* Colour. */
/* ------- */
/*
*att++
*  Name:
*     Colour(element)

*  Purpose:
*     Colour index for a Plot element.

*  Type:
*     Public attribute.

*  Synopsis:
*     Integer.

*  Description:
*     This attribute determines the colour index used when drawing
*     each element of graphical output produced by a Plot. It takes a
*     separate value for each graphical element so that, for instance,
*     the setting "Colour(title)=2" causes the Plot title to be drawn
*     using colour index 2. The synonym "Color" may also be used.
*
*     The range of integer colour indices available and their
*     appearance is determined by the underlying graphics system. The
*     default behaviour is for all graphical elements to be drawn
*     using the default colour index supplied by this graphics system
*     (normally, this is likely to result in white plotting on a black
*     background, or vice versa).
d
*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - For a list of the graphical elements available, see the
*     description of the Plot class.
*     - If no graphical element is specified, (e.g. "Colour" instead
*     of "Colour(title)"), then a "set" or "clear" operation will
*     affect the attribute value of all graphical elements, while a
*     "get" or "test" operation will use just the Colour(TextLab)
*     value.
*att--
*/
/* Colours. Has a value of -1 when not set yielding a default of 1. */
MAKE_CLEAR(Colour,colour,-1,AST__NPID)
MAKE_GET(Colour,int,1,( this->colour[axis] == -1 ? 1 : this->colour[axis] ),AST__NPID)
MAKE_TEST(Colour,( this->colour[axis] != -1 ),AST__NPID)
MAKE_SET(Colour,int,colour,value,AST__NPID)

/* Width. */
/* ------ */
/*
*att++
*  Name:
*     Width(element)

*  Purpose:
*     Line width for a Plot element.

*  Type:
*     Public attribute.

*  Synopsis:
*     Floating point.

*  Description:
*     This attribute determines the line width used when drawing each
*     element of graphical output produced by a Plot.  It takes a
*     separate value for each graphical element so that, for instance,
*     the setting "Width(border)=2.0" causes the Plot border to be
*     drawn using a line width of 2.0. A value of 1.0 results in a
*     line thickness which is approximately 0.0005 times the length of
*     the diagonal of the entire display surface.
*
*     The actual appearance of lines drawn with any particular width,
*     and the range of available widths, is determined by the
*     underlying graphics system.  The default behaviour is for all
*     graphical elements to be drawn using the default line width
*     supplied by this graphics system. This will not necessarily
*     correspond to a Width value of 1.0.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - For a list of the graphical elements available, see the
*     description of the Plot class.
*     - If no graphical element is specified, (e.g. "Width" instead of
*     "Width(border)"), then a "set" or "clear" operation will affect
*     the attribute value of all graphical elements, while a "get" or
*     "test" operation will use just the Width(Border) value.
*att--
*/
/* Line widths. Has a value of AST__BAD when not set yielding a
   default of 0.0. */
MAKE_CLEAR(Width,width,AST__BAD,AST__NPID)
MAKE_GET(Width,double,0.0,( this->width[axis] == AST__BAD ? 0.0 : this->width[axis] ),AST__NPID)
MAKE_TEST(Width,( this->width[axis] != AST__BAD ),AST__NPID)
MAKE_SET(Width,double,width,value,AST__NPID)

/* Size. */
/* ----- */
/*
*att++
*  Name:
*     Size(element)

*  Purpose:
*     Character size for a Plot element.

*  Type:
*     Public attribute.

*  Synopsis:
*     Floating Point.

*  Description:
*     This attribute determines the character size used when drawing
*     each element of graphical output produced by a Plot. It takes a
*     separate value for each graphical element so that, for instance,
*     the setting "Size(title)=2.0" causes the Plot title to be drawn
*     using twice the default character size.
*
*     The range of character sizes available and the appearance of the
*     resulting text is determined by the underlying graphics system.
*     The default behaviour is for all graphical elements to be drawn
*     using the default character size supplied by this graphics
*     system.

*  Applicability:
*     Plot
*        All Plots have this attribute.

*  Notes:
*     - For a list of the graphical elements available, see the
*     description of the Plot class.
*     - If no graphical element is specified, (e.g. "Size" instead
*     of "Size(title)"), then a "set" or "clear" operation will
*     affect the attribute value of all graphical elements, while a
*     "get" or "test" operation will use just the Size(TextLab)
*     value.
*att--
*/
/* Character sizes. Has a value of AST__BAD when not set yielding a default 
   of 1.0. */
MAKE_CLEAR(Size,size,AST__BAD,AST__NPID)
MAKE_GET(Size,double,1.0,( this->size[axis] == AST__BAD ? 1.0 : this->size[axis] ),AST__NPID)
MAKE_TEST(Size,( this->size[axis] != AST__BAD ),AST__NPID)
MAKE_SET(Size,double,size,value,AST__NPID)

/* Member functions. */
/* ================= */
static void AddCdt( CurveData *cdt1, CurveData *cdt2, const char *method, 
                    const char *class ){
/*
*
*  Name:
*     AddCdt

*  Purpose:
*     Append one CurveData structure to another.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void AddCdt( CurveData *cdt1, CurveData *cdt2, const char *method, 
*                  const char *class )

*  Class Membership:
*     Plot private function.

*  Description:
*     The contents of the structure pointed to by "cdt2" is appended
*     to the structure pointed to by "cdt1".

*  Parameters:
*     cdt1
*        Pointer to the CurveData structure to be modified.
*     cdt2
*        Pointer to the CurveData structure to be appended to cdt1.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Notes:
*     -  An error is reported if there is insufficient room in "cdt1" to
*     store the information in "cdt2".

*/

/* Local Variables: */
   int nbrk, i, j;

/* Check the global error status. */
   if ( !astOK ) return;

/* Get the total number of breaks described by both structures. */
   nbrk = cdt1->nbrk + cdt2->nbrk;

/* Report an error if this number of breaks cannot be stored in a CurveData
   structure. */
   if( nbrk > AST__MXBRK ){
      astError( AST__CVBRK, "%s(%s): Number of breaks in curve "
                "exceeds %d.", method, class, AST__MXBRK );

/* Otherwise, append the information. */
   } else {

/* Store the index within "cdt1" of the next break to be added. */
      j = cdt1->nbrk;

/* Add each the position and direction information for each of the breaks
   in "cdt2". */
      for( i = 0; i < cdt2->nbrk; i++ ){
         cdt1->xbrk[ j ] = cdt2->xbrk[ i ];
         cdt1->ybrk[ j ] = cdt2->ybrk[ i ];
         cdt1->vxbrk[ j ] = cdt2->vxbrk[ i ];
         cdt1->vybrk[ j ] = cdt2->vybrk[ i ];

/* Increment the index of the next break in "cdt1". */
         j++;
      }

/* Update the number of breaks in "cdt1". */
      cdt1->nbrk = nbrk; 

/* Update the length of the curve described by "cdt1". */
      cdt1->length += cdt2->length; 

/* Update the flag indicating if the entire curve is outside the plotting
   zone. */ 
      if( !cdt2->out ) cdt1->out = 0;

   }

/* Return. */
   return;

}

static void Apoly( float x, float y, const char *method, const char *class ){
/*
*  Name:
*     Apoly

*  Purpose:
*     Append a another point to a poly line.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void Apoly( float x, float y, const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function appends the supplied point to the current poly line. If 
*     this results in the buffer being filled, the buffer is drawn, and 
*     re-set to hold just the supplied point.

*  Parameters:
*     x
*        The graphics x coordinate.
*     y
*        The graphics y coordinate.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*/

/* Check the global status. */
   if( !astOK ) return;

/* If the buffer is already full, output it to the screen and re-initialise 
   it to hold just the final point. */      
   if( Poly_n == POLY_MAX ){
      Opoly( method, class );
      Poly_x[ 0 ] = Poly_x[ POLY_MAX - 1 ];
      Poly_y[ 0 ] = Poly_y[ POLY_MAX - 1 ];
      Poly_n = 1;
   }

/* Add the supplied point to the buffer. */
   Poly_x[ Poly_n ] = x;   
   Poly_y[ Poly_n++ ] = y;   

/* Update the box containing all plotted lines. */
   Box_lbnd[ 0 ] = MIN( x, Box_lbnd[ 0 ] );
   Box_ubnd[ 0 ] = MAX( x, Box_ubnd[ 0 ] );
   Box_lbnd[ 1 ] = MIN( y, Box_lbnd[ 1 ] );
   Box_ubnd[ 1 ] = MAX( y, Box_ubnd[ 1 ] );

}

static void AxPlot( AstPlot *this, int axis, const double *start, double length,
                    int ink, CurveData *cdata, int normal, const char *method, 
                    const char *class ){
/*
*
*  Name:
*     AxPlot

*  Purpose:
*     Draw a curve with constant axis value.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void AxPlot( AstPlot *this, int axis, const double *start, double length,
*                  int ink, CurveData *cdata, int normal, const char *method, 
*                  const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function draws a section of a curve of the specified length 
*     with constant value on a specified axis in the current Frame of the 
*     Plot, starting at the specified position. The algorithm used can handle 
*     discontinuities in the Mapping between the current Frame and graphics 
*     coordinates, and information describing any breaks in the curve 
*     (including the start and end of the curve) are returned in the supplied 
*     CurveData structure. 

*  Parameters:
*     this
*        Pointer to the Plot.
*     axis
*        The zero-based index of an axis within the current Frame of the Plot. 
*        The curve has a varying value on this axis.
*     start
*        A pointer to a an array holding the coordinates of the start of the 
*        curve within the current Frame of the Plot.
*     length
*        The length of the section of the curve to be drawn, given as an 
*        increment along the axis specified by parameter "axis".
*     ink
*        If zero, the curve is not actually drawn, but information about 
*        the breaks is still returned. If non-zero, the curve is also drawn.
*     cdata
*        A pointer to a structure in which to return information about the
*        breaks in the curve.
*     normal
*        If non-zero, then only draw points which are within the normal
*        ranges of the physical axes. Otherwise, draw all points.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Notes:
*     -  No curve is draw if the "start" array contains any bad values
*     (i.e. values equal to AST__BAD), or if the "length" value is bad,
*     or if a NULL pointer is supplied for "cdata". No errors are reported 
*     in these cases.
*/

/* Local Variables: */
   double d[ CRV_NPNT ];   /* Offsets to evenly spaced points along curve */
   double x[ CRV_NPNT ];   /* X coords at evenly spaced points along curve */
   double y[ CRV_NPNT ];   /* Y coords at evenly spaced points along curve */
   double tol;             /* Absolute tolerance value */
   int i;                  /* Loop count */
   int naxes;              /* No. of axes in the base Frame */
   int ok;                 /* Are all start coords good? */

/* Check the global error status. */
   if ( !astOK ) return;

/* Get the number of axes in the current Frame. */
   naxes = astGetNout( this );

/* Check the "start" parameter for bad values. */
   ok = 1;
   for( i = 0; i < naxes; i++ ) {
      if( start[ i ] == AST__BAD ){
         ok = 0;
         break;
      }
   }

/* Check the "length" parameter for bad values. */
   if( length == AST__BAD ) ok = 0;

/* Check that the "cdata" pointer can be used. */
   if( !cdata ) ok = 0;

/* Only proceed if the parameters are OK, and there has been no error. */
   if( ok && astOK ){   

/* Establish the correct graphical attributes as defined by attributes
   with the supplied Plot. */
      GrfAttrs( this, GRIDLINE_ID, 1, GRF__LINE );

/* Set up the externals used to communicate with the Map1 function...
   The number of axes in the physical coordinate system (i.e. the current
   Frame). */
      Map1_ncoord = naxes;

/* A pointer to the Plot, the Current Frame and the Mapping. */
      Map1_plot = this;
      Map1_frame = astGetFrame( this, AST__CURRENT );
      Map1_map = astGetMapping( this, AST__BASE, AST__CURRENT );

/* The physical coordinates at the start of the curve. */
      Map1_origin = start;

/* The scale factor to convert "dist" values into physical axis values. */
      Map1_scale = length;

/* The index of the axis which the curve follows. */
      Map1_axis = axis;

/* Copy the flag which says whether to omit points not in their normal
   ranges. */
      Map1_norm = normal;

/* Convert the tolerance from relative to absolute graphics coordinates. */
      tol = astGetTol( this )*MAX( this->xhi - this->xlo, 
                                   this->yhi - this->ylo );

/* Now set up the external variables used by the Crv and CrvLine function. */
      Crv_ux0 = AST__BAD;    
      Crv_tol = tol;
      Crv_limit = 0.5*tol*tol;
      Crv_map = Map1;
      Crv_ink = ink;
      Crv_xlo = this->xlo;
      Crv_xhi = this->xhi;
      Crv_ylo = this->ylo;
      Crv_yhi = this->yhi;
      Crv_out = 1;
      Crv_xbrk = cdata->xbrk;
      Crv_ybrk = cdata->ybrk;
      Crv_vxbrk = cdata->vxbrk;
      Crv_vybrk = cdata->vybrk;

/* Set up a list of points spread evenly over the curve. */
      for( i = 0; i < CRV_NPNT; i++ ){
        d[ i ] = ( (double) i)/( (double) CRV_NSEG );
      }

/* Map these points into graphics coordinates. */
      Map1( CRV_NPNT, d, x, y, method, class );

/* Use Crv and Map1 to draw the curve. */
      Crv( d, x, y, method, class );

/* End the current poly line. */
      Opoly( method, class );

/* Tidy up the static data used by Map1. */
      Map1( 0, NULL, NULL, NULL, method, class );

/* If no part of the curve could be drawn, set the number of breaks and the 
   length of the drawn curve to zero. */
      if( Crv_out ) {
         Crv_nbrk = 0;
         Crv_len = 0.0F;

/* Otherwise, add an extra break to the returned structure at the position of 
   the last point to be plotted. */
      } else {
         Crv_nbrk++;
         if( Crv_nbrk > CRV_MXBRK ){
            astError( AST__CVBRK, "%s(%s): Number of breaks in curve "
                      "exceeds %d.", method, class, CRV_MXBRK );
         } else {
            *(Crv_xbrk++) = (float) Crv_xl;
            *(Crv_ybrk++) = (float) Crv_yl;
            *(Crv_vxbrk++) = (float) -Crv_vxl;
            *(Crv_vybrk++) = (float) -Crv_vyl;
         }
      }

/* Store extra information about the curve in the returned structure. */
      if( cdata ){
         cdata->length = Crv_len;
         cdata->out = Crv_out;
         cdata->nbrk = Crv_nbrk;
      }

/* Annul the Frame and Mapping. */
      Map1_frame = astAnnul( Map1_frame );
      Map1_map = astAnnul( Map1_map );

/* Re-establish the original graphical attributes. */
      GrfAttrs( this, GRIDLINE_ID, 0, GRF__LINE );

   }

/* Return. */
   return;

}

static int Boundary( AstPlot *this, const char *method, const char *class ){
/*
*  Name:
*     Boundary

*  Purpose:
*     Draw a boundary around regions containing valid physical positions.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int Boundary( AstPlot *this, const char *method, const char *class  )

*  Class Membership:
*     Plot method.

*  Description:
*     This function draws a boundary around the regions of the plotting
*     area which contain valid, unclipped, physical coordinates, but does
*     not include the intersections with the edges of the plotting area.
*
*     Broadly, the algorithm is as follows: An initial coarse grid is
*     created covering the entire plotting area. This grid consists of a 
*     regular square matrix of points in graphics coordinates, and the 
*     corresponding physical coordinates. An array of flags is created,
*     one for each grid cell, indicating if the boundary passes through the
*     cell. This is assumed to be the case if the cell has a mix of good and 
*     bad corners (i.e corners which have good or bad physical coordinates). 
*     This assumption does not locate all boundary cells though, since if
*     the boundary passes into and out of a cell throught the same edge,
*     the corners of the cell will be either all good or all bad. But for
*     the moment, we just concentrate on the ones found using this simple
*     assumption. For each such cell, a finer grid is then created covering 
*     the cell, and the boundary is drawn through this fine grid using 
*     TraceBorder. TraceBorder returns a set of four flags indicating which 
*     edges of the cell were intersected by the boundary. A check is then 
*     made on any of the four neighbouring cells into which the curve
*     passes. If any of these cells were not flagged as boundary cells using 
*     the simple assumption described earlier, then they are flagged now
*     (with a different flag value). Once all the cells located using the 
*     simple assumption have been processed, any further cells flagged
*     with the new flag value are also processed using TraceBorder in the
*     same way. This process is repeated until no extra boundary cells are
*     found.

*  Parameters:
*     this
*        Pointer to a Plot.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     A flag indicating if any regions containing invalid physical
*     coordinates were found within the plotting area.

*  Notes:
*     -  This function assumes the physical coordinate Frame is
*     2-dimensional, and it should not be used if this is not the case.
*     -  A value of zero is returned if an error has already occurred, or
*     if this function should fail for any reason. 

*/

/* Local Variables: */
   AstMapping *map;        /* Pointer to Plot mapping (graphics -> physical) */
   AstPointSet *pset1;     /* PointSet holding coarse grid graphics coords */
   AstPointSet *pset2;     /* PointSet holding coarse grid physical coords */
   AstPointSet *pset3;     /* PointSet holding fine grid graphics coords */
   AstPointSet *pset4;     /* PointSet holding fine grid physical coords */
   double **ptr1;          /* Pointer to coarse grid graphics coords */
   double **ptr2;          /* Pointer to coarse grid physical coords */
   double **ptr3;          /* Pointer to fine grid graphics coords */
   double **ptr4;          /* Pointer to fine grid physical coords */
   double *ptr3b[2];       /* Pointers to next fine grid graphics coords */
   double *ptr4b[2];       /* Pointers to next fine grid physical coords */
   double power;           /* Exponent in pow call */
   double rlimit;          /* Maximum grid dimension */
   double tol;             /* Fractional plotting tolerance */
   int *flag;              /* Pointer to next cell's flag */
   int *flags;             /* Pointer to array of cell flags */
   int bc;                 /* Number ofmbad corners in current cell */
   int c0;                 /* Index of bottom left corner */
   int c1;                 /* Index of bottom right corner */
   int c2;                 /* Index of top right corner */
   int c3;                 /* Index of top left corner */
   int dim;                /* No. of points along each edge of coarse grid */
   int edge[ 4 ];          /* Intersection flags for each cell edge */
   int el;                 /* Index of next cell within PointSet */
   int flag_value;         /* Flag value for cells currently being drawn */
   int i;                  /* Column index */
   int j;                  /* Row index */
   int limit;              /* Maximum grid dimension */
   int nbndry;             /* No. of boundary cells with current flag value */
   int ncell;              /* No. of cells along each edge of coarse grid */
   int rdim;               /* No. of points along each edge of fine grid */
   int ret;                /* Any regions containing bad physical coords? */
   int rsize;              /* No. of points in fine grid */
   int size;               /* No. of cells in coarse grid */

/* Check global status. */
   if( !astOK ) return 0;

/* Initialise the answer to indicate that no regions containing invalid
   physical coordinates have been found. */
   ret = 0;

/* Store the fractional plotting tolerance. */
   tol = astGetTol( this );

/* Extract the mapping from the Plot. */
   map = astGetMapping( this, AST__BASE, AST__CURRENT );

/* Set up the dimension of a coarse grid in graphics coordinates to cover the 
   whole plotting area. This is chosen to give a finer grid for smaller
   plotting tolerances. Note, putting the power as a literal constant in
   the call to pow seems to cause a segmentation violation on some systems. */
   power = -0.666666666;
   dim = (int) pow( tol, power ) + 10;
   if( dim > 400 ) dim = 400;

/* Create the grid. */
   ptr2 = MakeGrid( this, NULL, map, dim, this->xlo, this->xhi, this->ylo, 
                    this->yhi, 2, &pset1, &pset2, 0, method, class );

/* Store the number of cells along each edge of the grid. */
   ncell = dim - 1;

/* Allocate memory to hold a flag for each cell of the coarse grid. These
   flags indicate if the good/bad boundary passes through each cell. */
   size = ncell*ncell;
   flags = (int *) astMalloc( sizeof(int)*(size_t)size );
   flag = flags;

/* Check the pointers just obtained can be used. */
   if( astOK ){

/* Initialise the flag for every cell to indicate that the good/bad
   boundary does not pass through the cell. */
      for( i = 0; i < size; i++ ) flags[ i ] = 0;

/* Loop through each row in the coarse grid. */
      for( j = 0; j < ncell; j++ ){   

/* Store the indices within the PointSet of the four corners of the first
   cell in the current row. The corners are: c0-bottom left, c1-bottom right, 
   c2-top right, c3-top left. */
         c0 = j*dim;
         c1 = c0 + 1;
         c2 = c1 + dim;
         c3 = c2 - 1;      

/* Loop through every cell in the current row. */
         for( i = 0; i < ncell; i++ ){   

/* Count the number of bad corners in the current cell. */
            bc = 0;       
            if( ptr2[ 0 ][ c0 ] == AST__BAD ||
                ptr2[ 1 ][ c0 ] == AST__BAD ) bc++;
            if( ptr2[ 0 ][ c1 ] == AST__BAD ||
                ptr2[ 1 ][ c1 ] == AST__BAD ) bc++;
            if( ptr2[ 0 ][ c2 ] == AST__BAD ||
                ptr2[ 1 ][ c2 ] == AST__BAD ) bc++;
            if( ptr2[ 0 ][ c3 ] == AST__BAD ||
                ptr2[ 1 ][ c3 ] == AST__BAD ) bc++;
  
/* If any bad corners were found, set the returned flag to indicate that
   some regions containing invalid physical coordinates have been found. */
            if( bc ) ret = 1;

/* The good/bad boundary is assumed to pass through the cell if there are both
   good and bad corners. If it does, set the flag for the cell. */
            if( bc > 0 && bc < 4 ) *flag = 1;

/* Update everything to refer to the next cell. */
            c0++;
            c1++;
            c2++;
            c3++;
            flag++;
          }
  
      }

/* Count the boundary cells. */
      flag = flags;
      nbndry = 0;
      for( i = 0; i < size; i++ ) {
         if( *(flag++) ) nbndry++;
      }

/* If any boundary cells were found, draw the boundary using a refined
   grid. */
      if( nbndry ){

/* Get a pointer to the graphics coordinate data for the coarse grid. */
         ptr1 = astGetPoints( pset1 );         


/* Each of the boundary cells from the coarse grid is sub-divided into
   a refined grid so that the refined grid has cells of the size specified
   by the supplied plotting tolerance. Find the dimension for the refined 
   grids covering each individual boundary cell. Do not let the total
   number of cells in all the refined grids exceed 1E6. */
         rdim = (int)( 1.0 / ( tol*dim ) ) + 1;

         if( rdim < 2 ) {
            rdim = 2;

         } else {
            rlimit = sqrt( 1.0E6 / (double) nbndry );
            limit = (int) rlimit;
            if( rdim > limit ) rdim = limit;
         }

         rsize = rdim*rdim;

/* Loop until all boundary cells have been drawn. We initially draw the
   boundary through cells which are flagged with the value 1. */
         flag_value = 1;
         while( nbndry ){

/* Create two PointSets to hold the graphics and physical coordinates for 
   the refined grids for all boundary cells. */
            pset3 = astPointSet( rsize*nbndry, 2, "" );
            pset4 = astPointSet( rsize*nbndry, 2, "" );

/* Get a pointer to the graphics coordinate PointSet data arrays, and
   store the starting address of each axis. */
            ptr3 = astGetPoints( pset3 );         
            ptr3b[ 0 ] = ptr3[ 0 ];
            ptr3b[ 1 ] = ptr3[ 1 ];

/* Store a pointer to the boundary flag for the first cell in the coarse
   grid. */
            flag = flags;

/* Check everything is OK. */
            if( astOK ){

/* Loop through each row of cells in the coarse grid. */
               for( j = 0; j < ncell; j++ ){   

/* Store the indices within the coarse grid PointSets of the bottom left
   and top right corners of the first cell in the current row. */
                  c0 = j*dim;
                  c2 = c0 + 1 + dim;
   
/* Loop through each cell in the current row of the coarse grid. */
                  for( i = 0; i < ncell; i++ ){   

/* If this cell is a boundary cell with the required flag value, store a 
   refined grid of graphics coordinates covering the area of the cell. */
                     if( *( flag++ ) == flag_value ){
                        GraphGrid( rdim, ptr1[ 0 ][ c0 ], ptr1[ 0 ][ c2 ], 
                                   ptr1[ 1 ][ c0 ], ptr1[ 1 ][ c2 ], ptr3b );

/* Increment the pointers to the next values to be added to the PointSet
   arrays. */
                        ptr3b[ 0 ] += rsize;
                        ptr3b[ 1 ] += rsize;
                     }

/* Update the corner indices to refer to the next cell of the coarse grid. */
                     c0++;
                     c2++;
                   }
               }
            }

/* Transform the graphics coordinates to get the corresponding physical
   coordinates. */
            (void) Trans( this, NULL, map, pset3, 1, pset4, 0, method, class ); 

/* Get a pointer to the physical coordinate PointSet data array. */
            ptr4 = astGetPoints( pset4 );         

/* Store pointers to the start of each graphics and physical axis. */
            ptr3b[ 0 ] = ptr3[ 0 ];
            ptr3b[ 1 ] = ptr3[ 1 ];
            ptr4b[ 0 ] = ptr4[ 0 ];
            ptr4b[ 1 ] = ptr4[ 1 ];

/* Check everything is OK. */
            if( astOK ){

/* Store a pointer to the boundary flag for the first cell in the coarse
   grid. */
               flag = flags;

/* Initialise the index of the first coarse grid cell in the PointSet. */
               el = 0;

/* Initialise the number of boundary cells found to be processed with a new
   flag value on the next pass through the "while" loop. */
               nbndry = 0;

/* Loop through each row of cells in the coarse grid. */
               for( j = 0; j < ncell; j++ ){   

/* Loop through each cell in the current row of the coarse grid. */
                  for( i = 0; i < ncell; i++ ){   

/* If this cell is a boundary cell with the current flag value, trace the 
   boundary through it using the refined grid. */
                     if( *( flag++ ) == flag_value ){
                        TraceBorder( ptr3b, ptr4b, rdim, edge, method, class );

/* Increment the pointers to the next values to be read from the PointSet
   arrays. */
                        ptr3b[ 0 ] += rsize;
                        ptr3b[ 1 ] += rsize;
                        ptr4b[ 0 ] += rsize;
                        ptr4b[ 1 ] += rsize;

/* If the curve passes into a coarse grid cell which has not been flagged
   as a boundary cell, flag it now, and count the number of extra boundary
   cells which need to be done. First deal with cases where the curve passes 
   through the bottom edge of the current coarse grid cell. */
                        if( edge[ 0 ] && j > 0 ) {
                           if( !flags[ el - ncell ] ){
                              flags[ el - ncell ] = flag_value + 1;
                              nbndry++;
                           }
                        }

/* Now deal with cases where the curves passes through the right-hand
   edge of the current coarse grid cell. */
                        if( edge[ 1 ] && i < ncell - 1 ) {
                           if( !flags[ el + 1 ] ){
                              flags[ el + 1 ] = flag_value + 1;
                              nbndry++;
                           }
                        }

/* Now deal with cases where the curves passes through the top edge of 
   the current coarse grid cell. */
                        if( edge[ 2 ] && j < ncell - 1 ) {
                           if( !flags[ el + ncell ] ){
                              flags[ el + ncell ] = flag_value + 1;
                              nbndry++;
                           }
                        }

/* Now deal with cases where the curves passes through the left-hand
   edge of the current coarse grid cell. */
                        if( edge[ 3 ] && i > 0 ) {
                           if( !flags[ el - 1 ] ){
                              flags[ el - 1 ] = flag_value + 1;
                              nbndry++;
                           }
                        }
                     }

/* Increment the index of the current coarse grid cell in the PointSet. */
                     el++;
                   }
               }
            }

/* Annul the PointSets holding the refined grid. */
            pset3 = astAnnul( pset3 );
            pset4 = astAnnul( pset4 );

/* Increment the flag value for the cells to be processed on the next
   pass. */
            flag_value++;
          }
       }
    }

/* Release the remaining resources. */
   map = astAnnul( map );
   pset1 = astAnnul( pset1 );
   pset2 = astAnnul( pset2 );
   flags = (int *) astFree( (void *) flags );

/* If an error has occurred, return 0. */
   if( !astOK ) ret = 0;

/* Return the answer. */
   return ret;

}

static int Border( AstPlot *this_nd ){
/*
*++
*  Name:
c     astBorder
f     AST_BORDER

*  Purpose:
*     Draw a border around valid regions of a Plot.

*  Type:
*     Public virtual function.

*  Synopsis:
c     #include "plot.h"
c     int astBorder( AstPlot *this )
f     RESULT = AST_BORDER( THIS, STATUS )

*  Class Membership:
*     Plot method.

*  Description:
*     This function draws a (line) border around regions of the
*     plotting area of a Plot which correspond to valid, unclipped
*     physical coordinates. For example, when plotting using an
*     all-sky map projection, this function could be used to draw the
*     boundary of the celestial sphere when it is projected on to the
*     plotting surface.
*
*     If the entire plotting area contains valid, unclipped physical
*     coordinates, then the boundary will just be a rectangular box
*     around the edges of the plotting area.

*  Parameters:
c     this
f     THIS = INTEGER (Given)
*        Pointer to the Plot.
f     STATUS = INTEGER (Given and Returned)
f        The global status.

*  Returned Value:
c     astBorder()
f     AST_BORDER = LOGICAL
c        Zero is returned if the plotting area is completely filled by
f        .FALSE. is returned if the plotting area is completely filled by
*        valid, unclipped physical coordinates (so that only a
c        rectangular box was drawn around the edge). Otherwise, one is
f        rectangular box was drawn around the edge). Otherwise, .TRUE. is
*        returned.

*  Notes:
c     - A value of zero will be returned if this function is invoked
f     - A value of .FALSE. will be returned if this function is invoked
c     with the AST error status set, or if it should fail for any
f     with STATUS set to an error value, or if it should fail for any
*     reason.
*     - An error results if either the current Frame or the base Frame
*     of the Plot is not 2-dimensional.
*     - An error also results if the transformation between the base
*     and current Frames of the Plot is not defined (i.e. the Plot's
*     TranForward attribute is zero).
*--
*/

/* Local Variables: */
   AstPlot *this;          /* Plot with no more than 2 current axes */
   CurveData cdata;        /* Structure to receive break information */
   const char *class;      /* Object class */
   const char *method;     /* Current method */
   int inval;              /* Were any bad regions found? */
   int naxes;              /* No. of axes in the base Frame */

/* Check the global error status. */
   if ( !astOK ) return 0;

/* Store the current method, and the class of the supplied object for use 
   in error messages.*/
   method = "astBorder";
   class = astGetClass( this_nd );

/* Check the base Frame of the Plot is 2-D. */
   naxes = astGetNin( this_nd );
   if( naxes != 2 && astOK ){
      astError( AST__NAXIN, "%s(%s): Number of axes (%d) in the base "
                "Frame of the supplied %s is invalid - this number should "
                "be 2.", method, class, naxes, class );
   } 

/* Get a Plot with a 2D (or 1D) current Frame. */
   this = (AstPlot *) Fset2D( (AstFrameSet *) this_nd, AST__CURRENT );

/* Check the current Frame of the Plot is 2-D. */
   naxes = astGetNout( this );
   if( naxes != 2 && astOK ){
      astError( AST__NAXIN, "%s(%s): Number of axes (%d) in the current "
                "Frame of the supplied %s is invalid - this number should "
                "be 2.", method, class, naxes, class );
   } 

/* Establish the correct graphical attributes as defined by attributes
   with the supplied Plot. */
   GrfAttrs( this, BORDER_ID, 1, GRF__LINE );

/* We first draw the intersections of the regions containing valid
   physical coordinates with the edges of the plotting area. First do
   the bottom edge. */
   LinePlot( this, this->xlo, this->ylo, this->xhi, this->ylo,
             1, &cdata, method, class );

/* Now do the right-hand edge. */
   LinePlot( this, this->xhi, this->ylo, this->xhi, this->yhi, 
             1, &cdata, method, class );

/* Now do the top edge. */
   LinePlot( this, this->xhi, this->yhi, this->xlo, this->yhi, 
             1, &cdata, method, class );

/* Now do the left-hand edge. */
   LinePlot( this, this->xlo, this->yhi, this->xlo, this->ylo, 
             1, &cdata, method, class );

/* Now draw a curve following the boundary through the interior of the 
   plotting area. */
   inval = Boundary( this, method, class );

/* Re-establish the original graphical attributes. */
   GrfAttrs( this, BORDER_ID, 0, GRF__LINE );

/* Annul the 2d plot. */
   this = astAnnul( this );

/* Return. */
   return inval;

}

static int BoxCheck( float *bx, float *by, float *cx, float *cy ) {
/*
*  Name:
*     BoxCheck

*  Purpose:
*     See if two boxes overlap.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int BoxCheck( float *bx, float *by, float *cx, float *cy )

*  Class Membership:
*     Plot method.

*  Description:
*     This function returns a flag indicating if two trapezoidal boxes 
*     (box "b" and box "c") overlap or not. 

*  Parameters:
*     bx
*        Pointer to an array holding the X coordinates at the 4 corners
*        of box "b".
*     by
*        Pointer to an array holding the Y coordinates at the 4 corners
*        of box "b".
*     cx
*        Pointer to an array holding the X coordinates at the 4 corners
*        of box "c".
*     cy
*        Pointer to an array holding the Y coordinates at the 4 corners
*        of box "c".

*  Returned Value:
*     Zero is returned if the boxes do not overlap or an error has
*     already occurred. Otherwise, 1 is returned.

*/

/* Local Variables: */
   float x2;
   float y2;
   int i;
   int ip;
   int j;
   int jp;
   int ret;

/* Assume the boxes do not overlap. */
   ret = 0;

/* Check the inherited status. */
   if( !astOK ) return ret;

/* Check each corner of box b to see if it is inside box c. */
   for( j = 0; j < 4 && ret == 0; j++ ){
      if( Inside( 4, cx, cy, bx[ j ], by[ j ] ) ) ret = 1;
   }

/* Now check each corner of box c to see if it is inside box b. */
   for( j = 0; j < 4 && ret == 0; j++ ){
      if( Inside( 4, bx, by, cx[ j ], cy[ j ] ) ) ret = 1;
   }

/* If no overlap has yet been found, we need to see if any of the edges
   of the boxes intersect. For instance, in the case of a cross formed by
   a vertical rectangle crossing a horizontal rectangle, the above checks
   on the corners would not have revealed any overlap. */
   if( !ret ) {

/* The following code assumes that the corners with indices 0, 1, 2, 3
   are adjacent round the edge of the box. This is the case if the line 
   joining corners 0 and 1 does not cross the line joining corners 2 and 
   3 AND the line joining corners 1 and 2 does not cross the line joining 
   corners 3 and 0. If either of these conditions is not met swap the 
   corners around to correct it. First do box b. */
      if( Cross( bx[0], by[0], bx[1], by[1],
                 bx[2], by[2], bx[3], by[3] ) ) {
         x2 = bx[2];
         y2 = by[2];
         bx[2] = bx[1];
         by[2] = by[1];
         bx[1] = x2;
         by[1] = y2;

      } else if( Cross( bx[1], by[1], bx[2], by[2],
                        bx[3], by[3], bx[0], by[0] ) ) {
         x2 = bx[2];
         y2 = by[2];
         bx[2] = bx[3];
         by[2] = by[3];
         bx[3] = x2;
         by[3] = y2;
      }

/* Now do box c. */
      if( Cross( cx[0], cy[0], cx[1], cy[1],
                 cx[2], cy[2], cx[3], cy[3] ) ) {
         x2 = cx[2];
         y2 = cy[2];
         cx[2] = cx[1];
         cy[2] = cy[1];
         cx[1] = x2;
         cy[1] = y2;

      } else if( Cross( cx[1], cy[1], cx[2], cy[2],
                        cx[3], cy[3], cx[0], cy[0] ) ) {
         x2 = cx[2];
         y2 = cy[2];
         cx[2] = cx[3];
         cy[2] = cy[3];
         cx[3] = x2;
         cy[3] = y2;
      }

/* We now check each edge of box b to see if it overlaps any edge of box c. */
      for( j = 0; j < 4 && ret == 0; j++ ) { 

/* This edge of box b starts at the corner with index j. Get the index of the
   corner at which the edge ends. */
         jp = j + 1;
         if( jp == 4 ) jp = 0;

/* Check to see if this edge of box b crosses each edge of box c in turn. */
         for( i = 0; i < 4 && ret == 0; i++ ) { 
            ip = i + 1;
            if( ip == 4 ) ip = 0;

            ret = Cross( bx[j], by[j], bx[jp], by[jp],
                         cx[i], cy[i], cx[ip], cy[ip] );

         }
      }
   }

   return ret;
}

static int BoxText( AstPlot *this, int esc, const char *text, float x, float y, 
                    const char *just, float upx, float upy, float *xbn, float *ybn,
                    const char *method, const char *class ){
/*
*+
*  Name:
*     BoxText

*  Purpose:
*     Find the bounding box enclosing a text string, potentially including 
*     superscripts and subscripts.

*  Synopsis:
*     #include "plot.h"
*     int BoxText( AstPlot *this, int esc, const char *text, float x, float y,
*                  const char *just, float upx, float upy, float *xbn, 
*                  float *ybn, const char *method, const char *class )

*  Description:
*     This function returns the bounding box which would enclosed the 
*     supplied text, if it were to be drawn. The returned box optionally 
*     includes super-scripts and sub-scripts implied by any escape sequences 
*     in the string. 

*  Parameters:
*     this
*        The plot.
*     esc
*        Should escape sequences be interpreted? They will be printed
*        literally otherwise.
*     text 
*        Pointer to a null-terminated character string to be displayed.
*     x
*        The graphics X coordinate of the label's reference point.
*     y
*        The graphics Y coordinate of the label's reference point.
*     just
*        Pointer to a null-terminated character string identifying the
*        reference point for the text being drawn. The first character
*        in this string identifies the reference position in the "up"
*        direction and may be "B", "C" or "T" (for bottom, centre or
*        top). The second character identifies the side-to-side
*        reference position and may be "L", "C" or "R" (for left,
*        centre or right). The string is case-insensitive, and only
*        the first two characters are significant.
*     upx
*        The x component of the up-vector for the text. Positive values
*        always refer to displacements from left to right on the screen, 
*        even if the graphics x axis increases in the opposite sense.
*     upy
*        The y component of the up-vector for the text. Positive values
*        always refer to displacements from left to right on the screen, 
*        even if the graphics y axis increases in the opposite sense.
*     xbn
*        An array in which is returned the x coordinates at the corners
*        of the bounding box. If "esc" is non-zero, then these corners
*        are in the order; bottom-left, bottom-right, top-right, top-left.
*        If "esc" is zero, the order is not specified.
*     ybn
*        An array in which is returned the Y coordinates at the corners
*        of the bounding box (see xbn).
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     Zero for failure, one for success.

*  Notes:
*     -  The "B" option for the justification in the "up" direction refers
*     to the base-line on which the text is written. Some characters
*     ("y", "p", "g", etc) descend below this line. In addition, if the
*     supplied text string includes any escape sequences which produce 
*     sub-scripts, then these will also descend below the base-line. To
*     justify the bottom of the entire string (instead of just the
*     base-line), specify "D" instead of "B" in the justification string.
*     -  The "T" option for the justification in the "up" direction refers
*     to the top of the tallest characters. However, if the supplied text 
*     string includes any escape sequences which produce super-scripts, 
*     then these may extend above this line. To justify the top of the 
*     entire string (including super-scripts), specify "U" instead of "T" 
*     in the justification string.
*     -  See function GrText for details of the supported escape sequences.
*     -  Both "upx" and "upy" being zero causes an error.
*-
*/


/* Local Variables: */
   char lj[3];          /* Local version of justification string. */
   int bbclip;          /* GrText to return bounding box of "normal" text? */
   int ret;             /* Returned status */

/* Check the global error status. */
   if ( !astOK ) return 0;

/* Assume success. */
   ret = 1;

/* Fill in any missing parts of the justification string. */
   if( just ){
      if( just[ 0 ] == 'T' || just[ 0 ] == 'C' || just[ 0 ] == 'B' ||
          just[ 0 ] == 'U' || just[ 0 ] == 'D' ){
         lj[ 0 ] = just[ 0 ];
      } else {
         lj[ 0 ] = 'C';
      }

      if( just[ 1 ] == 'L' || just[ 1 ] == 'C' || just[ 1 ] == 'R' ){
         lj[ 1 ] = just[ 1 ];
      } else {
         lj[ 1 ] = 'C';
      }

   } else {
      lj[ 0 ] = 'C';
      lj[ 1 ] = 'C';
   }

   lj[2] = 0;

/* Only proceed if some text has been supplied. */
   if( text ) {

/* The basic drawing function GrText assumes BL justification. If this is
   the requested justification, just call GrText to get the bounds of the 
   text. */
      if( lj[0] == 'B' && lj[1] == 'L' ) {
         ret = GrText( this, esc, text, 0, 0, x, y, upx, upy, xbn, ybn, 
                       method, class );

/* Otherwise, we need to determine the correct BL position which will
   give the requested justfication. This involves calling GrText twice;
   once (with ink switched off) to find the size of the text string, and
   once to find the required bounding box. */
      } else {

/* The vertical justification options "U" and "D" refer to the top or bottom 
   of the whole bounding box (including sub-scripts, super-scripts, etc ). If
   either of these have been requested, convert them into the equivalent
   options refering to the "normal" text bounding box (i.e. "T" or "B"),
   and set a flag indicating that the bounding box returned by GrText
   should not be clipped. */
         if( lj[0] == 'U' ) {
            lj[0] = 'T';   
            bbclip = 0;
      
         } else if( lj[0] == 'D' ) {
            lj[0] = 'B';   
            bbclip = 0;
      
         } else {
            bbclip = 1;
         }

/* Get the bounding box enclosing the text produced if the bottom left corner 
   of the bounding box is placed at the supplied reference position. This box 
   is clipped to exclude super-scripts and sub-scripts if "bbclip" is
   non-zero. */
         ret = GrText( this, esc, text, 0, bbclip, x, y, upx, upy, xbn, ybn, 
                       method, class );
         if( ret ) {

/* Find the position of the bottom left corner of the bounding box which
   produces the required justification. */
            if( lj[0] == 'C' ) {
               x += 0.5*( xbn[0] - xbn[3] );
               y += 0.5*( ybn[0] - ybn[3] );
   
            } else if( lj[0] == 'T' ) {
               x += xbn[0] - xbn[3];
               y += ybn[0] - ybn[3];
            }
   
            if( lj[1] == 'C' ) {
               x += 0.5*( xbn[0] - xbn[1] );
               y += 0.5*( ybn[0] - ybn[1] );

            } else if( lj[1] == 'R' ) {
               x += xbn[0] - xbn[1];
               y += ybn[0] - ybn[1];
            }

/* Get the unclipped bounding box for the text putting the bottom left 
   corner of the normal text at the modified reference position. */
            ret = GrText( this, esc, text, 0, 0, x, y, upx, upy, xbn, ybn, 
                          method, class );
         }
      }
   }

/* Return the status. */
   return ret;

}

static void Bpoly( float x, float y, const char *method, const char *class ){
/*
*  Name:
*     Bpoly

*  Purpose:
*     Begin a new poly line.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void Bpoly( float x, float y, const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function draws any current poly line, and then starts a new one
*     at the supplied position.

*  Parameters:
*     x
*        The graphics x coordinate.
*     y
*        The graphics y coordinate.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*/

/* Check the global status. */
   if( !astOK ) return;

/* Draw any existing poly line. */
   Opoly( method, class );

/* Add the supplied point into the buffer. */
   Apoly( x, y, method, class );

}

static int CheckLabels( AstFrame *frame, int axis, double *ticks, int nticks, 
                        char **list ){
/*
*  Name:
*     CheckLabels

*  Purpose:
*     Create tick mark labels and check that adjacent labels are different.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int CheckLabels( AstFrame *frame, int axis, double *ticks, int nticks, 
*                      char **list )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function formats the supplied ticks mark values using the
*     astFormat method for the supplied Frame. It then checks all pairs
*     of adjacent labels. If a pair is found which are identical then the
*     memory holding the labels is released, and a value of zero is
*     returned. Otherwise, a value of one is returned, indicating that
*     adjacent labels are all different and the labels are returned.

*  Parameters:
*     frame
*        Pointer to the Frame.
*     axis
*        The zero-based index of the axis to which the tick marks refer.
*     ticks
*        Pointer to an array holding the tick mark values.
*     nticks
*        The number of tick marks supplied by parameter "ticks".
*     list 
*        Pointer to the start of an array of pointers. Each of the
*        elements in this array receives a pointer to a string holding a
*        formatted label. Each of these strings should be freed using
*        astFree when no longer needed.

*  Returned Value:
*     Zero if any pairs of identical adjacent labels were found. One
*     otherwise.

*  Notes:
*     -  No error is reported if a pair of identical adjacent labels is
*     found.
*     -  If an error has already occurred, or if this function should
*     fail for any reason, a value of zero is returned, and the array of
*     pointers identified by "list" is filled with NULL pointers.


*/

/* Local Variables: */
   const char *label;        /* Pointer to formatted tick value */
   int i;                    /* Tick index */
   int len;                  /* Number of characters in curent label */
   int ok;                   /* The returned flag */

/* Fill the supplied label list with NULL pointers. */
   for( i = 0; i < nticks; i++ ) list[ i ] = NULL;

/* Check the global status. */
   if( !astOK ) return 0;

/* Initialise the returned flag to indicate that all adjacent labels are
   different. */
   ok = 1;

/* Format the first tick mark value. */
   label = astFormat( frame, axis, ticks[ 0 ] );

/* Allocate memory holding a copy of the formatted value, and store a
   pointer to this copy in the list of labels. */
   if( label ){
      len = strlen( label ) + 1;
      list[ 0 ] = (char *) astStore( NULL, (void *) label, len );
   } else {
      ok = 0;
   }

/* Format each of the tick mark values in this batch. */
   for( i = 1; i < nticks && astOK && ok; i++ ){
      label = astFormat( frame, axis, ticks[ i ] );
      if( label ){

/* Compare this label with the previous label. If they are identical clear
   the returned flag. */
         if( !strcmp( label, list[ i - 1 ] ) ) {
            ok = 0;

/* Allocate memory holding a copy of the label, and store a
   pointer to this copy in the list of labels. */
         } else {
            list[ i ] = (char *) astStore( NULL, (void *) label, strlen( label ) + 1 );
         }

      } else {
         ok = 0;
      }

   }

/* If two adjacent labels were identical, or an error occurred, release the 
   memory used to store the labels. */
   if( !ok || !astOK ){
      for( i = 0; i < nticks; i++ ){
         if( list[ i ] ) list[ i ] = (char *) astFree( (void *) list[ i ] );
      }
   }

/* Ensure a value of zero is returned if an error has occurred. */
   if( !astOK ) ok = 0;

/* Return the answer. */
   return ok;

}

static char **CheckLabels2( AstFrame *frame, int axis, double *ticks, int nticks, 
                            char **old_list ){
/*
*  Name:
*     CheckLabels2

*  Purpose:
*     Check that labels cannot be shortened.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     char **CheckLabels2( AstFrame *frame, int axis, double *ticks, 
*                          int nticks, char **old_list )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function formats the supplied ticks mark values using the
*     astFormat method for the supplied Frame. It then compares the labels
*     with the corresponding labels supplied in "old_list". If all of the
*     new labels are shorter than, or equal in length to, the old labels, 
*     then memory is allocated to hold the new (shorter) labels, and a
*     pointer to this memory is returned. If any new label is longer than 
*     the corresponding old label, then a NULL pointer is returned.

*  Parameters:
*     frame
*        Pointer to the Frame.
*     axis
*        The zero-based index of the axis to which the tick marks refer.
*     ticks
*        Pointer to an array holding the tick mark values.
*     nticks
*        The number of tick marks supplied by parameter "ticks".
*     old_list 
*        Pointer to the start of an array of pointers. Each of the
*        elements in this array should hold a pointer to a string holding a
*        formatted label. 

*  Returned Value:
*     A pointer to an array of pointers. Each of these pointers points to
*     a text string holding a shortened label. If a complete set of 
*     shortened labels could not be found (or if an error occurs), a NULL
*     pointer is returned.

*  Notes:
*     -  The memory holding the returned shortened labels should be
*     freed by cthe caller, together with the memory holding the pointers to
*     the labels.
*     -  No error is reported if a pair of identical adjacent labels is
*     found.
*     -  If an error has already occurred, or if this function should
*     fail for any reason, a value of NULL is returned.

*/

/* Local Variables: */
   char **list;              /* The returned pointer */
   const char *label;        /* Pointer to formatted tick value */
   int i;                    /* Tick index */
   int llen;                 /* Number of characters in curent label */
   int ok;                   /* Are the old labels OK to be used? */

/* Check the global status. */
   if( !astOK ) return NULL;

/* Allocate memory to hold the pointers to the new labels. */
   list = (char **) astMalloc( sizeof( char * )*(size_t) nticks );
   if( list ) {

/* Fill this array with NULLs for safety. */
      for( i = 0; i < nticks; i++ ) list[ i ] = NULL;

/* Initialise a flag to indicate that all the new labels are
   shorter than the old labels. */
      ok = 0;

/* Format each of the tick mark values in this batch. */
      for( i = 0; i < nticks && astOK; i++ ){
         label = astFormat( frame, axis, ticks[ i ] );
         if( label ){

/* Get the length of the new label. */
            llen = strlen( label );

/* Compare this label with the corresponding old label. If the new one is 
   longer than the old one, set the flag and leave the loop. */
            if( llen > strlen( old_list[ i ] ) ) {
               ok = 1;
               break;
            }

/* Store the new label. */
            list[ i ] = (char *) astStore( NULL, (void *) label, 
                                           (size_t) (llen + 1) );
         }
      }

/* If the old labels are to be used, or an error occurred, release the memory 
   used to store the new labels. */
      if( ok || !astOK ){
         for( i = 0; i < nticks; i++ ){
            if( list[ i ] ) list[ i ] = (char *) astFree( (void *) list[ i ] );
         }
         list = (char **) astFree( (void *) list );
      }

   }

/* Return the answer. */
   return list;

}

static int ChrLen( const char *string ){
/*
*  Name:
*     ChrLen

*  Purpose:
*     Return the length of a string excluding any trailing white space.

*  Type:
*     Private function.

*  Synopsis:
*     int ChrLen( const char *string )

*  Class Membership:
*     Plot

*  Description:
*     This function returns the length of a string excluding any trailing
*     white space.

*  Parameters:
*     string
*        Pointer to the string.

*  Returned Value:
*     The length of a string excluding any trailing white space.

*  Notes:
*     -  A value of zero is returned if a NULL pointer is supplied, or if an
*     error has already occurred.

*/

/* Local Variables: */
   const char *c;      /* Pointer to the next character to check */
   int ret;            /* The returned string length */

/* Check the global status. */
   if( !astOK ) return 0;

/* Initialise the returned string length. */
   ret = 0;

/* Check a string has been supplied. */
   if( string ){

/* Check each character in turn, starting with the last one. */
      ret = strlen( string );
      c = string + ret - 1;
      while( ret ){
         if( !isspace( (int) *c ) ) break;
         c--;
         ret--;
      }
   }

/* Return the answer. */
   return ret;

}

static CurveData **CleanCdata( CurveData **cdata ){
/*
*  Name:
*     CleanCdata

*  Purpose:
*     Release the structures holding curve break information.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     CurveData **CleanCdata( CurveData **cdata )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function releases the memory used to hold the curve break 
*     information returned by function DrawGrid, and returns a NULL pointer.

*  Parameters:
*     cdata
*        Pointer to the information to be freed.

*  Returned Value:
*     A NULL pointer.

*  Notes:
*     -  This function attempts to execute even if an error has already
*     occurred.

*/

/* Return if a NULL pointer has been supplied. */
   if( !cdata ) return NULL;

/* Release each of the two structures in turn (if they exist). */
   (void) astFree( (void *) cdata[ 0 ] );
   (void) astFree( (void *) cdata[ 1 ] );

/* Release the memory used to hold the two CurveData pointers. */
   (void) astFree( (void *) cdata );

/* Return. */
   return NULL;

}

static TickInfo **CleanGrid( TickInfo **grid ){
/*
*  Name:
*     CleanGrid

*  Purpose:
*     Release the structures holding grid information.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     TickInfo **CleanGrid( TickInfo **grid )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function releases the memory used to hold the grid information
*     returned by function GridLines, and returns a NULL pointer.

*  Parameters:
*     grid
*        Pointer to the information to be freed.

*  Returned Value:
*     A NULL pointer.

*  Notes:
*     -  This function attempts to execute even if an error has already
*     occurred.

*/

/* Local Variables: */
   TickInfo *info;             /* Pointer to TickInfo structure being freed */
   int i;                      /* Axis index */
   int j;                      /* Tick mark index */

/* Return if a NULL pointer has been supplied. */
   if( !grid ) return NULL;

/* Release each of the TickInfo structures in turn (if they exist). */
   for( i = 0; i < 2; i++ ){
      if( ( info = grid[ i ] ) ){

/* Release the memory holding major tick mark values. */
         (void) astFree( (void *) info->ticks );

/* Release the memory holding curve section starting positions. */
         (void) astFree( (void *) info->start );

/* Release the memory holding curve section lengths. */
         (void) astFree( (void *) info->length );

/* If there are any tick mark labels in the structure... */
         if( info->labels ){

/* Release the memory holding each tick mark label. */
            for( j = 0; j < info->nmajor; j++ ){
               (void) astFree( (void *) info->labels[ j ] );
            }

/* Release the memory holding the pointers to the tick mark labels. */
            (void) astFree( (void *) info->labels );

/* Release the memory holding the format specification string. */
            (void) astFree( (void *) info->fmt );

         }

/* Release the TickInfo structure. */
         (void) astFree( (void *) info );
      }
   }

/* Release the memory used to hold the two TickInfo pointers. */
   (void) astFree( (void *) grid );

/* Return. */
   return NULL;

}

static void ClearAttrib( AstObject *this_object, const char *attrib ) {
/*
*  Name:
*     ClearAttrib

*  Purpose:
*     Clear an attribute value for a Plot.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void ClearAttrib( AstObject *this, const char *attrib )

*  Class Membership:
*     Plot member function (over-rides the astClearAttrib protected
*     method inherited from the FrameSet class).

*  Description:
*     This function clears the value of a specified attribute for a
*     Plot, so that the default value will subsequently be used.

*  Parameters:
*     this
*        Pointer to the Plot.
*     attrib
*        Pointer to a null terminated string specifying the attribute
*        name.  This should be in lower case with no surrounding white
*        space.
*/

/* Local Variables: */
   AstPlot *this;                /* Pointer to the Plot structure */
   char label[21];               /* Graphics item label */
   int axis;                     /* Axis number */
   int id;                       /* Plot object id */
   int len;                      /* Length of attrib string */
   int nc;                       /* No. characters read by sscanf */

/* Check the global error status. */
   if ( !astOK ) return;

/* Obtain a pointer to the Plot structure. */
   this = (AstPlot *) this_object;

/* Obtain the length of the "attrib" string. */
   len = strlen( attrib );

/* Check the attribute name and clear the appropriate attribute. */

/* Edge(axis). */
/* ------------ */
   if ( nc = 0,
               ( 1 == sscanf( attrib, "edge(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearEdge( this, axis - 1 );

/* Grid. */
/* ----- */
   } else if ( !strcmp( attrib, "grid" ) ) {
      astClearGrid( this );

/* LabelUp */
/* ------- */
   } else if ( !strcmp( attrib, "labelup" ) ) {
      astClearLabelUp( this, 0 );
      astClearLabelUp( this, 1 );

/* LabelUp(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "labelup(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearLabelUp( this, axis - 1 );

/* NumLab. */
/* ---------- */
   } else if ( !strcmp( attrib, "numlab" ) ) {
      astClearNumLab( this, 0 );
      astClearNumLab( this, 1 );

/* NumLab(axis). */
/* ---------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "numlab(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearNumLab( this, axis - 1 );

/* MinTick. */
/* ---------- */
   } else if ( !strcmp( attrib, "mintick" ) ) {
      astClearMinTick( this, 0 );
      astClearMinTick( this, 1 );

/* MinTick(axis). */
/* ---------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "mintick(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearMinTick( this, axis - 1 );

/* TextLab. */
/* ---------- */
   } else if ( !strcmp( attrib, "textlab" ) ) {
      astClearTextLab( this, 0 );
      astClearTextLab( this, 1 );

/* TextLab(axis). */
/* --------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "textlab(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearTextLab( this, axis - 1 );

/* LabelUnits. */
/* --------- */
   } else if ( !strcmp( attrib, "labelunits" ) ) {
      astClearLabelUnits( this, 0 );
      astClearLabelUnits( this, 1 );

/* LabelUnits(axis). */
/* --------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "labelunits(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearLabelUnits( this, axis - 1 );

/* Style. */
/* ------ */
   } else if ( !strcmp( attrib, "style" ) ) {
      for( id = 0; id < AST__NPID; id++ ) astClearStyle( this, id );

/* Style(label). */
/* --------------*/
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "style(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      astClearStyle( this, FullForm( GrfLabels, label, attrib, "astClear", astGetClass( this ) ) );

/* Font. */
/* ----- */
   } else if ( !strcmp( attrib, "font" ) ) {
      for( id = 0; id < AST__NPID; id++ ) astClearFont( this, id );

/* Font(label). */
/* -------------*/
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "font(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      astClearFont( this, FullForm( GrfLabels, label, attrib, "astClear", astGetClass( this ) ) );

/* Colour. */
/* ------- */
   } else if ( !strcmp( attrib, "colour" ) ) {
      for( id = 0; id < AST__NPID; id++ ) astClearColour( this, id );

/* Colour(label). */
/* ---------------*/
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "colour(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      astClearColour( this, FullForm( GrfLabels, label, attrib, "astClear", astGetClass( this ) ) );

/* Color. */
/* ------ */
   } else if ( !strcmp( attrib, "color" ) ) {
      for( id = 0; id < AST__NPID; id++ ) astClearColour( this, id );

/* Color(label). */
/* --------------*/
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "color(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      astClearColour( this, FullForm( GrfLabels, label, attrib, "astClear", astGetClass( this ) ) );

/* Width. */
/* ------ */
   } else if ( !strcmp( attrib, "width" ) ) {
      for( id = 0; id < AST__NPID; id++ ) astClearWidth( this, id );

/* Width(label). */
/* --------------*/
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "width(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      astClearWidth( this, FullForm( GrfLabels, label, attrib, "astClear", astGetClass( this ) ) );

/* Size. */
/* ----- */
   } else if ( !strcmp( attrib, "size" ) ) {
      for( id = 0; id < AST__NPID; id++ ) astClearSize( this, id );

/* Size(label). */
/* -------------*/
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "size(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      astClearSize( this, FullForm( GrfLabels, label, attrib, "astClear", astGetClass( this ) ) );

/* LabelAt(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "labelat(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearLabelAt( this, axis - 1 );

/* Centre(axis). */
/* ------------ */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "centre(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearCentre( this, axis - 1 );

/* Gap. */
/* ---- */
   } else if ( !strcmp( attrib, "gap" ) ) {
      astClearGap( this, 0 );
      astClearGap( this, 1 );

/* Gap(axis). */
/* ---------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "gap(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearGap( this, axis - 1 );

/* NumLabGap. */
/* ---------- */
   } else if ( !strcmp( attrib, "numlabgap" ) ) {
      astClearNumLabGap( this, 0 );
      astClearNumLabGap( this, 1 );

/* NumLabGap(axis). */
/* ---------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "numlabgap(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearNumLabGap( this, axis - 1 );

/* TextLabGap. */
/* ----------- */
   } else if ( !strcmp( attrib, "textlabgap" ) ) {
      astClearTextLabGap( this, 0 );
      astClearTextLabGap( this, 1 );

/* TextLabGap(axis). */
/* ----------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "textlabgap(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearTextLabGap( this, axis - 1 );

/* TitleGap. */
/* --------- */
   } else if ( !strcmp( attrib, "titlegap" ) ) {
      astClearTitleGap( this );

/* MajTickLen. */
/* ----------- */
   } else if ( !strcmp( attrib, "majticklen" ) ) {
      astClearMajTickLen( this, 0 );
      astClearMajTickLen( this, 1 );

/* MajTickLen(axis). */
/* ----------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "majticklen(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearMajTickLen( this, axis - 1 );

/* MinTickLen. */
/* ----------- */
   } else if ( !strcmp( attrib, "minticklen" ) ) {
      astClearMinTickLen( this, 0 );
      astClearMinTickLen( this, 1 );

/* MinTickLen(axis). */
/* ----------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "minticklen(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      astClearMinTickLen( this, axis - 1 );

/* Labelling. */
/* -------- */
   } else if ( !strcmp( attrib, "labelling" ) ) {
      astClearLabelling( this );

/* TickAll. */
/* -------- */
   } else if ( !strcmp( attrib, "tickall" ) ) {
      astClearTickAll( this );

/* Border. */
/* ------- */
   } else if ( !strcmp( attrib, "border" ) ) {
      astClearBorder( this );

/* ClipOp. */
/* ------- */
   } else if ( !strcmp( attrib, "clipop" ) ) {
      astClearClipOp( this );

/* DrawTitle. */
/* ---------- */
   } else if ( !strcmp( attrib, "drawtitle" ) ) {
      astClearDrawTitle( this );

/* DrawAxes. */
/* --------- */
   } else if ( !strcmp( attrib, "drawaxes" ) ) {
      astClearDrawAxes( this );

/* Escape. */
/* ------- */
   } else if ( !strcmp( attrib, "escape" ) ) {
      astClearEscape( this );

/* Tol. */
/* ---- */
   } else if ( !strcmp( attrib, "tol" ) ) {
      astClearTol( this );

/* If the attribute is still not recognised, pass it on to the parent
   method for further interpretation. */
   } else {
      (*parent_clearattrib)( this_object, attrib );
   }
}

static void Clip( AstPlot *this, int iframe, const double lbnd[], 
                  const double ubnd[] ){
/*
*++
*  Name:
c     astClip
f     AST_CLIP

*  Purpose:
*     Set up or remove clipping for a Plot.

*  Type:
*     Public virtual function.

*  Synopsis:
c     #include "plot.h"
c     void astClip( AstPlot *this, int iframe, const double lbnd[], 
c                   const double ubnd[] )
f     CALL AST_CLIP( THIS, IFRAME, LBND, UBND, STATUS )

*  Class Membership:
*     Plot method.

*  Description:
c     This function defines regions of a Plot which are to be clipped.
f     This routine defines regions of a Plot which are to be clipped.
*     Any subsequent graphical output created using the Plot will then
*     be visible only within the unclipped regions of the plotting
*     area.

*  Parameters:
c     this
f     THIS = INTEGER (Given)
*        Pointer to the Plot.
c     iframe
f     IFRAME = INTEGER (Given)
*        The index of the Frame within the Plot to which the clipping
c        limits supplied in "lbnd" and "ubnd" (below) refer. Clipping
f        limits supplied in LBND and UBND (below) refer. Clipping
*        may be applied to any of the coordinate systems associated
*        with a Plot (as defined by the Frames it contains), so this
*        index may take any value from 1 to the number of Frames in
*        the Plot (Nframe attribute). In addition, the values
*        AST__BASE and AST__CURRENT may be used to specify the base
*        and current Frames respectively.
*
*        For example, a value of AST__CURRENT causes clipping to be
*        performed in physical coordinates, while a value of AST__BASE
*        would clip in graphical coordinates. Clipping may also be
*        removed completely by giving a value of AST__NOFRAME. In this
*        case any clipping bounds supplied (below) are ignored.
c     lbnd
f     LBND( * ) = DOUBLE PRECISION (Given)
*        An array with one element for each axis of the clipping Frame
c        (identified by the index "iframe"). This should contain the
f        (identified by the index IFRAME). This should contain the
*        lower bound, on each axis, of the region which is to remain
*        visible (unclipped).
c     ubnd
f     UBND( * ) = DOUBLE PRECISION (Given)
*        An array with one element for each axis of the clipping Frame
c        (identified by the index "iframe"). This should contain the
f        (identified by the index IFRAME). This should contain the
*        upper bound, on each axis, of the region which is to remain
*        visible (unclipped).
f     STATUS = INTEGER (Given and Returned)
f        The global status.

*  Notes:
c     - Only one clipping Frame may be active at a time. This function
f     - Only one clipping Frame may be active at a time. This routine
*     will deactivate any previously-established clipping Frame before
*     setting up new clipping limits.
c     - The clipping produced by this function is in addition to that
f     - The clipping produced by this routine is in addition to that
*     which always occurs at the edges of the plotting area
c     established when the Plot is created (see astPlot). The
f     established when the Plot is created (see AST_PLOT). The
*     underlying graphics system may also impose further clipping.
*     - When testing a graphical position for clipping, it is first
*     transformed into the clipping Frame. The resulting coordinate on
*     each axis is then checked against the clipping limits (given by
c     "lbnd" and "ubnd"). By default, a position is clipped if any
f     LBND and UBND). By default, a position is clipped if any
*     coordinate lies outside these limits. However, if a non-zero
*     value is assigned to the Plot's ClipOp attribute, then a
*     position is only clipped if the coordinates on all axes lie
*     outside their clipping limits.
*     - If the lower clipping limit exceeds the upper limit for any
*     axis, then the sense of clipping for that axis is reversed (so
*     that coordinate values lying between the limits are clipped
*     instead of those lying outside the limits). To produce a "hole"
*     in a coordinate space (that is, an internal region where nothing
*     is plotted), you should supply all the bounds in reversed order,
*     and set the ClipOp attribute for the Plot to a non-zero value.
*     - Either clipping limit may be set to the value AST__BAD, which
*     is equivalent to setting it to infinity (or minus infinity for a
*     lower bound) so that it is not used.
*     - If a graphical position results in any bad coordinate values
*     (AST__BAD) when transformed into the clipping Frame, then it is
*     treated (for the purposes of producing graphical output) as if
*     it were clipped.
*     - When a Plot is used as a Mapping to transform points
c     (e.g. using astTran2), any clipped output points are assigned
f     (e.g. using AST_TRAN2), any clipped output points are assigned
*     coordinate values of AST__BAD.
*     - An error results if the base Frame of the Plot is not
*     2-dimensional.
*--
*/

/* Local Variables: */
   AstFrame *fr;           /* Pointer to the clipping Frame */
   AstFrameSet *fset;      /* Pointer to the Plot's FrameSet */
   int i;                  /* Axis index */
   int ifrm;               /* The validated frame index */ 
   int naxes;              /* No. of axes in the base Frame */

/* Check the global error status. */
   if ( !astOK ) return;

/* Get a pointer to the FrameSet at the start of the Plot. */
   fset = (AstFrameSet *) this;

/* Check the base Frame of the Plot is 2-D. */
   naxes = astGetNin( fset );
   if( naxes != 2 && astOK ){
      astError( AST__NAXIN, "astClip(%s): Number of axes (%d) in the "
                "base Frame of the supplied %s is invalid - this number "
                "should be 2.", astGetClass( this ), naxes,  
                astGetClass( this ) );
   } 

/* If clipping is to be switched on, check the supplied frame index and 
   bounds. */
   if( iframe != AST__NOFRAME && astOK ) {

/* Report an error if either of the bounds pointers is NULL.*/
      if( !lbnd ){
         astError( AST__CLPAX, "astClip(%s): A NULL pointer was "
                   "supplied for the array holding the lower bounds of "
                   "the clipping volume.", astGetClass( this ) );
      } else if( !ubnd ){
         astError( AST__CLPAX, "astClip(%s): A NULL pointer was "
                   "supplied for the array holding the upper bounds of "
                   "the clipping volume.", astGetClass( this ) );
      }

/* Validate the clipping frame index. */
      ifrm = astValidateFrameIndex( fset, iframe, "astClip" );

/* Get the number of axes in the clipping frame. */
      fr = astGetFrame( this, ifrm );
      naxes = astGetNaxes( fr );
      fr = astAnnul( fr );

   }
      
/* Leave the current clipping information unchanged if an error has 
   occurred. */
   if( astOK ){

/* Remove all clipping information from the Plot. */
      this->clip_lbnd = (double *) astFree( (void *) this->clip_lbnd );
      this->clip_ubnd = (double *) astFree( (void *) this->clip_ubnd );
      this->clip_frame = AST__NOFRAME;
      this->clip_axes = 0;

/* If bounds have been supplied, set up new clipping information. */
      if( iframe != AST__NOFRAME ){

/* Store the information. */
         this->clip_frame = ifrm;
         this->clip_lbnd = astStore( NULL, lbnd, sizeof(double)*(size_t)naxes );
         this->clip_ubnd = astStore( NULL, ubnd, sizeof(double)*(size_t)naxes );
         this->clip_axes = naxes;

/* If an error has occurred, remove all clipping information. */
         if( !astOK ){
            this->clip_lbnd = (double *) astFree( (void *) this->clip_lbnd );
            this->clip_ubnd = (double *) astFree( (void *) this->clip_ubnd );
            this->clip_frame = AST__NOFRAME;
            this->clip_axes = 0;

/* Otherwise, replace any bounds of AST__BAD with suitable default
   values. */
         } else {
           for( i = 0; i < naxes; i++ ){
              if( this->clip_lbnd[ i ] == AST__BAD ) this->clip_lbnd[ i ] = -DBL_MAX;
              if( this->clip_ubnd[ i ] == AST__BAD ) this->clip_ubnd[ i ] = DBL_MAX;
           }

         }

      }

   }
   
/* Return. */
   return;

}

static int Compared( const void *elem1, const void *elem2 ){
/*
*  Name:
*     Compared

*  Purpose:
*     Compare two "double" values.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int Compared( const void *elem1, const void *elem2 )

*  Class Membership:
*     Plot method.

*  Description:
*     This function compares the two "double" values to which pointers
*     are supplied, and returns an integer indicating which is larger,
*     checking for AST__BAD values.  It is intended for use with the C 
*     Run-Time-Library sorting function "qsort". 

*  Parameters:
*     elem1
*        Pointer to the first "double".
*     elem2
*        Pointer to the second "double".

*  Returned Value:
*     Zero is returned if the values are equal. If the first is larger
*     than the second then +1 is returned. Otherwise, -1 is returned.

*  Notes:
*     -  Values of AST__BAD are considered to be larger than any other
*     value (other than another value of AST__BAD).
*     -  If both values are AST__BAD, then zero is returned.
*     -  This function executes even if an error has occurred.

*/

/* Local Variables: */
   double *delem1;    /* Pointer to the first "double" value */
   double *delem2;    /* Pointer to the second "double" value */
   int ret;           /* The returned value */
   
/* Get pointers to the two "double" values. */
   delem1 = (double *) elem1;
   delem2 = (double *) elem2;

/* Check the values for equality (including both values being AST__BAD). */
   if( *delem1 == *delem2 ){
      ret = 0;

/* If the first is bad, then it is considered to be larger than the
   second. */
   } else if( *delem1 == AST__BAD ){
      ret = 1;

/* If the second is bad, then it is considered to be larger than the
   first. */
   } else if( *delem2 == AST__BAD ){
      ret = -1;

/* If the first is larger than the second, return 1. */
   } else if( *delem1 > *delem2 ){
      ret = 1;

/* If the first is smaller than the second, return -1. */
   } else {
      ret = -1;

   }

/* Return the answer. */
   return ret;

}

static int Compare_LL( const void *elem1, const void *elem2 ){
/*
*  Name:
*     Compare_LL

*  Purpose:
*     Compare two LabelList structures as used by function PlotLabels.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int Compare_LL( const void *elem1, const void *elem2 )

*  Class Membership:
*     Plot method.

*  Description:
*     This function compares two "LabelList" structures as used by function
*     PlotLabels, and returns an integer indicating which has a larger 
*     "index" value. This function is intended to be used with the C 
*     Run-Time-Library sorting function "qsort". 

*  Parameters:
*     elem1
*        Pointer to the first LabelList.
*     elem2
*        Pointer to the second LabelList. 

*  Returned Value:
*     Zero is returned if the values are equal. If the first is larger
*     than the second then +1 is returned. Otherwise, -1 is returned.

*  Notes:
*     -  This function executes even if an error has occurred.

*/

/* Local Variables: */
   LabelList *ll1;           /* Pointer to the first LabelList */
   LabelList *ll2;           /* Pointer to the second LabelList */
   int ret;                  /* The returned value */
   
/* Get pointers to the two LabelList structures. */
   ll1 = (LabelList *) elem1;
   ll2 = (LabelList *) elem2;

/* Compare the indices for the two label's. */
   if( ll1->index < ll2->index ){
      ret = -1;

   } else if( ll1->index > ll2->index ){
      ret = 1;

   } else {
      ret = 0;
   }

/* Return the answer. */
   return ret;

}

static int CountGood( int n, double *data ){
/*
*  Name:
*     CountGood

*  Purpose:
*     Coount the number of non-bad values in an array.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int CountGood( int n, double *data )

*  Class Membership:
*     Plot method.

*  Description:
*     This function returns the number of elements in the supplied array
*     which do not have the value AST__BAD.

*  Parameters:
*     n
*        The total number of elements in the array.
*     data
*        Pointer to the start of the array.

*  Returned Value:
*     The number of good points in the array.

*  Notes:
*     -  A value of zero is returned if an error has already occurred.

*/

/* Local Variables: */
   int i;
   int ngood;
   double *value;

/* Check global status. */
   if( !astOK ) return 0;

/* Initialise a pointer to the next array element, and the number of 
   good elements found so far. */
   value = data;
   ngood = 0;

/* Check each element. */
   for( i = 0; i < n; i++ ){
      if( *(value++) != AST__BAD ) ngood++;
   }

/* Return the answer. */
   return ngood;

}

static int Cross( float ax, float ay, float bx, float by, 
                  float cx, float cy, float dx, float dy ){
/*
*  Name:
*     Cross

*  Purpose:
*     See if two line segments intersect.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int Cross( float ax, float ay, float bx, float by, 
*                float cx, float cy, float dx, float dy )

*  Class Membership:
*     Plot method.

*  Description:
*     This function sees if the line segment (A,B) intersects the line
*     segment (C,D).

*  Parameters:
*     ax, ay
*        The coordinates of A.
*     bx, by
*        The coordinates of B.
*     cx, cy
*        The coordinates of C.
*     dx, dy
*        The coordinates of D.

*  Returned Value:
*     Zero if the line segments do not cross or if an error has already
*     occurred, and 1 if they do.

*/

/* Local Variables: */
   int ret;
   float m1, m2, denom, num, t1, t2;

/* Check the inherited status. */
   if( !astOK ) return 0;

/* Get the fraction of the distance from A to B at which the line AB 
   intersects the line CD. */
   m1 = dx - cx;
   m2 = dy - cy;
   denom = (bx - ax)*m2 - (by-ay)*m1;
   num = (ay - cy)*m1 - (ax - cx)*m2;

   if( denom != 0.0 ) {
      t1 = num / denom;

/* If the the intersection occurs within the segment of the line between A
   and B... */
      if( t1 >= 0.0 && t1 <= 1.0 ){

/* ... then get the fraction of the distance from C to D at which the
   line CD intersects the line AB. */
         m1 = bx - ax;
         m2 = by - ay;
         denom = (dx - cx)*m2 - (dy-cy)*m1;
         num = (cy - ay)*m1 - (cx - ax)*m2;

         if( denom != 0.0 ) {
            t2 = num / denom;
   
/* If the the intersection occurs within the segment of the line between C
   and D then the line segments intersect. */
            if( t2 >= 0.0 && t2 <= 1.0 ){
               ret = 1;
            } else {
               ret = 0;
            }   

/* If the two lines are parallel, then they do not intersect. */
         } else {
            ret = 0;
         }      

      } else {
         ret = 0;
      }

   } else {
      ret = 0;

   }      

   return ret;
}

static void Crv( double *d, double *x, double *y, const char *method, 
                 const char *class ){
/*
*  Name:
*     Crv

*  Purpose:
*     Draw a curve.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void Crv( double *d, double *x, double *y, const char *method, 
*               const char *class  )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function draws a curve parameterised by the distance from some
*     starting point. The function pointed to by the external variable 
*     Crv_map is used to transform distances along the curve into graphics
*     coordinates (X,Y). The supplied function parameters defined the 
*     section of the curve to be drawn.
*
*     The algorithm used needs no knowledge about the nature of the mapping 
*     performed by Crv_map, and can handle discontinuities in the curve. It 
*     first of all determines if any of the segments of the curve can be 
*     adequately represented by simply drawing a straight line through the 
*     supplied end points. This decision is based on several requirements such 
*     as keeping the angle between adjacent sections low and both ends being
*     defined (i.e. X and Y not equal to AST__BAD). Any segments of the curve 
*     which satisfy the requirements are draw as straight lines. If any of 
*     the supplied curve segments cannot be drawn in this way, then they are 
*     split up into a set of evenly-spaced sub-segments and the graphics 
*     coordinates at the ends of these sub-segments are found using Crv_map. 
*     This function is then called recursively to draw the sub-segments. This
*     recursion is limited in depth by the requirement that all the 
*     sub-segments must be longer than a specified lower limit. If this is not 
*     the case, then the curve is assumed to be dis-continuous and and the 
*     sub-segments are ignored.

*  Parameters:
*     d
*        Pointer to an array of CRV_NPNT values giving the distance along
*        the curve from the starting point to each of CRV_NPNT points. They 
*        should increase monotonically, and should be in whatever units are
*        used by the function pointed to by Crv_map. The curve is drawn from
*        d[0] to d[CRV_NPNT].
*     x
*        Pointer to an array of CRV_NPNT values giving the graphics X 
*        coordinate for the positions supplied in the array pointed to by 
*        parameter "d". 
*     y
*        Pointer to an array of CRV_NPNT values giving the graphics Y
*        coordinate for the positions supplied in the array pointed to by 
*        parameter "d". 
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  External Variables:
*     Crv_nent = int (Read/Write)
*        The number of recursive entries which have been made into
*        this function. This should be set to zero before entering 
*        this function for the first time.
*     Crv_ux0 = double (Read/Write)
*        The X component in graphics coordinates of the unit vector 
*        along the previous segment of the curve. This should be set
*        to AST__BAD initially to indicate that the previous section
*        is not defined.
*     Crv_uy0 = double (Read/Write)
*        The Y component of the unit vector along the previous segment.
*     Crv_limit = double (Read)
*        The square of the maximum acceptable residual between the 
*        drawn curve and the true curve, in graphics coordinates.
*     Crv_map = void (*)( int n, double *dd, double *xx, double *yy,
*                         const char *method, const char *class ) (Read)
*        A pointer to a function which can be called to map "n" distances 
*        along the curve (supplied in "dd") into graphics coordinates 
*        (stored in "xx" and "yy"). See function "Map1" as an example.

*/

/* Local Variables: */
   double *dd;            /* Pointer to array holding sub-segment distances */
   double *pd;            /* Pointer to next sub-segment distance */
   double *px;            /* Pointer to next sub-segment x coord. */
   double *py;            /* Pointer to next sub-segment y coord. */
   double *xx;            /* Pointer to array holding sub-segment x coord.s */
   double *yy;            /* Pointer to array holding sub-segment x coord.s */
   double dl2[ CRV_NSEG ];/* Squred segment lengths */
   double dx[ CRV_NSEG ]; /* X increment along each segment */
   double dy[ CRV_NSEG ]; /* Y increment along each segment */
   int i;                 /* Segment index */
   int seg_ok[ CRV_NSEG ];/* Flags indicating which segments can be drawn */
   int subdivide;         /* Flag indicating if segments can be subdivided */

   static double *pdl2;   /* Pointer to next squared segment length */
   static double *pdx;    /* Pointer to next segment X increment */
   static double *pdy;    /* Pointer to next segment Y increment */
   static double cosang;  /* Cosine of angle between adjacent segments */
   static double d0;      /* Distance to start of first sub-segment */
   static double delta;   /* Distance between adjacent sub-segments */
   static double dl2_min; /* Minimum squred segment length */
   static double dl;      /* Segment length in graphics coordinates */
   static double last_x;  /* Graphics X at the end of the previous segment */
   static double last_y;  /* Graphics Y at the end of the previous segment */
   static double limit2;  /* Shortest acceptable squared segment length */
   static double t1;      /* Increment in X */
   static double t2;      /* Increment in Y */
   static double t3;      /* Squared segment length */
   static double vx;      /* X component of unit vector for current segment */
   static double vxl;     /* X component of unit vector for previous segment */
   static double vy;      /* Y component of unit vector for current segment */
   static double vyl;     /* Y component of unit vector for previous segment */
   static int all_bad;    /* Are all supplied positions bad or clipped?  */
   static int el;         /* Total sub-segment count */
   static int j;          /* Sub-segment index */
   static int last_ok;    /* Was the previous position defined? */
   static int nel;        /* Total number of sub-segments */
   static int nseg;       /* Number of segments being sub-divided */
   static int *seg0;      /* Pointer to current segment OK flag */
   static int *segm;      /* Pointer to previous segment OK flag */
   static int *segp;      /* Pointer to next segment OK flag */

/* Check inherited status */
   if( !astOK ) return;                 

/* If this is the first entry, set up the minimum length for a 
   sub-segment in graphics coordinates. If any segment is less than
   this minimum length, then recursion will stop and the curve will
   be assumed to be dis-continuous. */
   if( !Crv_nent ) limit2 = 2.0*Crv_limit/(CRV_NSEG*CRV_NSEG);

/* Increment the number of entries into this function. */
   Crv_nent++;

/* ======================================================================
   The first section of this function sets up some arrays holding 
   information which will be used later on. It looks at each of the segments 
   joing adjacent tabulated points, and finds and stores the increments in 
   X and Y along each segment, and the square of the segment length. It 
   also checks to see if the tabulated points are all bad, or if they are
   all good. It also finds the lowest squared segment length.
   ======================================================================*/

/* Look at the first tabulated point. If it is good, set a flag to indicate 
   that it can be used, store it as "the previous position" (i.e. the start of 
   the current segment). Also set a flag ("all_bad") to indicate if all
   points looked at so far have been bad, or outside the plotting area. */
   if( *x != AST__BAD && *y != AST__BAD ){
      last_ok = 1;
      last_x = *x;
      last_y = *y;
      all_bad = ( *x < Crv_xlo || *x > Crv_xhi || 
                  *y < Crv_ylo || *y > Crv_yhi );
   } else {
      last_ok = 0;
      all_bad = 1;
   }

/* Store pointers to the X and Y values for the "current position". This
   is the position at the end of the current segment. This is initially 
   the second tabulated point. */
   px = x + 1;
   py = y + 1;

/* Store pointers to the increments and squared length for the current 
   segment. */
   pdx = dx;
   pdy = dy;
   pdl2 = dl2;

/* Initialise the smallest squared length value. */
   dl2_min = DBL_MAX;

/* Loop round each segment. */
   for( i = 0; i < CRV_NSEG; i++ ){

/* If the tabulated point marking the end of the segment is good... */
      if( *px != AST__BAD && *py != AST__BAD ){

/* If the point is within the plotting area, set the "all_bad" flag to
   indicate that at least 1 point is within the plotting area. */
         if( *px >= Crv_xlo && *px <= Crv_xhi &&
             *py >= Crv_ylo && *py <= Crv_yhi ) all_bad = 0;

/* If the point marking the start of the segment was also good, find and 
   store the increments and squared length for the segment, incrementing 
   the pointers ready for the next segment. */
         if( last_ok ){
            t1 = *px - last_x;
            t2 = *py - last_y;
            t3 = t1*t1 + t2*t2;
            *(pdx++) = t1;
            *(pdy++) = t2;
            *(pdl2++) = t3;

/* Update the minimum squared length. */
            if( t3 < dl2_min ) dl2_min = t3;

/* If the start was bad, the length of the segment is not defined so store 
   bad values. */
         } else {
            *(pdx++) = AST__BAD;
            *(pdy++) = AST__BAD;
            *(pdl2++) = AST__BAD;
         }

/* The point at the end of the current segment becomes the point at the 
   start of the next segment. */
         last_ok = 1;
         last_x = *(px++);
         last_y = *(py++);

/* If the tabulated point marking the end of the current segment is bad, 
   the segment length is undefined so store bad values. */
      } else {
         *(pdx++) = AST__BAD;
         *(pdy++) = AST__BAD;
         *(pdl2++) = AST__BAD;

/* The point at the end of the current segment becomes the point at the 
   start of the next segment. */
         last_ok = 0;
         px++;
         py++;
       }
   
   }

/* ======================================================================
   The next section of this function checks to see lines can be drawn 
   directly through any of the tabulated points. The flags in  "seg_ok" 
   indicates if this is the case for each segment.
   ======================================================================*/

/* The unit vector along the previous segment is supplied in external
   variables Crv_ux0 and Crv_uy0. These will be AST__BAD if the direction
   of the previous segment is undefined. */
   vxl = Crv_ux0;
   vyl = Crv_uy0;

/* Set up some pointers used to walk through the arrays holding the lengths
   of each segment. */
   pdl2 = dl2;
   pdx = dx;
   pdy = dy;

/* Check each segment in turn to see if it can be drawn as a single
   straight line. */
   for( i = 0; i < CRV_NSEG; i++ ){

/* A segment can only be drawn as a single line if both ends are good
   and the distance between them is not zero. */
      if( *pdl2 != AST__BAD && *pdl2 > 0.0 ){

/* Get a unit vector in the direction of the current segment. */
         dl = sqrt( *pdl2 );
         vx = *pdx/dl;
         vy = *pdy/dl; 

/* If a unit vector in the direction of the previous segment is available, 
   we check that the angle between the previous segment and the current 
   segment is not too high. */
         if( vxl != AST__BAD ){
            cosang = vxl*vx + vyl*vy;

/* If the angle is too high, set a flag to indicate that the segment cannot
   be drawn as a single line. Also, set the flag for the previous segment as
   well. */
            if( cosang < 0.8 ||
                ( *pdl2 )*( 1.0 - cosang*cosang ) > Crv_limit ) {
               seg_ok[ i ] = 0;
               if( i > 0 ) seg_ok[ i - 1 ] = 0;

/* If the angle between this segment and the previous segment is not too
   high, the segment can be drawn as a straight line. */
            } else {
               seg_ok[ i ] = 1;
            }

/* If no unit vector is available for the previous segment, then assume
   we are re-starting the curve after a discontinuity. In this case, we
   can draw it as a straight line. */
         } else {
            seg_ok[ i ] = 1;
         }

/* Save the unit vector along the current segment for use next time. */
         vxl = vx;
         vyl = vy;      

/* If the length of the current segment is undefined, or zero, we cannot
   draw it as a single line. Also, there is no direction vector to pass
   on to the next time, so set them bad. */
      } else {
         seg_ok[ i ] = 0;
         vxl = AST__BAD;
         vyl = AST__BAD;      
      }

/* Point to the next segment. */
      pdl2++;
      pdx++;
      pdy++;
   
   }

/* Do not allow isolated segments to be OK. If a segment is flagged as being 
   OK, but both its neighbours are not OK, set the segment not OK as well. */
   seg0 = seg_ok + 1;
   segm = seg_ok;
   segp = seg_ok + 2;

   if( !(*seg0) ) *segm = 0;

   for( i = 1; i < CRV_NSEG - 1; i++ ){
      if( !(*segm) && !(*segp) ) *seg0 = 0;
      seg0++;
      segm++;
      segp++;
   }

   if( !(*segm) ) *seg0 = 0;

/* ======================================================================
   The next section of this function draws the curve. Each segment is drawn
   as a straight line if the corresponding flag in "seg_ok" is set.
   Segments for which the flag is not set are drawn by calling this function 
   recursivly.
   ======================================================================*/

/* Get the parametric length (i.e. the increment in "d") of the sub-segments
   within each subdivided segment. */
   delta = ( d[ CRV_NSEG ] - d[ 0 ] )/(double)( CRV_NSEG*CRV_NSEG );

/* If we have made the maximum number of recursive entries into this
   function, or if every supplied point was bad or outside the plotting
   area, or if any of the segments were very short in graphics space, we will 
   not be attempting to subdivide any segments which cannot be drawn directly 
   as a straight line. */
   subdivide = ( Crv_nent < CRV_MXENT && !all_bad && dl2_min > limit2 );

/* Initialise some pointers to the data defineding the subsegments. */
   dd = NULL;
   xx = NULL;
   yy = NULL;
   
/* If we may be subdividing any segments, find which segments they are
   and set up the offset to each sub-segment. */
   if( subdivide ){

/* Initialise the number of segments being subdivided. */
      nseg = 0;
   
/* Loop round each segment. */
      for( i = 0; i < CRV_NSEG; i++ ){

/* If the segment cannot be drawn directly as a straight line, we will 
   subdivide it. */
         if( !seg_ok[ i ] ){

/* Increment the number of segments being subdivided, and let the array
   of subsegment offsets grow to accomodate it. */
            nseg++;
            dd = (double *) astGrow( dd, nseg, sizeof(double)*( CRV_NSEG + 1 ) );
            if( !astOK ) break;

/* Append the offset to each new subsegment to the "dd" array. */
            el = ( nseg - 1 )*( CRV_NSEG + 1 );
            d0 = d[ i ];
            for( j = 0; j <= CRV_NSEG; j++ ){
               dd[ el++ ] = d0;
               d0 += delta;
            }
          }
      }

/* If any segments needed subdividing, get room to store the graphics
   coordinates at each point, and then fill these arrays by calling 
   Crv_map to map the offsets in "dd" into graphics coordinates. */
      if( nseg > 0 ){
         nel = nseg*( CRV_NSEG + 1 );
         xx = (double *) astMalloc( sizeof(double)*(size_t)nel );
         yy = (double *) astMalloc( sizeof(double)*(size_t)nel );
         Crv_map( nel, dd, xx, yy, method, class );             
      }
   }

/* If all has gone OK, we will draw each segment. Initialise pointers
   used to walk through the "xx", "yy" and "dd" arrays. */      
   if( astOK ){
      px = xx;
      py = yy;
      pd = dd;

/* Draw each segment in turn. */
      for( i = 0; i < CRV_NSEG; i++ ){

/* If possible, draw it as a single straight line, and then store the 
   unit vector along the line in the appropriate external variables for
   use by the next invocation of this function. */
         if( seg_ok[ i ] ){
            CrvLine( x[ i ], y[ i ], x[ i + 1 ], y[ i + 1 ], method, class );   
            dl = sqrt( dl2[ i ] );
            Crv_ux0 = dx[ i ]/dl;
            Crv_uy0 = dy[ i ]/dl; 

/* Otherwise, if we are subdividing, and if the current segment is
   not very short, we call this function recursively to draw the segment.
   Increment pointers into the "xx", "yy" and "dd" arrays so that they
   point to the start of the subsegment information for the next segment
   to be subdivided. */
         } else if( subdivide ){             
            Crv( pd, px, py, method, class );
            pd += CRV_NSEG + 1;
            px += CRV_NSEG + 1;
            py += CRV_NSEG + 1;

/* Otherwise, we assume we have hit a discontinuity in the curve. Store
   bad values for the unit vector along the previous sgment, and do not 
   draw anything. */
         } else {
            Crv_ux0 = AST__BAD;
            Crv_uy0 = AST__BAD;
         }
       }
    }
  
/* Free any memory used to store subsegment information. */   
   if( dd ) dd = (double *) astFree( (void *) dd );
   if( xx ) xx = (double *) astFree( (void *) xx );
   if( yy ) yy = (double *) astFree( (void *) yy );

/* Decrement the number of recursive entries into this function. */
   Crv_nent--;                 

/* Return. */
   return;
                    
}

static int CvBrk( AstPlot *this, int ibrk, double *brk, double *vbrk, 
                     double *len ){
/*
*+
*  Name:
*     astCvBrk

*  Purpose:
*     Return information about breaks in the last curve drawn by astGridLine
*     or astCurve.

*  Type:
*     Protected virtual function.

*  Synopsis:
*     #include "plot.h"
*     int CvBrk( AstPlot *this, int ibrk, double *brk, double *vbrk,
*                   double *len )

*  Class Membership:
*     Plot method.

*  Description:
*     Curves drawn by astGridLine or astCurve may contain breaks for several 
*     reasons (for instance, it may go outside the plotting area, or the 
*     mapping between physical and graphics coordinates may be discontinuous).
*     This function returns information about such breaks.

*  Parameters:
*     this
*        Pointer to a Plot.
*     ibrk
*        The index of the break for which information is required. The first
*        break has index 1. An error is reported if no break with the 
*        required index exists. The exception to this is that zero can be 
*        supplied, in which case the "brk" and "vbrk" parameters
*        are ignored, but all other information is returned.
*     brk
*        A pointer to an array of 2 elements
*        in which to return the X and Y graphics coordinates of the break.
*     vbrk
*        A pointer to an array of 2 elements
*        in which to return the X and Y components of a unit vector in the 
*        graphics coordinate system. The vector is tangential to the curve 
*        at the requested break, and points back along the drawn section of 
*        the curve.
*     len 
*        A pointer to a "double" in which to return the
*        length of the drawn curve, in the graphics coordinate system.

*   Returned Value:
*     astCvBrk()
*        The number of breaks which occurred in the curve.

*  Notes:
*     -  Currently, this function may not be used to return information
*     about curves drawn using astPolyCurve.
*     -  All curves contain at least two breaks; one at the start and one 
*     at the end. This is true even if the start and end of the curve are
*     coincident. However, if the entire curve was outside the plotting area
*     (i.e. if the length of the drawn curve is zero), then it will have no
*     breaks.
*     -  If no curve has yet been drawn by astGridLine or astCurve, then -1 is 
*     returned for the function value, and the function parameter values are 
*     left unchanged.
*     -  The returned information refers to the most recent curve drawn by
*     astGridLine or astCurve, even if that curve was drawn by a Plot other than 
*     the one supplied to this function.
*     -  NULL pointers may be supplied for "brk", "vbrk" or "len", in which
*     case the corresponding values are not returned.
*     -  Zero is returned by this function if an error has already occurred, 
*     or if this function should fail for any reason.

*-
*/

/* Local Variables: */
   int ret;             /* The number of breaks in the curve. */

/* Check the global status. */
   if( !astOK ) return 0;

/* Information about the most recent curve drawn by astGridLine or astCurve is 
   stored in the external structure "Curve_data". Get the number of breaks 
   in the last curve. This is initialised to -1 in astInitPlot when the 
   virtual function table for this class is initialised. */
   ret = Curve_data.nbrk;   

/* If a curve has been drawn, store the length of the drawn curve if 
   required. */
   if( ret != -1 ){
      if( len ) *len = (double) Curve_data.length;

/* If a legal break index has been supplied, return the position and 
   direction at the requested break (if required). */
      if( ibrk > 0 && ibrk <= ret ){
         if( brk ){
            brk[ 0 ] =  (double) Curve_data.xbrk[ ibrk - 1 ];
            brk[ 1 ] =  (double) Curve_data.ybrk[ ibrk - 1 ];
         }
         if( vbrk ){
            vbrk[ 0 ] =  (double) Curve_data.vxbrk[ ibrk - 1 ];
            vbrk[ 1 ] =  (double) Curve_data.vybrk[ ibrk - 1 ];
         }
      
/* If an illegal break index has been supplied (other than zero), report
   an error, and set the number of breaks to zero. */
      } else if( ibrk ){
         if( ret > 0 ){
            astError( AST__BDBRK, "astCvBrk(%s): The supplied break index "
                      "(%d) should be in the range [1,%d].", astGetClass(this),
                      ibrk, ret );      
            ret = 0;
         } else {
            astError( AST__BDBRK, "astCvBrk(%s): The most recent curve "
                      "plotted by method astGridLine or astCurve had no breaks.", 
                      astGetClass(this) );
         }
      }
    }

/* If an error has occurred, return 0. */
   if( !astOK ) ret = 0;

/* Return the result. */
   return ret;
   
}

static void CrvLine( double xa, double ya, double xb, double yb,
                     const char *method, const char *class ){
/*                     
*  Name:
*     CrvLine

*  Purpose:
*     Draw a straight line between two points, with clipping.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void CrvLine( double xa, double ya, double xb, double yb,
*                   const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This functions draws a straight line from (xa,ya) to (xb,yb), breaking 
*     the line at the edges of the plotting area defined by Crv_xlo, Crv_xhi,
*     Crv_ylo and Crv_yhi. If the line does not start at the end of the 
*     previous line plotted by this function, then information describing
*     the break in the curve is stored in external arrays.

*  Parameters:
*     xa
*        The graphics X coordinate at the start of the line.
*     ya
*        The graphics Y coordinate at the start of the line.
*     xb
*        The graphics X coordinate at the end of the line.
*     yb
*        The graphics Y coordinate at the end of the line.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  External Variables:
*     Crv_ink = int (Read)
*        If zero then no line is drawn even if the line intersects the
*        plotting space, but break information (etc) is still returned.
*     Crv_xlo = double (Read)
*        Lower x limit of the plotting space.
*     Crv_xhi = double (Read)
*        Upper x limit of the plotting space.
*     Crv_ylo = double (Read)
*        Lower y limit of the plotting space.
*     Crv_yhi = double (Read)
*        Upper y limit of the plotting space.
*     Crv_tol = double (Read)
*        The tolerance for determining if 2 points are coincident.
*     Crv_out = int (Read/Write)
*        Returned as zero if the line intersects the plotting space.
*        Unchanged otherwise.
*     Crv_xbrk = float * (Read/Write)
*        Pointer to the next available element in an array of CRV_MXBRK 
*        values containing the graphics X coordinates at which each break 
*        in the plotted curve occurred. A break is recorded if the starting
*        point of the current line is not the same as the end point of
*        the previous line. 
*     Crv_ybrk = float * (Read/Write)
*        Pointer to the next available element in an array of CRV_MXBRK 
*        values containing the graphics Y coordinates at which each break 
*        in the plotted curve occurred. 
*     Crv_vxbrk = float * (Read/Write)
*        Pointer to the next available element in an array of CRV_MXBRK 
*        values containing the X component of the unit vector (within the 
*        graphics coordinate system) parallel to the tangent to the curve 
*        at each break. The sense is such that the vector always points back 
*        along the plotted section of the curve. 
*     Crv_vybrk = float * (Read/Write)
*        Pointer to the next available element in an array of CRV_MXBRK 
*        values containing the Y component of the unit vector parallel to 
*        the tangent to the curve at each break. 
*     Crv_nbrk = int (Write)
*        The number of breaks for which information is returned in Crv_xbrk,
*        etc.
*     Crv_len = float (Write)
*        The length of the section of the curve which has been drawn so far.
*     Crv_xl = double (Write)
*        The graphics X coordinate at the end of the last line drawn.
*     Crv_yl = double (Write)
*        The graphics Y coordinate at the end of the last line drawn.
*     Crv_vxl = double (Write)
*        The X component of the unit vector along the last line drawn.
*     Crv_vyl = double (Write)
*        The Y component of the unit vector along the last line drawn.

*/

/* local Variables: */
   double a1;    /* Distance from B to the lower x boundary */
   double a2;    /* Distance from B to the upper x boundary */
   double a3;    /* Distance from B to the lower y boundary */
   double a4;    /* Distance from B to the upper y boundary */
   double aamax; /* Distance from supplied point B to the plotable point A */
   double aamin; /* Distance from supplied point B to the plotable point B */
   double dl;    /* Length of plotted line segment */
   double dx;    /* Difference in x between supplied points */
   double dy;    /* Difference in y between supplied points */
   double t;     /* Temporary storage */
   double xam;   /* Modified xa position */
   double xbm;   /* Modified xb position */
   double yam;   /* Modified ya position */
   double ybm;   /* Modified yb position */
   int plot;     /* True if a line can be plotted */

/* Check inherited global status. */
   if( !astOK ) return;

/* Store the shifts in x and y. */
   dx = xb - xa;
   dy = yb - ya;

/* Do nothing if the line is of zero length. */
   if( dx == 0.0 && dy == 0.0 ) return;

/* If either end is outside the zone, replace the given coordinates with
   the end coordinates of the section of the line which lies within the
   zone. */
   if( xa < Crv_xlo || xa > Crv_xhi || xb < Crv_xlo || xb > Crv_xhi ||
       ya < Crv_ylo || ya > Crv_yhi || yb < Crv_ylo || yb > Crv_yhi ){

/* Find the distance from point B towards point A at which the
   line cuts the two x bounds of the zone (distance at point B is
   0.0, and at point A is 1.0). */
      if( dx != 0.0 ){
         a1 = ( xb - Crv_xlo )/dx;
         a2 = ( xb - Crv_xhi )/dx;

/* Ensure that a1 represents the highest plottable offset, and a2 the
   lowest. */
         if( a1 < a2 ){
            t = a1;
            a1 = a2;
            a2 = t;
         }

/* If the line joining A and B is vertical... */
      } else {

/* If the line is within the plottable x range, indicate that all
   offsets are plottable (as far as the x range is concerned at least). */
         if( ( xa > Crv_xlo || EQUAL( xa, Crv_xlo ) ) && 
             ( xa < Crv_xhi || EQUAL( xa, Crv_xhi ) ) ){
            a1 = DBL_MAX;
            a2 = -DBL_MAX;

/* If the line is ouside the plottable x range, indicate that no
   offsets are plottable. */
         } else {
            a1 = 0.0;
            a2 = 0.0;
         }
       }

/* Find the fractional distance from point A to point B at which the
   line cuts the two y bounds of the zone. */
      if( dy != 0.0 ){
         a3 = ( yb - Crv_ylo )/dy;
         a4 = ( yb - Crv_yhi )/dy;

/* Ensure that a3 represents the highest plottable offset, and a4 the
   lowest. */
         if( a3 < a4 ){
            t = a3;
            a3 = a4;
            a4 = t;
         }

/* If the line joining A and B is horizontal... */
      } else {

/* If the line is within the plottable y range, indicate that all
   offsets are plottable (as far as the y range is concerned at least). */
         if( ( ya > Crv_ylo || EQUAL( ya, Crv_ylo ) ) && 
             ( ya < Crv_yhi || EQUAL( ya, Crv_yhi ) ) ){
            a3 = DBL_MAX;
            a4 = -DBL_MAX;

/* If the line is ouside the plottable y range, indicate that no
   offsets are plottable. */
         } else {
            a3 = 0.0;
            a4 = 0.0;
         }
      }

/* Find the fractional distances from point A to point B at the ends
   of the plotable line. */
      aamin = MIN( 1.0, MAX( 0.0, MAX( a2, a4 ) ) );
      aamax = MAX( 0.0, MIN( 1.0, MIN( a1, a3 ) ) );

/* Store the end coordinates of the line joining the plotable points. */
      if( aamax > aamin ){
         xam = xb - aamax*dx;
         yam = yb - aamax*dy;
         xbm = xb - aamin*dx;
         ybm = yb - aamin*dy;
         plot = 1;

/* Get the unit vector along the line and the length of the plotted section. */
         dl = sqrt( dx*dx + dy*dy ); 
         dx /= dl;
         dy /= dl;
         dl *= MAX( 0.0, aamax - aamin );

/* Clear the "plot" flag if the line does not intersect the plotting area. */
      } else {
         plot = 0;
      }

/* If both ends of the line are within the plotting zone, draw the whole
   line between the supplied end points. */
   } else {
      xam = xa;
      yam = ya;
      xbm = xb;
      ybm = yb;
      plot = 1;

/* Get the length of the line and the unit vector along the line. */
      dl = sqrt( dx*dx + dy*dy ); 
      dx /= dl;
      dy /= dl;
    }

/* If a line is to be plotted... */
   if( plot ){
      
/* If this is the first line to be plotted in the current curve, save
   the start of the line as a break, and indicate that some of the curve
   falls within the plotting zone. */
      if( Crv_out ){
         Crv_nbrk = 1;
         *(Crv_xbrk++) = (float) xam;
         *(Crv_ybrk++) = (float) yam;
         *(Crv_vxbrk++) = (float) dx;
         *(Crv_vybrk++) = (float) dy;
         Crv_out = 0;

/* Set the length of the curve plotted so far to the length of this first
   segment. */
         Crv_len = (float) dl;

/* Start a poly line. */
         if( Crv_ink ) Bpoly( (float) xam,  (float) yam, method, class );

/* If this is not the first line to be plotted... */
      } else {

/* ... increment the length of the curve plotted so far. */
         Crv_len += (float) dl;

/* If the start of this line is not coincident with the end
   of the previous line, save the previous and current positions as 
   breaks in the curve. Note, the previous vector is reversed so that 
   it points back towards the drawn section of the curve. Report an 
   error if the arrays are full. */
         if( fabs( xam - Crv_xl ) > Crv_tol || 
             fabs( yam - Crv_yl ) > Crv_tol ){
            Crv_nbrk += 2;
             if( Crv_nbrk > CRV_MXBRK ){
               astError( AST__CVBRK, "%s(%s): Number of breaks in plotted "
                         "curve exceeds %d.", method, class, CRV_MXBRK );
            } else {
               *(Crv_xbrk++) = (float) Crv_xl;
               *(Crv_ybrk++) = (float) Crv_yl;
               *(Crv_vxbrk++) = (float) -Crv_vxl;
               *(Crv_vybrk++) = (float) -Crv_vyl;
                *(Crv_xbrk++) = (float) xam;
               *(Crv_ybrk++) = (float) yam;
               *(Crv_vxbrk++) = (float) dx;
               *(Crv_vybrk++) = (float) dy;
            }

/* Start a poly line. */
            if( Crv_ink ) Bpoly( (float) xam,  (float) yam, method, class );
          }
      }

/* Append a section to the current poly line. */
      if( Crv_ink ) Apoly( (float) xbm,  (float) ybm, method, class );

/* Save the position and vector at the end of the current line. */
      Crv_xl = xbm;
      Crv_yl = ybm;
      Crv_vxl = dx;
      Crv_vyl = dy;
    }

/* Return. */
   return;
}


static void Curve( AstPlot *this, const double start[],
                                  const double finish[] ){
/*
*++
*  Name:
c     astCurve
f     AST_CURVE

*  Purpose:
*     Draw a geodesic curve.

*  Type:
*     Public virtual function.

*  Synopsis:
c     #include "plot.h"
c     void astCurve( AstPlot *this, const double start[],
c                                   const double finish[] )
f     CALL AST_CURVE( THIS, START, FINISH, STATUS )

*  Class Membership:
*     Plot method.

*  Description:
c     This function draws a geodesic curve between two points in the
f     This routine draws a geodesic curve between two points in the
*     physical coordinate system of a Plot.  The curve drawn is the
*     path of shortest distance joining the two points (as defined by
c     the astDistance function for the current Frame of the Plot).
f     the AST_DISTANCE function for the current Frame of the Plot).
*     For example, if the current Frame is a basic Frame, then the
*     curve joining the two points will be a straight line in physical
*     coordinate space.  If the current Frame is more specialised and
*     describes, for instance, a sky coordinate system, then the
*     geodesic curve would be a great circle in physical coordinate
*     space passing through the two sky positions given.
*
*     Note that the geodesic curve is transformed into graphical
*     coordinate space for plotting, so that a straight line in
*     physical coordinates may result in a curved line being drawn if
*     the Mapping involved is non-linear. Any discontinuities in the
*     Mapping between physical and graphical coordinates are
c     catered for, as is any clipping established using astClip.
f     catered for, as is any clipping established using AST_CLIP.
*
c     If you need to draw many geodesic curves end-to-end, then the
c     astPolyCurve function is equivalent to repeatedly using
c     astCurve, but will usually be more efficient.
f     If you need to draw many geodesic curves end-to-end, then the
f     AST_POLYCURVE routine is equivalent to repeatedly calling
f     AST_CURVE, but will usually be more efficient.

*  Parameters:
c     this
f     THIS = INTEGER (Given)
*        Pointer to the Plot.
c     start
f     START( * ) = DOUBLE PRECISION (Given)
*        An array, with one element for each axis of the Plot, giving
*        the physical coordinates of the first point on the geodesic
*        curve.
c     finish
f     FINISH( * ) = DOUBLE PRECISION (Given)
*        An array, with one element for each axis of the Plot, giving
*        the physical coordinates of the second point on the geodesic
*        curve.
f     STATUS = INTEGER (Given and Returned)
f        The global status.

*  Notes:
c     - No curve is drawn if either of the "start" or "finish" arrays
c     contains any coordinates with the value AST__BAD.
f     - No curve is drawn if either of the START or FINISH arrays
f     contains any coordinates with the value AST__BAD.
*     - An error results if the base Frame of the Plot is not 2-dimensional.
*     - An error also results if the transformation between the
*     current and base Frames of the Plot is not defined (i.e. the
*     Plot's TranInverse attribute is zero).
*--
*/
/* Local Variables: */
   const char *class;      /* Object class */
   const char *method;     /* Current method */
   int naxes;              /* No. of axes in the base Frame */

/* Check the global error status. */
   if ( !astOK ) return;

/* Store the current method, and the class of the supplied object for use 
   in error messages.*/
   method = "astCurve";
   class = astGetClass( this );

/* Check the base Frame of the Plot is 2-D. */
   naxes = astGetNin( this );
   if( naxes != 2 && astOK ){
      astError( AST__NAXIN, "%s(%s): Number of axes (%d) in the base "
                "Frame of the supplied %s is invalid - this number should "
                "be 2.", method, class, naxes, class );
   } 

/* Draw the curve. The break information is stored in an external structure
   where it can be accessed by public methods which return information
   about the most recently drawn curve. */
   CurvePlot( this, start, finish, 1, &Curve_data, method, class );

/* Return. */
   return;

}

static void CurvePlot( AstPlot *this, const double *start, const double *finish, 
                     int ink, CurveData *cdata, const char *method, 
                     const char *class ){
/*
*
*  Name:
*     CurvePlot

*  Purpose:
*     Draw a geodesic curve.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void CurvePlot( AstPlot *this, const double *start, const double *finish, 
*                   int ink, CurveData *cdata, const char *method, 
*                   const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function draws a geodesic curve between the supplied starting and
*     finishing positions. The algorithm used can handle discontinuities in the
*     Mapping between the current Frame and graphics coordinates, and 
*     information describing any breaks in the curve (including the start and
*     end of the curve) are returned in the supplied CurveData structure. 

*  Parameters:
*     this
*        Pointer to the Plot.
*     start
*        A pointer to a an array holding the coordinates of the start of the 
*        curve within the current Frame of the Plot.
*     finish
*        A pointer to a an array holding the coordinates of the finish of the 
*        curve within the current Frame of the Plot.
*     ink
*        If zero, the curve is not actually drawn, but information about 
*        the breaks is still returned. If non-zero, the curve is also drawn.
*     cdata
*        A pointer to a structure in which to return information about the
*        breaks in the curve.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Notes:
*     -  No curve is draw if the "start" or "finish" arrays contains any bad 
*     values, or if a NULL pointer is supplied for "cdata". No errors are 
*     reported in these cases.
*/

/* Local Variables: */
   double d[ CRV_NPNT ];   /* Offsets to evenly spaced points along curve */
   double x[ CRV_NPNT ];   /* X coords at evenly spaced points along curve */
   double y[ CRV_NPNT ];   /* Y coords at evenly spaced points along curve */
   double tol;             /* Absolute tolerance value */
   int i;                  /* Loop count */
   int naxes;              /* No. of axes in the base Frame */
   int ok;                 /* Are all start coords good? */

/* Check the global error status. */
   if ( !astOK ) return;

/* Get the number of axes in the current Frame. */
   naxes = astGetNout( this );

/* Check the "start" and "finish" parameter for bad values. */
   ok = 1;
   for( i = 0; i < naxes; i++ ) {
      if( start[ i ] == AST__BAD || finish[ i ] == AST__BAD ){
         ok = 0;
         break;
      }
   }

/* Check that the "cdata" pointer can be used. */
   if( !cdata ) ok = 0;

/* Only proceed if the parameters are OK, and there has been no error. */
   if( ok && astOK ){   

/* Establish the correct graphical attributes as defined by attributes
   with the supplied Plot. */
      GrfAttrs( this, CURVE_ID, 1, GRF__LINE );

/* Set up the externals used to communicate with the Map3 function...
   The number of axes in the physical coordinate system (i.e. the current
   Frame). */
      Map3_ncoord = naxes;

/* A pointer to the Plot, the Curretn Frame, and and Mapping. */
      Map3_plot = this;
      Map3_frame = astGetFrame( this, AST__CURRENT );
      Map3_map = astGetMapping( this, AST__BASE, AST__CURRENT );

/* The physical coordinates at the start of the curve. */
      Map3_origin = start;

/* The physical coordinates at the end of the curve. */
      Map3_end = finish;

/* The scale factor to convert "dist" values into physical offset values. */
      Map3_scale = astDistance( Map3_frame, start, finish );

/* Convert the tolerance from relative to absolute graphics coordinates. */
      tol = astGetTol( this )*MAX( this->xhi - this->xlo, 
                                   this->yhi - this->ylo );

/* Now set up the external variables used by the Crv and CrvLine function. */
      Crv_ux0 = AST__BAD;    
      Crv_tol = tol;
      Crv_limit = 0.5*tol*tol;
      Crv_map = Map3;
      Crv_ink = ink;
      Crv_xlo = this->xlo;
      Crv_xhi = this->xhi;
      Crv_ylo = this->ylo;
      Crv_yhi = this->yhi;
      Crv_out = 1;
      Crv_xbrk = cdata->xbrk;
      Crv_ybrk = cdata->ybrk;
      Crv_vxbrk = cdata->vxbrk;
      Crv_vybrk = cdata->vybrk;

/* Set up a list of points spread evenly over the curve. */
      for( i = 0; i < CRV_NPNT; i++ ){
        d[ i ] = ( (double) i)/( (double) CRV_NSEG );
      }

/* Map these points into graphics coordinates. */
      Map3( CRV_NPNT, d, x, y, method, class );

/* Use Crv and Map3 to draw the curve. */
      Crv( d, x, y, method, class );

/* End the current poly line. */
      Opoly( method, class );

/* Tidy up the static data used by Map3. */
      Map3( 0, NULL, NULL, NULL, method, class );

/* If no part of the curve could be drawn, set the number of breaks and the 
   length of the drawn curve to zero. */
      if( Crv_out ) {
         Crv_nbrk = 0;
         Crv_len = 0.0F;

/* Otherwise, add an extra break to the returned structure at the position of 
   the last point to be plotted. */
      } else {
         Crv_nbrk++;
         if( Crv_nbrk > CRV_MXBRK ){
            astError( AST__CVBRK, "%s(%s): Number of breaks in curve "
                      "exceeds %d.", method, class, CRV_MXBRK );
         } else {
            *(Crv_xbrk++) = (float) Crv_xl;
            *(Crv_ybrk++) = (float) Crv_yl;
            *(Crv_vxbrk++) = (float) -Crv_vxl;
            *(Crv_vybrk++) = (float) -Crv_vyl;
         }
      }

/* Store extra information about the curve in the returned structure. */
      if( cdata ){
         cdata->length = Crv_len;
         cdata->out = Crv_out;
         cdata->nbrk = Crv_nbrk;
      }

/* Annul the Frame and Mapping. */
      Map3_frame = astAnnul( Map3_frame );
      Map3_map = astAnnul( Map3_map );

/* Re-establish the original graphical attributes. */
      GrfAttrs( this, CURVE_ID, 0, GRF__LINE );

   }

/* Return. */
   return;

}


static AstPointSet *DefGap( AstPlot *this, double *gaps, int *ngood, 
                            double *frac, int *inval, const char *method, 
                            const char *class  ){
/*
*  Name:
*     DefGap

*  Purpose:
*     Find default gap sizes for the tick marks on the axes of a 2-D
*     physical coordinate system.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     AstPointSet *DefGap( AstPlot *this, double *gaps, int *ngood, 
*                          double *frac, int *inval, const char *method, 
*                          const char *class  )

*  Class Membership:
*     Plot method.

*  Description:
*     This function returns default gap sizes for each axis in a 2-D Frame.
*     The values are found by first obtaining a grid of points spread over
*     the region containing good physical coordinates. The values for each
*     axis are sorted into increasing order and a set of quantile axis
*     values found. The median of the gaps between these quantiles is
*     returned as the default gap for the axis. 

*  Parameters:
*     this
*        Pointer to a Plot.
*     gaps
*        Pointer to an array in which to return the default gap value for
*        each axis. 
*     ngood
*        Pointer to an array in which toi return the number of good
*        values in the returned PointSet for each axis.
*     frac
*        Pointer to a double in which to return the fraction of the
*        plotting area containing good physical coordinates.
*     inval
*        Pointer to a location at which to return a flag indicating if
*        any bad physical coordinates were encountered.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     A pointer to a PointSet holding the physical coordinate values at a
*     set of points spread across the plotting area. The values on each
*     axis are sorted into increasing order.

*  Notes:
*     -  The returned PointSet should be annulled when no longer needed.
*     -  This function assumes that the physical coordinate system is 2 
*     dimensional, and it should not be used if this is not the case.
*     -  Gap sizes of 1.0, zero good points, and a NULL pointer are returned 
*     if an error has already occurred, or if this function should fail for 
*     any reason. 

*/

/* Local Variables: */
   AstPointSet *pset1;        /* Pointer to PointSet holding graphics coords */
   AstPointSet *pset2;        /* Pointer to PointSet holding physical coords */
   double **ptr1;             /* Pointer to graphics axis values */
   double **ptr2;             /* Pointer to physical axis values */
   double qgap[ MAJTICKS_OPT ];/* Gaps between physical coordinate quantiles */
   int dim;                   /* Dimension of grid */
   int dk;                    /* The number of points between quantiles */
   int i;                     /* The quantile index */
   int j;                     /* Axis index */
   int k;                     /* Index into the sorted array of axis values */
   int psize;                 /* Total number of axis value */

/* Initialise the returned values. */
   gaps[ 0 ] = 1.0;
   gaps[ 1 ] = 1.0;
   ngood[ 0 ] = 0;
   ngood[ 1 ] = 0;
   *frac = 0.0;
   *inval = 0;

/* Check global status. */
   if( !astOK ) return NULL;

/* Get two PointSets, one holding a grid of 2D graphics coordinates,
   and one holding the corresponding physical coordinates. */
   *frac = GoodGrid( this, &dim, &pset1, &pset2, method, class );

/* Get pointers to the data values in each PointSet. */
   ptr1 = astGetPoints( pset1 );
   ptr2 = astGetPoints( pset2 );

/* Store the number of elements in each PointSet. */
   psize = dim*dim;

/* For each axis... */
   for( j = 0; j < 2 && astOK; j++ ){

/* Sort the axis values into increasing order. Any bad values are stored at
   the end of the array on return. */
      qsort( (void *) ptr2[ j ], (size_t) psize, sizeof(double), Compared );

/* Count the number of non-bad values returned. */
      ngood[ j ] = CountGood( psize, ptr2[ j ] );

/* Set the returned flag to indicate if any bad values were found. */
      if( ngood[ j ] < psize ) *inval = 1;

/* Report an error if there are too few good points. */
      if( ngood[ j ] < MAJTICKS_OPT ){
         astError( AST__VSMAL, "%s(%s): The area of the plot containing "
                      "valid coordinates is too small.", method, class );
         break;
      }

/* Find the gaps between adjacent evenly spaced quantiles. The number of 
   quantiles used equals the optimal number of major tick marks. */
      dk = (int)( (double)ngood[ j ]/MAJTICKS_OPT );
      i = 0;
      for( k = dk; k < ngood[ j ] && i < MAJTICKS_OPT; k += dk ){
         qgap[ i++ ] = ptr2[ j ][ k ] - ptr2[ j ][ k - dk ];
      }

/* Find the median of the gaps between adjacent quantiles. */
      qsort( (void *) qgap, (size_t) i, sizeof(double), Compared );
      gaps[ j ] = qgap[ i/2 ];

/* If the test gap size is zero, use a fraction of the total range. Report
   an error if the total range is zero. */
      if( gaps[ j ] <= 0.0 ){
         gaps[ j ] = ( ptr2[ j ][ ngood[ j ] - 1 ] - ptr2[ j ][ 0 ] )/MAJTICKS_OPT;;
         if( gaps[ j ] <= 0.0 ){
            astError( AST__VSMAL, "%s(%s): The range of axis values "
                      "covered by the plot is too small.", method, class );
         }

      }

   }

/* Annul the PointSet holding Graphics coordinates. */
   pset1 = astAnnul( pset1 );

/* If an error has occurred, annul the PointSet holding physical
   coordinates, and return gaps of 1.0. */
   if( !astOK ) {
      pset2 = astAnnul( pset2 );
      gaps[ 0 ] = 1.0;
      gaps[ 1 ] = 1.0;
      ngood[ 0 ] = 0;
      ngood[ 1 ] = 0;
      *frac = 0.0;
      *inval = 0;
   }

/* Return the physical PointSet. */
   return pset2;

}

static void DrawAxis( AstPlot *this, TickInfo **grid, double *labelat,
                      double *gap, const char *method, const char *class ){
/*
*
*  Name:
*     DrawAxis

*  Purpose:
*     Draw a curve joining the major tick marks.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void DrawAxis( AstPlot *this, TickInfo **grid, double *labelat,
*                    double *gap, const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function draws a curve through interior tick marks on both axes. 
*     The curve is drawn even if it has already been drawn as part of a
*     grid of curves, because it may have been assigned different graphics 
*     attributes to the grid curves.

*  Parameters:
*     this
*        A pointer to the Plot.
*     grid
*        A pointer to an array of two TickInfo pointers (one for each axis), 
*        each pointing to a TickInfo structure holding information about
*        tick marks on the axis. See function GridLines.
*     labelat
*        A pointer to a 2 element array giving the constant axis values at 
*        which tick marks are put. Element 0 should give the axis 1 value at
*        which tick marks for axis 0 are placed. Element 1 should give the 
*        axis 0 value at which tick marks for axis 1 are placed.
*     gap
*        Pointer to array of two values holding the gap between major
*        tick marks on the two axes.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Notes:
*     -  This function assumes the current Frame of the Plot is 2
*     dimensional, and it should not be called if this is not the case. 

*/

/* Local Variables: */
   CurveData cdata;       /* Somewhere to put the unneeded curve information */
   TickInfo *info;        /* Pointer to the TickInfo for the current axis */
   double *value;         /* Current tick value */
   double start[ 2 ];     /* The start of the curve in physical coordinates */
   int axis;              /* Current axis index */
   int tick;              /* Current tick index */

/* Check the global status. */
   if( !astOK ) return;

/* Establish the correct graphical attributes as defined by attributes
   with the supplied Plot. */
   GrfAttrs( this, AXIS_ID, 1, GRF__LINE );

/* Consider drawing a curve parallel to each axis in turn. */
   for( axis = 0; axis < 2; axis++ ){

/* If the tick marks have been placed round the edges of the plotting
   area, we do not need to draw the curves. */
      if( labelat[ axis ] != AST__BAD ){

/* Get a pointer to the structure containing information describing the 
   positions of the major tick marks along the current axis. */  
         info = grid[ axis ];

/* Get a pointer to the axis value at the first major tick mark. */
         value = info->ticks;

/* Loop round all ticks. */
         for( tick = 0; tick < info->nmajor; tick++ ){

/* Draw a curve parallel to the current axis, starting at the tick mark,
   with length equal to the gap between tick marks. Do not draw sections
   of the curve which are outside the normal ranges of the physical axes. */
            start[ axis ] = *(value++);
            start[ 1 - axis ] = labelat[ axis ];
            AxPlot( this, axis, start, gap[ axis ], 1, &cdata, 1, method, 
                    class );
         }
      }
   }

/* Re-establish the original graphical attributes. */
   GrfAttrs( this, AXIS_ID, 0, GRF__LINE );

/* Return. */
   return;

}


static CurveData **DrawGrid( AstPlot *this, TickInfo **grid, int drawgrid,
                             const char *method, const char *class ){ 
/*
*  Name:
*     DrawGrid

*  Purpose:
*     Draw a grid of lines at the major tick mark positions on both axes.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     CurveData **DrawGrid( AstPlot *this, TickInfo **grid, int drawgrid,
*                           const char *method, const char *class )

*  Class Membership:
*     Plot method.

*  Description:
*     This function draw a grid of curves at the major tick mark
*     positions on both axes, and returns information describing the
*     breaks in the curves. If short tick marks are required rather
*     than long curves (as specified by the Grid attribute of the supplied
*     Plot), then the curves are not drawn but the break information is
*     still returned. 

*  Parameters:
*     this
*        Pointer to a Plot.
*     grid
*        A pointer to an array of two pointers (one for each axis), each 
*        pointing to a TickInfo structure. These describe the positions
*        of the tick marks and should have been produced by function
*        GridLines. 
*     drawgrid
*        If non-zero, draw a grid of curves marking the major axis
*        values. Otherwise, tick marks will be drawn at these values later.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     A pointer to an array of two CurveData pointers (one for eacxh axis),
*     each pointing to an array of CurveData structures (one for each tick 
*     value).

*  Notes:
*     -  This function assumes that the physical coordinate system is 2 
*     dimensional, and it should not be used if this is not the case.
*     -  If an error has already occurred, or if this function should fail 
*     for any reason, then a NULL pointer is returned.

*/

/* Local Variables: */
   CurveData **cdata;       /* The returned pointer */
   CurveData *cdt;          /* Pointer to break info. for current tick mark */
   CurveData tcdt;          /* Pointer to break info. for current curve section */
   TickInfo *info;          /* Tick mark information for a single axis */
   double start[ 2 ];       /* Strting position for current curve section */
   int i;                   /* Axis index */
   int j;                   /* Tick mark index */
   int k;                   /* Curve section index */

/* Check the global status. */
   if( !astOK ) return NULL;

/* Allocate memory to hold two pointers, each pointing to an array of
   CurveData structure. */
   cdata = (CurveData **) astMalloc( 2*sizeof( CurveData *) );

/* If succesful, initialise the pointers. */
   if( astOK ){
      cdata[ 0 ] = NULL;
      cdata[ 1 ] = NULL;

/* Draw the curves marking the major tick values on each axis. If no grid is 
   required, we still do this in order to get information about the breaks 
   in the curves which will be used later to decide where to put the labels, 
   but we use "invisible ink". */
      for( i = 0; i < 2; i++ ){

/* Get a pointer to the TickInfo structure for this axis holding information 
   about where to put tick marks on this axis. */
         info = grid[ i ];

/* Allocate memory to hold information describing the breaks in each tick
   mark curve. This takes the form of an array of CurveDara structures,
   one for each tick mark. */
         cdata[ i ] = (CurveData *) astMalloc( sizeof(CurveData)*
                                               (size_t) info->nmajor );

/* Check the pointer can be used. */
         if( astOK ){

/* Initialise a pointer to the first CurveData structure for this axis. */
            cdt = cdata[ i ];

/* Do each tick mark. */
            for( j = 0; j < info->nmajor; j++ ){

/* Store the starting point of the first section of the curve. */
               start[ i ] = (info->ticks)[ j ];
               start[ 1 - i ] = (info->start)[ 0 ];         

/* Draw the first section of the curve parallel to the other axis, starting 
   at the values in "start", and extending for a length given in the TickInfo 
   structure. We use invisible ink if short tick marks are required instead 
   of a grid of curves. */
               AxPlot( this, 1 - i, start, (info->length)[ 0 ],
                       drawgrid, cdt, 1, method, class );

/* Now draw any other sections in the curve. */
               for( k = 1; k < info->nsect; k++ ){

/* Modify the starting value on the other axis. The starting value on
   the current axis remains set to the tick mark value. */
                  start[ 1 - i ] = (info->start)[ k ];         

/* Draw the curve, the information describing the breaks goes into
   temporary storage in the local structure "tcdt". */
                  AxPlot( this, 1 - i, start, (info->length)[ k ],
                          drawgrid, &tcdt, 1, method, class );

/* Concatenate the break information for this section with the break
   information describing the previous sections. */
                  AddCdt( cdt, &tcdt, method, class );

               }

/* Point to the CurveData structure for the next tick mark. */
               cdt++;

            }

         }
  
      }

   }

/* If an error has occurred, clean up the returned structures. */
   if( !astOK ) cdata = CleanCdata( cdata );

/* Return. */
   return cdata;   

}

#if 0
/* ENABLE-ESCAPE - Add the following function when escape sequences
   are enabled. */
static int DrawText( AstPlot *this, int esc, const char *text, float x, float y, 
                     const char *just, float upx, float upy, const char *method, 
                     const char *class ){
/*
*+
*  Name:
*     DrawText

*  Purpose:
*     Draw a character string, potentially including superscripts and
*     subscripts.

*  Synopsis:
*     #include "plot.h"
*     int DrawText( AstPlot *this, int esc, const char *text, float x, float y,
*                   const char *just, float upx, float upy, const char *method,
*                   const char *class )

*  Description:
*     This function displays a character string at a given position
*     using a specified up-vector, optionally interpreting any Plot escape 
*     sequences contained within the text. The justification is specified
*     by the caller, and refers to the edges of the bounding box
*     enclosing the "normal" text (i.e. super-scripts and sub-scripts may
*     extend above or below the bounding box used).

*  Parameters:
*     this
*        The plot.
*     esc
*        Should escape sequences be interpreted? They will be printed
*        literally otherwise.
*     text 
*        Pointer to a null-terminated character string to be displayed.
*     x
*        The graphics X coordinate of the label's reference point.
*     y
*        The graphics Y coordinate of the label's reference point.
*     just
*        Pointer to a null-terminated character string identifying the
*        reference point for the text being drawn. The first character in
*        this string identifies the reference position in the "up" direction
*        and may be "B", "C" or "T" (for bottom, centre or top - two
*        other legal characters, "D" and "U" are described in the Notes 
*        below). The second character identifies the side-to-side reference 
*        position and may be "L", "C" or "R" (for left, centre or right). The 
*        string is case-insensitive, and only the first two characters are 
*        significant.
*     upx
*        The x component of the up-vector for the text. Positive values
*        always refer to displacements from left to right on the screen, 
*        even if the graphics x axis increases in the opposite sense.
*     upy
*        The y component of the up-vector for the text. Positive values
*        always refer to displacements from left to right on the screen, 
*        even if the graphics y axis increases in the opposite sense.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     Zero for failure, one for success.

*  Notes:
*     -  At the moment, this function draws all strings with BL
*     justification. If this is not the requested justification then 
*     the supplied reference position is modified so that BL justification
*     gives the correct positioning. This causes problems in GAIA when 
*     zooming. This is because GAIA zooms the reference positions but not the 
*     text size, resulting in the text drifting to the bottom left. For
*     this reason, astGText is currently used instead of this function 
*     (DrawText) throughout the Plot class.
*     -  The "B" option for the justification in the "up" direction refers
*     to the base-line on which the text is written. Some characters
*     ("y", "p", "g", etc) descend below this line. In addition, if the
*     supplied text string includes any escape sequences which produce 
*     sub-scripts, then these will also descend below the base-line. To
*     justify the bottom of the entire string (instead of just the
*     base-line), specify "D" instead of "B" in the justification string.
*     -  The "T" option for the justification in the "up" direction refers
*     to the top of the tallest characters. However, if the supplied text 
*     string includes any escape sequences which produce super-scripts, 
*     then these may extend above this line. To justify the top of the 
*     entire string (including super-scripts), specify "U" instead of "T" 
*     in the justification string.
*     -  See function GrText for details of the supported escape sequences.
*     -  Any graphics within the rotated box enclosing the text are
*     erased if argument ink is non-zero.
*     -  Both "upx" and "upy" being zero causes an error.
*-
*/


/* Local Variables: */
   char lj[3];          /* Local version of justification string. */
   float xbn[ 4 ];      /* X at corners of bounding box */
   float ybn[ 4 ];      /* Y at corners of bounding box */
   int bbclip;          /* GrText to return bounding box of "normal" text? */
   int ret;             /* Returned status */

/* Check the global error status. */
   if ( !astOK ) return 0;

/* Assume success. */
   ret = 1;

/* Fill in any missing parts of the justification string. */
   if( just ){
      if( just[ 0 ] == 'T' || just[ 0 ] == 'C' || just[ 0 ] == 'B' ||
          just[ 0 ] == 'U' || just[ 0 ] == 'D' ){
         lj[ 0 ] = just[ 0 ];
      } else {
         lj[ 0 ] = 'C';
      }

      if( just[ 1 ] == 'L' || just[ 1 ] == 'C' || just[ 1 ] == 'R' ){
         lj[ 1 ] = just[ 1 ];
      } else {
         lj[ 1 ] = 'C';
      }

   } else {
      lj[ 0 ] = 'C';
      lj[ 1 ] = 'C';
   }

   lj[2] = 0;

/* Only proceed if there is some text to draw. */
   if( text ) {

/* The basic drawing function GrText assumes BL justification. If this is
   the requested justification, just call GrText to draw the text. */
      if( lj[0] == 'B' && lj[1] == 'L' ) {
         ret = GrText( this, esc, text, 1, 1, x, y, upx, upy, xbn, ybn, method, class );

/* Otherwise, we need to determine the correct BL position which will
   give the requested justfication. This involves calling GrText twice;
   once (with ink switched off) to find the size of the text string, and
   once to draw it.  */
      } else {

/* The vertical justification options "U" and "D" refer to the top or bottom 
   of the whole bounding box (including sub-scripts, super-scripts, etc ). If
   either of these have been requested, convert them into the equivalent
   options refering to the "normal" text bounding box (i.e. "T" or "B"),
   and set a flag indicating that the bounding box returned by GrText
   should not be clipped. */
         if( lj[0] == 'U' ) {
            lj[0] = 'T';   
            bbclip = 0;
      
         } else if( lj[0] == 'D' ) {
            lj[0] = 'B';   
            bbclip = 0;
      
         } else {
            bbclip = 1;
         }

/* Get the bounding box enclosing the text produced if the bottom left corner 
   of the bounding box is placed at the supplied reference position. This box 
   is clipped to exclude super-scripts and sub-scripts if "bbclip" is
   non-zero. */
         ret = GrText( this, esc, text, 0, bbclip, x, y, upx, upy, xbn, ybn, 
                       method, class );
         if( ret ) {

/* Find the position of the bottom left corner of the bounding box which
   produces the required justification. */
            if( lj[0] == 'C' ) {
               x += 0.5*( xbn[0] - xbn[3] );
               y += 0.5*( ybn[0] - ybn[3] );
   
            } else if( lj[0] == 'T' ) {
               x += xbn[0] - xbn[3];
               y += ybn[0] - ybn[3];
            }
   
            if( lj[1] == 'C' ) {
               x += 0.5*( xbn[0] - xbn[1] );
               y += 0.5*( ybn[0] - ybn[1] );

            } else if( lj[1] == 'R' ) {
               x += xbn[0] - xbn[1];
               y += ybn[0] - ybn[1];
            }

/* Draw the text putting the bottom left corner of the bounding box at the
   modified reference position. */
            ret = GrText( this, esc, text, 1, 1, x, y, upx, upy, xbn, ybn, 
                          method, class );
         }
      }
   }

/* Return the status. */
   return ret;

}
#endif

static void DrawTicks( AstPlot *this, TickInfo **grid, int drawgrid, 
                       double *labelat, double *gap, const char *method, 
                       const char *class ){
/*
*
*  Name:
*     DrawTicks

*  Purpose:
*     Draw tick marks for a 2-D annotated coordinate grid.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void DrawTicks( AstPlot *this, TickInfo **grid, int drawgrid, 
*                     double *labelat, double *gap, const char *method, 
*                     const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function draws major and minot tick marks. It uses a different
*     technique depending on whether the tick marks are to be put along the
*     edges of the plotting area, or along a curve through the middle of the
*     plotting area. The physical axis values at which to put tick marks
*     are supplied in parameter "grid".
*
*     If the ticks are placed on the edges of the plotting area, The
*     EdgeCrossings function is used to find all points along the edge which
*     have a physical axis value correspoinding to a tick value (there can in 
*     general be more than one point on an edge with a given physical axis 
*     value). Ticks are put at all such crossings.
*
*     If ticks are placed within the plotting area, then they are put
*     along a curve defined by the "other axis" values supplied in
*     parameter "labelat".

*  Parameters:
*     this
*        A pointer to the Plot.
*     grid
*        A pointer to an array of two TickInfo pointers (one for each axis), 
*        each pointing to a TickInfo structure holding information about
*        tick marks on the axis. See function GridLines.
*     drawgrid
*        If non-zero, then a grid of curves has been drawn to mark the
*        major axis values.
*     labelat
*        A pointer to a 2 element array in holding the constant axis 
*        values at which tick marks are to be put. Element 0 should hold
*        the axis 1 value at which tick marks for axis 0 are placed. Element 
*        1 should hold the axis 0 value at which tick marks for axis 
*        1 are placed. If ticks are to be placed round the edges of the
*        plotting zone instead of within the plotting zone, then values of
*        AST__BAD should be supplied.
*     gap
*        Pointer to array of two values holding the gap between major
*        tick marks on the two axes.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Notes:
*     -  This function assumes the current Frame of the Plot is 2
*     dimensional, and it should not be called if this is not the case. 
*/

/* Local Variables: */
   AstFrame *frame;       /* Pointer to current Frame in Plot */
   AstMapping *mapping;   /* Pointer to graphics->physical Mapping */
   AstPointSet *pset1;    /* Pointer to PointSet holding physical coords. */
   AstPointSet *pset2;    /* Pointer to PointSet holding graphics coords. */
   AstPointSet *pset3;    /* Pointer to PointSet holding clipped graphics coords. */
   TickInfo *info;        /* Pointer to the TickInfo for the current axis */
   double *axother;       /* Pointer to normalised value for the other axis */
   double *axthis;        /* Pointer to normalised value for the requested axis */
   double *ptr1[2];       /* Pointer to physical data */
   double **ptr2;         /* Pointer to graphics data */
   double **ptr3;         /* Pointer to clipped graphics data */
   double *a;             /* Pointer to next current axis value */
   double *b;             /* Pointer to next other axis value */
   double *value;         /* Current tick value */
   double *x;             /* Pointer to next X value */
   double *xc;            /* Pointer to next clipped X value */
   double *y;             /* Pointer to next Y value */
   double *yc;            /* Pointer to next clipped Y value */
   double a0;             /* Physical axis value at base of tick */
   double delta;          /* Increment along current axis between minor ticks */
   double dl2;            /* Squared increment between points */
   double dl2_limit;      /* Minimum usable squared increment between points */
   double dl;             /* Increment between points */
   double dx;             /* X component of increment along tick mark */
   double dy;             /* Y component of increment along tick mark */
   double ex;             /* X component of increment between points */
   double ey;             /* Y component of increment between points */
   double lblat2;         /* Other axis value part way up each tick */
   double lblat;          /* Other axis value at base of each tick */
   double mindim;         /* Shortest dimension of plotting area */
   double minval;         /* Current axis value at next minor tick */
   double mjsign;         /* Sign of the major tick mark length */
   double mjtklen;        /* Length of major tick marks */
   double mnsign;         /* Sign of the minor tick mark length */
   double mntklen;        /* Length of minor tick marks */
   double ux;             /* X component of unit vector along tick mark */
   double uy;             /* Y component of unit vector along tick mark */
   double val[2];         /* Normalised axis values at minor tick mark */
   double x0;             /* X at base of tick */
   double x1;             /* X at end of tick */
   double x2;             /* Clipped X at base of tick */
   double y0;             /* Y at base of tick */
   double y1;             /* Y at end of tick */
   double y2;             /* Clipped Y at base of tick */
   int *majflag;          /* Pointer to next major/minor flag */
   int *majflags;         /* Pointer to aray of major/minor flags */
   int axis;              /* Current axis index */
   int ed;                /* Doing a secondary edge? */
   int edge;              /* Index of edge being ticked */
   int first;             /* Is this the first tick to be drawn? */
   int i;                 /* Minor tick mark index */
   int major;             /* Are major tick marks required? */
   int minhi;             /* Highest minor tick mark index */
   int minlo;             /* Lowest minor tick mark index */
   int minor;             /* Are minor tick marks required? */
   int nedge;             /* No. of edges to be ticked for each axis */
   int nel;               /* Actual number of tick marks to draw */
   int ntot;              /* Maximum number of tick marks */
   int tick;              /* Tick index */

/* Check the global status. */
   if( !astOK ) return;

/* Get the minimum dimension of the plotting ares. */
   mindim = MIN( this->xhi - this->xlo, this->yhi - this->ylo );

/* Establish the correct graphical attributes as defined by attributes
   with the supplied Plot. */
   GrfAttrs( this, TICKS_ID, 1, GRF__LINE );

/* If ticks are to be put round the edges of the plotting area... */
/* ============================================================== */
   if( labelat[ 0 ] == AST__BAD || labelat[ 1 ] == AST__BAD ){

/* Store the number of edges to be ticked for each axis. */
      nedge = astGetTickAll( this )? 2 : 1;

/* Do each required edge. */
      for( ed = 0; ed < nedge; ed++ ){

/* Do each axis. */
         for( axis = 0; axis < 2; axis++ ){

/* Store the length in graphics coordinates of major tick marks for this
   axis. Use a default of zero if a grid has been drawn. */
            if( astTestMajTickLen( this, axis ) || !drawgrid ){
               mjtklen = astGetMajTickLen( this, axis )*mindim;
            } else {
               mjtklen = 0.0;
            }

/* See if major tick marks are required. This is the case if the length of 
   major tick marks is not zero. */
            major = ( mjtklen != 0.0 );

/* Store the length in graphics coordinates of minor tick marks. */
            mntklen = astGetMinTickLen( this, axis )*mindim;

/* If the minor tick marks are of zero length, don't draw them. */
            minor = ( mntklen != 0.0 );

/* Get the edge to be labelled with the axis values. Edge 0 is the left hand 
   edge. Edge 1 is the top edge. Edge 2 is the right-hand edge. Edge 3 is 
   the bottom edge. */
            edge = ( astGetEdge( this, axis ) + ed*2 ) % 4;
            if( edge < 0 ) edge = -edge;

/* Store a pointer to the structure containing information describing the 
   positions of the major tick marks along this axis. */  
            info = grid[ axis ];

/* Store a pointer to the axis value at the first major tick mark. */
            value = info->ticks;

/* Minor tick marks are drawn on both sides of each major tick mark. They
   are identified by an index number relative to major tick mark at zero. 
   Store the indicies of the first and last minor tick marks. */
            minlo = ( 1 - info->nminor )/2;
            minhi = info->nminor/2;

/* Store the gap between minor tick marks. */
            delta = gap[ axis ]/(double)info->nminor;

/* Loop round until all ticks have been done. */
            for( tick = 0; tick < info->nmajor; tick++ ){

/* If ticks are being put at major tick values, draw tick marks at
   all occurrences of the current major tick value on the selected edge
   of the plotting area. */
               if( major ) Ticker( this, edge, axis, *value, gap, mjtklen,
                                   method, class );

/* If ticks are being put at minor tick values... */
               if( minor ){

/* Store the axis value at the first minor tick mark. */
                  minval = *value + minlo*delta;

/* Loop round all the minor tick marks, storing the physical coordinates
   defining the tick mark. */
                  for( i = minlo; i <= minhi; i++ ){

/* Draw tick marks at all occurrences of the current minor tick value on
   the selected edge of th eplotting area. Do not do the minor tick mark 
   with index zero, since this corresponds to the position of the major 
   tick mark. */
                     if( i ) Ticker( this, edge, axis, minval, gap, mntklen,
                                   method, class );

/* Get the axis value at the next minor tick mark. */
                     minval += delta;
   
                  }

               }
  
/* Point to the next major tick value. */
               value++;

            }

         } 

      }

/* Free the static resources allocated within EdgeCrossings (called
   by Ticker). */
      (void) EdgeCrossings( NULL, 0, 0, 0.0, NULL, NULL, method, class );

/* If ticks are to put within the interior of the plotting area... */
/* ============================================================== */
   } else {

/* Get the mapping from base Frame (graphics coords) to current Frame
   (physical coords). */
      mapping = astGetMapping( this, AST__BASE, AST__CURRENT );

/* Get the current Frame from the Plot. */
      frame = astGetFrame( this, AST__CURRENT );

/* Do each axis. */
      for( axis = 0; axis < 2; axis++ ){

/* Store the length in graphics coordinates of major tick marks for this
   axis. Use a default of zero if a grid has been drawn. */
         if( astTestMajTickLen( this, axis ) || !drawgrid ){
            mjtklen = astGetMajTickLen( this, axis )*mindim;
         } else {
            mjtklen = 0.0;
         }

/* See if major tick marks are required. This is the case if the length of 
   major tick marks is not zero. */
         major = ( mjtklen != 0.0 );

/* Store the length in graphics coordinates of minor tick marks. */
         mntklen = astGetMinTickLen( this, axis )*mindim;

/* If the minor tick marks are of zero length, don't draw them. */
         minor = ( mntklen != 0.0 );

/* Indicate that the tick mark lengths should not be negatated. */
         mjsign = 1.0;
         mnsign = 1.0;

/* Store the smallest squared distance in graphics coordinates which 
   can reliably be used to determine the direction of a tick mark. */
         dl2_limit = 0.0001*mindim;
         dl2_limit *= dl2_limit;

/* Store pointers to the places where normalised physical coordinates are
   stored. */
         axthis = val + axis;    
         axother = val + 1 - axis;    

/* Store a pointer to the structure containing information describing the 
   positions of the major tick marks along this axis. */  
         info = grid[ axis ];

/* Store a pointer to the axis value at the first major tick mark. */
         value = info->ticks;

/* Get the maximum number of tick marks to be drawn on this axis. */
         ntot = 0;
         if( major ) ntot = info->nmajor;
         if( minor ) ntot += info->nmajor*( info->nminor - 1 );

/* Break out of the loop to do the next axis if no ticks are to be drawn. */
         if( !ntot ) break;

/* Allocate memory to hold the physical coordinates defining all the
   required tick marks. Each tick mark is defined by 2 points. */
         ptr1[ 0 ] = (double *) astMalloc( sizeof(double)*(size_t)(2*ntot) );
         ptr1[ 1 ] = (double *) astMalloc( sizeof(double)*(size_t)(2*ntot) );

/* Allocate memory to hold a set of flags indicating whether each tick
   mark is minor or major. */
         majflags = (int *) astMalloc( sizeof(int)*(size_t)ntot );

/* Check the pointers can be used. */
         if( astOK ){

/* Store pointers to the next point on each axis. "a" always refers to the
   current axis. Also store the value on the other axis at which the tick
   marks starts, and another value on the other axis which is used to
   defined the tick mark directions. Also store the increment in axis
   value between minor tick marks. */
            a = ptr1[ axis ];    
            b = ptr1[ 1 - axis ];    
            majflag = majflags;
            lblat = labelat[ axis ];
            lblat2 = labelat[ axis ] + 0.2*gap[ 1 - axis ];
            delta = gap[ axis  ]/(double)info->nminor;

/* Store the indicies of the first and last minor tick marks, relative to
   a major tick mark. */
            minlo = 1;
            minhi = info->nminor - 1;

/* Loop round until all ticks have been done. */
            for( tick = 0; tick < info->nmajor; tick++ ){

/* If major tick marks are required, store the physical coordinates at the 
   start of the major tick mark, and at a point a little way up the major 
   tick mark. */
               if( major ){
                  *(a++) = *value;
                  *(b++) = lblat;
                  *(a++) = *value;
                  *(b++) = lblat2;
                  *(majflag++) = 1;
               }

/* If minor tick marks are required, store the points defining the minor tick 
   marks on either side of this major tick mark. */
               if( minor ){

/* Store the axis value at the first minor tick mark. */
                  minval = *value + minlo*delta;

/* Loop round all the minor tick marks, storing the physical coordinates
   defining the tick mark. */
                  for( i = minlo; i <= minhi; i++ ){

/* Normalise the tick mark position. */
                  *axthis = minval;
                  *axother = lblat;
                  astNorm( frame, val );

/* Do not do the minor tick mark with index zero, since this corresponds
   to the position of the major tick mark. Also, do not do any minor tick
   mark which is not within the normal ranges of both axes. */
                     if( i && EQUAL( *axthis, minval ) && 
                              EQUAL( *axother, lblat ) ){
                        *(a++) = minval;
                        *(b++) = lblat;
                        *(a++) = minval;
                        *(b++) = lblat2;
                        *(majflag++) = 0;
                     }

/* Get the axis value at the next minor tick mark. */
                     minval += delta;
   
                  }

               } 

/* Point to the next major tick value. */
               value++;

            }

         }

/* Adjust the size of the arrays to exclude any unused space. */
         nel = a - ptr1[axis];
         ptr1[axis] = (double *) astRealloc( (void *) ptr1[axis], 
                                             sizeof(double)*nel );
         ptr1[1-axis] = (double *) astRealloc( (void *) ptr1[1-axis], 
                                               sizeof(double)*nel );

/* Create a pointset holding these coordinates. */
         pset1 = astPointSet( nel, 2, "" );
         astSetPoints( pset1, ptr1 );

/* Transform these physical coordinates into graphics coordinates, without
   doing any clipping (this is so that tick marks are still drawn even if
   they extend into the area containing clipped physical coordinates). */
         pset2 = astTransform( mapping, pset1, 0, NULL );
         ptr2 = astGetPoints( pset2 );

/* Transform them again this time with clipping. */
         pset3 = Trans( this, NULL, mapping, pset1, 0, NULL, 0, method, class );
         ptr3 = astGetPoints( pset3 );

/* Check the pointers can be used.*/
         if( astOK ){

/* Store pointers to the next point on each axis. */
            a = ptr1[ axis ];

            x = ptr2[ 0 ];    
            y = ptr2[ 1 ];    

            xc = ptr3[ 0 ];    
            yc = ptr3[ 1 ];    

            majflag = majflags;

/* Loop round all ticks (major and minor). */
            ux = AST__BAD;
            first = 1;
            for( tick = 0; tick < nel/2; tick++ ){

/* Store the physical axis value at the base of the tick mark (skip over
   the physical axis value at the point up the tick mark). */
               a0 = *(a++);
               a++;

/* Store the x and y coordinates at the base of the tick mark. */
               x0 = *(x++);
               y0 = *(y++);

/* Store the x and y coordinates at a point up the tick mark. */
               x1 = *(x++);
               y1 = *(y++);

/* Store the clipped x and y coordinates at the base of the tick mark. */
               x2 = *(xc++);
               y2 = *(yc++);

/* Skip over the clipped x and y coordinates at the point up the tick mark. */
               xc++;
               yc++;

/* Check they are all valid, and that the start of the tick mark is within
   the plotting area. */
               if( x0 != AST__BAD && y0 != AST__BAD &&
                   x1 != AST__BAD && y1 != AST__BAD &&
                   x2 != AST__BAD && y2 != AST__BAD &&
                   x0 <= this->xhi && x0 >= this->xlo &&
                   y0 <= this->yhi && y0 >= this->ylo ){

/* Get the increments in X and Y beyween the two points, and the squared
   distance between the two points. */
                  dx = x1 - x0;
                  dy = y1 - y0;
                  dl2 = dx*dx + dy*dy;

/* Check the two points are not co-incident. */
                  if( dl2 > dl2_limit ){

/* Store the distance between the two points. */
                     dl = sqrt( dl2 );

/* If this is the first tick to be drawn on this axis, decide which
   direction to draw the tick mark so that they will appear on the right
   hand side of the axis as seen by someone moving along the axis in the
   positive direction (the numerical labels are also drawn on the same 
   side). */
                     if( first ){
                        first = 0;

/* If the next tick mark is not defined, make an arbitrary decision by
   leaving the sign of the tick mark length unchanged. */
                        if( tick + 1 < nel/2 && 
                            *x != AST__BAD && *y != AST__BAD &&
                            a0 != AST__BAD && *a != AST__BAD ){

/* Form the vector joining this tick mark to the next. */
                            ex = *x - x0;
                            ey = *y - y0;

/* Ensure this vector is in the positive direction of the axis. */
                            if( *a < a0 ) {
                               ex = -ex;
                               ey = -ey;
                            }

/* If a positive tick mark length would put the marks on the wrong side, 
   negate the tick mark length. */
                            if( ex*dy > ey*dx ){
                               mjsign = -1.0;
                               mnsign = -1.0;
                            }
                        }
                     }

/* Store the unit vector in the direction of the tick mark. This is used
   as the default vector for the next tick mark if the direction of the 
   next tick mark is indeterminate. */
                     ux = dx/dl;
                     uy = dy/dl;

                  }

/* Only draw this tickmark if its direction is known. */
                  if( ux != AST__BAD ) {

/* Get the position of the end of the tick mark. The length of the tick
   mark depends on whether it is a major or minor tick mark. */
                     if( *majflag ){
                        x1 = x0 + mjsign*mjtklen*ux;
                        y1 = y0 + mjsign*mjtklen*uy;
                     } else {
                        x1 = x0 + mnsign*mntklen*ux;
                        y1 = y0 + mnsign*mntklen*uy;
                     }

/* Draw the tick mark. */
                     Bpoly( (float) x0, (float) y0, method, class );
                     Apoly( (float) x1, (float) y1, method, class );
                     Opoly( method, class );

                  }

               }

/* Point to the next major/minor flag. */
               majflag++;

            }

         }

/* Free the memory holding the physical coordinates. */
         ptr1[ 0 ] = (double *) astFree( ( void *) ptr1[ 0 ] );
         ptr1[ 1 ] = (double *) astFree( ( void *) ptr1[ 1 ] );
         majflags = (int *) astFree( (void *) majflags );

/* Annul the PointSets. */
         pset1 = astAnnul( pset1 );
         pset2 = astAnnul( pset2 );

      }

/* Annul the pointers to the Mapping and Frame. */
      mapping = astAnnul( mapping );
      frame = astAnnul( frame );

   }

/* Re-establish the original graphical attributes. */
   GrfAttrs( this, TICKS_ID, 0, GRF__LINE );

/* Return. */
   return;

}

static int EdgeLabels( AstPlot *this, int ink, TickInfo **grid, 
                       CurveData **cdata, const char *method, 
                       const char *class ){
/*
*
*  Name:
*     EdgeLabels

*  Purpose:
*     Attempts to display labels for the major tick values around the edges 
*     of the plotting area.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int EdgeLabels( AstPlot *this, int ink, TickInfo **grid, 
*                     CurveData **cdata, const char *method, 
*                     const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function determines how many major tick value labels could be 
*     placed on the specified edges of the plotting area, and then if
*     requested, and if sufficient such labels are found (more than 3 on 
*     each axis), they are drawn . To place a label on an edge, the curve 
*     defining the major tick value must cross the edge at a reasonably 
*     angle (at least 3 degrees). Labels are not drawn which would overlap 
*     other, previously drawn, labels. A flag is returned indicating if 
*     edge labels were (or could be) drawn.

*  Parameters:
*     this
*        A pointer to the Plot.
*     ink
*        If zero, then no labels are drawn, but the decision whether or
*        not to draw them is still made and indicated in the returned function 
*        value.
*     grid
*        A pointer to an array of two TickInfo pointers (one for each axis), 
*        each pointing to a TickInfo structure holding information about
*        tick marks on the axis. See function GridLines.
*     cdata
*        A pointer to an array of two CurveData pointers (one for each axis), 
*        each pointing to an array of CurveData structure (one for each
*        major tick value on the axis), holding information about breaks
*        in the curves drawn to mark the major tick values. See function 
*        DrawGrid. 
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     If edge labels were drawn, 1 is returned. Otherwise 0 is returned.

*  Notes:
*     -  Zero is returned if an error has already occurred.
*/


/* Local Variables: */
   AstFrame *frame;       /* Pointer to current Frame */
   CurveData *cdt;        /* Pointer to the CurveData for the next tick */
   LabelList *labellist;  /* Pointer to a ingle list of labels to be plotted */
   LabelList *llist[2];   /* Pointers to both lists of labels to be plotted */
   LabelList *ll;         /* Pointer to next label to be plotted */
   TickInfo *info;        /* Pointer to the TickInfo for the current axis */
   const char *just[ 2 ]; /* Justification string */
   const char *text;      /* Pointer to label text */
   double edgeval;        /* Axis value at the labelled edge */
   double mindim;         /* Minimum dimension of the plotting area */
   double oppval;         /* Axis value on the edge opposite to the labels */
   double tol;            /* Max. distance between a break and the edge */
   double txtgap;         /* Absolute gap between labels and edges */
   float *box;            /* Pointer to array of label bounding boxes */
   float *vxbrk;          /* X component of unit vector at current break */
   float *vybrk;          /* Y component of unit vector at current break */
   float *xbrk;           /* X coord. of current break */
   float *ybrk;           /* Y coord. of current break */
   float xref;            /* X coordinate at label's reference position */
   float yref;            /* Y coordinate at label's reference position */
   int axis;              /* Current axis index */
   int brk;               /* Current break index */
   int edge;              /* The edge to be labelled */
   int edgeax;            /* Index of axis parallel to the labelled edge */
   int edgelabs;          /* Can edge labels be produced? */
   int naxlab;            /* Number of edge labels */
   int near;              /* Draw a label on the near edge? */
   int nedge[2];          /* No. of edge labels for each axis */
   int tick;              /* Tick index */

/* Check the global status. */
   if( !astOK ) return 0;

/* Initialise the returned flag to indicate that edge labels cannot be 
   produced. */
   edgelabs = 0;

/* Get the minimum dimension of the plotting ares. */
   mindim = MIN( this->xhi - this->xlo, this->yhi - this->ylo );

/* Set up the tolerance for curve breaks occuring on an edge of 
   the plotting zone. */
   tol = 0.0005*mindim;

/* First, we get a list of all the labels which can be produced on each
   axis. The list includes the labels reference position in graphics
   coordinates, and the index of the major tick value which it
   represents. We do not yet know whether enough of the grid lines cross
   the required edge to make it feasable to use edge labelling, so we do
   not yet draw the labels.
   =====================================================================*/

/* Initialise pointers to arrays of structures holding information
   about the labels which can be draw round the edge for both axes. */
   llist[ 0 ] = NULL;
   llist[ 1 ] = NULL;

/* indicate that no labels can yet be drawn on either axis. */
   nedge[ 0 ] = 0;
   nedge[ 1 ] = 0;

/* For each axis, identify the the usable edge labels. */
   for( axis = 0; axis < 2; axis++ ){

/* Store the required gap between the label text and the axis. */
      txtgap = astGetNumLabGap( this, axis )*mindim;

/* Get the edge to be labelled with the axis values. Edge 0 is the left hand 
   edge. Edge 1 is the top edge. Edge 2 is the right-hand edge. Edge 3 is 
   the bottom edge. */
      edge = astGetEdge( this, axis ) % 4;
      if( edge < 0 ) edge = -edge;

/* If edge labels for the current axis are to go on the left hand edge of
   the plotting area... */
      if( edge == 0 ){

/* Choose the justification based on the sign of the text gap. */
         if( txtgap > 0.0 ){
            just[ axis ] = "CR";
         } else if( txtgap < 0.0 ){
            just[ axis ] = "CL";
         } else {
            just[ axis ] = "CC";
         }

/* Store the constant X axis value at the edge being labelled. Also store
   the X value to use for the reference position for all labels. Take into
   account whether or not the X axis is displayed reversed (i.e. with high
   X values at the left hand side of the screen ). */
         if( !this->xrev ){
            edgeval = this->xlo;
            oppval = this->xhi;
            xref = (float)( edgeval - txtgap );
         } else {
            edgeval = this->xhi;
            oppval = this->xlo;
            xref = (float)( edgeval + txtgap );
         }

/* Indicate that the "edgeval" value refers to axis 1 (the X axis). */
         edgeax = 1;
         
/* Do the same if the labels are to go on the top edge. */
      } else if( edge == 1 ){
         if( txtgap > 0.0 ){
            just[ axis ] = "BC";
         } else if( txtgap < 0.0 ){
            just[ axis ] = "TC";
         } else {
            just[ axis ] = "CC";
         }

         if( !this->yrev ){
            edgeval = this->yhi;
            oppval = this->ylo;
            yref = (float)( edgeval + txtgap );
         } else {
            edgeval = this->ylo;
            oppval = this->yhi;
            yref = (float)( edgeval - txtgap );
         }

         edgeax = 0;
         
/* Do the same if the labels are to go on the right-hand edge. */
      } else if( edge == 2 ){
         if( txtgap > 0.0 ){
            just[ axis ] = "CL";
         } else if( txtgap < 0.0 ){
            just[ axis ] = "CR";
         } else {
            just[ axis ] = "CC";
         }

         if( !this->xrev ){
            edgeval = this->xhi;
            oppval = this->xlo;
            xref = (float)( edgeval + txtgap );
         } else {
            edgeval = this->xlo;
            oppval = this->xhi;
            xref = (float)( edgeval - txtgap );
         }

         edgeax = 1;

/* Do the same if the labels are to go on the bottom edge. */
      } else {
         if( txtgap > 0.0 ){
            just[ axis ] = "TC";
         } else if( txtgap < 0.0 ){
            just[ axis ] = "BC";
         } else {
            just[ axis ] = "CC";
         }

         if( !this->yrev ){
            edgeval = this->ylo;
            oppval = this->yhi;
            yref = (float)( edgeval - txtgap );
         } else {
            edgeval = this->yhi;
            oppval = this->ylo;
            yref = (float)( edgeval + txtgap );
         }

         edgeax = 0;

      }

/* Get a pointer to the structure containing information describing the 
   positions of the major tick marks along this axis. */  
      info = grid[ axis ];

/* Get a pointer to the structure containing information describing the 
   breaks in the curve which is parallel to the other axis and passes 
   through the first major tick mark. */
      cdt = cdata[ axis ];

/* Initialise the pointer to the list of text strings to be drawn. */
      labellist = NULL;

/* Initialise the number of labels which can be placed on the near edge of 
   the plotting zone. */
      naxlab = 0;
 
/* Loop round each of the major tick marks on the current axis. */
      for( tick = 0; cdt && info && tick < info->nmajor; tick++ ){

/* Store pointers to the values giving the position and unit direction 
   vector of the curve at the first break. */
         xbrk = cdt->xbrk;
         ybrk = cdt->ybrk;
         vxbrk = cdt->vxbrk;
         vybrk = cdt->vybrk;

/* Loop round each of the breaks in the curve which passes through the 
   current major tick mark, and is parallel to the other axis. */
         for( brk = 0; brk < cdt->nbrk; brk++ ){

/* A label can be produced on the near edge of the plotting zone if the 
   current break occurs on, or close to, the edge, and the curve is not 
   nearly parallel to the axis. */
            near = ( ( edgeax == 0 && 
                       fabs( (double) *ybrk - edgeval ) < tol &&
                       fabs( (double) *vybrk ) > 0.05 ) || 
                     ( edgeax == 1 && 
                       fabs( (double) *xbrk - edgeval ) < tol &&
                       fabs( (double) *vxbrk ) > 0.05 ) );


/* Get the label text. */
            if( info->labels ) {
               text = (info->labels)[ tick ];
            } else {
               text = NULL;
            }

/* If a label can be produced, record the information needed to draw the 
   label. */
            if( near && text ){ 

               labellist = (LabelList *) astGrow( (void *) labellist, naxlab + 1, sizeof(LabelList) );
               if ( !astOK ) break;

               if( edgeax == 0 ){
                  (labellist + naxlab)->index = (double) *xbrk;
                  (labellist + naxlab)->x = (double) *xbrk;
                  (labellist + naxlab)->y = (double) yref;
               } else {
                  (labellist + naxlab)->index = (double) *ybrk;
                  (labellist + naxlab)->x = (double) xref;
                  (labellist + naxlab)->y = (double) *ybrk;
               }

               (labellist + naxlab)->text = (char *) astStore( NULL, (void *) text, strlen(text) + 1 );
               (labellist + naxlab)->just = (char *) astStore( NULL, (void *) just[ axis ], strlen(just[ axis ]) + 1 );
               (labellist + naxlab)->upx = 0.0;
               (labellist + naxlab)->upy = 1.0;
               (labellist + naxlab)->val = (info->ticks)[ tick ];
               naxlab++;

            }

/* Increment the pointers to the values giving the position and unit direction 
   vector of the next break. */
            xbrk++;
            ybrk++;
            vxbrk++;
            vybrk++;

         }
            
/* If an error has occurred, break out of the loop. */
         if( !astOK ) break;

/* Get a pointer to the curve through the next major tick mark. */
         cdt++;
            
      }

/* If an error has occurred, break out of the loop. */
      if( !astOK ) break;

/* Store the number of labels for this axis, and the pointer to the
   drawable labels. */
      nedge[ axis ] = naxlab;
      llist[ axis ] = labellist;
   }

/* We now know how many labels would be produced on each axis if edge
   labelling were to be used. We also know what those labelled values are,
   and where the labels would be drawn. We now take the decision as to
   whether there are enough of these labels to make edge labelling
   feasable. If so, we carry on and draw the labels. There need to be 
   at least 3 labels on each axis...
   ================================================================= */   
   if( astOK && nedge[ 0 ] > 2 && nedge[ 1 ] > 2 ){

/* Set the returned flag to indicate that edge labelling is being used. */
      edgelabs = 1;

/* Initialise the pointer to the memory holding the bounding boxes for 
   all labels (used by function Overlap). */
      box = NULL;

/* Get a pointer to the current Frame in the Plot. */
      frame = astGetFrame( this, AST__CURRENT );

/* If required, draw the labels for each axis in turn. */
      for( axis = 0; axis < 2 && ink; axis++ ){
         info = grid[ axis ];
         PlotLabels( this, frame, axis, llist[ axis ], info->fmt, 
                     nedge[ axis ], &box, method, class );
      }

/* Free the memory used to hold the bounding boxes. */
      box = (float *) astFree( (void *) box );

/* Annul the pointer to the Frame. */
      frame = astAnnul( frame );
   }

/* Free the memory used to store the label information. */
   for( axis = 0; axis < 2; axis++ ){
      ll = llist[ axis ];
      if( ll ) {
         for( tick = 0; tick < nedge[ axis ]; tick ++ ) {
            ll->text = (char *) astFree( (void *) ll->text );
            ll->just = (char *) astFree( (void *) ll->just );
            ll++;
         }
         llist[ axis ] = (LabelList *) astFree( (void *) llist[ axis ] );
      }
   }

/* Return the flag indicating if edge labels were produced. */
   return edgelabs;

}

static int EdgeCrossings( AstPlot *this, int edge, int axis, double axval, 
                          double *gap, double **cross, const char *method, 
                          const char *class ){
/*
*
*  Name:
*     EdgeCrossings

*  Purpose:
*     Find all occurrences of a given physical axis value on an edge of the
*     plotting area.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int EdgeCrossings( AstPlot *this, int edge, int axis, double axval, 
*                        double *gap, double **cross, const char *method, 
*                        const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function finds all occurences of a given physical axis value
*     along a specified edge of the plotting area. Firstly, a set of evenly
*     spaced points ("edge samples") are placed along the edge and the 
*     corresponding physical coordinates are found. These physical coordinates 
*     are then offset slightly from their original positions in the direction
*     of the "other" axis (i.e. index [ 1 - axis ] ), and transformned back
*     into graphics coordinates. These coordinates give the tangent vector
*     at each of the edge samples.
*
*     To find the crossings, the supplied axis value is compared with the axis 
*     value at each sample in turn, starting from one end of the edge and
*     working through to the other end. When a crossing is found, linear
*     interpolation is used between the two adjacent edge samples to find a
*     more accurate estimate of the crossing. The vector at the crossing
*     is also estimated by linear interpolation between the vectors at the two
*     adjacent samples.
*
*     This basic algorithm fails if there is a discontinuity in the axis
*     values along the edge. For instance, if the edge covers a range of
*     Right Ascension from 23h to 1h, there will be a discontinuity at 0h
*     at which the RA values suddenly jump from 2*PI to zero. This jump
*     encompasses all normalised RA values and so every axis value would be 
*     given a crossing at this point. To avoid this, a bad sample is
*     interposed between the two samples on either side of the
*     discontinuity. This prevents any crossings from being placed at the
*     discontinuity.
*
*     There is a second problem related to discontinuities. If the supplied
*     axis value is zero (using the above RA example again), then no
*     crossings will be found, not only because of the extra bad sample,
*     but also because the samples will not quite cover the range of axis
*     values covered by the discontinuity because of the discrete nature
*     of the samples). To get round this, the sections on either side 
*     of the discontinity are extended by a single sample. These extra
*     samples are assumed to be conincident with the neighbouring sample,
*     except that the value for the searched axis is modified to be a
*     linear extension from the neighbouring samples.


*  Parameters:
*     this
*        A pointer to the Plot.
*     edge
*        The edge of the plotting area to be used. Edge 0 is the left hand 
*        edge. Edge 1 is the top edge. Edge 2 is the right-hand edge. Edge 3 
*        is the bottom edge. 
*     axis
*        The index of the axis to which "axval" refers. 
*     axval
*        The physical axis value to be searched for.
*     gap
*        Pointer to array of two values holding the gap between major
*        tick marks on the two axes.
*     cross
*        A pointer to the location at which to return a pointer to an
*        array of doubles holding the crossing information. Each crossing
*        is described by 4 doubles. The first pair are the graphiucs (x,y)
*        coordinates of the point on the edge at which the crossing occurs.
*        The second pair represents a unit vector in graphics coordinates
*        which is tangential to the curve of constant axis value at the
*        crossing. The memory allocated within this function to hold this
*        data should be freed using astFree when no longer needed. If no
*        crossings are found a NULL pointer is returned.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Return Value:
*     The number of crossings found.

*  Notes:
*     -  This function allocates static resource on the first invocation
*     which should be freed when no more calls are to be made, by making a 
*     final call with a NULL pointer supplied for "this". All other parameters 
*     are then ignored.
*     -  The static resources are re-initialised each time "edge" or
*     "axis" changes, and so the calling function should be structure in
*     order to minimise the number of times these parameter values change.
*     -  If an error has already occurred, or if this function should
*     fail for any reason, zero is returned, and a NULL pointer is stored at
*     "cross".

*/

/* Local Variables: */
   static AstFrame *frame = NULL;   /* Pointer to current Frame in Plot */
   static AstPointSet *pset1 = NULL;/* Graphics cooords at edge samples */
   static AstPointSet *pset2 = NULL;/* Physical cooords at edge samples */
   static AstPointSet *pset4 = NULL;/* Graphics cooords at offset edge samples */
   static double **ptr1 = NULL;     /* Pointer to graphics coord. data */
   static double **ptr2 = NULL;     /* Pointer to physical coord. data */
   static double **ptr4 = NULL;     /* Pointer to graphics coord. data */
   static double edgehi;            /* High bound on varying graphics axis */
   static double edgelo;            /* Low bound on varying graphics axis */
   static double edgeval;           /* Constant graphics axis value along edge */
   static double limit;             /* Three times the RMS step size */
   static int dim;                  /* Extended number of samples */
   static int edgeax;               /* Graphics axis to which edgeval refers */
   static int paxis = -1;           /* Axis used in first invocation */
   static int pedge = -1;           /* Edge used in first invocation */

   AstMapping *mapping;       /* Pointer to graphics->physical mapping */
   AstPointSet *pset1a;       /* Physical cooords at offset edge samples */
   AstPointSet *pset2a;       /* Physical cooords at offset edge samples */
   AstPointSet *pset3;        /* Physical cooords at offset edge samples */
   AstPointSet *pset4a;       /* Physical cooords at offset edge samples */
   double **ptr1a;            /* Pointer to physical coord. data */
   double **ptr2a;            /* Pointer to physical coord. data */
   double **ptr3;             /* Pointer to physical coord. data */
   double **ptr4a;            /* Pointer to physical coord. data */
   double *axother;           /* Pointer to normalised other physical axis value */
   double *axthis;            /* Pointer to normalised required physical axis value */
   double *data;              /* Pointer to next item of crossing information */
   double *p1;                /* Pointer to graphics axis with constant value */
   double *p1a;               /* Pointer to graphics axis with constant value */
   double *p2;                /* Pointer to graphics axis with varying value */
   double *p2a;               /* Pointer to graphics axis with varying value */
   double *q1;                /* Pointer to physical axis being searched */
   double *q1a;               /* Pointer to physical axis being searched */
   double *q2;                /* Pointer to other physical axis */
   double *q2a;               /* Pointer to other physical axis */
   double *v1;                /* Pointer to vector component on axis 0 */
   double *v2;                /* Pointer to vector component on axis 1 */
   double *v1a;               /* Pointer to vector component on axis 0 */
   double *v2a;               /* Pointer to vector component on axis 1 */
   double dd;                 /* The gap between edge samples */
   double diff;               /* Squared differences between adjacent edge samples */
   double dl2;                /* Squared vector length */
   double dl;                 /* Vector length */
   double dx;                 /* Vector X component */
   double dy;                 /* Vector Y component */
   double f;                  /* Weight for the current edge sample */
   double offset;             /* Physical offset */
   double pp2;                /* Varying graphics axis value at previous sample */
   double pq1;                /* Required physical axis value at previous sample */
   double pv1;                /* Previous vector component on axis 0 */
   double pv2;                /* Previous vector component on axis 1 */
   double sum;                /* Sum of squared differences between adjacent edge samples */
   double val[2];             /* Normalised physical axis values */
   double value;              /* The current graphics axis value */
   double vx;                 /* Vector component on axis 0 at crossing */
   double vy;                 /* Vector component on axis 1 at crossing */
   double z;                  /* Varying graphics axis value at crossing */
   int i;                     /* Edge sample index */
   int iter;                  /* Iteration index */
   int larger;                /* Is current axis value larger than target? */
   int ncross;                /* No. of crossings */
   int ndisc;                 /* No. of discontinuities along the edge */
   int nsum;                  /* Number of values summed in "sum" */
   int plarger;               /* Was previous axis value larger than target? */

/* If a NULL Plot pointer has been supplied, release the static
   resources, and return. */
   if( !this ){
      if( pset1 ) pset1 = astAnnul( pset1 );
      if( pset2 ) pset2 = astAnnul( pset2 );
      if( pset4 ) pset4 = astAnnul( pset4 );
      if( frame ) frame = astAnnul( frame );
      return 0;
   }

/* Initialise the number of crossings found, and the pointer to the place
   to store them. */
   ncross = 0;
   *cross = NULL;

/* Check the global status. */
   if( !astOK ) return 0;

/* Ensure that "edge" is in the range 0 - 3. */
   edge = edge % 4;
   if( edge < 0 ) edge = -edge;

/* If the edge or axis has changed since the last invocation, or if this is 
   the first invocation, initialise some static data. */
/* ======================================================================*/
   if( pedge == -1 || pedge != edge || paxis != axis ){
      pedge = edge;
      paxis = axis;

/* Annull any previous static data objects */
      if( pset1 ) pset1 = astAnnul( pset1 );
      if( pset2 ) pset2 = astAnnul( pset2 );
      if( pset4 ) pset4 = astAnnul( pset4 );
      if( frame ) frame = astAnnul( frame );

/* Store some values so that the code does not need to consider each edge
   separately. First deal with the left hand edge. */
      if( edge == 0 ){
         edgeax = 0;       
         if( this->xrev ){      
            edgeval = this->xhi;
         } else {
            edgeval = this->xlo;
         }
         edgehi = this->yhi;
         edgelo = this->ylo;
 
/* Now deal with the right hand edge. */
      } else if( edge == 2 ){
         edgeax = 0;       
         if( this->xrev ){      
            edgeval = this->xlo;
         } else {
            edgeval = this->xhi;
         }
         edgehi = this->yhi;
         edgelo = this->ylo;

/* Now deal with the bottom edge. */
      } else if( edge == 3 ){
         edgeax = 1;       
         if( this->yrev ){      
            edgeval = this->yhi;
         } else {
            edgeval = this->ylo;
         }
         edgehi = this->xhi;
         edgelo = this->xlo;


/* Finally deal with the top edge. */
      } else {
         edgeax = 1;       
         if( this->yrev ){      
            edgeval = this->ylo;
         } else {
            edgeval = this->yhi;
         }
         edgehi = this->xhi;
         edgelo = this->xlo;

      }

/* Get a pointer to the current Frame in the supplied Plot. */
      frame = astGetFrame( this, AST__CURRENT );

/* Get a pointer to the mapping from base to current Frame in the supplied 
   Plot. */
      mapping = astGetMapping( this, AST__BASE, AST__CURRENT );

/* Create a PointSet to hold the graphics coordinates at a set of
   regularly spaced points along the specified edge of the plotting area. */
      pset1a = astPointSet( EDGETICKS_DIM, 2, "" );
      ptr1a = astGetPoints( pset1a );

/* Create a PointSet to hold the corresponding physical coordinates. */
      pset2a = astPointSet( EDGETICKS_DIM, 2, "" );
      ptr2a = astGetPoints( pset2a );

/* Check they can be used. */
      if( astOK ){

/* Set up the graphics coordinates. */
         dd = ( edgehi - edgelo )/(double)( EDGETICKS_DIM - 1 );
         value = edgelo;
   
         p1 = ptr1a[ edgeax ];
         p2 = ptr1a[ 1 - edgeax ];

         for( i = 0; i < EDGETICKS_DIM; i++ ){
            *(p1++) = edgeval;
            *(p2++) = value;
            value += dd;
         }
      }

/* Transform the graphics coordinates to physical coordinates,
   normalising them into their normal ranges. */
      (void) Trans( this, frame, mapping, pset1a, 1, pset2a, 1, method, class );

/* Find the RMS step size along the axis. This is used to locate
   discontinuities along the edge.  Do three rejection iterations. */
      limit = DBL_MAX;
      for( iter = 0; iter < 3; iter ++ ){
         q1 = ptr2a[ axis ];
         pq1 = AST__BAD;
         sum = 0.0;
         nsum = 0;

         for( i = 0; i < EDGETICKS_DIM; i++ ){
            if( *q1 != AST__BAD && pq1 != AST__BAD ){
               diff = *q1 - pq1;
               if( fabs( diff ) < limit ){   
                  sum += diff*diff;
                  nsum++;
               }
            }
            pq1 = *(q1++);
         }
 
         if( nsum == 0 ) break;
         limit = 3.0*sqrt( sum/(double)nsum );
      }

/* Now create another PointSet holding positions slightly offset from the
   physical coordinates at the edge samples. The offset is in the direction
   of the other physical axis. These positions are used to determine th
   vector at the crossings. */
      if( nsum > 0 ){
         pset3 = astPointSet( EDGETICKS_DIM, 2, "" );
         ptr3 = astGetPoints( pset3 );

/* Create a PointSet to hold the corresponding graphics coordinates. */
         pset4a = astPointSet( EDGETICKS_DIM, 2, "" );
         ptr4a = astGetPoints( pset4a );

/* Check they can be used. */
         if( astOK ){

/* Copy the physical coordinates from PointSet 2 to PointSet 3, offseting
   them slightly along the other axis. */
            p1 = ptr2a[ axis ];
            p2 = ptr2a[ 1 - axis ];

            q1 = ptr3[ axis ];
            q2 = ptr3[ 1 - axis ];

            offset = 0.2*gap[ 1 - axis ];

            pq1 = AST__BAD;

            for( i = 0; i < EDGETICKS_DIM; i++ ){
               if( *p1 != AST__BAD && *p2 != AST__BAD ){
                  *(q2++) = *p2 + offset;
               } else {               
                  *(q2++) = AST__BAD;
               }
               pq1 = *(p1++);
               *(q1++) = pq1;
               p2++;
            }
 
         }

/* Transform the physical coordinates to graphics coordinates. */
         (void) Trans( this, NULL, mapping, pset3, 0, pset4a, 0, method, class );

/* Check they can be used. */
         if( astOK ){

/* Modify the contents of PointSet 4 to represent the unit vector in
   graphics coordinates at each edge sample. */
            p1 = ptr1a[ 0 ];
            p2 = ptr1a[ 1 ];
            q1 = ptr4a[ 0 ];
            q2 = ptr4a[ 1 ];

            for( i = 0; i < EDGETICKS_DIM; i++ ){
               if( *p1 != AST__BAD && *p2 != AST__BAD &&
                   *q1 != AST__BAD && *q2 != AST__BAD ){

                  dx = *q1 - *p1;
                  dy = *q2 - *p2;
                  dl2 = dx*dx + dy*dy;

                  if( dl2 > 0.0 ){
                     dl = sqrt( dl2 );
                     *q1 = dx/dl; 
                     *q2 = dy/dl; 
                  } else {
                     *q1 = AST__BAD;
                     *q2 = AST__BAD;
                  }

               } else {
                  *q1 = AST__BAD;
                  *q2 = AST__BAD;
               }
   
               p1++;
               p2++;
               q1++;
               q2++;

            }
 
         }
 
/* Annul the PointSet holding offset physical cooridnates. */
         pset3 = astAnnul( pset3 );      

/* Discontinuities in the axis values can cause problems. For instance,
   using the above PointSets, no tick mark could be put at 0 hours RA
   because of the discontinuity there. To get round this, 3 extra samples
   are added at each discontinuity, the first extends the continuous section
   which ends at the discontinuity, and the third extends the secion which 
   starts at the discontinuity. This results in the two sections overlapping 
   by one sample. The second is placed between therse two and has a bad
   axis value. It prevents crossings from being found in between the values 
   at the ends of the two sections. 

   First count the number of discontinuities in the axis values.
   Discontinuites are defined as steps of more than 9 times the RMS step
   size. */
         q1 = ptr2a[ axis ];
         pq1 = AST__BAD;
         limit *= 3.0;
         ndisc = 0;

         for( i = 0; i < EDGETICKS_DIM; i++ ){
            if( *q1 != AST__BAD && pq1 != AST__BAD ){
               if( fabs( *q1 - pq1 ) > limit ) ndisc++;
            }
            pq1 = *(q1++);
         }

/* Store the size of the new PointSets holding the extra samples. */
         dim = EDGETICKS_DIM + 3*ndisc;         
 
/* If there are no discontinuities, just clone the existing PointSets. */
         if( !ndisc ){
            pset1 = astClone( pset1a );
            pset2 = astClone( pset2a );
            pset4 = astClone( pset4a );
            ptr1 = astGetPoints( pset1 );
            ptr2 = astGetPoints( pset2 );
            ptr4 = astGetPoints( pset4 );

/* Otherwise, create new PointSets. */
         } else {
            pset1 = astPointSet( dim, 2, "" );
            ptr1 = astGetPoints( pset1 );
            pset2 = astPointSet( dim, 2, "" );
            ptr2 = astGetPoints( pset2 );
            pset4 = astPointSet( dim, 2, "" );
            ptr4 = astGetPoints( pset4 );

/* Set up pointers used to walk through the arrays in the original
   PointSets and the new PointSets. */
            p1 = ptr1[ 0 ];
            p2 = ptr1[ 1 ];
            q1 = ptr2[ axis ];
            q2 = ptr2[ 1 - axis ];
            v1 = ptr4[ 0 ];
            v2 = ptr4[ 1 ];

            p1a = ptr1a[ 0 ];
            p2a = ptr1a[ 1 ];
            q1a = ptr2a[ axis ];
            q2a = ptr2a[ 1 - axis ];
            v1a = ptr4a[ 0 ];
            v2a = ptr4a[ 1 ];

/* Initialise the axis value at the previous sample. */
            pq1 = AST__BAD;

/* Check all samples in the original PointSets. */   
            for( i = 0; i < EDGETICKS_DIM; i++ ){

/* If this is the first point after a discontinuity... */
               if( *q1a != AST__BAD && pq1 != AST__BAD ){
                  if( fabs( *q1a - pq1 ) > limit ) {

/* Insert an extra sample with the coordinates of the previous sample, 
   but with an axis value which is linearly extrapolated from the previous 
   samples. */
                     *(p1++) = p1a[ 0 ];
                     *(p2++) = p2a[ 0 ];
                     *(v1++) = v1a[ -1 ];
                     *(v2++) = v2a[ -1 ];
                     *(q2++) = q2a[ -1 ];
                     if( i > 1 && q1a[ -2 ] != AST__BAD ){
                        *(q1++) = 2.0*pq1 - q1a[ -2 ];
                     } else {
                        *(q1++) = pq1;
                     }

/* Insert an extra sample with bad coordinates. */
                     *(p1++) = AST__BAD;
                     *(p2++) = AST__BAD;
                     *(v1++) = AST__BAD;
                     *(v2++) = AST__BAD;
                     *(q2++) = AST__BAD;
                     *(q1++) = AST__BAD;

/* Insert an extra sample with the cooridnates of the current sample, 
   but with an axis value which is linearly extrapolated from the
   subsequent samples. */
                     *(p1++) = p1a[ -1 ];
                     *(p2++) = p2a[ -1 ];
                     *(v1++) = *v1a;
                     *(v2++) = *v2a;
                     *(q2++) = *q2a;
                     if( i < EDGETICKS_DIM - 1 && q1a[ 1 ] != AST__BAD ){
                        *(q1++) = 2.0*(*q1a) - q1a[ 1 ];
                     } else {
                        *(q1++) = pq1;
                     }

                  }

               }

/* Save the current axis value. */
               pq1 = *q1a;

/* Copy the current input values to the new PointSets, and move on the next 
   point in the original PointSets. */
               *(p1++) = *(p1a++);
               *(p2++) = *(p2a++);
               *(q1++) = *(q1a++);
               *(q2++) = *(q2a++);
               *(v1++) = *(v1a++);
               *(v2++) = *(v2a++);

            }                                                 

         }

/* Anull the original PointSets. */
         pset1a = astAnnul( pset1a );
         pset2a = astAnnul( pset2a );
         pset4a = astAnnul( pset4a );

/* If all the physical coordinates are bad, indicate this by setting the
   limiting step size bad. */
      } else {
         limit = AST__BAD;
      }
      
/* Annul the pointer to the mapping from base to current Frame. */
      mapping = astAnnul( mapping );

   }

/* ======================================================================*/
/* The initialisation has now been done. Check the physical coordinate data 
   can be used. */
   if( astOK && limit != AST__BAD ){

/* Store pointer to the places to store the physical axis values prior to
   normalisation. */
      axthis = val + axis;
      axother = val + 1 - axis;

/* Store pointers to the graphics and physical coordinates at the first
   edge sample. */
      p1 = ptr1[ edgeax ];     /* Graphics axis with constant value */
      p2 = ptr1[ 1 - edgeax ]; /* Graphics axis with varying value */
      q1 = ptr2[ axis ];       /* Physical axis values to be searched */
      q2 = ptr2[ 1 - axis ];   /* The other physical axis */
 
/* Store pointers to the components of the unit vector at the first
   edge sample. */
      v1 = ptr4[ 0 ];
      v2 = ptr4[ 1 ];

/* Inidicate that there is currently no "previous sample". */
      pq1 = AST__BAD;

/* Check each point in turn... */
      for( i = 0; i < dim; i++ ){

/* Skip this point if the phsyical coordinates are undefined. */
         if( *q1 != AST__BAD && *q2 != AST__BAD ){

/* Normalise the supplied physical axis value using the other axis value from 
   the current edge sample. */
            *axthis = axval;
            *axother = *q2;
            astNorm( frame, val );

/* Get a flag indicating if the required axis value has been exceeded at
   the current edge sample. */
            larger = ( *q1 > *axthis ); 

/* If the state of this flag has changed since the previous edge sample, 
   and if we know where the previous sample was, we have found a
   crossing. */
            if( pq1 != AST__BAD && larger != plarger ){

/* Find the distance from the previous physical axis value to the required
   axis value, as a fraction of the distance from the previous axis value
   to the current axis value. Since the flag has changed, we know that the 
   q1 value at this edge sample and the previous one must be different, so 
   we know that the denominator is not zero. */
               f = ( *axthis - pq1 )/( *q1 - pq1 );

/* Use linear interpolation to estimate the graphics axis value at the
   crossing. */
               if( f != -1.0 ){
                  z = pp2 + f*( *p2 - pp2 );

/* Use linear interpolation to estimate the two components of the unit
   vector at the crossing. */
                  if( *v1 != AST__BAD && pv1 != AST__BAD &&
                      *v2 != AST__BAD && pv2 != AST__BAD ){
                     vx = pv1 + f*( *v1 - pv1 );
                     vy = pv2 + f*( *v2 - pv2 );

/* Normalise the vector. */
                     dl2 = vx*vx + vy*vy;
                     if( dl2 > 0.0 ){
                        dl = sqrt( dl2 );
                        vx /= dl;
                        vy /= dl;
                     } else {
                        vx = AST__BAD;
                        vy = AST__BAD;
                     }

                  } else {
                     vx = AST__BAD;
                     vy = AST__BAD;
                  } 

/* Grow the returned array to hold another crossing. */
                  ncross++;
                  *cross = (double *) astGrow( (void *) *cross, ncross, 
                                               4*sizeof( double ) );

/* If succesful, store the crossing. */
                 if( astOK ) {
  
                    data = *cross + 4*( ncross - 1 );
                    if( edgeax ){
                       *(data++) = z;
                       *(data++) = edgeval;
                    } else {
                       *(data++) = edgeval;
                       *(data++) = z;
                    }
                    *(data++) = vx;
                    *(data++) = vy;
  
                  }

               }

            }

/* Save the flag for use on the next pass through this loop. */
            plarger = larger;

         }

/* Save the varying graphics axis value and the required physical axis 
   value at the current edge sample (also save the vector). */
         pp2 = *p2;
         pq1 = *q1;
         pv1 = *v1;
         pv2 = *v2;

/* Point to the next edge sample. */
         p1++;
         p2++;
         q1++;
         q2++;
         v1++;
         v2++;

      }

   }

/* If an error has occurred, free the array holding the crossings, and 
   indicate that there are zero corssing. */
   if( !astOK ) {
      *cross = (double *) astFree( (void *) *cross );
      ncross = 0;
   }

/* Return the answer. */
   return ncross;

}

static int FindMajTicks( AstFrame *frame, int axis, double refval, 
                         double gap, double *cen, int ngood, double *data, 
                         double **tick_data ){
/*
*  Name:
*     FindMajTicks

*  Purpose:
*     Place the major tick marks for a physical coordinate axis.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int FindMajTicks( AstFrame *frame, int axis, double refval, double gap, 
*                       double *cen, int ngood, double *data, double **tick_data )

*  Class Membership:
*     Plot member function.

*  Description:
*     The caller supplies an array of axis values, sorted into ascending
*     order (with any bad values at the end), together with the gap size
*     for the axis. The array of axis values is assumed to cover the
*     entire range which the axis can take within the plotting zone. The
*     first tick mark is placed just below the smallest axis value, at a
*     position which is an integral number of gaps away from the value
*     supplied in "cen" (if a value of AST__BAD is supplied for "cen" then 
*     "cen = 0.0" is assumed). Notionally, tick marks are then placed at
*     intervals given by "gap" all the way upto, and just beyond, the
*     largest axis value. However, it could be that large sections of the 
*     axis are not actually present within the plotting zone. For instance,
*     an RA axis covering the two hour range from 23h to 1h (centred on
*     0h), will have some values at zero and some at 23.999.., but there
*     will be a large range inbetween these limits which is not represented
*     in the plotting area (i.e. the 22h range from 1h to 23h centred on
*     12h). For this reason, tick marks are removed if there are no axis
*     values inbetween the tick mark and either of its neighbours. However,
*     small "holes" in the axis coverage are allowed (upto 4 empty tick
*     mark divisions), and ticks marks are returned covering such small
*     holes. An extra tick marks is placed at each end of the range to
*     guard against the supplied array of axis values not entirely covering
*     the range of axis values in the plotting area.
*
*     The returned tick mark values are normalised using the astNorm
*     method for the supplied Frame. The other axis is assigned the value
*     "refval" during the normalisation. Duplicate tick marks values are
*     removed from the returned list.

*  Parameters:
*     frame
*        Pointer to the Frame.
*     axis 
*        Zero-based index of the axis being used.
*     refval
*        Value to use for the other axis (index [1-axis]) when normalising
*        the tick mark values.
*     gap
*        The supplied value for the gaps between ticks on the axis.
*     cen
*        Pointer to the supplied axis value at which to put a central tick. 
*        Other ticks will be placed evenly on either side of this tick. If 
*        AST__BAD is provided, a value will be used which would put a tick 
*        at an axis value of zero. The used value is returned.
*     ngood
*        The number of good values in the array pointer to by "data" (i.e.
*        values not equal to AST__BAD).
*     data
*        A pointer to an array holding sorted axis values covering the
*        entire plotting area.
*     tick_data
*        A pointer to a place at which to store a pointer to an array
*        holding the returned tick mark values for the axis.

*  Returned Value:
*     The number of major tick mark values stored in the array pointer to
*     by "*tick_data".

*  Notes:
*     -  If an error has already occurred, or if this function should fail 
*     for any reason, then a NULL pointer is returned in "tick_data", and zero 
*     is returned for the function value.
*/

/* Local Variables: */
   double *r;         /* Pointer to next tick value to be read */
   double *ticks;     /* Pointer to the axis values at the major tick marks */
   double *w;         /* Pointer to last tick value to be written */
   double centre;     /* The axis value at the first tick mark */
   double f;          /* The nearest acceptable tick mark index */
   double val[ 2 ];   /* Axis values to be normalised */
   int i;             /* Index of current axis value */
   int k;             /* Tick mark index */
   int klast;         /* Index of the previous tick mark */
   int nticks;        /* Number of major tick marks used */

/* Initialise the returned pointer. */
   *tick_data = NULL;

/* Check the global error status. */
   if ( !astOK ) return 0;

/* Decide where to put the first major tick. Use any value supplied by
   the caller. Otherwise put it an integral number of gaps away from the
   origin. This would result in the origin being at a major tick mark. */
   if( cen && *cen != AST__BAD ) {
      centre = *cen;
   } else {
      centre = gap*floor( 0.5 + data[ 0 ]/gap );
      if( cen ) *cen = centre;
   }

/* Reserve memory initially to hold 20 major tick mark axis values. */
   ticks = (double *) astMalloc( sizeof(double)*20 );

/* Check that the pointer can be used. */
   if( astOK ){

/* Put the first two tick marks just below the lowest axis value (in case
   the grid did not sample the entire range of the axis). */
      k = floor( ( data[ 0 ] - centre )/gap );
      ticks[ 0 ] = gap*(double)( k - 1 ) + centre;
      ticks[ 1 ] = gap*(double)( k ) + centre;

/* Initialise the number of major tick marks found so far. */
      nticks = 2;

/* Loop round each of the remaining good ordered axis values. */
      klast = k;
      for( i = 1; i < ngood && astOK; i++ ) {

/* Find the tick marks enclosing the axis value. The tick mark placed at 
   "centre" is called tick mark zero, and tick marks are indexed (positive 
   or negative) from an origin at "centre". Find the index of the more 
   negative of the two tick marks enclosing the axis value. */
         k = floor( ( data[ i ] - centre )/gap );

/* Ensure that the tick marks enclosing the current axis value are used.
   Some extra tick marks are used at the start and end of any gaps in
   the axis coverage. This is done to "fill in" small holes caused by the
   grid of physical coordinate values not completely covering the
   plotting area. Large holes, such as occur on an RA axis covering the 2 
   hour range from 23 hours to 1 hour are left without any tick marks in 
   them (the "hole" in this case is the 22 hours range from 1 hour to 23 
   hours). */
         if( k - klast > 3 ) {
            ticks = (double *) astGrow( ticks, nticks + 1, sizeof( double ) );
            if( astOK ) ticks[ nticks++ ] = 
                                         gap*(double)( klast + 2 ) + centre;
         }
   
         if( k - klast > 2 ) {
            ticks = (double *) astGrow( ticks, nticks + 1, sizeof( double ) );
            if( astOK ) ticks[ nticks++ ] =
                                         gap*(double)( klast + 1 ) + centre;
         }
   
         if( k - klast > 1 ) {
            ticks = (double *) astGrow( ticks, nticks + 1, sizeof( double ) );
            if( astOK ) ticks[ nticks++ ] = 
                                         gap*(double)( k - 1 ) + centre;
         }
   
         if( k - klast > 0 ) {
            ticks = (double *) astGrow( ticks, nticks + 1, sizeof( double ) );
            if( astOK ) ticks[ nticks++ ] = 
                                         gap*(double)( k ) + centre;
         }
   
/* Save the index of the current tick mark. */
         klast = k;
   
      }

/* Add two extra tick marks beyond the end in case the grid did not sample
   the entire range of the axis. */
      ticks = (double *) astGrow( ticks, nticks + 2, sizeof( double ) );
      if( astOK ) ticks[ nticks++ ] = gap*(double)( klast + 1 ) + centre;
      if( astOK ) ticks[ nticks++ ] = gap*(double)( klast + 2 ) + centre;

   }
  
/* If all has gone OK, normalise the tick values using the supplied value 
   for the other axis. */
   if( astOK ){
      val[ 1 - axis ] = refval;
      r = ticks;
      for( k = 0; k < nticks; k++ ){
         val[ axis ] = *r;
         astNorm( frame, val );
         *(r++) = val[ axis ];
      }

/* Ensure that all ticks marks are offset from the "centre" value by an 
   integer multiple of the gap size. This is done by changing each tick
   value to the closest accetpable value. */
      r = ticks;
      for( k = 0; k < nticks; k++ ){
         f = floor( 0.5 + ( *r - centre )/gap );
         *(r++) = f*gap + centre;
      }

/* Sort the normalised tick values into increasing order. */
      qsort( (void *) ticks, (size_t) nticks, sizeof(double), Compared );

/* Remove any duplicate tick values by shuffling the higher unique values
   down to over-write them. */
      r = ticks + 1;
      w = ticks;
      for( k = 1; k < nticks && astOK; k++ ){
         if( !EQUAL( *r, *w ) ){
            w++;
            *w = *r;
         }
         r++;
      }

/* Modify the number of ticks to exclude the duplicate ones. */
      nticks = (int) ( w - ticks ) + 1;
   }

/* If an error has occurred, free the memory holding the major tick mark
   values, and indicate that zero tick marks have been found. */
   if( !astOK ){
      ticks = (double *) astFree( (void *) ticks );
      nticks = 0;
   }

/* Store the pointer to the major tick mark values. */
   *tick_data = ticks;

/* Return the number of major ticks. */
   return nticks;

}

static int FindString( int n, const char *list[], const char *test, 
                       const char *text, const char *method, 
                       const char *class ){
/*
*  Name:
*     FindString

*  Purpose:
*     Find a given string within an array of character strings.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int FindString( int n, const char *list[], const char *test, 
*                     const char *text, const char *method, const char *class )

*  Class Membership:
*     Plot method.

*  Description:
*     This function identifies a supplied string within a supplied
*     array of valid strings, and returns the index of the string within
*     the array. The test option may not be abbreviated, but case is
*     insignificant.

*  Parameters:
*     n
*        The number of strings in the array pointed to be "list".
*     list
*        A pointer to an array of legal character strings.
*     test
*        A candidate string.
*     text
*        A string giving a description of the object, parameter,
*        attribute, etc, to which the test value refers.
*        This is only for use in constructing error messages. It should
*        start with a lower case letter.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     The index of the identified string within the supplied array, starting
*     at zero.

*  Notes:
*     -  A value of -1 is returned if an error has already occurred, or
*     if this function should fail for any reason (for instance if the
*     supplied option is not specified in the supplied list). 

*/

/* Local Variables: */
   int ret;                /* The returned index */

/* Check global status. */
   if( !astOK ) return -1;

/* Compare the test string with each element of the supplied list. Leave
   the loop when a match is found. */
   for( ret = 0; ret < n; ret++ ) {
      if( !Ustrcmp( test, list[ ret ] ) ) break;
   }

/* Report an error if the supplied test string does not match any element
   in the supplied list. */
   if( ret >= n ) {
      astError( AST__OPT, "%s(%s): Illegal value '%s' supplied for %s.",
                method, class, test, text );
      ret = -1;
   }

/* Return the answer. */
   return ret;
}

static char *FindWord( char *ptr, const char *d, const char **p ) {
/*
*  Name:
*     FindWord

*  Purpose:
*     Return a copy of the next word in a supplied string.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     char *FindWord( char *ptr, const char *d, const char **p )

*  Class Membership:
*     Plot method.

*  Description:
*     This function locates the start and end of the first word in the
*     string pointed to by *p, and returns a copy of the word. The pointer
*     *p is modified to point to the start of the following word (if any).
*     The characters which delimit words are supplied in string "d".

*  Parameters:
*     ptr
*        A pointer to a character string in which to store the returned 
*        word. The memory holding this string should have been allocated
*        using one of the functions in the AST "memory" module. The memory
*        area will be modified in size to fit the returned word. A NULL
*        pointer may be supplied if no memory has yet been allocated.
*        Any memory pointed to by ptr is freed if a NULL pointer is
*        returned by this function (i.e. if no word is found).
*     d
*        A string holding the characters which are to be used as word
*        delimiters.
*     p
*        The address of a character string pointer. On entry, this pointer
*        identifies the start of the string to be searched. On exit, it is
*        modified to point to the start of the following word. It is
*        returned NULL if there are no more words.

*  Returned Value:
*     A pointer to a dynamically allocated character string holding the 
*     next word, or NULL if no word could be found. 

*/

/* Local Variables: */
   const char *a, *b, *c;
   char *ret;
   int nc;   

/* Free any allocated memory and return if any of the supplied pointers 
   (except ptr) is NULL, or if an error has occurred. */
   if( !astOK || !d || !p || !*p ) {
      (void) astFree( (void *) ptr );
      return NULL;
   }

/* Get a pointer to the first character which is not in "d". Terminate
   the loop if a null character is encountered. */
   a = *p;
   while( *a && strchr( d, (int) *a ) ) a++;

/* Get a pointer to the next character which is in "d". Terminate
   the loop if a null character is encountered. */
   b = a;
   while( *b && !strchr( d, (int) *b ) ) b++;

/* Get a pointer to the next character which is not in "d". Terminate
   the loop if a null character is encountered. */
   c = b;
   while( *c && strchr( d, (int) *c ) ) c++;

/* Adjust the supplied pointer so that it points to the start of the next
   word. */
   if( *c ){
      *p = c;
   } else {
      *p = NULL;
   }

/* Get a null-terminated copy of the word between a and b. */
   nc = b - a;
   if( nc > 0 ) {
      ret = (char *) astStore( (void *) ptr, (void *) a, (size_t) (nc + 1) );
      ret[ nc ] = 0;
   } else {
      ret = astFree( (void *) ptr );
   }

   return ret;
}

static AstFrameSet *Fset2D( AstFrameSet *fset, int ifrm ) {
/*
*  Name:
*     Fset2D

*  Purpose:
*     Create a FrameSet with no more than 2 dimensions for a given Frame.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*      AstFrameSet *Fset2D( AstFrameSet *fset, int ifrm )

*  Class Membership:
*     Plot method.

*  Description:
*     This function checks a specified Frame in the supplied FrameSet.
*     If the Frame has more than 2 dimensions, a new Frame is added to 
*     the FrameSet containing just the first two axes of the specified
*     Frame. A PermMap is used to connect this Frame to the specified 
*     Frame, which supplied bad values for any missing axes. If the
*     specified Frame is the base Frame in the supplied FrameSet, then the
*     new Frame becomes the base Frame in the returned FrameSet. Like-wise,
*     if the specified Frame is the current Frame, then the new Frame
*     will be the current Frame in the returned FrameSet.
*     
*     If the specified Frame does not have more than 2 axes, then a clone
*     of the FrameSet pointer is returned, otherwise the returned pointer
*     points to a copy of the supplied FrameSet with the new 2-D Frame
*     added.

*  Parameters:
*     fset
*        Pointer to the FrameSet.
*     ifrm
*        The index of the Frame to check. This should be AST__BASE or
*        AST_CURRENT.

*  Returned Value:
*     A pointer to a FrameSet in which the Frame with index given by ifrm
*     has no more than 2 axes.
*/

/* Local Variables: */
   AstFrame *frm;
   AstFrame *newfrm;
   AstFrameSet *ret;
   AstPermMap *map;
   double zero;
   int *inperm;
   int axes[2];
   int i;
   int ic;
   int nax;

/* Check the inherited status. */
   if( !astOK ) return NULL;

/* Get a pointer to the requested Frame in the supplied FrameSet. */
   frm = astGetFrame( fset, ifrm );

/* See how many dimensions the specified Frame of the supplied FrameSet 
   has. */
   nax = astGetNaxes( frm );

/* If it is more than 2-dimensionbal, create a 2D Frame by picking 
   axes 1 and 2 from the original Frame. */
   if( nax > 2 ) {
      axes[ 0 ] = 0;
      axes[ 1 ] = 1;
      newfrm = astPickAxes( frm, 2, axes, NULL );

/* Create a PermMap to describe the mapping between the two Frames. 
   Use zero as the value for unknown axes (the optional mapping which
   can be returned by astPickAxes uses AST__BAD for unknown axes). */
      inperm = (int *) astMalloc( sizeof(int)*(size_t) nax );
      if( astOK ){
         inperm[ 0 ] = 0;
         inperm[ 1 ] = 1;
         for( i = 2; i < nax; i++ ) inperm[ i ] = -1;
         zero = 0.0;
         map = astPermMap( nax, inperm, 2, axes, &zero, "" );
         inperm = (int *) astFree( (void *) inperm );
      }

/* Get a copy of the supplied FrameSet. */
      ret = astCopy( fset );

/* Add the new Frame to the FrameSet (it becomes the current Frame). */
      ic = astGetCurrent( ret );
      astAddFrame( ret, ifrm, map, newfrm );
      newfrm = astAnnul( newfrm );

/* If the new Frame was derived from the base frame, set the new base
   Frame, and re-instate the original current Frame */
      if( ifrm == AST__BASE ){
         astSetBase( ret, astGetCurrent( ret ) );      
         astSetCurrent( ret, ic );
      }

/* If the specified Frame in the supplied FrameSet is 2-dimensional, just
   return a clone of it. */
   } else {
      ret = astClone( fset );
   }

/* Annul the pointer to the original Frame. */
   frm = astAnnul( frm );

   return ret;

}

static int FullForm( const char *list, const char *test, const char *text,
                     const char *method, const char *class ){
/*
*  Name:
*     FullForm

*  Purpose:
*     Identify the full form of an option string.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int FullForm( const char *list, const char *test, const char *text,
*                   const char *method, const char *class )

*  Class Membership:
*     Plot method.

*  Description:
*     This function identifies a supplied test option within a supplied
*     list of valid options, and returns the index of the option within
*     the list. The test option may be abbreviated, and case is
*     insignificant.

*  Parameters:
*     list
*        A list of space separated option strings.
*     test
*        A candidate option string.
*     text
*        A string giving the context in which the supplied test option
*        was supplied. For instance, this may be an attribute setting string.
*        This is only for use in constructing error messages.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     The index of the identified option within the supplied list, starting
*     at zero.

*  Notes:
*     -  A value of -1 is returned if an error has already occurred, or
*     if this function should fail for any reason (for instance if the
*     supplied option is not uniquely specified in the supplied list). 

*/

/* Local Variables: */
   char *option;           /* Pointer to a copy of the next option */
   const char *p;          /* Pointer to the start of the next word */
   int i;                  /* Current option index */
   int len;                /* Length of supplied option */
   int nmatch;             /* Number of matching options */
   int ret;                /* The returned index */

/* Initialise the answer to indicate that the option has not been
   uniquely identified. */
   ret = -1;

/* Check global status. */
   if( !astOK ) return ret;

/* Save the number of characters in the supplied test option (excluding
   trailing spaces). */
   len = ChrLen( test );

/* Compare the supplied test option against each of the known options in 
   turn. Count the number of matches. */
   nmatch = 0;
   p = list;
   option = FindWord( NULL, " ", &p );
   i = 0;
   while( option ){

/* If every character in the supplied label matches the corresponding
   character in the current test label we have a match. Increment the 
   number of matches and save the current item index. */
      if( !Ustrncmp( test, option, len ) ) {
         nmatch++;
         ret = i;
      }

/* Get a pointer to the next option. */
      option = FindWord( option, " ", &p );
      i++;
   }

/* Report an error if no match was found, and return -1. */
   if( !nmatch ){
      astError( AST__OPT, "%s(%s): Option '%.*s' is unknown in '%.*s'.",
                method, class, len, test, ChrLen( text ), text );
      ret = -1;

/* Report an error if the label was ambiguous, and return -1. */
   } else if( nmatch > 1 ){
      astError( AST__OPT, "%s(%s): Option '%.*s' is ambiguous in '%.*s'.",
                method, class, len, test, ChrLen( text ), text );
      ret = -1;
   }

/* Return the answer. */
   return ret;
}

static const char *GetAttrib( AstObject *this_object, const char *attrib ) {
/*
*  Name:
*     GetAttrib

*  Purpose:
*     Get the value of a specified attribute for a Plot.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     const char *GetAttrib( AstObject *this, const char *attrib )

*  Class Membership:
*     Plot member function (over-rides the protected astGetAttrib
*     method inherited from the FrameSet class).

*  Description:
*     This function returns a pointer to the value of a specified
*     attribute for a Plot, formatted as a character string. 
*
*     The value returned is the value which would actually be used if
*     astGrid was called with the current set of attribute values. This
*     may not always be the same as the value set by the user. For
*     instance, if Labelling is set to "exterior" by the user, it may not
*     be possible to produce exterior labels, in which case interior labels
*     will be produced. If this function is used to get the value of
*     Labelling in this situation, then the value actually used (i.e.
*     interior) will be returned instead of the requested value (i.e. 
*     exterior).
*
*     Some attributes have dynamic defaults, (i.e. the behaviour if not
*     set depends on the values of other attributes). If the value for
*     such an attribute is enquired using this function, then the dynamic
*     default value actually used will be returned if no value has been
*     set explicitly for the attribute.

*  Parameters:
*     this
*        Pointer to the Plot.
*     attrib
*        Pointer to a null terminated string containing the name of
*        the attribute whose value is required. This name should be in
*        lower case, with all white space removed.

*  Returned Value:
*     - Pointer to a null terminated string containing the attribute
*     value.

*  Notes:
*     - The returned string pointer may point at memory allocated
*     within the Plot, or at static memory. The contents of the
*     string may be over-written or the pointer may become invalid
*     following a further invocation of the same function or any
*     modification of the Plot. A copy of the string should
*     therefore be made if necessary.
*     - A NULL pointer will be returned if this function is invoked
*     with the global error status set, or if it should fail for any
*     reason.
*/

/* Local Constants: */
#define BUFF_LEN 50              /* Max. characters in result buffer */

/* Local Variables: */
   AstPlot *this;                /* Pointer to the Plot structure */
   const char *result;           /* Pointer value to return */
   char label[21];               /* Graphics item label */
   double dval;                  /* Double attribute value */
   int axis;                     /* Axis number */
   int ival;                     /* Int attribute value */
   int len;                      /* Length of attrib string */
   int nc;                       /* No. characters read by sscanf */
   static char buff[ BUFF_LEN + 1 ]; /* Buffer for string result */

/* Initialise. */
   result = NULL;

/* Check the global error status. */   
   if ( !astOK ) return result;

/* Obtain a pointer to the Plot structure. */
   this = (AstPlot *) this_object;

/* Obtain the length of the attrib string. */
   len = strlen( attrib );

/* Compare "attrib" with each recognised attribute name in turn,
   obtaining the value of the required attribute. If necessary, write
   the value into "buff" as a null terminated string in an appropriate
   format.  Set "result" to point at the result string. */

/* Tol. */
/* ---- */
   if ( !strcmp( attrib, "tol" ) ) {
      dval = astGetTol( this );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* Grid. */
/* ----- */
   } else if ( !strcmp( attrib, "grid" ) ) {
      ival = GetUsedGrid( this );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* TickAll. */
/* -------- */
   } else if ( !strcmp( attrib, "tickall" ) ) {
      ival = astGetTickAll( this );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* Border. */
/* ------- */
   } else if ( !strcmp( attrib, "border" ) ) {
      ival = GetUsedBorder( this );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* ClipOp. */
/* ------- */
   } else if ( !strcmp( attrib, "clipop" ) ) {
      ival = astGetClipOp( this );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* DrawTitle. */
/* --------- */
   } else if ( !strcmp( attrib, "drawtitle" ) ) {
      ival = astGetDrawTitle( this );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* DrawAxes. */
/* --------- */
   } else if ( !strcmp( attrib, "drawaxes" ) ) {
      ival = astGetDrawAxes( this );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* Escape. */
/* ------- */
   } else if ( !strcmp( attrib, "escape" ) ) {
      ival = astGetEscape( this );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* LabelAt(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "labelat(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      dval = GetUsedLabelAt( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* Centre(axis). */
/* ------------ */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "centre(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      dval = GetUsedCentre( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* Gap. */
/* ---- */
   } else if ( !strcmp( attrib, "gap" ) ) {
      dval = GetUsedGap( this, 0 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* Gap(axis). */
/* ---------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "gap(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      dval = GetUsedGap( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* NumLabGap. */
/* -------- */
   } else if ( !strcmp( attrib, "numlabgap" ) ) {
      dval = astGetNumLabGap( this, 0 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* NumLabGap(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "numlabgap(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      dval = astGetNumLabGap( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* TextLabGap. */
/* ----------- */
   } else if ( !strcmp( attrib, "textlabgap" ) ) {
      dval = astGetTextLabGap( this, 0 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* TextLabGap(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "textlabgap(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      dval = astGetTextLabGap( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* LabelUp. */
/* -------- */
   } else if ( !strcmp( attrib, "labelup" ) ) {
      ival = astGetLabelUp( this, 0 );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* LabelUp(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "labelup(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      ival = astGetLabelUp( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* NumLab. */
/* -------- */
   } else if ( !strcmp( attrib, "numlab" ) ) {
      ival = astGetNumLab( this, 0 );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* NumLab(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "numlab(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      ival = astGetNumLab( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* MinTick. */
/* -------- */
   } else if ( !strcmp( attrib, "mintick" ) ) {
      ival = GetUsedMinTick( this, 0 );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* MinTick(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "mintick(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      ival = GetUsedMinTick( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* TextLab. */
/* ---------- */
   } else if ( !strcmp( attrib, "textlab" ) ) {
      ival = GetUsedTextLab( this, 0 );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* TextLab(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "textlab(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      ival = GetUsedTextLab( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* LabelUnits. */
/* ----------- */
   } else if ( !strcmp( attrib, "labelunits" ) ) {
      ival = GetUsedLabelUnits( this, 0 );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* LabelUnits(axis). */
/* ----------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "labelunits(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      ival = GetUsedLabelUnits( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* Style. */
/* ------ */
   } else if ( !strcmp( attrib, "style" ) ) {
      ival = astGetStyle( this, BORDER_ID );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* Style(label). */
/* ------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "style(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      ival = astGetStyle( this, FullForm( GrfLabels, label, attrib, "astGet", astGetClass( this ) ) );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* Font. */
/* ----- */
   } else if ( !strcmp( attrib, "font" ) ) {
      ival = astGetFont( this, TEXTLABS_ID );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* Font(label). */
/* ------------ */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "font(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      ival = astGetFont( this, FullForm( GrfLabels, label, attrib, "astGet", astGetClass( this ) ) );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* Colour. */
/* ------- */
   } else if ( !strcmp( attrib, "colour" ) ) {
      ival = astGetColour( this, TEXTLABS_ID );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* Colour(label). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "colour(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      ival = astGetColour( this, FullForm( GrfLabels, label, attrib, "astGet", astGetClass( this ) ) );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* Color. */
/* ------ */
   } else if ( !strcmp( attrib, "color" ) ) {
      ival = astGetColour( this, TEXTLABS_ID );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* Color(label). */
/* ------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "color(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      ival = astGetColour( this, FullForm( GrfLabels, label, attrib, "astGet", astGetClass( this ) ) );
      if ( astOK ) {
         (void) sprintf( buff, "%d", ival );
         result = buff;
      }

/* Width. */
/* ------ */
   } else if ( !strcmp( attrib, "width" ) ) {
      dval = astGetWidth( this, BORDER_ID );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }


/* Width(label). */
/* ------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "width(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      dval = astGetWidth( this, FullForm( GrfLabels, label, attrib, "astGet", astGetClass( this ) ) );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* Size. */
/* ----- */
   } else if ( !strcmp( attrib, "size" ) ) {
      dval = astGetSize( this, TEXTLABS_ID );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* Size(label). */
/* ------------ */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "size(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      dval = astGetSize( this, FullForm( GrfLabels, label, attrib, "astGet", astGetClass( this ) ) );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* TitleGap. */
/* --------- */
   } else if ( !strcmp( attrib, "titlegap" ) ) {
      dval = astGetTitleGap( this );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* MajTickLen. */
/* ----------- */
   } else if ( !strcmp( attrib, "majticklen" ) ) {
      dval = GetUsedMajTickLen( this, 0 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* MajTickLen(axis). */
/* ----------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "majticklen(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      dval = GetUsedMajTickLen( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* MinTickLen. */
/* ----------- */
   } else if ( !strcmp( attrib, "minticklen" ) ) {
      dval = astGetMinTickLen( this, 0 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* MinTickLen(axis). */
/* ----------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "minticklen(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      dval = astGetMinTickLen( this, axis - 1 );
      if ( astOK ) {
         (void) sprintf( buff, "%.*g", DBL_DIG, dval );
         result = buff;
      }

/* Labelling. */
/* ---------- */
   } else if ( !strcmp( attrib, "labelling" ) ) {
      ival = GetUsedLabelling( this );
      if ( astOK ) {
         result = ival ? xlbling[0] : xlbling[1];
      }

/* Edge(axis). */
/* ----------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "edge(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      ival = GetUsedEdge( this, axis - 1 );
      if ( astOK ) {
         if( ival == LEFT ){
            result = "left";
         } else if( ival == RIGHT ){
            result = "right";
         } else if( ival == TOP ){
            result = "top";
         } else if( ival == BOTTOM ){
            result = "bottom";
         } else {
            result = "<bad>";
         }
      }

/* If the attribute name was not recognised, pass it on to the parent
   method for further interpretation. */
   } else {
      result = (*parent_getattrib)( this_object, attrib );
   }

/* Return the result. */
   return result;

/* Undefine macros local to this function. */
#undef BUFF_LEN
}

static double GetTicks( AstPlot *this, int axis, double *cen, double gap, 
                      double **ticks, int *nmajor, int *nminor, int format_set,
                      int *inval, const char *method, const char *class ){
/*
*  Name:
*     GetTicks

*  Purpose:
*     Obtain a list of tick mark values for a single axis in a 2-D 
*     physical coordinate Frame.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     double GetTicks( AstPlot *this, int axis, double *cen, double gap, 
*                      double **ticks, int *nmajor, int *nminor, 
*                      int format_set, int *inval, const char *method, 
*                      const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     An initial guess is made at a gap size, and the number of major
*     tick marks which would result from using the gap is found. If this
*     number is not within acceptable limits the gap size is changed, and
*     the process is repeated. If this fails to produce a satisfactory
*     result after 10 attempts, the most recent gap sizes are used anyway.
*
*     The positioning of the gaps can be specified explicitly by the
*     caller, or they can be found automatically.

*  Parameters:
*     this
*        The Plot.
*     axis
*        The zero-based index of the axis to use.
*     cen
*        Pointer to the supplied axis value at which to put a single 
*        central tick. Other ticks will be placed evenly on either side 
*        of this tick. If AST__BAD is provided, a value will be used 
*        which would put a tick at an axis value of zero. The used value
*        is returned.
*     gap
*        The supplied values for the gaps between ticks on the axis. If
*        this is AST__BAD a suitable default value will be used, and
*        returned as the functiuon value.
*     ticks
*        Pointer to a place at which to return a pointer to the memory in 
*        which are stored the tick values to be used. This pointer should be 
*        freed using astFree when no longer needed. The number of values in
*        the array is given by the value returned by parameter "nmajor".
*     nmajor
*        A pointer to a location at which to return the number of major
*        ticks.
*     nminor
*        A pointer to a location at which to return the number of division
*        into which each gap should be divided when drawing minor tick marks.
*        This is one more than the number of minor tick marks.
*     format_set
*        Indicates if an explicit format has been set for the axis. If
*        not, "cen" is always assumed to be AST__BAD, and any supplied
*        value for "gap" is rounded to the nearest "nice" value. This has
*        to be done because the algorithm for choosing a format avoiding
*        unnecessary precision only works if the gap size causes 1 digit to
*        change between adjacent labels.
*     inval
*        A pointer to a location at which to return a flag indicating if
*        any invalid physical coordinates were encountered.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     The used gap size.

*  Notes:
*     -  This function allocates some static resources on its first
*     invocation, which should be released when no longer needed, or when
*     a different Plot is supplied, by calling this function with a NULL 
*     pointer for parameter "this". All other parameters are ignored.
*     -  This function assumes that the physical coordinate system is 2 
*     dimensional, and it should not be used if this is not the case.
*     -  An error is reported if the region containing valid physical
*     coordinates is too small to use.
*     -  If an error has already occurred, or if this function should fail 
*     for any reason, then a NULL pointer is returned in "ticks", zero 
*     is returned for the number of major and minor ticks marks. 
*/

/* Local Variables: */
   int i;                    /* Axis index */
   int j;                    /* Position index */
   double *p;                /* Pointer to next axis value */
   double cen0;              /* Supplied value of cen */
   double frac;              /* Fraction of plot area holding good coords */
   double sum;               /* Sum of axis values */
   double test_gap;          /* Trial gap size */
   double used_gap;          /* The used gap size */

   static AstFrame *frame;          /* Pointer to the current Frame */
   static AstPointSet *pset=NULL;   /* Pointer to a PointSet holding physical coords */
   static double **ptr;             /* Pointer to physical coordinate values */
   static double defgaps[ 2 ];      /* Initial test gaps for each axis */
   static double mean[ 2 ];         /* Mean value on each axis */
   static int maxticks;             /* Max. number of ticks on each axis */
   static int mintick;             /* Min. number of ticks on each axis */
   static int ngood[ 2 ];           /* No. of good physical values on each axis */
   static int bad;                  /* Were any bad pixels found? */

/* Initialise the returned information. */
   *ticks = NULL;
   *nmajor = 0;
   *nminor = 0;

/* If a NULL pointer has been supplied for "this", release the resources
   allocated on the first call to this function, and return. */
   if( !this ){
      pset = astAnnul( pset );
      frame = astAnnul( frame );
      return 0.0;
   }

/* Check the global error status. */
   if ( !astOK ) return 0.0;

/* If this is the first call to this function, do some initialisation. */
   if( !pset ){

/* Get a pointer to the current Frame from the Plot. */
      frame = astGetFrame( this, AST__CURRENT );

/* Get initial guesses at suitable gaps for each axis. A PointSet is
   returned holding sorted values for the physical axes. */
      pset = DefGap( this, defgaps, ngood, &frac, &bad, method, class );

/* Store the maximum and minimum number of major tick marks along each
   axis. These numbers are reduced if only a small part of the plotting
   area contains valid coordinates, so that the tick marks do not end up
   to close together. */
      maxticks = (int) ( 0.5 + MAJTICKS_MAX*sqrt( frac ) );
      mintick = (int) ( 0.5 + MAJTICKS_MIN*sqrt( frac ) );
      if( mintick < 5 ) mintick = 5;
      if( maxticks < mintick ) maxticks = mintick;

/* Get a pointer to the data in the PointSet. */
      ptr = astGetPoints( pset );

/* Find the mean value on each axis. */
      for( i = 0; i < 2 && astOK; i++ ){

         if( ngood[ i ] > 0 ){
            sum = 0.0;
            p = ptr[ i ];
            for( j = 0; j < ngood[ i ]; j++ ) sum += *(p++);
            mean[ i ] = sum/(double) ngood[ i ];

         } else {
            mean[ i ] = AST__BAD;
         }

      }

   }

/* Return the flag indicating if any regions of invalid physical coordinates 
   were found. */
   *inval = bad;

/* Store the supplied valeu of cen. */
   cen0 = ( cen ) ? *cen : AST__BAD;

/* If no format has been set for the axis, ensure AST__BAD is used for cen. */
   if( !format_set ) cen0 = AST__BAD;

/* Try to find a "nice" gap size, so long as the caller has not supplied
   a gap size. The default gap size obtained above is our initial guess. */
   if( gap == AST__BAD ){

/* Start of using the default gap found during the initialisation. */
      test_gap = defgaps[ axis ];

/* Loop round until a gap size is found which gives an acceptable number
   of tick marks. Upto 10 gap sizes are tried. */
      for( i = 0; i < 10 && astOK; i++ ){

/* Find a "nice" gap size close to the current test gap size. Also find
   the number of minor tick marks to use with the nice gap size. */
         used_gap = astGap( frame, axis, test_gap, nminor );

/* Find the number and positions of major tick marks which would result
   from using this gap size. Annul the memory used to hold any previous tick 
   data first. */
         if( *ticks ) *ticks = astFree( *ticks );
         if( cen ) *cen = cen0;
         *nmajor = FindMajTicks( frame, axis, mean[ 1 - axis ], used_gap, cen, 
                                 ngood[ axis ], ptr[ axis ], ticks );

/* If the number of ticks is unacceptable, try a different gap size. If the
   gap was too large to produce any ticks, try using half the gap size. */
         if( *nmajor == 0 ) {
            test_gap *= 0.5;

/* If there were some ticks, but not enough, decrease the gap size in
   proportion to the shortfall. */
         } else if( *nmajor < mintick ){
            test_gap *= (double)( *nmajor )/(double)( mintick );

/* If there were too many ticks, increase the gap size in proportion to the 
   excess. */
         } else if( *nmajor > maxticks ){
            test_gap *= (double)( *nmajor )/(double)( maxticks );

/* If the number of ticks is acceptable, break out of the loop early.*/
         } else {
            break;
         }

      }

/* If an explicit gap size was supplied, use it. */
   } else {

/* Find a likely value for the number of minor tick marks to use, and find
   a nice gap close to the supplied gap (unless an explicit format has
   been set). */
      if( format_set ){
         used_gap = gap;
         (void) astGap( frame, axis, gap, nminor );
      } else {
         used_gap = astGap( frame, axis, gap, nminor );
      }

/* Find where the major ticks should be put. */
      if( cen ) *cen = cen0;
      *nmajor = FindMajTicks( frame, axis, mean[ 1 - axis ], used_gap, cen, 
                              ngood[ axis ], ptr[ axis ], ticks );

   }

/* If an error has occurred, annul the memory used to hold tick data, and
   return zero ticks. */
   if( !astOK ) {
      *ticks = (double *) astFree( (void *) *ticks );
      nmajor = 0;
      nminor = 0;
      used_gap = 0.0;
   }

/* Return. */
   return used_gap;
}

static double GoodGrid( AstPlot *this, int *dim, AstPointSet **pset1, 
                        AstPointSet **pset2, const char *method, 
                        const char *class ){
/*
*  Name:
*     GoodGrid

*  Purpose:
*     Create a grid covering the region containing good coordinates in a 
*     2-D physical coordinate Frame.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     double GoodGrid( AstPlot *this, int *dim, AstPointSet **pset1, 
*                      AstPointSet **pset2, const char *method, 
*                      const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function creates two PointSets, one holding a square grid of
*     graphics coordinates, and the other holding the corresponding physical 
*     coordinates. The grid covers just the area containing good physical
*     coordinates. The points are stored row by row in the returned PointSets.

*  Parameters:
*     this
*        The Plot.
*     dim
*        A pointer to an integer in which to store the number of samples
*        along each edge of the returned grid. 
*     pset1
*        A pointer to a location at which to store a pointer to the
*        PointSet holding the graphics coordinates.
*     pset2
*        A pointer to a location at which to store a pointer to the
*        PointSet holding the physical coordinates.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     The fraction of the plotting area containing good physical
*     coordinates.

*  Notes:
*     -  This function assumes that the physical coordinate system is 2 
*     dimensional, and it should not be used if this is not the case.
*     -  The returned physical coordinates will have been normalised
*     using the astNorm method of the current Frame in the supplied Plot.
*     -  The returned PointSets should be annulled when no longer needed,
*     using astAnnul.
*     -  An error is reported if the region containing valid physical
*     coordinates is too small to use.
*     -  A function value of zero, and NULL pointers are returned if an error 
*     has already occurred, or if this function should fail for any reason.
*/

/* Local Variables: */
   AstFrame *frm;     /* Pointer to the Current Frame in the Plot */
   AstMapping *map;   /* Pointer to "graphics to physical" mapping */
   double **ptr1;     /* Pointer to physical axis value data */
   double **ptr2;     /* Pointer to graphics axis value data */
   double *pa;        /* Pointer to next value on 1st physical axis */
   double *pb;        /* Pointer to next value on 2nd physical axis */
   double *px;        /* Pointer to next value on 1st graphics axis */
   double *py;        /* Pointer to next value on 2nd graphics axis */
   double dx;         /* Cell size along graphics X (1st) axis */
   double dy;         /* Cell size along graphics Y (2nd) axis */
   double frac;       /* Fraction of good physical coordinates */
   double xmax;       /* High X bound of region containing good phy. coords */
   double xmin;       /* Low X bound of region containing good phy. coords */
   double ymax;       /* High Y bound of region containing good phy. coords */
   double ymin;       /* Low Y bound of region containing good phy. coords */
   int j;             /* Element offset */
   int ngood;         /* Number of grid points with good physical coords */

/* Initialise the returned PointSet pointers. */
   *pset1 = NULL;
   *pset2 = NULL;

/* Check the global error status. */
   if ( !astOK ) return 0.0;

/* Get the Mapping from base (graphics) to current (physical) Frame in the 
   supplied Plot. */
   map = astGetMapping( this, AST__BASE, AST__CURRENT );

/* Get a pointer to the Current Frame in the Plot. */
   frm = astGetFrame( this, AST__CURRENT );

/* Initialise the grid dimension. */
   *dim = 8;

/* We need a grid which has at least 4 good points. */
   ngood = 0;
   while( ngood < 4 && astOK ){

/* Double the grid dimension. */
      *dim *= 2;

/* Report an error if the grid is now too big. */
      if( *dim >= 256 ){
         astError( AST__VSMAL, "%s(%s): The area of the plot containing "
                   "valid coordinates is too small.", method, class );
         break;
      }

/* Get two PointSets, one holding a regular grid of graphics coordinates,
   and the other holding the corresponding physical coordinates. The grid
   covers the entire plotting area with the current grid dimension. A
   pointer to the physical axis values is returned. */
      ptr2 = MakeGrid( this, frm, map, *dim, this->xlo, this->xhi, this->ylo, 
                       this->yhi, 2, pset1, pset2, 1, method, class );

/* Get a pointer to the graphics axis values. */
      ptr1 = astGetPoints( *pset1 );

/* Check the pointers can be used. */
      if( astOK ){

/* Find the bounds in graphics coordinates of the area enclosing the
   good physical positions in the grid, and count the good positions. */
         ngood = 0;

         pa = ptr2[ 0 ];   
         pb = ptr2[ 1 ];   
         px = ptr1[ 0 ];   
         py = ptr1[ 1 ];   

         xmin = DBL_MAX;
         xmax = -DBL_MAX;
         ymin = DBL_MAX;
         ymax = -DBL_MAX;

         for( j = 0; j < (*dim)*(*dim); j++ ){
            if( *pa != AST__BAD && *pb != AST__BAD ){
               if( *px < xmin ) xmin = *px;
               if( *px > xmax ) xmax = *px;
               if( *py < ymin ) ymin = *py;
               if( *py > ymax ) ymax = *py;
               ngood++;
            }   
            px++;
            py++;
            pa++;
            pb++;
         }
      }
   }

/* Store approximate fraction of the plotting area containing good
   physical cooridnates. */
   if( astOK ) {
      frac =  ( (double) ngood )/(double)( (*dim)*(*dim) );

/* Get the size of each grid cell. */
      dx = ptr1[0][1] - ptr1[0][0];
      dy = ptr1[1][1] - ptr1[1][0];

/* Extend the area containing good points by one grid cell. */
      xmax += dx;
      xmin -= dx;
      ymax += dy;
      ymin -= dy;
    
/* If the area containing good points is significantly smaller than 
   the supplied area, create a new grid covering just the area containing
   good positions. */
      if( ( xmax - xmin ) < 0.9*( this->xhi - this->xlo ) ||
                  ( ymax - ymin ) < 0.9*( this->yhi - this->ylo ) ){

/* Find a new grid dimension which results in a cell size similar to
   the one used to create the grid, but covering only the region containing
   good physical coordinates. */
         *dim *= MAX( (xmax - xmin)/(this->xhi - this->xlo), 
                      (ymax - ymin)/(this->yhi - this->ylo) );
         if( *dim < 16 ) *dim = 16;

/* Annul the PointSet holding the current grid. */
         *pset1 = astAnnul( *pset1 );
         *pset2 = astAnnul( *pset2 );

/* Create the new grid covering the region containing good physical
   coordinates. */
         (void) MakeGrid( this, frm, map, *dim, xmin, xmax, ymin, ymax, 2,
                          pset1, pset2, 1, method, class );
      }
   }

/* Annul the Mapping from base to current Frame, and the pointer to the
   Current Frame. */
   map = astAnnul( map );
   frm = astAnnul( frm );

/* If an error has occurred, annul the two pointsets and indicate that
   there are no good points in the plotting area. */
   if( !astOK ){
      *pset1 = astAnnul( *pset1 );
      *pset2 = astAnnul( *pset2 );
      frac = 0.0;
   }

/* Return. */
   return frac;

}

static void GraphGrid( int dim, double xlo, double xhi, double ylo, 
                       double yhi, double **ptr1 ){
/*
*  Name:
*     GraphGrid

*  Purpose:
*     Fill an array with a square grid of graphics coordinates.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void GraphGrid( int dim, double xlo, double xhi, double ylo, 
*                     double yhi, double **ptr1 )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function fills the supplied array with a square grid of graphics 
*     coordinates covering the supplied area. The points are stored row by 
*     row, i.e. if the cell size for the grid is (dx,dy), the first point 
*     is (xmin,ymin), followed by (xmin+dx,ymin), (xmin+2*dx,ymin), up to 
*     (xmin+(dim-1)*dx,ymin), followed by the next row (xmin,ymin+dy),
*     (xmin+dx,ymin+dy), etc.

*  Parameters:
*     dim
*        The number of samples along each edge of the grid.
*     xlo
*        The lower bound on the first axis of the region to be covered
*        by the grid.
*     xhi
*        The upper bound on the first axis of the region to be covered
*        by the grid.
*     ylo
*        The lower bound on the second axis of the region to be covered
*        by the grid.
*     yhi
*        The upper bound on the second axis of the region to be covered
*        by the grid.
*     ptr1
*        A pointer to an array of two pointers giving the start of the two 
*        arrays to receive the values for each of the two axes of the graphics
*        coordinate data.

*/

/* Local Variables: */
   double *px;
   double *py;
   double dx;      
   double dy;
   double y;
   int i;
   int j;

/* Check the global error status. */
   if ( !astOK ) return;

/* Find the cell size. */
   dx = ( xhi - xlo )/(double)( dim - 1 );
   dy = ( yhi - ylo )/(double)( dim - 1 );
 
/* Initialise pointers to the start of the two arrays to recieve the 
   returned graphics values for each axis. */
   px = ptr1[ 0 ];
   py = ptr1[ 1 ];

/* Loop round row. */
   for( j = 0; j < dim; j++ ){

/* Get the Y coordinate of the current row. */
      y = ylo + j*dy;

/* Loop round each column in the current row. */
      for( i = 0; i < dim; i++ ){

/* Store the coordinates of the current grid point. */
         *(px++) = xlo + i*dx;
         *(py++) = y;

      }

   }

/* Return. */
   return;

}

static char *GrfItem( int item, const char *text ){
/*
*  Name:
*     GrfItem

*  Purpose:
*     Return the textual name corresponding to a specified graphical item
*     index.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     char *GrfItem( int item, const char *text )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function returns a textual description of the graphical item 
*     with the supplied index.

*  Parameters:
*     item
*        The index of the graphical item.
*     text
*        A pointer to a string which will be appended to the textual
*        description of the graphical iten. May be NULL.

*  Returned Value:
*     A pointer to a dynamically allocated string holding the textual 
*     description of the graphical item, followed by any supplied "text".

*  Notes:
*     - An error is reported and a NULL pointer returned if the 
*     index does not correspond to any graphical item.
*     - The returned pointer should be freed using astFree when it is no
*     longer needed.
*     - This function attempts to execute even if an error has already
*     occurred.

*/

/* Local Variables: */
   char *desc;              /* Pointer to the item description */
   char *ret;               /* Pointer to the returned string */
   int dlen;                /* Length of the item description */

   if( item == BORDER_ID ) {         
      desc = "Border";

   } else if ( item == GRIDLINE_ID ) {     
      desc = "Gridline";

   } else if ( item == CURVE_ID ) {        
      desc = "Curve";

   } else if ( item == NUMLABS_ID ) {      
      desc = "Numerical labels";

   } else if ( item == TEXTLABS_ID ) {     
      desc = "Textual labels";

   } else if ( item == TITLE_ID ) {        
      desc = "Title";

   } else if ( item == MARKS_ID ) {        
      desc = "Markers";

   } else if ( item == TEXT_ID ) {         
      desc = "Text string";

   } else if ( item == TICKS_ID ) {        
      desc = "Major and minor ticks";

   } else if ( item == AXIS_ID ) {         
      desc = "Axis";

   } else {
      desc = NULL;
      if( astOK ){
         astError( AST__INTER, "GrfItem: AST internal programming error - "
                   "Invalid graphical item index %d supplied to GrfItem.",
                   item );
      }
   }

   if( desc ) {
      dlen = strlen( desc );

      if( text ) {
         ret = astStore( NULL, desc, dlen + strlen( text ) + 1 );
         if( ret ) strcpy( ret + dlen, text );
      } else {
         ret = astStore( NULL, desc, dlen + 1 );
      }

   } else {
      ret = NULL;
   }

/* Return the answer. */
   return ret;
}

static void Grid( AstPlot *this_nd ){
/*
*++
*  Name:
c     astGrid
f     AST_GRID

*  Purpose:
*     Draw a set of labelled coordinate axes. 

*  Type:
*     Public virtual function.

*  Synopsis:
c     #include "plot.h"
c     void astGrid( AstPlot *this )
f     CALL AST_GRID( THIS, STATUS )

*  Class Membership:
*     Plot method.

*  Description:
c     This function draws a complete annotated set of 2-dimensional
f     This routine draws a complete annotated set of 2-dimensional 
*     coordinate axes for a Plot with (optionally) a coordinate grid
*     superimposed. Details of the axes and grid can be controlled by
*     setting values for the various attributes defined by the Plot
*     class (q.v.).

*  Parameters:
c     this
f     THIS = INTEGER (Given)
*        Pointer to the Plot.
f     STATUS = INTEGER (Given and Returned)
f        The global status.

*  Notes:
*     - An error results if either the current Frame or the base Frame
*     of the Plot is not 2-dimensional.
*     - An error also results if the transformation between the base
*     and current Frames of the Plot is not defined in either
*     direction (i.e. the Plot's TranForward or TranInverse attribute
*     is zero).
*--
*/

/* Local Variables: */
   AstAxis *ax;            /* Pointer to an axis of the current Frame */
   AstPlot *this;          /* Plot with 2d current Frame */
   AstFrame *fr;           /* Pointer to the current Frame */
   CurveData **cdata;      /* Pointer to info. about breaks in curves */
   TickInfo **grid;        /* Pointer to info. about tick marks */
   const char *class;      /* Object class */
   const char *method;     /* Current method */
   double cen[ 2 ];        /* Position of first tick mark */
   double gap[ 2 ];        /* Gap between tick marks */
   double labelat[ 2 ];    /* Axis values at which tick marks are put */
   int axis;               /* Physical axis index */
   int border;             /* Draw a border? */
   int dounits[2];         /* Include Units in each axis label? */
   int drawgrid;           /* Is a grid of lines to be drawn? */
   int clredge;            /* Clear the Edge attributes before returning? */
   int edgeticks;          /* Draw labels round edges of plotting area? */
   int ink;                /* Draw the grid with visible ink? */
   int inval;              /* Were areas of invalid coordinates found? */
   int naxes;              /* No. of axes in the base or current Frame */
   int oldedge0;           /* Default value for Edge(1) */
   int oldedge1;           /* Default value for Edge(2) */

/* Check the global error status. */
   if ( !astOK ) return;

/* Store the current method and class for inclusion in error messages
   generated by lower level functions. */
   method = "astGrid";
   class = astClass( this_nd );

/* Check the base Frame of the Plot is 2-D. */
   naxes = astGetNin( this_nd );
   if( naxes != 2 && astOK ){
      astError( AST__NAXIN, "%s(%s): Number of axes (%d) in the base "
                "Frame of the supplied %s is invalid - this number should "
                "be 2.", method, class, naxes, class );
   } 

/* Get a Plot with a 2D (or 1D) current Frame. */
   this = (AstPlot *) Fset2D( (AstFrameSet *) this_nd, AST__CURRENT );

/* Check the current Frame of the Plot is 2-D. */
   naxes = astGetNout( this );
   if( naxes != 2 && astOK ){
      astError( AST__NAXIN, "%s(%s): Number of axes (%d) in the current "
                "Frame of the supplied %s is invalid - this number should "
                "be 2.", method, class, naxes, class );
   } 

/* If the protected attribute "Ink" is set to zero, then the plot
   is drawn in "invisble ink" (i.e. all the calculations needed to
   produce the grid are performed, but nothing is actually drawn). */
   ink = astGetInk( this );   

/* Initialise the bounds of the box containing all plotted lines and
   numerical labels. */
   Box_lbnd[ 0 ] = FLT_MAX;
   Box_lbnd[ 1 ] = FLT_MAX;
   Box_ubnd[ 0 ] = FLT_MIN;
   Box_ubnd[ 1 ] = FLT_MIN;

/* Obtain the requested gap and centre attribute values for both physical 
   axes. */
   for( axis = 0; axis < 2; axis++ ){
      gap[ axis ] = astGetGap( this, axis );
      cen[ axis ] = astGetCentre( this, axis );
   }

/* Determine where to put the major axis values. */
   grid = GridLines( this, cen, gap, &inval, method, class );

/* If the user has set an explicit value for Grid, use it. */
   if( astTestGrid( this ) ){
      drawgrid = astGetGrid( this );

/* If not, the default for Grid is based on whether or not there are any 
   invalid regions. */
   } else if( inval ){
      drawgrid = 1;

   } else {
      drawgrid = 0;
   }

/* Draw the curves marking the major tick values on each axis. Information
   is returned describing the positions of the breaks in these curves. */
   cdata = DrawGrid( this, grid, ( ink && drawgrid ), method, class );

/* See if labels and tick marks will be drawn round the edges of the
   plotting area, rather than within it (no labels are actually drawn
   yet). Interior labels can always be produced, in which case edgeticks
   is set explicitly to zero to indicate that ticks will be internal.
   Exterior labelling may or may not be possible. If it is requested,
   check to see if it is possible. */
   clredge = 0;
   if( astGetLabelling( this ) ){
      edgeticks = 0;
   } else {
      edgeticks = EdgeLabels( this, 0, grid, cdata, method, class );

/* If the external labelling was requested, but could not be produced... */
      if( !edgeticks ) {

/* and if the Edge attributes have not been set... */
         if( !astTestEdge( this, 0 ) && !astTestEdge( this, 1 ) ) {

/* Try flipping the default Edge values, to see if this allows us to
   honour the requested Labelling scheme. */
            oldedge0 = astGetEdge( this, 0 );
            oldedge1 = astGetEdge( this, 1 );
            astSetEdge( this, 0, oldedge1 );
            astSetEdge( this, 1, oldedge0 );

/* See if exterior labels could be drawn with these new edges. */
            edgeticks = EdgeLabels( this, 0, grid, cdata, method, class );

/* If this would allow us to use the requested labelling scheme, retain
   the new Edge values, setting a flag to indicate that they will need to be
   cleared before returning. Otherwise, clear them. */
            if( edgeticks ) {
               clredge = 1;
            } else {
               astClearEdge( this, 0 );
               astClearEdge( this, 1 );
            }
         }
      }
   }

/* If edge ticks are being used, store bad values for the labelat values to 
   indicate that labels are not being drawn within the interior of the 
   plotting area. */
   if( edgeticks ){
      labelat[ 0 ] = AST__BAD;
      labelat[ 1 ] = AST__BAD;

/* Otherwise, see where interior labels and tick marks should go (the axis
   values are put in "labelat"). */
   } else {
      Labelat( this, grid, cdata, labelat, method, class );
   }

/* See if a border is required. By default, a border is drawn only when
   using exterior labelling. */
   if( astTestBorder( this ) ) {
      border = astGetBorder( this );
   } else {
      border = edgeticks;
   }

/* See if the Units string is to be inluded in the label. If no value has
   been set for LabelUnits, assume no for any SkyAxis axes within the 
   current frame of the Plot, and yes for other axes. */
   fr = astGetFrame( this, AST__CURRENT );

   for( axis = 0; axis < 2; axis++ ) {
      if( astTestLabelUnits( this, axis ) ){
         dounits[ axis ] = astGetLabelUnits( this, axis );
      } else {
         ax = astGetAxis( fr, axis );
         dounits[ axis ] =  astIsASkyAxis( ax ) ? 0 : 1 ;
         ax = astAnnul( ax );
      }
   }

   fr = astAnnul( fr );

/* The rest is not done if no output is required. */
   if( ink ) {

/* Draw tick marks (major and minor). */
      DrawTicks( this, grid, drawgrid, labelat, gap, method, class );

/* If required, ensure that curves through the tick marks have been drawn */
      if( astGetDrawAxes( this ) ){ 
         DrawAxis( this, grid, labelat, gap, method, class );
      }

/* If required, draw a curve around the edge of the area containing valid 
   physical coordinates. */
      if( border ) (void) astBorder( this );

/* Draw the numerical labels at the major tick values. */
      Labels( this, grid, cdata, gap, labelat, method, class );

/* Draw the textual labels for each axis and a title. */
      TextLabels( this, edgeticks, dounits, method, class );
   }

/* Store the actual values used for all attributes which have dynamic 
   defaults. Check the global status to ensure the pointer "grid" can be
   used without the possibility of a segmentation violation. */
   for( axis = 0; axis < 2 && astOK ; axis++ ) {
      SetUsedGap( this_nd, axis, gap[ axis ] );
      SetUsedCentre( this_nd, axis, cen[ axis ] );
      SetUsedEdge( this_nd, axis, astGetEdge( this, axis ) );
      SetUsedLabelAt( this_nd, axis, labelat[ axis ] );
      SetUsedLabelUnits( this_nd, axis, dounits[ axis ] );
      SetUsedMinTick( this_nd, axis, grid[ axis ]->nminor );

      if( astTestTextLab( this, axis ) ) {
         SetUsedTextLab( this_nd, axis, astGetTextLab( this, axis ) );
      } else {
         SetUsedTextLab( this_nd, axis, edgeticks );
      }
      
      if( astTestMajTickLen( this, axis ) ) {
         SetUsedMajTickLen( this_nd, axis, astGetMajTickLen( this, axis ) );
      } else {
         SetUsedMajTickLen( this_nd, axis, drawgrid ? 0.0 : 
                                           astGetMajTickLen( this, axis ) );
      }

   }

   SetUsedGrid( this_nd, drawgrid );
   SetUsedLabelling( this_nd, edgeticks ? 0 : 1 );
   SetUsedBorder( this_nd, border );

/* Free the memory used to hold information about the curves. */
   cdata = CleanCdata( cdata );

/* Free the memory used to hold information about the tick marks. */
   grid = CleanGrid( grid );

/* If required clear the Edge attributes. */
   if( clredge ) {
      astClearEdge( this, 0 );
      astClearEdge( this, 1 );
   }

/* Free the 2D Plot. */
   this = astAnnul( this );

/* Return. */
   return;

}

static void GridLine( AstPlot *this, int axis, const double start[], 
                      double length ){
/*
*++
*  Name:
c     astGridLine
f     AST_GRIDLINE

*  Purpose:
*     Draw a grid line (or axis) for a Plot.

*  Type:
*     Public virtual function.

*  Synopsis:
c     #include "plot.h"
c     void astGridLine( AstPlot *this, int axis, const double start[], 
c                       double length )
f     CALL AST_GRIDLINE( THIS, AXIS, START, LENGTH, STATUS )

*  Class Membership:
*     Plot method.

*  Description:
c     This function draws a curve in the physical coordinate system of
f     This routine draws a curve in the physical coordinate system of
*     a Plot by varying only one of the coordinates along the length
*     of the curve. It is intended for drawing coordinate axes,
*     coordinate grids, and tick marks on axes (but note that these
c     are also available via the more comprehensive astGrid function).
f     are also available via the more comprehensive AST_GRID routine).
*
*     The curve is transformed into graphical coordinate space for
*     plotting, so that a straight line in physical coordinates may
*     result in a curved line being drawn if the Mapping involved is
*     non-linear. Any discontinuities in the Mapping between physical
*     and graphical coordinates are catered for, as is any
c     clipping established using astClip.
f     clipping established using AST_CLIP.

*  Parameters:
c     this
f     THIS = INTEGER (Given)
*        Pointer to the Plot.
c     axis
f     AXIS = INTEGER (Given)
*        The index of the Plot axis whose physical coordinate value is
*        to be varied along the length of the curve (all other
*        coordinates will remain fixed). This value should lie in the
*        range from 1 to the number of Plot axes (Naxes attribute).
c     start
f     START( * ) = DOUBLE PRECISION (Given)
*        An array, with one element for each axis of the Plot, giving
*        the physical coordinates of the start of the curve.
c     length
f     LENGTH = DOUBLE PRECISION (Given)
*        The length of curve to be drawn, given as an increment along
*        the selected physical axis. This may be positive or negative.
f     STATUS = INTEGER (Given and Returned)
f        The global status.

*  Notes:
c     - No curve is drawn if the "start" array contains any
c     coordinates with the value AST__BAD, nor if "length" has this value.
f     - No curve is drawn if the START array contains any
f     coordinates with the value AST__BAD, nor if LENGTH has this value.
*     - An error results if the base Frame of the Plot is not 2-dimensional.
*     - An error also results if the transformation between the
*     current and base Frames of the Plot is not defined (i.e. the
*     Plot's TranInverse attribute is zero).
*--
*/
/* Local Variables: */
   const char *class;      /* Object class */
   const char *method;     /* Current method */
   int naxes;              /* No. of axes in the base Frame */

/* Check the global error status. */
   if ( !astOK ) return;

/* Store the current method, and the class of the supplied object for use 
   in error messages.*/
   method = "astGridLine";
   class = astGetClass( this );

/* Check the base Frame of the Plot is 2-D. */
   naxes = astGetNin( this );
   if( naxes != 2 && astOK ){
      astError( AST__NAXIN, "%s(%s): Number of axes (%d) in the base "
                "Frame of the supplied %s is invalid - this number should "
                "be 2.", method, class, naxes, class );
   } 

/* Validate the axis index, converting the axis index to be zero-based. */
   (void) astValidateAxis( this, axis - 1, method );

/* Draw the curve. The break information is stored in an external structure
   where it can be accessed by public methods which return information
   about the most recently drawn curve. */
   AxPlot( this, axis - 1, start, length, 1, &Curve_data, 1, method, class );

/* Return. */
   return;

}

static TickInfo **GridLines( AstPlot *this, double *cen, double *gap, 
                             int *inval, const char *method, const char *class ){
/*
*  Name:
*     GridLines

*  Purpose:
*     Obtain information desribing the major tick values within the plotting 
*     area.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     TickInfo **GridLines( AstPlot *this, double *cen, double *gap, 
*                           int *inval, const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     A pointer is returned which points to an array of two pointers. Each
*     of these pointers points to a TickInfo structure which holds
*     information about the ticks on a single axis. These structures,
*     together with the array holding the two pointers, should be released
*     when no longer needed using CleanGrid.

*  Parameters:
*     this
*        The Plot.
*     cen
*        A pointer to an array holding axis values at which to put a single 
*        central tick. Other ticks are placed evenly on either side of this 
*        tick. If AST__BAD is provided, a value will be used which would put a 
*        tick at an axis value of zero.
*     gap
*        A pointer to an array holding the gaps between ticks required on
*        each axis. If this is AST__BAD a suitable default value will be used
*        and returned in place of the AST__BAD value.
*     inval
*        A pointer to a location at which to return a flag indicating if
*        any invalid physical coordinates were encountered while deciding on 
*        the tick values. 
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     A pointer to an array of two TickInfo pointers.

*  Notes:
*     -  This function assumes that the physical coordinate system is 2 
*     dimensional, and it should not be used if this is not the case.
*     -  If an error has already occurred, or if this function should fail 
*     for any reason, then a NULL pointer is returned.
*/

/* Local Variables: */
   TickInfo **info;       /* Returned array of two TickInfo pointers */
   double *lengths;       /* Pointer to lengths of each curve section */
   double *starts;        /* Pointer to start of each curve section */
   double *ticks;         /* Pointer to tick mark values */
   int i;                 /* Tick mark index */
   int j;                 /* Axis index */
   int k;                 /* Section index */
   int nticks;            /* Number of tick marks */

/* Check the global status. */
   if( !astOK ) return NULL;

/* Get memory to hold two TickInfo pointers. */
   info = (TickInfo **) astMalloc( 2*sizeof( TickInfo *) );

/* If succesful, initialise the two pointers. */
   if( astOK ){
      info[ 0 ] = NULL;
      info[ 1 ] = NULL;

/* Obtain the tick mark values, and the corresponding formatted labels for
   each axis. */
      for( j = 0; j < 2; j++ ){
         info[ j ] = TickMarks( this, j, cen + j, gap + j, inval, method, class );
      }

/* Release the resources allocated in the first call to TickMarks. */
      (void) TickMarks( NULL, 0, NULL, gap, NULL, method, class );

/* Each major tick value for axis "j" may be marked with a curve parallel
   to axis "1-j" drawn across the entire plotting area. We need to decide
   where to start drawing this curve and how long it should be. We can
   simply use the minimum value on axis "1-j" together with the tick value
   on axis "j" to define the starting position. The length could be taken
   as the difference between the maximum and minimum values on axis "1-j".
   However, this may not be right in some situations. For instance if the 
   plotting area covers a small range of Right Ascension from 23:59:59 to
   00:00:01. Using the difference between the maximum and minimum values 
   to give the length of the curve would result in the curve starting at
   00:00:00 (the minimum axis value) and extending for a length of 23:59:59
   (the axis range). To get round this sort of problem, the curve is split
   up into sections with lengths and starting positions determined by the
   tick mark values on axis "1-j". The first section starts at the minimum 
   axis value and extends upto the first missing tick mark (in the RA
   example, this would be at 00:00:01). Subsequent sections starts at the
   next tick mark (23:59:59 in the RA example) and extends upto the next
   missing tick mark, or the last tick mark if none are missing. */

/* Find the start and length of each section of the curve for each tick
   mark on axis "j". */
      for( j = 0; j < 2 && astOK; j++ ){

/* Get a pointer to the major tick mark values on the other axis ("1-j"), 
   together with the number of them. */
         ticks = info[ 1 - j ]->ticks;
         nticks = info[ 1 - j ]->nmajor;

/* Reserve memory to hold the starts and lengths of each section of the 
   grid line marking the major ticks on the axis "j". The allocated
   arrays are the largest that could possibly be needed (i.e. if every
   tick mark starts a new section). */
         starts = (double *) astMalloc( sizeof(double)*(size_t) nticks );
         lengths = (double *) astMalloc( sizeof(double)*(size_t) nticks );
         info[ j ]->start = starts;
         info[ j ]->length = lengths;

/* Check that the pointers can be used. */
         if( astOK ) {

/* Loop round each of the major tick marks on axis "1-j". */
            k = 0;
            i = 0;
            while( i < nticks ){

/* Record the start of the next section of the grid lines. */
               starts[ k ] = ticks[ i++ ];

/* Tick marks should be regularly spaced by the values in "gap". Check each 
   tick mark until a missing tick mark is  found. The section ends at the 
   start of the gap. */
               while( i < nticks && 
                      ( ticks[ i ] - ticks[ i - 1 ] ) < 1.5*gap[ 1 - j ] ) i++;

/* Record the length of the section. */
               lengths[ k ] = ticks[ i - 1 ] - starts[ k ];   

/* The section is extended at start and end by one gap in order to "cover
   up the joins". */
               starts[ k ] -= gap[ 1 - j];
               lengths[ k ] += 2.0*gap[ 1 - j ];

/* Increment the number of sections. */
               k++;
            }

/* Store the number of sections in the returned structure. */
            info[j]->nsect = k;
      
         }
      }   
   }

/* If an error has occurred, clean up the returned TickInfo structures. */
   if( !astOK ) info = CleanGrid( info );

/* Return. */
   return info;   

}

void GrfAttrs( AstPlot *this, int id, int set, int prim ){
/*
*  Name:
*     GrfAttrs

*  Purpose:
*     Establish values for the graphics attributes for a given object.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void GrfAttrs( AstPlot *this, int id, int set, int prim )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function should be called with "set=1" to establish the correct 
*     graphics attributes prior to drawing specific graphical objects. Once 
*     the object has been drawn, it should be called again with "set=0" to 
*     re-establish the original graphics attributes.
*
*     NOTE, each type of graphical object identified by "id" should be
*     drawn entirely by calls to just one of astGMark, astGText or astGLine
*     as indicated by argument "prim".

*  Parameters:
*     this
*        A pointer to the Plot.
*     id
*        An integer specifying the graphical object to be drawn. The 
*        following symbolic values should be used:
*
*        BORDER_ID   - The boundary curve drawn by astBorder.
*        GRIDLINE_ID - Curves drawn by astGridLine.
*        CURVE_ID    - Curves drawn by astCurve or astPolyCurve.
*        NUMLABS_ID  - Numerical labels.
*        TEXTLABS_ID - Textual axis labels (not the title).
*        TITLE_ID    - The grid title.
*        MARKS_ID    - Marks drawn with astMark.
*        TEXT_ID     - Text strings drawn with astText.
*        TICKS_ID    - Major and minor tick marks 
*        AXIS_ID     - Axes through interior tick marks 
*     set
*        If non-zero then the attributes for the specified object are set
*        to the values indicated by the corresponding Plot attributes,
*        and the current values are saved in a static array. If zero, then 
*        the values are set to the values stored in the static array.
*     prim
*        Indicates the sort of graphics primative used to draw the
*        object. This must be one of (defined in grf.h) :
*
*           GRF__LINE
*           GRF__MARK
*           GRF__TEXT

*  Notes:
*     -  This function should always be called in pairs with set=1 on the
*     first call and set=0 on the second call. 
*     -  If a pair of calls is nested within another pair of calls, the
*     inner pair has no effect.

*/

/* Local Variables: */
   static double attrs[ GRF__NATTR ]; /* Saved attribute values */
   double *attr;           /* Pointer to the next attribute value */
   double dval;            /* Floating point attribute value */
   int ival;               /* Integer attribute value */
   static int nesting=0;   /* Nesting level. */

/* Check the global status. */
   if( !astOK ) return;

/* Set up a pointer to the next element in "attrs". */
   attr = attrs;

/* If we are setting new values, increment the nesting level, otherwise
   decrement it. */
   if( set ){
      nesting++;
   } else {
      nesting--;
   } 

/* First deal with cases where we are establishing new values for the
   graphics attributes by setting them to the values of the corresponding
   Plot attributes. Only do this if we are at nesting level one. */
   if( set && nesting == 1 ){

/* See if a value has been set in the Plot for the line style attribute for 
   the specified object, If so, get the value. */
      if( astTestStyle( this, id ) ){
         ival = astGetStyle( this, id );      

/* Save the current value, and establish the new value. */
         astGAttr( GRF__STYLE, (double) ival, attr++, prim );

/* If no style was specified, retain the current value. Indicate that no
   new value has been established by setting the old value bad. */
      } else {
         *(attr++) = AST__BAD;
      }

/* Do the same for the line width attribute. */
      if( astTestWidth( this, id ) ){
         dval = astGetWidth( this, id );      
         astGAttr( GRF__WIDTH, dval, attr++, prim );
      } else {
         *(attr++) = AST__BAD;
      }

/* Do the same for the character size attribute. */
      if( astTestSize( this, id ) ){
         dval = astGetSize( this, id );      
         astGAttr( GRF__SIZE, dval, attr++, prim );
      } else {
         *(attr++) = AST__BAD;
      }

/* Do the same for the character font attribute. */
      if( astTestFont( this, id ) ){
         ival = astGetFont( this, id );      
         astGAttr( GRF__FONT, (double) ival, attr++, prim );
      } else {
         *(attr++) = AST__BAD;
      }

/* Do the same for the colour attribute. */
      if( astTestColour( this, id ) ){
         ival = astGetColour( this, id );      
         astGAttr( GRF__COLOUR, (double) ival, attr++, prim );
      } else {
         *(attr++) = AST__BAD;
      }

   }

/* Now deal with cases where we are re-establishing old values saved on a
   previous call to this function. Only do this if we are at nesting
   level zero. */
   if( !set && !nesting ){
      astGAttr( GRF__STYLE, *(attr++), NULL, prim );
      astGAttr( GRF__WIDTH, *(attr++), NULL, prim );
      astGAttr( GRF__SIZE, *(attr++), NULL, prim );
      astGAttr( GRF__FONT, *(attr++), NULL, prim );
      astGAttr( GRF__COLOUR, *(attr++), NULL, prim );
   }

/* Return. */
   return;

}

static int GrText( AstPlot *this, int esc, const char *text, int ink, 
                   int bbclip, float x, float y, float upx, float upy, 
                   float *xbn, float *ybn, const char *method, 
                   const char *class ){
/*
*+
*  Name:
*     GrText

*  Purpose:
*     Draw a character string, potentially including superscripts and
*     subscripts.

*  Synopsis:
*     #include "plot.h"
*     int GrText( AstPlot *this, int esc, const char *text, int ink, 
*                 int bbclip, float x, float y, float upx, float upy, 
*                 float *xbn, float *ybn, const char *method, 
*                 const char *class )

*  Description:
*     This function displays a character string at a given position
*     using a specified up-vector, optionally interpreting any Plot escape 
*     sequences contained within the text. The bounding box enclosing the
*     text is returned, optionally clipped at the top and bottom of the 
*     "normal" text (i.e. text as determined by the current Plot attribute 
*     settings). The position of the text is determined by supplying the 
*     coordinates of the bottom left corner of this bounding box.

*  Parameters:
*     this
*        The plot.
*     esc
*        Should escape sequences be interpreted? They will be printed
*        literally otherwise.
*     text 
*        Pointer to a null-terminated character string to be displayed.
*     ink
*        If zero, no text is drawn on the screen, but the bounding box is
*        still returned.
*     bbclip
*        If non-zero, then the top and bottom edges of the returned bounding 
*        box are determined by the "normal" text. This may result in 
*        super-scripts and sub-scripts extending above or below the bounding 
*        box. The width of the bounding box always encloses all text.
*     x 
*        The x coordinate at the left hand end of the base-line for
*        "normal" text.
*     y 
*        The y coordinate at the left hand end of the base-line for
*        "normal" text.
*     upx
*        The x component of the up-vector for the text. Positive values
*        always refer to displacements from left to right on the screen, 
*        even if the graphics x axis increases in the opposite sense.
*     upy
*        The y component of the up-vector for the text. Positive values
*        always refer to displacements from left to right on the screen, 
*        even if the graphics y axis increases in the opposite sense.
*     xbn
*        An array in which is returned the x coordinates at the corners
*        of the bounding box. If "esc" is non-zero, then these corners
*        are in the order; bottom-left, bottom-right, top-right, top-left.
*        If "esc" is zero, the order is not specified.
*     ybn
*        An array in which is returned the Y coordinates at the corners
*        of the bounding box (see xbn).
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     Zero for failure, one for success.

*  Escape Sequences:
*     Escape sequences are introduced into the text string by a percent 
*     "%" character. The following escape sequences are currently recognised 
*     ("..." represents a string of one or more decimal digits):
*
*       %%      - Print a literal "%" character.
*
*       %^...+  - Draw subsequent characters as super-scripts. The digits
*                 "..." give the distance from the base-line of "normal" 
*                 text to the base-line of the super-script text, scaled 
*                 so that a value of "100" corresponds to the height of 
*                 "normal" text.
*       %^+     - Draw subsequent characters with the normal base-line.
*
*       %v...+  - Draw subsequent characters as sub-scripts. The digits
*                 "..." give the distance from the base-line of "normal" 
*                 text to the base-line of the sub-script text, scaled 
*                 so that a value of "100" corresponds to the height of 
*                 "normal" text.
*
*       %v+     - Draw subsequent characters with the normal base-line
*                 (equivalent to %^+).
*
*       %>...+  - Leave a gap before drawing subsequent characters.
*                 The digits "..." give the size of the gap, scaled 
*                 so that a value of "100" corresponds to the height of 
*                 "normal" text.
*
*       %s...+  - Change the Size attribute for subsequent characters. The
*                 digits "..." give the new Size as a fraction of the 
*                 "normal" Size, scaled so that a value of "100" corresponds 
*                 to 1.0;
*
*       %s+     - Reset the Size attribute to its "normal" value.
*
*       %w...+  - Change the Width attribute for subsequent characters. The
*                 digits "..." give the new width as a fraction of the 
*                 "normal" Width, scaled so that a value of "100" corresponds 
*                 to 1.0;
*
*       %w+     - Reset the Wize attribute to its "normal" value.
*
*       %f...+  - Change the Font attribute for subsequent characters. The
*                 digits "..." give the new Font value.
*
*       %f+     - Reset the Font attribute to its "normal" value.
*
*       %c...+  - Change the Colour attribute for subsequent characters. The
*                 digits "..." give the new Colour value.
*
*       %c+     - Reset the Colour attribute to its "normal" value.
*
*       %t...+  - Change the Style attribute for subsequent characters. The
*                 digits "..." give the new Style value.
*
*       %t+     - Reset the Style attribute to its "normal" value.
*
*       %+      - Reset all attributes to their "normal" values.

*  Notes:
*     -  Any graphics within the rotated box enclosing the text are
*     erased if argument ink is non-zero.
*     -  Both "upx" and "upy" being zero causes an error.
*-
*/

/* Local Variables: */
   char *ltext;		/* Pointer to local copy of text */
   char *p;		/* Pointer to start of current sub-string */
   char *pp;		/* Pointer to next character */
   char *sl;		/* Pointer to start of next sub-string */
   char *t;		/* Pointer to next character */
   char et;		/* Character at start of the next sub-string */
   char oc;		/* Old sub-string termination character */
   double a;            
   double b;            
   double bot;          /* Fractional height to bottom of bounding box */
   double h;		/* Height of plotted text */
   double hd;		/* Height from text base-line to box bottom. */
   double hu;		/* Height from text base-line to box top. */
   double l;		/* Length of supplied up-vector */
   double ncolour;      /* Colour attribute value on entry */
   double nfont;        /* Font attribute value on entry */
   double nl;		/* Character height in world coordinates */
   double nsize;	/* Size attribute for normal text */
   double nstyle;       /* Style attribute value on entry */
   double nwidth;       /* Width attribute value on entry */
   double off;          /* Fractional height to baseline */
   double test;         /* Height from base-line to corner i */
   double top;          /* Fractional height to top of bounding box */
   double tw;           /* Total width of bounding box */
   double ux;		/* X comp. of graphics up-vector */
   double uxn;		/* X comp. of unit graphics up-vector */
   double uy;		/* Y comp. of graphics up-vector */
   double uyn;		/* Y comp. of unit graphics up-vector */
   double vx;		/* X comp. of graphics base-vector */
   double vy;		/* Y comp. of graphics base-vector */
   double w;		/* Width of plotted text */
   double x0;		/* X at bottom left corner of sub-string */
   double xbase;	/* X at base-line at start of sub-string */
   double y0;		/* Y at bottom left corner of sub-string */
   double ybase;	/* Y at base-line at start of sub-string */
   float alpha;         /* Scale factor for X axis */
   float beta;          /* Scale factor for Y axis */
   float chh;		/* Size in world coords of a horizontal character */
   float chv;		/* Size in world coords of a vertical character */
   float txbn[ 4 ];     /* X at corners of sub-string bounding box */
   float tybn[ 4 ];     /* Y at corners of sub-string bounding box */
   float xr;            /* World X value at sub-string reference point */
   float yr;            /* World Y value at sub-string reference point */
   int dd;              /* Escape sequence argument value */
   int i;               /* Corner index */
   int n;               /* No. of characters in sub-string */
   int nc;              /* No. of digits read from escape sequence */
   int nesc;            /* No. of characters in escape sequence */
   int ret;             /* Returned status */

/* Check the global error status. */
   if ( !astOK ) return 0;

/* Assume success. */
   ret = 1;

/* First deal with cases where any escape sequences are to be interpreted. */
   if( esc && text ) {

/* Get the scales on the two world coordinate axes. */

/* NOTE --- The facility for including escape characters is currently
   disabled. When it is enabled, the following lines of code should be
   replaced by the following block which ic currently commented out. 
   (ENABLE-ESCAPE) */
      if ( 1 ) {
         alpha = 1.0;
         beta = 1.0;

/*
      if( !astGAxScale( &alpha, &beta ) ) {
         ret = 0;
         astError( AST__GRFER, "%s(%s): Graphics error in astGAxScale. ", 
                   method, class );
*/


/* Ensure that the supplied up-vector refers to world coordinate axes in
   their correct senses. */
      } else {
         ux = ( this->xrev ) ? -upx : upx;
         uy = ( this->yrev ) ? -upy : upy;

/* Convert the up-vector into "standard" system in which the axes have
   equal scales, and increase left-to-right, bottom-to-top. */
         ux *= alpha;
         uy *= beta;

/* Normalise this up-vector. */
         l = sqrt( ux*ux + uy*uy );
         if( l <= 0.0 ) {
           ux = 0.0;
           uy = 1.0;
         } else {
           ux /= l;
           uy /= l;
         }

/* Get the vector along the base-line of the text, by rotating the 
   up-vector by 90 degrees clockwise. */
         vx = uy;   
         vy = -ux;
      }      

/* Take a copy of the supplied string. */
      ltext = (char *) astStore( NULL, (void *) text, strlen( text ) + 1 );

/* Store the position on the base-line of the "normal" characters  which is 
   at the start of the next sub-string, relative to the supplied reference 
   position. */
      xbase = 0.0;
      ybase = 0.0;

/* Store the position of the bottom left corner of the next sub-string. */
      x0 = xbase;
      y0 = ybase;

/* Get the attributes for "normal" characters. */
      astGAttr( GRF__SIZE, AST__BAD, &nsize, GRF__TEXT );
      astGAttr( GRF__WIDTH, AST__BAD, &nwidth, GRF__TEXT );
      astGAttr( GRF__FONT, AST__BAD, &nfont, GRF__TEXT );
      astGAttr( GRF__STYLE, AST__BAD, &nstyle, GRF__TEXT );
      astGAttr( GRF__COLOUR, AST__BAD, &ncolour, GRF__TEXT );

/* Find the height in "standard" coordinates of "normal" text draw with the 
   requested up-vector. */
      astGQch( &chv, &chh );
      a = beta*chh*ux;
      b = alpha*chv*uy;
      nl = sqrt( a*a + b*b );

/* Save a copy of the unit up-vector. */
      uxn = ux;
      uyn = uy;

/* Scale the up-vector so that its length is equal to the height of 
   "normal" text with the specified up-vector. */
      ux *= nl;
      uy *= nl;

/* Initialise the base-line offset for "normal" text, and the fractional 
   height to the top and bottom of the un-clipped bounding box. */
      off = 0.0;
      bot = 0.0;
      top = 0.0;

/* Initialise a pointer to the next character to be read from the text
   string. */
      p = ltext;

/* Initialise the total width of the string to zero. */
      tw = 0.0;

/* Loop until the whole string has been printed. */
      while( p && *p ) {

/* Loop until the start of a new sub-string is found. Variable p points
   to the first character in the sub-string. Variable sl ends up pointing 
   at the first character in the next substring. Variable nesc ends up
   holding the number of escape characters to skip in the subsequent
   sub-string. */
         pp = p;
         while( 1 ) {

/* Find the next occurrence of the escape character. */
            sl = strchr( pp, '%' );

/* If no more escape characters were found, print up to the end of the
   whole string. */
            if( !sl ) {
               et = 0;
               nesc = 0;
               sl = strchr( pp, 0 );
               break;
            }

/* Get the character following the next escape character. */
            et = *(sl + 1);

/* If the escape character is the last character in the string, print up
   to the end of the whole string. */
            if( !et ) {
               sl++;
               nesc = 0;
               break;

/* If this is an escaped percent, shuffle the contents of the string
   down one character to over-write the escape character, and continue to
   find the next escape character. */
            } else if( et == '%' ) {
               t = sl;
               while ( *(t++) ) *( t - 1 ) = *t;
               pp++;

/* If this is a "reset all" escape sequence, set the number of characters
   to be skipped, and leave the loop. */
            } else if( et == '+' ) {
               nesc = 2;
               break;

/* If this is an attribute setting escape sequence... */
            } else if( et == 's' || et == '^' || et == 'v' || et == '>' ||
                       et == 'w' || et == 'f' || et == 'c' || et == 't' ) {

/* If the following character is a "+", set the new value for the attribute
   to INT_MAX to indicate that the "normal" value is to be used. */
              if( *( sl + 2 ) == '+' ) {
                  dd = INT_MAX;
                  nesc = 3;
                  break;

/* Otherwise, extract any digits following the escape character. If a
   valid digits field is found, store the number of characters in the escape
   sequence and leave the loop. */
               } else if( (nc = 0, sscanf( sl + 2, "%d%n", &dd, &nc )) &&
                          *(sl + 2 + nc) == '+' ){
                  nesc = nc + 3;
                  break;

/* If the digits field could not be read, print the whole escape sequence
   literally. */
               } else {
                  pp++;
               }

/* Skip over unrecognised escape sequence, printing them literally. */
            } else {
              pp++;
            }
         }

/* Find the number of characters in the next sub-string. */
         n = sl - p;

/* Print the sub-string if it has non-zero length. */
         if( n > 0 ) {

/* Get the reference position in world coordinates. */
            xr = x + ( x0/alpha );
            yr = y + ( y0/beta );

/* Temporarily terminate the sub-string. */
            oc = *sl;
            *sl = 0;            

/* Draw the sub-string (if required). */
            if( ink ) {
               if( !astGText( p, xr, yr, "BL", upx, upy ) ) {
                  ret = 0;
                  astError( AST__GRFER, "%s(%s): Graphics error in astGText. ", 
                            method, class );
                  break;
               }
            }

/* Find the bounding box of the sub-string. */
            if( !astGTxExt( p, xr, yr, "BL", upx, upy, txbn, tybn ) ){
               astError( AST__GRFER, "%s(%s): Graphics error in astGTxExt.", 
                         method, class );
            } 

/* Convert the bounding box positions into "standard" coordinates
   relative to the left hand end of the text base-line. */
            for( i = 0; i < 4; i++ ){
               txbn[ i ] = ( txbn[ i ] - x ) * alpha;
               tybn[ i ] = ( tybn[ i ] - y ) * beta;
            }

/* Find the height of the top and bottom of the bounding box above and
   below the text base-line. */
            hu = -FLT_MAX;
            hd = FLT_MAX;
            for( i = 0; i < 4; i++ ){
               test = uxn*( txbn[ i ] - x0 ) + uyn*( tybn[ i ] - y0 );
               if( test > hu ) hu = test;
               if( test < hd ) hd = test;
            }

/* Find the total height of the bounding box. */
            h = hu - hd;

/* Find the width of the bounding box. */
            w = 0.0;
            for( i = 0; i < 4; i++ ){
               test = vx*( txbn[ i ] - x0 ) + vy*( tybn[ i ] - y0 );
               if( test > w ) w = test;
            }
  
/* Find the position on the base-line of the normal characters which is
   at the end of the sub-string just drawn. */
            xbase += vx*w;
            ybase += vy*w;

/* Initialise the coordinates of the bottom left corner of the next
   sub-string to be on the "normal" base-line. */
            x0 = xbase;
            y0 = ybase;

/* Update the width of the total bounding box. */
            tw += w;

/* Update the fractional height to the top and bottom of the 
   total bounding box. */
            top = MAX( top, off + hu/nl );
            bot = MIN( bot, off + hd/nl );

/* Reinstate the original escape character. */
            *sl = oc;
         }

/* Increment the pointer to the start of the next sub-string, skipping
   the escape sequence characters. */
         p = sl + nesc;

/* Leave the loop if the end of the string has been reached. */
         if( !et ) {
            break;

/* If required, leave a gap before the next character. */
         } else if( et == '>' ) {         
            if( dd != INT_MAX ) {

/* Find the width of the gap and increment the total width of the string. */
               w = nl*( (double) dd )/100.0;
               tw += w;

/* Move on the position for the next character. */
               xbase += vx*w;
               ybase += vy*w;
               x0 += vx*w;
               y0 += vy*w;

            }

/* For up super-scripts and sub-scripts, set up the coordinates of the 
   bottom left corner of the next sub-string. This is offset away from 
   [xbase,ybase] in the direction of the up-vector. */
         } else if( et == '^' ) {         
            if( dd != INT_MAX ) {
               off = dd/100.0;
            } else {
               off = 0.0;
            }
            x0 += ux*off;
            y0 += uy*off;

         } else if( et == 'v' ) {         
            if( dd != INT_MAX ) {
               off = -dd/100.0;
            } else {
               off = 0.0;
            }
            x0 += ux*off;
            y0 += uy*off;

/* For size changes, set the new size as a fraction of the normal size. */
         } else if( et == 's' ) {         
            if( dd != INT_MAX ) {
               astGAttr( GRF__SIZE, ((double) dd/100.0)*nsize, NULL, GRF__TEXT );
            } else {
               astGAttr( GRF__SIZE, nsize, NULL, GRF__TEXT );
            }

/* For width changes, set the new width as a fraction of the normal width. */
         } else if( et == 'w' ) {         
            if( dd != INT_MAX ) {
               astGAttr( GRF__WIDTH, ((double) dd/100.0)*nwidth, NULL, GRF__TEXT );
            } else {
               astGAttr( GRF__WIDTH, nwidth, NULL, GRF__TEXT );
            }

/* For font changes, set the new font. */
         } else if( et == 'f' ) {         
            if( dd != INT_MAX ) {
               astGAttr( GRF__FONT, (double) dd, NULL, GRF__TEXT );
            } else {
               astGAttr( GRF__FONT, nfont, NULL, GRF__TEXT );
            }

/* For colour changes, set the new colour. */
         } else if( et == 'c' ) {         
            if( dd != INT_MAX ) {
               astGAttr( GRF__COLOUR, (double) dd, NULL, GRF__TEXT );
            } else {
               astGAttr( GRF__COLOUR, ncolour, NULL, GRF__TEXT );
            }

/* For style changes, set the new style. */
         } else if( et == 't' ) {         
            if( dd != INT_MAX ) {
               astGAttr( GRF__STYLE, (double) dd, NULL, GRF__TEXT );
            } else {
               astGAttr( GRF__STYLE, nstyle, NULL, GRF__TEXT );
            }

/* Reset everything if required. */
         } else if( et == '+' ) {         
            off = 0.0;
            x0 = xbase;
            y0 = ybase;
            astGAttr( GRF__SIZE, nsize, NULL, GRF__TEXT );
            astGAttr( GRF__WIDTH, nwidth, NULL, GRF__TEXT );
            astGAttr( GRF__COLOUR, ncolour, NULL, GRF__TEXT );
            astGAttr( GRF__FONT, nfont, NULL, GRF__TEXT );
            astGAttr( GRF__STYLE, nstyle, NULL, GRF__TEXT );
         }
      }

/* Convert the up and base-line vectors back into world coordinates. */
      ux /= alpha;
      uy /= beta;
      vx /= alpha;
      vy /= beta;
   
/* Set up the returned bounding box. */
      if( bbclip ) {
         xbn[ 0 ] = x;
         ybn[ 0 ] = y;
         xbn[ 1 ] = x + tw*vx;
         ybn[ 1 ] = y + tw*vy;
         xbn[ 2 ] = x + ux + tw*vx;
         ybn[ 2 ] = y + uy + tw*vy;
         xbn[ 3 ] = x + ux;
         ybn[ 3 ] = y + uy;

      } else {
         xbn[ 0 ] = x + bot*ux;
         ybn[ 0 ] = y + bot*uy;
         xbn[ 1 ] = x + bot*ux + tw*vx;
         ybn[ 1 ] = y + bot*uy + tw*vy;
         xbn[ 2 ] = x + top*ux + tw*vx;
         ybn[ 2 ] = y + top*uy + tw*vy;
         xbn[ 3 ] = x + top*ux;
         ybn[ 3 ] = y + top*uy;
      }

/* Ensure any future text comes out with "normal" attributes. */
      astGAttr( GRF__SIZE, nsize, NULL, GRF__TEXT );
      astGAttr( GRF__WIDTH, nwidth, NULL, GRF__TEXT );
      astGAttr( GRF__COLOUR, ncolour, NULL, GRF__TEXT );
      astGAttr( GRF__FONT, nfont, NULL, GRF__TEXT );
      astGAttr( GRF__STYLE, nstyle, NULL, GRF__TEXT );

/* Free the local copy of the supplied string. */
      ltext = (char *) astFree( (void *) ltext );

/* If escape sequences are to be printed literally, just display
   the text as supplied. */
   } else {
      if( ink ) {
         if( !astGText( text, x, y, "BL", upx, upy ) ) {
            ret = 0;
            astError( AST__GRFER, "%s(%s): Graphics error in astGText. ", 
                      method, class );
         }
      }

/* Find the bounding box of the text. */
      if( !astGTxExt( text, x, y, "BL", upx, upy, xbn, ybn ) ){
         astError( AST__GRFER, "%s(%s): Graphics error in astGTxExt.", 
                   method, class );

      } 
   }

/* Return the status. */
   return ret;

}

static int GVec( AstPlot *this, AstMapping *mapping, double *phy, 
                 int axis, double delta, AstPointSet **pset1, 
                 AstPointSet **pset2, double *gx, double *gy, 
                 double *dx, double *dy, int *flag, const char *method, 
                 const char *class ){
/*
*  Name:
*     GVec

*  Purpose:
*     Returns a unit vector parallel to a physical axis at a given point.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int GVec( AstPlot *this, AstMapping *mapping, double *phy, 
*               int axis, double delta, AstPointSet **pset1, 
*               AstPointSet **pset2, double *gx, double *gy, 
*               double *dx, double *dy, int *flag, const char *method, 
*               const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function returns a unit vector (in the graphics coordinate
*     system) in the positive direction of the specified physical axis, 
*     at the given physical position. It works by transforming the given 
*     physical position, together with another very close position, and
*     returning the vector between them. It is possible for a 
*     discontinuity to occur between these two close positions, 
*     resulting in a very large meaningless vector prior to 
*     normalisation. For this reason two vectors are found, one joining 
*     the given position to a close position higher up the axis, and one 
*     joining a close position lower down the axis to the given position.
*     If these two vectors differ in magnitude by a large factor, then
*     the shorter of the two vectors is normalised and returned. 
*     Otherwise, the vector which is closest in direction to the vector
*     supplied in [dx,dy] is returned. The returned vector is reversed if
*     necessary so that it always points in the positive direction of the
*     axis.
*
*     If neither of the two vectors can be found (i.e. if the graphics
*     coordinates are bad, or coincident), then the vector supplied in 
*     [dx,dy] is returned unchanged, and a function value of zero is 
*     returned. Otherwise, a function value of one is returned.

*  Parameters:
*     this
*        Pointer to the Plot.
*     mapping
*        Pointer to the Mapping from the base Frame of the Plot ot the
*        current Frame.
*     phy
*        Pointer to an array holding the coordinates in the current Frame
*        of the Plot at which the tangent vector is required.
*     axis
*        The index of the axis within the current Frame for which the
*        tangent vector is required.
*     delta
*        The increment in the axis value to use between positions defining
*        the vectors.
*     pset1
*        A pointer to a place at which to store a pointer to a PointSet
*        holding current Frame coordinates. This PointSet pointer should 
*        be supplied as NULL on the first call to this function, resulting
*        in a new PointSet being created and a pointer to it returned.
*        Subsequent calls to this function shopuld retain the pointer
*        returned by the first call. The PointSet pointer should be
*        annulled using astAnnul when no longer needed.
*     pset2
*        A pointer to a place at which to store a pointer to a PointSet
*        holding base Frame coordinates. This PointSet is managed in the
*        same way as "pset1".
*     gx
*        A pointer to a double in which to return the graphics X
*        coordinate of the position supplied by "phy".
*     gy
*        A pointer to a double in which to return the graphics Y
*        coordinate of the position supplied by "phy".
*     dx
*        A pointer to a double in which to return the X component
*        of the unit tangent vector. This should be supplied holding a
*        "default" unit vector which is left unchanged if no new vector
*        can be found.
*     dy
*        A pointer to a double in which to return the Y component
*        of the unit tangent vector. This should be supplied holding a
*        "default" unit vector which is left unchanged if no new vector
*        can be found.
*     flag
*        A pointer to an int in which to return a flag indicating which
*        of the two vectors was returned. Zero is returned if the vector
*        was estimated by moving in a positive direction along the axis 
*        from the position supplied by "phy". One is returned if the vector
*        was estimated by moving in a negative direction along the axis 
*        from the position supplied by "phy" (in this case the returned
*        vector will have been negated so that it refers to the positive
*        direction).
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     One is returned if the vector was found succesfully, Zero is returned
*     if the vector could not be estimated for any reason. No error is
*     reported if the failure was due to the nature of the mapping.

*  Notes:
*     -  If an error has already occurred, or if this function should fail 
*     for any reason, then a NULL pointer is returned.
*/

/* Local Variables: */
   double dd1;        /* Length of positive vector */
   double dd2;        /* Length of negative vector */
   double dx1;        /* X component of positive vector */
   double dx2;        /* X component of negative vector */
   double dy1;        /* Y component of positive vector */
   double dy2;        /* Y component of negative vector */
   double **ptr1;     /* Pointers to physical coordinate data */
   double **ptr2;     /* Pointers to graphics coordinate data */
   int i;             /* Axis index */
   int nphy;          /* No. of axes in current (physical) Frame */
   int ret;           /* Was a vector estimated succesfully? */

/* Check the global status. */
   if( !astOK ) return 0;

/* Initialise the returned value to indicate that the vector can not
   be found. */
   ret = 0;

/* Get the number of physical coordinates from the mapping. */
   nphy = astGetNout( mapping );

/* If no PointSets have been supplied, create some now. PointSet 1 
   contains physical coordinates, PointSet 2 contains graphics 
   coordinates. */
   if( !(*pset1) ) *pset1 = astPointSet( 3, nphy, "" );
   if( !(*pset2) ) *pset2 = astPointSet( 3, 2, "" );

/* Get pointers to the PointSet data. */     
   ptr1 = astGetPoints( *pset1 );
   ptr2 = astGetPoints( *pset2 );

/* Check the PointSets can be used. */
   if( astOK ){

/* Store the physical coordinates of three close points on a curve 
   parallel to the given axis, with the centre point at the given 
   position. */
      for( i = 0; i < nphy; i++ ){
         ptr1[ i ][ 0 ] = phy[ i ];
         ptr1[ i ][ 1 ] = phy[ i ];
         ptr1[ i ][ 2 ] = phy[ i ];
      }   
 
      if( phy[ axis ] != AST__BAD ){
         ptr1[ axis ][ 0 ] = phy[ axis ] - delta;
         ptr1[ axis ][ 2 ] = phy[ axis ] + delta;
      }

/* Find the corresponding graphics coordinates. */
      (void) Trans( this, NULL, mapping, *pset1, 0, *pset2, 0, method, class );

/* Check the central position is OK. */
      *gx = ptr2[ 0 ][ 1 ];
      *gy = ptr2[ 1 ][ 1 ];
      if( astOK && *gx != AST__BAD && *gy != AST__BAD ){

/* Get the unit vector between the central position and the position at 
   the higher physical axis value. Also get the length of the vector 
   joining the two positions. */
         if( ptr2[ 0 ][ 2 ] != AST__BAD && ptr2[ 1 ][ 2 ] != AST__BAD ){
            dx1 = ptr2[ 0 ][ 2 ] - *gx;
            dy1 = ptr2[ 1 ][ 2 ] - *gy;
            dd1 = dx1*dx1 + dy1*dy1;

            if( dd1 > 0.0 ) {
               dd1 = sqrt( dd1 );
               dx1 /= dd1;               
               dy1 /= dd1;               
            } else {
               dd1 = AST__BAD;
            }

         } else {
            dd1 = AST__BAD;
         }

/* Do the same for the position with lower physical axis value, 
   reversing the direction of the vector so that it refers to the
   positive direction. */
         if( ptr2[ 0 ][ 0 ] != AST__BAD && ptr2[ 1 ][ 0 ] != AST__BAD ){
            dx2 = *gx - ptr2[ 0 ][ 0 ];
            dy2 = *gy - ptr2[ 1 ][ 0 ];
            dd2 = dx2*dx2 + dy2*dy2;

            if( dd2 > 0.0 ) {
               dd2 = sqrt( dd2 );
               dx2 /= dd2;               
               dy2 /= dd2;               
            } else {
               dd2 = AST__BAD;
            }

         } else {
            dd2 = AST__BAD;
         }

/* Only overwrite the supplied vector if at least one of the two tangent 
   vectors was defined. */
         if( dd1 != AST__BAD || dd2 != AST__BAD ){

/* If the first vector was not defined, return the second. */
            if( dd1 == AST__BAD ){
               *dx = dx2;
               *dy = dy2;
               *flag = 1;
               ret = 1;

/* If the second vector was not defined, return the first. */
            } else if( dd2 == AST__BAD ){
               *dx = dx1;
               *dy = dy1;
               *flag = 0;
               ret = 1;

/* If the first vector is much longer than the second, return the 
   second. */
            } else if( dd1 > 100.0*dd2 ){
               *dx = dx2;
               *dy = dy2;
               *flag = 1;
               ret = 1;

/* If the second vector is much longer than the first, return the 
   first. */
            } else if( dd2 > 100.0*dd1 ){
               *dx = dx1;
               *dy = dy1;
               *flag = 0;
               ret = 1;

/* If both vectors are defined and of comparable length, return the
   vector which is most nearly parallel to the supplied vector. Note, we
   assume that the supplied vector [dx,dy] is a unit vector. */
            } else if( *dx != AST__BAD && *dx != AST__BAD ){
               if( ( dx1*(*dx) + dy1*(*dy) )/dd1 > 
                   ( dx2*(*dx) + dy2*(*dy) )/dd2 ){
                  *dx = dx1;
                  *dy = dy1;
                  *flag = 0;
                  ret = 1;
               
               } else {
                  *dx = dx2;
                  *dy = dy2;
                  *flag = 1;
                  ret = 1;
               }

/* If no vector was supplied, return the shorter of the two vectors. */
            } else if( dd1 < dd2 ){
               *dx = dx1;
               *dy = dy1;
               *flag = 0;
               ret = 1;

            } else {               
               *dx = dx2;
               *dy = dy2;
               *flag = 1;
               ret = 1;

            }

         }

      }

   }

/* Return the answer. */
   return ret;

}

static void InitVtab( AstPlotVtab *vtab ) {
/*
*  Name:
*     InitVtab

*  Purpose:
*     Initialise a virtual function table for a Plot.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void InitVtab( AstPlotVtab *vtab )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function initialises the component of a virtual function
*     table which is used by the Plot class.

*  Parameters:
*     vtab
*        Pointer to the virtual function table. The components used by
*        all ancestral classes should already have been initialised.
*/

/* Local Variables: */
   AstFrameSetVtab *fset;        /* Pointer to FrameSet component of Vtab */
   AstObjectVtab *object;        /* Pointer to Object component of Vtab */
   AstMappingVtab *mapping;      /* Pointer to Mapping component of Vtab */

/* Check the local error status. */
   if ( !astOK ) return;

/* Store a unique "magic" value in the virtual function table. This will be
   used (by astIsAPlot) to determine if an object belongs to this class.
   We can conveniently use the address of the (static) class_init variable to
   generate this unique value. */
   vtab->check = &class_init;

/* Initialise member function pointers. */
/* ------------------------------------ */
/* Store pointers to the member functions (implemented here) that provide
   virtual methods for this class. */
   vtab->Mark = Mark;
   vtab->Text = Text;
   vtab->Border = Border;
   vtab->Clip = Clip; 
   vtab->GridLine = GridLine;
   vtab->Curve = Curve;
   vtab->PolyCurve = PolyCurve;
   vtab->CvBrk = CvBrk;
   vtab->Grid = Grid; 
   vtab->ClearTol = ClearTol;
   vtab->SetTol = SetTol;
   vtab->GetTol = GetTol;
   vtab->TestTol = TestTol;
   vtab->ClearGrid = ClearGrid;
   vtab->SetGrid = SetGrid;
   vtab->GetGrid = GetGrid;
   vtab->TestGrid = TestGrid;
   vtab->ClearTickAll = ClearTickAll;
   vtab->SetTickAll = SetTickAll;
   vtab->GetTickAll = GetTickAll;
   vtab->TestTickAll = TestTickAll;
   vtab->ClearBorder = ClearBorder;
   vtab->SetBorder = SetBorder;
   vtab->GetBorder = GetBorder;
   vtab->TestBorder = TestBorder;
   vtab->ClearInk = ClearInk;
   vtab->SetInk = SetInk;
   vtab->GetInk = GetInk;
   vtab->TestInk = TestInk;
   vtab->ClearClipOp = ClearClipOp;
   vtab->SetClipOp = SetClipOp;
   vtab->GetClipOp = GetClipOp;
   vtab->TestClipOp = TestClipOp;
   vtab->ClearDrawTitle = ClearDrawTitle;
   vtab->SetDrawTitle = SetDrawTitle;
   vtab->GetDrawTitle = GetDrawTitle;
   vtab->TestDrawTitle = TestDrawTitle;
   vtab->ClearLabelUp = ClearLabelUp;
   vtab->SetLabelUp = SetLabelUp;
   vtab->GetLabelUp = GetLabelUp;
   vtab->TestLabelUp = TestLabelUp;
   vtab->ClearDrawAxes = ClearDrawAxes;
   vtab->SetDrawAxes = SetDrawAxes;
   vtab->GetDrawAxes = GetDrawAxes;
   vtab->TestDrawAxes = TestDrawAxes;
   vtab->ClearEscape = ClearEscape;
   vtab->SetEscape = SetEscape;
   vtab->GetEscape = GetEscape;
   vtab->TestEscape = TestEscape;
   vtab->ClearLabelling = ClearLabelling;
   vtab->SetLabelling = SetLabelling;
   vtab->GetLabelling = GetLabelling;
   vtab->TestLabelling = TestLabelling;
   vtab->ClearMajTickLen = ClearMajTickLen;
   vtab->SetMajTickLen = SetMajTickLen;
   vtab->GetMajTickLen = GetMajTickLen;
   vtab->TestMajTickLen = TestMajTickLen;
   vtab->ClearTitleGap = ClearTitleGap;
   vtab->SetTitleGap = SetTitleGap;
   vtab->GetTitleGap = GetTitleGap;
   vtab->TestTitleGap = TestTitleGap;
   vtab->ClearMinTickLen = ClearMinTickLen;
   vtab->SetMinTickLen = SetMinTickLen;
   vtab->GetMinTickLen = GetMinTickLen;
   vtab->TestMinTickLen = TestMinTickLen;
   vtab->ClearNumLabGap = ClearNumLabGap;
   vtab->SetNumLabGap = SetNumLabGap;
   vtab->GetNumLabGap = GetNumLabGap;
   vtab->TestNumLabGap = TestNumLabGap;
   vtab->ClearTextLabGap = ClearTextLabGap;
   vtab->SetTextLabGap = SetTextLabGap;
   vtab->GetTextLabGap = GetTextLabGap;
   vtab->TestTextLabGap = TestTextLabGap;
   vtab->ClearLabelAt = ClearLabelAt;
   vtab->SetLabelAt = SetLabelAt;
   vtab->GetLabelAt = GetLabelAt;
   vtab->TestLabelAt = TestLabelAt;
   vtab->ClearCentre = ClearCentre;
   vtab->SetCentre = SetCentre;
   vtab->GetCentre = GetCentre;
   vtab->TestCentre = TestCentre;
   vtab->ClearGap = ClearGap;
   vtab->SetGap = SetGap;
   vtab->GetGap = GetGap;
   vtab->TestGap = TestGap;
   vtab->ClearEdge = ClearEdge;
   vtab->SetEdge = SetEdge;
   vtab->GetEdge = GetEdge;
   vtab->TestEdge = TestEdge;
   vtab->ClearNumLab = ClearNumLab;
   vtab->SetNumLab = SetNumLab;
   vtab->GetNumLab = GetNumLab;
   vtab->TestNumLab = TestNumLab;
   vtab->ClearMinTick = ClearMinTick;
   vtab->SetMinTick = SetMinTick;
   vtab->GetMinTick = GetMinTick;
   vtab->TestMinTick = TestMinTick;
   vtab->ClearTextLab = ClearTextLab;
   vtab->SetTextLab = SetTextLab;
   vtab->GetTextLab = GetTextLab;
   vtab->TestTextLab = TestTextLab;
   vtab->ClearLabelUnits = ClearLabelUnits;
   vtab->SetLabelUnits = SetLabelUnits;
   vtab->GetLabelUnits = GetLabelUnits;
   vtab->TestLabelUnits = TestLabelUnits;
   vtab->ClearStyle = ClearStyle;
   vtab->SetStyle = SetStyle;
   vtab->GetStyle = GetStyle;
   vtab->TestStyle = TestStyle;
   vtab->ClearFont = ClearFont;
   vtab->SetFont = SetFont;
   vtab->GetFont = GetFont;
   vtab->TestFont = TestFont;
   vtab->ClearColour = ClearColour;
   vtab->SetColour = SetColour;
   vtab->GetColour = GetColour;
   vtab->TestColour = TestColour;
   vtab->ClearWidth = ClearWidth;
   vtab->SetWidth = SetWidth;
   vtab->GetWidth = GetWidth;
   vtab->TestWidth = TestWidth;
   vtab->ClearSize = ClearSize;
   vtab->SetSize = SetSize;
   vtab->GetSize = GetSize;
   vtab->TestSize = TestSize;

/* Save the inherited pointers to methods that will be extended, and replace
   them with pointers to the new member functions. */
   object = (AstObjectVtab *) vtab;
   mapping = (AstMappingVtab *) vtab;
   fset = (AstFrameSetVtab *) vtab;

   parent_clearattrib = object->ClearAttrib;
   object->ClearAttrib = ClearAttrib;
   parent_getattrib = object->GetAttrib;
   object->GetAttrib = GetAttrib;
   parent_setattrib = object->SetAttrib;
   object->SetAttrib = SetAttrib;
   parent_testattrib = object->TestAttrib;
   object->TestAttrib = TestAttrib;

   parent_transform = mapping->Transform;
   mapping->Transform = Transform;

   parent_removeframe = fset->RemoveFrame;
   fset->RemoveFrame = RemoveFrame;

/* Declare the destructor and copy constructor. */
   astSetDelete( (AstObjectVtab *) vtab, Delete );
   astSetCopy( (AstObjectVtab *) vtab, Copy );

/* Declare the class dump function. */
   astSetDump( vtab, Dump, "Plot", "Provide facilities for graphical output" );

/* Initialise the external structure used to store information about the 
   most recent curve drawn by astGridLine. The number of breaks in the curve 
   set to -1 to indicate that no curve has yet been drawn. */
   Curve_data.nbrk = -1;

/* Return. */
   return;

}

static int Inside( int n, float *cx, float *cy, float x, float y ){
/*
*  Name:
*     Inside

*  Purpose:
*     See if a given point is inside a 2-d polygon.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int Inside( int n, float *cx, float *cy, float x, float y )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function determines if the position given by x and y, is inside
*     or outside the polygon specified by the vertices given in arrays cx
*     and cy. 

*  Parameters:
*     n
*        The number of vertices in the polygon.
*     cx
*        A pointer to an array holding the x coordinates at the "n" vertices.
*     cy
*        A pointer to an array holding the y coordinates at the "n" vertices.
*     x
*        The x coordinate of the test point.
*     y
*        The y coordinate of the test point.

*  Returned Value:
*     A boolean flag indicating if the test point is inside the polygon.

*  Notes:
*     -  The algorithm used only works for convex polygons.
*     -  The polygon is closed by joining the last vertex to the first
*     vertex.
*     -  Zero is returned if an error has occurred.

*/

/* Local Variables: */
   int i;        /* Index of the current vertex */
   int j;        /* Index of the next vertex */
   int ret;      /* Is the test point inside the polygon? */
   int sgn;      /* Which side of the first edge is the test point? */

/* Check the global status. */
   if( !astOK ) return 0;

/* Initialise the returned value to indicate that the point is inside the
   box. */
   ret = 1;

/* Get the sign of the angle between the vector joining vertex 1 to vertex
   0, and the vector joining the test point to vertex zero. */
   if( ( cx[ 1 ] - cx[ 0 ] )*( y - cy[ 0 ] ) > 
       ( x - cx[ 0 ] )*( cy[ 1 ] - cy[ 0 ] ) ){
      sgn = 1;
   } else {
      sgn = -1;
   }

/* Check that the remaining test point is on the same side of the remaining
   sides. */
   for( i = 1; i < n; i++ ){

/* Get the index of the next vertex, joining the last vertex up with
   vertex zero. */
      j = i + 1;
      if( j >= n ) j -= n;

/* Get the sign of the angle between the vector joining vertex j to vertex
   i, and the vector joining the test point to vertex i. If the sign is
   opposite to that found for vertex zero, then the test point is outside
   the polygon. Break out of the loop if this is the case. */
      if( ( cx[ j ] - cx[ i ] )*( y - cy[ i ] ) > 
          ( x - cx[ i ] )*( cy[ j ] - cy[ i ] ) ){

         if( sgn == -1 ) {
            ret = 0;
            break;
         }

      } else {

         if( sgn == 1 ) {
            ret = 0;
            break;
         }

      }

   }


/* Return the answer. */
   return ret;

}

static void Labelat( AstPlot *this, TickInfo **grid, CurveData **cdata, 
                     double *labelat, const char *method, const char *class ){
/*
*
*  Name:
*     Labelat

*  Purpose:
*     Determine the other axis value at which to place interior labels
*     and tick marks.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void Labelat( AstPlot *this, TickInfo **grid, CurveData **cdata, 
*                  *gap, double *labelat, const char *method, 
*                  const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     If tick marks and labels are to be placed within the plotting area, 
*     the tick values stored in "grid" determine their position on one
*     axis, and their position on the other axis is determined by this
*     function. If a value has been set for the "LabelAt" attribute, then
*     it is used, otherwise the "ohter axis" value on the longest curve 
*     parallel to the "other axis" is used (although the curve "other axis 
*     = zero" is used if it passes through the plotting area and is not too 
*     short).

*  Parameters:
*     this
*        A pointer to the Plot.
*     grid
*        A pointer to an array of two TickInfo pointers (one for each axis), 
*        each pointing to a TickInfo structure holding information about
*        tick values on the axis. See function GridLines.
*     cdata
*        A pointer to an array of two CurveData pointers (one for each axis), 
*        each pointing to an array of CurveData structure (one for each
*        major tick value on the axis), holding information about breaks
*        in the curves drawn to mark the major tick values. See function 
*        DrawGrid. 
*     labelat
*        A pointer to a 2 element array in which to store the constant axis 
*        values at which tick marks are put. Element 0 is returned holding
*        the axis 1 value at which tick marks for axis 0 are placed. Element 
*        1 is returned holding the axis 0 value at which tick marks for axis 
*        1 are placed. 
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Notes:
*     -  This function assumes the current Frame of the Plot is 2
*     dimensional, and it should not be called if this is not the case. 
*/

/* Local Variables: */
   CurveData *cdt;        /* Pointer to the CurveData for the next tick */
   TickInfo *info;        /* Pointer to the TickInfo for the current axis */
   double *value;         /* Current tick value */
   double maxlen;         /* Length of longest curve */
   double zerolen;        /* Length of curve for other axis = 0.0 */
   int axis;              /* Current axis index */
   int tick;              /* Tick index */

/* Check the global status. */
   if( !astOK ) return;

/* Do each axis. */
   for( axis = 0; axis < 2; axis++ ){

/* We need to decide where to put the labels. The major tick values give
   their location on one axis. The position on the other axis may be
   specified by the caller using the "LabelAt" attribute, or a default value 
   can be found if no values have been supplied for this attributes. If the 
   attribute for this axis has been set, use its value. */
      if( astTestLabelAt( this, axis ) ){
         labelat[ axis ] = astGetLabelAt( this, axis );

/* Otherwise, find the longest curve parallel to the axis being labelled. 
   Also find the length of the curve which passes through the origin of the 
   other axis which is within the plotting area... */
      } else {
  
/* Get a pointer to the structure containing information describing the 
   positions of the major tick marks along the other axis. */  
         info = grid[ 1 - axis ];

/* Get a pointer to the axis value at the first major tick mark. */
         value = info->ticks;

/* Get a pointer to the structure containing information describing the 
   breaks in the curve which passes through the first major tick mark. */
         cdt = cdata[ 1 - axis ];

/* Initialise the length of the longest curve, and the curve passing through 
   the origin. */
         maxlen = -1.0;
         zerolen = 0.0;
         labelat[ axis ] = AST__BAD;

/* Loop round each of the major tick marks. */
         for( tick = 0; tick < info->nmajor; tick++ ){

/* If the curve through this tick mark is longer than any other found so
   far, record it. */
            if( cdt->length > maxlen ){
               maxlen = cdt->length;
               labelat[ axis ] = *value;
            }

/* If this tick mark is at the origin, note the length of the curve. */
            if( *value == 0.0 ) zerolen = cdt->length;

/* Get a pointer to the curve through the next major tick mark. */
            cdt++;
            
/* Get a pointer to the axis value at the next major tick mark. */
            value++;

         }
   
/* Use the curve through the origin unless it is significantly shorter
   than the longest curve. */
         if( zerolen > 0.4*maxlen ) labelat[ axis ] = 0.0;

      }

   }

/* Return. */
   return;

}

static void Labels( AstPlot *this, TickInfo **grid, CurveData **cdata, 
                    double *gap, double *labelat, const char *method, 
                    const char *class ){
/*
*
*  Name:
*     Labels

*  Purpose:
*     Draw numerical axis labels for a 2-D annotated coordinate grid.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void Labels( AstPlot *this, TickInfo **grid, CurveData **cdata, 
*                  double *gap, double *labelat, const char *method, 
*                  const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     The policy for placing labels for the major tick values is broadly as
*     follows: if possible, labels for a given physical axis are placed on
*     one edge of the plotting area, at the place where the curve for a 
*     major tick value crosses the edge. If very few of the curves cross
*     the edge, then the label for a curve is placed at the intersection
*     of that curve with the longest of the curves representing the major 
*     tick values on the other axis.

*  Parameters:
*     this
*        A pointer to the Plot.
*     grid
*        A pointer to an array of two TickInfo pointers (one for each axis), 
*        each pointing to a TickInfo structure holding information about
*        tick values on the axis. See function GridLines.
*     cdata
*        A pointer to an array of two CurveData pointers (one for each axis), 
*        each pointing to an array of CurveData structure (one for each
*        major tick value on the axis), holding information about breaks
*        in the curves drawn to mark the major tick values. See function 
*        DrawGrid. 
*     gap
*        Pointer to array of two values holding the gap between major
*        tick values on the two axes.
*     labelat
*        A pointer to a 2 element array holding the constant axis 
*        values at which tick marks are put. Element 0 should hold
*        the axis 1 value at which tick marks for axis 0 are placed. Element 
*        1 should hold the axis 0 value at which tick marks for axis 
*        1 are placed. If labels are to be placed round the edges of the
*        plotting zone instead of within the plotting zone, then values of
*        AST__BAD should be supplied.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Notes:
*     -  This function assumes the current Frame of the Plot is 2
*     dimensional, and it should not be called if this is not the case. 
*/

/* Local Variables: */
   AstFrame *frame;       /* Pointer to current Frame */
   AstMapping *mapping;   /* Pointer to graphics->physical Mapping */
   AstPointSet *pset1;    /* Pointer to PointSet holding physical coords. */
   AstPointSet *pset2;    /* Pointer to PointSet holding graphics coords. */
   CurveData *cdt;        /* Pointer to the CurveData for the next tick */
   LabelList *labellist;  /* Pointer to list of labels to be plotted */
   LabelList *ll;         /* Pointer to next label to be plotted */
   TickInfo *info;        /* Pointer to the TickInfo for the current axis */
   char just_buf[3];      /* Buffer to hold a justification string */
   const char *just;      /* Justification string */
   const char *text;      /* Pointer to label text */
   double *used;          /* Pointer to list of used label values */
   double *value;         /* Current tick value */
   double dx2;            /* Text base-line X component after axis reversal */
   double dx;             /* Text base-line X component */
   double dy2;            /* Text base-line Y component after axis reversal */
   double dy;             /* Text base-line Y component */
   double gx;             /* Reference position graphics X coord. */
   double gy;             /* Reference position graphics Y coord. */
   double mindim;         /* Shortest dimension of plotting area */
   double offx;           /* X component of offset vector */
   double offy;           /* Y component of offset vector */
   double sin45;          /* Sine of 45 degrees */
   double txtgap;         /* Absolute gap between labels and edges */
   double upx;            /* Text up-vector X component */
   double upy;            /* Text up-vector Y component */
   double val[ 2 ];       /* Normalised physical coordinates */
   float *box;            /* Pointer to array of label bounding boxes */
   int axis;              /* Current axis index */
   int flag;              /* Flag indicating which way the base-vector points */
   int iused;             /* Index into list of used axis values */
   int last;              /* The index of the last tick to use */
   int nlab;              /* The number of labels to be plotted */
   int nused;             /* Number of used axis values */
   int t0;                /* Index of central tick */
   int tick;              /* Current tick index */
   int tinc;              /* Increment between ticks */
   int upfree;            /* Are we free to change the up-vector? */

/* Check the global status. */
   if( !astOK ) return;

/* Get the minimum dimension of the plotting ares. */
   mindim = MIN( this->xhi - this->xlo, this->yhi - this->ylo );

/* Establish the correct graphical attributes as defined by attributes
   with the supplied Plot. */
   GrfAttrs( this, NUMLABS_ID, 1, GRF__TEXT );

/* If required, draw the labels around the edges of the plotting area. */
   if( labelat[ 0 ] == AST__BAD || labelat[ 1 ] == AST__BAD ){
      (void) EdgeLabels( this, 1, grid, cdata, method, class );

/* Otherwise, draw labels within the interior of the plotting area. */
   } else {
   
/* Store a value for the sine of 45 degrees. */
      sin45 = 1.0/sqrt( 2.0 );

/* Initialise the pointer to the memory holding the bounding boxes for 
   all labels (used by function Overlap). */
      box = NULL;

/* Get a pointer to the current Frame in the Plot. */
      frame = astGetFrame( this, AST__CURRENT );

/* Get a pointer to the mapping form the base Frame to the current Frame in 
   the Plot. */
      mapping = astGetMapping( this, AST__BASE, AST__CURRENT );

/* Do each axis. */
      for( axis = 0; axis < 2; axis++ ){

/* Get a pointer to the structure containing information describing the 
   positions of the major tick marks along this axis. */  
         info = grid[ axis ];

/* Only progress if there are some labels stored within the structure. */
         if( info->labels ) {

/* Initialise the pointer to the list of text strings to be drawn. */
            labellist = NULL;
            nlab = 0;

/* See if numerical labels are always to be drawn horizontal. If so, set 
   a flag and initialise a vertical up-vector. */
            if( astGetLabelUp( this, axis ) ){
               upfree = 0;
               upx = 0.0;
               upy = 1.0;

/* Otherwise, clear the flag and indicate that we do not yet have an
   up-vector. */
            } else {
               upfree = 1;
               upx = AST__BAD;
               upy = AST__BAD;
            }

/* Indicate that the tangent vector to the other axis is not yet 
   known. */
            dx = AST__BAD;
            dy = AST__BAD;

/* Store the gap to put next to the label text. */
            txtgap = astGetNumLabGap( this, axis )*mindim;

/* Get a pointer to the structure containing information describing the
   breaks in the curve which passes through the first major tick mark. */
            cdt = cdata[ axis ];

/* Get a pointer to the axis value at the first major tick mark. */
            value = info->ticks;

/* Initialise pointers to two PointSets which will be created and used 
   within function GVec. */
            pset1 = NULL;
            pset2 = NULL;

/* Get memory to hold the normalised axis values at which labels have been
   put. */
            used = (double *) astMalloc( sizeof(double)*(size_t)info->nmajor );
            nused = 0;

/* The tick marks are done in two batches, each batch working out from the 
   middle. This is done because there may be extra tick marks outside the
   normal ranges at the extremes, and these should not be given the
   priority caused by doing them first. Store the mid-tick index, the
   current tick index, and the increment between ticks. The ticks from the
   middle up to the highest index are done first. */
            t0 = info->nmajor/2;
            tick = t0 - 1;
            tinc = 1;

/* Loop round until all ticks have been done. */
            last = info->nmajor - 1;
            while( tick > 0 && astOK ){

/* Increment the tick index. */
               tick += tinc;

/* If we have done the highest tick index, start again at the tick just
   below middle, and work done towards index zero. */
               if( tick == info->nmajor ){
                  tick = t0 - 1;
                  tinc = -1;
               } 

/* Normalise the reference position for the label . */
               val[ axis ] = value[ tick ];
               val[ 1 - axis ] = labelat[ axis ];
               astNorm( frame, val );

/* See if the normalised axis value has already been used. */
               for( iused = 0; iused < nused; iused++ ){
                  if( fabs( val[ axis ] - used[ iused ] ) <
                      1.0E-3*gap[ axis ] ) break;
               }

/* If the normalised axis value has already been used, don't use it again. */
               if( iused >= nused || nused == 0 ){
                  used[ nused++ ] = val[ axis ];

/* We now need to decide where to put the reference point for the text
   string, and what justification to use. Assuming that NumLabGap is +ve,
   the labels are drawn on the right hand side of the axis as seen by 
   someone moving along the axis in the positive direction, with an 
   up-vector which is normal to the axis tangent. First, find the graphics 
   coordinates at the point being labelled, and the tangent-vector parallel
   to the axis being labelled. If the tangent vector is not defined, then 
   the tangent vector used for the previous label is re-used. */
                  GVec( this, mapping, val, axis, 0.01*gap[ axis ], &pset1, 
                        &pset2, &gx, &gy, &dx, &dy, &flag, method, class );

/* If we now have a tangent vector and good graphics coordinates for the 
   label's reference position... */
                  if( dx != AST__BAD && dy != AST__BAD &&
                      gx != AST__BAD && gy != AST__BAD ){

/* The reference position for the text is displaced away from the 
   reference position normal to the axis on the left hand side by the 
   "txtgap" value. */
                     if( ( this->xrev && this->yrev ) ||
                         ( !this->xrev && !this->yrev ) ) {
                        offx = -dy*txtgap;                  
                        offy = dx*txtgap;                  
                     } else {
                        offx = dy*txtgap;                  
                        offy = -dx*txtgap;                  
                     }

                     gx += offx;
                     gy += offy;

/* Reverse the vector components if the graphics axes are displayed 
   reversed. */
                     dx2 = ( this->xrev ) ? -dx : dx;
                     dy2 = ( this->yrev ) ? -dy : dy; 
                     offx = ( this->xrev ) ? -offx : offx;
                     offy = ( this->yrev ) ? -offy : offy; 

/* The up-vector and justification for the text depends on whether or 
   not the up-vector is free to rotate. If it is free, the up-vector is
   chosen so that the text is not upside-down. */
                     if( upfree ){
   
                        if( dx2 < -0.01 ){
                           upx = dy2;
                           upy = -dx2;
                           just = ( txtgap < 0.0 )? "BC" : "TC";
                        } else {
                           upx = -dy2;
                           upy = dx2;
                           just = ( txtgap < 0.0 )? "TC" : "BC";
                        }
                        if( txtgap == 0.0 ) just = "CC";

/* If the up vector is required to be vertical, a system is used which
   tries to put the centre of the text string on or near the offset
   vector. */
                     } else {
                        upx = 0.0;
                        upy = 1.0;
   
                        if( offy > fabs(txtgap)*sin45 ){
                           just_buf[0] = 'B';
                        } else if( offy < -fabs(txtgap)*sin45 ){
                           just_buf[0] = 'T';
                        } else {                  
                           just_buf[0] = 'C';
                        }
                        if( txtgap == 0.0 ) just_buf[0] = 'C';
   
                        if( offx < -fabs(txtgap)*sin45 ){
                           just_buf[1] = 'R';
                        } else if( offx > fabs(txtgap)*sin45 ){
                           just_buf[1] = 'L';
                        } else {                  
                           just_buf[1] = 'C';
                        }
                        if( txtgap == 0.0 ) just_buf[1] = 'C'; 
   
                        just_buf[2] = 0;
                        just = just_buf;
                     }

/* Get the label text. */
                     text = (info->labels)[ tick ];
                     if( text ){

/* Check that the reference position is within the plotting area. 
   If so, add it to the list of labels to be drawn. */
                        if( gx >= this->xlo && gx <= this->xhi &&
                            gy >= this->ylo && gy <= this->yhi ){

                           labellist = (LabelList *) astGrow( (void *) labellist, nlab + 1, sizeof(LabelList) );
                           if ( astOK ) {
                              (labellist + nlab)->index = tick;
                              (labellist + nlab)->text = (char *) astStore( NULL, (void *) text, strlen(text) + 1 );
                              (labellist + nlab)->x = gx;
                              (labellist + nlab)->y = gy;
                              (labellist + nlab)->just = (char *) astStore( NULL, (void *) just, strlen(just) + 1 );
                              (labellist + nlab)->upx = upx;
                              (labellist + nlab)->upy = upy;
                              (labellist + nlab)->val = val[ axis ];
                              nlab++;
                           } else {
                              break;
                           }
                        }
                     }
                  }
               }
            }

/* If any labels were stored, draw the text strings, and then release the
   memory used to hold the text, etc. */
            if( nlab > 0 ) {
               PlotLabels( this, frame, axis, labellist, info->fmt, nlab, 
                           &box, method, class );
               ll = labellist;
               for( tick = 0; tick < nlab; tick ++ ) {
                  ll->text = (char *) astFree( (void *) ll->text );
                  ll->just = (char *) astFree( (void *) ll->text );
                  ll++;
               }
               labellist = (LabelList *) astFree( (void *) labellist );
            }

/* Free the memory used to hold the normalised axis values at which labels have 
   been put. */
            used = (double *) astFree( (void *) used );

/* Annul the PointSets (if used). */
            if( pset1 ) pset1 = astAnnul( pset1 );
            if( pset2 ) pset2 = astAnnul( pset2 );
         }
      }

/* Free the memory used to hold the bounding boxes. */
      box = (float *) astFree( (void *) box );

/* Annul the pointers to the Frame and the Mapping. */
      mapping = astAnnul( mapping );
      frame = astAnnul( frame );

   }

/* Re-establish the original graphical attributes. */
   GrfAttrs( this, NUMLABS_ID, 0, GRF__TEXT );

/* Return. */
   return;

}

static void LinePlot( AstPlot *this, double xa, double ya, double xb, 
                      double yb, int ink, CurveData *cdata, 
                      const char *method, const char *class ){
/*
*
*  Name:
*     LinePlot

*  Purpose:
*     Draws a straight line omitting bad regions.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void LinePlot( AstPlot *this, double xa, double ya, double xb, 
*                    double yb, int ink, CurveData *cdata, 
*                    const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function draws a straight line between two positions in graphics 
*     coordinates but leaves gaps in the line where it passes through
*     regions which have no corresponding physical coordinates. 

*  Parameters:
*     this
*        Pointer to the Plot.
*     xa
*        The graphics X coordinate at the start of the line.
*     ya
*        The graphics Y coordinate at the start of the line.
*     xb
*        The graphics X coordinate at the end of the line.
*     yb
*        The graphics Y coordinate at the end of the line.
*     ink
*        If zero, the line is not actually drawn, but information about 
*        the breaks is still returned. If non-zero, the line is also drawn.
*     cdata
*        A pointer to a structure in which to return information about the
*        breaks in the line.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Notes:
*     -  No curve is draw if any of the start or end positions are bad
*     (i.e. equal to AST__BAD), or if a NULL pointer is supplied for "cdata". 
*     No errors are reported in these cases.
*/

/* Local Variables: */
   double d[ CRV_NPNT ];   /* Offsets to evenly spaced points along curve */
   double x[ CRV_NPNT ];   /* X coords at evenly spaced points along curve */
   double y[ CRV_NPNT ];   /* Y coords at evenly spaced points along curve */
   double tol;             /* Absolute tolerance value */
   int i;                  /* Loop count */

/* Check the global error status. */
   if ( !astOK ) return;

/* Check the supplied values are usable. */
   if( xa == AST__BAD || ya == AST__BAD || 
       xb == AST__BAD || yb == AST__BAD ||
      !cdata ) return;

/* Convert the tolerance from relative to absolute graphics coordinates. */
   tol = astGetTol( this )*MAX( this->xhi - this->xlo, this->yhi - this->ylo );

/* Set up the external variables used by the Crv and CrvLine function (see 
   their prologues for details). */
   Crv_ux0 = AST__BAD;
   Crv_limit = 0.5*tol*tol;
   Crv_tol = tol;
   Crv_map = Map2;
   Crv_ink = ink;
   Crv_len = 0.0F;
   Crv_xlo = this->xlo;
   Crv_xhi = this->xhi;
   Crv_ylo = this->ylo;
   Crv_yhi = this->yhi;
   Crv_out = 1;
   Crv_xbrk = cdata->xbrk;
   Crv_ybrk = cdata->ybrk;
   Crv_vxbrk = cdata->vxbrk;
   Crv_vybrk = cdata->vybrk;

/* Create a set of evenly spaced values between 0.0 and 1.0. These are the
   offsets the edge of the plotting zone at which the mapping is tested. */
   for( i = 0; i < CRV_NPNT; i++ ){
     d[ i ] = ( (double) i)/( (double) CRV_NSEG );
   }

/* Now set up the externals used to communicate with the Map2 function.
   Map2 transforms a set of offsets between zero and one into a set of
   corresponding graphics coordinates, with bad values substituted for any
   offsets which correspond to points outside the domain of the mapping. */

/* The number of axes in the physical coordinate system (i.e. the current
   Frame). */
   Map2_ncoord = astGetNout( this );

/* A pointer to the mapping from graphics world cordinates to physical
   coordinates. */
   Map2_plot = this;
   Map2_map = astGetMapping( this, AST__BASE, AST__CURRENT );

/* The graphics coordinates corresponding to an offset of zero (i.e.
   the start of the line). */
   Map2_x0 = xa;
   Map2_y0 = ya;

/* The increments in X and Y between offset zero (the start of the
   line) and offset 1 (the end of the line). */
   Map2_deltax = xb - xa;
   Map2_deltay = yb - ya;

/* Get the graphics coordinates corresponding to the initial set of
   offsets. */
   Map2( CRV_NPNT, d, x, y, method, class );

/* Use Crv and Map2 to draw the intersection of the straight line with
   the region containing valid physical coordinates. */
   Crv( d, x, y, method, class );

/* End the current poly line. */
   Opoly( method, class );

/* Tidy up the static data used by Map2. */
   Map2( 0, NULL, NULL, NULL, method, class );

/* Annul the Mapping. */
   Map2_map = astAnnul( Map2_map );

/* Return. */
   return;

}

static double **MakeGrid( AstPlot *this, AstFrame *frm, AstMapping *map, 
                          int dim, double xlo, double xhi, double ylo, 
                          double yhi, int nphy, AstPointSet **pset1, 
                          AstPointSet **pset2, int norm, const char *method, 
                          const char *class ){
/*
*  Name:
*     MakeGrid

*  Purpose:
*     Create a square grid of graphics coordinates and the corresponding 
*     physical coordinates.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     double **MakeGrid( AstPlot *this, AstFrame *frm, AstMapping *map, 
*                        int dim, double xlo, double xhi, double ylo, 
*                        double yhi, int nphy, AstPointSet **pset1, 
*                        AstPointSet **pset2, int norm, const char *method, 
*                        const char *class ){

*  Class Membership:
*     Plot member function.

*  Description:
*     This function creates two PointSets, one holding a square grid of
*     graphics coordinates covering the supplied area, and the other
*     holding the corresponding physical coordinates. The points are
*     stored row by row in the returned PointSets, i.e. if the cell size
*     for the grid is (dx,dy), the first point is (xmin,ymin), followed
*     by (xmin+dx,ymin), (xmin+2*dx,ymin), up to (xmin+(dim-1)*dx,ymin),
*     followed by the next row (xmin,ymin+dy), (xmin+dx,ymin+dy), etc.

*  Parameters:
*     this
*        The Plot.
*     frm
*        A pointer to the Current Frame in the Plot. If this is supplied
*        NULL, then a pointer is found within this function if required (i.e. 
*        if "norm" is non-zero).
*     map
*        The Mapping from graphics to physical coordinates, extracted from
*        the Plot.
*     dim
*        The number of samples along each edge of the grid.
*     xlo
*        The lower bound on the first axis of the region to be covered
*        by the grid.
*     xhi
*        The upper bound on the first axis of the region to be covered
*        by the grid.
*     ylo
*        The lower bound on the second axis of the region to be covered
*        by the grid.
*     yhi
*        The upper bound on the second axis of the region to be covered
*        by the grid.
*     nphy
*        The number of axes in the physical cooridinate system.
*     pset1
*        A pointer to a location at which to store a pointer to the
*        PointSet holding the graphics coordinates.
*     pset2
*        A pointer to a location at which to store a pointer to the
*        PointSet holding the physical coordinates.
*     norm
*        If non-zero the physical cooridnates are normalised using the
*        Plot's astNorm method.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     A pointer to the physical coordinate data stored in the PointSet
*     "pset2".

*  Notes:
*     - The returned PointSets should be annulled when no longer needed,
*     using astAnnul.
*     -  NULL pointers are returned if an error has already occurred, or
*     if this function should fail for any reason.
*/

/* Local Variables: */
   double **ptr1;    /* Pointers to graphics axis values */
   double **ptr2;    /* Pointers to physical axis values */
   int size;         /* No. of points in the grid */

/* Initialise the returned pointers. */
   *pset1 = NULL;
   *pset2 = NULL;

/* Check the global error status. */
   if ( !astOK ) return NULL;

/* Create two PointSets. */
   size = dim*dim;
   *pset1 = astPointSet( size, 2, "" );
   *pset2 = astPointSet( size, nphy, "" );

/* Get pointers to the data arrays for the two PointSets. */
   ptr1 = astGetPoints( *pset1 );
   ptr2 = astGetPoints( *pset2 );

/* Create a grid covering the supplied area. */
   GraphGrid( dim, xlo, xhi, ylo, yhi, ptr1 );

/* Transform these graphics positions to physical coordinates. */
   Trans( this, frm, map, *pset1, 1, *pset2, norm, method, class ); 

/* If an error has occurred, annul the two pointsets. */
   if( !astOK ){
      *pset1 = astAnnul( *pset1 );
      *pset2 = astAnnul( *pset2 );
      ptr2 = NULL;
   }

/* Return. */
   return ptr2;

}

static void Map1( int n, double *dist, double *x, double *y, 
                  const char *method, const char *class  ){
/*
*  Name:
*     Map1

*  Purpose:
*     Find graphics coordinates at given distances along a curve
*     parallel to a physical axis.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void Map1( int n, double *dist, double *x, double *y,
*                const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     The supplied distances are converted into physical coordinates
*     using the scalings described by various external variables, and then 
*     these physical coordinates are mapped into graphics coordinates. 

*  Parameters:
*     n 
*        The number of points to map. Static resources are released but
*        no points are mapped if zero is supplied.
*     dist
*        A pointer to an array holding "n" distances. A "dist" value of
*        zero corresponds to the starting position supplied in external 
*        variable Map1_origin. A "dist" value of one corresponds to the 
*        finishing position which is a distance Map1_scale away from 
*        Map1_origin, moving in the positive direction of the axis given 
*        by Map1_axis.
*     x
*        A pointer to an array in which to store the "n" graphics X 
*        coordinate values corresponding to the positions in "dist".
*     y
*        A pointer to an array in which to store the "n" graphics Y
*        coordinate values corresponding to the positions in "dist".
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  External Variables:
*     Map1_ncoord = int (Read)
*        The number of axes in the physical coordinate system.
*     Map1_axis = int (Read)
*        The zero-based index of the axis which the curve follows (i.e.
*        the axis which changes value along the curve).
*     Map1_origin = const double * (Read)
*        A pointer to an array holding the physical coordinate value on 
*        each axis at the start of the curve (i.e. at dist = 0.0).
*     Map1_scale = double (Read)
*        The scale factor to convert "dist" values into increments
*        along the physical axis given by Map1_axis.
*     Map1_plot = AstPlot * (Read)
*        A pointer to the Plot defining the mapping from graphics cordinates
*        to physical coordinates.
*     Map1_map = AstMapping * (Read)
*        A pointer to the mapping from graphics cordinates to physical 
*        coordinates extracted from the Plot.
*     Map1_frame = AstFrame * (Read)
*        A pointer to the Current Frame in the Plot.
*     Map1_norm = int (Read)
*        A flag indicating if physical coordinate values which are not in
*        the normal ranges of the corresponding axes should be considered
*        bad.

*  Notes:
*     -  On the first call, this function allocates static resources which 
*     are used by subsequent invocation. These resources should be freed before
*     calling this function with new values for any of the external variables, 
*     or when no longer needed, by calling this function with "n" supplied as 
*     zero.
*     -  If an error has already occurred, this runction returns without 
*     action ,except that if "n" is supplied as zero then static resources
*     are released even if an error has already occurred.

*/

/* Local Constants: */
   static AstPointSet *pset1 = NULL; /* PointSet holding physical coords */
   static AstPointSet *pset2 = NULL; /* PointSet holding graphics coords */
   static double **ptr1 = NULL;      /* Pointer to physical coord data */
   static double *ptr2[ 2 ] = {NULL,NULL}; /* Pointers to graphics coord data */
   static double *pax = NULL;        /* Pointer to start of axis data */
   static double *work;              /* Pointer to work space for astNorm call */
   static double *wax;               /* Pointer to work element for plotted axis */
   static double axorig;             /* Physical axis value at start of curve */
   static int nl = 0;                /* No. of points in pset1 and pset2 */
   int i, j;                         /* Loop counts */
   double axval;                     /* Axis origin value */
   double *p;                        /* Pointer to next value */

/* If zero points were supplied, release any PointSets and work space which 
   have been used and return. */
   if( n == 0 ){
      nl = 0;       
      if( pset1 ) pset1 = astAnnul( pset1 );
      if( pset2 ) pset2 = astAnnul( pset2 );
      if( work ) work = (double *) astFree( (void *) work );
      return;
   }
   
/* Otherwise, check the inherited global status. */
   if( !astOK ) return;

/* If the number of points to be mapped is different to last time, 
   set up some PointSets to store the specified number of points. */
   if( n != nl ){
      nl = n;

/* Create a PointSet to hold the physical coordinates corresponding to
   the supplied offsets. First annul any existing PointSet. */
      if( pset1 ) pset1 = astAnnul( pset1 );
      pset1 = astPointSet( n, Map1_ncoord, "" );   
      ptr1 = astGetPoints( pset1 );

/* Create a PointSet to hold the corresponding graphics coordinates. 
   The supplied "x" and "y" arrays will be used to store the data 
   so we do not need to get pointers to the data using astGetPoints. First 
   annul any existing PointSet. */
      if( pset2 ) pset2 = astAnnul( pset2 );
      pset2 = astPointSet( n, 2, "" );   

/* If we are only plotting points in their normal ranges, get work space to 
   hold a single position. */
      work = (double *) astMalloc( sizeof(double)*(size_t)Map1_ncoord );

/* Check the pointer can be used. */
      if( astOK ){

/* Store a pointer to the start of the memory which will be used to store 
   the physical data for the axis being drawn. */
         pax = ptr1[ Map1_axis ]; 
         
/* Fill the PointSet which is used to hold physical data with the physical 
   coordinates at the start of the curve. */
         for( i = 0; i < Map1_ncoord; i++ ){
            axval = Map1_origin[ i ];
            work[ i ] = axval;
            p = ptr1[ i ];
            for( j = 0; j < n; j++ ) *(p++) = axval;
         }           

/* Store a pointer to the element of the work array corresponding to the
   axis being drawn. */
         wax = work + Map1_axis;

/* Store the starting value for the axis being followed. */
         axorig = Map1_origin[ Map1_axis ];
       }
    }

/* Check the initialisation went OK (if done). */
   if( astOK ){

/* Loop round each offset along the curve, converting the normalised offset 
   in the range [0,1] to a physical coordinate and storing in PointSet 1. */
      p = pax;
      for( i = 0; i < n; i++){
         axval = axorig + Map1_scale*dist[ i ];

/* If points not in their normal ranges are to be considered bad, copy the 
   axis values to the work array and normalise them using astNorm. If the 
   normalised values are different, set the physical coordinates bad. */
         if( Map1_norm ){
            *wax = axval;
            astNorm( Map1_frame, work );

            if( !EQUAL( *wax, axval ) ) {
               axval = AST__BAD;
            }

            for( j = 0; j < Map1_ncoord; j++ ) work[ j ] = Map1_origin[ j ];

         }

         *(p++) = axval;
      }

/* Store pointers to the results arrays in PointSet 2. */
      ptr2[ 0 ] = x;
      ptr2[ 1 ] = y;   
      astSetPoints( pset2, ptr2 );

/* Map all the positions into graphics coordinates. */
      (void) Trans( Map1_plot, NULL, Map1_map, pset1, 0, pset2, 1, method, class );
    }
   
/* Return. */
   return;

}

static void Map2( int n, double *dist, double *x, double *y, 
                  const char *method, const char *class ){
/*
*  Name:
*     Map2

*  Purpose:
*     Find which graphics coordinates have good physical coordinates
*     at given distances along a straight line.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void Map2( int n, double *dist, double *x, double *y, 
*                const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     The supplied distances refer to the distance along a straight line
*     in the graphics coordinate system. The returned graphics coordinates
*     correspond to the supplied distances, except that any position for
*     which there are no defined physical coordinates is returned bad.

*  Parameters:
*     n 
*        The number of points to map. Static resources are released but
*        no points are mapped if zero is supplied.
*     dist
*        A pointer to an array holding "n" distances. A "dist" value of
*        zero corresponds to the graphics position supplied in external 
*        variables (Map2_x0, Map2_y0). A "dist" value of one corresponds to 
*        the graphics position which is offset from the start by the vector
*        (Map2_deltax, Map2_deltay).
*     x
*        A pointer to an array in which to store the "n" graphics X 
*        coordinate values corresponding to the positions in "dist",
*        except that any which have no corresponding physical coordinates
*        are set to AST__BAD.
*     y
*        A pointer to an array in which to store the "n" graphics Y
*        coordinate values corresponding to the positions in "dist",
*        except that any which have no corresponding physical coordinates
*        are set to AST__BAD.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  External Variables:
*     Map2_ncoord = int (Read)
*        The number of axes in the physical coordinate system.
*     Map2_x0 = double (Read)
*        The graphics X coordinate at the start of the line (i.e. at dist 
*        = 0.0).
*     Map2_y0 = double (Read)
*        The graphics Y coordinate at the start of the line (i.e. at dist 
*        = 0.0).
*     Map2_deltax = double (Read)
*        The increment along the graphics X axis between the start and
*        end of the line.
*     Map2_deltay = double (Read)
*        The increment along the graphics Y axis between the start and
*        end of the line.
*     Map2_plot = AstPlot * (Read)
*        A pointer to the Plot defining the mapping from graphics cordinates
*        to physical coordinates.
*     Map2_map = AstMapping * (Read)
*        A pointer to the mapping from graphics cordinates to physical 
*        coordinates, extracted from the Plot.

*  Notes:
*     -  On the first call, this function allocates static resources which 
*     are used by subsequent invocation. These resources should be freed before
*     calling this function with new values for any of the external variables, 
*     or when no longer needed, by calling this function with "n" supplied as 
*     zero.
*     -  If an error has already occurred, this runction returns without 
*     action ,except that if "n" is supplied as zero then static resources
*     are released even if an error has already occurred.

*/
/* Local Constants: */
   static AstPointSet *pset1=NULL; /* PointSet holding graphics coords */
   static AstPointSet *pset2=NULL; /* PointSet holding physical coords */
   static double **ptr2=NULL;      /* Pointer to physical coord data */
   static double *ptr1[ 2 ]={NULL,NULL}; /* Pointers to graphics coord data */
   static int nl=0;                /* No. of points in pset1 and pset2 */
   int i, j;                       /* Loop counts */
   double *p;                      /* Pointer to next physical value */
   double *px;                     /* Pointer to next x graphics value */
   double *py;                     /* Pointer to next y graphics value */

/* If zero points were supplied, release any PointSets which have
   been created and return. */
   if( n == 0 ){
      nl = 0;       
      if( pset1 ) pset1 = astAnnul( pset1 );
      if( pset2 ) pset2 = astAnnul( pset2 );
      return;
   }
   
/* Otherwise, check the inherited global status. */
   if( !astOK ) return;

/* If the number of points to be mapped is different to last time, 
   set up some PointSets to store the specified number of points. */
   if( n != nl ){
      nl = n;

/* Create a PointSet to hold the graphics coordinates corresponding to
   the supplied offsets. The supplied arrays will be used to hold the
   data for this PointSet, and so astGetPoints is not called. */
      if( pset1 ) pset1 = astAnnul( pset1 );
      pset1 = astPointSet( n, 2, "" );   

/* Create a PointSet to hold the corresponding physical coordinates, and
   get pointers to the associated axis values. */
      if( pset2 ) pset2 = astAnnul( pset2 );
      pset2 = astPointSet( n, Map2_ncoord, "" );   
      ptr2 = astGetPoints( pset2 );
    }


/* Check the initialisation went OK (if done). */
   if( astOK ){

/* Store pointers to the results arrays in PointSet 1. */
      ptr1[ 0 ] = x;
      ptr1[ 1 ] = y;   
      astSetPoints( pset1, ptr1 );

/* Loop round each offset along the curve, converting the normalised offset 
      in the range [0,1] to graphics coordinate and storing in PointSet 1. */
      px = x;
      py = y;
      for( i = 0; i < n; i++){
         *(px++) = Map2_x0 + Map2_deltax*dist[ i ];
         *(py++) = Map2_y0 + Map2_deltay*dist[ i ];
      }

/* Map all the positions into physical coordinates. */
      (void) Trans( Map2_plot, NULL, Map2_map, pset1, 1, pset2, 0, method, class );

/* Check the physical coordinates for bad values, setting the corresponding
   graphics coordinates bad. */
      for( j = 0; j < Map2_ncoord; j++ ){
         p = ptr2[ j ];   
         px = x;
         py = y;
   
         for( i = 0; i < n; i++){
            if( *(p++) == AST__BAD ){
               *(px++) = AST__BAD;
               *(py++) = AST__BAD;
            } else {
               px++;
               py++;
            }
         }
      }
   }

/* Return. */
   return;

}

static void Map3( int n, double *dist, double *x, double *y, 
                  const char *method, const char *class  ){
/*
*  Name:
*     Map3

*  Purpose:
*     Find graphics coordinates at given distances along a geodesic curve
*     between two physical coordinate positions.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void Map3( int n, double *dist, double *x, double *y,
*                const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     The supplied distances are converted into physical offsets along the 
*     geodesic curve joining the starting and finishing points given by
*     externals Map3_origin and Map3_end. The physical coordinates at these
*     offsets are found, and transformed into graphics coordinates.

*  Parameters:
*     n 
*        The number of points to map. Static resources are released but
*        no points are mapped if zero is supplied.
*     dist
*        A pointer to an array holding "n" distances. A "dist" value of
*        zero corresponds to the starting position supplied in external 
*        variable Map3_origin. A "dist" value of one corresponds to the 
*        finishing position given by Map3_end.
*     x
*        A pointer to an array in which to store the "n" graphics X 
*        coordinate values corresponding to the positions in "dist".
*     y
*        A pointer to an array in which to store the "n" graphics Y
*        coordinate values corresponding to the positions in "dist".
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  External Variables:
*     Map3_ncoord = int (Read)
*        The number of axes in the physical coordinate system.
*     Map3_origin = const double * (Read)
*        A pointer to an array holding the physical coordinate value on 
*        each axis at the start of the curve (i.e. at dist = 0.0).
*     Map3_end = const double * (Read)
*        A pointer to an array holding the physical coordinate value on 
*        each axis at the end of the curve (i.e. at dist = 1.0).
*     Map3_scale = double (Read)
*        The scale factor to convert "dist" values into physical offsets 
*        along the geodesic curve.
*     Map3_plot = AstPlot * (Read)
*        A pointer to the Plot defining the mapping from graphics cordinates
*        to physical coordinates.
*     Map3_map = AstMapping * (Read)
*        A pointer to the mapping from graphics cordinates to physical 
*        coordinates extracted from the Plot.
*     Map3_frame = AstFrame * (Read)
*        A pointer to the Current Frame in the Plot.

*  Notes:
*     -  On the first call, this function allocates static resources which 
*     are used by subsequent invocation. These resources should be freed before
*     calling this function with new values for any of the external variables, 
*     or when no longer needed, by calling this function with "n" supplied as 
*     zero.
*     -  If an error has already occurred, this runction returns without 
*     action ,except that if "n" is supplied as zero then static resources
*     are released even if an error has already occurred.

*/

/* Local Constants: */
   static AstPointSet *pset1 = NULL; /* PointSet holding physical coords */
   static AstPointSet *pset2 = NULL; /* PointSet holding graphics coords */
   static double **ptr1 = NULL;      /* Pointer to physical coord data */
   static double *ptr2[ 2 ] = {NULL,NULL}; /* Pointers to graphics coord data */
   static int nc = 0;                /* No. of physical axes */
   static int nl = 0;                /* No. of points in pset1 and pset2 */
   static double *pos = NULL;        /* Pointer to memory for a single position */
   int i, j;                         /* Loop counts */

/* If zero points were supplied, release any PointSets which have
   been created and return. */
   if( n == 0 ){
      nl = 0;       
      nc = 0;
      if( pset1 ) pset1 = astAnnul( pset1 );
      if( pset2 ) pset2 = astAnnul( pset2 );
      if( pos ) pos = (double *) astFree( (void *) pos );
      return;
   }
   
/* Otherwise, check the inherited global status. */
   if( !astOK ) return;

/* If the number of points to be mapped is different to last time, 
   set up some PointSets to store the specified number of points. */
   if( n != nl ){
      nl = n;

/* Create a PointSet to hold the physical coordinates corresponding to
   the supplied offsets. First annul any existing PointSet. */
      if( pset1 ) pset1 = astAnnul( pset1 );
      pset1 = astPointSet( n, Map3_ncoord, "" );   
      ptr1 = astGetPoints( pset1 );

/* Create a PointSet to hold the corresponding graphics coordinates. 
   The supplied "x" and "y" arrays will be used to store the data 
   so we do not need to get pointers to the data using astGetPoints. First 
   annul any existing PointSet. */
      if( pset2 ) pset2 = astAnnul( pset2 );
      pset2 = astPointSet( n, 2, "" );   

   }

/* If the number of physical axes is different to last time,  allocate
   memory to hold a single physical position. */
   if( nc != Map3_ncoord ){
      nc = Map3_ncoord;
      pos = (double *) astMalloc( sizeof(double)*(size_t)Map3_ncoord );
   }

/* Check the initialisation went OK (if done). */
   if( astOK ){

/* Loop round each offset along the curve, converting the normalised offset 
   in the range [0,1] to a physical offset, and then into a physical
   position, and store in PointSet 1. */
      for( i = 0; i < n; i++){
         astOffset( Map3_frame, Map3_origin, Map3_end, Map3_scale*dist[ i ],
                    pos );

         for( j = 0; j < Map3_ncoord; j++ ){
            ptr1[ j ][ i ] = pos[ j ];
         }

      }

/* Store pointers to the results arrays in PointSet 2. */
      ptr2[ 0 ] = x;
      ptr2[ 1 ] = y;   
      astSetPoints( pset2, ptr2 );

/* Map all the positions into graphics coordinates. */
      (void) Trans( Map3_plot, NULL, Map3_map, pset1, 0, pset2, 1, method, class );
   }
   
/* Return. */
   return;

}

static void Mark( AstPlot *this, int nmark, int ncoord, int indim, 
                  const double (*in)[], int type ){
/*
*++
*  Name:
c     astMark
f     AST_MARK

*  Purpose:
*     Draw a set of markers for a Plot.

*  Type:
*     Public virtual function.

*  Synopsis:
c     #include "plot.h"
c     void astMark( AstPlot *this, int nmark, int ncoord, int indim,
c                   const double (*in)[], int type )
f     CALL AST_MARK( THIS, NMARK, NCOORD, INDIM, IN, TYPE, STATUS )

*  Class Membership:
*     Plot method.

*  Description:
c     This function draws a set of markers (symbols) at positions
f     This routine draws a set of markers (symbols) at positions
*     specified in the physical coordinate system of a Plot. The
*     positions are transformed into graphical coordinates to
*     determine where the markers should appear within the plotting
*     area.

*  Parameters:
c     this
f     THIS = INTEGER (Given)
*        Pointer to the Plot.
c     nmark
f     NMARK = INTEGER (Given)
*        The number of markers to draw. This may be zero, in which
*        case nothing will be drawn.
c     ncoord
f     NCOORD = INTEGER (Given)
*        The number of coordinates being supplied for each mark
*        (i.e. the number of axes in the current Frame of the Plot, as
*        given by its Naxes attribute).
c     indim
f     INDIM = INTEGER (Given)
c        The number of elements along the second dimension of the "in"
f        The number of elements along the first dimension of the IN
*        array (which contains the marker coordinates). This value is
*        required so that the coordinate values can be correctly
*        located if they do not entirely fill this array. The value
c        given should not be less than "nmark".
f        given should not be less than NMARK.
c     in
f     IN( INDIM, NCOORD ) = DOUBLE PRECISION (Given)
c        A 2-dimensional array of shape "[ncoord][indim]" giving the
c        physical coordinates of the points where markers are to be
c        drawn. These should be stored such that the value of
c        coordinate number "coord" for input mark number "mark" is
c        found in element "in[coord][mark]".
f        A 2-dimensional array giving the physical coordinates of the
f        points where markers are to be drawn. These should be
f        stored such that the value of coordinate number COORD for
f        input mark number MARK is found in element IN(MARK,COORD).
c     type
f     TYPE = INTEGER (Given)
*        A value specifying the type (e.g. shape) of marker to be
*        drawn. The set of values which may be used (and the shapes
*        that will result) is determined by the underlying graphics
*        system.
f     STATUS = INTEGER (Given and Returned)
f        The global status.

*  Notes:
*     - Markers are not drawn at positions which have any coordinate
*     equal to the value AST__BAD (or where the transformation into
*     graphical coordinates yields coordinates containing the value
*     AST__BAD).
c     - If any marker position is clipped (see astClip), then the
f     - If any marker position is clipped (see AST_CLIP), then the
*     entire marker is not drawn.
*     - An error results if the base Frame of the Plot is not 2-dimensional.
*     - An error also results if the transformation between the
*     current and base Frames of the Plot is not defined (i.e. the
*     Plot's TranInverse attribute is zero).
*--
*/

/* Local Variables: */
   AstMapping *mapping;    /* Pointer to graphics->physical mapping */
   AstPointSet *pset1;     /* PointSet holding physical positions */
   AstPointSet *pset2;     /* PointSet holding graphics positions */
   const char *class;      /* Object class */
   const char *method;     /* Current method */
   const double **ptr1;    /* Pointer to physical positions */
   double **ptr2;          /* Pointer to graphics positions */
   double *xpd;            /* Pointer to next double precision x value */ 
   double *ypd;            /* Pointer to next double precision y value */ 
   float *x;               /* Pointer to single precision x values */ 
   float *xpf;             /* Pointer to next single precision x value */ 
   float *y;               /* Pointer to single precision y values */ 
   float *ypf;             /* Pointer to next single precision y value */ 
   int axis;               /* Axis index */
   int i;                  /* Loop count */
   int naxes;              /* No. of axes in the base Frame */
   int nn;                 /* Number of good marker positions */

/* Check the global error status. */
   if ( !astOK ) return;

/* Store the current method and class for inclusion in error messages
   generated by lower level functions. */
   method = "astMark";
   class = astClass( this );

/* Check the base Frame of the Plot is 2-D. */
   naxes = astGetNin( this );
   if( naxes != 2 && astOK ){
      astError( AST__NAXIN, "%s(%s): Number of axes (%d) in the base "
                "Frame of the supplied %s is invalid - this number should "
                "be 2.", method, class, naxes, class );
   } 

/* Also validate the input array dimension argument. */
   if ( astOK && ( indim < nmark ) ) {
      astError( AST__DIMIN, "%s(%s): The input array dimension value "
                "(%d) is invalid.", method, class, indim );
      astError( AST__DIMIN, "This should not be less than the number of "
                "markers being drawn (%d).", nmark );
   }

/* Establish the correct graphical attributes as defined by attributes
   with the supplied Plot. */
   GrfAttrs( this, MARKS_ID, 1, GRF__MARK );

/* Create a PointSet to hold the supplied physical coordinates. */
   pset1 = astPointSet( nmark, ncoord, "" );

/* Allocate memory to hold pointers to the first value on each axis. */
   ptr1 = (const double **) astMalloc( sizeof( const double * )*
                                       (size_t)( ncoord ));

/* Check the pointer can be used, then store pointers to the first value
   on each axis. */
   if( astOK ){
      for( axis = 0; axis < ncoord; axis++ ){
         ptr1[ axis ] = *in + axis*indim;
      }
   }

/* Store these pointers in the PointSet. */
   astSetPoints( pset1, (double **) ptr1 );

/* Transform the supplied data from the current frame (i.e. physical 
   coordinates) to the base frame (i.e. graphics coordinates) using 
   the inverse Mapping defined by the Plot. */
   mapping = astGetMapping( this, AST__BASE, AST__CURRENT );
   pset2 = Trans( this, NULL, mapping, pset1, 0, NULL, 0, method, class );
   mapping = astAnnul( mapping );

/* Get pointers to the graphics coordinates. */
   ptr2 = astGetPoints( pset2 );

/* Allocate memory to hold single precision versions of the graphics
   coordinates. */
   x = (float *) astMalloc( sizeof( float )*(size_t) nmark );
   y = (float *) astMalloc( sizeof( float )*(size_t) nmark );

/* Check the pointers can be used. */
   if( astOK ){

/* Store pointers to the next single and double precision x and y
   values. */
      xpf = x;
      ypf = y;
      xpd = ptr2[ 0 ];
      ypd = ptr2[ 1 ];
   
/* Convert the double precision values to single precision, rejecting
   any bad marker positions. */
      nn = 0;
      for( i = 0; i < nmark; i++ ){
         if( *xpd != AST__BAD && *ypd != AST__BAD ){
            nn++;
            *(xpf++) = (float) *(xpd++);
            *(ypf++) = (float) *(ypd++);
         } else {
            xpd++;
            ypd++;
         }
      }

/* Draw the remaining markers. */
      if( astOK && !astGMark( nn, x, y, type ) ){
         astError( AST__GRFER, "%s(%s): Graphics error in astGMark. ", 
                   method, class );
      }

   }

/* Free the memory used to store single precision graphics coordinates. */
   x = (float *) astFree( (void *) x );
   y = (float *) astFree( (void *) y );
   
/* Annul the PointSets. */
   pset1 = astAnnul( pset1 );
   pset2 = astAnnul( pset2 );

/* Free the memory holding the pointers to the first value on each axis. */
   ptr1 = (const double **) astFree( (void *) ptr1 );

/* Re-establish the original graphical attributes. */
   GrfAttrs( this, MARKS_ID, 0, GRF__MARK );

/* Return */
   return;
}

static void Opoly( const char *method, const char *class ){
/*
*  Name:
*     Opoly

*  Purpose:
*     Draws the current poly line.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void Opoly( const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function draws the current poly line, and empties the buffer.

*  Parameters:
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*/

/* Check the global status. */
   if( !astOK ) return;

/* Call a function in the low level graphics module GRF to draw the 
   poly-line. Report an error if anything goes wrong. */
   if( !astGLine( Poly_n, Poly_x, Poly_y ) ){
      astError( AST__GRFER, "%s(%s): Graphics error in astGLine. ", method, 
                class );
   }

/* Indicate that the poly-line buffer is now empty. */
   Poly_n = 0;

}

static int Overlap( AstPlot *this, int esc, const char *text, float x, 
                    float y, const char *just, float upx, float upy, 
                    float **work, const char *method, const char *class  ){
/*
*  Name:
*     Overlap

*  Purpose:
*     See if a major tick value label would overlap any of the previously 
*     drawn labels.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int Overlap( AstPlot *this, int esc, const char *text, float x, 
*                  float y, const char *just, float upx, float upy, 
*                  float **work, const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     A record is kept of the bounding boxes enclosing all the displayed
*     labels. If the bounding box of the new label defined by the given
*     parameter values would overlap any of the old bounding boxes, 0 is 
*     returned. Otherwise 1 is returned and the bounding box for the new 
*     label is added to the list of old bounding boxes.
*
*     This function also updates the external variables Box_lbnd and
*     Box_ubnd which hold the lower and upper bounds of the area enclosing
*     all used labels.

*  Parameters:
*     this
*        A pointer to the Plot.
*     esc
*        Should escape sequences in the text be interpreted?
*     text
*        A pointer to the label text string.
*     x
*        The graphics X coordinate of the label's reference point.
*     y
*        The graphics Y coordinate of the label's reference point.
*     just
*        A character string which specifies the location within the
*        text string which is to be placed at the reference position
*        given by x and y. The first character may be 'T' for "top",
*        'C' for "centre", or 'B' for "bottom", and specifies the
*        vertical location of the reference position. The second 
*        character may be 'L' for "left", 'C' for "centre", or 'R' 
*        for "right", and specifies the horizontal location of the 
*        reference position. If the string has less than 2 characters
*        then 'C' is used for the missing characters. 
*     upx
*        The x component of the up-vector for the text.
*     upy
*        The y component of the up-vector for the text.
*     work
*        A pointer to a place at which to store a pointer to an array of
*        floats holding the old bounding boxes. Memory to hold this array
*        is allocated automatically within this function. The pointer to
*        the array should be supplied as NULL on the first call to this 
*        function, and the array should be freed using astFree when no
*        longer needed.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     A boolean flag indicating if the new label overlaps any of the previous
*     labels.

*  Notes:
*     -  Zero is returned if an error has occurred, or if this function
*     should fail for any reason.

*/

/* Local Variables: */
   static int nbox = 0;   /* Number of boxes stored in "work" */
   int ret;               /* Does the new label overlap a previous label? */
   int i;                 /* Box index */
   float *cx;             /* Pointer to next corner's X value */
   float *cy;             /* Pointer to next corner's Y value */
   float xbn[ 4 ];        /* X coords at corners of new label's bounding box */
   float ybn[ 4 ];        /* Y coords at corners of new label's bounding box */

/* Initialise the returned value to indicate no overlap has been found. */
   ret = 0;

/* If no work array has been supplied, allocate one now with room for
   10 boxes. Each box requires 8 floats, 2 for each of the 4 corners. The
   X graphics coordinates at the 4 corners are stored in the first 4 floats, 
   and the corresponding Y graphics coordinates in the second group of 4 
   floats. */
   if( !(*work) ){
      nbox = 0;
      *work = (float *) astMalloc( 80*sizeof(float) );
   }

/* Check the global status. */
   if( !astOK ) return ret;

/* Get the bounds of the box containing the new label. */
   BoxText( this, esc, text, x, y,  just, upx, upy, xbn, ybn,
            method, class );

/* If the bounding box was obtained succesfully... */
   if( astOK ) {

/* Check for an overlap between the box and each of the previous boxes. */
      cx = *work;
      cy = *work + 4;
      for( i = 0; i < nbox; i++ ){

         if( BoxCheck( xbn, ybn, cx, cy ) ) {
            ret = 1;
            break;
         }

/* Increment the pointers to the next box. */
         cx += 8;
         cy += 8;

      }

/* If no overlap was found, add the new box to the list. */
      if( !ret ){
         *work = (float *) astGrow( (void *) *work, nbox + 1, 8*sizeof(float) );
         cx = *work + 8*(nbox++);
         cy = cx + 4;
         for( i = 0; i < 4; i++ ){
            cx[ i ] = xbn[ i ];
            cy[ i ] = ybn[ i ];
         }

/* Extend the bounds of the global bounding box held externally to include 
   the new box. */
         for( i = 0; i < 4; i++ ){
            Box_lbnd[ 0 ] = MIN( xbn[ i ], Box_lbnd[ 0 ] );
            Box_ubnd[ 0 ] = MAX( xbn[ i ], Box_ubnd[ 0 ] );
            Box_lbnd[ 1 ] = MIN( ybn[ i ], Box_lbnd[ 1 ] );
            Box_ubnd[ 1 ] = MAX( ybn[ i ], Box_ubnd[ 1 ] );
         }

      }

   }

/* If an error has occur, return a value of 0. */
   if( !astOK ) ret = 0;

/* Return the answer. */
   return ret;

}

static void PlotLabels( AstPlot *this, AstFrame *frame, int axis, 
                        LabelList *list, char *fmt, int nlab, float **box, 
                        const char *method, const char *class ) {
/*
*
*  Name:
*     PlotLabels

*  Purpose:
*     Draws the numerical labels which have been selected for display.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void PlotLabels( AstPlot *this, AstFrame *frame, int axis, 
*                      LabelList *list, char *fmt, int nlab, float **box, 
*                      const char *method, const char *class ) 

*  Class Membership:
*     Plot member function.

*  Description:
*     This function displays the numerical labels supplied in the
*     structure pointed to by "list". Overlapping labels are omitted, 
*     and redundant leading fields are removed from adjacent labels.
*     Nothing is plotted if the NumLab attribute for the axis is false.

*  Parameters:
*     this
*        A pointer to the Plot.
*     frame
*        A pointer to the current Frame of the Plot.
*     axis
*        The axis index (0 or 1).
*     list
*        A pointer to the LabelList structure holding information about
*        the selected numerical labels.
*     fmt
*        A pointer to a null terminated string holding the format
*        specification used to create the labels.
*     nlab
*        The number of labels described by "list".
*     box
*        A pointer to a place at which to store a pointer to an array of
*        floats holding the bounding boxes of displayed labels. Memory to 
*        hold this array is allocated automatically within this function. 
*        The pointer to the array should be supplied as NULL on the first 
*        call to this function, and the array should be freed using astFree 
*        when no longer needed.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.
*/

/* Local Constants: */
#define MAXFLD 20            /* Maximum no. of fields in label */

/* Local Variables: */
   LabelList *ll;            /* Pointer to next label structure */
   char *a;                  /* Pointer to next character */
   char *ctext;              /* Pointer to comparison label text */
   char *text;               /* Pointer to label text */
   const char *atext;        /* Pointer to abbreviated label text */
   int esc;                  /* Interpret escape sequences? */
   int i;                    /* Label index */
   int nz;                   /* Number of trailing zeros in this label */
   int nzmax;                /* Max. number of trailing zeros */
   int root;                 /* Index of unabbreviated label */

/* Return without action if an error has occurred, or there are no labels to 
   draw. */
   if( !astOK || nlab == 0 || !list || !astGetNumLab( this, axis ) ) return;

/* See if escape sequences are to be interpreted within text strings. */
   esc = astGetEscape( this );

/* If there is only 1 label to display, display it so long as it does not
   overlap any previosuly drawn labels. */
   if( nlab == 1 ) {

/* Check to see if the supplied label would overlap any other existing
   labels. */
      if( !Overlap( this, esc, list->text, (float) list->x, (float) list->y, 
                    list->just, (float) list->upx, (float) list->upy, box, 
                    method, class ) ) {

         astGText( list->text, (float) list->x, (float) list->y, list->just, 
                   (float) list->upx, (float) list->upy );

/* ENABLE-ESCAPE - Replace the above call to astGText with the call to
   DrawText below when escape sequences are enabled.
         DrawText( this, esc, list->text, (float) list->x, (float) list->y,
                   list->just, (float) list->upx, (float) list->upy, method, 
                   class );
*/
      }

/* If there is more than 1 label to draw... */
   } else {

/* Sort the supplied LabelList into ascending index order. */
      qsort( (void *) list, (size_t) nlab, sizeof(LabelList), Compare_LL );

/* Find the label with the largest number of trailing zeros (ignoring
   field delimiter characters). This label may be obscured by an earlier label,
   so loop round until one is found which is not obscured. */
      while( 1 ) {

         ll = list;
         nzmax = -1;
         for( i = 0; i < nlab; i++ ) {
            if( ll->index != DBL_MAX ) {
               text = ll->text;

/* Loop through each field (least significant first), counting the number
   of trailing zeros. Ignore non-digits (eg decimal points, +, -, etc). 

   NOTE - this assumes that field delimiter strings never contain any
   digits. When escape sequences are supported this will not be the case,
   and the following block of code will need to be replaced by something
   like the following block (currently commented out), which is based on
   a new Frame method "astFields" which decompoeses a formatted axis value
   into its separate fields. (ENABLE-ESCAPE) */
               nz = 0;
               for( a = text + strlen( text ) - 1; a >= text; a-- ) {
                  if( isdigit( (int) *a ) && *a != '0' ) break;
                  nz++;
               }

/*
               nf = astFields( frame, axis, fmt, text, MAXFLD, fld, nc, NULL );
               nz = 0;
               for( jf = nf - 1; jf >= 0; jf-- ) {
                  for( a = fld[ jf ] + nc[ jf ] - 1; a >= fld[ jf ]; a-- ) {
                     if( isdigit( (int) *a ) && *a != '0' ) break;
                     nz++;
                  }
               }
*/


/* If this label beats the previous maximum number of trailing zeros, record 
   the new maximum. */
               if( nz > nzmax ) {
                  nzmax = nz;
                  root = i;         
               }            
            }
            ll++;
         }

/* If no labels remain, return. */
         if( nzmax == -1 ) return;

/* Check to see if this label would overlap any other existing labels. */
         ll = list + root;
         if( !Overlap( this, esc, ll->text, (float) ll->x, (float) ll->y, 
                       ll->just, (float) ll->upx, (float) ll->upy, box, 
                       method, class ) ) {

/* If not, draw this "root" label without any abbreviation. */
            astGText( ll->text, (float) ll->x, (float) ll->y, ll->just, 
                      (float) ll->upx, (float) ll->upy );

/* ENABLE-ESCAPE - Replace the above call to astGText with the call to
   DrawText below when escape sequences are enabled.
            DrawText( this, esc, ll->text, (float) ll->x, (float) ll->y,
                      ll->just, (float) ll->upx, (float) ll->upy, method, 
                      class );
*/

/* Leave the loop once a label has been drawn. */
            break;

/* If the label overlaps an existing label, flag it by setting its index
   value to DBL_MAX. */
         } else {
            ll->index = DBL_MAX;
         }
      }
            
/* Draw the labels with lower indices (only those which do not overlap). */
      for( i = root - 1; i >= 0; i-- ) {
         ll = list + i;
         if( !Overlap( this, esc, ll->text, (float) ll->x, (float) ll->y, 
                       ll->just, (float) ll->upx, (float) ll->upy, box, 
                       method, class ) ) {
            text = ll->text;

/* Select the comparison text to be used when abbreviating redundant
   leading fields. Compare the current field with which ever neighbour 
   has the smaller absolute value. */
            if( fabs( ll->val ) < fabs( (ll + 1)->val ) ) {
               if( i > 0 ) {
                  ctext = (ll - 1)->text;
               } else {
                  ctext = (ll + 1)->text;
               }

            } else {
               if( i < nlab - 1 ) {
                  ctext = (ll + 1)->text;
               } else {
                  ctext = (ll - 1)->text;
               }
            }

/* Get an abbreviated form of the label from which any leading fields have 
   been removed which are identical to the leading fields in the comparison
   label. Do not allow the label to be totally removed by this abbreviation.
   When escape sequences are enabled, the astAbbrev argument list may
   need to be changed to include the format string pointed to by variable 
   "fmt".  (ENABLE-ESCAPE). */
            if( ctext && text ){
               atext = astAbbrev( frame, axis, ctext, text );
               if( !atext || !strlen( atext ) ) atext = text;
            } else {
               atext = text;
            }

/* Draw the label. */
            astGText( atext, (float) ll->x, (float) ll->y, ll->just, 
                      (float) ll->upx, (float) ll->upy );
/* ENABLE-ESCAPE - Replace the above call to astGText with the call to
   DrawText below when escape sequences are enabled.
            DrawText( this, esc, atext, (float) ll->x, (float) ll->y,
                      ll->just, (float) ll->upx, (float) ll->upy, method, 
                      class );
*/
         }
      }

/* In the same way, draw the labels with higher indices (only those which do 
   not overlap). */
      for( i = root + 1; i < nlab; i++ ) {
         ll = list + i;
         if( !Overlap( this, esc, ll->text, (float) ll->x, (float) ll->y, 
                       ll->just, (float) ll->upx, (float) ll->upy, box, 
                       method, class ) ) {
            text = ll->text;

/* Select the comparison text to be used when abbreviating redundant
   leading fields. Compare the current field with which ever neighbour 
   has the smaller absolute value. */
            if( fabs( ll->val ) > fabs( (ll - 1)->val ) ) {
               if( i > 0 ) {
                  ctext = (ll - 1)->text;
               } else {
                  ctext = (ll + 1)->text;
               }
            } else {
               if( i < nlab - 1 ) {
                  ctext = (ll + 1)->text;
               } else {
                  ctext = (ll - 1)->text;
               }
            }

/* Get an abbreviated form of the label from which any leading fields have 
   been removed which are identical to the leading fields in the comparison
   label. Do not allow the label to be totally removed by this abbreviation. 
   When escape sequences are enabled, the astAbbrev argument list may
   need to be changed to include the format string pointed to by variable 
   "fmt".  (ENABLE-ESCAPE). */
            if( ctext && text ){
               atext = astAbbrev( frame, axis, ctext, text );
               if( !atext || !strlen( atext ) ) atext = text;
            } else {
               atext = text;
            }

/* Draw the label. */
            astGText( atext, (float) ll->x, (float) ll->y, ll->just, 
                      (float) ll->upx, (float) ll->upy );
/* ENABLE-ESCAPE - Replace the above call to astGText with the call to
   DrawText below when escape sequences are enabled.
            DrawText( this, esc, atext, (float) ll->x, (float) ll->y,
                      ll->just, (float) ll->upx, (float) ll->upy, method, 
                      class );
*/
         }
      }
   }

/* Undefine macros local to this function. */
#undef MAXFLD

}

static void PolyCurve( AstPlot *this, int npoint, int ncoord, int indim, 
                       const double (*in)[] ){
/*
*++
*  Name:
c     astPolyCurve
f     AST_POLYCURVE

*  Purpose:
*     Draw a series of connected geodesic curves.

*  Type:
*     Public virtual function.

*  Synopsis:
c     #include "plot.h"
c     void astPolyCurve( AstPlot *this, int npoint, int ncoord, int indim, 
c                        const double (*in)[] )
f     CALL AST_POLYCURVE( THIS, NPOINT, NCOORD, INDIM, IN, STATUS )

*  Class Membership:
*     Plot method.

*  Description:
c     This function joins a series of points specified in the physical
c     coordinate system of a Plot by drawing a sequence of geodesic
c     curves.  It is equivalent to making repeated use of the astCurve
c     function (q.v.), except that astPolyCurve will generally be more
c     efficient when drawing many geodesic curves end-to-end. A
c     typical application of this might be in drawing contour lines.
f     This routine joins a series of points specified in the physical
f     coordinate system of a Plot by drawing a sequence of geodesic
f     curves.  It is equivalent to making repeated calls to the
f     AST_CURVE routine (q.v.), except that AST_POLYCURVE will
f     generally be more efficient when drawing many geodesic curves
f     end-to-end. A typical application of this might be in drawing
f     contour lines.
*
c     As with astCurve, full account is taken of the Mapping between
c     physical and graphical coordinate systems. This includes any
c     discontinuities and clipping established using astClip.
f     As with AST_CURVE, full account is taken of the Mapping between
f     physical and graphical coordinate systems. This includes any
f     discontinuities and clipping established using AST_CLIP.

*  Parameters:
c     this
f     THIS = INTEGER (Given)
*        Pointer to the Plot.
c     npoint
f     NPOINT = INTEGER (Given)
*        The number of points between which geodesic curves are to be drawn.
c     ncoord
f     NCOORD = INTEGER (Given)
*        The number of coordinates being supplied for each point (i.e.
*        the number of axes in the current Frame of the Plot, as given
*        by its Naxes attribute).
c     indim
f     INDIM = INTEGER (Given)
c        The number of elements along the second dimension of the "in"
f        The number of elements along the first dimension of the IN
*        array (which contains the input coordinates). This value is
*        required so that the coordinate values can be correctly
*        located if they do not entirely fill this array. The value
c        given should not be less than "npoint".
f        given should not be less than NPOINT.
c     in
f     IN( INDIM, NCOORD ) = DOUBLE PRECISION (Given)
c        A 2-dimensional array, of shape "[ncoord][indim]" giving the
c        physical coordinates of the points which are to be joined in
c        sequence by geodesic curves. These should be stored such that
c        the value of coordinate number "coord" for point number
c        "point" is found in element "in[coord][point]".
f        A 2-dimensional array giving the physical coordinates of the
f        points which are to be joined in sequence by geodesic
f        curves. These should be stored such that the value of
f        coordinate number COORD for input point number POINT is found
f        in element IN(POINT,COORD).
f     STATUS = INTEGER (Given and Returned)
f        The global status.

*  Notes:
*     - No curve is drawn on either side of any point which has any
*     coordinate equal to the value AST__BAD.
*     - An error results if the base Frame of the Plot is not
*     2-dimensional.
*     - An error also results if the transformation between the
*     current and base Frames of the Plot is not defined (i.e. the
*     Plot's TranInverse attribute is zero).
*--
*/
/* Local Variables: */
   const char *class;      /* Object class */
   const char *method;     /* Current method */
   const double **in_ptr;  /* Pointer to array of data pointers */
   double *finish;         /* Pointer to array holding segment end position */
   double *start;          /* Pointer to array holding segment start position */
   double d[ CRV_NPNT ];   /* Offsets to evenly spaced points along curve */
   double tol;             /* Absolute tolerance value */
   double x[ CRV_NPNT ];   /* X coords at evenly spaced points along curve */
   double y[ CRV_NPNT ];   /* Y coords at evenly spaced points along curve */
   int coord;              /* Loop counter for coordinates */
   int i;                  /* Loop count */
   int naxes;              /* No. of Frame axes */
   int ok;                 /* Are all start and end coords good? */

/* Check the global error status. */
   if ( !astOK ) return;

/* Store the current method, and the class of the supplied object for use 
   in error messages.*/
   method = "astPolyCurve";
   class = astGetClass( this );

/* Check the base Frame of the Plot is 2-D. */
   naxes = astGetNin( this );
   if( naxes != 2 && astOK ){
      astError( AST__NAXIN, "%s(%s): Number of axes (%d) in the base "
                "Frame of the supplied %s is invalid - this number should "
                "be 2.", method, class, naxes, class );
   } 

/* Check the current Frame of the Plot has ncoord axes. */
   naxes = astGetNout( this );
   if( naxes != ncoord && astOK ){
      astError( AST__NAXIN, "%s(%s): Number of axes (%d) in the current "
                "Frame of the supplied %s is invalid - this number should "
                "be %d (possible programming error).", method, class, naxes,
                class, ncoord );
   } 

/* Check the array dimension argument. */
   if ( astOK && ( indim < npoint ) ) {
      astError( AST__DIMIN, "%s(%s): The array dimension value "
                "(%d) is invalid.", method, class, indim );
      astError( AST__DIMIN, "This should not be less than the number of "
                "points being drawn (%d).", npoint );
   }

/* Allocate memory to hold the array of data pointers, the start position,
   and the end position. */
   if ( astOK ) {
      in_ptr = (const double **) astMalloc( sizeof( const double * ) *
                                            (size_t) ncoord );
      start = (double *) astMalloc( sizeof( double ) * (size_t) ncoord );
      finish = (double *) astMalloc( sizeof( double ) * (size_t) ncoord );
      
/* Set up externals used to communicate with the Map3 function...
   The number of axes in the physical coordinate system (i.e. the current
   Frame). */
      Map3_ncoord = ncoord;

/* A pointer to the Plot, the Current Frame, and and Mapping. */
      Map3_plot = this;
      Map3_frame = astGetFrame( this, AST__CURRENT );
      Map3_map = astGetMapping( this, AST__BASE, AST__CURRENT );

/* Convert the tolerance from relative to absolute graphics coordinates. */
      tol = astGetTol( this )*MAX( this->xhi - this->xlo, 
                                   this->yhi - this->ylo );

/* Now set up the external variables used by the Crv and CrvLine function. */
      Crv_tol = tol;
      Crv_limit = 0.5*tol*tol;
      Crv_map = Map3;
      Crv_ink = 1;
      Crv_xlo = this->xlo;
      Crv_xhi = this->xhi;
      Crv_ylo = this->ylo;
      Crv_yhi = this->yhi;

/* Set up a list of points spread evenly over each curve segment. */
      for( i = 0; i < CRV_NPNT; i++ ){
        d[ i ] = ( (double) i)/( (double) CRV_NSEG );
      }

/* Initialise the data pointers to locate the coordinate data in
   the "in" array. */
      if ( astOK ) {
         for ( coord = 0; coord < ncoord; coord++ ) {
            in_ptr[ coord ] = *in + coord * indim;
         }

/* Establish the correct graphical attributes as defined by attributes
   with the supplied Plot. */
         GrfAttrs( this, CURVE_ID, 1, GRF__LINE );

/* Loop round each curve segment. */
         for( i = 1 ; i < npoint; i++ ) {

/* Store the start position and check it for bad values. Increment the
   pointers to the next position on each axis, so that they refer to the
   finish point of the current curve segment. */
            ok = 1;
            for( coord = 0; coord < ncoord; coord++ ) {
               if( *( in_ptr[coord] ) == AST__BAD ){
                  ok = 0;
               } else {
                  start[ coord ] = *( in_ptr[coord] );
               }
               ( in_ptr[coord] )++;
            }

/* Store the end position and check it for bad values. Do not increment
   the axis pointers. This means that they will refer to the start position
   of the next curve segment on the next pass through this loop. */
            for( coord = 0; coord < ncoord; coord++ ) {
               if( *( in_ptr[coord] ) == AST__BAD ){
                  ok = 0;
               } else {
                  finish[ coord ] = *( in_ptr[coord] );
               }
            }

/* Pass on to the next curve segment if either the start or finish position
   was bad. */
            if( ok ) {

/* Set up the remaining externals used to communicate with the Map3
   function... */

/* The physical coordinates at the start of the curve. */
               Map3_origin = start;

/* The physical coordinates at the end of the curve. */
               Map3_end = finish;

/* The scale factor to convert "dist" values into physical offset values. */
               Map3_scale = astDistance( Map3_frame, start, finish );

/* Now set up the remaining external variables used by the Crv and CrvLine 
   function. */
               Crv_ux0 = AST__BAD;    
               Crv_out = 1;
               Crv_xbrk = Curve_data.xbrk;
               Crv_ybrk = Curve_data.ybrk;
               Crv_vxbrk = Curve_data.vxbrk;
               Crv_vybrk = Curve_data.vybrk;

/* Map the evenly spread distances between "start" and "finish" into graphics 
   coordinates. */
               Map3( CRV_NPNT, d, x, y, method, class );

/* Use Crv and Map3 to draw the curve segment. */
               Crv( d, x, y, method, class );

            }
         }

/* End the last poly line. */
         Opoly( method, class );

/* Tidy up the static data used by Map3. */
         Map3( 0, NULL, NULL, NULL, method, class );

/* Re-establish the original graphical attributes. */
         GrfAttrs( this, CURVE_ID, 0, GRF__LINE );

      }

/* Annul the Frame and Mapping. */
      Map3_frame = astAnnul( Map3_frame );
      Map3_map = astAnnul( Map3_map );

/* Free the memory used for the data pointers, and start and end positions. */
      in_ptr = (const double **) astFree( (void *) in_ptr );
      start = (double *) astFree( (void *) start );
      finish = (double *) astFree( (void *) finish ); 
   }

/* Return. */
   return;

}

static void RemoveFrame( AstFrameSet *this_fset, int iframe ) {
/*
*  Name:
*     RemoveFrame

*  Purpose:
*     Remove a Frame from a Plot.

*  Type:
*     Public virtual function.

*  Synopsis:
*     #include "plot.h"
*     void RemoveFrame( AstFrameSet *this_fset, int iframe )

*  Class Membership:
*     Plot member function (over-rides the astRemoveFrame public
*     method inherited from the FrameSet class).

*  Description:
*     This function removes a Frame from a Plot. All other Frames
*     in the Plot have their indices re-numbered from one (if
*     necessary), but are otherwise unchanged.
*
*     If the index of the clipping Frame is changed, the index value 
*     stored in the Plot is updated. If the clipping Frame itself is
*     removed, all clipping information is removed from the Plot.

*  Parameters:
*     this_fset
*        Pointer to the FrameSet component of the Plot.
*     iframe
*        The index within the Plot of the Frame to be removed.
*        This value should lie in the range from 1 to the number of
*        Frames in the Plot (as given by its Nframe attribute).

*/

/* Local Variables: */
   AstPlot *this;          /* Pointer to Plot structure */
   int ifrm;               /* Validated frame index */

/* Check the global error status. */
   if ( !astOK ) return;

/* Obtain a pointer to the Plot structure. */
   this = (AstPlot *) this_fset;

/* Validate the frame index. */
   ifrm = astValidateFrameIndex( this_fset, iframe, "astRemoveFrame" );

/* Invoke the parent astRemoveFrame method to remove the Frame. */
   (*parent_removeframe)( this_fset, iframe );

/* If the index of the removed Frame is smaller than the clipping Frame
   index, then decrement the clipping Frame index so that the same Frame 
   will be used in future. */
   if( astOK ){
      if( ifrm < this->clip_frame ){
         (this->clip_frame)--;

/* If the clipping fgrame itself has been removed, indicate that no
   clipping should nbow be performed. */
      } else if( ifrm == this->clip_frame ){
         astClip( this, AST__NOFRAME, NULL, NULL );
      }
   }
}

static void SetAttrib( AstObject *this_object, const char *setting ) {
/*
*  Name:
*     SetAttrib

*  Purpose:
*     Set an attribute value for a Plot.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void SetAttrib( AstObject *this, const char *setting )

*  Class Membership:
*     Plot member function (over-rides the astSetAttrib protected
*     method inherited from the FrameSet class).

*  Description:
*     This function assigns an attribute value for a Plot, the
*     attribute and its value being specified by means of a string of
*     the form:
*
*        "attribute= value "
*
*     Here, "attribute" specifies the attribute name and should be in
*     lower case with no white space present. The value to the right
*     of the "=" should be a suitable textual representation of the
*     value to be assigned and this will be interpreted according to
*     the attribute's data type.  White space surrounding the value is
*     only significant for string attributes.

*  Parameters:
*     this
*        Pointer to the Plot.
*     setting
*        Pointer to a null terminated string specifying the new attribute
*        value.
*/

/* Local Variables: */
   AstPlot *this;                /* Pointer to the Plot structure */
   char label[21];               /* Graphics item label */
   double dval;                  /* Double attribute value */
   int axis;                     /* Index for the axis */
   int edge;                     /* Index of edge within list */
   int id;                       /* Plot object id */
   int ival;                     /* Int attribute value */
   int len;                      /* Length of setting string */
   int nc;                       /* Number of characters read by sscanf */

/* Check the global error status. */
   if ( !astOK ) return;

/* Obtain a pointer to the Plot structure. */
   this = (AstPlot *) this_object;

/* Obtain the length of the setting string. */
   len = (int) strlen( setting );

/* Test for each recognised attribute in turn, using "sscanf" to parse
   the setting string and extract the attribute value (or an offset to
   it in the case of string values). In each case, use the value set
   in "nc" to check that the entire string was matched. Once a value
   has been obtained, use the appropriate method to set it. */

/* Tol. */
/* ---- */
   if ( nc = 0,
        ( 1 == sscanf( setting, "tol= %lg %n", &dval, &nc ) )
        && ( nc >= len ) ) {
      astSetTol( this, dval );

/* Grid. */
/* ----- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "grid= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetGrid( this, ival );

/* TickAll. */
/* -------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "tickall= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetTickAll( this, ival );

/* Border. */
/* ------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "border= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetBorder( this, ival );

/* ClipOp. */
/* ------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "clipop= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetClipOp( this, ival );

/* DrawTitle. */
/* ---------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "drawtitle= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetDrawTitle( this, ival );

/* DrawAxes. */
/* --------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "drawaxes= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetDrawAxes( this, ival );

/* Escape. */
/* ------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "escape= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetEscape( this, ival );

/* Edge(axis). */
/* ----------- */
   } else if ( nc = 0,
               ( 1 == sscanf( setting, "edge(%d)= %n%*s %n", &axis, &ival, &nc ) )
               && ( nc >= len ) ) {
      edge = FullForm( "left right top bottom", setting + ival, setting, 
                       "astSet", astGetClass( this ) );
      if( edge == 0 ) {
         astSetEdge( this, axis - 1, LEFT );
      } else if( edge == 1 ) {
         astSetEdge( this, axis - 1, RIGHT );
      } else if( edge == 2 ) {
         astSetEdge( this, axis - 1, TOP );
      } else if( edge == 3 ) {
         astSetEdge( this, axis - 1, BOTTOM );
      }

/* LabelAt (axis). */
/* --------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "labelat(%d)= %lg %n",
                              &axis, &dval, &nc ) )
               && ( nc >= len ) ) {
      astSetLabelAt( this, axis - 1, dval );

/* Centre(axis). */
/* ------------ */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "centre(%d)= %lg %n",
                              &axis, &dval, &nc ) )
               && ( nc >= len ) ) {
      astSetCentre( this, axis - 1, dval );

/* Gap. */
/* ---- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "gap= %lg %n", &dval, &nc ) )
        && ( nc >= len ) ) {
      astSetGap( this, 0, dval );
      astSetGap( this, 1, dval );

/* Gap(axis). */
/* ---------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "gap(%d)= %lg %n",
                              &axis, &dval, &nc ) )
               && ( nc >= len ) ) {
      astSetGap( this, axis - 1, dval );

/* NumLabGap. */
/* -------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "numlabgap= %lg %n", &dval, &nc ) )
        && ( nc >= len ) ) {
      astSetNumLabGap( this, 0, dval );
      astSetNumLabGap( this, 1, dval );

/* NumLabGap(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "numlabgap(%d)= %lg %n",
                              &axis, &dval, &nc ) )
               && ( nc >= len ) ) {
      astSetNumLabGap( this, axis - 1, dval );

/* TextLabGap. */
/* -------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "textlabgap= %lg %n", &dval, &nc ) )
        && ( nc >= len ) ) {
      astSetTextLabGap( this, 0, dval );
      astSetTextLabGap( this, 1, dval );

/* TextLabGap(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "textlabgap(%d)= %lg %n",
                              &axis, &dval, &nc ) )
               && ( nc >= len ) ) {
      astSetTextLabGap( this, axis - 1, dval );

/* LabelUp. */
/* -------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "labelup= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetLabelUp( this, 0, ival );
      astSetLabelUp( this, 1, ival );

/* LabelUp(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "labelup(%d)= %d %n",
                              &axis, &ival, &nc ) )
               && ( nc >= len ) ) {
      astSetLabelUp( this, axis - 1, ival );

/* NumLab. */
/* -------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "numlab= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetNumLab( this, 0, ival );
      astSetNumLab( this, 1, ival );

/* NumLab(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "numlab(%d)= %d %n",
                              &axis, &ival, &nc ) )
               && ( nc >= len ) ) {
      astSetNumLab( this, axis - 1, ival );

/* MinTick. */
/* -------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "mintick= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetMinTick( this, 0, ival );
      astSetMinTick( this, 1, ival );

/* MinTick(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "mintick(%d)= %d %n",
                              &axis, &ival, &nc ) )
               && ( nc >= len ) ) {
      astSetMinTick( this, axis - 1, ival );

/* TextLab. */
/* ---------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "textlab= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetTextLab( this, 0, ival );
      astSetTextLab( this, 1, ival );

/* TextLab(axis). */
/* ---------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "textlab(%d)= %d %n",
                              &axis, &ival, &nc ) )
               && ( nc >= len ) ) {
      astSetTextLab( this, axis - 1, ival );

/* LabelUnits. */
/* --------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "labelunits= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      astSetLabelUnits( this, 0, ival );
      astSetLabelUnits( this, 1, ival );

/* LabelUnits(axis). */
/* ---------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "labelunits(%d)= %d %n",
                              &axis, &ival, &nc ) )
               && ( nc >= len ) ) {
      astSetLabelUnits( this, axis - 1, ival );

/* Style. */
/* ------ */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "style= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      for( id = 0; id < AST__NPID; id++ ) astSetStyle( this, id, ival );

/* Style(label). */
/* ------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "style(%20[^()])= %d %n",
                              label, &ival, &nc ) )
               && ( nc >= len ) ) {
      astSetStyle( this, FullForm( GrfLabels, label, setting, "astSet", astGetClass( this ) ), ival );

/* Font. */
/* ----- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "font= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      for( id = 0; id < AST__NPID; id++ ) astSetFont( this, id, ival );

/* Font(label). */
/* ------------ */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "font(%20[^()])= %d %n",
                              label, &ival, &nc ) )
               && ( nc >= len ) ) {
      astSetFont( this, FullForm( GrfLabels, label, setting, "astSet", astGetClass( this ) ), ival );

/* Colour. */
/* ------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "colour= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      for( id = 0; id < AST__NPID; id++ ) astSetColour( this, id, ival );

/* Colour(label). */
/* -------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "colour(%20[^()])= %d %n",
                              label, &ival, &nc ) )
               && ( nc >= len ) ) {
      astSetColour( this, FullForm( GrfLabels, label, setting, "astSet", astGetClass( this ) ), ival );

/* Color. */
/* ------ */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "color= %d %n", &ival, &nc ) )
        && ( nc >= len ) ) {
      for( id = 0; id < AST__NPID; id++ ) astSetColour( this, id, ival );

/* Color(label). */
/* ------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "color(%20[^()])= %d %n",
                              label, &ival, &nc ) )
               && ( nc >= len ) ) {
      astSetColour( this, FullForm( GrfLabels, label, setting, "astSet", astGetClass( this ) ), ival );

/* Width. */
/* ------ */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "width= %lg %n", &dval, &nc ) )
        && ( nc >= len ) ) {
      for( id = 0; id < AST__NPID; id++ ) astSetWidth( this, id, dval );

/* Width(label). */
/* ------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "width(%20[^()])= %lg %n",
                              label, &dval, &nc ) )
               && ( nc >= len ) ) {
      astSetWidth( this, FullForm( GrfLabels, label, setting, "astSet", astGetClass( this ) ), dval );

/* Size. */
/* ----- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "size= %lg %n", &dval, &nc ) )
        && ( nc >= len ) ) {
      for( id = 0; id < AST__NPID; id++ ) astSetSize( this, id, dval );

/* Size(label). */
/* ------------ */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "size(%20[^()])= %lg %n",
                              label, &dval, &nc ) )
               && ( nc >= len ) ) {
      astSetSize( this, FullForm( GrfLabels, label, setting, "astSet", astGetClass( this ) ), dval );

/* TitleGap. */
/* ----------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "titlegap= %lg %n", &dval, &nc ) )
        && ( nc >= len ) ) {
      astSetTitleGap( this, dval );

/* MajTickLen. */
/* ----------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "majticklen= %lg %n", &dval, &nc ) )
        && ( nc >= len ) ) {
      astSetMajTickLen( this, 0, dval );
      astSetMajTickLen( this, 1, dval );

/* MajTickLen(axis). */
/* ----------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "majticklen(%d)= %lg %n",
                              &axis, &dval, &nc ) )
               && ( nc >= len ) ) {
      astSetMajTickLen( this, axis - 1, dval );

/* MinTickLen. */
/* ----------- */
   } else if ( nc = 0,
        ( 1 == sscanf( setting, "minticklen= %lg %n", &dval, &nc ) )
        && ( nc >= len ) ) {
      astSetMinTickLen( this, 0, dval );
      astSetMinTickLen( this, 1, dval );

/* MinTickLen(axis). */
/* ----------------- */
   } else if ( nc = 0,
               ( 2 == sscanf( setting, "minticklen(%d)= %lg %n",
                              &axis, &dval, &nc ) )
               && ( nc >= len ) ) {
      astSetMinTickLen( this, axis - 1, dval );

/* Labelling. */
/* -------- */
   } else if ( nc = 0,
               ( 0 == sscanf( setting, "labelling= %n%*s %n", &ival, &nc ) )
               && ( nc >= len ) ) {
      astSetLabelling( this, FullForm( "exterior interior", 
                                        setting + ival, setting, 
                                        "astSet", astGetClass( this ) )
                      );

/* If the attribute is still not recognised, pass it on to the parent
   method for further interpretation. */
   } else {
      (*parent_setattrib)( this_object, setting );
   }

/* Undefine macros local to this function. */
#undef MATCH
}

static int TestAttrib( AstObject *this_object, const char *attrib ) {
/*
*  Name:
*     TestAttrib

*  Purpose:
*     Test if a specified attribute value is set for a Plot.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     int TestAttrib( AstObject *this, const char *attrib )

*  Class Membership:
*     Plot member function (over-rides the astTestAttrib protected
*     method inherited from the FrameSet class).

*  Description:
*     This function returns a boolean result (0 or 1) to indicate whether
*     a value has been set for one of a Plot's attributes.

*  Parameters:
*     this
*        Pointer to the Plot.
*     attrib
*        Pointer to a null terminated string specifying the attribute
*        name.  This should be in lower case with no surrounding white
*        space.

*  Returned Value:
*     One if a value has been set, otherwise zero.

*  Notes:
*     - A value of zero will be returned if this function is invoked
*     with the global status set, or if it should fail for any reason.
*/

/* Local Variables: */
   AstPlot *this;                /* Pointer to the Plot structure */
   char label[21];               /* Graphics item label */
   int axis;                     /* Axis number */
   int len;                      /* Length of attrib string */
   int nc;                       /* No. characters read by sscanf */
   int result;                   /* Result value to return */

/* Initialise. */
   result = 0;

/* Check the global error status. */
   if ( !astOK ) return result;

/* Obtain a pointer to the Plot structure. */
   this = (AstPlot *) this_object;

/* Obtain the length of the attrib string. */
   len = strlen( attrib );

/* Check the attribute name and test the appropriate attribute. */

/* Tol. */
/* ---- */
   if ( !strcmp( attrib, "tol" ) ) {
      result = astTestTol( this );

/* Edge(axis). */
/* ----------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "edge(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      result = astTestEdge( this, axis - 1 );

/* Grid. */
/* ----- */
   } else if ( !strcmp( attrib, "grid" ) ) {
      result = astTestGrid( this );

/* TickAll. */
/* -------- */
   } else if ( !strcmp( attrib, "tickall" ) ) {
      result = astTestTickAll( this );

/* Border. */
/* ------- */
   } else if ( !strcmp( attrib, "border" ) ) {
      result = astTestBorder( this );

/* ClipOp. */
/* ------- */
   } else if ( !strcmp( attrib, "clipop" ) ) {
      result = astTestClipOp( this );

/* DrawTitle. */
/* ---------- */
   } else if ( !strcmp( attrib, "drawtitle" ) ) {
      result = astTestDrawTitle( this );

/* DrawAxes. */
/* --------- */
   } else if ( !strcmp( attrib, "drawaxes" ) ) {
      result = astTestDrawAxes( this );

/* Escape. */
/* ------- */
   } else if ( !strcmp( attrib, "escape" ) ) {
      result = astTestEscape( this );

/* Gap. */
/* ---- */
   } else if ( !strcmp( attrib, "gap" ) ) {
      result = astTestGap( this, 0 );

/* Gap(axis). */
/* ---------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "gap(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      result = astTestGap( this, axis - 1 );

/* NumLabGap. */
/* --------- */
   } else if ( !strcmp( attrib, "numlabgap" ) ) {
      result = astTestNumLabGap( this, 0 );

/* NumLabGap(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "numlabgap(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      result = astTestNumLabGap( this, axis - 1 );

/* TextLabGap. */
/* --------- */
   } else if ( !strcmp( attrib, "textlabgap" ) ) {
      result = astTestTextLabGap( this, 0 );

/* TextLabGap(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "textlabgap(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      result = astTestTextLabGap( this, axis - 1 );

/* LabelUp. */
/* -------- */
   } else if ( !strcmp( attrib, "labelup" ) ) {
      result = astTestLabelUp( this, 0 );

/* LabelUp(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "labelup(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      result = astTestLabelUp( this, axis - 1 );

/* NumLab. */
/* -------- */
   } else if ( !strcmp( attrib, "numlab" ) ) {
      result = astTestNumLab( this, 0 );

/* NumLab(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "numlab(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      result = astTestNumLab( this, axis - 1 );

/* MinTick. */
/* -------- */
   } else if ( !strcmp( attrib, "mintick" ) ) {
      result = astTestMinTick( this, 0 );

/* MinTick(axis). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "mintick(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      result = astTestMinTick( this, axis - 1 );

/* TextLab. */
/* ---------- */
   } else if ( !strcmp( attrib, "textlab" ) ) {
      result = astTestTextLab( this, 0 );

/* TextLab(axis). */
/* ---------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "textlab(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      result = astTestTextLab( this, axis - 1 );

/* LabelUnits. */
/* --------- */
   } else if ( !strcmp( attrib, "labelunits" ) ) {
      result = astTestLabelUnits( this, 0 );

/* LabelUnits(axis). */
/* --------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "labelunits(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      result = astTestLabelUnits( this, axis - 1 );

/* Style. */
/* ------ */
   } else if ( !strcmp( attrib, "style" ) ) {
      result = astTestStyle( this, BORDER_ID );

/* Style(label). */
/* ------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "style(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      result = astTestStyle( this, FullForm( GrfLabels, label, attrib, "astTest", astGetClass( this ) ) );

/* Font. */
/* ----- */
   } else if ( !strcmp( attrib, "font" ) ) {
      result = astTestFont( this, TEXTLABS_ID );

/* Font(label). */
/* ------------ */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "font(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      result = astTestFont( this, FullForm( GrfLabels, label, attrib, "astTest", astGetClass( this ) ) );

/* Colour. */
/* ------- */
   } else if ( !strcmp( attrib, "colour" ) ) {
      result = astTestColour( this, TEXTLABS_ID );

/* Color. */
/* ------- */
   } else if ( !strcmp( attrib, "color" ) ) {
      result = astTestColour( this, TEXTLABS_ID );

/* Colour(label). */
/* -------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "colour(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      result = astTestColour( this, FullForm( GrfLabels, label, attrib, "astTest", astGetClass( this ) ) );

/* Color(label). */
/* ------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "color(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      result = astTestColour( this, FullForm( GrfLabels, label, attrib, "astTest", astGetClass( this ) ) );

/* Width. */
/* ------ */
   } else if ( !strcmp( attrib, "width" ) ) {
      result = astTestWidth( this, BORDER_ID );

/* Width(label). */
/* ------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "width(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      result = astTestWidth( this, FullForm( GrfLabels, label, attrib, "astTest", astGetClass( this ) ) );

/* Size. */
/* ----- */
   } else if ( !strcmp( attrib, "size" ) ) {
      result = astTestSize( this, TEXTLABS_ID );

/* Size(label). */
/* ------------ */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "size(%20[^()])%n", label, &nc ) )
               && ( nc >= len ) ) {
      result = astTestSize( this, FullForm( GrfLabels, label, attrib, "astTest", astGetClass( this ) ) );

/* TitleGap. */
/* --------- */
   } else if ( !strcmp( attrib, "titlegap" ) ) {
      result = astTestTitleGap( this );

/* MajTickLen. */
/* ----------- */
   } else if ( !strcmp( attrib, "majticklen" ) ) {
      result = astTestMajTickLen( this, 0 );

/* MajTickLen(axis). */
/* ---------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "majticklen(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      result = astTestMajTickLen( this, axis - 1 );

/* MinTickLen. */
/* ----------- */
   } else if ( !strcmp( attrib, "minticklen" ) ) {
      result = astTestMinTickLen( this, 0 );

/* MinTickLen(axis). */
/* ---------------- */
   } else if ( nc = 0,
               ( 1 == sscanf( attrib, "minticklen(%d)%n", &axis, &nc ) )
               && ( nc >= len ) ) {
      result = astTestMinTickLen( this, axis - 1 );

/* Labelling. */
/* -------- */
   } else if ( !strcmp( attrib, "labelling" ) ) {
      result = astTestLabelling( this );

/* If the attribute is still not recognised, pass it on to the parent
   method for further interpretation. */
   } else {
      result = (*parent_testattrib)( this_object, attrib );
   }

/* Return the result, */
   return result;
}

static void Text( AstPlot *this, const char *text, const double pos[], 
                  const float up[2], const char *just ){
/*
*++
*  Name:
c     astText
f     AST_TEXT

*  Purpose:
*     Draw a text string for a Plot.

*  Type:
*     Public virtual function.

*  Synopsis:
c     #include "plot.h"
c     void astText( AstPlot *this, const char *text, const double pos[], 
c                   const float up[ 2 ], const char *just )
f     CALL AST_TEXT( THIS, TEXT, POS, UP, JUST, STATUS )

*  Class Membership:
*     Plot method.

*  Description:
*     This function draws a string of text at a position specified in
*     the physical coordinate system of a Plot. The physical position
*     is transformed into graphical coordinates to determine where the
*     text should appear within the plotting area.

*  Parameters:
c     this
f     THIS = INTEGER (Given)
*        Pointer to the Plot.
c     text
f     TEXT = CHARACTER * ( * ) (Given)
c        Pointer to a null-terminated character string containing the
f        A character string containing the
*        text to be drawn. Trailing white space is ignored.
c     pos
f     POS( * ) = DOUBLE PRECISION (Given)
*        An array, with one element for each axis of the Plot, giving
*        the physical coordinates of the point where the reference
*        position of the text string is to be placed.
c     up
f     UP( 2 ) = REAL (Given)
*        An array holding the components of a vector in the "up"
*        direction of the text (in graphical coordinates). For
c        example, to get horizontal text, the vector {0.0f,1.0f} should
f        example, to get horizontal text, the vector [0.0,1.0] should
*        be supplied.
c     just
f     JUST = CHARACTER * ( * ) (Given)
c        Pointer to a null-terminated character string identifying the
f        A character string identifying the
*        reference point for the text being drawn. The first character in
*        this string identifies the reference position in the "up" direction
*        and may be "B", "C" or "T". The second character identifies the 
*        side-to-side reference position and may be "L", "C" or "R" (for 
*        left, centre or right). The string is case-insensitive, and only 
*        the first two characters are significant.
*
*        For example, a value of "BL" means that the bottom left point
*        of the original (un-rotated) text is to be drawn at the
c        position given by "pos".
f        position given by POS.

f     STATUS = INTEGER (Given and Returned)
f        The global status.

*  Notes:
*     - Text is not drawn at positions which have any coordinate equal
*     to the value AST__BAD (or where the transformation into
*     graphical coordinates yields coordinates containing the value
*     AST__BAD).
c     - If the plotting position is clipped (see astClip), then no
f     - If the plotting position is clipped (see AST_CLIP), then no
*     text is drawn.
*     - An error results if the base Frame of the Plot is not
*     2-dimensional.
*     - An error also results if the transformation between the
*     current and base Frames of the Plot is not defined (i.e. the
*     Plot's TranInverse attribute is zero).
*--
*/

/* Local Variables: */
   AstMapping *mapping;    /* Pointer to graphics->physical mapping */
   AstPointSet *pset1;     /* PointSet holding physical positions */
   AstPointSet *pset2;     /* PointSet holding graphics positions */
   const char *class;      /* Object class */
   const char *method;     /* Current method */
   const double **ptr1;    /* Pointer to physical positions */
   char ljust[3];          /* Upper case copy of "just" */
   char *ltext;            /* Local copy of "text" excluding trailing spaces */
   double **ptr2;          /* Pointer to graphics positions */
   int axis;               /* Axis index */
   int naxes;              /* No. of axes in the base Frame */
   int ncoord;             /* No. of axes in the current Frame */
   int ulen;               /* Length of "text" excluding trailing spaces */

/* Check the global error status. */
   if ( !astOK || !text ) return;

/* Store the current method and class for inclusion in error messages
   generated by lower level functions. */
   method = "astText";
   class = astClass( this );

/* Check the base Frame of the Plot is 2-D. */
   naxes = astGetNin( this );
   if( naxes != 2 && astOK ){
      astError( AST__NAXIN, "%s(%s): Number of axes (%d) in the base "
                "Frame of the supplied %s is invalid - this number should "
                "be 2.", method, class, naxes, class );
   } 

/* Establish the correct graphical attributes as defined by attributes
   with the supplied Plot. */
   GrfAttrs( this, TEXT_ID, 1, GRF__TEXT );

/* Get the number of coordinates in the physical coordinate frame. */
   ncoord = astGetNout( this );   

/* Create a PointSet to hold the supplied physical coordinates. */
   pset1 = astPointSet( 1, ncoord, "" );

/* Allocate memory to hold pointers to the first value on each axis. */
   ptr1 = (const double **) astMalloc( sizeof( const double * )*
                                       (size_t)( ncoord ));

/* Check the pointer can be used, then store pointers to the first value
   on each axis. */
   if( astOK ){
      for( axis = 0; axis < ncoord; axis++ ){
         ptr1[ axis ] = pos + axis;
      }
   }

/* Store these pointers in the PointSet. */
   astSetPoints( pset1, (double **) ptr1 );

/* Transform the supplied data from the current frame (i.e. physical 
   coordinates) to the base frame (i.e. graphics coordinates) using 
   the inverse Mapping defined by the Plot. */
   mapping = astGetMapping( this, AST__BASE, AST__CURRENT );
   pset2 = Trans( this, NULL, mapping, pset1, 0, NULL, 0, method, class );
   mapping = astAnnul( mapping );

/* Get pointers to the graphics coordinates. */
   ptr2 = astGetPoints( pset2 );

/* Take a copy of the string excluding any trailing white space. */
   ulen = ChrLen( text );
   ltext = (char *) astStore( NULL, (void *) text, ulen + 1 );

/* Check the pointers can be used. */
   if( astOK ){

/* Terminate the local copy of the text string. */
      ltext[ ulen ] = 0;

/* Produce an upper-case copy of the first two characters in "just". */
      ljust[0] = (char) toupper( (int) just[0] );
      ljust[1] = (char) toupper( (int) just[1] );
      ljust[2] = 0;

/* Convert the double precision values to single precision, checking for
   bad positions. */
      if( ptr2[0][0] != AST__BAD && ptr2[1][0] != AST__BAD ){

/* Draw the text string. */
         astGText( ltext, (float) ptr2[0][0], (float) ptr2[1][0], ljust, 
                   up[ 0 ], up[ 1 ] );

/* ENABLE-ESCAPE - Replace the above call to astGText with the call to
   DrawText below when escape sequences are enabled.
         DrawText( this, astGetEscape( this ), ltext, (float) ptr2[0][0],
                   (float) ptr2[1][0], ljust, up[ 0 ], up[ 1 ], method, 
                   class );
*/
      }

/* Free the local copy of the string. */
      ltext = (char *) astFree( (void *) ltext );

   }

/* Annul the PointSets. */
   pset1 = astAnnul( pset1 );
   pset2 = astAnnul( pset2 );

/* Free the memory holding the pointers to the first value on each axis. */
   ptr1 = (const double **) astFree( (void *) ptr1 );

/* Re-establish the original graphical attributes. */
   GrfAttrs( this, TEXT_ID, 0, GRF__TEXT );

/* Return */
   return;
}

static void TextLabels( AstPlot *this, int edgeticks, int dounits[2],
                        const char *method, const char *class ){
/*
*
*  Name:
*     TextLabels

*  Purpose:
*     Draw textual labels round a grid.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void TextLabels( AstPlot *this, int edgeticks, int dounits[2],
*                      const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This function displays a textual label for each physical axis, and a 
*     title. The text strings are obtained from the Label and Title
*     attributes of the current Frame in the Plot.

*  Parameters:
*     this
*        A pointer to the Plot.
*     edgeticks
*        If tick marks and numerical labels were drawn around the edges
*        of the plotting area, this should be supplied as 1. Otherwise it 
*        should be supplied as zero.
*     dounits
*        Flags indicating if the axis Units string should be included in
*        the edge labels.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*/

/* Local Variables: */
   char *new_text;         /* Pointer to complete text string (inc. units) */
   char *just;             /* Pointer to axis label justification string */
   const char *text;       /* Pointer to text string to be displayed */
   const char *units;      /* Pointer to text string describing the units */
   double mindim;          /* Minimum dimension of plotting area */
   double xrange;          /* Width of plotting area */
   double yrange;          /* Height of plotting area */
   float txtgap;           /* Gap between bounding box and text string */
   float upx;              /* X component of text up-vector */
   float upy;              /* Y component of text up-vector */
   float xbn[ 4 ];         /* X coords at corners of new label's bounding box */
   float ybn[ 4 ];         /* Y coords at corners of new label's bounding box */
   float xref;             /* Graphics X coord. at text ref. position */
   float yref;             /* Graphics Y coord. at text ref. position */
   float xlo, xhi, ylo, yhi;/* The original bounding box (excluding labels) */
   int axis;               /* Axis index */
   int draw;               /* Should label be drawn? */
   int edge;               /* Edge to be labelled */
   int esc;                /* Interpret escape sequences? */
   int i;                  /* Corner index */
   int tlen;               /* No. of characetsr in label */
   int ulen;               /* No. of characetsr in units */

/* Check the global status. */
   if( !astOK ) return;

/* Get the minimum dimension of the plotting area. */
   xrange = this->xhi - this->xlo;
   yrange = this->yhi - this->ylo;
   mindim = MIN( xrange, yrange );

/* Establish the correct graphical attributes as defined by attributes
   with the supplied Plot. */
   GrfAttrs( this, TEXTLABS_ID, 1, GRF__TEXT );
   
/* Take a copy of the bounding box which encloses all other parts of the
   annotated grid. If nothing has been plotted, use an area 20 % smaller
   than the plotting area. */   
   if( Box_lbnd[ 0 ] != FLT_MAX ) {
      xlo = Box_lbnd[ 0 ];
      xhi = Box_ubnd[ 0 ];
      ylo = Box_lbnd[ 1 ];
      yhi = Box_ubnd[ 1 ];
   } else {
      xlo = this->xlo + 0.2*xrange;
      xhi = this->xhi - 0.2*xrange;
      ylo = this->ylo + 0.2*yrange;
      yhi = this->yhi - 0.2*yrange;
   }

/* See if escape sequences are to be interpreted within the labels. */
   esc = astGetEscape( this );

/* Now write a label for each physical axis. */
   for( axis = 0; axis < 2 && astOK; axis++ ){

/* See if the label is to be drawn. If an explicit value has not been set
   for the TextLab attribute, the default is to draw the label if tick
   marks were draw round the edge of the plotting area, and not to
   otherwise. */
      if( astTestTextLab( this, axis ) ){
         draw = astGetTextLab( this, axis );
      } else {
         draw = edgeticks;
      }

/* If so get the label. */
      if( draw ){
         text = astGetLabel( this, axis );
         tlen = ChrLen( text );

/* If required, get the units string and concatenate it with the label (inside 
   parenthesise). Ignore trailing spaces. */
         if( dounits[ axis ] ){
            units = astGetUnit( this, axis );
            if( units && units[0] ){
               ulen = ChrLen( units );
               new_text = astStore( NULL, (void *) text, tlen + ulen + 4 );
               
               text = new_text + tlen;

               memcpy( (void *) text, " (", 2 );
               text += 2;

               memcpy( (char *) text, units, ulen );
               text += ulen;

               memcpy( (char *) text, ")", 1 );
               text += 1;

               ( (char *) text )[0] = 0;

               text = new_text;

            } else {
               new_text = astStore( NULL, (void *) text, tlen + 1 );
               new_text[ tlen ] = 0;
               text = new_text;
               units = NULL;
            }

         } else {
            new_text = astStore( NULL, (void *) text, tlen + 1 );
            new_text[ tlen ] = 0;
            text = new_text;
            units = NULL;
         }

/* Get the gap between the edge of the bounding box and the closest edge
   of the text string. */
         txtgap = (float)( mindim*astGetTextLabGap( this, axis ) );

/* Get the edge to be labelled. Edge 0 is the left hand edge. Edge 1 is the 
   top edge. Edge 2 is the right-hand edge. Edge 3 is the bottom edge. */
         edge = astGetEdge( this, axis ) % 4;
         if( edge < 0 ) edge = -edge;

/* If the label is to be put on the left hand edge... */
         if( edge == 0 ){

/* Set the up vector so that the text is written from bottom to top. */
            upx = -1.0;
            upy = 0.0;

/* Justify the bottom of the bounding box. */
            just = "BC";

/* ENABLE-ESCAPE - replace the above assignment to "just" with the
   following assignment... */

/* Justify the bottom of the whole bounding box (not just the text
   base-line). */
/*            just = "DC"; */

/* Set the x reference position just outside the box enclosing all the
   graphics drawn so far. The reference point refers to the centre of the
   text string in both directions ("CC" justification). Take account of 
   whether or not the x axis is reversed. Do not allow the text to be 
   written outside the whole plotting surface. */
            if( this->xrev ){
               xref = xhi + txtgap;
            } else {
               xref = xlo - txtgap;
            }

/* The Y reference position is at the mid point vertically. */
            yref = 0.5*( MIN( yhi, this->yhi ) + 
                         MAX( ylo, this->ylo ) );

/* Do the same for the top edge. */
         } else if( edge == 1 ){
            upx = 0.0;
            upy = 1.0;
            just = "BC";
/* ENABLE-ESCAPE just = "DC"; */
            if( this->yrev ){
               yref = ylo - txtgap;
            } else {
               yref = yhi + txtgap;
            }
            xref = 0.5*( MIN( xhi, this->xhi ) + 
                         MAX( xlo, this->xlo ) );

/* Do the same for the right-hand edge. */
         } else if( edge == 2 ){
            upx = 1.0;
            upy = 0.0;
            just = "BC";
/* ENABLE-ESCAPE just = "DC"; */
            if( this->xrev ){
               xref = xlo - txtgap; 
            } else {
               xref = xhi + txtgap;
            }
            yref = 0.5*( MIN( yhi, this->yhi ) + 
                         MAX( ylo, this->ylo ) );

/* Do the same for the bottom edge. */
         } else {
            upx = 0.0;
            upy = 1.0;
            just = "TC";
/* ENABLE-ESCAPE just = "UC"; */
            if( this->yrev ){
               yref = yhi + txtgap;
            } else {
               yref = ylo - txtgap;
            }
            xref = 0.5*( MIN( xhi, this->xhi ) + 
                         MAX( xlo, this->xlo ) );
         }

/* Display the label. */
         astGText( text, xref, yref, just, upx, upy );

/* ENABLE-ESCAPE - Replace the above call to astGText with the call to
   DrawText below when escape sequences are enabled.
         DrawText( this, esc, text, xref, yref, just,
                   upx, upy, method, class );
*/

/* Get the bounds of the box containing the new label. */
         BoxText( this, esc, text, xref, yref, just, upx, upy, xbn, ybn,
                  method, class );

/* Extend the bounds of the global bounding box held externally to include 
   the new box. */
         if( astOK ){
            for( i = 0; i < 4; i++ ){
               Box_lbnd[ 0 ] = MIN( xbn[ i ], Box_lbnd[ 0 ] );
               Box_ubnd[ 0 ] = MAX( xbn[ i ], Box_ubnd[ 0 ] );
               Box_lbnd[ 1 ] = MIN( ybn[ i ], Box_lbnd[ 1 ] );
               Box_ubnd[ 1 ] = MAX( ybn[ i ], Box_ubnd[ 1 ] );
            }
         }

/* Release the memory allocated to store the axis label;. */
         new_text = (char *) astFree( (void *) new_text );
         text = NULL;

      }
   }

/* Re-establish the original graphical attributes. */
   GrfAttrs( this, TEXTLABS_ID, 0, GRF__TEXT );

/* See if the title is to be drawn. */
   if( astOK && astGetDrawTitle( this ) ){

/* If so get the title. */
      text = astGetTitle( this );

/* Create a copy from which trailing spaces have been removed. */
      tlen = ChrLen( text );
      new_text = (char *) astStore( NULL, (void *) text, tlen + 1 );
      new_text[ tlen ] = 0;
      text = new_text;
 
/* Establish the correct graphical attributes as defined by attributes
   with the supplied Plot. */
      GrfAttrs( this, TITLE_ID, 1, GRF__TEXT );

/* Take a copy of the bounding box which encloses all other parts of the
   annotated grid (this may have been extended by the above code). If 
   nothing has been plotted, use an area 20 % smaller than the plotting 
   area. */   
      if( Box_lbnd[ 0 ] != FLT_MAX ) {
         xlo = Box_lbnd[ 0 ];
         xhi = Box_ubnd[ 0 ];
         ylo = Box_lbnd[ 1 ];
         yhi = Box_ubnd[ 1 ];
      } else {
         xlo = this->xlo + 0.2*xrange;
         xhi = this->xhi - 0.2*xrange;
         ylo = this->ylo + 0.2*yrange;
         yhi = this->yhi - 0.2*yrange;
      }

/* Get the graphics coordinates of the bottom centre point of the title.
   The X centre is put at the mid point of the used x axis range
   (restricted to the range of the plotting area). */
      xref = 0.5*( MIN( xhi, this->xhi ) + 
                   MAX( xlo, this->xlo ) );

/* The Y centre is put a "TitleGap" distance outside the box containing
   the everything else. */
      if( this->yrev ){
         yref = ylo - (float)( mindim*astGetTitleGap( this ) );
      } else {
         yref = yhi + (float)( mindim*astGetTitleGap( this ) );
      }

/* Display the title. Justify the bottom of the whole bounding box (not 
   just the text base-line). */
      astGText( text, xref, yref, "BC", 0.0F, 1.0F );

/* ENABLE-ESCAPE - Replace the above call to astGText with the call to
   DrawText below when escape sequences are enabled.
      DrawText( this, esc, text, xref, yref, "DC", 0.0F, 1.0F,
                method, class );
*/

/* Re-establish the original graphical attributes. */
      GrfAttrs( this, TITLE_ID, 0, GRF__TEXT );

/* Release the memory allocated to store the title. */
      new_text = (char *) astFree( (void *) new_text );
      text = NULL;
   }

/* Return. */
   return;

}

static void Ticker( AstPlot *this, int edge, int axis, double value,
                    double *gap, double tklen, const char *method, 
                    const char *class ){
/*
*
*  Name:
*     Ticker

*  Purpose:
*     Draw edge tick marks for a given axis value.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void Ticker( AstPlot *this, int edge, int axis, double value,
*                  double *gap, double tklen, const char *method, 
*                  const char *class ){

*  Class Membership:
*     Plot member function.

*  Description:
*     This function draws tick marks at all occurences of a given
*     physical axis value on a given edge of the plotting area.

*  Parameters:
*     this
*        A pointer to the Plot.
*     edge
*        The edge of the plotting area to be ticked. Edge 0 is the left hand 
*        edge. Edge 1 is the top edge. Edge 2 is the right-hand edge. Edge 3 
*        is the bottom edge. 
*     axis
*        The index of the axis to which "value" refers. The tick mark extends 
*        parallel to this axis.
*     value
*        The physical axis value at which to place the tick mark. 
*     gap
*        Pointer to array of two values holding the gap between major
*        tick marks on the two axes.
*     tklen
*        The length of the tick, in graphics units.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*/

/* Local Variables: */
   double *cross;         /* Pointer to crossings information */
   double *vx;            /* Pointer to next X vector component value */
   double *vy;            /* Pointer to next Y vector component value */
   double *x;             /* Pointer to next X value */
   double *y;             /* Pointer to next Y value */
   int j;                 /* Crossing index */
   int ncross;            /* No. of crossings of tick value and edge */

/* Check the global status. */
   if( !astOK ) return;

/* See where the current major tick value crosses the edge. */
   ncross = EdgeCrossings( this, edge, axis, value, gap, &cross, method, 
                           class );

/* Do nothing if the supplied axis value does not occur on the specified
   edge of the plotting area. */
   if( ncross ){

/* Draw major tick marks at the crossings. */
      x = cross;
      y = cross + 1;
      vx = cross + 2;
      vy = cross + 3;

/* Draw a tick mark at each occurence of the axis value on the specified
   edge. */
      for( j = 0; j < ncross; j++ ){

/* Check the tick mark position and directionm are defined. */
         if( *vx != AST__BAD && *vy != AST__BAD &&
              *x != AST__BAD &&  *y != AST__BAD ){

/* Ensure the tick mark will point into the plotting area, no matter which 
   edge it is on. First ensure the direction vector refers to a system in
   which X increases to the left and Y increases upwards. */
            if( this->xrev ) *vx = -*vx;
            if( this->yrev ) *vy = -*vy;

/* If necessary reverse the vector so that it points into the plotting
   area. How to do this depends on which edge is being ticked. */
            if( ( edge == 0 && *vx < 0.0 ) ||   /* left-hand edge */
                ( edge == 1 && *vy > 0.0 ) ||   /* Top edge */
                ( edge == 2 && *vx > 0.0 ) ||   /* Right-hand edge */
                ( edge == 3 && *vy < 0.0 ) ){   /* Bottom edge */

               *vx = -*vx;
               *vy = -*vy;
            }

/* Now ensure the direction vector refers to a the native graphics system 
   taking account of any reversal of axes. */
            if( this->xrev ) *vx = -*vx;
            if( this->yrev ) *vy = -*vy;

/* Draw the tick mark as a straight line of the specified length. */
            Bpoly( (float) *x, (float) *y, method, class );
            Apoly( (float)( *x + tklen*(*vx) ), (float)( *y + tklen*(*vy) ), 
                   method, class );
            Opoly( method, class );
               
/* Move on to the next crossing. */
            x += 4;
            y += 4;
            vx += 4;
            vy += 4;
         }
      }
 
/* Free the memory holding the crossings. */
      if( cross ) cross = (double *) astFree( (void *) cross );

   }

/* Return. */
   return;

}

static TickInfo *TickMarks( AstPlot *this, int axis, double *cen, double *gap, 
                            int *inval, const char *method, const char *class ){
/*
*  Name:
*     TickMarks

*  Purpose:
*     Obtain a list of tick mark values and labels for a single axis in a 2-D 
*     physical coordinate Frame.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     TickInfo *TickMarks( AstPlot *this, int axis, double *cen, double *gap, 
*                          int *inval, const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     A set of tick marks values and corresponding formatted labels are 
*     found for an axis which result in all adjacent labels being different, 
*     but using the minimum number of digits of precision in the formatting.
*     This algorithm is over-ridden if the caller has set an explicit Format
*     string for the axis. The gap between tick marks can be specified by
*     the caller or a default value may be found automatically.

*  Parameters:
*     this
*        The Plot.
*     axis
*        The zero-based index of the axis to use.
*     cen
*        Pointer to the supplied axis value at which to put a single 
*        central tick. Other ticks will be placed evenly on either side of 
*        this tick. If AST__BAD is provided, a value will be used which 
*        would put a tick at an axis value of zero. The used value is
*        returned.
*     gap
*        The supplied values for the gaps between ticks on the axis. If
*        this is AST__BAD a suitable default value will be used and
*        returned in place of the AST__BAD value.
*     inval
*        A pointer to a location at which to return a flag indicating if
*        any invalid physical coordinates were encountered while deciding on 
*        the tick values.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     A pointer to a TickInfo structure holding information about the tick
*     marks (no. of major and minor ticks, the major tick mark values and
*     labels). This structure should be freed, together with its contents,
*     using astFree when it is no longer needed.

*  Notes:
*     -  The returned labels are NOT abbreviated to remove identical
*     leading fields.
*     -  This function allocates some static resources on its first
*     invocation, which should be released when no longer needed, or when
*     a different Plot is supplied, by calling this function with a NULL 
*     pointer for parameter "this". All other parameters are ignored.
*     -  This function assumes that the physical coordinate system is 2 
*     dimensional, and it should not be used if this is not the case.
*     -  An error is reported if the region containing valid physical
*     coordinates is too small to use.
*     -  If an error has already occurred, or if this function should fail 
*     for any reason, then a NULL pointer is returned.
*/

/* Local Variables: */
   AstAxis *ax;        /* Pointer to the axis. */
   AstFrame *frame;    /* Pointer to the current Frame in the Plot */
   TickInfo *ret;      /* Pointer to the returned structure. */
   char **labels;      /* Pointer to list of formatted labels */
   char **new;         /* Pointer to list of shortened formatted labels */
   const char *fmt;    /* Format string actually used */
   const char *old_format; /* Original Format string */
   double *ticks;      /* Pointer to major tick mark values */
   double cen0;        /* Supplied value of cen */
   double used_gap;    /* The gap size actually used */
   int axdigset;       /* Was the Axis Digits attribute set originally? */
   int frdigset;       /* Was the Frame Digits attribute set originally? */
   int dig_low;        /* The lowest value to use for Digits */
   int digits;         /* New Digits value */
   int i;              /* Tick index. */
   int nmajor;         /* No. of major tick marks */
   int nminor;         /* No. of minor tick marks */
   int ok;             /* Are all adjacent labels different? */
   int old_digits;     /* Original Digits value (-1 if not set) */
   int req_digits;     /* Original Digits value (default value if not set) */
   int bot_digits;     /* Digits value which makes labels as short as possible */
   int top_digits;     /* Digits value needed to make all labels different */

/* If a NULL pointer has been supplied for "this", release the resources
   allocated within GetTicks, and return. */
   if( !this ){
      (void) GetTicks( NULL, 0, NULL, 0.0, &ticks, &nmajor, &nminor, 
                       0, inval, method, class );
      return NULL;
   }      

/* Check the global status. */
   if( !astOK ) return NULL;

/* Initialise the returned pointer. */
   ret = NULL;

/* Store the supplied value of cen. */
   cen0 = cen ? *cen : AST__BAD ;

/* Get a pointer to the current Frame from the Plot. */
   frame = astGetFrame( this, AST__CURRENT );

/* Initialise a flag to indicate that all adjacent labels are different. */
   ok = 0;

/* Initialise the pointer to the list of formatted tick mark values to
   indicate that no memory has yet been obtained. */
   labels = NULL;

/* Get a pointer to the axis. */
   ax = astGetAxis( frame, axis );

/* See if a value has been set for the axis Digits. */
   axdigset = astTestAxisDigits( ax );

/* See if a value has been set for the Frame Digits. */
   frdigset = astTestDigits( frame );

/* If the axis Format string or Digits value, or the Frame Digits value, is 
   set, we should attempt to use them, so that the user's attempts to get a 
   specific result are not foiled. */
   if( astTestFormat( frame, axis ) || axdigset || frdigset ){

/* Get a set of tick mark values. */
      used_gap = GetTicks( this, axis, cen, *gap, &ticks, &nmajor, &nminor, 1, 
                           inval, method, class );

/* Reserve memory to hold pointers to the formatted labels. */
      labels = (char **) astMalloc( sizeof(char *)*(size_t)nmajor );

/* See if there are any adjacent labels which are identical. If there are
   not, the labels are formatted and returned in "labels". */
      fmt = astGetFormat( frame, axis );
      ok = CheckLabels( frame, axis, ticks, nmajor, labels );

   }

/* If no Format has been set for the Frame, or if the set Format results in
   some adjacent labels being identical, we need to find a Format which
   gives different labels, but without using any more digits than
   necessary. */
   if( !ok ){

/* Save a copy of the Frame's Format value, if set, and then clear it so
   that the Digits value will be used to determine the default format. */
      if( astTestFormat( frame, axis ) ) {
         old_format = astGetFormat( frame, axis );
         astClearFormat( frame, axis );
      } else {
         old_format = NULL;
      }

/* If a value has been set for the axis Digits or the Frame Digits, get it. 
   Otherwise set the value to -1. */
      if( axdigset ) {
         req_digits = astGetAxisDigits( ax );
         old_digits = req_digits;
         dig_low = req_digits;

      } else if( frdigset ) {
         req_digits = astGetDigits( frame );
         dig_low = req_digits;

      } else {
         req_digits = astGetDigits( frame );
         dig_low = 1;
      }

/* Loop round increasing the number of digits in the formatted labels
   until all adjacent labels are different. An arbitrary upper limit of 
   1000 is used for Digits to stop it looping for ever. */    
      for( digits = req_digits; digits < 1000; digits++ ){

/* Store the new Digits value. */
         astSetAxisDigits( ax, digits );
         
/* Get a set of tick mark values. */
         if( cen ) *cen = cen0;
         used_gap = GetTicks( this, axis, cen, *gap, &ticks, &nmajor, &nminor,
                              0, inval, method, class );

/* Expand the memory holding the pointers to the formatted labels. */
         labels = (char **) astGrow( labels, nmajor, sizeof(char *) );

/* Break out of the loop if a Digits value has been found which results
   in all adjacent labels being different. */
         fmt = astGetFormat( frame, axis );
         if( CheckLabels( frame, axis, ticks, nmajor, labels ) ) {
            ok = 1;
            top_digits = digits;
            break;
         }
      }

/* Top_digits gives the precision required to make all labels distinct, but is 
   limited to be never less than the Digits value for the axis. This
   value may be too high (i.e. we may be able to reduce digits and *still*
   have distinct labels). We enter a loop in which digits is reduced by
   one each time. On each pass, the labels are compared with the previous
   set of labels. The loop is left when reducing the number of digits
   causes any of the labels to increase in length (as can happen for
   instance if printf decides to include an exponent in the label). We do 
   this to find the shortest labels which can be used to describe each
   tick value. */
      if( ok ){
         ok = 0;
         for( digits = top_digits - 1; digits > 0; digits-- ){
            astSetAxisDigits( ax, digits );

/* CheckLabels2 formats the labels with the decreased number of digits,
   and compares them with the old labels in "labels". If all the new labels
   are longer than the corresponding old labels, then a null pointer is
   returned. Otherwise, a pointer is returned to the new set of labels. */
            fmt = astGetFormat( frame, axis );
            new = CheckLabels2( frame, axis, ticks, nmajor, labels );

/* Free the old labels. */
            for( i = 0; i < nmajor; i++ ){
               if( labels[ i ] ) labels[ i ] = (char *) astFree( (void *) labels[ i ] );
            }
            labels = (char **) astFree( (void *) labels );

/* If any of the labels got longer as a result of reducing the digits
   value, then use the previous number of digits. Break out of the loop. */
            if( !new ) {
               bot_digits = digits + 1;
               ok = 1;
               break;
            }

/* Use the shorter labels from now on. */
            labels = new;

/* If the user requested more digits, then honour the request by exiting
   this loop (free the new labels first). */
            if( digits <= dig_low ) {
               bot_digits = dig_low; 
               ok = 1;

               for( i = 0; i < nmajor; i++ ){
                  if( new[ i ] ) new[ i ] = (char *) astFree( (void *) new[ i ] );
               }
               new = (char **) astFree( (void *) new );

               break;
            }
         }
      }

/* The above loop may have reduced the digits value too much so that
   adjacent labels are indistinct. Go through another loop increasing the
   digits until all adjacent labels are again distinct, and then get
   the used format and leave the loop. */
      if( ok ) {
         ok = 0;
         labels = (char **) astMalloc( sizeof(char *)*(size_t) nmajor );
         if( labels ) {
            for( digits = bot_digits; digits < 1000; digits++ ){
               astSetAxisDigits( ax, digits );
               fmt = astGetFormat( frame, axis );
               if( CheckLabels( frame, axis, ticks, nmajor, labels ) ) {
                  ok = 1;
                  break;
               }
            }
         }
      }

/* Clear the Digits and Format values. */
      astClearAxisDigits( ax );
      astClearAxisFormat( ax );
   
/* Restore the original axis Format and Digits values, if set. */
      if( old_format ) astSetAxisFormat( ax, old_format );
      if( axdigset ) astSetAxisDigits( ax, old_digits );

   }

/* Annul the pointer to the Axis. */
   ax = astAnnul( ax );

/* If suitable labels were found... */
   if( ok ) {

/* Store the used gap size. */
      *gap = used_gap;

/* If the caller has specified the number of minor tick marks to use,
   use the specified value rather than the value found above. */
      if( astTestMinTick( this, axis ) ){
         nminor = astGetMinTick( this, axis );
      }

/* Allocate memory for the returned structure. */
      ret = (TickInfo *) astMalloc( sizeof( TickInfo ) );

/* If the pointer can be used, store the information. */
      if( astOK ){
         ret->nmajor = nmajor;
         ret->nminor = nminor;
         ret->ticks = ticks;
         ret->labels = labels;
         ret->fmt = (char *) astStore( NULL, (void *) fmt, strlen( fmt ) + 1 );
         ret->start = NULL;
         ret->length = NULL;
         ret->nsect = 0;
      }

/* If no suitable labels were found report an error. */
   } else if( astOK ){
      if( astTestFormat( frame, axis ) ){
         astError( AST__PLFMT, "%s(%s): No numerical labels can be produced "
                   "for axis %d using the supplied %s format string '%s'.",
                   method, class, axis + 1, astGetClass( frame ), 
                   astGetFormat( frame, axis ) );
      } else {      
         astError( AST__PLFMT, "%s(%s): No suitable format can be found to "
                   "produce numerical labels for axis %d of a %s.",
                   method, class, axis + 1, astGetClass( frame ) );
      }
   }

/* Release the pointer to the current Frame from the Plot. */
   frame = astAnnul( frame );

/* If an error has occurred, release the returned information. */
   if( !astOK ){
      ticks = (double *) astFree( (void *) ticks );
      if( labels ){
         for( i = 0; i < nmajor; i++ ) {
            labels[ i ] = (char *) astFree( (void *) labels[ i ] );
         }
         labels = (char **) astFree( (void *) labels );
         if( ret ) (void ) astFree( (void *) ret->fmt );
      }
      ret = (TickInfo *) astFree( (void *) ret );
   }

/* Return the structure. */
   return ret;

}

static void TraceBorder( double **ptr1, double **ptr2, int dim, int *edge,
                         const char *method, const char *class ){
/*
*  Name:
*     TraceBorder

*  Purpose:
*     Trace the boundary between good and bad physical coordinates through a 
*     fine grid.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     void TraceBorder( double **ptr1, double **ptr2, int dim, int *edge,
*                      const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     Each edge cell of the fine grid is checked until a cell is found 
*     through which the good/bad boundary passes (as shown by a mixture of 
*     bad and good physical coordinates at the four cell corners). The boundary
*     is then traced away from the grid edge outwards from this starting cell.
*     For each cell, the next cell along the curve is identified by 
*     looking for two adjacent cell corners with differing validity (i.e.
*     one has good physical coordinates and the other has not). The curve
*     is assumed to leave the current cell at the mid point between these
*     two adjacent cell corners, and to pass on into the neighbouring cell.
*     The polyline is continued in this way until the edge of the fine grid
*     is reached.

*  Parameters:
*     ptr1
*        A pointer to an array of two pointers, giving the arrays
*        holding the graphics coordinates at each point in the grid, row
*        by row, starting at the bottom left corner. 
*     ptr2
*        A pointer to an array of two pointers, giving the arrays
*        holding the physical coordinates at each point in the grid, row
*        by row, starting at the bottom left corner. 
*     dim
*        The number of points along one edge of the fine grid.
*     edge
*        A pointer to an array of 4 values, in which will be returned
*        flags indicating if the good/bad boundary intersects any of the 
*        edges of the grid. These flags are stored in the order bottom, 
*        right-hand, top, left-hand.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*/

/* Local Variables: */
   double *gx[ 4 ];   /* Pointers to graphics x coords at cell corners */
   double *gy[ 4 ];   /* Pointers to graphics y coords at cell corners */
   double *px[ 4 ];   /* Pointers to physical x coords at cell corners */
   double x0;         /* X graphics coord at crossing in starting cell */
   double y0;         /* Y graphics coord at crossing in starting cell */
   int bad;           /* Is the current cell corner bad? */
   int ca;            /* Index of corner at anticlockwise end of edge */
   int cb;            /* Index of corner at clockwise end of edge */
   int ed0;           /* Edge of the starting cell crossed by the boundary */
   int ed;            /* Edge through which curve leaves current cell */
   int i0;            /* Column index of starting cell */
   int i;             /* Column index */
   int j0;            /* Row index of starting cell */
   int j;             /* Row index */
   int k;             /* Various uses */
   int lbad;          /* Was the previous cell corner bad? */
   int lost;          /* Has the curve been lost? */
   int ncell;         /* No. of cells in the fine grid */
   int test_edge;     /* Edge to test for a crossing */

/* Check the global error status. */
   if ( !astOK ) return;

/* Initialise the returned flags to indicate that the good/bad boundary
   does not intersect any of the edges. */
   edge[ 0 ] = 0;
   edge[ 1 ] = 0;
   edge[ 2 ] = 0;
   edge[ 3 ] = 0;

/* Store the number of cells in the grid. */
   ncell = dim - 1;

/* We first find a cell (the "starting cell") through which the boundary 
   passes. Set a flag indicating that no such cell has yet been found. */
   ed0 = -1;

/* We scan each edge of the grid in turn looking for the starting cell. First 
   do the bottom edge (edge 0). Store pointers to the graphics and physical 
   coordinates at the bottom two corners of the first cell in the bottom row. 
   The corners are: 0=bottom left, 1=bottom right, 2=top right, 3=top left. */
   gx[ 0 ] = ptr1[ 0 ];
   gy[ 0 ] = ptr1[ 1 ];
   px[ 0 ] = ptr2[ 0 ];

   gx[ 1 ] = gx[ 0 ] + 1;
   gy[ 1 ] = gy[ 0 ] + 1;
   px[ 1 ] = px[ 0 ] + 1;

/* See if the bottom left corner of the current cell is bad. */
   bad = ( *( px[ 0 ] ) == AST__BAD );

/* Loop round each cell in the bottom row. */
   for( i = 0; i < ncell; i++ ){

/* See if the bottom left and right corners of the current cell are bad. 
   The bottom right corner of the previous cell becomes the bottom left
   corner of the current cell. */
      lbad = bad;
      bad = ( *( px[ 1 ] ) == AST__BAD );

/* If one corner is bad and the other is not bad, the good/bad boundary 
   crosses the edge. We assume it passes half way between them, so record a 
   crossing at the mid point between them, and break out of the loop. */
      if( lbad != bad ){
         i0 = i;
         j0 = 0;
         ed0 = 0;
         x0 = 0.5*( *( gx[ 0 ] ) + *( gx[ 1 ] ) );
         y0 = 0.5*( *( gy[ 0 ] ) + *( gy[ 1 ] ) );
         edge[ 0 ] = 1;
         break;
      }

/* Update the pointers to the corner coordinates so that they refer to 
   the next cell in this row. */
      gx[ 0 ]++;
      gy[ 0 ]++;
      px[ 0 ]++;

      gx[ 1 ]++;
      gy[ 1 ]++;

   }

/* If no crossing was found on the bottom edge of the grid, do the top
   edge in the same way. */ 
   if( ed0 == -1 ){

/* Store pointers to the graphics and physical coordinates at the top two 
   corners of the first cell in the top row. */
      k = ncell*dim + 1;
      gx[ 2 ] = ptr1[ 0 ] + k;
      gy[ 2 ] = ptr1[ 1 ] + k;
      px[ 2 ] = ptr2[ 0 ] + k;

      gx[ 3 ] = gx[ 2 ] - 1;
      gy[ 3 ] = gy[ 2 ] - 1;
      px[ 3 ] = px[ 2 ] - 1;

/* See if the top left corner of the current cell is bad. */
      bad = ( *( px[ 3 ] ) == AST__BAD );

/* Loop round each cell in the top row. */
      for( i = 0; i < ncell; i++ ){

/* See if the top left and right corners of the current cell are bad. 
   The top right corner of the previous cell becomes the top left
   corner of the current cell. */
         lbad = bad;
         bad = ( *( px[ 2 ] ) == AST__BAD );

/* If one corner is bad and the other is not bad, the good/bad boundary 
   crosses the edge. We assume it passes half way between them, so record a 
   crossing at the mid point between them, and break out of the loop. */
         if( lbad != bad ){
            i0 = i;
            j0 = ncell - 1;
            ed0 = 2;
            x0 = 0.5*( *( gx[ 2 ] ) + *( gx[ 3 ] ) );
            y0 = 0.5*( *( gy[ 2 ] ) + *( gy[ 3 ] ) );
            edge[ 2 ] = 1;
            break;
         }

/* Update the pointers to the corner coordinates so that they refer to 
   the next cell in this row. */
         gx[ 2 ]++;
         gy[ 2 ]++;
         px[ 2 ]++;
   
         gx[ 3 ]++;
         gy[ 3 ]++;

      }
   }

/* If no crossing has yet been found, do the left edge in the same way. */ 
   if( ed0 == -1 ){

/* Store pointers to the graphics and physical coordinates at the left two 
   corners of the first cell in the bottom row. */
      gx[ 0 ] = ptr1[ 0 ];
      gy[ 0 ] = ptr1[ 1 ];
      px[ 0 ] = ptr2[ 0 ];

      gx[ 3 ] = gx[ 0 ] + dim;
      gy[ 3 ] = gy[ 0 ] + dim;
      px[ 3 ] = px[ 0 ] + dim;

/* See if the bottom left corner of the bottom left cell is bad. */
      bad = ( *( px[ 0 ] ) == AST__BAD );

/* Loop round each row in the left hand column. */
      for( j = 0; j < ncell; j++ ){

/* See if the two left corners of the current cell are bad. The top left 
   corner of the previous cell becomes the bottom left corner of the current 
   cell. */
         lbad = bad;
         bad = ( *( px[ 3 ] ) == AST__BAD );

/* If one corner is bad and the other is not bad, the good/bad boundary 
   crosses the edge. We assume it passes half way between them, so record a 
   crossing at the mid point between them, and break out of the loop. */
         if( lbad != bad ){
            i0 = 0;
            j0 = j;
            ed0 = 3;
            x0 = 0.5*( *( gx[ 0 ] ) + *( gx[ 3 ] ) );
            y0 = 0.5*( *( gy[ 0 ] ) + *( gy[ 3 ] ) );
            edge[ 3 ] = 1;
            break;
         }

/* Update the pointers to the corner coordinates so that they refer to 
   the next cell in this row. */
         gx[ 0 ] += dim;
         gy[ 0 ] += dim;
   
         gx[ 3 ] += dim;
         gy[ 3 ] += dim;
         px[ 3 ] += dim;

      }
   }

/* If no crossing has yet been found, do the right edge in the same way. */ 
   if( ed0 == -1 ){

/* Store pointers to the graphics and physical coordinates at the right two 
   corners of the last cell in the bottom row. */
      gx[ 1 ] = ptr1[ 0 ] + ncell;
      gy[ 1 ] = ptr1[ 1 ] + ncell;
      px[ 1 ] = ptr2[ 0 ] + ncell;

      gx[ 2 ] = gx[ 1 ] + dim;
      gy[ 2 ] = gy[ 1 ] + dim;
      px[ 2 ] = px[ 1 ] + dim;

/* See if the bottom right corner of the bottom right cell is bad. */
      bad = ( *( px[ 1 ] ) == AST__BAD );

/* Loop round each row in the right hand column. */
      for( j = 0; j < ncell; j++ ){

/* See if the two right corners of the current cell are bad. The top right
   corner of the previous cell becomes the bottom right corner of the current 
   cell. */
         lbad = bad;
         bad = ( *( px[ 2 ] ) == AST__BAD );

/* If one corner is bad and the other is not bad, the good/bad boundary 
   crosses the edge. We assume it passes half way between them, so record a 
   crossing at the mid point between them, and break out of the loop. */
         if( lbad != bad ){
            i0 = ncell - 1;
            j0 = j;
            ed0 = 1;
            x0 = 0.5*( *( gx[ 1 ] ) + *( gx[ 2 ] ) );
            y0 = 0.5*( *( gy[ 1 ] ) + *( gy[ 2 ] ) );
            edge[ 1 ] = 1;
            break;
         }

/* Update the pointers to the corner coordinates so that they refer to 
   the next cell in this row. */
         gx[ 1 ] += dim;
         gy[ 1 ] += dim;
   
         gx[ 2 ] += dim;
         gy[ 2 ] += dim;
         px[ 2 ] += dim;

      }
   }

/* If we have found a starting cell we trace the curve out in both directions 
   from it. */
   if( ed0 != -1 ){

/* Start the polyline at the recorded edge crossing. */
      Bpoly( (float) x0, (float) y0, method, class );

/* Initialise the row and column of the starting cell, and the edge
   through which the curve enters the starting cell. */
      i = i0;
      j = j0;
      ed = ed0;

/* We now follow the curve until it crosses one of the edges of the grid, or 
   is lost. */
      lost = 0;
      while( !lost ){

/* Store pointers to the graphics and physical coordinates at the four corners 
   of the current cell. */
         k = j*dim + i;
         gx[ 0 ] = ptr1[ 0 ] + k;
         gy[ 0 ] = ptr1[ 1 ] + k; 
         px[ 0 ] = ptr2[ 0 ] + k;
       
         px[ 1 ] = px[ 0 ] + 1;
         gx[ 1 ] = gx[ 0 ] + 1;
         gy[ 1 ] = gy[ 0 ] + 1;
       
         px[ 2 ] = px[ 1 ] + dim;
         gx[ 2 ] = gx[ 1 ] + dim;
         gy[ 2 ] = gy[ 1 ] + dim;
       
         px[ 3 ] = px[ 2 ] - 1;
         gx[ 3 ] = gx[ 2 ] - 1;
         gy[ 3 ] = gy[ 2 ] - 1;

/* Check each edge of the current cell to see if the boundary crosses it. */
         lost = 1;
         bad = ( *( px[ 0 ] ) == AST__BAD );
         for( test_edge = 0; test_edge < 4; test_edge++ ){

/* Get the index of the corner at the anti-clockwise end of the edge. */
            if( test_edge == 3 ) {
               ca = 0;
            } else {
               ca = test_edge + 1;
            }

/* Get the index of the corner at the clockwise end of the edge. */
            cb = test_edge;

/* Get flags indicating if the corners at the two ends of the edge are bad. */
            lbad = bad;
            bad = ( *( px[ ca ]  )== AST__BAD );

/* If one is and one is not, the good/bad boundary crosses the edge (we
   ignore the edge through which the curve entered the cell). Add a section 
   to the polyline which ends at the mid point of the edge. */
            if( lbad != bad && test_edge != ed ){
               Apoly( (float) ( 0.5*( *( gx[ ca ] ) + *( gx[ cb ] ) ) ),
                      (float) ( 0.5*( *( gy[ ca ] ) + *( gy[ cb ] ) ) ),
                      method, class );

/* Indicate that the curve has not been lost, save the index of the edge 
   through which the curve leaves the cell, and leave the loop. */
               lost = 0;
               ed = test_edge;
               break;
            }

         }

/* If the current cell is on the bottom row, and the curve has passed out
   through the bottom edge, set the edge's flag and leave the loop. */
         if( j == 0 && ed == 0 ){
            edge[ 0 ] = 1;
            break;

/* Otherwise, if the current cell is on the right hand edge of the grid,
   and the curve passes through the right hand edge of the cell, set the
   edge's flag and leave the loop. */
         } else if( i == ( ncell - 1 ) && ed == 1 ){
            edge[ 1 ] = 1;
            break;

/* Otherwise, if the current cell is on the top edge of the grid,
   and the curve passes through the top edge of the cell, set the
   edge's flag and leave the loop. */
         } else if( j == ( ncell - 1 ) && ed == 2 ){
            edge[ 2 ] = 1;
            break;

/* Otherwise, if the current cell is on the left hand edge of the grid,
   and the curve passes through the left hand edge of the cell, set the
   edge's flag and leave the loop. */
         } else if( i == 0 && ed == 3 ){
            edge[ 3 ] = 1;
            break;

/* Otherwise, find the row and column numbers of the cell into which the curve
   passes. Also, modify the edge number so that it refers to the new cell. */
         } else {

            if( ed == 0 ){
               j--;
               ed = 2;
            } else if( ed == 1 ){
               i++;
               ed = 3;
            } else if( ed == 2 ){
               j++;
               ed = 0;
            } else {
               i--;
               ed = 1;
            }              

         }

      }

/* We have now reached the edge of the grid, or the curve has been lost.
   In either case end the poly line. */
      Opoly( method, class );

   }

/* Return. */
   return;

}

static AstPointSet *Trans( AstPlot *this, AstFrame *frm, AstMapping *mapping, 
                           AstPointSet *in, int forward, AstPointSet *out, 
                           int norm, const char *method, const char *class ) {
/*
*  Name:
*     Trans

*  Purpose:
*     Use a Mapping to transform a set of points.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     AstPointSet *Trans( AstPlot *this, AstFrame *frm, AstMapping *mapping, 
*                         AstPointSet *in, int forward, AstPointSet *out,
*                         int norm, const char *method, const char *class )

*  Class Membership:
*     Plot member function.

*  Description:
*     This performs the same task as the protected method astTransform
*     but uses the astTransform method for the supplied Mapping instead 
*     the parent method for the Plot. This allows the Mapping to be
*     extracted from the Plot using astGetMapping once, rather than every 
*     time a mapping is performed.

*  Parameters:
*     this
*        Pointer to the Plot (only used to access clipping attributes and
*        other methods).
*     frm
*        Pointer to the Current Frame in the Plot. If this is NULL, then
*        a pointer for the Current Frame is found within this function if
*        required (i.e. if "forward" and "norm" are both non-zero).
*     mapping
*        Pointer to the Mapping extracted from the Plot.
*     in
*        Pointer to the PointSet holding the input coordinate data.
*     forward
*        A non-zero value indicates that the forward coordinate 
*        transformation should be applied while a zero value requests the 
*        inverse transformation.
*     out
*        Pointer to a PointSet which will hold the transformed (output)
*        coordinate values. A NULL value may also be given, in which case a
*        new PointSet will be created by this function.
*     norm
*        The normalisation of returned physical coordinates is only done
*        if "norm" is non-zero. Otherwise they are left as returned by
*        astTransform.
*     method
*        Pointer to a string holding the name of the calling method.
*        This is only for use in constructing error messages.
*     class 
*        Pointer to a string holding the name of the supplied object class.
*        This is only for use in constructing error messages.

*  Returned Value:
*     Pointer to the output (possibly new) PointSet.

*  Notes:
*     -  Clipping is only performed as set up using the astClip method. 
*     In particular, the clipping specified by the arguments to the astPlot
*     constructor function is NOT performed. This is done in order to improve
*     the efficiency of the curve drawing method astGridLine.
*     -  A null pointer will be returned if this function is invoked with the
*     global error status set, or if it should fail for any reason.
*     -  The number of coordinate values per point in the input PointSet must
*     match the number of coordinates for the Plot being applied.
*     -  If an output PointSet is supplied, it must have space for sufficient
*     number of points and coordinate values per point to accommodate the
*     result. Any excess space will be ignored.
*/

/* Local Variables: */
   AstFrame *cfr;                /* Pointer to the Current Frame */
   AstFrame *fr;                 /* Pointer to the clipping Frame */
   AstMapping *map;              /* Pointer to output->clip mapping */
   AstPointSet *clip;            /* Positions in clipping Frame */
   AstPointSet *result;          /* Positions in output Frame */
   double **ptr_clip;            /* Pointer to clipping Frame data */
   double **ptr_out;             /* Pointer to output coordinate data */
   double *work;                 /* Pointer to array holding an o/p position */
   double axval;                 /* Axis value in clipping frame */
   double lbnd;                  /* Lower bound on current clipping axis */
   double ubnd;                  /* Upper bound on current clipping axis */
   int axin;                     /* Is the axis value within the allowed range? */
   int clip_norm;                /* Normalise the clipping positions? */
   int clip_or;                  /* Combine axes using a logical OR? */
   int clipit;                   /* Should the current point be clipped? */
   int i;                        /* Point index */
   int iframe;                   /* Validated index for clipping Frame */
   int j;                        /* Axis index */
   int naxes;                    /* Number of axes in clipping Frame */
   int ncoord_out;               /* Number of coordinates per output point */
   int npoint;                   /* Number of points */

/* Check the global error status. */
   if ( !astOK ) return NULL;

/* Apply the parent mapping using the stored pointer to the Transform member
   function inherited from the parent FrameSet class. */
   result = astTransform( mapping, in, forward, out );

/* Get the dimensions of the returned data, and an array of pointers to 
   the axis values. */
   ncoord_out = astGetNcoord( result );
   npoint = astGetNpoint( result );
   ptr_out = astGetPoints( result );

/* If we have done a forward mapping, we now normalise the returned physical 
   positions if required using the astNorm method for the supplied object. */
   if( forward && norm ){

/* If no Frame was supplied, get a pointer to the Current Frame. Otherwise,
   use the supplied pointer. */
      if( !frm ) {
         cfr = astGetFrame( this, AST__CURRENT );
      } else {
         cfr = frm;
      }      

/* Get work space to hold a single positions. */
      work = (double *) astMalloc( sizeof(double)*(size_t)ncoord_out );

/* Check the work space and axis pointers can be used. */
      if( astOK ){

/* Now loop through every position, copying the axis values to the work array, 
   normalising them using astNorm, and copying them back to the returned 
   PointSet. */
         for( i = 0; i < npoint; i++ ){
            for( j = 0; j < ncoord_out; j++ ) work[ j ] = ptr_out[ j ][ i ];
            astNorm( cfr, work );
            for( j = 0; j < ncoord_out; j++ ) ptr_out[ j ][ i ] = work[ j ];
         }
      }
      
/* Free the work space. */
      work = (double *) astFree( (void *) work );

/* Annul the pointer to the Current Frame if it was obtained in this
   function. */
      if( !frm ) cfr = astAnnul( cfr );

   }

/* Clipping is only performed if the bounds of a clipping region are
   available for both axes. */
   if( this->clip_lbnd && this->clip_ubnd ){

/* Validate and translate the index of the clipping Frame. */
      iframe = astValidateFrameIndex( this, this->clip_frame, method );

/* Obtain a pointer to the clipping Frame and determine how many axes it
   has. */ 
      fr = astGetFrame( this, iframe );
      naxes = astGetNaxes( fr );

/* Report an error if the number of bounds does not equal the number of
   axes in the clipping Frame. */
      if( astOK && naxes != this->clip_axes ){
         astError( AST__CLPAX, "%s%s): The supplied %s specifies clipping "
                   "in %d dimensions, but the clipping Frame ('%s') has "
                   "%d axes.", method, class, class, this->clip_axes, 
                   astGetTitle( fr ), naxes );
      }

/* Set a flag indicating if the coordinates in the clipping frame need to
   be normalised. */
      clip_norm = 1;

/* We now obtain a pointer to a PointSet holding the corresponding
   coordinates in the clipping frame.  If the clipping frame is the
   base frame, then take a clone of the PointSet holding base frame 
   coordinates. */
      if( iframe == astGetBase( this ) ){
         if( forward ){
            clip = astClone( in );
         } else {
            clip = astClone( result );
         }

/* If the clipping frame is the current frame, then take a clone of the 
   PointSet holding current coordinates. Note, if the returned physical
   coordinates have already been normalised, we don't need to normalise
   the clipping coordinates. */
      } else if( iframe == astGetCurrent( this ) ){
         if( forward ){
            clip = astClone( result );
            if( norm ) clip_norm = 0;
         } else {
            clip = astClone( in );
         }

/* If the clipping Frame is neither the base nor the current Frame, we need
   to map the returned normalised points into the clipping Frame. */
      } else {
         if( forward ){
            map = astGetMapping( this, AST__CURRENT, iframe );
         } else {
            map = astGetMapping( this, AST__BASE, iframe );
         }
         clip = astTransform( map, in, 1, NULL );
         map = astAnnul( map );
       }

/* Get a pointer to the coordinate data in the clipping Frame. */ 
      ptr_clip = astGetPoints( clip );

/* If necessary, normalise the coordinates in the clipping frame. */
      if( clip_norm ){

/* Get work space to hold a single position. */
         work = (double *) astMalloc( sizeof(double)*(size_t)naxes );

/* Check the work space and axis pointers can be used. */
         if( astOK ){

/* Now loop through every position, copying the axis values to the work array, 
   normalising them using astNorm, and copying them back to the clipping
   PointSet. */
            for( i = 0; i < npoint; i++ ){
               for( j = 0; j < naxes; j++ ) work[ j ] = ptr_clip[ j ][ i ];
               astNorm( fr, work );
               for( j = 0; j < naxes; j++ ) ptr_clip[ j ][ i ] = work[ j ];
            }
         }
      
/* Free the work space. */
         work = (double *) astFree( (void *) work );

      }

/* If all has gone ok, we will now clip the returned points. */
      if( astOK ){

/* Get the logical operation to be used to determine if a point is to be
   clipped. A zero value means that a logical AND is to be performed
   between the axes (i.e. all axes must be within the supplied bounds for a 
   point to be retained). A non-zero value means that a logical OR is to be 
   performed between the axes (i.e. only a single axis need be within the 
   supplied bounds for a point to be retained). */
         clip_or = astGetClipOp( this );

/* Do each point in turn. */
         for( j = 0; j < npoint; j++ ){

/* If all axes must fall within the supplied range to avoid the point being 
   clipped (i.e. if clip_or is 0), then assume initially that the point 
   is not to be clipped. This will be toggled as soon as the first 
   out-of-bounds point is found. If, on the other hand, the point is
   only clipped if all axis values are out-of-bounds, then assume
   initially that the point is to be clipped. This will be toggled as
   soon as the first axis value is found which is not out-of-bounds. */
            clipit = clip_or;

/* Check each axis value for the current point. */
            for( i = 0; i < naxes; i++ ){
               axval =  ptr_clip[ i ][ j ];

/* Chekc that it is not bad. */
               if( axval != AST__BAD ){

/* Store the bounds of the clipping volume on this axis. */
                  lbnd = this->clip_lbnd[ i ];
                  ubnd = this->clip_ubnd[ i ];

/* Set a flag indicating if the axis value is within the specified range.
   If the supplied bounds are reversed, they specify the range to exclude,
   otherwise they specify the range to include.  */
                  if( lbnd <= ubnd ){
                     axin = ( axval >= lbnd && axval <= ubnd );
                  } else {
                     axin = ( axval < ubnd || axval > lbnd );
                  }   
   
/* If the point is within the range and only one such point is
   required to avoid the point being clipped, indicate that the point
   should not be clipped, and leave the loop. */
                  if( axin && clip_or ){ 
                     clipit = 0;
                     break;

/* If the point is not within the range and we only one such point is
   required to cause the point to be clipped, indicate that the point
   should be clipped, and leave the loop. */
                  } else if( !axin && !clip_or ){
                     clipit = 1;
                     break;
                  }

/* Clip the point if any axis value is bad in the clipping Frame. */      
               } else {
                  clipit = 1;
                  break;
               }

            }

/* If the point is to be clipped, set all returned axis values bad. */
            if( clipit ) {
               for( i = 0; i < naxes; i++ ) ptr_out[ i ][ j ] = AST__BAD;
            }

         }

      }

/* Annul the PointSet holding clipping Frame positions. */
      if( clip ) clip = astAnnul( clip );

/* Annul the clipping Frame pointer. */
      fr = astAnnul( fr );

    }

/* If an error has occurred, annul the result. */
   if( !astOK ) result = astAnnul( result );

/* Return a pointer to the output PointSet. */
   return result;

}

static AstPointSet *Transform( AstMapping *this, AstPointSet *in,
                               int forward, AstPointSet *out ) {
/*
*  Name:
*     Transform

*  Purpose:
*     Use a Plot to transform a set of points.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     AstPointSet *Transform( AstMapping *this, AstPointSet *in,
*                             int forward, AstPointSet *out )

*  Class Membership:
*     Plot member function (over-rides the astTransform protected
*     method inherited from the FrameSet class).

*  Description:
*     This function takes a Plot and a set of points encapsulated in a
*     PointSet and transforms the points from graphics coordinates to 
*     physical coordinates (in the forward direction). If the returned 
*     positions are physical coordinates (i.e. if a forward mapping is 
*     performed) they are normalised using the astNorm method of the supplied
*     Plot. The returned axis values are set to AST__BAD for any positions 
*     which are outside the clipping volume set up by the astClip method.

*  Parameters:
*     this
*        Pointer to the Plot.
*     in
*        Pointer to the PointSet holding the input coordinate data.
*     forward
*        A non-zero value indicates that the forward coordinate 
*        transformation should be applied while a zero value requests the 
*        inverse transformation.
*     out
*        Pointer to a PointSet which will hold the transformed (output)
*        coordinate values. A NULL value may also be given, in which case a
*        new PointSet will be created by this function.

*  Returned Value:
*     Pointer to the output (possibly new) PointSet.

*  Notes:
*     -  Clipping is only performed as set up using the astClip method. 
*     In particular, the clipping specified by the arguments to the astPlot
*     constructor function is NOT performed. This is done in order to improve
*     the efficiency of the curve drawing method astGridLine.
*     -  A null pointer will be returned if this function is invoked with the
*     global error status set, or if it should fail for any reason.
*     -  The number of coordinate values per point in the input PointSet must
*     match the number of coordinates for the Plot being applied.
*     -  If an output PointSet is supplied, it must have space for sufficient
*     number of points and coordinate values per point to accommodate the
*     result. Any excess space will be ignored.
*/

/* Local Variables: */
   AstMapping *map;              /* Pointer to the mapping */
   AstPointSet *result;          /* Positions in output Frame */
   AstPlot *plot;                /* The Plot */

/* Check the global error status. */
   if ( !astOK ) return NULL;

/* Get a pointer to the Plot. */
   plot = (AstPlot *) this;

/* Get the Mapping from the base to the current Frame. */
   map = astGetMapping( plot, AST__BASE, AST__CURRENT );

/* Do the transformation. */
   result = Trans( plot, NULL, map, in, forward, out, 1, "astTransform",
                   astGetClass( this ) );

/* Annul the mapping. */
   map = astAnnul( map );

/* If an error has occurred, annul the result. */
   if( !astOK ) result = astAnnul( result );

/* Return a pointer to the output PointSet. */
   return result;

}

static int Ustrcmp( const char *a, const char *b ){
/*
*  Name:
*     Ustrncmp

*  Purpose:
*     A case blind version of strcmp.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     static int Ustrcmp( const char *a, const char *b )

*  Class Membership:
*     Plot member function.

*  Description:
*     Returns 0 if there are no differences between the two strings, and 1 
*     otherwise. Comparisons are case blind.

*  Parameters:
*     a
*        Pointer to first string.
*     b
*        Pointer to second string.

*  Returned Value:
*     Zero if the strings match, otherwise one.

*  Notes:
*     -  This function does not consider the sign of the difference between
*     the two strings, whereas "strcmp" does.
*     -  This function attempts to execute even if an error has occurred. 

*/

/* Local Variables: */
   const char *aa;         /* Pointer to next "a" character */
   const char *bb;         /* Pointer to next "b" character */
   int ret;                /* Returned value */

/* Initialise the returned value to indicate that the strings match. */
   ret = 0;

/* Initialise pointers to the start of each string. */
   aa = a;
   bb = b;

/* Loop round each character. */
   while( 1 ){

/* We leave the loop if either of the strings has been exhausted. */
      if( !(*aa ) || !(*bb) ){

/* If one of the strings has not been exhausted, indicate that the
   strings are different. */
         if( *aa || *bb ) ret = 1;

/* Break out of the loop. */
         break;

/* If neither string has been exhausted, convert the next characters to
   upper case and compare them, incrementing the pointers to the next
   characters at the same time. If they are different, break out of the
   loop. */
      } else {

         if( toupper( (int) *(aa++) ) != toupper( (int) *(bb++) ) ){
            ret = 1;
            break;
         }

      }

   }

/* Return the result. */
   return ret;

}

static int Ustrncmp( const char *a, const char *b, size_t n ){
/*
*  Name:
*     Ustrncmp

*  Purpose:
*     A case blind version of strncmp.

*  Type:
*     Private function.

*  Synopsis:
*     #include "plot.h"
*     static int Ustrncmp( const char *a, const char *b, size_t n )

*  Class Membership:
*     Plot member function.

*  Description:
*     Returns 0 if there are no differences between the first "n"
*     characters of the two strings, and 1 otherwise. Comparisons are
*     case blind.

*  Parameters:
*     a
*        Pointer to first string.
*     b
*        Pointer to second string.
*     n
*        The maximum number of characters to compare.

*  Returned Value:
*     Zero if the strings match, otherwise one.

*  Notes:
*     -  This function does not consider the sign of the difference 
*     between the two strings, whereas "strncmp" does.
*     -  This function attempts to execute even if an error has 
*     occurred. 

*/

/* Local Variables: */
   const char *aa;         /* Pointer to next "a" character */
   const char *bb;         /* Pointer to next "b" character */
   int i;                  /* Character index */
   int ret;                /* Returned value */

/* Initialise the returned value to indicate that the strings match. */
   ret = 0;

/* Initialise pointers to the start of each string. */
   aa = a;
   bb = b;

/* Compare up to "n" characters. */
   for( i = 0; i < (int) n; i++ ){

/* We leave the loop if either of the strings has been exhausted. */
      if( !(*aa ) || !(*bb) ){

/* If one of the strings has not been exhausted, indicate that the
   strings are different. */
         if( *aa || *bb ) ret = 1;

/* Break out of the loop. */
         break;

/* If neither string has been exhausted, convert the next characters to
   upper case and compare them, incrementing the pointers to the next
   characters at the same time. If they are different, break out of the
   loop. */
      } else {

         if( toupper( (int) *(aa++) ) != toupper( (int) *(bb++) ) ){
            ret = 1;
            break;
         }

      }

   }

/* Return the result. */
   return ret;

}

/* Destructor. */
/* ----------- */
static void Delete( AstObject *obj ) {
/*
*  Name:
*     Delete

*  Purpose:
*     Destructor for Plot objects.

*  Type:
*     Private function.

*  Synopsis:
*     void Delete( AstObject *obj )

*  Description:
*     This function implements the destructor for Plot objects.

*  Parameters:
*     obj
*        Pointer to the object to be deleted.

*  Notes:
*     This function attempts to execute even if the global error status is
*     set.
*/

/* Local Variables: */
   AstPlot *this;               /* Pointer to Plot */

/* Obtain a pointer to the Plot structure. */
   this = (AstPlot *) obj;

/* Free the clipping bounds arrays. */
   this->clip_lbnd = (double *) astFree( (void *) this->clip_lbnd );
   this->clip_ubnd = (double *) astFree( (void *) this->clip_ubnd );

}

/* Copy constructor. */
/* ----------------- */
static void Copy( const AstObject *objin, AstObject *objout ) {
/*
*  Name:
*     Copy

*  Purpose:
*     Copy constructor for Plot objects.

*  Type:
*     Private function.

*  Synopsis:
*     void Copy( const AstObject *objin, AstObject *objout )

*  Description:
*     This function implements the copy constructor for Plot objects.

*  Parameters:
*     objin
*        Pointer to the object to be copied.
*     objout
*        Pointer to the object being constructed.

*  Notes:
*     -  This constructor makes a deep copy.
*/

/* Local Variables: */
   AstPlot *in;                 /* Pointer to input Plot */
   AstPlot *out;                /* Pointer to output Plot */

/* Check the global error status. */
   if ( !astOK ) return;

/* Obtain pointers to the input and output Plots. */
   in = (AstPlot *) objin;
   out = (AstPlot *) objout;

/* For safety, first clear any references to the input memory from
   the output Plot. */
   out->clip_lbnd = NULL;
   out->clip_ubnd = NULL;

/* Copy the clipping bounds arrays. */
   out->clip_lbnd = (double *) astStore( NULL, (void *) in->clip_lbnd,
                                      sizeof(double)*(size_t)(in->clip_axes) );
   out->clip_ubnd = (double *) astStore( NULL, (void *) in->clip_ubnd,
                                      sizeof(double)*(size_t)(in->clip_axes) );

/* If an error occurred, free any allocated memory. */
   if ( !astOK ) { 
      out->clip_lbnd = (double *) astFree( out->clip_lbnd );     
      out->clip_ubnd = (double *) astFree( out->clip_ubnd );
    }
}

/* Dump function. */
/* -------------- */
static void Dump( AstObject *this_object, AstChannel *channel ) {
/*
*  Name:
*     Dump

*  Purpose:
*     Dump function for Plot objects.

*  Type:
*     Private function.

*  Synopsis:
*     void Dump( AstObject *this, AstChannel *channel )

*  Description:
*     This function implements the Dump function which writes out data
*     for the Plot class to an output Channel.

*  Parameters:
*     this
*        Pointer to the Plot whose data are being written.
*     channel
*        Pointer to the Channel to which the data are being written.
*/

#define KEY_LEN 50               /* Maximum length of a keyword */

/* Local Variables: */
   AstPlot *this;                /* Pointer to the Plot structure */
   char buff[ KEY_LEN + 1 ];     /* Buffer for keyword string */
   char *comment;                /* Pointer to comment string */
   double dval;                  /* Double precision value */
   int axis;                     /* Zero based axis index */
   int id;                       /* Zero based graphical object id */
   int ival;                     /* Integer value */
   int set;                      /* Attribute value set? */

/* Check the global error status. */
   if ( !astOK ) return;

/* Obtain a pointer to the Plot structure. */
   this = (AstPlot *) this_object;

/* Write out values representing the instance variables for the
   Plot class.  Accompany these with appropriate comment strings,
   possibly depending on the values being written.*/

/* In the case of attributes, we first use the appropriate (private)
   Test...  member function to see if they are set. If so, we then use
   the (private) Get... function to obtain the value to be written
   out.

   For attributes which are not set, we use the astGet... method to
   obtain the value instead. This will supply a default value
   (possibly provided by a derived class which over-rides this method)
   which is more useful to a human reader as it corresponds to the
   actual default attribute value.  Since "set" will be zero, these
   values are for information only and will not be read back. */

/* Tol. */
/* ---- */
   set = TestTol( this );
   dval = set ? GetTol( this ) : astGetTol( this );
   astWriteDouble( channel, "Tol", set, 0, dval, "Plotting tolerance" );

/* Grid. */
/* ----- */
   set = TestGrid( this );
   ival = set ? GetGrid( this ) : astGetGrid( this );
   astWriteInt( channel, "Grid", set, 0, ival, "Is a grid required?" );

/* TickAll. */
/* -------- */
   set = TestTickAll( this );
   ival = set ? GetTickAll( this ) : astGetTickAll( this );
   astWriteInt( channel, "TckAll", set, 1, ival, "Put ticks on all edges?" );

/* Border. */
/* ------- */
   set = TestBorder( this );
   ival = set ? GetBorder( this ) : astGetBorder( this );
   astWriteInt( channel, "Border", set, 0, ival, "Draw a border round the grid?" );

/* ClipOp. */
/* ------- */
   set = TestClipOp( this );
   ival = set ? GetClipOp( this ) : astGetClipOp( this );
   astWriteInt( channel, "ClpOp", set, 0, ival, "Clip using logical OR?" );

/* DrawTitle. */
/* --------- */
   set = TestDrawTitle( this );
   ival = set ? GetDrawTitle( this ) : astGetDrawTitle( this );
   astWriteInt( channel, "DrwTtl", set, 1, ival, "Add a title to the grid?" );

/* DrawAxes. */
/* --------- */
   set = TestDrawAxes( this );
   ival = set ? GetDrawAxes( this ) : astGetDrawAxes( this );
   astWriteInt( channel, "DrwAxs", set, 1, ival, "Draw axes through ticks?" );

/* Escape. */
/* ------- */
/* NOTE - this attribute is not currently used. The following code should
   be uncommented when facilities exist in the rest of AST to support its
   use. (ENABLE-ESCAPE) */
   /*
   set = TestEscape( this );
   ival = set ? GetEscape( this ) : astGetEscape( this );
   astWriteInt( channel, "Escape", set, 1, ival, "Interpret escape sequences?" );
   */

/* LabelAt(axis). */
/* -------------- */
   for( axis = 0; axis < 2; axis++ ){
      set = TestLabelAt( this, axis );
      dval = set ? GetLabelAt( this, axis ) : astGetLabelAt( this, axis );
      if( dval != AST__BAD ){
         (void) sprintf( buff, "LblAt%d", axis + 1 );
         astWriteDouble( channel, buff, set, 0, dval, "Put numerical labels at" );
      }
   }

/* Centre(axis). */
/* ------------ */
   for( axis = 0; axis < 2; axis++ ){
      set = TestCentre( this, axis );
      dval = set ? GetCentre( this, axis ) : astGetCentre( this, axis );
      if( dval != AST__BAD ){
         (void) sprintf( buff, "Cen%d", axis + 1 );
         astWriteDouble( channel, buff, set, 0, dval, "Tick mark origin" );
      }
   }

/* Gap(axis). */
/* ---------- */
/* Discovering the default value requires a lot of calculation. Only
   write out this attribute if an explicit value has been set. */
   for( axis = 0; axis < 2; axis++ ){
      if( astTestGap( this, axis ) ) {
         dval = astGetGap( this, axis );
         if( dval != AST__BAD ){
            (void) sprintf( buff, "Gap%d", axis + 1 );
            astWriteDouble( channel, buff, set, 0, dval, "Gap between ticks" );
         }
      }
   }

/* NumLabGap(axis). */
/* ---------------- */
   for( axis = 0; axis < 2; axis++ ){
      set = TestNumLabGap( this, axis );
      dval = set ? GetNumLabGap( this, axis ) : astGetNumLabGap( this, axis );
      if( dval != AST__BAD ) {
         (void) sprintf( buff, "NmGap%d", axis + 1 );
         astWriteDouble( channel, buff, set, 1, dval, "Spacing of numerical labels" );
      }
   }

/* TextLabGap(axis). */
/* ----------------- */
   for( axis = 0; axis < 2; axis++ ){
      set = TestTextLabGap( this, axis );
      dval = set ? GetTextLabGap( this, axis ) : astGetTextLabGap( this, axis );
      if( dval != AST__BAD ) {
         (void) sprintf( buff, "TxGap%d", axis + 1 );
         astWriteDouble( channel, buff, set, 1, dval, "Spacing of descriptive labels" );
      }
   }

/* LabelUp(axis). */
/* -------------- */
   for( axis = 0; axis < 2; axis++ ){
      set = TestLabelUp( this, axis );
      ival = set ? GetLabelUp( this, axis ) : astGetLabelUp( this, axis );
      (void) sprintf( buff, "LblUp%d", axis + 1 );
      astWriteInt( channel, buff, set, 1, ival, "Draw numerical labels upright?" );
   }

/* NumLab(axis). */
/* -------------- */
   for( axis = 0; axis < 2; axis++ ){
      set = TestNumLab( this, axis );
      ival = set ? GetNumLab( this, axis ) : astGetNumLab( this, axis );
      (void) sprintf( buff, "NmLbl%d", axis + 1 );
      astWriteInt( channel, buff, set, 1, ival, "Draw numerical labels?" );
   }

/* MinTick(axis). */
/* -------------- */
   for( axis = 0; axis < 2; axis++ ){
      set = TestMinTick( this, axis );
      ival = set ? GetMinTick( this, axis ) : astGetMinTick( this, axis );
      (void) sprintf( buff, "MnTks%d", axis + 1 );
      astWriteInt( channel, buff, set, 0, ival, "No. of sub-divisions "
                   "between major tick marks" );
   }

/* TextLab(axis). */
/* -------------- */
   for( axis = 0; axis < 2; axis++ ){
      set = TestTextLab( this, axis );
      ival = set ? GetTextLab( this, axis ) : astGetTextLab( this, axis );
      (void) sprintf( buff, "TxLbl%d", axis + 1 );
      astWriteInt( channel, buff, set, 0, ival, "Draw textual label?" );
   }

/* LabelUnits(axis). */
/* ----------------- */
   for( axis = 0; axis < 2; axis++ ){
      set = TestLabelUnits( this, axis );
      ival = set ? GetLabelUnits( this, axis ) : astGetLabelUnits( this, axis );
      (void) sprintf( buff, "LbUnt%d", axis + 1 );
      astWriteInt( channel, buff, set, 0, ival, "Add units to axis label?" );
   }

/* Style(object). */
/* -------------- */
   for( id = 0; id < AST__NPID; id++ ){
      set = TestStyle( this, id );
      ival = set ? GetStyle( this, id ) : astGetStyle( this, id );
      (void) sprintf( buff, "Style%d", id + 1 );
      comment = GrfItem( id, " line style" );
      astWriteInt( channel, buff, set, 0, ival, comment );
      comment = (char *) astFree( (void *) comment );
   }

/* Font(object). */
/* ------------- */
   for( id = 0; id < AST__NPID; id++ ){
      set = TestFont( this, id );
      ival = set ? GetFont( this, id ) : astGetFont( this, id );
      (void) sprintf( buff, "Font%d", id + 1 );
      comment = GrfItem( id, " character font" );
      astWriteInt( channel, buff, set, 0, ival, comment );
      comment = (char *) astFree( (void *) comment );
   }

/* Colour(object). */
/* --------------- */
   for( id = 0; id < AST__NPID; id++ ){
      set = TestColour( this, id );
      ival = set ? GetColour( this, id ) : astGetColour( this, id );
      (void) sprintf( buff, "Col%d", id + 1 );
      comment = GrfItem( id, " colour index" );
      astWriteInt( channel, buff, set, 0, ival, comment );
      comment = (char *) astFree( (void *) comment );
   }

/* Width(object). */
/* -------------- */
   for( id = 0; id < AST__NPID; id++ ){
      set = TestWidth( this, id );
      dval = set ? GetWidth( this, id ) : astGetWidth( this, id );
      if( dval != AST__BAD ) {
         (void) sprintf( buff, "Width%d", id + 1 );
         comment = GrfItem( id, " line width" );
         astWriteDouble( channel, buff, set, 0, dval, comment );
         comment = (char *) astFree( (void *) comment );
      }
   }

/* Size(object). */
/* ------------- */
   for( id = 0; id < AST__NPID; id++ ){
      set = TestSize( this, id );
      dval = set ? GetSize( this, id ) : astGetSize( this, id );
      if( dval != AST__BAD ) {
         (void) sprintf( buff, "Size%d", id + 1 );
         comment = GrfItem( id, " character size" );
         astWriteDouble( channel, buff, set, 0, dval, comment );
         comment = (char *) astFree( (void *) comment );
      }
   }

/* TitleGap. */
/* --------- */
   set = TestTitleGap( this );
   dval = set ? GetTitleGap( this ) : astGetTitleGap( this );
   if( dval != AST__BAD ) astWriteDouble( channel, "TtlGap", set, 1, dval, 
                                         "Gap between title and edge" );

/* MajTickLen(axis). */
/* ----------------- */
   for( axis = 0; axis < 2; axis++ ){
      set = TestMajTickLen( this, axis );
      dval = set ? GetMajTickLen( this, axis ) : astGetMajTickLen( this, axis );
      if( dval != AST__BAD ) {
         (void) sprintf( buff, "MjTkLn%d", axis + 1 );
         astWriteDouble( channel, buff, set, 0, dval, "Major tick length" );
      }
   }

/* MinTickLen(axis). */
/* ----------------- */
   for( axis = 0; axis < 2; axis++ ){
      set = TestMinTickLen( this, axis );
      dval = set ? GetMinTickLen( this, axis ) : astGetMinTickLen( this, axis );
      if( dval != AST__BAD ) {
         (void) sprintf( buff, "MnTkLn%d", axis + 1 );
         astWriteDouble( channel, buff, set, 1, dval, "Minor tick length" );
      }
   }

/* Labelling. */
/* ---------- */
   set = TestLabelling( this );
   ival = set ? GetLabelling( this ) : astGetLabelling( this );
   comment = "Labelling scheme";
   astWriteString( channel, "Lbling", set, 0, xlbling[ival], comment );

/* Edge(axis). */
/* ----------- */
   for( axis = 0; axis < 2; axis++ ){
      set = TestEdge( this, axis );
      ival = set ? GetEdge( this, axis ) : astGetEdge( this, axis );
      (void) sprintf( buff, "Edge%d", axis + 1 );

      if( axis == 0 ) {
         comment = "Edge used to label axis 1";
      } else {
         comment = "Edge used to label axis 2";
      }

      astWriteString( channel, buff, set, 0, xedge[ival], comment );
   }

/* Now do instance variables which are not attributes. */
/* =================================================== */

/* Only write out clipping information if set. */
   if( this->clip_lbnd && this->clip_ubnd ){

/* The lower bounds of the clipping volume. */
      for( axis = 0; axis < this->clip_axes; axis++ ){
         (void) sprintf( buff, "ClpLb%d", axis + 1 );
         if( this->clip_lbnd && (this->clip_lbnd)[ axis ] != AST__BAD ){
            astWriteDouble( channel, buff, 1, 0, (this->clip_lbnd)[ axis ], 
                            "Lower bound of clipping region" );
         }
      }

/* The upper bounds of the clipping volume. */
      for( axis = 0; axis < this->clip_axes; axis++ ){
         (void) sprintf( buff, "ClpUb%d", axis + 1 );
         if( this->clip_ubnd && (this->clip_ubnd)[ axis ] != AST__BAD ){
            astWriteDouble( channel, buff, 1, 0, (this->clip_ubnd)[ axis ], 
                            "Upper bound of clipping region" );
         } 
      }

/* The number of bounds supplied for the clipping volume. */
      astWriteInt( channel, "ClpAxs", 1, 0, this->clip_axes,
                   "No. of bounds for clipping region" );

/* The index of the clipping Frame within the Plot. */
      astWriteInt( channel, "ClpFrm", 1, 0, this->clip_frame,
                   "Index of clipping Frame" );
   }

/* The bounds of the plotting area. */   
   astWriteDouble( channel, "Xlo", 1, 1, this->xlo,
                   "Lower X bound of plotting area" );
   astWriteDouble( channel, "Ylo", 1, 1, this->ylo,
                   "Lower Y bound of plotting area" );
   astWriteDouble( channel, "Xhi", 1, 1, this->xhi,
                   "Upper X bound of plotting area" );
   astWriteDouble( channel, "Yhi", 1, 1, this->yhi,
                   "Upper Y bound of plotting area" );

/* Axis reversal flags. */
   astWriteInt( channel, "Xrev", 1, 0, this->xrev, "X axis reversed?" );
   astWriteInt( channel, "Yrev", 1, 0, this->yrev, "Y axis reversed?" );

/* Return. */
   return;

/* Undefine macros local to this function. */
#undef KEY_LEN
}


/* Standard class functions. */
/* ========================= */
/* Implement the astIsAPlot and astCheckPlot functions using
   the macros defined for this purpose in the "object.h" header
   file. */
astMAKE_ISA(Plot,FrameSet,check,&class_init)
astMAKE_CHECK(Plot)

AstPlot *astPlot_( void *frame_void, const float *graphbox, 
                   const double *basebox, const char *options, ... ) {
/*
*+
*  Name:
*     astPlot

*  Purpose:
*     Create a Plot.

*  Type:
*     Protected function.

*  Synopsis:
*     #include "plot.h"
*     AstPlot *astPlot( AstFrame *frame, const float *graphbox, 
*                       const double *basebox, const char *options, ... ) 

*  Class Membership:
*     Plot constructor.

*  Description:
*     This function creates a new Plot and optionally initialises
*     its attributes.
*
*     The supplied Frame (or the base frame if a FrameSet was supplied) is 
*     assumed to be related to the graphics world coordinate system by a 
*     simple shift and scale along each axis. The mapping between graphics 
*     world coordinates and this Frame is specified by supplying the 
*     coordinates in both systems at the bottom left and top right corners 
*     of a box on the graphics device. By default, no graphics will be 
*     produced outside the supplied box, but this default behaviour can be 
*     changed by setting explicit values for the various clipping attributes.

*  Parameters:
*     frame
*        A pointer to a Frame or FrameSet to be annotated. If a NULL pointer
*        is supplied, then a default 2-D Frame will be created to which labels,
*        etc, can be attached by setting the relevant Frame attributes.
*     graphbox
*        A pointer to an array of 4 values giving the graphics world 
*        coordinates of the bottom left and top right corners of a box on 
*        the graphics output device. The first pair of values should be the 
*        coordinates of the bottom left corner of the box and the second
*        pair of values should be the coordinates of the top right corner.
*        The horizontal axis should be given first in each pair.
*     basebox
*        A pointer to an array of 4 values giving the coordinates in the
*        supplied Frame, or base frame of the supplied FrameSet, at the 
*        bottom left and top right corners of the box specified by parameter 
*        graphbox. These should be supplied in the same order as for 
*        parameter "graphbox".
*     options
*        Pointer to a null terminated string containing an optional
*        comma-separated list of attribute assignments to be used for
*        initialising the new Plot. The syntax used is the same as
*        for the astSet method and may include "printf" format
*        specifiers identified by "%" symbols in the normal way.
*     ...
*        If the "options" string contains "%" format specifiers, then
*        an optional list of arguments may follow it in order to
*        supply values to be substituted for these specifiers. The
*        rules for supplying these are identical to those for the
*        astSet method (and for the C "printf" function).

*  Returned Value:
*     A pointer to the new Plot.

*  Notes:
*     -  The base Frame of the created Plot corresponds to the graphics world
*     coordinate system, and should not, in general, be changed.
*     -  The current Frame of the created Plot corresponds to the Frame
*     given by parameter "frame". If a FrameSet was supplied then its 
*     current Frame becomes the current Frame of the created Plot. 
*     - If the supplied Frame, or base Frame if a FrameSet was supplied, 
*     has more than 2 axes, then the sub-Frame defined by the first 2 axes 
*     is used.
*     -  A NULL pointer will be returned if this function is invoked with the
*     global error status set, or if it should fail for any reason.
*-

*  Implementation Notes:
*     - This function implements the basic Plot constructor which
*     is available via the protected interface to the Plot class.
*     A public interface is provided by the astPlotId_ function.
*     - Because this function has a variable argument list, it is
*     invoked by a macro that evaluates to a function pointer (not a
*     function invocation) and no checking or casting of arguments is
*     performed before the function is invoked. Because of this, the
*     "frame" parameter is of type (void *) and is converted and
*     validated within the function itself.

*/

/* Local Variables: */
   AstFrame *frame;              /* Pointer to Frame structure */
   AstPlot *new;                 /* Pointer to new Plot */
   va_list args;                 /* Variable argument list */

/* Check the global status. */
   if ( !astOK ) return NULL;

/* Obtain and validate a pointer to any supplied Frame structure. */
   if( frame_void ){
      frame = astCheckFrame( frame_void );
   } else {
      frame = NULL;
   }

/* Check the pointer can be used. */
   if ( astOK ) {

/* Initialise the Plot, allocating memory and initialising the
   virtual function table as well if necessary. */
      new = astInitPlot( NULL, sizeof( AstPlot ), !class_init,
                         &class_vtab, "Plot", frame, graphbox, 
                         basebox );

/* If successful, note that the virtual function table has been
   initialised. */
      if ( astOK ) {
         class_init = 1;

/* Obtain the variable argument list and pass it along with the
   options string to the astVSet method to initialise the new
   Plot's attributes. */
         va_start( args, options );
         astVSet( new, options, args );
         va_end( args );

/* If an error occurred, clean up by deleting the new object. */
         if ( !astOK ) new = astDelete( new );
      }
   }

/* Return a pointer to the new Plot. */
   return new;
}

AstPlot *astInitPlot_( void *mem, size_t size, int init, AstPlotVtab *vtab, 
                       const char *name, AstFrame *frame, const float *graphbox, 
                       const double *basebox ) {
/*
*+
*  Name:
*     astInitPlot

*  Purpose:
*     Initialise a Plot.

*  Type:
*     Protected function.

*  Synopsis:
*     #include "plot.h"
*     AstPlot *astInitPlot( void *mem, size_t size, int init, 
*                           AstPlotVtab *vtab, const char *name, 
*                           AstFrame *frame, const float *graphbox, 
*                           const double *basebox )

*  Class Membership:
*     Plot initialiser.

*  Description:
*     This function is provided for use by class implementations to initialise
*     a new Plot object. It allocates memory (if necessary) to accommodate
*     the Plot plus any additional data associated with the derived class.
*     It then initialises a Plot structure at the start of this memory. If
*     the "init" flag is set, it also initialises the contents of a virtual
*     function table for a Plot at the start of the memory passed via the
*     "vtab" parameter.

*  Parameters:
*     mem
*        A pointer to the memory in which the Plot is to be created. This
*        must be of sufficient size to accommodate the Plot data
*        (sizeof(Plot)) plus any data used by the derived class. If a value
*        of NULL is given, this function will allocate the memory itself using
*        the "size" parameter to determine its size.
*     size
*        The amount of memory used by the Plot (plus derived class data).
*        This will be used to allocate memory if a value of NULL is given for
*        the "mem" parameter. This value is also stored in the Plot
*        structure, so a valid value must be supplied even if not required for
*        allocating memory.
*     init
*        A logical flag indicating if the Plot's virtual function table is
*        to be initialised. If this value is non-zero, the virtual function
*        table will be initialised by this function.
*     vtab
*        Pointer to the start of the virtual function table to be associated
*        with the new Plot.
*     name
*        Pointer to a constant null-terminated character string which contains
*        the name of the class to which the new object belongs (it is this
*        pointer value that will subsequently be returned by the astGetClass
*        method).
*     fset
*        A pointer to the Frame or Frameset to be annotated.
*     graphbox
*        A pointer to an array of 4 values giving the graphics coordinates 
*        of the bottom left and top right corners of a box on the graphics 
*        output device. The first pair of values should be the graphics 
*        coordinates of the bottom left corner of the box and the second
*        pair of values are the graphics coordinates of the top right corner.
*        The horizontal axis should be given first in each pair.
*     basebox
*        A pointer to an array of 4 values giving the coordinates in the
*        supplied Frame or base Frame of the supplied FrameSet at the bottom 
*        left and top right corners of the box specified by parameter graphbox.
*        These should be supplied in the same order as for parameter "graphbox".

*  Returned Value:
*     A pointer to the new Plot.

*  Notes:
*     - If the supplied Frame, or base Frame if a FrameSet was supplied, 
*     has more than 2 axes, then the sub-Frame defined by the first 2 axes 
*     is used.
*     -  The current Frame of the supplied FrameSet need not be 2-dimensional.
*     -  A null pointer will be returned if this function is invoked with the
*     global error status set, or if it should fail for any reason.
*-
*/

/* Local Variables: */
   AstPlot *new;                /* Pointer to new Plot */
   AstFrame *baseframe;         /* Pointer to base frame */
   AstFrame *graphicsframe;     /* Pointer to graphics frame */
   AstFrameSet *fset0;          /* The n-D FrameSet to be annotated */
   AstFrameSet *fset;           /* The 2-D FrameSet to be annotated */
   AstWinMap *winmap;           /* Mapping which scales and shifts coords */
   char *mess;                  /* Pointer to a descriptive message */
   double gbox[ 4 ];            /* Double precision version of "graphbox" */
   int axis;                    /* Axis index, 0 or 1 */
   int bi;                      /* Index of base frame */
   int ci;                      /* Index of current frame */
   int id;                      /* Plot object id */
   int naxes;                   /* No. of axes in frame */

/* Check the global status. */
   if ( !astOK ) return NULL;

/* Initialise. */
   new = NULL;

/* First of all we need to ensure that we have a FrameSet and a base 
   Frame on which to base the new Plot. If a NULL Frame pointer was 
   supplied, create a default 2-D Frame, and then create a FrameSet 
   containing just this default Frame. Also store a pointer to a 
   message which can be used to describe the object within error 
   messages. */
   if( !frame ){
      baseframe = astFrame( 2, "" );
      fset = astFrameSet( baseframe, "" );
      mess = "default 2-d Frame";

/* If an object was supplied, report an error if it is not a Frame or 
   an object derived from a Frame (such as a FrameSet). */
   } else if( !astIsAFrame( frame ) ){
      if( astOK ){
         astError( AST__BDOBJ, "astInitPlot(%s): Supplied Object (class '%s') "
                   "is not a Frame.", name, astGetClass( frame ) );
      }

/* Also report an error if the supplied object is a Plot or an object 
   derived from a Plot (a Plot is a sort of Frame and so will pass the 
   above test). */
   } else if( astIsAPlot( frame ) ){
      if( astOK ){
         astError( AST__BDOBJ, "astInitPlot(%s): Supplied Object (class '%s') "
                   "cannot be included in a %s.", name, astGetClass( frame ), 
                   name );
      }
   
/* If the object is not a FrameSet, create a FrameSet holding the 
   supplied Frame. If the Frame is not 2D, an extra 2D Frame is 
   included in the FrameSet derived from axes 1 and 2 of the supplied
   Frame. This new Frame becomes the base Frame. */
   } else if( !astIsAFrameSet( frame ) ){
      fset0 = astFrameSet( frame, "" );
      mess = "supplied Frame";
      fset = Fset2D( fset0, AST__BASE );      
      fset0 = astAnnul( fset0 );
      baseframe = astGetFrame( fset, astGetBase( fset ) );

/* If a FrameSet was supplied, ensure it has a 2D base Frame.
   If the supplied FrameSet is not 2D, then a new base Frame is 
   inserted into it which is derived from axes 1 and 2 of the 
   original base Frame. */
   } else {
      fset = Fset2D( (AstFrameSet *) frame, AST__BASE );      
      baseframe = astGetFrame( fset, astGetBase( fset ) );
      mess = "base Frame of the supplied FrameSet";
   }

/* Check that there are 2 axes in the base frame of the FrameSet. */
   naxes = astGetNaxes( baseframe );
   if ( naxes != 2 && astOK ) {
      astError( AST__NAXIN, "astInitPlot(%s): Number of axes (%d) in the %s "
                "is invalid - this number should be 2.", name, naxes, mess );
   } 

/* Check that neither dimension of the graphbox is zero. */
   if( ( graphbox[ 2 ] == graphbox[ 0 ] ||
         graphbox[ 3 ] == graphbox[ 1 ] ) && astOK ){
      astError( AST__BADBX, "astInitPlot(%s): The plotting area has zero size "
                "in the graphics world coordinate system.", name );
   }

/* Check that neither dimension of the basebox is zero. */
   if( ( basebox[ 2 ] == basebox[ 0 ] ||
         basebox[ 3 ] == basebox[ 1 ] ) && astOK ){
      astError( AST__BADBX, "astInitPlot(%s): The plotting area has zero size "
                "in the coordinate system of the %s.", name, mess );
   }

/* Create a Frame which describes the graphics world coordinate system. */
   graphicsframe = astFrame( 2,
                             "Domain=GRAPHICS,Title=Graphical Coordinates" );

/* Initialise a FrameSet structure (the parent class) as the first
   component within the Plot structure, allocating memory if necessary. 
   The new FrameSet is initialised to hold the graphics Frame created 
   above. */
   new = (AstPlot *) astInitFrameSet( mem, size, init, (AstFrameSetVtab *) vtab,
                                      name, graphicsframe );

/* Annul the frame. */
   graphicsframe = astAnnul( graphicsframe );

/* If necessary, initialise the virtual function table. */
/* ---------------------------------------------------- */
   if ( init ) InitVtab( vtab );
   if ( astOK ) {

/* Initialise the Plot data. */
/* ----------------------------- */

/* Get a double precision version of "graphbox". */
      gbox[ 0 ] = (double) graphbox[ 0 ];
      gbox[ 1 ] = (double) graphbox[ 1 ];
      gbox[ 2 ] = (double) graphbox[ 2 ];
      gbox[ 3 ] = (double) graphbox[ 3 ];

/* Create a mapping which describes the transformation from graphics 
   coordinates to the base (pixel) frame of the supplied FrameSet. This 
   will be a scale and shift on each axis, and is implemented as a WinMap. */
      winmap = astWinMap( 2, gbox, gbox + 2, basebox, basebox + 2, "" );

/* Get the index of the current (physical) and base (pixel) Frames in 
   the supplied FrameSet. */
      bi = astGetBase( fset );
      ci = astGetCurrent( fset );

/* Temporarily set the current Frame to be the pixel frame. */
      astSetCurrent( fset, bi );

/* Add the supplied FrameSet into the Plot (i.e. FrameSet) created 
   earlier. This leaves the graphics frame with index 1 in the 
   returned  Plot. */
      astAddFrame( (AstFrameSet *) new, 1, winmap, fset );

/* Set the current Frame in the Plot to be the physical coordinate Frame 
   (with index incremented by one because the graphics Frame has been added). */
      astSetCurrent( (AstFrameSet *) new, ci + 1 );

/* Re-establish the original current Frame in the supplied FrameSet. */
      astSetCurrent( fset, ci );

/* Annul the mapping */
      winmap = astAnnul( winmap );

/* Store the bounds in graphics coordinates of the clipping box, ensuring
   that the low bound is lower than the high bound. Set flags to indicate
   if the supplied bounds has to be reversed to do this (some graphics
   system have the Y axis increasing from the top of the screen to the
   bottom). */
      if( graphbox[ 0 ] <= graphbox[ 2 ] ){
         new->xlo = gbox[ 0 ];
         new->xhi = gbox[ 2 ];
         new->xrev = 0;
      } else {
         new->xhi = gbox[ 0 ];
         new->xlo = gbox[ 2 ];
         new->xrev = 1;
      }
       if( graphbox[ 1 ] <= graphbox[ 3 ] ){
         new->ylo = gbox[ 1 ];
         new->yhi = gbox[ 3 ];
         new->yrev = 0;
      } else {
         new->yhi = gbox[ 1 ];
         new->ylo = gbox[ 3 ];
         new->yrev = 1;
      }

/* Store a value of -1.0 for Tol to indicate that no value has yet been
   set. This will cause a default value of 0.001 to be used. */
      new->tol = -1.0;

/* Set up default clipping information which gives no clipping. */
      new->clip_frame = AST__NOFRAME;
      new->clip_lbnd = NULL;
      new->clip_ubnd = NULL;
      new->clip_axes = 0;

/* Is a grid covering the plotting area required? Store a value of -1  
   to indicate that no value has yet been set. This will cause a default
   value of 0 (no) to be used. */
      new->grid = -1;

/* Are tick marks to be placed on both edges in a pair of opposite edges?
   Store a value of -1 to indicate that no value has yet been set. This will 
   cause a default value of 1 (yes) to be used. */
      new->tickall = -1;

/* Shoudl ast Grid draw a boundary round the regions of valid coordinates? 
   Store a value of -1 to indicate that no value has yet been set. This will 
   cause a default value of 1 (yes) to be used. */
      new->border = -1;

/* Is clipping to be done using a logical OR operation between the axes? 
   Store a value of -1 to indicate that no value has yet been set. This will 
   cause a default value of 0 (no, i.e. a logical AND) to be used. */
      new->clipop = -1;

/* Is a title to be added to an annotated grid? Store a value of -1 to 
   indicate that no value has yet been set. This will cause a default value 
   of 1 (yes) to be used. */
      new->drawtitle = -1;

/* Are curves to be drawn through the tick marks even if no grid is
   produced? Store a value of -1 to indicate that no value has yet been 
   set. This will cause a default value of 1 (yes) to be used. */
      new->drawaxes = -1;

/* Are escape sequences within text strings to be interpreted? If not,
   they are printed literally. Store a value of -1 when not set.
   This will cause a default value of 1 (yes) to be used. */
      new->escape = -1;

/* A boolean attribute indicating where numerical labels are to be 
   placed; zero implies round the edges of the plotting area; non-zero 
   implies within the plotting area. The unset value of -9999 yields a 
   default of zero. */
      new->labelling = -9999;

/* The length of the major tick marks as a fraction of the minimum
   dimension of the plotting area. Store AST__BAD to indicate that no
   value has been set. This will cause a default of 0.015 to be used. */
      new->majticklen[ 0 ] = AST__BAD;
      new->majticklen[ 1 ] = AST__BAD;

/* The length of the minor tick marks as a fraction of the minimum
   dimension of the plotting area. Store AST__BAD to indicate that no
   value has been set. This will cause a default of 0.007 to be used. */
      new->minticklen[ 0 ] = AST__BAD;
      new->minticklen[ 1 ] = AST__BAD;

/* Are numeric labels to be drawn upright? Store a value of -1 to indicate 
   that no value has yet been set. This will cause a default value of 0 (no)
   to be used. */
      new->labelup[ 0 ] = -1;
      new->labelup[ 1 ] = -1;

/* The space between an axis and its numeric labels as a fraction of the 
   minimum dimension of the plotting area. Store AST__BAD to indicate that no
   value has been set. This will cause a default of 0.01 to be used. */
      new->numlabgap[ 0 ] = AST__BAD;
      new->numlabgap[ 1 ] = AST__BAD;
      new->textlabgap[ 0 ] = AST__BAD;
      new->textlabgap[ 1 ] = AST__BAD;

/* The space between the top edge and the grid title as a fraction of the 
   minimum dimension of the plotting area. Store AST__BAD to indicate that no
   value has been set. This will cause a default of 0.05 to be used. */
      new->titlegap = AST__BAD;

/* The edges on which to put labels for axes 1 and 2. Store values of -1
   to indicate that no values have been set. This will cause default values
   to be used. */
      new->edge[ 0 ] = -1;
      new->edge[ 1 ] = -1;

/* The placement of labels within the plotting area will be done
   automatically by default. */
      new->labelat[ 0 ] = AST__BAD;
      new->labelat[ 1 ] = AST__BAD;

/* The central tick is placed automatically by default. */
      new->centre[ 0 ] = AST__BAD;
      new->centre[ 1 ] = AST__BAD;

/* The gap between tick marks and the number of minor tick marks will be
   found automatically by default. */
      new->gap[ 0 ] = AST__BAD;
      new->gap[ 1 ] = AST__BAD;
      new->mintick[ 0 ] = -1;
      new->mintick[ 1 ] = -1;

/* Both axes will be labelled by default. */
      new->numlab[ 0 ] = -1;
      new->numlab[ 1 ] = -1;
      new->textlab[ 0 ] = -1;
      new->textlab[ 1 ] = -1;
      new->labelunits[ 0 ] = -1;
      new->labelunits[ 1 ] = -1;

/* Graphics attributes. Default behaviour is to use the current values. */
      for( id = 0; id < AST__NPID; id++ ){
         new->style[ id ] = -1;
         new->font[ id ] = -1;
         new->colour[ id ] = -1;
         new->width[ id ] = AST__BAD;
         new->size[ id ] = AST__BAD;
      }

/* Initialise the components used to store the values actually used
   for attributes which have dynamic defaults. */
      for( axis = 0; axis < 2; axis++ ) {
         new->ugap[ axis ] = new->gap[ axis ];
         new->ucentre[ axis ] = new->centre[ axis ];
         new->uedge[ axis ] = new->edge[ axis ];
         new->ulblat[ axis ] = new->labelat[ axis ];
         new->ulbunit[ axis ] = new->labelunits[ axis ];
         new->umintk[ axis ] = new->mintick[ axis ];
         new->utxtlb[ axis ] = new->textlab[ axis ];
         new->umjtkln[ axis ] = new->majticklen[ axis ];
      }
   
      new->ugrid = new->grid;
      new->ulbling = new->labelling;
      new->uborder = new->border;

/* Initialise the protected Ink attribute so that visible ink is used. */
      new->ink = -1;

   }

/* If an error occurred, clean up by deleting the new object. */
   if ( !astOK ) new = astDelete( new );

/* Annul the pointer to the base Frame and FrameSet. */
   baseframe = astAnnul( baseframe );
   fset = astAnnul( fset );

/* Return a pointer to the new object. */
   return new;
}

AstPlot *astLoadPlot_( void *mem, size_t size, int init,
                       AstPlotVtab *vtab, const char *name,
                       AstChannel *channel ) {
/*
*+
*  Name:
*     astLoadPlot

*  Purpose:
*     Load a Plot.

*  Type:
*     Protected function.

*  Synopsis:
*     #include "Plot.h"
*     AstPlot *astLoadPlot( void *mem, size_t size, int init,
*                           AstPlotVtab *vtab, const char *name,
*                           AstChannel *channel )

*  Class Membership:
*     Plot loader.

*  Description:
*     This function is provided to load a new Plot using data read
*     from a Channel. It first loads the data used by the parent class
*     (which allocates memory if necessary) and then initialises a
*     Plot structure in this memory, using data read from the input
*     Channel.
*
*     If the "init" flag is set, it also initialises the contents of a
*     virtual function table for a Plot at the start of the memory
*     passed via the "vtab" parameter.

*  Parameters:
*     mem
*        A pointer to the memory into which the Plot is to be
*        loaded.  This must be of sufficient size to accommodate the
*        Plot data (sizeof(Plot)) plus any data used by derived
*        classes. If a value of NULL is given, this function will
*        allocate the memory itself using the "size" parameter to
*        determine its size.
*     size
*        The amount of memory used by the Plot (plus derived class
*        data).  This will be used to allocate memory if a value of
*        NULL is given for the "mem" parameter. This value is also
*        stored in the Plot structure, so a valid value must be
*        supplied even if not required for allocating memory.
*
*        If the "vtab" parameter is NULL, the "size" value is ignored
*        and sizeof(AstPlot) is used instead.
*     init
*        A boolean flag indicating if the Plot's virtual function
*        table is to be initialised. If this value is non-zero, the
*        virtual function table will be initialised by this function.
*
*        If the "vtab" parameter is NULL, the "init" value is ignored
*        and the (static) virtual function table initialisation flag
*        for the Plot class is used instead.
*     vtab
*        Pointer to the start of the virtual function table to be
*        associated with the new Plot. If this is NULL, a pointer
*        to the (static) virtual function table for the Plot class
*        is used instead.
*     name
*        Pointer to a constant null-terminated character string which
*        contains the name of the class to which the new object
*        belongs (it is this pointer value that will subsequently be
*        returned by the astGetClass method).
*
*        If the "vtab" parameter is NULL, the "name" value is ignored
*        and a pointer to the string "Plot" is used instead.

*  Returned Value:
*     A pointer to the new Plot.

*  Notes:
*     - A null pointer will be returned if this function is invoked
*     with the global error status set, or if it should fail for any
*     reason.
*-
*/

#define KEY_LEN 50               /* Maximum length of a keyword */

/* Local Variables: */
   AstPlot *new;                 /* Pointer to the new Plot */
   char buff[ KEY_LEN + 1 ];     /* Buffer for keyword string */
   char *text;                   /* Textual version of integer value */
   int axis;                     /* Zero based axis index */
   int id;                       /* Zero based graphical object id */

/* Initialise. */
   new = NULL;

/* Check the global error status. */
   if ( !astOK ) return new;

/* If a NULL virtual function table has been supplied, then this is
   the first loader to be invoked for this Plot. In this case the
   Plot belongs to this class, so supply appropriate values to be
   passed to the parent class loader (and its parent, etc.). */
   if ( !vtab ) {
      size = sizeof( AstPlot );
      init = !class_init;
      vtab = &class_vtab;
      name = "Plot";
   }

/* Invoke the parent class loader to load data for all the ancestral
   classes of the current one, returning a pointer to the resulting
   partly-built Plot. */
   new = astLoadFrameSet( mem, size, init, (AstFrameSetVtab *) vtab, name,
                          channel );

/* If required, initialise the part of the virtual function table used
   by this class. */
   if ( init ) InitVtab( vtab );

/* Note if we have successfully initialised the (static) virtual
   function table owned by this class (so that this is done only
   once). */
   if ( astOK ) {
      if ( ( vtab == &class_vtab ) && init ) class_init = 1;

/* Read input data. */
/* ================ */
/* Request the input Channel to read all the input data appropriate to
   this class into the internal "values list". */
      astReadClassData( channel, "Plot" );

/* Now read each individual data item from this list and use it to
   initialise the appropriate instance variable(s) for this class. */

/* In the case of attributes, we first read the "raw" input value,
   supplying the "unset" value as the default. If a "set" value is
   obtained, we then use the appropriate (private) Set... member
   function to validate and set the value properly. */

/* Tol. */
/* ---- */
      new->tol = astReadDouble( channel, "tol", -1.0 );
      if ( TestTol( new ) ) SetTol( new, new->tol );

/* Grid. */
/* ----- */
      new->grid = astReadInt( channel, "grid", -1 );
      if ( TestGrid( new ) ) SetGrid( new, new->grid );

/* TickAll. */
/* -------- */
      new->tickall = astReadInt( channel, "tckall", -1 );
      if ( TestTickAll( new ) ) SetTickAll( new, new->tickall );

/* Border. */
/* -------- */
      new->border = astReadInt( channel, "border", -1 );
      if ( TestBorder( new ) ) SetBorder( new, new->border );

/* ClipOp. */
/* ------- */
      new->clipop = astReadInt( channel, "clpop", -1 );
      if ( TestClipOp( new ) ) SetClipOp( new, new->clipop );

/* DrawTitle. */
/* --------- */
      new->drawtitle = astReadInt( channel, "drwttl", -1 );
      if ( TestDrawTitle( new ) ) SetDrawTitle( new, new->drawtitle );

/* LabelUp(axis). */
/* -------------- */
      for( axis = 0; axis < 2; axis++ ){
         (void) sprintf( buff, "lblup%d", axis + 1 );
         new->labelup[ axis ] = astReadInt( channel, buff, -1 );
         if ( TestLabelUp( new, axis ) ) SetLabelUp( new, axis,
                                                     new->labelup[ axis ] );
      }

/* DrawAxes. */
/* --------- */
      new->drawaxes = astReadInt( channel, "drwaxs", -1 );
      if ( TestDrawAxes( new ) ) SetDrawAxes( new, new->drawaxes );

/* Escape. */
/* ------- */
/* NOTE - this attribute is not currently used. The following code should
   be uncommented when facilities exist in the rest of AST to support its
   use. (ENABLE-ESCAPE) */
   /*
      new->escape = astReadInt( channel, "escape", -1 );
      if ( TestEscape( new ) ) SetEscape( new, new->escape );
   */

/* LabelAt(axis). */
/* -------------- */
      for( axis = 0; axis < 2; axis++ ){
         (void) sprintf( buff, "lblat%d", axis + 1 );
         new->labelat[ axis ] = astReadDouble( channel, buff, AST__BAD );
         if ( TestLabelAt( new, axis ) ) SetLabelAt( new, axis,
                                                     new->labelat[ axis ] );
      }

/* Centre(axis). */
/* ------------ */
      for( axis = 0; axis < 2; axis++ ){
         (void) sprintf( buff, "cen%d", axis + 1 );
         new->centre[ axis ] = astReadDouble( channel, buff, AST__BAD );
         if ( TestCentre( new, axis ) ) SetCentre( new, axis,
                                                   new->centre[ axis ] );
      }

/* Gap(axis). */
/* ---------- */
      for( axis = 0; axis < 2; axis++ ){
         (void) sprintf( buff, "gap%d", axis + 1 );
         new->gap[ axis ] = astReadDouble( channel, buff, AST__BAD );
         if ( TestGap( new, axis ) ) SetGap( new, axis, new->gap[ axis ] );
      }

/* NumLabGap(axis). */
/* -------------- */
      for( axis = 0; axis < 2; axis++ ){
         (void) sprintf( buff, "nmgap%d", axis + 1 );
         new->numlabgap[ axis ] = astReadDouble( channel, buff, AST__BAD );
         if ( TestNumLabGap( new, axis ) ) SetNumLabGap( new, axis,
                                                     new->numlabgap[ axis ] );
      }

/* TextLabGap(axis). */
/* -------------- */
      for( axis = 0; axis < 2; axis++ ){
         (void) sprintf( buff, "txgap%d", axis + 1 );
         new->textlabgap[ axis ] = astReadDouble( channel, buff, AST__BAD );
         if ( TestTextLabGap( new, axis ) ) SetTextLabGap( new, axis,
                                                     new->textlabgap[ axis ] );
      }

/* NumLab(axis). */
/* ---------------- */
      for( axis = 0; axis < 2; axis++ ){
         (void) sprintf( buff, "nmlbl%d", axis + 1 );
         new->numlab[ axis ] = astReadInt( channel, buff, -1 );
         if ( TestNumLab( new, axis ) ) SetNumLab( new, axis,
                                                     new->numlab[ axis ] );
      }

/* MinTick(axis). */
/* --------------- */
      for( axis = 0; axis < 2; axis++ ){
         (void) sprintf( buff, "mntks%d", axis + 1 );
         new->mintick[ axis ] = astReadInt( channel, buff, -1 );
         if ( TestMinTick( new, axis ) ) SetMinTick( new, axis,
                                                       new->mintick[ axis ] );
      }

/* TextLab(axis). */
/* -------------- */
      for( axis = 0; axis < 2; axis++ ){
         (void) sprintf( buff, "txlbl%d", axis + 1 );
         new->textlab[ axis ] = astReadInt( channel, buff, -1 );
         if ( TestTextLab( new, axis ) ) SetTextLab( new, axis,
                                                      new->textlab[ axis ] );
      }

/* LabelUnits(axis). */
/* --------------- */
      for( axis = 0; axis < 2; axis++ ){
         (void) sprintf( buff, "lbunt%d", axis + 1 );
         new->labelunits[ axis ] = astReadInt( channel, buff, -1 );
         if ( TestLabelUnits( new, axis ) ) SetLabelUnits( new, axis,
                                                      new->labelunits[ axis ] );
      }

/* Style(object). */
/* ------------ */
      for( id = 0; id < AST__NPID; id++ ){
         (void) sprintf( buff, "style%d", id + 1 );
         new->style[ id ] = astReadInt( channel, buff, -1 );
         if ( TestStyle( new, id ) ) SetStyle( new, id, new->style[ id ] );
      }

/* Font(object). */
/* ----------- */
      for( id = 0; id < AST__NPID; id++ ){
         (void) sprintf( buff, "font%d", id + 1 );
         new->font[ id ] = astReadInt( channel, buff, -1 );
         if ( TestFont( new, id ) ) SetFont( new, id, new->font[ id ] );
      }

/* Colour(object). */
/* --------------- */
      for( id = 0; id < AST__NPID; id++ ){
         (void) sprintf( buff, "col%d", id + 1 );
         new->colour[ id ] = astReadInt( channel, buff, -1 );
         if ( TestColour( new, id ) ) SetColour( new, id, new->colour[ id ] );
      }

/* Width(object). */
/* ------------ */
      for( id = 0; id < AST__NPID; id++ ){
         (void) sprintf( buff, "width%d", id + 1 );
         new->width[ id ] = astReadDouble( channel, buff, AST__BAD );
         if ( TestWidth( new, id ) ) SetWidth( new, id, new->width[ id ] );
      }

/* Size(object). */
/* ----------- */
      for( id = 0; id < AST__NPID; id++ ){
         (void) sprintf( buff, "size%d", id + 1 );
         new->size[ id ] = astReadDouble( channel, buff, AST__BAD );
         if ( TestSize( new, id ) ) SetSize( new, id, new->size[ id ] );
      }

/* TitleGap. */
/* --------- */
      new->titlegap = astReadDouble( channel, "ttlgap", AST__BAD );
      if ( TestTitleGap( new ) ) SetTitleGap( new, new->titlegap );

/* MajTickLen. */
/* ----------- */
/* Retained in order to read old Plots - new Plots use MajTickLen(axis). */
      new->majticklen[ 0 ] = astReadDouble( channel, "mjtkln", AST__BAD );
      if( new->majticklen[ 0 ] != AST__BAD ) {
         new->majticklen[ 1 ] = new->majticklen[ 0 ];
         if ( TestMajTickLen( new, 0 ) ) SetMajTickLen( new, 0, new->majticklen[ 0 ] );
         if ( TestMajTickLen( new, 1 ) ) SetMajTickLen( new, 1, new->majticklen[ 1 ] );

/* MajTickLen(axis). */
/* ----------------- */
      } else {
         for( axis = 0; axis < 2; axis++ ){
            (void) sprintf( buff, "mjtkln%d", axis + 1 );
            new->majticklen[ axis ] = astReadDouble( channel, buff, AST__BAD );
            if ( TestMajTickLen( new, axis ) ) SetMajTickLen( new, axis,
                                                        new->majticklen[ axis ] );
         }
      }

/* MinTickLen. */
/* ----------- */
/* Retained in order to read old Plots - new Plots use MinTickLen(axis). */
      new->minticklen[ 0 ] = astReadDouble( channel, "mntkln", AST__BAD );
      if( new->minticklen[ 0 ] != AST__BAD ) {
         new->minticklen[ 1 ] = new->minticklen[ 0 ];
         if ( TestMinTickLen( new, 0 ) ) SetMinTickLen( new, 0, new->minticklen[ 0 ] );
         if ( TestMinTickLen( new, 1 ) ) SetMinTickLen( new, 1, new->minticklen[ 1 ] );

/* MinTickLen(axis). */
/* ----------------- */
      } else {
         for( axis = 0; axis < 2; axis++ ){
            (void) sprintf( buff, "mntkln%d", axis + 1 );
            new->minticklen[ axis ] = astReadDouble( channel, buff, AST__BAD );
            if ( TestMinTickLen( new, axis ) ) SetMinTickLen( new, axis,
                                                        new->minticklen[ axis ] );
         }
      }

/* Labelling. */
/* ---------- */
      text = astReadString( channel, "lbling", " " );
      if( strcmp( text, " " ) ) {
         new->labelling = FindString( 2, xlbling, text, 
                                      "the Plot component 'Lbling'", 
                                      "astRead", astGetClass( channel ) );
      } else {
         new->labelling = -9999;
      }
      if ( TestLabelling( new ) ) SetLabelling( new, new->labelling );

/* Edge(axis). */
/* ----------- */
      for( axis = 0; axis < 2; axis++ ){
         (void) sprintf( buff, "edge%d", axis + 1 );
         text = astReadString( channel, buff, " " );
         if( strcmp( text, " " ) ) {
            new->edge[ axis ] = FindString( 4, xedge, text, 
                                            "the Plot component 'Edge'", 
                                            "astRead", astGetClass( channel ) );
         } else {
            new->edge[ axis ] = -1;
         }
         if ( TestEdge( new, axis ) ) SetEdge( new, axis,
                                               new->edge[ axis ] );
      }

/* Now do instance variables which are not attributes. */
/* =================================================== */

/* Initialise the protected Ink attribute so that visible ink is used. */
      new->ink = -1;

/* The number of bounds supplied for the clipping volume. */
      new->clip_axes = astReadInt( channel, "clpaxs", 0 );
      if ( new->clip_axes < 0 ) new->clip_axes = 0;

/* The index of the clipping Frame within the Plot. */
      new->clip_frame = astReadInt( channel, "clpfrm", AST__NOFRAME );

/* If necessary, allocate memory to hold the bounds of the clipping volume. */
      if( new->clip_axes > 0 ){
         new->clip_lbnd = astMalloc( sizeof( double ) * (size_t) new->clip_axes );
         new->clip_ubnd = astMalloc( sizeof( double ) * (size_t) new->clip_axes );

/* If an error occurs, ensure that all allocated memory is freed. */
         if ( !astOK ) {
            new->clip_lbnd = (double *) astFree( (void *) new->clip_lbnd );
            new->clip_ubnd = (double *) astFree( (void *) new->clip_ubnd );

/* Otherwise, store the bounds. Use extreme defaults if no values are
   available. */
         } else {
            for( axis = 0; axis < new->clip_axes; axis++ ){
               (void) sprintf( buff, "clplb%d", axis + 1 );
               new->clip_lbnd[ axis ] = astReadDouble( channel, buff, -DBL_MAX );

               (void) sprintf( buff, "clpub%d", axis + 1 );
               new->clip_ubnd[ axis ] = astReadDouble( channel, buff, DBL_MAX );
            }
         }

/* If there are no clipping axes, store NULL pointers for the bounds
   arrays. */
      } else {
         new->clip_lbnd = NULL;
         new->clip_ubnd = NULL;
      }

/* The bounds of the plotting area. */   
      new->xlo = astReadDouble( channel, "xlo", 0.0 );
      new->xhi = astReadDouble( channel, "xhi", 1.0 );
      new->ylo = astReadDouble( channel, "ylo", 0.0 );
      new->yhi = astReadDouble( channel, "yhi", 1.0 );

/* Axis reversal flags. */
      new->xrev = astReadInt( channel, "xrev", 0 );
      new->yrev = astReadInt( channel, "yrev", 0 );

/* If an error occurred, clean up by deleting the new Plot. */
      if ( !astOK ) new = astDelete( new );
   }

/* Return the new Plot pointer. */
   return new;
}

/* Virtual function interfaces. */
/* ============================ */
/* These provide the external interface to the virtual functions defined by
   this class. Each simply checks the global error status and then locates and
   executes the appropriate member function, using the function pointer stored
   in the object's virtual function table (this pointer is located using the
   astMEMBER macro defined in "object.h").
    Note that the member function may not be the one defined here, as it may
   have been over-ridden by a derived class. However, it should still have the
   same interface. */

int astBorder_( AstPlot *this ){
   if( !astOK ) return 0;
   return (**astMEMBER(this,Plot,Border))(this);
}

void astClip_( AstPlot *this, int iframe, const double lbnd[], const double ubnd[] ){
   if( !astOK ) return;
   (**astMEMBER(this,Plot,Clip))(this,iframe,lbnd,ubnd);
}

void astGrid_( AstPlot *this ){
   if( !astOK ) return;
   (**astMEMBER(this,Plot,Grid))(this);
}

int astCvBrk_( AstPlot *this, int ibrk, double *brk, double *vbrk,
                   double *len ){
   if( !astOK ) return 0;
   return (**astMEMBER(this,Plot,CvBrk))(this,ibrk,brk,vbrk,len);
}

void astMark_( AstPlot *this, int nmark, int ncoord, int indim,
               const double (*in)[], int type ) {
   if ( !astOK ) return;
   (**astMEMBER(this,Plot,Mark))( this, nmark, ncoord, indim, in, type );
}

void astText_( AstPlot *this, const char *text, const double pos[], 
               const float up[2], const char *just ){
   if ( !astOK ) return;
   (**astMEMBER(this,Plot,Text))( this, text, pos, up, just );
}

void astGridLine_( AstPlot *this, int axis, const double start[], double length ){
   if( !astOK ) return;
   (**astMEMBER(this,Plot,GridLine))(this,axis,start,length);
}

void astCurve_( AstPlot *this, const double start[], const double finish[] ){
   if( !astOK ) return;
   (**astMEMBER(this,Plot,Curve))(this,start,finish);
}

void astPolyCurve_( AstPlot *this, int npoint, int ncoord, int dim, 
                    const double (*in)[] ){
   if( !astOK ) return;
   (**astMEMBER(this,Plot,PolyCurve))(this,npoint,ncoord,dim,in);
}

/* Special public interface functions. */
/* =================================== */
/* These provide the public interface to certain special functions
   whose public interface cannot be handled using macros (such as
   astINVOKE) alone. In general, they are named after the
   corresponding protected version of the function, but with "Id"
   appended to the name. */

/* Special interface function implementations. */
/* ------------------------------------------- */
AstPlot *astPlotId_( void *frame_void, const float graphbox[4], 
                     const double basebox[4], const char *options, ... ) {
/*
*++
*  Name:
c     astPlot
f     AST_PLOT

*  Purpose:
*     Create a Plot.

*  Type:
*     Public function.

*  Synopsis:
c     #include "plot.h"
c     AstPlot *astPlot( AstFrame *frame, const float graphbox[ 4 ], 
c                       const double basebox[ 4 ], const char *options, ... ) 
f     RESULT = AST_PLOT( FRAME, GRAPHBOX, BASEBOX, OPTIONS, STATUS )

*  Class Membership:
*     Plot constructor.

*  Description:
*     This function creates a new Plot and optionally initialises its
*     attributes.
*
*     A Plot is a specialised form of FrameSet, in which the base
*     Frame describes a "graphical" coordinate system and is
*     associated with a rectangular plotting area in the underlying
*     graphics system. This plotting area is where graphical output
*     appears. It is defined when the Plot is created.
*
*     The current Frame of a Plot describes a "physical" coordinate
*     system, which is the coordinate system in which plotting
*     operations are specified. The results of each plotting operation
*     are automatically transformed into graphical coordinates so as
*     to appear in the plotting area (subject to any clipping which
*     may be in effect).
*
*     Because the Mapping between physical and graphical coordinates
*     may often be non-linear, or even discontinuous, most plotting
*     does not result in simple straight lines. The basic plotting
*     element is therefore not a straight line, but a geodesic curve
c     (see astCurve). A Plot also provides facilities for drawing
c     markers or symbols (astMark), text (astText) and grid lines
c     (astGridLine). It is also possible to draw curvilinear axes with
c     optional coordinate grids (astGrid).
f     (see AST_CURVE). A Plot also provides facilities for drawing
f     markers or symbols (AST_MARK), text (AST_TEXT) and grid lines
f     (AST_GRIDLINE). It is also possible to draw curvilinear axes
f     with optional coordinate grids (AST_GRID).
*     A range of Plot attributes is available to allow precise control
*     over the appearance of graphical output produced by these
c     functions.
f     routines.
*
*     You may select different physical coordinate systems in which to
*     plot (including the native graphical coordinate system itself)
*     by selecting different Frames as the current Frame of a Plot,
*     using its Current attribute.  You may also set up clipping (see
c     astClip) to limit the extent of any plotting you perform, and
f     AST_CLIP) to limit the extent of any plotting you perform, and
*     this may be done in any of the coordinate systems associated
*     with the Plot, not necessarily the one you are plotting in.
*
*     Like any FrameSet, a Plot may also be used as a Frame. In this
*     case, it behaves like its current Frame, which describes the
*     physical coordinate system.
*
*     When used as a Mapping, a Plot describes the inter-relation
*     between graphical coordinates (its base Frame) and physical
*     coordinates (its current Frame).  It differs from a normal
*     FrameSet, however, in that an attempt to transform points which
*     lie in clipped areas of the Plot will result in bad coordinate
*     values (AST__BAD).

*  Parameters:
c     frame
f     FRAME = INTEGER (Given)
*        Pointer to a Frame describing the physical coordinate system
*        in which to plot. A pointer to a FrameSet may also be given,
*        in which case its current Frame will be used to define the
*        physical coordinate system and its base Frame will be mapped
*        on to graphical coordinates (see below).
*
*        If a null Object pointer (AST__NULL) is given, a default
*        2-dimensional Frame will be used to describe the physical
*        coordinate system. Labels, etc. may then be attached to this
*        by setting the appropriate Frame attributes
*        (e.g. Label(axis)) for the Plot.
c     graphbox
f     GRAPHBOX( 4 ) = REAL (Given)
*        An array giving the position and extent of the plotting area
*        (on the plotting surface of the underlying graphics system)
*        in which graphical output is to appear. This must be
*        specified using graphical coordinates appropriate to the
*        underlying graphics system.
*
*        The first pair of values should give the coordinates of the
*        bottom left corner of the plotting area and the second pair
*        should give the coordinates of the top right corner. The
*        coordinate on the horizontal axis should be given first in
*        each pair. Note that the order in which these points are
*        given is important because it defines up, down, left and
*        right for subsequent graphical operations.
c     basebox
f     BASEBOX( 4 ) = DOUBLE PRECISION (Given)
*        An array giving the coordinates of two points in the supplied
*        Frame (or in the base Frame if a FrameSet was supplied) which
*        correspond to the bottom left and top right corners of the
*        plotting area, as specified above. This range of coordinates
*        will be mapped linearly on to the plotting area. The
*        coordinates should be given in the same order as above.
c     options
f     OPTIONS = CHARACTER * ( * ) (Given)
c        Pointer to a null-terminated string containing an optional
c        comma-separated list of attribute assignments to be used for
c        initialising the new Plot. The syntax used is identical to
c        that for the astSet function and may include "printf" format
c        specifiers identified by "%" symbols in the normal way.
c        If no initialisation is required, a zero-length string may be
c        supplied.
f        A character string containing an optional comma-separated
f        list of attribute assignments to be used for initialising the
f        new Plot. The syntax used is identical to that for the
f        AST_SET routine. If no initialisation is required, a blank
f        value may be supplied.
c     ...
c        If the "options" string contains "%" format specifiers, then
c        an optional list of additional arguments may follow it in
c        order to supply values to be substituted for these
c        specifiers. The rules for supplying these are identical to
c        those for the astSet function (and for the C "printf"
c        function).
f     STATUS = INTEGER (Given and Returned)
f        The global status.

*  Returned Value:
c     astPlot()
f     AST_PLOT
*        A pointer to the new Plot.

*  Notes:
*     - The base Frame of the returned Plot will be a new Frame which
*     is created by this function to represent the coordinate system
*     of the underlying graphics system (graphical coordinates). It is
*     given a Frame index of 1 within the Plot. The choice of base
*     Frame (Base attribute) should not, in general, be changed once a
*     Plot has been created (although you could use this as a way of
*     moving the plotting area around on the plotting surface).
c     - If a Frame is supplied (via the "frame" pointer), then it
f     - If a Frame is supplied (via the FRAME pointer), then it
*     becomes the current Frame of the new Plot and is given a Frame
*     index of 2.
c     - If a FrameSet is supplied (via the "frame" pointer), then
f     - If a FrameSet is supplied (via the FRAME pointer), then 
*     all the Frames within this FrameSet become part of the new Plot
*     (where their Frame indices are increased by 1), with the
*     FrameSet's current Frame becoming the current Frame of the Plot.
*     - If a null Object pointer (AST__NULL) is supplied (via the
c     "frame" pointer), then the returned Plot will contain two
f     FRAME pointer), then the returned Plot will contain two
*     Frames, both created by this function. The base Frame will
*     describe graphics coordinates (as above) and the current Frame
*     will be a basic Frame with no attributes set (this will
*     therefore give default values for such things as the Plot Title
*     and the Label on each axis). Physical coordinates will be mapped
*     linearly on to graphical coordinates.
*     - An error will result if the Frame supplied (or the base Frame
*     if a FrameSet was supplied) is not 2-dimensional.
*     - A null Object pointer (AST__NULL) will be returned if this
c     function is invoked with the AST error status set, or if it
f     function is invoked with STATUS set to an error value, or if it
*     should fail for any reason.
*--

*  Implementation Notes:
*     - This function implements the external (public) interface to
*     the astPlot constructor function. It returns an ID value
*     (instead of a true C pointer) to external users, and must be
*     provided because astPlot_ has a variable argument list which
*     cannot be encapsulated in a macro (where this conversion would
*     otherwise occur).
*     - Because no checking or casting of arguments is performed
*     before the function is invoked, the "frame" parameter is of type
*     (void *) and is converted from an ID value to a pointer and
*     validated within the function itself.
*     - The variable argument list also prevents this function from
*     invoking astPlot_ directly, so it must be a
*     re-implementation of it in all respects, except for the
*     conversions between IDs and pointers on input/output of Objects.
*/

/* Local Variables: */
   AstFrame *frame;              /* Pointer to Frame structure */
   AstPlot *new;                 /* Pointer to new Plot */
   va_list args;                 /* Variable argument list */

/* Check the global status. */
   if ( !astOK ) return NULL;

/* Obtain a Frame pointer from any ID supplied and validate the
   pointer to ensure it identifies a valid Frame. */
   if( frame_void ){
      frame = astCheckFrame( astMakePointer( frame_void ) );
   } else {
      frame = NULL;
   }

/* Check the pointer can be used. */
   if ( astOK ) {

/* Initialise the Plot, allocating memory and initialising the
   virtual function table as well if necessary. */
      new = astInitPlot( NULL, sizeof( AstPlot ), !class_init,
                         &class_vtab, "Plot", frame, graphbox, 
                         basebox );

/* If successful, note that the virtual function table has been
   initialised. */
      if ( astOK ) {
         class_init = 1;

/* Obtain the variable argument list and pass it along with the
   options string to the astVSet method to initialise the new
   Plot's attributes. */

         va_start( args, options );
         astVSet( new, options, args );
         va_end( args );

/* If an error occurred, clean up by deleting the new object. */
         if ( !astOK ) new = astDelete( new );
      }
   }

/* Return an ID value for the new Plot. */
   return astMakeId( new );

}





