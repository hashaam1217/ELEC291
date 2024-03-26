/*
* ----------------------------------------------------------------------------
* THE COFFEEWARE LICENSEù (Revision 1
* <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a coffee in return.
* -----------------------------------------------------------------------------
* Please define your platform specific functions in this file ...
* -----------------------------------------------------------------------------
*/

#include <msp430.h>
#include <stdint.h>

/* ------------------------------------------------------------------------- */
void nrf24_setupPins()
{
	// Connect the MISO/MOSI/SCLK pins to the SPI module.
	P1SEL |= BIT5 + BIT6 + BIT7;
	P1SEL2 |= BIT5 + BIT6 + BIT7;

    // Using P1.0 for CSn.
	P1DIR |= BIT0;  // Configure P1.0 as output.
	P1OUT |= BIT0;  // Default to 1

    // Using P1.3 for CE.
	P1DIR |= BIT3;  // Configure P1.3 as output.
	P1OUT |= BIT3;  // Default to 1

}
/* ------------------------------------------------------------------------- */
void nrf24_ce_digitalWrite(uint8_t state)
{
    if(state)
    {
    	P1OUT |= BIT3;
    }
    else
    {
    	P1OUT &= ~BIT3;
    }
}
/* ------------------------------------------------------------------------- */
void nrf24_csn_digitalWrite(uint8_t state)
{
    if(state)
    {
    	P1OUT |= BIT0;
    }
    else
    {
    	P1OUT &= ~BIT0;
    }
}
/* ------------------------------------------------------------------------- */
void nrf24_sck_digitalWrite(uint8_t state)
{
    // Nothing to do.  The SPI hardware handles it.
}
/* ------------------------------------------------------------------------- */
void nrf24_mosi_digitalWrite(uint8_t state)
{
    // Nothing to do.  The SPI hardware handles it.
}
/* ------------------------------------------------------------------------- */
uint8_t nrf24_miso_digitalRead()
{
    // Nothing to do.  The SPI hardware handles it.
}
/* ------------------------------------------------------------------------- */
