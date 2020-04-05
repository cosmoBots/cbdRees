/**
 * This header file allows to compile the same project with different
 * variants or flavours.  This file will drive the prj_cfg.h parameters
 * setting specific configuration for each variant
 */ 

#ifndef _PRJ_VARIANTS_H
#define _PRJ_VARIANTS_H

/**
 Definitions of variant identifiers
 */

#define CFG_VARIANT_ZERO 0
#define CFG_VARIANT_ONE 1
#define CFG_VARIANT_TWO 2

/**
 * Select the active variant for this compilation
 */
#define CFG_VARIANT CFG_VARIANT_ZERO
//#define CFG_VARIANT CFG_VARIANT_ONE
//#define CFG_VARIANT CFG_VARIANT_TWO

/** 
 * Default variant if not selected 
 * */
#ifndef CFG_VARIANT
#define CFG_VARIANT CFG_VARIANT_ZERO
#endif

#if (CFG_VARIANT == CFG_VARIANT_ZERO)
/**
 Specific configuration for variant zero
 This configuration will drive the prj_config.h parameters
 */

#elif (CFG_VARIANT == CFG_VARIANT_ONE)
/**
 Specific configuration for variant one
 This configuration will drive the prj_config.h parameters
 */

#elif (CFG_VARIANT == CFG_VARIANT_TWO)
/**
 Specific configuration for variant two
 This configuration will drive the prj_config.h parameters
 */
#else

#error "prj_variants.h: no variant defined"

#endif


#endif /* _PRJ_VARIANTS_H */
