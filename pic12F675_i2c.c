/*******************************************************************************
 Project: I2C protocol for PIC12F675
 File: pic12f675_i2c.h
 Developed by: Nelson Rossi Bittencourt
 Last updated: 19/03/2025
********************************************************************************/

#include <xc.h>    
#include "pic12F675_i2c.h"

// I2C pins configuration
void init_i2c()
{
    scl_high();     // scl on tri-state
    sda_high();     // sda on tri-state
}


// Sends start (S) command
void start_i2c()
{    
    scl_high();                     // SCL on tri-state
    sda_high();                     // SDA on tri-state
    
    sda_low();                      // SDA low
    __delay_us(I2C_SDelay);         // Short delay
    scl_low();                      // SCL low
    __delay_us(I2C_SDelay);  
}

// Sends stop (P) command
void stop_i2c()
{       
    scl_high();
    sda_low();
    __delay_us(I2C_SDelay);  
    sda_high();
}

// Writes a byte to I2C bus. Returns ack/nack from slave.
char write_i2c(uint8_t data)
{
    char mask = 0x80;           // Mask to select bits
    char ret = 0;               // Initial value = 0 -> nack from slave
    
    do
	{      
        if(mask & data)         // Changes SDA state for each data bit
            sda_high();
		else
            sda_low();
                        
        scl_high();                  
        __delay_us(I2C_LDelay); // Long delay        
      
        scl_low();              
        __delay_us(I2C_LDelay);         
        mask >>= 1;				// Updates mask
    }
	while(mask > 0);
          
    scl_high();                  
    __delay_us(I2C_LDelay);             
   
    sda_high();                       
    __delay_us(I2C_SDelay);                      
    
    if(SDA_STATE) ret = 1;      // if SDA_STATE is high, ack else nack
                             
    scl_low();                      
    __delay_us(I2C_LDelay);             
    
    sda_low();                      
    __delay_us(I2C_SDelay);        
    
    return(ret);                        // return ack(1) or nack(0)                                            
}

// Sets SCL to low level
void scl_low(void)
{
    SCL_TRIS = 0;
    SCL_STATE = 0;
}

// Sets SCL in tri-state (high level by pull-ups in I2C bus)
void scl_high(void)
{
    SCL_TRIS = 1;
}

// Sets SDA to low level
void sda_low(void)
{
    SDA_TRIS=0;
    SDA_STATE = 0;
}

// Sets SDA in tri-state (high level by pull-ups in I2C bus)
void sda_high(void)
{
    SDA_TRIS = 1;
}