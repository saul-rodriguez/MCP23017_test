#ifndef MCP23017_ISR_H
#define MCP23017_ISR_H

#include "mcp23017.h"

extern Mcp23017* p_extender_1;

void extender1_isrA(void);
void extender1_isrB(void);
void setupMcp23017_isr_ext1(Mcp23017* pMcp23017);


#endif // MCP23017_ISR_H
