/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * u1ld_custom_mipi.c
 *
 * Project:
 * --------
 * MT6290
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *

/*===============================================================================*/

#include "kal_general_types.h"
#include "ul1d_custom_mipi.h"
#include "ul1d_custom_rf.h"
#include "mml1_custom_mipi.h"
#include "ul1d_rf_public.h"

/*===============================================================================*/

//#define MIPI_INITIAL_CW_NUM 0
#if (IS_3G_MIPI_SUPPORT)


UL1_MIPI_DATA_TABLE_T UMTS_MIPI_INITIAL_CW[MIPI_MAX_INITIAL_IMM_BSI_CW_NUM] =
{
   //elm type, port_sel     , data_seq, ,usid         , {addr, data}
   {UMTS_MIPI_END, 0, 0, 0,{0,0}}
};


UL1_MIPI_DATA_TABLE_T UMTS_MIPI_SLEEP_CW[MIPI_MAX_SLEEP_IMM_BSI_CW_NUM] =
{
   {UMTS_MIPI_END, 0, 0, 0,{0,0}}
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBandNone[UL1_MIPI_RX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ MIPI_NULL ,{ 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 1  */ MIPI_NULL ,{ 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 2  */ MIPI_NULL ,{ 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 3  */ MIPI_NULL ,{ 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 16 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 17 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 18 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 19 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 20 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 21 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 22 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 23 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};


UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand1[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ MIPI_ASM,  { 0    , 1    }, MIPI_TRX_ON, US2CHIPCNT(200)     },
   { /* 1  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 2  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 16 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 17 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 18 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 19 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 20 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 21 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 22 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 23 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};


UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand2[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ MIPI_ASM,  { 0    , 1    }, MIPI_TRX_ON, US2CHIPCNT(200)     },
   { /* 1  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 2  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 16 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 17 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 18 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 19 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 20 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 21 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 22 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 23 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand3[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ MIPI_ASM,  { 0    , 1    }, MIPI_TRX_ON, US2CHIPCNT(200)     },
   { /* 1  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 2  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 16 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 17 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 18 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 19 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 20 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 21 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 22 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 23 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};




UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand4[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ MIPI_ASM,  { 0    , 1    }, MIPI_TRX_ON, US2CHIPCNT(200)     },
   { /* 1  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 2  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 16 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 17 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 18 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 19 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 20 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 21 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 22 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 23 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};


UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand5[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ MIPI_ASM,  { 0    , 1    }, MIPI_TRX_ON, US2CHIPCNT(200)     },
   { /* 1  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 2  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 16 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 17 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 18 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 19 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 20 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 21 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 22 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 23 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand8[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ MIPI_ASM,  { 0    , 1    }, MIPI_TRX_ON, US2CHIPCNT(200)     },
   { /* 1  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 2  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 16 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 17 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 18 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 19 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 20 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 21 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 22 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 23 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand6[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand9[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand11[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand19[] = {{0}};


UL1_MIPI_EVENT_TABLE_T*  UMTS_MIPI_RX_EVENT_TABLE[] =
{
   M_UMTS_RX_EVENT(UMTSBandNone),             /*UMTSUMTSBandNone*/          
   M_UMTS_RX_EVENT(RX_HIGHBAND1_INDICATOR),   /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_RX_EVENT(RX_HIGHBAND2_INDICATOR),   /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_RX_EVENT(RX_HIGHBAND3_INDICATOR),   /*RX_HIGHBAND3_INDICATOR*/   
   M_UMTS_RX_EVENT(RX_LOWBAND1_INDICATOR),    /*RX_LOWBAND1_INDICATOR*/   
   M_UMTS_RX_EVENT(RX_LOWBAND2_INDICATOR),    /*RX_LOWBAND2_INDICATOR*/   
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBandNone[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data },{ sub 1 ,addr, data },{ sub 2 ,addr, data}, { sub 3, addr, data  }, { sub 4, addr data  } },
   { /* 0  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 1  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 2  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 3  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 4  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 5  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 6  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 18 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 19 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 20 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 21 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 22 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 23 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 24 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 25 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 26 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 27 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand1[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ MIPI_ASM,  UL1_MIPI_PORT1,  REG_W     , MIPI_USID_ASM0, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 1  */ MIPI_ASM,  UL1_MIPI_PORT1,  REG_W     , MIPI_USID_ASM0, { { 21124 ,{0x00, 0x0C}}, { 21262 ,{0x00, 0x0C}}, { 21400 ,{0x00, 0x0C}}, { 21538  ,{0x00, 0x0C}}, { 21676 ,{0x00, 0x0C}}} },
   { /* 2  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 3  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 4  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 5  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 6  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 18 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 19 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 20 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 21 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 22 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 23 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 24 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 25 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 26 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 27 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },

};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand2[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ MIPI_ASM,  UL1_MIPI_PORT1,  REG_W     , MIPI_USID_ASM0,  { { 19324 ,{0x1C, 0x38}}, { 19462 ,{0x1C, 0x38}}, { 19600 ,{0x1C, 0x38}}, { 19738  ,{0x1C, 0x38}}, { 19876 ,{0x1C, 0x38}}} },
   { /* 1  */ MIPI_ASM,  UL1_MIPI_PORT1,  REG_W     , MIPI_USID_ASM0,  { { 19324 ,{0x00, 0x04}}, { 19462 ,{0x00, 0x04}}, { 19600 ,{0x00, 0x04}}, { 19738  ,{0x00, 0x04}}, { 19876 ,{0x00, 0x04}}} },
   { /* 2  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 3  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 4  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 5  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 6  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 18 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 19 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 20 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 21 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 22 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 23 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 24 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 25 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 26 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 27 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
};


UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand3[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ MIPI_ASM,  UL1_MIPI_PORT0,  REG_W     , MIPI_USID_ASM0,  { { 18074 ,{0x1C, 0x38}}, { 18204 ,{0x1C, 0x38}}, { 18424 ,{0x1C, 0x38}}, { 18654  ,{0x1C, 0x38}}, { 18776  ,{0x1C, 0x38}}} },
   { /* 1  */ MIPI_ASM,  UL1_MIPI_PORT0,  REG_W     , MIPI_USID_ASM0,  { { 18074,{0x00, 0x02}}, { 18204,{0x00, 0x02}}, { 18424 ,{0x00, 0x02}}, { 18654  ,{0x00, 0x02}}, { 18776,{0x00, 0x02}}} },
   { /* 2  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 3  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 4  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 5  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 6  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 18 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 19*/ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 20*/ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 21*/ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 22 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 23 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 24 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 25*/ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 26 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },
   { /* 27 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 18074,{0x0, 0x0}},   { 18204 ,{0x0, 0x0}},   { 18424 ,{0x0, 0x0}},   { 18654 ,{0x0, 0x0}},   { 18776 ,{0x0,   0x0}}} },

};





UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand4[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ MIPI_ASM,  UL1_MIPI_PORT0,  REG_W     , MIPI_USID_ASM0,  { { 21124 ,{0x1C, 0x38}}, { 21227 ,{0x1C, 0x38}}, { 21330 ,{0x1C, 0x38}}, { 21428  ,{0x1C, 0x38}}, { 21526 ,{0x1C, 0x38}}} },
   { /* 1  */ MIPI_ASM,  UL1_MIPI_PORT0,  REG_W     , MIPI_USID_ASM0,  { { 21124 ,{0x00, 0x04}}, { 21227 ,{0x00, 0x04}}, { 21330 ,{0x00, 0x04}}, { 21428  ,{0x00, 0x04}}, { 21526 ,{0x00, 0x04}}} },
   { /* 2  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 3  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 4  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 5  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 6  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 18 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 19 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 20 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 21 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 22 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 23 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 24 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 25 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 26 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 27 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },

};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand5[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ MIPI_ASM,  UL1_MIPI_PORT1,  REG_W     , MIPI_USID_ASM0,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}} }},
   { /* 1  */ MIPI_ASM,  UL1_MIPI_PORT1,  REG_W     , MIPI_USID_ASM0,  { { 8714 ,{0x00, 0x0B}}, { 8764 ,{0x00, 0x0B}},   { 8815 ,{0x00, 0x0B}},  { 8865  ,{0x00, 0x0B}},   { 8916 ,{0x00, 0x0B}} }},
   { /* 2  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 3  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 4  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 5  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 6  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 18 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 19 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 20 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 21 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 22 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 23 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 24 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 25 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 26 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 27 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
};



UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand8[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ MIPI_ASM,  UL1_MIPI_PORT1,  REG_W     , MIPI_USID_ASM0,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}} }},
   { /* 1  */ MIPI_ASM,  UL1_MIPI_PORT1,  REG_W     , MIPI_USID_ASM0,  { { 9274 ,{0x00, 0x03}}, { 9349 ,{0x00, 0x03}},   { 9425 ,{0x00, 0x03}},  { 9500  ,{0x00, 0x03}},   { 9576 ,{0x00, 0x03}} }},
   { /* 2  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 3  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 4  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 5  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 6  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 18 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 19 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 20 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 21 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 22 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 23 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 24 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 25 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 26 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 27 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand6[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand9[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand11[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand19[] = {{0}};

UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_RX_DATA_TABLE[] = 
{
   M_UMTS_RX_DATA(UMTSBandNone),             /*UMTSUMTSBandNone*/          
   M_UMTS_RX_DATA(RX_HIGHBAND1_INDICATOR),   /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_RX_DATA(RX_HIGHBAND2_INDICATOR),   /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_RX_DATA(RX_HIGHBAND3_INDICATOR),   /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_RX_DATA(RX_LOWBAND1_INDICATOR),    /*RX_LOWBAND1_INDICATOR*/ 
   M_UMTS_RX_DATA(RX_LOWBAND2_INDICATOR),    /*RX_LOWBAND2_INDICATOR*/ 
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBandNone[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 1  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 2  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand1[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ MIPI_PA,   { 0    , 0   }, MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ MIPI_PA,   { 1    , 4   }, MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ MIPI_ASM,  { 5    , 6    }, MIPI_TRX_ON,     US2CHIPCNT(200) },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand2[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ MIPI_PA,   { 0    , 0   }, MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ MIPI_PA,   { 1    , 4   }, MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ MIPI_ASM,  { 5    , 6    }, MIPI_TRX_ON,     US2CHIPCNT(200) },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand3[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ MIPI_PA,   { 0    , 0   }, MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ MIPI_PA,   { 1    , 4   }, MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ MIPI_ASM,  { 5    , 6    }, MIPI_TRX_ON,     US2CHIPCNT(200) },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};



UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand4[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ MIPI_PA,   { 0    , 0   }, MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ MIPI_PA,   { 1    , 4   }, MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ MIPI_ASM,  { 5    , 6    }, MIPI_TRX_ON,     US2CHIPCNT(200) },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand5[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ MIPI_PA,   { 0    , 0   }, MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ MIPI_PA,   { 1    , 4   }, MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ MIPI_ASM,  { 5    , 6    }, MIPI_TRX_ON,     US2CHIPCNT(200) },
   { /* 3 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand8[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ MIPI_PA,   { 0    , 0   }, MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ MIPI_PA,   { 1    , 4   }, MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ MIPI_ASM,  { 5    , 6    }, MIPI_TRX_ON,     US2CHIPCNT(200) },
   { /* 3  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 4  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 5  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 6  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 7  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 8  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 9  */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 10 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 11 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 12 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 13 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 14 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
   { /* 15 */ MIPI_NULL, { 0    , 0    }, MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand6[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand9[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand11[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand19[] = {{0}};

UL1_MIPI_EVENT_TABLE_T*  UMTS_MIPI_TX_EVENT_TABLE[] =
{
   M_UMTS_TX_EVENT(UMTSBandNone),               /*UMTSUMTSBandNone*/          
   M_UMTS_TX_EVENT(RX_HIGHBAND1_INDICATOR),     /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_TX_EVENT(RX_HIGHBAND2_INDICATOR),     /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_TX_EVENT(RX_HIGHBAND3_INDICATOR),     /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_TX_EVENT(RX_LOWBAND1_INDICATOR),      /*RX_LOWBAND1_INDICATOR*/ 
   M_UMTS_TX_EVENT(RX_LOWBAND2_INDICATOR),      /*RX_LOWBAND2_INDICATOR*/ 
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBandNone[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 1  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 2  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 3  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 4  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 5  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 6  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL,  SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand1[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},
   { /* 1  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 2  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 19224 ,{0x01, 0x00}}, { 19362 ,{0x01, 0x00}}, { 19500 ,{0x01, 0x00}}, { 19638 ,{0x01, 0x00}}, { 19776 ,{0x01, 0x00}}}},
   { /* 3  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 19224 ,{0x02, 0x00}}, { 19362 ,{0x02, 0x00}}, { 19500 ,{0x02, 0x00}}, { 19638 ,{0x02, 0x00}}, { 19776 ,{0x02, 0x00}}}},
   { /* 4  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 19224 ,{0x03, 0x00}}, { 19362 ,{0x03, 0x00}}, { 19500 ,{0x03, 0x00}}, { 19638 ,{0x03, 0x00}}, { 19776 ,{0x03, 0x00}}}},
   { /* 5  */ MIPI_ASM , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_ASM0  , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},
   { /* 6  */ MIPI_ASM , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_ASM0  , { { 19224 ,{0x00, 0x0C}}, { 19362 ,{0x00, 0x0C}}, { 19500 ,{0x00, 0x0C}}, { 19638 ,{0x00, 0x0C}}, { 19776 ,{0x00, 0x0C}}}},
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
};



UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand2[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 18524 ,{0x1C, 0x38}}, { 18662 ,{0x1C, 0x38}}, { 18800 ,{0x1C, 0x38}}, { 18938 ,{0x1C, 0x38}}, { 19076 ,{0x1C, 0x38}} }},
   { /* 1  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 2  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 18524 ,{0x01, 0x00}}, { 18662 ,{0x01, 0x00}}, { 18800 ,{0x01, 0x00}}, { 18938 ,{0x01, 0x00}}, { 19076 ,{0x01, 0x00}} }},
   { /* 3  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 18524 ,{0x02, 0x00}}, { 18662 ,{0x02, 0x00}}, { 18800 ,{0x02, 0x00}}, { 18938 ,{0x02, 0x00}}, { 19076 ,{0x02, 0x00}} }},
   { /* 4  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 18524 ,{0x03, 0x00}}, { 18662 ,{0x03, 0x00}}, { 18800 ,{0x03, 0x00}}, { 18938 ,{0x03, 0x00}}, { 19076 ,{0x03, 0x00}} }},
   { /* 5  */ MIPI_ASM , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_ASM0  , { { 18524 ,{0x1C, 0x38}}, { 18662 ,{0x1C, 0x38}}, { 18800 ,{0x1C, 0x38}}, { 18938 ,{0x1C, 0x38}}, { 19076 ,{0x1C, 0x38}} }},
   { /* 6  */ MIPI_ASM , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_ASM0  , { { 18524 ,{0x00, 0x04}}, { 18662 ,{0x00, 0x04}}, { 18800 ,{0x00, 0x04}}, { 18938 ,{0x00, 0x04}}, { 19076 ,{0x00, 0x04}} }},
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
};




UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand3[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ MIPI_PA  , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_PA0   , { { 18074 ,{0x1C, 0x38}}, { 18204 ,{0x1C, 0x38}}, { 18424  ,{0x1C, 0x38}}, { 18654  ,{0x1C, 0x38}}, { 18776 ,{0x1C, 0x38}} }},
   { /* 1  */ MIPI_PA  , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_PA0   , { { 18074,{0x00, 0x00}}, { 18204 ,{0x00, 0x00}}, { 18424  ,{0x00, 0x00}}, { 18654  ,{0x00, 0x00}}, { 18776 ,{0x00, 0x00}} }},
   { /* 2  */ MIPI_PA  , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_PA0   , { { 18074 ,{0x01, 0x00}}, { 18204 ,{0x01, 0x00}}, { 18424  ,{0x01, 0x00}}, { 18654 ,{0x01, 0x00}}, { 18776 ,{0x01, 0x00}} }},
   { /* 3  */ MIPI_PA  , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_PA0   , { { 18074 ,{0x02, 0x00}}, { 18204,{0x02, 0x00}}, { 18424 ,{0x02, 0x00}}, { 18654 ,{0x02, 0x00}}, { 18776 ,{0x02, 0x00}} }},
   { /* 4  */ MIPI_PA  , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_PA0   , { { 18074 ,{0x03, 0x00}}, { 18204 ,{0x03, 0x00}}, { 18424  ,{0x03, 0x00}}, { 18654 ,{0x03, 0x00}}, { 18776,{0x03, 0x00}} }},
   { /* 5  */ MIPI_ASM , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_ASM0  , { { 18074 ,{0x1C, 0x38}}, { 18204 ,{0x1C, 0x38}}, { 18424  ,{0x1C, 0x38}}, { 18654  ,{0x1C, 0x38}}, { 18776,{0x1C, 0x38}} }},
   { /* 6  */ MIPI_ASM , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_ASM0  , { { 18074 ,{0x00, 0x02}}, { 18204,{0x00, 0x02}}, { 18424  ,{0x00, 0x02}}, { 18654  ,{0x00, 0x02}}, { 18776,{0x00, 0x02}} }},
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18074 ,{0x00, 0x00}}, { 18204 ,{0x00, 0x00}}, { 18424  ,{0x00, 0x00}}, { 18654  ,{0x00, 0x00}}, { 18776,{0x00, 0x00}} }},
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18074 ,{0x00, 0x00}}, { 18204 ,{0x00, 0x00}}, { 18424  ,{0x00, 0x00}}, { 18654  ,{0x00, 0x00}}, { 18776,{0x00, 0x00}} }},
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18074 ,{0x00, 0x00}}, { 18204,{0x00, 0x00}}, { 18424  ,{0x00, 0x00}}, { 18654  ,{0x00, 0x00}}, { 18776,{0x00, 0x00}} }},
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18074 ,{0x00, 0x00}}, { 18204,{0x00, 0x00}}, { 18424  ,{0x00, 0x00}}, { 18654  ,{0x00, 0x00}}, { 18776 ,{0x00, 0x00}} }},
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18074 ,{0x00, 0x00}}, { 18204,{0x00, 0x00}}, { 18424  ,{0x00, 0x00}}, { 18654  ,{0x00, 0x00}}, { 18776 ,{0x00, 0x00}} }},
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18074 ,{0x00, 0x00}}, { 18204 ,{0x00, 0x00}}, { 18424  ,{0x00, 0x00}}, { 18654 ,{0x00, 0x00}}, { 18776 ,{0x00, 0x00}} }},
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18074,{0x00, 0x00}}, { 18204 ,{0x00, 0x00}}, { 18424 ,{0x00, 0x00}}, { 18654  ,{0x00, 0x00}}, { 18776 ,{0x00, 0x00}} }},
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18074 ,{0x00, 0x00}}, { 18204,{0x00, 0x00}}, { 18424  ,{0x00, 0x00}}, { 18654  ,{0x00, 0x00}}, { 18776 ,{0x00, 0x00}} }},
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18074 ,{0x00, 0x00}}, { 18204,{0x00, 0x00}}, { 18424  ,{0x00, 0x00}}, { 18654  ,{0x00, 0x00}}, { 18776 ,{0x00, 0x00}} }},
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18074 ,{0x00, 0x00}}, { 18204 ,{0x00, 0x00}}, { 18424  ,{0x00, 0x00}}, { 18654 ,{0x00, 0x00}}, { 18776 ,{0x00, 0x00}} }},
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 18074,{0x00, 0x00}}, { 18204 ,{0x00, 0x00}}, { 18424 ,{0x00, 0x00}}, { 18654  ,{0x00, 0x00}}, { 18776 ,{0x00, 0x00}} }},
};



UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand4[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 17124 ,{0x1C, 0x38}}, { 17224 ,{0x1C, 0x38}}, { 17324 ,{0x1C, 0x38}}, { 17425 ,{0x1C, 0x38}}, { 17526 ,{0x1C, 0x38}} }},
   { /* 1  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 2  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 17124 ,{0x01, 0x00}}, { 17224 ,{0x01, 0x00}}, { 17324 ,{0x01, 0x00}}, { 17425 ,{0x01, 0x00}}, { 17526 ,{0x01, 0x00}} }},
   { /* 3  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 17124 ,{0x02, 0x00}}, { 17224 ,{0x02, 0x00}}, { 17324 ,{0x02, 0x00}}, { 17425 ,{0x02, 0x00}}, { 17526 ,{0x02, 0x00}} }},
   { /* 4  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 17124 ,{0x03, 0x00}}, { 17224 ,{0x03, 0x00}}, { 17324 ,{0x03, 0x00}}, { 17425 ,{0x03, 0x00}}, { 17526 ,{0x03, 0x00}} }},
   { /* 5  */ MIPI_ASM , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_ASM0  , { { 17124 ,{0x1C, 0x38}}, { 17224 ,{0x1C, 0x38}}, { 17324 ,{0x1C, 0x38}}, { 17425 ,{0x1C, 0x38}}, { 17526 ,{0x1C, 0x38}} }},
   { /* 6  */ MIPI_ASM , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_ASM0  , { { 17124 ,{0x00, 0x04}}, { 17224 ,{0x00, 0x04}}, { 17324 ,{0x00, 0x04}}, { 17425 ,{0x00, 0x04}}, { 17526 ,{0x00, 0x04}} }},
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
};



UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand5[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 1  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 2  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 8264 ,{0x01, 0x00}}, { 8314 ,{0x01, 0x00}}, { 8365 ,{0x01, 0x00}}, { 8415 ,{0x01, 0x00}}, { 8466 ,{0x01, 0x00}} }},
   { /* 3  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 8264 ,{0x02, 0x00}}, { 8314 ,{0x02, 0x00}}, { 8365 ,{0x02, 0x00}}, { 8415 ,{0x02, 0x00}}, { 8466 ,{0x02, 0x00}} }},
   { /* 4  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 8264 ,{0x03, 0x00}}, { 8314 ,{0x03, 0x00}}, { 8365 ,{0x03, 0x00}}, { 8415 ,{0x03, 0x00}}, { 8466 ,{0x03, 0x00}} }},
   { /* 5  */ MIPI_ASM , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_ASM0  , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 6  */ MIPI_ASM , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_ASM0  , { { 8264 ,{0x00, 0x0B}}, { 8314 ,{0x00, 0x0B}}, { 8365 ,{0x00, 0x0B}}, { 8415 ,{0x00, 0x0B}}, { 8466 ,{0x00, 0x0B}} }},
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
};


UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand8[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 1  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 2  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 8824 ,{0x01, 0x00}}, { 8899 ,{0x01, 0x00}}, { 8975 ,{0x01, 0x00}}, { 9050 ,{0x01, 0x00}}, { 9126 ,{0x01, 0x00}} }},
   { /* 3  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 8824 ,{0x02, 0x00}}, { 8899 ,{0x02, 0x00}}, { 8975 ,{0x02, 0x00}}, { 9050 ,{0x02, 0x00}}, { 9126 ,{0x02, 0x00}} }},
   { /* 4  */ MIPI_PA  , UL1_MIPI_PORT0, REG_W  ,    MIPI_USID_PA0   , { { 8824 ,{0x03, 0x00}}, { 8899 ,{0x03, 0x00}}, { 8975 ,{0x03, 0x00}}, { 9050 ,{0x03, 0x00}}, { 9126 ,{0x03, 0x00}} }},
   { /* 5  */ MIPI_ASM , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_ASM0  , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 6  */ MIPI_ASM , UL1_MIPI_PORT1, REG_W  ,    MIPI_USID_ASM0  , { { 8824 ,{0x00, 0x03}}, { 8899 ,{0x00, 0x03}}, { 8975 ,{0x00, 0x03}}, { 9050 ,{0x00, 0x03}}, { 9126 ,{0x00, 0x03}} }},
   { /* 7  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 8  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 9  */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 10 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 11 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 12 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 13 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 14 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 15 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 16 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 17 */ MIPI_NULL, MIPI_DATA_NULL, SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand6[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand9[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand11[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand19[] = {{0}};

UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_TX_DATA_TABLE[] = 
{
   M_UMTS_TX_DATA(UMTSBandNone),             /*UMTSUMTSBandNone*/
   M_UMTS_TX_DATA(RX_HIGHBAND1_INDICATOR),   /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_TX_DATA(RX_HIGHBAND2_INDICATOR),   /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_TX_DATA(RX_HIGHBAND3_INDICATOR),   /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_TX_DATA(RX_LOWBAND1_INDICATOR),    /*RX_LOWBAND1_INDICATOR*/
   M_UMTS_TX_DATA(RX_LOWBAND2_INDICATOR),    /*RX_LOWBAND2_INDICATOR*/
};

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBandNone = {{0}};

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand1 = 
{
   /* Event */
  {
   /* No.           elm type , data idx       , evt_type       , evt_offset     */
   /*                           { start, stop },                  ( us )         */
    { /* 0, Prf_7  */ MIPI_PA, { 0    , 3     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*highest power*/
    { /* 1, Prf_6  */ MIPI_PA, { 4    , 7     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 2, Prf_5  */ MIPI_PA, { 8    , 11    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 3, Prf_4  */ MIPI_PA, { 12   , 15    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 4, Prf_3  */ MIPI_PA, { 16   , 19    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 5, Prf_2  */ MIPI_PA, { 20   , 23    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 6, Prf_1  */ MIPI_PA, { 24   , 27    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 7, Prf_0  */ MIPI_PA, { 28   , 31    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*lowest power*/
  },

  /* Data */
  {
   //elm type  , port_sel       , data_seq, user id,         {{sub 0, addr, data}}, {{sub 1, addr, data}}, {{sub 2, addr, data} , {{sub 3, addr, data}}, {{sub 4, addr, data}
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},  /*L7, TPC IDX 0*/
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x1F}}, {19362, {0x01, 0x1F}}, {19500, {0x01, 0x1F}}, {19638, {0x01, 0x1F}}, {19776, {0x01, 0x1F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0x8F}}, {19362, {0x02, 0x8F}}, {19500, {0x02, 0x8F}}, {19638, {0x02, 0x8F}}, {19776, {0x02, 0x8F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x30}}, {19362, {0x03, 0x30}}, {19500, {0x03, 0x30}}, {19638, {0x03, 0x30}}, {19776, {0x03, 0x30}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},  /*L6, TPC IDX 2*/
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x1F}}, {19362, {0x01, 0x1F}}, {19500, {0x01, 0x1F}}, {19638, {0x01, 0x1F}}, {19776, {0x01, 0x1F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0x8F}}, {19362, {0x02, 0x8F}}, {19500, {0x02, 0x8F}}, {19638, {0x02, 0x8F}}, {19776, {0x02, 0x8F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x30}}, {19362, {0x03, 0x30}}, {19500, {0x03, 0x30}}, {19638, {0x03, 0x30}}, {19776, {0x03, 0x30}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},  /*L5, TPC IDX 4*/
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x1F}}, {19362, {0x01, 0x1F}}, {19500, {0x01, 0x1F}}, {19638, {0x01, 0x1F}}, {19776, {0x01, 0x1F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0x8F}}, {19362, {0x02, 0x8F}}, {19500, {0x02, 0x8F}}, {19638, {0x02, 0x8F}}, {19776, {0x02, 0x8F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x30}}, {19362, {0x03, 0x30}}, {19500, {0x03, 0x30}}, {19638, {0x03, 0x30}}, {19776, {0x03, 0x30}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},  /*L4, TPC IDX 6*/
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x1F}}, {19362, {0x01, 0x1F}}, {19500, {0x01, 0x1F}}, {19638, {0x01, 0x1F}}, {19776, {0x01, 0x1F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0x8F}}, {19362, {0x02, 0x8F}}, {19500, {0x02, 0x8F}}, {19638, {0x02, 0x8F}}, {19776, {0x02, 0x8F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x30}}, {19362, {0x03, 0x30}}, {19500, {0x03, 0x30}}, {19638, {0x03, 0x30}}, {19776, {0x03, 0x30}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},  /*L3, TPC IDX 9*/
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x1F}}, {19362, {0x01, 0x1F}}, {19500, {0x01, 0x1F}}, {19638, {0x01, 0x1F}}, {19776, {0x01, 0x1F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0xBB}}, {19362, {0x02, 0xBB}}, {19500, {0x02, 0xBB}}, {19638, {0x02, 0xBB}}, {19776, {0x02, 0xBB}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x10}}, {19362, {0x03, 0x10}}, {19500, {0x03, 0x10}}, {19638, {0x03, 0x10}}, {19776, {0x03, 0x10}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},  /*L2, TPC IDX 15, Hyst1*/
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x1F}}, {19362, {0x01, 0x1F}}, {19500, {0x01, 0x1F}}, {19638, {0x01, 0x1F}}, {19776, {0x01, 0x1F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0xBB}}, {19362, {0x02, 0xBB}}, {19500, {0x02, 0xBB}}, {19638, {0x02, 0xBB}}, {19776, {0x02, 0xBB}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x10}}, {19362, {0x03, 0x10}}, {19500, {0x03, 0x10}}, {19638, {0x03, 0x10}}, {19776, {0x03, 0x10}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},  /*L1, TPC IDX 18*/
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x1F}}, {19362, {0x01, 0x1F}}, {19500, {0x01, 0x1F}}, {19638, {0x01, 0x1F}}, {19776, {0x01, 0x1F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0xBB}}, {19362, {0x02, 0xBB}}, {19500, {0x02, 0xBB}}, {19638, {0x02, 0xBB}}, {19776, {0x02, 0xBB}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x10}}, {19362, {0x03, 0x10}}, {19500, {0x03, 0x10}}, {19638, {0x03, 0x10}}, {19776, {0x03, 0x10}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},  /*L0, TPC IDX 25, Hyst2*/
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x1F}}, {19362, {0x01, 0x1F}}, {19500, {0x01, 0x1F}}, {19638, {0x01, 0x1F}}, {19776, {0x01, 0x1F}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0x66}}, {19362, {0x02, 0x66}}, {19500, {0x02, 0x66}}, {19638, {0x02, 0x66}}, {19776, {0x02, 0x66}}}},
    {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x00}}, {19362, {0x03, 0x00}}, {19500, {0x03, 0x00}}, {19638, {0x03, 0x00}}, {19776, {0x03, 0x00}}}},
    {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}} 
  }
};



UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand2 = 
{
   /* Event */
   {
    /* No.           elm type , data idx       , evt_type       , evt_offset     */
    /*                           { start, stop },                  ( us )         */
     { /* 0, Prf_7  */ MIPI_PA, { 0    , 3     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*highest power*/
     { /* 1, Prf_6  */ MIPI_PA, { 4    , 7     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 2, Prf_5  */ MIPI_PA, { 8    , 11    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 3, Prf_4  */ MIPI_PA, { 12   , 15    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 4, Prf_3  */ MIPI_PA, { 16   , 19    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 5, Prf_2  */ MIPI_PA, { 20   , 23    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 6, Prf_1  */ MIPI_PA, { 24   , 27    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 7, Prf_0  */ MIPI_PA, { 28   , 31    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*lowest power*/
   },
   
   /* Data */
   {
      //elm type  , port_sel     , data_seq, user id,         {{sub 0, addr, data}}, {{sub 1, addr, data}}, {{sub 2, addr, data} , {{sub 3, addr, data}}, {{sub 4, addr, data}     
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x04}}, {18662, {0x00, 0x04}}, {18800, {0x00, 0x04}}, {18938, {0x00, 0x04}}, {19076, {0x00, 0x04}} }},  /*L7, TPC IDX 0*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x1F}}, {18662, {0x01, 0x1F}}, {18800, {0x01, 0x1F}}, {18938, {0x01, 0x1F}}, {19076, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0x8F}}, {18662, {0x02, 0x8F}}, {18800, {0x02, 0x8F}}, {18938, {0x02, 0x8F}}, {19076, {0x02, 0x8F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x30}}, {18662, {0x03, 0x30}}, {18800, {0x03, 0x30}}, {18938, {0x03, 0x30}}, {19076, {0x03, 0x30}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x04}}, {18662, {0x00, 0x04}}, {18800, {0x00, 0x04}}, {18938, {0x00, 0x04}}, {19076, {0x00, 0x04}} }},  /*L6, TPC IDX 2*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x1F}}, {18662, {0x01, 0x1F}}, {18800, {0x01, 0x1F}}, {18938, {0x01, 0x1F}}, {19076, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0x8F}}, {18662, {0x02, 0x8F}}, {18800, {0x02, 0x8F}}, {18938, {0x02, 0x8F}}, {19076, {0x02, 0x8F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x30}}, {18662, {0x03, 0x30}}, {18800, {0x03, 0x30}}, {18938, {0x03, 0x30}}, {19076, {0x03, 0x30}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x04}}, {18662, {0x00, 0x04}}, {18800, {0x00, 0x04}}, {18938, {0x00, 0x04}}, {19076, {0x00, 0x04}} }},  /*L5, TPC IDX 4*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x1F}}, {18662, {0x01, 0x1F}}, {18800, {0x01, 0x1F}}, {18938, {0x01, 0x1F}}, {19076, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0x8F}}, {18662, {0x02, 0x8F}}, {18800, {0x02, 0x8F}}, {18938, {0x02, 0x8F}}, {19076, {0x02, 0x8F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x30}}, {18662, {0x03, 0x30}}, {18800, {0x03, 0x30}}, {18938, {0x03, 0x30}}, {19076, {0x03, 0x30}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x04}}, {18662, {0x00, 0x04}}, {18800, {0x00, 0x04}}, {18938, {0x00, 0x04}}, {19076, {0x00, 0x04}} }},  /*L4, TPC IDX 6*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x1F}}, {18662, {0x01, 0x1F}}, {18800, {0x01, 0x1F}}, {18938, {0x01, 0x1F}}, {19076, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0x8F}}, {18662, {0x02, 0x8F}}, {18800, {0x02, 0x8F}}, {18938, {0x02, 0x8F}}, {19076, {0x02, 0x8F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x30}}, {18662, {0x03, 0x30}}, {18800, {0x03, 0x30}}, {18938, {0x03, 0x30}}, {19076, {0x03, 0x30}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x04}}, {18662, {0x00, 0x04}}, {18800, {0x00, 0x04}}, {18938, {0x00, 0x04}}, {19076, {0x00, 0x04}} }},  /*L3, TPC IDX 9*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x1F}}, {18662, {0x01, 0x1F}}, {18800, {0x01, 0x1F}}, {18938, {0x01, 0x1F}}, {19076, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xBB}}, {18662, {0x02, 0xBB}}, {18800, {0x02, 0xBB}}, {18938, {0x02, 0xBB}}, {19076, {0x02, 0xBB}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x10}}, {18662, {0x03, 0x10}}, {18800, {0x03, 0x10}}, {18938, {0x03, 0x10}}, {19076, {0x03, 0x10}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x04}}, {18662, {0x00, 0x04}}, {18800, {0x00, 0x04}}, {18938, {0x00, 0x04}}, {19076, {0x00, 0x04}} }},  /*L2, TPC IDX 15, Hyst1*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x1F}}, {18662, {0x01, 0x1F}}, {18800, {0x01, 0x1F}}, {18938, {0x01, 0x1F}}, {19076, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xBB}}, {18662, {0x02, 0xBB}}, {18800, {0x02, 0xBB}}, {18938, {0x02, 0xBB}}, {19076, {0x02, 0xBB}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x10}}, {18662, {0x03, 0x10}}, {18800, {0x03, 0x10}}, {18938, {0x03, 0x10}}, {19076, {0x03, 0x10}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x04}}, {18662, {0x00, 0x04}}, {18800, {0x00, 0x04}}, {18938, {0x00, 0x04}}, {19076, {0x00, 0x04}} }},  /*L1, TPC IDX 18*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x1F}}, {18662, {0x01, 0x1F}}, {18800, {0x01, 0x1F}}, {18938, {0x01, 0x1F}}, {19076, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xBB}}, {18662, {0x02, 0xBB}}, {18800, {0x02, 0xBB}}, {18938, {0x02, 0xBB}}, {19076, {0x02, 0xBB}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x10}}, {18662, {0x03, 0x10}}, {18800, {0x03, 0x10}}, {18938, {0x03, 0x10}}, {19076, {0x03, 0x10}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x04}}, {18662, {0x00, 0x04}}, {18800, {0x00, 0x04}}, {18938, {0x00, 0x04}}, {19076, {0x00, 0x04}} }},  /*L0, TPC IDX 25, Hyst2*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x1F}}, {18662, {0x01, 0x1F}}, {18800, {0x01, 0x1F}}, {18938, {0x01, 0x1F}}, {19076, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0x66}}, {18662, {0x02, 0x66}}, {18800, {0x02, 0x66}}, {18938, {0x02, 0x66}}, {19076, {0x02, 0x66}} }},
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x00}}, {18662, {0x03, 0x00}}, {18800, {0x03, 0x00}}, {18938, {0x03, 0x00}}, {19076, {0x03, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }}
   }
};



UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand3 = 
{
   /* Event */
   {
    /* No.           elm type , data idx       , evt_type       , evt_offset     */
    /*                           { start, stop },                  ( us )         */
     { /* 0, Prf_7  */ MIPI_PA, { 0    , 3     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*highest power*/
     { /* 1, Prf_6  */ MIPI_PA, { 4    , 7     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 2, Prf_5  */ MIPI_PA, { 8    , 11    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 3, Prf_4  */ MIPI_PA, { 12   , 15    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 4, Prf_3  */ MIPI_PA, { 16   , 19    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 5, Prf_2  */ MIPI_PA, { 20   , 23    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 6, Prf_1  */ MIPI_PA, { 24   , 27    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 7, Prf_0  */ MIPI_PA, { 28   , 31    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*lowest power*/
   },
   
   /* Data */
   {
      //elm type  , port_sel     , data_seq, user id,         {{sub 0, addr, data}}, {{sub 1, addr, data}}, {{sub 2, addr, data} , {{sub 3, addr, data}}, {{sub 4, addr, data}     
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x00, 0x08}}, {18204, {0x00, 0x08}}, {18424, {0x00, 0x08}}, {18654, {0x00, 0x08}}, {18776, {0x00, 0x08}} }},  /*L7, TPC IDX 0*/
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x01, 0x1F}}, {18204, {0x01, 0x1F}}, {18424, {0x01, 0x1F}}, {18654, {0x01, 0x1F}}, {18776, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x02, 0x8E}}, {18204, {0x02, 0x8E}}, {18424, {0x02, 0x8E}}, {18654, {0x02, 0x8E}}, {18776, {0x02, 0x8E}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x03, 0x30}}, {18204, {0x03, 0x30}}, {18424, {0x03, 0x30}}, {18654, {0x03, 0x30}}, {18776, {0x03, 0x30}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x00, 0x08}}, {18204, {0x00, 0x08}}, {18424, {0x00, 0x08}}, {18654, {0x00, 0x08}}, {18776, {0x00, 0x08}} }},  /*L6, TPC IDX 2*/
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x01, 0x1F}}, {18204, {0x01, 0x1F}}, {18424, {0x01, 0x1F}}, {18654, {0x01, 0x1F}}, {18776, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x02, 0x8E}}, {18204, {0x02, 0x8E}}, {18424, {0x02, 0x8E}}, {18654, {0x02, 0x8E}}, {18776, {0x02, 0x8E}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x03, 0x30}}, {18204, {0x03, 0x30}}, {18424, {0x03, 0x30}}, {18654, {0x03, 0x30}}, {18776, {0x03, 0x30}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x00, 0x08}}, {18204, {0x00, 0x08}}, {18424, {0x00, 0x08}}, {18654, {0x00, 0x08}}, {18776, {0x00, 0x08}} }},  /*L5, TPC IDX 4*/
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x01, 0x1F}}, {18204, {0x01, 0x1F}}, {18424, {0x01, 0x1F}}, {18654, {0x01, 0x1F}}, {18776, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x02, 0x8E}}, {18204, {0x02, 0x8E}}, {18424, {0x02, 0x8E}}, {18654, {0x02, 0x8E}}, {18776, {0x02, 0x8E}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x03, 0x30}}, {18204, {0x03, 0x30}}, {18424, {0x03, 0x30}}, {18654, {0x03, 0x30}}, {18776, {0x03, 0x30}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x00, 0x08}}, {18204, {0x00, 0x08}}, {18424, {0x00, 0x08}}, {18654, {0x00, 0x08}}, {18776, {0x00, 0x08}} }},  /*L4, TPC IDX 6*/
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x01, 0x1F}}, {18204, {0x01, 0x1F}}, {18424, {0x01, 0x1F}}, {18654, {0x01, 0x1F}}, {18776, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x02, 0x8E}}, {18204, {0x02, 0x8E}}, {18424, {0x02, 0x8E}}, {18654, {0x02, 0x8E}}, {18776, {0x02, 0x8E}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x03, 0x30}}, {18204, {0x03, 0x30}}, {18424, {0x03, 0x30}}, {18654, {0x03, 0x30}}, {18776, {0x03, 0x30}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x00, 0x08}}, {18204, {0x00, 0x08}}, {18424, {0x00, 0x08}}, {18654, {0x00, 0x08}}, {18776, {0x00, 0x08}} }},  /*L3, TPC IDX 9*/
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x1F}}, {18204, {0x01, 0x1F}}, {18424, {0x01, 0x1F}}, {18654, {0x01, 0x1F}}, {18776, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xBA}}, {18204, {0x02, 0xBA}}, {18424, {0x02, 0xBA}}, {18654, {0x02, 0xBA}}, {18776, {0x02, 0xBA}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x00}}, {18204, {0x03, 0x00}}, {18424, {0x03, 0x00}}, {18654, {0x03, 0x00}}, {18776, {0x03, 0x00}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x00, 0x08}}, {18204, {0x00, 0x08}}, {18424, {0x00, 0x08}}, {18654, {0x00, 0x08}}, {18776, {0x00, 0x08}} }},  /*L2, TPC IDX 15, Hyst1*/
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x1F}}, {18204, {0x01, 0x1F}}, {18424, {0x01, 0x1F}}, {18654, {0x01, 0x1F}}, {18776, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xBA}}, {18204, {0x02, 0xBA}}, {18424, {0x02, 0xBA}}, {18654, {0x02, 0xBA}}, {18776, {0x02, 0xBA}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x00}}, {18204, {0x03, 0x00}}, {18424, {0x03, 0x00}}, {18654, {0x03, 0x00}}, {18776, {0x03, 0x00}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x00, 0x08}}, {18204, {0x00, 0x08}}, {18424, {0x00, 0x08}}, {18654, {0x00, 0x08}}, {18776, {0x00, 0x08}} }},  /*L1, TPC IDX 18*/
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x1F}}, {18204, {0x01, 0x1F}}, {18424, {0x01, 0x1F}}, {18654, {0x01, 0x1F}}, {18776, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xBA}}, {18204, {0x02, 0xBA}}, {18424, {0x02, 0xBA}}, {18654, {0x02, 0xBA}}, {18776, {0x02, 0xBA}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x00}}, {18204, {0x03, 0x00}}, {18424, {0x03, 0x00}}, {18654, {0x03, 0x00}}, {18776, {0x03, 0x00}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x00, 0x08}}, {18204, {0x00, 0x08}}, {18424, {0x00, 0x08}}, {18654, {0x00, 0x08}}, {18776, {0x00, 0x08}} }},  /*L0, TPC IDX 25, Hyst2*/
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x01, 0x1F}}, {18204, {0x01, 0x1F}}, {18424, {0x01, 0x1F}}, {18654, {0x01, 0x1F}}, {18776, {0x01, 0x1F}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x02, 0x66}}, {18204, {0x02, 0x66}}, {18424, {0x02, 0x66}}, {18654, {0x02, 0x66}}, {18776, {0x02, 0x66}} }},
     {MIPI_PA   , UL1_MIPI_PORT1 , REG_W ,   MIPI_USID_PA0,   {{18074, {0x03, 0x00}}, {18204, {0x03, 0x00}}, {18424, {0x03, 0x00}}, {18654, {0x03, 0x00}}, {18776, {0x03, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }}
   }
};



UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand4 = 
{
   /* Event */
   {
    /* No.           elm type , data idx       , evt_type       , evt_offset     */
    /*                           { start, stop },                  ( us )         */
     { /* 0, Prf_7  */ MIPI_PA, { 0    , 3     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*highest power*/
     { /* 1, Prf_6  */ MIPI_PA, { 4    , 7     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 2, Prf_5  */ MIPI_PA, { 8    , 11    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 3, Prf_4  */ MIPI_PA, { 12   , 15    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 4, Prf_3  */ MIPI_PA, { 16   , 19    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 5, Prf_2  */ MIPI_PA, { 20   , 23    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 6, Prf_1  */ MIPI_PA, { 24   , 27    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 7, Prf_0  */ MIPI_PA, { 28   , 31    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*lowest power*/
   },
   
   /* Data */
   {                                                                                                                                                                               
      //elm type  , port_sel     , data_seq, user id,         {{sub 0, addr, data}}, {{sub 1, addr, data}}, {{sub 2, addr, data} , {{sub 3, addr, data}}, {{sub 4, addr, data}     
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L7, TPC IDX 0*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x8E}}, {17224, {0x02, 0x8E}}, {17324, {0x02, 0x8E}}, {17425, {0x02, 0x8E}}, {17526, {0x02, 0x8E}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x30}}, {17224, {0x03, 0x30}}, {17324, {0x03, 0x30}}, {17425, {0x03, 0x30}}, {17526, {0x03, 0x30}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L6, TPC IDX 2*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x8E}}, {17224, {0x02, 0x8E}}, {17324, {0x02, 0x8E}}, {17425, {0x02, 0x8E}}, {17526, {0x02, 0x8E}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x30}}, {17224, {0x03, 0x30}}, {17324, {0x03, 0x30}}, {17425, {0x03, 0x30}}, {17526, {0x03, 0x30}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L5, TPC IDX 4*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x8E}}, {17224, {0x02, 0x8E}}, {17324, {0x02, 0x8E}}, {17425, {0x02, 0x8E}}, {17526, {0x02, 0x8E}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x30}}, {17224, {0x03, 0x30}}, {17324, {0x03, 0x30}}, {17425, {0x03, 0x30}}, {17526, {0x03, 0x30}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L4, TPC IDX 6*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x8E}}, {17224, {0x02, 0x8E}}, {17324, {0x02, 0x8E}}, {17425, {0x02, 0x8E}}, {17526, {0x02, 0x8E}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x30}}, {17224, {0x03, 0x30}}, {17324, {0x03, 0x30}}, {17425, {0x03, 0x30}}, {17526, {0x03, 0x30}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L3, TPC IDX 9*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0xBA}}, {17224, {0x02, 0xBA}}, {17324, {0x02, 0xBA}}, {17425, {0x02, 0xBA}}, {17526, {0x02, 0xBA}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x10}}, {17224, {0x03, 0x10}}, {17324, {0x03, 0x10}}, {17425, {0x03, 0x10}}, {17526, {0x03, 0x10}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L2, TPC IDX 15, Hyst1*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0xBA}}, {17224, {0x02, 0xBA}}, {17324, {0x02, 0xBA}}, {17425, {0x02, 0xBA}}, {17526, {0x02, 0xBA}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x10}}, {17224, {0x03, 0x10}}, {17324, {0x03, 0x10}}, {17425, {0x03, 0x10}}, {17526, {0x03, 0x10}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L1, TPC IDX 18*/       
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0xBA}}, {17224, {0x02, 0xBA}}, {17324, {0x02, 0xBA}}, {17425, {0x02, 0xBA}}, {17526, {0x02, 0xBA}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x10}}, {17224, {0x03, 0x10}}, {17324, {0x03, 0x10}}, {17425, {0x03, 0x10}}, {17526, {0x03, 0x10}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L0, TPC IDX 25, Hyst2*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x66}}, {17224, {0x02, 0x66}}, {17324, {0x02, 0x66}}, {17425, {0x02, 0x66}}, {17526, {0x02, 0x66}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x00}}, {17224, {0x03, 0x00}}, {17324, {0x03, 0x00}}, {17425, {0x03, 0x00}}, {17526, {0x03, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }}                            
   }                                                                            
};


UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand5 = 
{
   /* Event */
   {
    /* No.           elm type , data idx       , evt_type       , evt_offset     */
    /*                           { start, stop },                  ( us )         */
     { /* 0, Prf_7  */ MIPI_PA, { 0    , 3     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*highest power*/
     { /* 1, Prf_6  */ MIPI_PA, { 4    , 7     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 2, Prf_5  */ MIPI_PA, { 8    , 11    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 3, Prf_4  */ MIPI_PA, { 12   , 15    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 4, Prf_3  */ MIPI_PA, { 16   , 19    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 5, Prf_2  */ MIPI_PA, { 20   , 23    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 6, Prf_1  */ MIPI_PA, { 24   , 27    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 7, Prf_0  */ MIPI_PA, { 28   , 31    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*lowest power*/
   },
   
   /* Data */
   {                                                                                                                                                                               
      //elm type  , port_sel     , data_seq, user id,         {{sub 0, addr, data}}, {{sub 1, addr, data}}, {{sub 2, addr, data} , {{sub 3, addr, data}}, {{sub 4, addr, data}     
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x04}}, {8314, {0x00, 0x04}}, {8365, {0x00, 0x04}}, {8415, {0x00, 0x04}}, {8466, {0x00, 0x04}} }},  /*L7, TPC IDX 0*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x0F}}, {8314, {0x01, 0x0F}}, {8365, {0x01, 0x0F}}, {8415, {0x01, 0x0F}}, {8466, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x8B}}, {8314, {0x02, 0x8B}}, {8365, {0x02, 0x8B}}, {8415, {0x02, 0x8B}}, {8466, {0x02, 0x8B}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x30}}, {8314, {0x03, 0x30}}, {8365, {0x03, 0x30}}, {8415, {0x03, 0x30}}, {8466, {0x03, 0x30}} }},                      
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x04}}, {8314, {0x00, 0x04}}, {8365, {0x00, 0x04}}, {8415, {0x00, 0x04}}, {8466, {0x00, 0x04}} }},  /*L6, TPC IDX 2*/           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x0F}}, {8314, {0x01, 0x0F}}, {8365, {0x01, 0x0F}}, {8415, {0x01, 0x0F}}, {8466, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x8B}}, {8314, {0x02, 0x8B}}, {8365, {0x02, 0x8B}}, {8415, {0x02, 0x8B}}, {8466, {0x02, 0x8B}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x30}}, {8314, {0x03, 0x30}}, {8365, {0x03, 0x30}}, {8415, {0x03, 0x30}}, {8466, {0x03, 0x30}} }},          
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x04}}, {8314, {0x00, 0x04}}, {8365, {0x00, 0x04}}, {8415, {0x00, 0x04}}, {8466, {0x00, 0x04}} }},  /*L5, TPC IDX 4*/          
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x0F}}, {8314, {0x01, 0x0F}}, {8365, {0x01, 0x0F}}, {8415, {0x01, 0x0F}}, {8466, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x8B}}, {8314, {0x02, 0x8B}}, {8365, {0x02, 0x8B}}, {8415, {0x02, 0x8B}}, {8466, {0x02, 0x8B}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x30}}, {8314, {0x03, 0x30}}, {8365, {0x03, 0x30}}, {8415, {0x03, 0x30}}, {8466, {0x03, 0x30}} }},          
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x04}}, {8314, {0x00, 0x04}}, {8365, {0x00, 0x04}}, {8415, {0x00, 0x04}}, {8466, {0x00, 0x04}} }},  /*L4, TPC IDX 6*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x0F}}, {8314, {0x01, 0x0F}}, {8365, {0x01, 0x0F}}, {8415, {0x01, 0x0F}}, {8466, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x8B}}, {8314, {0x02, 0x8B}}, {8365, {0x02, 0x8B}}, {8415, {0x02, 0x8B}}, {8466, {0x02, 0x8B}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x30}}, {8314, {0x03, 0x30}}, {8365, {0x03, 0x30}}, {8415, {0x03, 0x30}}, {8466, {0x03, 0x30}} }},                            
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x04}}, {8314, {0x00, 0x04}}, {8365, {0x00, 0x04}}, {8415, {0x00, 0x04}}, {8466, {0x00, 0x04}} }},  /*L3, TPC IDX 9*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x0F}}, {8314, {0x01, 0x0F}}, {8365, {0x01, 0x0F}}, {8415, {0x01, 0x0F}}, {8466, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0xF9}}, {8314, {0x02, 0xF9}}, {8365, {0x02, 0xF9}}, {8415, {0x02, 0xF9}}, {8466, {0x02, 0xF9}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x00}}, {8314, {0x03, 0x00}}, {8365, {0x03, 0x00}}, {8415, {0x03, 0x00}}, {8466, {0x03, 0x00}} }},    
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x04}}, {8314, {0x00, 0x04}}, {8365, {0x00, 0x04}}, {8415, {0x00, 0x04}}, {8466, {0x00, 0x04}} }},  /*L2, TPC IDX 15, Hyst1*/  
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x0F}}, {8314, {0x01, 0x0F}}, {8365, {0x01, 0x0F}}, {8415, {0x01, 0x0F}}, {8466, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0xF9}}, {8314, {0x02, 0xF9}}, {8365, {0x02, 0xF9}}, {8415, {0x02, 0xF9}}, {8466, {0x02, 0xF9}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x00}}, {8314, {0x03, 0x00}}, {8365, {0x03, 0x00}}, {8415, {0x03, 0x00}}, {8466, {0x03, 0x00}} }},    
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x04}}, {8314, {0x00, 0x04}}, {8365, {0x00, 0x04}}, {8415, {0x00, 0x04}}, {8466, {0x00, 0x04}} }},  /*L1, TPC IDX 18*/     
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x0F}}, {8314, {0x01, 0x0F}}, {8365, {0x01, 0x0F}}, {8415, {0x01, 0x0F}}, {8466, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0xF9}}, {8314, {0x02, 0xF9}}, {8365, {0x02, 0xF9}}, {8415, {0x02, 0xF9}}, {8466, {0x02, 0xF9}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x00}}, {8314, {0x03, 0x00}}, {8365, {0x03, 0x00}}, {8415, {0x03, 0x00}}, {8466, {0x03, 0x00}} }},                                              
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x04}}, {8314, {0x00, 0x04}}, {8365, {0x00, 0x04}}, {8415, {0x00, 0x04}}, {8466, {0x00, 0x04}} }},  /*L0, TPC IDX 25, Hyst2*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x0F}}, {8314, {0x01, 0x0F}}, {8365, {0x01, 0x0F}}, {8415, {0x01, 0x0F}}, {8466, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x76}}, {8314, {0x02, 0x76}}, {8365, {0x02, 0x76}}, {8415, {0x02, 0x76}}, {8466, {0x02, 0x76}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x00}}, {8314, {0x03, 0x00}}, {8365, {0x03, 0x00}}, {8415, {0x03, 0x00}}, {8466, {0x03, 0x00}} }},                   
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }}                            
   }                                                                            
};

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand8 = 
{
   /* Event */
   {
    /* No.           elm type , data idx       , evt_type       , evt_offset     */
    /*                           { start, stop },                  ( us )         */
     { /* 0, Prf_7  */ MIPI_PA, { 0    , 3     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*highest power*/
     { /* 1, Prf_6  */ MIPI_PA, { 4    , 7     }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 2, Prf_5  */ MIPI_PA, { 8    , 11    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 3, Prf_4  */ MIPI_PA, { 12   , 15    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 4, Prf_3  */ MIPI_PA, { 16   , 19    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 5, Prf_2  */ MIPI_PA, { 20   , 23    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 6, Prf_1  */ MIPI_PA, { 24   , 27    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 7, Prf_0  */ MIPI_PA, { 28   , 31    }, MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*lowest power*/
   },
   
   /* Data */
   {                                                                                                                                                                               
      //elm type  , port_sel     , data_seq, user id,         {{sub 0, addr, data}}, {{sub 1, addr, data}}, {{sub 2, addr, data} , {{sub 3, addr, data}}, {{sub 4, addr, data}     
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},  /*L7, TPC IDX 0*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x0F}}, {8899, {0x01, 0x0F}}, {8975, {0x01, 0x0F}}, {9050, {0x01, 0x0F}}, {9126, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0xEB}}, {8899, {0x02, 0xEB}}, {8975, {0x02, 0xEB}}, {9050, {0x02, 0xEB}}, {9126, {0x02, 0xEB}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x10}}, {8899, {0x03, 0x10}}, {8975, {0x03, 0x10}}, {9050, {0x03, 0x10}}, {9126, {0x03, 0x10}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},  /*L6, TPC IDX 2*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x0F}}, {8899, {0x01, 0x0F}}, {8975, {0x01, 0x0F}}, {9050, {0x01, 0x0F}}, {9126, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0xEB}}, {8899, {0x02, 0xEB}}, {8975, {0x02, 0xEB}}, {9050, {0x02, 0xEB}}, {9126, {0x02, 0xEB}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x10}}, {8899, {0x03, 0x10}}, {8975, {0x03, 0x10}}, {9050, {0x03, 0x10}}, {9126, {0x03, 0x10}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},  /*L5, TPC IDX 4*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x0F}}, {8899, {0x01, 0x0F}}, {8975, {0x01, 0x0F}}, {9050, {0x01, 0x0F}}, {9126, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0xEB}}, {8899, {0x02, 0xEB}}, {8975, {0x02, 0xEB}}, {9050, {0x02, 0xEB}}, {9126, {0x02, 0xEB}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x10}}, {8899, {0x03, 0x10}}, {8975, {0x03, 0x10}}, {9050, {0x03, 0x10}}, {9126, {0x03, 0x10}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},  /*L4, TPC IDX 6*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x0F}}, {8899, {0x01, 0x0F}}, {8975, {0x01, 0x0F}}, {9050, {0x01, 0x0F}}, {9126, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0xEB}}, {8899, {0x02, 0xEB}}, {8975, {0x02, 0xEB}}, {9050, {0x02, 0xEB}}, {9126, {0x02, 0xEB}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x10}}, {8899, {0x03, 0x10}}, {8975, {0x03, 0x10}}, {9050, {0x03, 0x10}}, {9126, {0x03, 0x10}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},  /*L3, TPC IDX 9*/        
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x0F}}, {8899, {0x01, 0x0F}}, {8975, {0x01, 0x0F}}, {9050, {0x01, 0x0F}}, {9126, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0xF9}}, {8899, {0x02, 0xF9}}, {8975, {0x02, 0xF9}}, {9050, {0x02, 0xF9}}, {9126, {0x02, 0xF9}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x00}}, {8899, {0x03, 0x00}}, {8975, {0x03, 0x00}}, {9050, {0x03, 0x00}}, {9126, {0x03, 0x00}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},  /*L2, TPC IDX 15, Hyst1*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x0F}}, {8899, {0x01, 0x0F}}, {8975, {0x01, 0x0F}}, {9050, {0x01, 0x0F}}, {9126, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0xF9}}, {8899, {0x02, 0xF9}}, {8975, {0x02, 0xF9}}, {9050, {0x02, 0xF9}}, {9126, {0x02, 0xF9}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x00}}, {8899, {0x03, 0x00}}, {8975, {0x03, 0x00}}, {9050, {0x03, 0x00}}, {9126, {0x03, 0x00}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},  /*L1, TPC IDX 18*/       
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x0F}}, {8899, {0x01, 0x0F}}, {8975, {0x01, 0x0F}}, {9050, {0x01, 0x0F}}, {9126, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0xF9}}, {8899, {0x02, 0xF9}}, {8975, {0x02, 0xF9}}, {9050, {0x02, 0xF9}}, {9126, {0x02, 0xF9}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x00}}, {8899, {0x03, 0x00}}, {8975, {0x03, 0x00}}, {9050, {0x03, 0x00}}, {9126, {0x03, 0x00}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},  /*L0, TPC IDX 25, Hyst2*/
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x0F}}, {8899, {0x01, 0x0F}}, {8975, {0x01, 0x0F}}, {9050, {0x01, 0x0F}}, {9126, {0x01, 0x0F}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0x76}}, {8899, {0x02, 0x76}}, {8975, {0x02, 0x76}}, {9050, {0x02, 0x76}}, {9126, {0x02, 0x76}} }},                           
     {MIPI_PA   , UL1_MIPI_PORT0 , REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x00}}, {8899, {0x03, 0x00}}, {8975, {0x03, 0x00}}, {9050, {0x03, 0x00}}, {9126, {0x03, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {MIPI_NULL , MIPI_DATA_NULL , SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }}                            
   }                                                                          
};

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand6 = {{0}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand9 = {{0}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand11 = {{0}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand19 = {{0}};

UL1_MIPI_EVENT_TABLE_T*  UMTS_MIPI_TPC_EVENT_TABLE[] =
{
   M_UMTS_TPC_EVENT(UMTSBandNone),             /*UMTSUMTSBandNone*/          
   M_UMTS_TPC_EVENT(RX_HIGHBAND1_INDICATOR),   /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_TPC_EVENT(RX_HIGHBAND2_INDICATOR),   /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_TPC_EVENT(RX_HIGHBAND3_INDICATOR),   /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_TPC_EVENT(RX_LOWBAND1_INDICATOR),    /*RX_LOWBAND1_INDICATOR*/ 
   M_UMTS_TPC_EVENT(RX_LOWBAND2_INDICATOR),    /*RX_LOWBAND2_INDICATOR*/ 
};

UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_TPC_DATA_TABLE[] = 
{
   M_UMTS_TPC_DATA(UMTSBandNone),               /*UMTSUMTSBandNone*/          
   M_UMTS_TPC_DATA(RX_HIGHBAND1_INDICATOR),     /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_TPC_DATA(RX_HIGHBAND2_INDICATOR),     /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_TPC_DATA(RX_HIGHBAND3_INDICATOR),     /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_TPC_DATA(RX_LOWBAND1_INDICATOR),      /*RX_LOWBAND1_INDICATOR*/ 
   M_UMTS_TPC_DATA(RX_LOWBAND2_INDICATOR),      /*RX_LOWBAND2_INDICATOR*/ 
};

UL1_UMTS_MIPI_TPC_T* UMTS_MIPI_TPC_TABLE[] =
{
   M_UMTS_TPC(UMTSBandNone          ),   /*UMTSUMTSBandNone          */          
   M_UMTS_TPC(RX_HIGHBAND1_INDICATOR),   /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_TPC(RX_HIGHBAND2_INDICATOR),   /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_TPC(RX_HIGHBAND3_INDICATOR),   /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_TPC(RX_LOWBAND1_INDICATOR ),   /*RX_LOWBAND1_INDICATOR */ 
   M_UMTS_TPC(RX_LOWBAND2_INDICATOR ),   /*RX_LOWBAND2_INDICATOR */ 
};



/*special handle for T/Rx calibration, we should force ASM to isolation mode */
/*Users just need to provide the ASM isolation CW, DSP may use immediate mode*/
/*to control the MIPI ASM                                                    */
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBandNone[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand1[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]   = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]   = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand4[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]   = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand5[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]  = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand8[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]  = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand3[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]   = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand6[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]   = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand9[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]   = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand11[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]  = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand19[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]  = {{0}};

UL1_MIPI_DATA_TABLE_T* UMTS_MIPI_ASM_ISOLATION_DATA_TABLE[] = 
{
   M_UMTS_ASM_ISO(UMTSBandNone)      ,      /*UMTSUMTSBandNone*/          
   M_UMTS_ASM_ISO(RX_HIGHBAND1_INDICATOR),      /*RX_HIGHBAND1_INDICATOR*/  
   M_UMTS_ASM_ISO(RX_HIGHBAND2_INDICATOR),      /*RX_HIGHBAND2_INDICATOR*/  
   M_UMTS_ASM_ISO(RX_HIGHBAND3_INDICATOR),      /*RX_HIGHBAND3_INDICATOR*/  
   M_UMTS_ASM_ISO(RX_LOWBAND1_INDICATOR ),      /*RX_LOWBAND1_INDICATOR*/   
   M_UMTS_ASM_ISO(RX_LOWBAND2_INDICATOR ),      /*RX_LOWBAND2_INDICATOR*/   
};

/////////////////////////////////////////////

#endif

