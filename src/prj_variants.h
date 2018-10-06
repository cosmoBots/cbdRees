#ifndef _PRJ_VARIANTS_H
#define _PRJ_VARIANTS_H

/**
 Definitions of variant identifiers
 */

#define CFG_VARIANT_ZERO 0
#define CFG_VARIANT_ONE 1
#define CFG_VARIANT_TWO 2

#ifndef CFG_VARIANT
//#define CFG_VARIANT CFG_VARIANT_TESTBOX
//#define CFG_VARIANT CFG_VARIANT_SCALEMODEL
#define CFG_VARIANT CFG_VARIANT_ZERO
#endif

#if (CFG_VARIANT == CFG_VARIANT_ZERO)
/**
 Configuration for variant zero
 */

#elif (CFG_VARIANT == CFG_VARIANT_ONE)
/**
 Configuration for variant one
 */

#elif (CFG_VARIANT == CFG_VARIANT_TWO)
/**
 Configuration for variant two
 */
#else

#error "prj_variants.h: no variant defined"

#endif


#endif /* _PRJ_VARIANTS_H */
