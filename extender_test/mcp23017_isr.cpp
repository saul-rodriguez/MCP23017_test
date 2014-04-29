#include "mcp23017_isr.h"

#include "mcp23017.h"
#include <wiringPi.h>
#include "hardware_conf.h"

Mcp23017* p_extender_1;

/*
 * Function: setupMcp23017_isr_1
 *-------------------------------
 * Configures the interrupt service routine. First, it registers an Mcp23017 object.
 * This object will be tied to the interrupt. Then it calls the setISR public function
 * which setups the pins that are going to be used as interrupts. This is done by
 * using the INTA_PINS constant which should be degined in the hardware_conf.h file.
 * Finally, it assings an input pin from the Raspberry to an interrupt function.
 * This pin is MCP23017_INTA and must be also defined in hardware_conf.
 */

void setupMcp23017_isr_ext1(Mcp23017* pMcp23017)
{
    p_extender_1 = pMcp23017;

    p_extender_1->setISR(PORTA,INTA_PINS); //Only PORTA configured!
    p_extender_1->setISR(PORTB,INTB_PINS); //Only PORTB configured!

    //Wire MCP interrupt pin in the raspberry to a function
    wiringPiISR(MCP23017_INTA, INT_EDGE_FALLING, &extender1_isrA); //Only INTA configured!
    wiringPiISR(MCP23017_INTB, INT_EDGE_FALLING, &extender1_isrB); //Only INTA configured!

    p_extender_1->readPort(PORTA); // Dummy read to reset any glitch interrupt during setup
    p_extender_1->readPort(PORTB); // Dummy read to reset any glitch interrupt during setup

    p_extender_1->porta = p_extender_1->readPort(PORTA); // Dummy read to reset any glitch interrupt during setup
    p_extender_1->portb =p_extender_1->readPort(PORTB); // Dummy read to reset any glitch interrupt during setup
}

/*
 * Function extender1_isr
 * ----------------------
 * This function is the interrupt service routing that is triggered when INTA signal
 * is activated. It calls the virtual function ISR.
 */

void extender1_isrA(void)
{
    int change;

    change = p_extender_1->ISRA();

    //qDebug("extender1_isr");
    //Here glue your logic
}

void extender1_isrB(void)
{
    int change;

    change = p_extender_1->ISRB();

    //qDebug("extender2_isr called");
    //Here glue your logic
}
