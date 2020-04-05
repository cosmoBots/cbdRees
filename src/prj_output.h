/**
 * This code implements the typical and simple task of writing 
 * the output to the ports, using the values storedat the DRE
 * for normal output flows
 */
#ifndef _PRJ_OUTPUT_H
#define _PRJ_OUTPUT_H

/* Initialization of output flows */
void prjOutputInit(void);
/* Spin function to write output flows */
void prjOutput(void);

#endif /* _PRJ_OUTPUT_H */
