/** *****************************************************************************
 * \file    flash.c
 * \brief   MCU flash configuration
 *
 * \section AUTHOR
 *    1. Dominik Beinlich
 *
 * \section SVN
 *  $Date$
 *  $Author$
 *  $Revision$
 *
 * \section LICENSE
 * Copyright (c) 2016 Delta Electronics (Hangzhou Design Center & Thailand)
 * All rights reserved.
 ***************************************************************************** */

/*******************************************************************************
 * Included header
 ******************************************************************************/

#include "StdPeriphDriver.h"
#include "global.h"
#include "debug_llc.h"

/* Module header */
#define FLASH_EXPORT_H
  #include "flash_api.h"
  #include "flash_scb.h"
  #include "flash_cfg.h"
  #include "flash_scfg.h"
  #include "flash_conf.h"

/*******************************************************************************
 * Local data (private to module)
 ******************************************************************************/

__IO uint32 FLASH_mg_u32Offset = 0U;

/*******************************************************************************
 * Local function prototypes (private to module)
 ******************************************************************************/
static uint8 mg_u8MemoryWr(uint32 addr, uint8* Buff, uint32 len);

__IO uint32_t  Reset_Handle_Point[2] __attribute__((at(0x08000000))) = {0x200007F0,0x080031AD};//{SP, Reset Point}

const uint8 u8BootLoaderRev[16] __attribute__((at(0x08003000))) = { \
  'E', 'C', 'D', '1', '6', '0','2', '0', '1','0', '7', 0x20, 'X','X', 'X', 'X'};

/*******************************************************************************
 * Global functions (public to other modules)
 ******************************************************************************/

/** *****************************************************************************
 * \brief         Init function
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
void FLASH_vInit(void)
{

}

/** *****************************************************************************
 * \brief         De-init function
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
void FLASH_vDeInit(void)
{

}

/** *****************************************************************************
 * \brief         Read flash address of boot loader existing flag
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
uint8 FLASH_u8ReadBlExistFlg(void)
{
  /* Read the flag from address and compare with flag key */
  if (MG_BL_EXISTING_FLG == FLASH_vReadWordFlash(MG_BL_EXISTING_ADDR))
  {
    /* BL existing flag is true */
    return TRUE;
  }
  else
  {
    /* BL existing flag is false */
    return FALSE;
  }
}

/** *****************************************************************************
 * \brief         Write flash address of firmware upgrade flag
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
void FLASH_vWriteUpgradeFlg(void)
{
  /* Write the flag to address*/
  (void)FLASH_u8WriteWordFlash(MG_FW_UPGRADE_FLG_ADDR,MG_FW_UPGRADE_FLG);
}

/** *****************************************************************************
 * \brief         Read flash address of boot loader firmware version
 *
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        -
 *
 ***************************************************************************** */
uint32 FLASH_u32ReadBlFwVer(void)
{
  /* Read the flag from address and compare with flag key */
  return FLASH_vReadWordFlash(MG_BL_FW_REV_ADDR);
}

/** *****************************************************************************
 * \brief         Memory write routine for application data
 *                RTE_FLG_MOD_OK if operation is successeful, else RTE_FLG_MOD_FAIL
 * \param[in]     Buffer data to write, length of data to write
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        MOD ok/fail flag
 *
 ***************************************************************************** */
uint8 FLASH_u8AppWr32(uint8* Buff, uint32 size)
{
  __IO uint32 phyAddr;

  phyAddr = (uint32)FLASH_mg_u32Offset + MG_APP_START_ADDR;

  FLASH_Unlock();

  /* Erase page if needded */
  if ((phyAddr & (MG_PAGE_SIZE - 1U)) == 0U)
  {
    /* Erase page */
    if (FLASH_ErasePage((uint32)phyAddr) != FLASH_COMPLETE)
    return FLG_MOD_FAIL;
  }

  if (mg_u8MemoryWr(phyAddr, Buff, size) != FLG_MOD_OK)
  {
    return FLG_MOD_FAIL;
  }

  FLASH_Lock();
  return FLG_MOD_OK;
}

/** *****************************************************************************
 * \brief         Memory write routine for application data
 *                RTE_FLG_MOD_OK if operation is successeful, else RTE_FLG_MOD_FAIL
 * \param[in]     Buffer data to write, length of data to write
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        MOD ok/fail flag
 *
 ***************************************************************************** */
uint8 FLASH_u8AppWr(uint32 u32phyAddr,uint8* Buff, uint32 size)
{
  FLASH_Unlock();

  if (mg_u8MemoryWr(u32phyAddr, Buff, size) != FLG_MOD_OK)
  {
    return FLG_MOD_FAIL;
  }

  FLASH_Lock();
  return FLG_MOD_OK;
}

