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
#include "module_msg_range.h"

#ifndef _TST_MSG_H
#define _TST_MSG_H

MODULE_MSG_BEGIN( TST_MSG_CODE_BEGIN )
#if defined (__DHL_MODULE__)
MSG_ID_DHL_INJECT_STRING = TST_MSG_CODE_BEGIN,
MSG_ID_TST_INJECT_STRING,
MSG_ID_DHL_IND_READ_VARIABLE_RETURN,
MSG_ID_DHL_IND_READ_MEMORY_REPORT,
MSG_ID_DHL_IND_QUERY_MEMORY_RANGE,
MSG_ID_DHL_IND_NVRAM_READ_CNF,
MSG_ID_DHL_IND_NVRAM_RESET_CNF,
MSG_ID_DHL_IND_NVRAM_WRITE_CNF,
MSG_ID_DHL_IND_STACK_STATISTICS,
MSG_ID_DHL_IND_FILE_TRANSFER_REPORT,
MSG_ID_DHL_IND_FILE_SAVE_REPORT,
MSG_ID_DHL_IND_QUERY_BUF_MONITOR_REPORT,
MSG_ID_DHL_TO_ETSTM,
MSG_ID_ETSTM_TO_DHL,
MSG_ID_DHL_IND_SWLA_QUERY_HEADER_REPORT,
MSG_ID_DHL_IND_GENERAL_QUERY_CMD_ACK,
MSG_ID_DHL_TEST,
MSG_ID_HELLO_GPD,
MSG_ID_HELLO_PTR_ARRAY,
MSG_ID_HELLO_INLINE_ILM,
MSG_ID_HELLO_INLINE_ILM2,
MSG_ID_DHL_DRIVER_STATE_CHANGE,
MSG_ID_DHL_TTY_RX_DONE,
MSG_ID_DHL_REDUMP_END_WARN,
MSG_ID_DHL_CMD_NVRAM,
MSG_ID_DHL_CMD_READ_STACK_STATISTICS,
MSG_ID_DHL_CMD_QUERY_CTRL_BUF_MONITOR_DATA,
MSG_ID_DHL_CMD_QUERY_FLC_BUF_MONITOR_DATA,
MSG_ID_DHL_CMD_MSG_BKPT,
MSG_ID_DHL_CMD_INJECT_AT_CMD,
MSG_ID_DHL_CMD_SWLA_START,
MSG_ID_DHL_CMD_SWLA_STOP,	
MSG_ID_DHL_CMD_SWLA_EMI_MONITOR_MASTER_SELECT,
MSG_ID_DHLDBG_MSG_BREAK,
MSG_ID_DHL_IND_VIRTUAL_CHANNEL,
MSG_ID_DHL_IND_UBDB,
MSG_ID_TST_R8_DL_PKT_SINGLE_GPD_IND,
MSG_ID_DHL_CMD_ST_START,
MSG_ID_DHL_CMD_ST_STOP,
MSG_ID_DHL_CMD_ST_STOP_REPORT,
MSG_ID_DHL_CMD_ST_QUERY_HEADER,
MSG_ID_DHL_IND_ST_QUERY_HEADER_REPORT,
MSG_ID_TST_L2COPRO_FILTER_RETRIEVAL,
MSG_ID_TST_L2COPRO_FILTER_SAVE,
MSG_ID_DHL_CMD_SET_DHL_MUX_FILTER,
MSG_ID_DHL_CMD_ENABLE_23G_DSP_LOGGING,
MSG_ID_DHL_CMD_DISABLE_23G_DSP_LOGGING,
MSG_ID_DHL_CMD_LOOP_BACK_RESPONSE,
MSG_ID_DHL_AUTO_MEMORY_DUMP_IN_ILM,
MSG_ID_DHL_IND_CUSTOM_READ_MEMORY_REPORT,
#else
MSG_ID_TST_INJECT_STRING = TST_MSG_CODE_BEGIN,
MSG_ID_TST_GET_GPRS_POOL_STATUS,
MSG_ID_TST_POOL_QUERY_TIME_EXPIRY,
MSG_ID_TST_MSG_FROM_DSP,
MSG_ID_TST_STREAM_FROM_DSP,
MSG_ID_TST_UT_MSG1,
MSG_ID_TST_L2COPRO_FILTER_RETRIEVAL,
MSG_ID_TST_L2COPRO_FILTER_SAVE,
MSG_ID_TST_MSG_FROM_AP,
MSG_ID_TST_UT_CCCI_MSG,
MSG_ID_TST_TR_INTERNAL,
MSG_ID_TST_MINI_LOG_STATIC_INFO,
MSG_ID_TST_R8_DL_PKT_SINGLE_GPD_IND,
#endif
MODULE_MSG_END( MSG_ID_TST_CODE_TAIL )

#endif  //_TST_MSG_H
