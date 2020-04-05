/** This header includes specific datatypes for the project 
 * DO NOT include here the structures that form the DRE structure.
 * It also include definitions to be used within the project, like specific 
 * constant values or macros */
#ifndef _PRJ_TYPES
#define _PRJ_TYPES

/* Headers helper, include other type definition headers to spread them globally */
#include <Arduino.h>
#include <gttc_timer.h>
/* Basic types constants convention definition */
#define TRUE true
#define FALSE false

/* Commonly used macros */
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

/**
 * A t_tbd type to easily define structures when the type is not clear and braking the compilation
 * is stopping the project.
 * It is easier in a code review to search t_tbd string than to review all the variable types
 * to know if they are consistent or to find all the cases the code has been commented out or 
 * wiped using #define 0 clauses
 */

typedef uint16_t t_tbd;

#endif /* _PRJ_TYPES */
