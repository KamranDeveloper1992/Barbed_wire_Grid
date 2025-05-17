/*******************************************************************/
/*                                                                 */
/*                      ADOBE CONFIDENTIAL                         */
/*                   _ _ _ _ _ _ _ _ _ _ _ _ _                     */
/*                                                                 */
/* Copyright 2007 Adobe Systems Incorporated                       */
/* All Rights Reserved.                                            */
/*                                                                 */
/* NOTICE:  All information contained herein is, and remains the   */
/* property of Adobe Systems Incorporated and its suppliers, if    */
/* any.  The intellectual and technical concepts contained         */
/* herein are proprietary to Adobe Systems Incorporated and its    */
/* suppliers and may be covered by U.S. and Foreign Patents,       */
/* patents in process, and are protected by trade secret or        */
/* copyright law.  Dissemination of this information or            */
/* reproduction of this material is strictly forbidden unless      */
/* prior written permission is obtained from Adobe Systems         */
/* Incorporated.                                                   */
/*                                                                 */
/*******************************************************************/

/*
	Barbed_wire_Grid.h
*/

#pragma once

#ifndef Barbed_wire_Grid_H
#define Barbed_wire_Grid_H

typedef unsigned char		u_char;
typedef unsigned short		u_short;
typedef unsigned short		u_int16;
typedef unsigned long		u_long;
typedef short int			int16;
#define PF_TABLE_BITS	12
#define PF_TABLE_SZ_16	4096

#define PF_DEEP_COLOR_AWARE 1	// make sure we get 16bpc pixels; 
								// AE_Effect.h checks for this.

#include "AEConfig.h"

#ifdef AE_OS_WIN
	typedef unsigned short PixelType;
	#include <Windows.h>
#endif

#include "entry.h"
#include "AE_Effect.h"
#include "AE_EffectCB.h"
#include "AE_Macros.h"
#include "Param_Utils.h"
#include "AE_EffectCBSuites.h"
#include "String_Utils.h"
#include "AE_GeneralPlug.h"
#include "AEFX_ChannelDepthTpl.h"
#include "AEGP_SuiteHandler.h"

#include "Barbed_wire_Grid_Strings.h"

/* Versioning information */

#define	MAJOR_VERSION	1
#define	MINOR_VERSION	0
#define	BUG_VERSION		0
#define	STAGE_VERSION	PF_Stage_DEVELOP
#define	BUILD_VERSION	1


/* Parameter defaults */

#define	Barbed_wire_Grid_GAIN_MIN		0
#define	Barbed_wire_Grid_GAIN_MAX		100
#define	Barbed_wire_Grid_GAIN_DFLT		10

enum {
	Barbed_wire_Grid_INPUT = 0,
	Barbed_wire_Grid_GAIN,
	Barbed_base_thickness_Grid_GAIN,
	Barbed_scale_grid_Grid_GAIN,
	Barbed_checkbox_Grid_GAIN,
	Barbed_wire_Grid_COLOR,
	Barbed_wire_Grid_NUM_PARAMS
};

enum {
	GAIN_DISK_ID = 1,
	COLOR_DISK_ID,
	CHECKBOX_DISK_ID,
};

typedef struct GainInfo{
	PF_FpLong	base_spacingF;
	PF_FpLong base_thicknessF;
	PF_FpLong scale_gridF;
	PF_Boolean checkbox_gridF;
	PF_Pixel8    color_spacingRGB;
} GainInfo, *GainInfoP, **GainInfoH;


extern "C" {

	DllExport
	PF_Err
	EffectMain(
		PF_Cmd			cmd,
		PF_InData		*in_data,
		PF_OutData		*out_data,
		PF_ParamDef		*params[],
		PF_LayerDef		*output,
		void			*extra);

}

#endif // Barbed_wire_Grid_H