/** *****************************************************************************
 * \brief         Read half word (16bit) from memory address
 *
 * \param[in]     Address
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        16bit value from address
 *
 ***************************************************************************** */
uint16 FLASH_vReadHalfWordFlash(uint32 u32Addr)
{
  uint16 u16Tmp;
  /* Create pointer and load pointer with address */
  uint8* pu8Addr = (uint8*)u32Addr;
  /* Get lower 8bit */
  u16Tmp = *pu8Addr;
  /* Increase address */
  pu8Addr++;
  /* Get higher 8bit and combine to int16 */
  u16Tmp = (*pu8Addr << 8) | (u16Tmp);
  /* Return read value */
  return u16Tmp;
}

/** *****************************************************************************
 * \brief         Read word (32bit) from memory address
 *
 * \param[in]     Address
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        32bit value from address
 *
 ***************************************************************************** */
uint32 FLASH_vReadWordFlash(uint32 u32Addr)
{
  uint32 u32Tmp;
  uint8* pu8Addr;
  /* Create pointer and load pointer with address */
  for (pu8Addr = (uint8*)u32Addr + 3; (uint8*)u32Addr <= pu8Addr; pu8Addr--)
  {
    u32Tmp = (u32Tmp << 8) | (*pu8Addr);
  }
  /* Return read value */
  return u32Tmp;
}

/** *****************************************************************************
 * \brief         Memory write of 16bit data to address
 *
 * \param[in]     Address, Data
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        MOD ok/fail flag
 *
 ***************************************************************************** */
uint8 FLASH_u8WriteHalfWordFlash(uint32 u32Addr, uint16 u16Data)
{
  uint8 u8Status = FLG_MOD_OK;
  /* Unlock flash for write/erase operation */
  FLASH_Unlock();

  /* Write 32bit flag to memory */
  if (FLASH_ProgramHalfWord(u32Addr, u16Data) != FLASH_COMPLETE)
  {
    /* Error occurred while write operation */
    FLASH_Lock();
    return FLG_MOD_FAIL;
  }

  /* Lock flash for protection */
  FLASH_Lock();
  /* Return status */
  return u8Status;
}

/** *****************************************************************************
 * \brief         Memory write of 32bit data to address
 *
 * \param[in]     Address, Data
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        MOD ok/fail flag
 *
 ***************************************************************************** */
uint8 FLASH_u8WriteWordFlash(uint32 u32Addr, uint32 u32Data)
{
  uint8 u8Status = FLG_MOD_OK;
  /* Unlock flash for write/erase operation */
  FLASH_Unlock();

  /* Write 32bit flag to memory */
  if (FLASH_ProgramWord(u32Addr, u32Data) != FLASH_COMPLETE)
  {
    /* Error occurred while write operation */
    FLASH_Lock();
    return FLG_MOD_FAIL;
  }

  /* Lock flash for protection */
  FLASH_Lock();
  /* Return status */
  return u8Status;
}

/** *****************************************************************************
 * \brief         Erase one page of the memory
 *                The address has to be the start address of the page (multiples of 2048byte)
 * \param[in]     -
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        MOD ok/fail flag
 *
 ***************************************************************************** */
uint8 FLASH_u8ErasePageFlash(uint32 u32Addr)
{
  uint8 u8Status = FLG_MOD_OK;
  /* Unlock flash for write/erase operation */
  FLASH_Unlock();

  /* Erase reserved page */
  if (FLASH_ErasePage(u32Addr) != FLASH_COMPLETE)
  {
    /* Error occurred while page erase */
    FLASH_Lock();
    u8Status = FLG_MOD_FAIL;
  }
  
  /* Lock flash for protection */
  FLASH_Lock();
  /* Return status */
  return u8Status;
}

/*******************************************************************************
 * Local functions (privat for module)
 ******************************************************************************/

/** *****************************************************************************
 * \brief         Memory write
 *                RTE_FLG_MOD_OK if operation is successeful, else RTE_FLG_MOD_FAIL
 * \param[in]     Address, buffer data to write, length of data to write
 * \param[in,out] -
 * \param[out]    -
 *
 * \return        MOD ok/fail flag
 *
 ***************************************************************************** */
static uint8 mg_u8MemoryWr(uint32 addr, uint8* Buff, uint32 len)
{
  uint32 size = len & 0x3, idx;

  if (size)
  {
    for (idx = len; idx < ((len & 0xFFFC) + 4); idx++)
    {
      Buff[idx] = 0xFF;
    }
  }

  for (idx = 0; idx < len; idx = idx + 4)
  {
    while (FLASH_ProgramWord(addr, *(uint32*)(Buff + idx)) != FLASH_COMPLETE)
    {
      //return FLG_MOD_FAIL;
    }
    addr += 4;
  }
  
  return FLG_MOD_OK;
}

/*
 * End of file
 */
