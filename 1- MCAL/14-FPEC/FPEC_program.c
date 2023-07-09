/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    21 MARCH 2023	    	        		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 FPEC									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/********************************************************************************************/
/* Include libraries                                                                        */
/********************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "FPEC_private.h"
#include "FPEC_config.h"
#include "FPEC_interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                  Global Variables
----------------------------------------------------------------------------------------------------
*/


/*
----------------------------------------------------------------------------------------------------
!-                                FPEC  Function  PROGRAM
----------------------------------------------------------------------------------------------------
*/

void FPEC_voidInit(void)
{
    /** @defrgroup: FPEC_LATENCY */
    FPEC->ACR = FPEC_LATENCY;
}/** @end FPEC_voidInit */

/**
 *-- Programming procedure:
 * - Unlock the FPEC.
 * - Read the CR "LOCK" Flag. (LOCK == 0)
 * - Async checking if "BSY" in SR (BSY == 0)
 * - Set the "PG" in CR.
 * - Write "half word" to the address.
 * - Async checking if "BSY" in SR (BSY == 0)
 * - Data validation.
 * - Lock the FPEC.
 */
u8
FPEC_u8WriteFlash(u32 Copy_u32MemoryAddress,
                    u16 *Address_u16Data,
                    u16 Copy_u16DataLength)
{
    u8 L_ENThisFunctionErrorState = FLASH_WRITE_OK;

    /* Unlock the flash access */
    if( (1 == BIT_GET(FPEC->CR, LOCK)) )
    {
        FPEC->KEYR = FPEC_ACCESS_KEY1;
        FPEC->KEYR = FPEC_ACCESS_KEY2;
    }else {;}

    /* Check if the flash busy */
    while( (1 == BIT_GET(FPEC->SR, BSY)) ) {;}

    /* Start writing the data */
		u16 DataCounter = 0;
    for(; (DataCounter < Copy_u16DataLength); ++DataCounter)
    {
        /* Enable flash programming */
        BIT_SET(FPEC->SR, PG);

        /* Write to the address */
        WRT_MEM16(Copy_u32MemoryAddress, Address_u16Data[DataCounter]);
        Copy_u32MemoryAddress += 2; /* To the next address */

        /* Check if the flash busy */
        while( (1 == BIT_GET(FPEC->SR, BSY)) ) {;}

        /* Validate the data */
        if( (DATA_ASSERT(Copy_u32MemoryAddress, Address_u16Data[DataCounter])) )
        {
            /* Error handle */
            L_ENThisFunctionErrorState = NOK;
        }else{;}

        /* Reset the End Of Programming Flag */
        BIT_SET(FPEC->SR, EOP);
        /* Disable flash programming */
        BIT_CLR(FPEC->SR, PG);
    }

    return L_ENThisFunctionErrorState;
}/** FPEC_voidWriteFlash */

/**
 *-- Erasing Page procedure:
 * - Unlock the FPEC.
 * - Read the CR "LOCK" Flag. (LOCK == 0)
 * - Async checking if "BSY" in SR (BSY == 0)
 * - Set the "PER" in CR.
 * - Select the page to erase in AR.
 * - Set the "STRT" bit in CR.
 * - Async checking if "BSY" in SR (BSY == 0)
 * - Validate the erasing. //-->TODO
 * - Lock the FPEC.
 */
u8
FPEC_u8FlashPageErase(u8 Copy_u8PageNumber)
{
    u8 L_ENThisFunctionErrorState = PAGE_ERASE_OK;

    /* Unlock the flash access */
    if( (1 == BIT_GET(FPEC->CR, LOCK)) )
    {
        FPEC->KEYR = FPEC_ACCESS_KEY1;
        FPEC->KEYR = FPEC_ACCESS_KEY2;
    }else {;}

    /* Check if the flash busy */
    while( (1 == BIT_GET(FPEC->SR, BSY)) ) {;}

    /* Set the Page Erase Bit */
    BIT_SET(FPEC->CR, PER);

    /* Set the page address to be erased */
    FPEC->AR = (u32) (Copy_u8PageNumber * MEM_PAGE_SIZE) + FLASH_MEM_START_ADDRESS;

    /* Start the erasing */
    BIT_SET(FPEC->CR, STRT);

    /* Check if the flash busy */
    while( (1 == BIT_GET(FPEC->SR, BSY)) ) {;}

    /* Reset the End Of Programming Flag */
    BIT_SET(FPEC->SR, EOP);
    /* Disable flash programming */
    BIT_CLR(FPEC->SR, PG);

    return L_ENThisFunctionErrorState;
}/** @end FPEC_voidFlashPageErase */

/**
 *-- Erasing MASS procedure:
 * - Unlock the FPEC.
 * - Read the CR "LOCK" Flag. (LOCK == 0)
 * - Async checking if "BSY" in SR (BSY == 0)
 * - Set the "MER" in CR.
 * - Set the "STRT" bit in CR.
 * - Async checking if "BSY" in SR (BSY == 0)
 * - Validate the erasing. //-->TODO
 * - Lock the FPEC.
 */
u8
FPEC_u8FlashMassErase(void)
{
    u8 L_ENThisFunctionErrorState = MASS_ERASE_OK;

    /* Unlock the flash access */
    if( (1 == BIT_GET(FPEC->CR, LOCK)) )
    {
        FPEC->KEYR = FPEC_ACCESS_KEY1;
        FPEC->KEYR = FPEC_ACCESS_KEY2;
    }else {;}

    /* Check if the flash busy */
    while( (1 == BIT_GET(FPEC->SR, BSY)) ) {;}

    /* Set the Page Erase Bit */
    BIT_SET(FPEC->CR, MER);

    /* Start the erasing */
    BIT_SET(FPEC->CR, STRT);

    /* Check if the flash busy */
    while( (1 == BIT_GET(FPEC->SR, BSY)) ) {;}

    /* Reset the End Of Programming Flag */
    BIT_SET(FPEC->SR, EOP);
    /* Disable flash programming */
    BIT_CLR(FPEC->SR, PG);

    return L_ENThisFunctionErrorState;
}/** @end FPEC_voidFlashMassErase */

/*
----------------------------------------------------------------------------------------------------
!-                                  FPEC Function  PRIVATE
----------------------------------------------------------------------------------------------------
*/

