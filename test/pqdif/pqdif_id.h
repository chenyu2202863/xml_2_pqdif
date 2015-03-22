/*
**  PQDIF - Power Quality Data Interchange Format
**  Version 1.5
**
**  File name:          $Workfile: pqdif_id.h $
**  Last modified:      $Modtime: 7/03/02 2:21p $
**  Last modified by:   $Author: Jack $
**
**  VCS archive path:   $Archive: /PQDIF/Document/Version15/pqdif_id.h $
**  VCS revision:       $Revision: 50 $
**
**  STANDARD ID DEFINITIONS
**  ======================================================================
**  This file contains the current list of standard IDs for the various
**  tags in the PQDIF standard. The IDs consist of two types: GUIDs
**  and integers (UINT4). For now, the integer uses a #define and the GUID
**  uses a const GUID ...
**  ======================================================================
**  The current version of this file and related information
**  can be found at URL:
**
**  http://grouper.ieee.org/groups/1159/3/docs.html
**
**  ======================================================================
**
*/

#ifndef PQDIF_ID_H
#define PQDIF_ID_H

//  ======================================================================
//  Do not modify anything after the following comment:
//  {{{{ AUTO-GENERATED CONSTANTS }}}}

//  ==========================================================
//  The following IDs are the legal values for
//  tagCompressionStyleID
//  ==========================================================

//  Description:   No compression is used.
//  Version:       1.0
#define ID_COMP_STYLE_NONE 0

//  Description:   The body of each record is compressed individually. The checksums will be found in the header of each record.
//  Version:       1.0
#define ID_COMP_STYLE_RECORDLEVEL 2

//  Description:   Everything after the container record is compressed as a single block. This feature has been deprecated under 1.5 and should not be used.
//  Version:       1.5 Deprecated
#define ID_COMP_STYLE_TOTALFILE 1

//  ==========================================================
//  The following IDs are the legal values for
//  tagCompressionAlgorithmID
//  ==========================================================

//  Description:   No compression algorithm is used.
//  Version:       1.0
#define ID_COMP_ALG_NONE 0

//  Description:   A standard compression algorithm -- ZLIB -- standardized by the IETF (Internet Engineering Task Force). See http://quest.jpl.nasa.gov/zlib/ for details.
//  Version:       1.0
#define ID_COMP_ALG_ZLIB 1

//  Description:   A commercial package, the PKZIP data compression library, was used to compress the data. This feature has been deprecated under 1.5 and should not be used.
//  Version:       1.5 Deprecated
#define ID_COMP_ALG_PKZIPCL 64

//  ==========================================================
//  The following IDs are the legal values for
//  tagDataSourceTypeID
//  ==========================================================

//  Version:       1.0
const GUID ID_DS_TYPE_MEASURE = { 0xe6b51730, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_DS_TYPE_MANUAL = { 0xe6b51731, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_DS_TYPE_SIMULATE = { 0xe6b51732, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_DS_TYPE_BENCHMARK = { 0xe6b51733, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_DS_TYPE_DEBUG = { 0xe6b51734, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  ==========================================================
//  The following IDs are the legal values for
//  tagVendorID
//  ==========================================================

const GUID ID_VENDOR_SATEC = { 0xe2da5081, 0x7fdb, 0x11d3, { 0x9b, 0x39, 0x0, 0x40, 0x5, 0x2c, 0x2d, 0x28 } };

const GUID ID_VENDOR_WPT = { 0xe2da5082, 0x7fdb, 0x11d3, { 0x9b, 0x39, 0x0, 0x40, 0x5, 0x2c, 0x2d, 0x28 } };

const GUID ID_VENDOR_NONE = { 0xe6b51701, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_BMI = { 0xe6b51702, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_BPA = { 0xe6b51703, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_CESI = { 0xe6b51704, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_COOPER = { 0xe6b51705, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_DCG = { 0xe6b51706, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_DRANETZ = { 0xe6b51707, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_EDF = { 0xe6b51708, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_EPRI = { 0xe6b51709, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_ELECTROTEK = { 0xe6b5170a, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_FLUKE = { 0xe6b5170b, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_HYDROQUEBEC = { 0xe6b5170c, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_IEEE = { 0xe6b5170d, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_KREISSJOHNSON = { 0xe6b5170e, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_METROSONIC = { 0xe6b5170f, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_PML = { 0xe6b51710, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_PSI = { 0xe6b51711, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_PTI = { 0xe6b51712, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_PUBLICDOMAIN = { 0xe6b51713, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_RPM = { 0xe6b51714, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_SQUAREDPOWERLOGIC = { 0xe6b51715, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_VENDOR_TELOG = { 0xe6b51716, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.5
const GUID ID_VENDOR_PMI = { 0x609acec0, 0x993d, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Version:       1.5
const GUID ID_VENDOR_METONE = { 0xb5b5da61, 0xe2e1, 0x11d4, { 0x82, 0xd9, 0x0, 0xe0, 0x98, 0x72, 0xa0, 0x94 } };

//  Description:   Trinergi
//  Version:       1.5
const GUID ID_VENDOR_TRINERGI = { 0xfd5a3a8, 0xd73a, 0x11d2, { 0xac, 0x3e, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   General Electric US
//  Version:       1.5
const GUID ID_VENDOR_GE = { 0x5202bd00, 0x245c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Version:       1.5
const GUID ID_VENDOR_LEM = { 0x80c4a722, 0x2816, 0x11d4, { 0x8a, 0xb4, 0x0,0x40, 0x5, 0x69, 0x8d, 0x26 } };

//  Version:       1.5
const GUID ID_VENDOR_ACTL = { 0x80c4a761, 0x2816, 0x11d4, { 0x8a, 0xb4,0x0,0x40, 0x5, 0x69, 0x8d, 0x26 } };

//  Description:   Advantech
//  Version:       1.5
const GUID ID_VENDOR_ADVANTECH = { 0x650f988f, 0x378c, 0x47b8, { 0xba, 0xed, 0xcc, 0xcb, 0x3f, 0x95, 0x9a, 0xd7 } };

//  Description:   Elcom
//  Version:       1.5
const GUID ID_VENDOR_ELCOM = { 0xf7e9eb70, 0x6f1d, 0x11d6, {0x9c, 0xb3, 0x00, 0x20, 0xe0, 0x10, 0x45, 0x3b } };

//  ==========================================================
//  The following IDs are the legal values for
//  tagEquipmentID
//  ==========================================================

const GUID ID_EQUIP_WPT_5530 = { 0xe2da5083, 0x7fdb, 0x11d3, { 0x9b, 0x39, 0x0, 0x40, 0x5, 0x2c, 0x2d, 0x28 } };

const GUID ID_EQUIP_WPT_5540 = { 0xe2da5084, 0x7fdb, 0x11d3, { 0x9b, 0x39, 0x0, 0x40, 0x5, 0x2c, 0x2d, 0x28 } };

const GUID ID_EQUIP_BMI_3100 = { 0xf1c04780, 0x50fb, 0x11d3, { 0xac, 0x3e, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

const GUID ID_EQUIP_BMI_7100 = { 0xe6b51717, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_BMI_8010 = { 0xe6b51718, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_BMI_8020 = { 0xe6b51719, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_BMI_9010 = { 0xe6b5171a, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_COOPER_VHARM = { 0xe6b5171b, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_COOPER_VFLICKER = { 0xe6b5171c, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_DCG_EMTP = { 0xe6b5171d, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_DRANETZ_656 = { 0xe6b5171e, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_DRANETZ_658 = { 0xe6b5171f, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_ETK_TESTPROGRAM = { 0xe6b51721, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_DRANETZ_8000 = { 0xe6b51720, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_ETK_PQDIFEDITOR = { 0xe6b51722, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_ETK_PASS = { 0xe6b51723, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_ETK_SUPERHARM = { 0xe6b51724, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_ETK_SUPERTRAN = { 0xe6b51725, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_ETK_TOP = { 0xe6b51726, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_ETK_PQVIEW = { 0xe6b51727, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_ETK_HARMONI = { 0xe6b51728, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_FLUKE_CUR = { 0xe6b51729, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_IEEE_COMTRADE = { 0xe6b5172b, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_FLUKE_F41 = { 0xe6b5172a, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_PUBLIC_ATP = { 0xe6b5172c, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_METROSONIC_M1 = { 0xe6b5172d, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_SQD_SMS = { 0xe6b5172e, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_TELOG_M1 = { 0xe6b5172f, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_PML_3710 = { 0x85726d0, 0x1dc0, 0x11d0, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_PML_3720 = { 0x85726d1, 0x1dc0, 0x11d0, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_PML_3800 = { 0x85726d2, 0x1dc0, 0x11d0, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_PML_7300 = { 0x85726d3, 0x1dc0, 0x11d0, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_PML_7700 = { 0x85726d4, 0x1dc0, 0x11d0, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_PML_VIP = { 0x85726d5, 0x1dc0, 0x11d0, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

const GUID ID_EQUIP_PML_LOGSERVER = { 0x85726d6, 0x1dc0, 0x11d0, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.5
const GUID ID_EQUIP_METONE_ELT15 = { 0xb5b5da62, 0xe2e1, 0x11d4, { 0x82, 0xd9, 0x0, 0xe0, 0x98, 0x72, 0xa0, 0x94 } };

//  Version:       1.5
const GUID ID_EQUIP_PMI_SCANNER = { 0x609acec1, 0x993d, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Advantech ADAM 4017
//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM4017 = { 0x92b7977b, 0xc02, 0x4766, { 0x95, 0xcf, 0xdd, 0x37, 0x9c, 0xae, 0xb4, 0x17 } };

//  Description:   Electrotek DSS
//  Version:       1.5
const GUID ID_EQUIP_ETK_DSS = { 0xd347ba66, 0xe34c, 0x11d4, { 0x82, 0xd9, 0x0, 0xe0, 0x98, 0x72, 0xa0, 0x94 } };

//  Description:   Advantech ADAM 4018
//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM4018 = { 0x3008151e, 0x2317, 0x4405, { 0xa5, 0x9e, 0xe7, 0xb3, 0xb2, 0x6, 0x67, 0xa9 } };

//  Description:   Advantech ADAM 4018M
//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM4018M = { 0x3a1af807, 0x1347, 0x45f8, { 0x96, 0x6a, 0xf4, 0x81, 0xc6, 0xae, 0x20, 0x8e } };

//  Description:   Advantech ADAM 4052
//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM4052 = { 0x8bba416b, 0xa7ec, 0x4616, { 0x8b, 0x8f, 0x59, 0xfe, 0xd7, 0x49, 0x32, 0x3d } };

//  Description:   BMI 8800
//  Version:       1.5
const GUID ID_EQUIP_BMI_8800 = { 0xe77d1a81, 0x1235, 0x11d5, { 0xa3, 0x90, 0x0, 0x10, 0xa4, 0x92, 0x4e, 0xcc } };

//  Description:   Trinergi PQM
//  Version:       1.5
const GUID ID_EQUIP_TRINERGI_PQM = { 0xfd5a3aa, 0xd73a, 0x11d2, { 0xac, 0x3e, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Medcal
//  Version:       1.5
const GUID ID_EQUIP_MEDCAL = { 0xf3bfa0a1, 0xeb87, 0x11d2, { 0xac, 0x3e, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   GE kV Energy Meter
//  Version:       1.5
const GUID ID_EQUIP_GE_KV = { 0x5202bd01, 0x245c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   GE kV2 Energy Meter
//  Version:       1.5
const GUID ID_EQUIP_GE_KV2 = { 0x5202bd03, 0x245c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Version:       1.5
const GUID ID_EQUIP_ACUMENTRICS_CONTROL = { 0x5202bd04, 0x245c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Version:       1.5
const GUID ID_EQUIP_ETK_TEXTPQDIF = { 0x5202bd05, 0x245c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Version:       1.5
const GUID ID_EQUIP_ETK_PQWEB = { 0x5202bd06, 0x245c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Version:       1.5
const GUID ID_EQUIP_QWAVE_POWER_DISTRIBUTION = { 0x80c4a723, 0x2816,0x11d4,{ 0x8a, 0xb4, 0x0, 0x40, 0x5, 0x69, 0x8d, 0x26 } };

//  Version:       1.5
const GUID ID_EQUIP_QWAVE_POWER_TRANSMISSION = { 0x80c4a725, 0x2816,0x11d4,{ 0x8a, 0xb4, 0x0, 0x40, 0x5, 0x69, 0x8d, 0x26 } };

//  Version:       1.5
const GUID ID_EQUIP_QWAVE_MICRO = { 0x80c4a727, 0x2816, 0x11d4, { 0x8a,0xb4, 0x0, 0x40, 0x5, 0x69, 0x8d, 0x26 } };

//  Version:       1.5
const GUID ID_EQUIP_QWAVE_TWIN = { 0x80c4a728, 0x2816, 0x11d4, { 0x8a,0xb4,0x0, 0x40, 0x5, 0x69, 0x8d, 0x26 } };

//  Version:       1.5
const GUID ID_EQUIP_QWAVE_PREMIUM = { 0x80c4a729, 0x2816, 0x11d4, { 0x8a,0xb4, 0x0, 0x40, 0x5, 0x69, 0x8d, 0x26 } };

//  Version:       1.5
const GUID ID_EQUIP_QWAVE_LIGHT = { 0x80c4a72a, 0x2816, 0x11d4, { 0x8a,0xb4, 0x0, 0x40, 0x5, 0x69, 0x8d, 0x26 } };

//  Version:       1.5
const GUID ID_EQUIP_QWAVE_NOMAD = { 0x80c4a72b, 0x2816, 0x11d4, { 0x8a,0xb4, 0x0, 0x40, 0x5, 0x69, 0x8d, 0x26 } };

//  Version:       1.5
const GUID ID_EQUIP_EWON_4000 = { 0x80c4a762, 0x2816, 0x11d4, { 0x8a, 0xb4,0x0, 0x40, 0x5, 0x69, 0x8d, 0x26 } };

//  Version:       1.5
const GUID ID_EQUIP_QUALIMETRE = { 0x80c4a764, 0x2816, 0x11d4, { 0x8a,0xb4,0x0, 0x40, 0x5, 0x69, 0x8d, 0x26 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_ANALYST3Q = { 0xd567cb71, 0xbcc0, 0x41ee, { 0x8e, 0x8c, 0x35, 0x85, 0x15, 0x53, 0xf6, 0x55 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_ANALYST1Q = { 0x477ecb3b, 0x917f, 0x4915, { 0xaf, 0x99, 0xa6, 0xc2, 0x9a, 0xc1, 0x87, 0x64 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_ANALYST2050 = { 0x9878ccab, 0xa842, 0x4cac, { 0x95, 0xf, 0x6d, 0x47, 0x21, 0x5b, 0xff, 0xdf } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_ANALYST2060 = { 0x312471a2, 0xb586, 0x491c, { 0x85, 0x5a, 0xca, 0x5, 0x45, 0x9a, 0x7e, 0x20 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_MIDGET200 = { 0x8449f6b9, 0x10f4, 0x40a7, { 0xa1, 0xc3, 0xbe, 0x33, 0x8e, 0xb9, 0x74, 0x22 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_MBX300 = { 0xd4578d61, 0xdf2b, 0x4218, { 0xa7, 0xb1, 0x5e, 0xf1, 0xa9, 0xbb, 0x85, 0xfa } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_MBX800 = { 0x1c14b57a, 0xba25, 0x47fb, { 0x88, 0xfa, 0x5f, 0xe5, 0xce, 0xc9, 0x9e, 0x6a } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_MBX601 = { 0x1f3cda7b, 0x2ce1, 0x4030, { 0xa3, 0x90, 0xe3, 0xd4, 0x9c, 0x56, 0x15, 0xd2 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_MBX602 = { 0x4a157756, 0x414a, 0x427b, { 0x99, 0x32, 0x55, 0x76, 0xe, 0xd5, 0xf7, 0x7 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_MBX603 = { 0xf7b4677b, 0xb277, 0x45b5, { 0xaa, 0xae, 0x5f, 0xb3, 0x93, 0x41, 0xb3, 0x90 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_MBX686 = { 0x40004266, 0xa978, 0x4991, { 0x9e, 0xd6, 0xc1, 0xcd, 0x73, 0xf, 0x5b, 0xf5 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_PERMA701 = { 0x9b0dfd9d, 0xd4e9, 0x419d, { 0xba, 0x10, 0xc1, 0xce, 0xe6, 0xcf, 0x8f, 0x93 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_PERMA702 = { 0x7f5d62ac, 0x9fab, 0x400f, { 0xb5, 0x1a, 0xf0, 0xf3, 0x94, 0x1f, 0xb5, 0xaa } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_PERMA705 = { 0xd85fea9c, 0x14d5, 0x45eb, { 0x83, 0x1f, 0xe0, 0x39, 0x73, 0x9, 0x2b, 0xd8 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_PERMA706 = { 0x16d6bbfc, 0xb5a, 0x4cf0, { 0x81, 0xcf, 0x48, 0xa3, 0x10, 0x5e, 0xff, 0x4f } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_QWAVEMICRO = { 0xe0380e52, 0xc205, 0x43a0, { 0x9f, 0xf4, 0x76, 0xfb, 0xd6, 0x76, 0x5f, 0x37 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_QWAVENOMAD = { 0x165f145d, 0x90c3, 0x4591, { 0x95, 0x9a, 0x33, 0xb1, 0x1, 0xd4, 0xbf, 0x8b } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_QWAVELIGHT = { 0x5198ceb9, 0x4b4e, 0x439c, { 0xa1, 0xc0, 0x21, 0x8c, 0x96, 0x3d, 0x6a, 0x9c } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_QWAVETWIN = { 0x67a42a2d, 0xb831, 0x4222, { 0x80, 0x5e, 0xd5, 0xfd, 0xeb, 0xdd, 0x3a, 0x46 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_QWAVEPOWER_DISTRIBUTION = { 0x2401bf48, 0x9db2, 0x46ec, { 0xac, 0xde, 0x5d, 0xed, 0xde, 0x25, 0xe5, 0x4e } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_QWAVEPREMIUM = { 0x6b609a29, 0x4a64, 0x4d1c, { 0xa6, 0xe3, 0xca, 0xef, 0x94, 0xfa, 0x56, 0xa0 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_QWAVEPOWER_TRANSPORT = { 0xd4422eeb, 0xb1cd, 0x4ba9, { 0xa7, 0xc8, 0x5d, 0x14, 0x1d, 0xf4, 0x5, 0x18 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_TOPASLT = { 0x9c46483a, 0x541e, 0x4d66, { 0x9c, 0x10, 0xf9, 0x43, 0xab, 0xfc, 0x34, 0x8a } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_TOPAS1000 = { 0x459b8614, 0x6724, 0x48fb, { 0xb5, 0xd4, 0xf1, 0x49, 0xed, 0xc, 0x62, 0xf5 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_TOPAS1019 = { 0x7b11408b, 0x9d2c, 0x407c, { 0x84, 0xa5, 0x89, 0x44, 0x2, 0x18, 0xdc, 0xf8 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_TOPAS1020 = { 0xd1def77d, 0x990f, 0x484e, { 0xa1, 0x66, 0xf7, 0x92, 0x11, 0x70, 0xa6, 0x4b } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_TOPAS1040 = { 0xd3cc1de2, 0x6e6b, 0x4b6e, { 0xad, 0x90, 0x10, 0xd6, 0x58, 0x5f, 0x8f, 0xa2 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_BEN5000 = { 0xa70e32b1, 0x2f1a, 0x4543, { 0xa6, 0x84, 0x78, 0xa4, 0xb5, 0xbe, 0x34, 0xbb } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_BEN6000 = { 0x5a4c1b5, 0x6681, 0x47e6, { 0x9f, 0x64, 0x8d, 0xa1, 0x25, 0xdb, 0xec, 0x32 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_EWAVE = { 0xe46981d5, 0x708d, 0x4822, { 0x97, 0xaa, 0xfd, 0xb6, 0xf7, 0x3b, 0x3a, 0xf2 } };

//  Version:       1.5
const GUID ID_EQUIP_LEM_EWON4000 = { 0xd4c0895c, 0xfd48, 0x4981, { 0x99, 0x7c, 0x9e, 0x70, 0xd8, 0xe, 0xfb, 0x6 } };

//  Version:       1.5
const GUID ID_EQUIP_WPT_5510 = { 0x752871de, 0x583, 0x4d44, { 0xa9, 0xae, 0xc5, 0xfa, 0xdc, 0x1, 0x44, 0xac } };

//  Version:       1.5
const GUID ID_EQUIP_WPT_5520 = { 0xb72d289, 0x7645, 0x40b8, { 0x94, 0x6e, 0xc3, 0xce, 0x4f, 0x1b, 0xcd, 0x37 } };

//  Version:       1.5
const GUID ID_EQUIP_WPT_5530T = { 0x8f88ea9e, 0x1007, 0x4569, { 0xab, 0x47, 0x75, 0x6f, 0x29, 0x2a, 0x23, 0xed } };

//  Version:       1.5
const GUID ID_EQUIP_WPT_5560 = { 0x5fd9c0ff, 0x4432, 0x41b5, { 0x9a, 0x9e, 0x9a, 0x32, 0xba, 0x2c, 0xf0, 0x5 } };

//  Version:       1.5
const GUID ID_EQUIP_WPT_5590 = { 0x2861d5ca, 0x23ac, 0x4a51, { 0xa5, 0xa0, 0x49, 0x8d, 0xa6, 0x1d, 0x26, 0xdd } };

//  Version:       1.5
const GUID ID_EQUIP_ETK_NODECENTER = { 0xc52e8460, 0x58b4, 0x4f1a, { 0x84, 0x69, 0x69, 0xca, 0x3f, 0xef, 0x9f, 0xf1 } };

//  Version:       1.5
const GUID ID_EQUIP_WPT_DRANVIEW = { 0x8d97aa1, 0x1719, 0x11d6, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM5017 = { 0x2f46263c, 0x92ac, 0x4717, { 0x8a, 0x8, 0xa6, 0x17, 0x7d, 0xf3, 0xf6, 0x11 } };

//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM5018 = { 0xcc2d3247, 0xfe65, 0x4db6, { 0x82, 0x6, 0x50, 0xa, 0x23, 0x15, 0x1b, 0xb2 } };

//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM5080 = { 0x6c37b63c, 0xe770, 0x4b85, { 0xbd, 0x32, 0x47, 0x39, 0xd6, 0xeb, 0x98, 0x46 } };

//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM5052 = { 0xe9261dfe, 0x3d44, 0x47e3, { 0xac, 0x36, 0x3b, 0x9, 0x7f, 0xaa, 0x8c, 0xda } };

//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM4050 = { 0x9212066d, 0xea65, 0x477e, { 0xbf, 0x95, 0xe4, 0xa0, 0x6, 0x6d, 0x25, 0xce } };

//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM4053 = { 0xdc29b83f, 0xbebe, 0x4cf3, { 0xb3, 0xfb, 0x0, 0xdc, 0x63, 0x62, 0x6d, 0xd9 } };

//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM4080 = { 0x64fc42c6, 0x3c90, 0x4633, { 0x99, 0xdf, 0x2c, 0x60, 0x58, 0x21, 0x4b, 0x72 } };

//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM5050 = { 0xc950a2e3, 0x7a35, 0x440c, { 0x86, 0x60, 0x63, 0xf6, 0x11, 0x97, 0x25, 0x19 } };

//  Version:       1.5
const GUID ID_EQUIP_ADVANTECH_ADAM5051 = { 0xc8f92334, 0xa69b, 0x4856, { 0xb2, 0x53, 0xec, 0x24, 0x71, 0xd1, 0x37, 0xd6 } };

//  Description:   ELCOM_BK550
//  Version:       1.5
const GUID ID_EQUIP_ELCOM_BK550 = { 0xf4380a60, 0x6f1d, 0x11d6, {0x9c, 0xb3, 0x00, 0x20, 0xe0, 0x10, 0x45, 0x3b } };

//  ==========================================================
//  The following IDs are the legal values for
//  tagInstrumentTypeID
//  ==========================================================

//  Version:       1.0
const GUID ID_INSTR_TYPE_SCOPE = { 0xe6b51735, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Frequency recorder.
//  Version:       1.0
const GUID ID_INSTR_TYPE_FR = { 0xe6b51736, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Power quality meter.
//  Version:       1.0
const GUID ID_INSTR_TYPE_PQM = { 0xe6b51737, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Voltage recorder.
//  Version:       1.0
const GUID ID_INSTR_TYPE_VR = { 0xe6b51738, 0xf747, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_INSTR_TYPE_SA = { 0xc690e871, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  ==========================================================
//  The following IDs are the legal values for
//  tagPhaseID
//  ==========================================================

//  Description:   Phase is not applicable.
//  Version:       1.0
#define ID_PHASE_NONE 0

//  Description:   A-to-neutral.
//  Version:       1.0
#define ID_PHASE_AN   1

//  Description:   B-to-neutral.
//  Version:       1.0
#define ID_PHASE_BN   2

//  Description:   C-to-neutral.
//  Version:       1.0
#define ID_PHASE_CN   3

//  Description:   Neutral-to-ground.
//  Version:       1.0
#define ID_PHASE_NG   4

//  Description:   A-to-B.
//  Version:       1.0
#define ID_PHASE_AB   5

//  Description:   B-to-C.
//  Version:       1.0
#define ID_PHASE_BC   6

//  Description:   C-to-A.
//  Version:       1.0
#define ID_PHASE_CA   7

//  Description:   Residual - the vector or point-on-wave sum of Phases A, B, and C.  Should be zero in a perfectly balanced system.
//  Version:       1.0
#define ID_PHASE_RES  8

//  Description:   Net - the vector or point-on-wave sum of Phases A, B, C and the Neutral phase.  Should be zero in a 4 wire system with no earth return path.
//  Version:       1.0
#define ID_PHASE_NET  9

//  Description:   The value representing a total or other summarizing value in a multi-phase system.
//  Version:       1.5
#define ID_PHASE_TOTAL 13

//  Description:   The value representing average of 3 line-neutral values
//  Version:       1.5
#define ID_PHASE_LN_AVE 14

//  Description:   The value representing average of 3 line-line values
//  Version:       1.5
#define ID_PHASE_LL_AVE 15

//  Description:   The value representing the "worst" of the 3 phases
//  Version:       1.5
#define ID_PHASE_WORST 16

//  Description:   DC Positive
//  Version:       1.5
#define ID_PHASE_PLUS 17

//  Description:   DC Negative
//  Version:       1.5
#define ID_PHASE_MINUS 18

//  Description:   Generic Phase 1
//  Version:       1.5
#define ID_PHASE_GENERAL_1 19

//  Description:   Generic Phase 2
//  Version:       1.5
#define ID_PHASE_GENERAL_2 20

//  Description:   Generic Phase 3
//  Version:       1.5
#define ID_PHASE_GENERAL_3 21

//  Description:   Generic Phase 4
//  Version:       1.5
#define ID_PHASE_GENERAL_4 22

//  Description:   Generic Phase 5
//  Version:       1.5
#define ID_PHASE_GENERAL_5 23

//  Description:   Generic Phase 6
//  Version:       1.5
#define ID_PHASE_GENERAL_6 24

//  Description:   Generic Phase 7
//  Version:       1.5
#define ID_PHASE_GENERAL_7 25

//  Description:   Generic Phase 8
//  Version:       1.5
#define ID_PHASE_GENERAL_8 26

//  Description:   Generic Phase 9
//  Version:       1.5
#define ID_PHASE_GENERAL_9 27

//  Description:   Generic Phase 10
//  Version:       1.5
#define ID_PHASE_GENERAL_10 28

//  Description:   Generic Phase 11
//  Version:       1.5
#define ID_PHASE_GENERAL_11 29

//  Description:   Generic Phase 12
//  Version:       1.5
#define ID_PHASE_GENERAL_12 30

//  Description:   Generic Phase 13
//  Version:       1.5
#define ID_PHASE_GENERAL_13 31

//  Description:   Generic Phase 14
//  Version:       1.5
#define ID_PHASE_GENERAL_14 32

//  Description:   Generic Phase 15
//  Version:       1.5
#define ID_PHASE_GENERAL_15 33

//  Description:   Generic Phase 16
//  Version:       1.5
#define ID_PHASE_GENERAL_16 34

//  ==========================================================
//  The following IDs are the legal values for
//  tagQuantityTypeID
//  ==========================================================

//  Description:   TIME, VAL / For point-on-wave measurements,
//  Version:       1.0
const GUID ID_QT_WAVEFORM = { 0x67f6af80, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   TIME, MIN, MAX, AVG, INST, VAL ?/ For time-based logged entries.
//  Version:       1.5
const GUID ID_QT_VALUELOG = { 0x67f6af82, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   TIME, MIN, MAX, AVG, INST, VAL, PHASEANGLE ?/ For time-domain  measurements including magnitudes and (optionally) phase angle.
//  Version:       1.5
const GUID ID_QT_PHASOR = { 0x67f6af81, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   VAL (FREQUENCY), VAL, PHASEANGLE / For frequency-domain measurements including magnitude and (optionally) phase angle.
//  Version:       1.0
const GUID ID_QT_RESPONSE = { 0x67f6af85, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   TIME, LAT, LON, VAL, POLARITY, ELLIPSE
//  Version:       1.0
const GUID ID_QT_FLASH = { 0x67f6af83, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   BINLOW, BINHIGH, BINID, COUNT
//  Version:       1.0
const GUID ID_QT_HISTOGRAM = { 0x67f6af87, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   XBINLOW, XBINHIGH, YBINLOW, YBINHIGH, BINID, COUNT
//  Version:       1.0
const GUID ID_QT_HISTOGRAM3D = { 0x67f6af88, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   PROB, VAL. (Note that the specific P1 value types have been deprecated.)
//  Version:       1.0
const GUID ID_QT_CPF = { 0x67f6af89, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   VAL, VAL
//  Version:       1.0
const GUID ID_QT_XY = { 0x67f6af8a, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   VAL, DUR
//  Version:       1.0
const GUID ID_QT_MAGDUR = { 0x67f6af8b, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   VAL, VAL, VAL
//  Version:       1.0
const GUID ID_QT_XYZ = { 0x67f6af8c, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   TIME, VAL, DUR
//  Version:       1.0
const GUID ID_QT_MAGDURTIME = { 0x67f6af8d, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   TIME, VAL, DUR, COUNT
//  Version:       1.0
const GUID ID_QT_MAGDURCOUNT = { 0x67f6af8e, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  ==========================================================
//  The following IDs are the legal values for
//  tagDisturbanceCategoryID
//  ==========================================================

//  Description:   No IEEE 1159 definition applicable or desired
//  Version:       1.0
const GUID ID_DISTURB_1159_NONE = { 0x67f6af8f, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   IEEE 1159 Transient
//  Version:       1.0
const GUID ID_DISTURB_1159_TRANSIENT = { 0x67f6af90, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   IEEE 1159 Impulsive Transient
//  Version:       1.5
const GUID ID_DISTURB_1159_TRANSIENT_IMPULSIVE = { 0xdd56ef60, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Impulsive Transient - nanosecond duration
//  Version:       1.5
const GUID ID_DISTURB_1159_TRANSIENT_IMPULSIVE_NANO = { 0xdd56ef61, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Impulsive Transient - microsecond duration
//  Version:       1.5
const GUID ID_DISTURB_1159_TRANSIENT_IMPULSIVE_MICRO = { 0xdd56ef63, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Impulsive Transient - millisecond duration
//  Version:       1.5
const GUID ID_DISTURB_1159_TRANSIENT_IMPULSIVE_MILLI = { 0xdd56ef64, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Oscillatory Transient
//  Version:       1.5
const GUID ID_DISTURB_1159_TRANSIENT_OSCILLATORY = { 0xdd56ef65, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Oscillatory Transient - Low Frequency
//  Version:       1.5
const GUID ID_DISTURB_1159_TRANSIENT_OSCILLATORY_LOWFREQ = { 0xdd56ef66, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Oscillatory Transient - Medium Frequency
//  Version:       1.5
const GUID ID_DISTURB_1159_TRANSIENT_OSCILLATORY_MEDFREQ = { 0xdd56ef67, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Oscillatory Transient - High Frequency
//  Version:       1.5
const GUID ID_DISTURB_1159_TRANSIENT_OSCILLATORY_HIGHFREQ = { 0xdd56ef68, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Short Duration RMS Variation
//  Version:       1.0
const GUID ID_DISTURB_1159_SHORTDUR = { 0x67f6af91, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   IEEE 1159 Short Duration RMS Variation - Instantaneous duration
//  Version:       1.5
const GUID ID_DISTURB_1159_SHORTDUR_INSTANT = { 0xdd56ef69, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Short Duration RMS Variation - Instantaneous Sag
//  Version:       1.5
const GUID ID_DISTURB_1159_SHORTDUR_INSTANT_SAG = { 0xdd56ef6a, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Short Duration RMS Variation - Instantaneous Swell
//  Version:       1.5
const GUID ID_DISTURB_1159_SHORTDUR_INSTANT_SWELL = { 0xdd56ef6b, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Short Duration RMS Variation - Momentary Duration
//  Version:       1.5
const GUID ID_DISTURB_1159_SHORTDUR_MOMENT = { 0xdd56ef6c, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Short Duration RMS Variation - Momentary Interruption
//  Version:       1.5
const GUID ID_DISTURB_1159_SHORTDUR_MOMENT_INTERRUPT = { 0xdd56ef6d, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Short Duration RMS Variation - Momentary Sag
//  Version:       1.5
const GUID ID_DISTURB_1159_SHORTDUR_MOMENT_SAG = { 0xdd56ef6e, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Short Duration RMS Variation - Momentary Swell
//  Version:       1.5
const GUID ID_DISTURB_1159_SHORTDUR_MOMENT_SWELL = { 0xdd56ef6f, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Short Duration RMS Variation - Temporary Duration
//  Version:       1.5
const GUID ID_DISTURB_1159_SHORTDUR_TEMP = { 0xdd56ef70, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Short Duration RMS Variation - Temporary Interruption
//  Version:       1.5
const GUID ID_DISTURB_1159_SHORTDUR_TEMP_INTERRUPT = { 0xdd56ef71, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Short Duration RMS Variation - Temporary Sag
//  Version:       1.5
const GUID ID_DISTURB_1159_SHORTDUR_TEMP_SAG = { 0xdd56ef72, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Short Duration RMS Variation - Temporary Swell
//  Version:       1.5
const GUID ID_DISTURB_1159_SHORTDUR_TEMP_SWELL = { 0xdd56ef73, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Long Duration RMS Variation
//  Version:       1.0
const GUID ID_DISTURB_1159_LONGDUR = { 0x67f6af92, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   IEEE 1159 Long Duration RMS Variation - Interruption
//  Version:       1.5
const GUID ID_DISTURB_1159_LONGDUR_INTERRUPT = { 0xdd56ef74, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Long Duration RMS Variation - Undervoltage
//  Version:       1.5
const GUID ID_DISTURB_1159_LONGDUR_SAG = { 0xdd56ef75, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Long Duration RMS Variation - Overvoltage
//  Version:       1.5
const GUID ID_DISTURB_1159_LONGDUR_SWELL = { 0xdd56ef76, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Imbalance
//  Version:       1.5
const GUID ID_DISTURB_1159_IMBALANCE = { 0xdd56ef77, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Power Frequency Variation
//  Version:       1.5
const GUID ID_DISTURB_1159_POWERFREQVARIATION = { 0xdd56ef7e, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Voltage Fluctuation (causes light flicker)
//  Version:       1.5
const GUID ID_DISTURB_1159_VOLTAGEFLUCTUATION = { 0x67f6af93, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   IEEE 1159 Waveform Distortion
//  Version:       1.5
const GUID ID_DISTURB_1159_WAVEDISTORT = { 0x67f6af94, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   DC offset of voltage or current waveform
//  Version:       1.5
const GUID ID_DISTURB_1159_WAVEDISTORT_DCOFFSET = { 0xdd56ef78, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Waveform Harmonics Present
//  Version:       1.5
const GUID ID_DISTURB_1159_WAVEDISTORT_HARMONIC = { 0xdd56ef79, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Waveform Interharmonics Present
//  Version:       1.5
const GUID ID_DISTURB_1159_WAVEDISTORT_INTERHARMONIC = { 0xdd56ef7a, 0x7edd, 0x11d2, { 0xb3, 0xa, 0x0, 0x60, 0x97, 0x89, 0xd1, 0x93 } };

//  Description:   IEEE 1159 Waveform Notching Present
//  Version:       1.5
const GUID ID_DISTURB_1159_WAVEDISTORT_NOTCHING = { 0x67f6af95, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   IEEE 1159 Waveform Noise Present
//  Version:       1.5
const GUID ID_DISTURB_1159_WAVEDISTORT_NOISE = { 0x67f6af96, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  ==========================================================
//  The following IDs are the legal values for
//  tagQuantityUnitsID
//  ==========================================================

//  Description:   Unitless.
//  Version:       1.0
#define ID_QU_NONE        0

//  Description:   Seconds -- relative from the beginning time of the observation (using tagTimeStart as the beginning time).
//  Version:       1.0
#define ID_QU_SECONDS     2

//  Description:   Absolute time. Each timestamp in the series must be in absolute time using the TIMESTAMPPQDIF physical type. This is generally *not* recommended, but is acceptible when _VALUELOG is used.
//  Version:       1.0
#define ID_QU_TIMESTAMP   1

//  Description:   The timestamps are in cycles, relative to tagTimeStart.
//  Version:       1.0
#define ID_QU_CYCLES      3

//  Description:   Volts.
//  Version:       1.0
#define ID_QU_VOLTS       6

//  Description:   Amperes.
//  Version:       1.0
#define ID_QU_AMPS        7

//  Description:   Volt-amperes.
//  Version:       1.0
#define ID_QU_VA          8

//  Description:   Watts.
//  Version:       1.0
#define ID_QU_WATTS       9

//  Description:   Volt-amperes reactive.
//  Version:       1.0
#define ID_QU_VARS        10

//  Description:   Ohms.
//  Version:       1.0
#define ID_QU_OHMS        11

//  Description:   Siemens.
//  Version:       1.0
#define ID_QU_SIEMENS     12

//  Description:   Volts per amp.
//  Version:       1.0
#define ID_QU_VOLTSPERAMP 13

//  Description:   Joules.
//  Version:       1.0
#define ID_QU_JOULES      14

//  Description:   Hertz.
//  Version:       1.0
#define ID_QU_HERTZ       15

//  Description:   Celcius.
//  Version:       1.0
#define ID_QU_CELCIUS     16

//  Description:   Degrees of arc.
//  Version:       1.0
#define ID_QU_DEGREES     17

//  Description:   Decibels.
//  Version:       1.0
#define ID_QU_DB          18

//  Description:   Percent.
//  Version:       1.0
#define ID_QU_PERCENT     19

//  Description:   Per-unit.
//  Version:       1.0
#define ID_QU_PERUNIT     20

//  Description:   Number of counts or samples
//  Version:       1.0
#define ID_QU_SAMPLES     21

//  Description:   Energy - var-hours
//  Version:       1.5
#define ID_QU_VARHOURS 22

//  Description:   Energy - Watt-hours
//  Version:       1.5
#define ID_QU_WATTHOURS 23

//  Description:   Energy - VA-hours
//  Version:       1.5
#define ID_QU_VAHOURS 24

//  Description:   Meters/Second
//  Version:       1.5
#define ID_QU_MPS 25

//  Description:   Miles/Hr
//  Version:       1.5
#define ID_QU_MPH 26

//  Description:   Pressure, Bars
//  Version:       1.5
#define ID_QU_BARS 27

//  Description:   Pressure, Pascals
//  Version:       1.5
#define ID_QU_PASCALS 28

//  Description:   Force, Newtons
//  Version:       1.5
#define ID_QU_NEWTONS 29

//  Description:   Torque, Newton Meters
//  Version:       1.5
#define ID_QU_NEWTONMETERS 30

//  Description:   Revolutions/minute
//  Version:       1.5
#define ID_QU_RPM 31

//  Description:   Radians/Second
//  Version:       1.5
#define ID_QU_RADPERSEC 32

//  Description:   Meters
//  Version:       1.5
#define ID_QU_METERS 33

//  Description:   Flux Linkage - Weber Turns
//  Version:       1.5
#define ID_QU_WEBERTURNS 34

//  Description:   Flux Density - Teslas
//  Version:       1.5
#define ID_QU_TESLAS 35

//  Description:   Magnetic Field - Webers
//  Version:       1.5
#define ID_QU_WEBERS 36

//  Description:   Volts/Volts transfer function
//  Version:       1.5
#define ID_QU_VOLTSPERVOLT 37

//  Description:   Amps/Amps transfer function
//  Version:       1.5
#define ID_QU_AMPSPERAMP 38

//  Description:   Impedance Transfer Funtion
//  Version:       1.5
#define ID_QU_AMPSPERVOLT 39

//  ==========================================================
//  The following IDs are the legal values for
//  tagValueTypeID
//  ==========================================================

//  Description:   This should be the default value type for a measurement -- a value.
//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_VAL = { 0x67f6af97, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Time.
//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_TIME = { 0xc690e862, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Minimum.
//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_MIN = { 0x67f6af98, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Maximum.
//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_MAX = { 0x67f6af99, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Average.
//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_AVG = { 0x67f6af9a, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Instantaneous. (depricated - use VAL instead)
//  Version:       1.5 Deprecated
const GUID ID_SERIES_VALUE_TYPE_INST = { 0x67f6af9b, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Phase angle (used for a _VAL series or when it applies to all).
//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_PHASEANGLE = { 0x3d786f9d, 0xf76e, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Phase angle which corresponds to a _MIN series (completing a complex pair).
//  Version:       1.5
const GUID ID_SERIES_VALUE_TYPE_PHASEANGLE_MIN = { 0xdc762340, 0x3c56, 0x11d2, { 0xae, 0x44, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Phase angle which corresponds to a _MAX series.
//  Version:       1.5
const GUID ID_SERIES_VALUE_TYPE_PHASEANGLE_MAX = { 0xdc762341, 0x3c56, 0x11d2, { 0xae, 0x44, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Phase angle which corresponds to an _AVG series.
//  Version:       1.5
const GUID ID_SERIES_VALUE_TYPE_PHASEANGLE_AVG = { 0xdc762342, 0x3c56, 0x11d2, { 0xae, 0x44, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Area under the signal, usually an rms voltage, current or other quantity.
//  Version:       1.5
const GUID ID_SERIES_VALUE_TYPE_AREA = { 0xc7825ce0, 0x8ace, 0x11d3, { 0xb9, 0x2f, 0x0, 0x50, 0xda, 0x2b, 0x1f, 0x4d } };

//  Description:   Latitude.
//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_LATITUDE = { 0xc690e864, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Duration.
//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_DURATION = { 0xc690e863, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Longitude.
//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_LONGITUDE = { 0xc690e865, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Polarity.
//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_POLARITY = { 0xc690e866, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Ellipse (for lightning flash density).
//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_ELLIPSE = { 0xc690e867, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_BINID = { 0xc690e869, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_BINHIGH = { 0xc690e86a, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_BINLOW = { 0xc690e86b, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_XBINHIGH = { 0xc690e86c, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_XBINLOW = { 0xc690e86d, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_YBINHIGH = { 0xc690e86e, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_YBINLOW = { 0xc690e86f, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Version:       1.0
const GUID ID_SERIES_VALUE_TYPE_COUNT = { 0xc690e870, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Transition event code series.  This series contains codes cooresponding to values in a value series that indicates what kind of transition caused the event to be recorded.  Used only with VALUELOG data.
//  Version:       1.5
const GUID ID_SERIES_VALUE_TYPE_TRANSITION = { 0x5369c260, 0xc347, 0x11d2, { 0x92, 0x3f, 0x0, 0x10, 0x4b, 0x2b, 0x84, 0xb1 } };

//  Description:   Cumulative probability in percent.
//  Version:       1.5
const GUID ID_SERIES_VALUE_TYPE_PROB = { 0x6763cc71, 0x17d6, 0x11d4, { 0x9f, 0x1c, 0x0, 0x20, 0x78, 0xe0, 0xb7, 0x23 } };

//  Description:   Interval data
//  Version:       1.5
const GUID ID_SERIES_VALUE_TYPE_INTERVAL = { 0x72e82a40, 0x336c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Status Data
//  Version:       1.5
const GUID ID_SERIES_VALUE_TYPE_STATUS = { 0xb82b5c82, 0x55c7, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Probability: 1%. This has been deprecated under 1.5 and should not be used.
//  Version:       1.5 Deprecated
const GUID ID_SERIES_VALUE_TYPE_P1 = { 0x67f6af9c, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Probability: 5%. This has been deprecated under 1.5 and should not be used.
//  Version:       1.5 Deprecated
const GUID ID_SERIES_VALUE_TYPE_P5 = { 0x67f6af9d, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Probability: 10%. This has been deprecated under 1.5 and should not be used.
//  Version:       1.5 Deprecated
const GUID ID_SERIES_VALUE_TYPE_P10 = { 0x67f6af9e, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Probability: 90%. This has been deprecated under 1.5 and should not be used.
//  Version:       1.5 Deprecated
const GUID ID_SERIES_VALUE_TYPE_P90 = { 0x67f6af9f, 0xf753, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Probability: 95%. This has been deprecated under 1.5 and should not be used.
//  Version:       1.5 Deprecated
const GUID ID_SERIES_VALUE_TYPE_P95 = { 0xc690e860, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Probability: 99%. This has been deprecated under 1.5 and should not be used.
//  Version:       1.5 Deprecated
const GUID ID_SERIES_VALUE_TYPE_P99 = { 0xc690e861, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  Description:   Frequency. This has been deprecated under 1.5 and should not be used. (It is now a characteristic instead of a value type.)
//  Version:       1.5 Deprecated
const GUID ID_SERIES_VALUE_TYPE_FREQUENCY = { 0xc690e868, 0xf755, 0x11cf, { 0x9d, 0x89, 0x0, 0x80, 0xc7, 0x2e, 0x70, 0xa3 } };

//  ==========================================================
//  The following IDs are the legal values for
//  tagStorageMethodID
//  ==========================================================

//  Description:   The data in tagSeriesValues are a straight array of data points.
//  Version:       1.0
#define ID_SERIES_METHOD_VALUES    0x01

//  Description:   All values in tagSeriesValues will be multiplied by tagSeriesScale.
//  Version:       1.0
#define ID_SERIES_METHOD_SCALED 0x02

//  Description:   The data in tagSeriesValues consists of a special sequence to indicate the contents of a regular rate series (see main documentation for details). The vector contains: #rates, numpts1, rate1 ... numptsN, rateN.
//  Version:       1.0
#define ID_SERIES_METHOD_INCREMENT 0x04

//  ==========================================================
//  The following IDs are the legal values for
//  tagHintGreekPrefixID
//  ==========================================================

//  Version:       1.0
#define ID_GREEK_DONTCARE 0

//  Version:       1.0
#define ID_GREEK_FEMTO    1

//  Version:       1.0
#define ID_GREEK_PICO     2

//  Version:       1.0
#define ID_GREEK_NANO     3

//  Version:       1.0
#define ID_GREEK_MICRO    4

//  Version:       1.0
#define ID_GREEK_MILLI    5

//  Version:       1.0
#define ID_GREEK_NONE     6

//  Version:       1.0
#define ID_GREEK_KILO     7

//  Version:       1.0
#define ID_GREEK_MEGA     8

//  Version:       1.0
#define ID_GREEK_TERA 10

//  Version:       1.0
#define ID_GREEK_GIGA     9

//  ==========================================================
//  The following IDs are the legal values for
//  tagHintPreferredUnitsID
//  ==========================================================

//  Version:       1.0
#define ID_PREFER_ENG 1

//  Version:       1.0
#define ID_PREFER_PCT 2

//  Version:       1.0
#define ID_PREFER_PU  3

//  ==========================================================
//  The following IDs are the legal values for
//  tagHintDefaultDisplayID
//  ==========================================================

//  Version:       1.0
#define ID_DEFAULT_DONTCARE 0

//  Version:       1.0
#define ID_DEFAULT_MAG      1

//  Version:       1.0
#define ID_DEFAULT_ANG      2

//  Version:       1.0
#define ID_DEFAULT_REAL     3

//  Version:       1.0
#define ID_DEFAULT_IMAG 4

//  Version:       1.0
#define ID_DEFAULT_RX 5

//  ==========================================================
//  The following IDs are the legal values for
//  tagTriggerTypeID
//  ==========================================================

//  Version:       1.0
#define ID_TRIG_NONE  0x00

//  Version:       1.0
#define ID_TRIG_LOW   0x01

//  Version:       1.0
#define ID_TRIG_HIGH  0x02

//  Version:       1.0
#define ID_TRIG_RATE  0x04

//  Version:       1.0
#define ID_TRIG_SHAPE 0x08

//  Version:       1.0
#define ID_TRIG_OTHER 0x10

//  ==========================================================
//  The following IDs are the legal values for
//  tagXDTransformerTypeID
//  ==========================================================

//  Version:       1.0
#define ID_XFORMER_TYPE_CT 2

//  Version:       1.0
#define ID_XFORMER_TYPE_PT 1

//  ==========================================================
//  The following IDs are the legal values for
//  tagTriggerMethodID
//  ==========================================================

//  Version:       1.0
#define ID_TRIGGER_METH_NONE 0

//  Description:   A specific channel (or channels) caused the trigger; should be used with tagChannelTriggerIdx to specify which channels.
//  Version:       1.0
#define ID_TRIGGER_METH_CHANNEL 1

//  Version:       1.0
#define ID_TRIGGER_METH_PERIODIC 2

//  Version:       1.0
#define ID_TRIGGER_METH_EXTERNAL 3

//  Description:   Periodic Statistical Data
//  Version:       1.5
#define ID_TRIGGER_METH_PERIODIC_STATS 4

//  ==========================================================
//  The following IDs are the legal values for
//  tagQuantityCharacteristicID
//  ==========================================================

//  Version:       1.5
const GUID ID_QC_NONE = { 0xa6b31adf, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Instantaneous f(t)
//  Version:       1.5
const GUID ID_QC_INSTANTANEOUS = { 0xa6b31add, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Spectra F(F)
//  Version:       1.5
const GUID ID_QC_SPECTRA = { 0xa6b31ae9, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Peak value
//  Version:       1.5
const GUID ID_QC_PEAK = { 0xa6b31ae2, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   RMS value
//  Version:       1.5
const GUID ID_QC_RMS = { 0xa6b31ae5, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Harmonic RMS
//  Version:       1.5
const GUID ID_QC_HRMS = { 0xa6b31adc, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Frequency
//  Version:       1.5
const GUID ID_QC_FREQUENCY = { 0x7ef68af, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Total harmonic distortion (%)
//  Version:       1.5
const GUID ID_QC_TOTAL_THD = { 0xa6b31aec, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Even harmonic distortion (%)
//  Version:       1.5
const GUID ID_QC_EVEN_THD = { 0xa6b31ad4, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Odd harmonic distortion (%)
//  Version:       1.5
const GUID ID_QC_ODD_THD = { 0xa6b31ae0, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Crest factor
//  Version:       1.5
const GUID ID_QC_CREST_FACTOR = { 0xa6b31ad2, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Form factor
//  Version:       1.5
const GUID ID_QC_FORM_FACTOR = { 0xa6b31adb, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Arithmetic sum
//  Version:       1.5
const GUID ID_QC_ARITH_SUM = { 0xa6b31ad0, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Zero sequence component unbalance (%)
//  Version:       1.5
const GUID ID_QC_S0S1 = { 0xa6b31ae7, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Negative sequence component unbalance (%)
//  Version:       1.5
const GUID ID_QC_S2S1 = { 0xa6b31ae8, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Positive sequence component
//  Version:       1.5
const GUID ID_QC_SPOS = { 0xa6b31aea, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Negative sequence component
//  Version:       1.5
const GUID ID_QC_SNEG = { 0xd71a4b91, 0x3c92, 0x11d4, { 0x9f, 0x2c, 0x0, 0x20, 0x78, 0xe0, 0xb7, 0x23 } };

//  Description:   Zero sequence component
//  Version:       1.5
const GUID ID_QC_SZERO = { 0xd71a4b92, 0x3c92, 0x11d4, { 0x9f, 0x2c, 0x0, 0x20, 0x78, 0xe0, 0xb7, 0x23 } };

//  Description:   Imbalance by max deviation from average
//  Version:       1.5
const GUID ID_QC_AVG_IMBAL = { 0xa6b31ad1, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Total THD normalized to RMS
//  Version:       1.5
const GUID ID_QC_TOTAL_THD_RMS = { 0xf3d216e0, 0x2aa5, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Odd THD normalized to RMS
//  Version:       1.5
const GUID ID_QC_ODD_THD_RMS = { 0xf3d216e1, 0x2aa5, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Even THD normalized to RMS
//  Version:       1.5
const GUID ID_QC_EVEN_THD_RMS = { 0xf3d216e2, 0x2aa5, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };;

//  Description:   Total Interharmonic Distortion
//  Version:       1.5
const GUID ID_QC_TID = { 0xf3d216e3, 0x2aa5, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Total Interharmonic Distortion Normalized to RMS
//  Version:       1.5
const GUID ID_QC_TID_RMS = { 0xf3d216e4, 0x2aa5, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:    Interharmonic RMS
//  Version:       1.5
const GUID ID_QC_IHRMS = { 0xf3d216e5, 0x2aa5, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Spectra by Harmonic Group index
//  Version:       1.5
const GUID ID_QC_SPECTRA_HGROUP = { 0x53be6ba8, 0x789, 0x455b, { 0x9a, 0x95, 0xda, 0x12, 0x86, 0x83, 0xdd, 0xa7 } };

//  Description:   Spectra by Interharmonic Group Index
//  Version:       1.5
const GUID ID_QC_SPECTRA_IGROUP = { 0x5e51e006, 0x9c95, 0x4c5e, { 0x87, 0x8f, 0x7c, 0xa8, 0x7c, 0xd, 0x2a, 0xe } };

//  Description:   TIF
//  Version:       1.5
const GUID ID_QC_TIF = { 0xa6b31aeb, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Flicker average RMS value
//  Version:       1.5
const GUID ID_QC_FLKR_MAG_AVG = { 0xa6b31ad6, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   dV/V base
//  Version:       1.5
const GUID ID_QC_FLKR_MAX_DVV = { 0xa6b31ad8, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Frequence of maximum flicker harmonic
//  Version:       1.5
const GUID ID_QC_FLKR_FREQ_MAX = { 0xa6b31ad5, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Magnitude of maximum flicker harmonic
//  Version:       1.5
const GUID ID_QC_FLKR_MAG_MAX = { 0xa6b31ad7, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Spectrum weighted average
//  Version:       1.5
const GUID ID_QC_FLKR_WGT_AVG = { 0xa6b31ada, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Flicker spectrum VRMS(F)
//  Version:       1.5
const GUID ID_QC_FLKR_SPECTRUM = { 0xa6b31ad9, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Short Term Flicker
//  Version:       1.5
const GUID ID_QC_FLKR_PST = { 0x515bf320, 0x71ca, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Long Term Flicker
//  Version:       1.5
const GUID ID_QC_FLKR_PLT = { 0x515bf321, 0x71ca, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   TIF normalized to RMS
//  Version:       1.5
const GUID ID_QC_TIF_RMS = { 0xf3d216e6, 0x2aa5, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Sliding PLT
//  Version:       1.5
const GUID ID_QC_FLKR_PLTSLIDE = { 0x2257ec05, 0x6ea, 0x4709, { 0xb4, 0x3a, 0xc, 0x0, 0x53, 0x4d, 0x55, 0x4a } };

//  Version:       1.5
const GUID ID_QC_FLKR_PILPF = { 0x4d693eec, 0x5d1d, 0x4531, { 0x99, 0x3a, 0x79, 0x3b, 0x53, 0x56, 0xc6, 0x3d } };

//  Version:       1.5
const GUID ID_QC_FLKR_PIMAX = { 0x126de61c, 0x6691, 0x4d16, { 0x8f, 0xdf, 0x46, 0x48, 0x2b, 0xca, 0x46, 0x94 } };

//  Version:       1.5
const GUID ID_QC_FLKR_PIROOT = { 0xe065b621, 0xffdb, 0x4598, { 0x93, 0x30, 0x4d, 0x9, 0x35, 0x39, 0x88, 0xb6 } };;

//  Version:       1.5
const GUID ID_QC_FLKR_PIROOTLPF = { 0x7d11f283, 0x1ce7, 0x4e58, { 0x8a, 0xf0, 0x79, 0x4, 0x87, 0x93, 0xb8, 0xa7 } };

//  Description:   IT
//  Version:       1.5
const GUID ID_QC_IT = { 0xa6b31ade, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   RMS value of current for a demand interval
//  Version:       1.5
const GUID ID_QC_RMS_DEMAND = { 0x7ef68a0, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Transformer Derating Factor
//  Version:       1.5
const GUID ID_QC_ANSI_TDF = { 0x8786ca10, 0x9113, 0x11d3, { 0xb9, 0x30, 0x0, 0x50, 0xda, 0x2b, 0x1f, 0x4d } };

//  Description:   Transformer K Factor
//  Version:       1.5
const GUID ID_QC_K_FACTOR = { 0x8786ca11, 0x9113, 0x11d3, { 0xb9, 0x30, 0x0, 0x50, 0xda, 0x2b, 0x1f, 0x4d } };

//  Description:   Total Demand Distortion
//  Version:       1.5
const GUID ID_QC_TDD = { 0xf3d216e7, 0x2aa5, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Peak Demand Current
//  Version:       1.5
const GUID ID_QC_RMS_PEAK_DEMAND = { 0x72e82a44, 0x336c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Real power (watts)
//  Version:       1.5
const GUID ID_QC_P = { 0xa6b31ae1, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Reactive power (VAR)
//  Version:       1.5
const GUID ID_QC_Q = { 0xa6b31ae4, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Apparent power (VA)
//  Version:       1.5
const GUID ID_QC_S = { 0xa6b31ae6, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   True Power Factor - (Vrms * Irms) / P.
//  Version:       1.5
const GUID ID_QC_PF = { 0xa6b31ae3, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Displacement Factor - Cosine of the phase angle between fundamental frequency voltage and current phasors.
//  Version:       1.5
const GUID ID_QC_DF = { 0xa6b31ad3, 0xb451, 0x11d1, { 0xae, 0x17, 0x0, 0x60, 0x8, 0x3a, 0x26, 0x28 } };

//  Description:   Value of active power for a demand interval
//  Version:       1.5
const GUID ID_QC_P_DEMAND = { 0x7ef68a1, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of reactive power for a demand interval
//  Version:       1.5
const GUID ID_QC_Q_DEMAND = { 0x7ef68a2, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of apparent power for a demand interval
//  Version:       1.5
const GUID ID_QC_S_DEMAND = { 0x7ef68a3, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of displacement power factor for a demand interval
//  Version:       1.5
const GUID ID_QC_DF_DEMAND = { 0x7ef68a4, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of true power factor for a demand interval
//  Version:       1.5
const GUID ID_QC_PF_DEMAND = { 0x7ef68a5, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Predicted value of active power for current demand interval
//  Version:       1.5
const GUID ID_QC_P_PRED_DEMAND = { 0x672d0305, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Predicted value of reactive power for current demand interval
//  Version:       1.5
const GUID ID_QC_Q_PRED_DEMAND = { 0x672d0306, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Pedicted value of apparent power for current demand interval
//  Version:       1.5
const GUID ID_QC_S_PRED_DEMAND = { 0x672d0307, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of active power coincident with reactive power demand
//  Version:       1.5
const GUID ID_QC_P_CO_Q_DEMAND = { 0x672d030a, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of active power coincident with apparent power demand
//  Version:       1.5
const GUID ID_QC_P_CO_S_DEMAND = { 0x672d030b, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of reative power coincident with active power demand
//  Version:       1.5
const GUID ID_QC_Q_CO_P_DEMAND = { 0x672d030d, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of reactive power coincident with apparent power demand
//  Version:       1.5
const GUID ID_QC_Q_CO_S_DEMAND = { 0x672d030e, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of displacement power factor coincident with apparent power demand
//  Version:       1.5
const GUID ID_QC_DF_CO_S_DEMAND = { 0x7ef68ad, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of true power factor coincident with apparent power demand
//  Version:       1.5
const GUID ID_QC_PF_CO_S_DEMAND = { 0x7ef68ae, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of true power factor coincident with active power demand
//  Version:       1.5
const GUID ID_QC_PF_CO_P_DEMAND = { 0x672d0308, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of true power factor coincident with reactive power demand
//  Version:       1.5
const GUID ID_QC_PF_CO_Q_DEMAND = { 0x672d0309, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of the power angle at fundamental
//  Version:       1.5
const GUID ID_QC_ANGLE_FUND = { 0x672d030f, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of the reactive power at fundamental frequency
//  Version:       1.5
const GUID ID_QC_Q_FUND = { 0x672d0310, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   True Power Factor - IEEE vector calculations
//  Version:       1.5
const GUID ID_QC_PF_VECTOR = { 0x672d0311, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Displacement Factor - IEEE vector calculations
//  Version:       1.5
const GUID ID_QC_DF_VECTOR = { 0x672d0312, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of apparent power - IEEE vector calculations
//  Version:       1.5
const GUID ID_QC_S_VECTOR = { 0x672d0314, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of fundamental frequency apparent power - IEEE vector calculations
//  Version:       1.5
const GUID ID_QC_S_VECTOR_FUND = { 0x672d0315, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of fundamental frequency apparent power
//  Version:       1.5
const GUID ID_QC_S_FUND = { 0x672d0316, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Apparent power coincident with active power demand
//  Version:       1.5
const GUID ID_QC_S_CO_P_DEMAND = { 0x672d0317, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Apparent power coincident with reactive power demand
//  Version:       1.5
const GUID ID_QC_S_CO_Q_DEMAND = { 0x672d0318, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   True Power Factor - IEEE arithmetic calculations
//  Version:       1.5
const GUID ID_QC_PF_ARITH = { 0x1c39fb00, 0xa6aa, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Displacement Factor - IEEE Arithmetic calculations
//  Version:       1.5
const GUID ID_QC_DF_ARITH = { 0x1c39fb01, 0xa6aa, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of apparent power - IEEE Arithmetic calculations
//  Version:       1.5
const GUID ID_QC_S_ARITH = { 0x1c39fb02, 0xa6aa, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of fundamental frequency apparent power - IEEE Arithmetic calculations
//  Version:       1.5
const GUID ID_QC_S_ARITH_FUND = { 0x1c39fb03, 0xa6aa, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Peak Apparent Power Demand
//  Version:       1.5
const GUID ID_QC_S_PEAK_DEMAND = { 0x72e82a43, 0x336c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Peak Reactive Power Demand
//  Version:       1.5
const GUID ID_QC_Q_PEAK_DEMAND = { 0x72e82a42, 0x336c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Peak Active Power Demand
//  Version:       1.5
const GUID ID_QC_P_PEAK_DEMAND = { 0x72e82a41, 0x336c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Net Harmonic Actve Power
//  Version:       1.5
const GUID ID_QC_P_HARMONIC = { 0xb82b5c80, 0x55c7, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Arithmetic sum Harmonic Actve Power
//  Version:       1.5
const GUID ID_QC_P_HARMONIC_UNSIGNED = { 0xb82b5c81, 0x55c7, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of fundamental frequency real power
//  Version:       1.5
const GUID ID_QC_P_FUND = { 0x1cdda475, 0x1ebb, 0x42d8, { 0x80, 0x87, 0xd0, 0x1b, 0xb, 0x5c, 0xfa, 0x97 } };

//  Description:   Value of active power integrated over time (Energy - watt-hours)
//  Version:       1.5
const GUID ID_QC_P_INTG = { 0x7ef68a6, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of active power integrated over time (Energy - watt-hours) in the positive direction (toward load).
//  Version:       1.5
const GUID ID_QC_P_INTG_POS = { 0x7ef68a7, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of active fund. Freq. power integrated over time (Energy - watt-hours) in the positive direction (toward load).
//  Version:       1.5
const GUID ID_QC_P_INTG_POS_FUND = { 0x672d0300, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of active power integrated over time (Energy - watt-hours) in the negative direction (away from load).
//  Version:       1.5
const GUID ID_QC_P_INTG_NEG = { 0x7ef68a8, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of active fund. Freq.  power integrated over time (Energy - watt-hours) in the negative direction (away from load).
//  Version:       1.5
const GUID ID_QC_P_INTG_NEG_FUND = { 0x672d0301, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of reactive power integrated over time (var-hours)
//  Version:       1.5
const GUID ID_QC_Q_INTG = { 0x7ef68a9, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of reactive power integrated over time (Energy - watt-hours) in the positive direction (toward load).
//  Version:       1.5
const GUID ID_QC_Q_INTG_POS = { 0x7ef68aa, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of fund. Freq. reactive power integrated over time (Energy - watt-hours) in the positive direction (toward load).
//  Version:       1.5
const GUID ID_QC_Q_INTG_POS_FUND = { 0x672d0303, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of fund. Freq. reactive power integrated over time (Energy - watt-hours) in the negative direction (away from load).
//  Version:       1.5
const GUID ID_QC_Q_INTG_NEG_FUND = { 0x672d0304, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of reactive power integrated over time (Energy - watt-hours) in the negative direction (away from load).
//  Version:       1.5
const GUID ID_QC_Q_INTG_NEG = { 0x7ef68ab, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of apparent power integrated over time (VA-hours)
//  Version:       1.5
const GUID ID_QC_S_INTG = { 0x7ef68ac, 0x9ff5, 0x11d2, { 0xb3, 0xb, 0x0, 0x60, 0x8, 0xb3, 0x71, 0x83 } };

//  Description:   Value of fundamental frequency apparent power integrated over time (VA-hours)
//  Version:       1.5
const GUID ID_QC_S_INTG_FUND = { 0x672d0313, 0x7810, 0x11d4, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of active power integrated over time (Energy - watt-hours)
//  Version:       1.5
const GUID ID_QC_P_IVL_INTG = { 0xf098a9a0, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of active power integrated over time (Energy - watt-hours) in the positive direction (toward load).
//  Version:       1.5
const GUID ID_QC_P_IVL_INTG_POS = { 0xf098a9a1, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of active fund. Freq. power integrated over time (Energy - watt-hours) in the positive direction (toward load).
//  Version:       1.5
const GUID ID_QC_P_IVL_INTG_POS_FUND = { 0xf098a9a2, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of active power integrated over time (Energy - watt-hours) in the negative direction (away from load).
//  Version:       1.5
const GUID ID_QC_P_IVL_INTG_NEG = { 0xf098a9a3, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of active fund. Freq.  power integrated over time (Energy - watt-hours) in the negative direction (away from load).
//  Version:       1.5
const GUID ID_QC_P_IVL_INTG_NEG_FUND = { 0xf098a9a4, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of reactive power integrated over time (var-hours)
//  Version:       1.5
const GUID ID_QC_Q_IVL_INTG = { 0xf098a9a5, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of reactive power integrated over time (Energy - watt-hours) in the positive direction (toward load).
//  Version:       1.5
const GUID ID_QC_Q_IVL_INTG_POS = { 0xf098a9a6, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of fund. Freq. reactive power integrated over time (Energy - watt-hours) in the positive direction (toward load).
//  Version:       1.5
const GUID ID_QC_Q_IVL_INTG_POS_FUND = { 0xf098a9a7, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of fund. Freq. reactive power integrated over time (Energy - watt-hours) in the negative direction (away from load).
//  Version:       1.5
const GUID ID_QC_Q_IVL_INTG_NEG_FUND = { 0xf098a9a8, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of reactive power integrated over time (Energy - watt-hours) in the negative direction (away from load).
//  Version:       1.5
const GUID ID_QC_Q_IVL_INTG_NEG = { 0xf098a9a9, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of apparent power integrated over time (VA-hours)
//  Version:       1.5
const GUID ID_QC_S_IVL_INTG = { 0xf098a9aa, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Value of fundamental frequency apparent power integrated over time (VA-hours)
//  Version:       1.5
const GUID ID_QC_S_IVL_INTG_FUND = { 0xf098a9ab, 0x3ee4, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   D Axis Components
//  Version:       1.5
const GUID ID_QC_DAXISFIELD = { 0xd347ba65, 0xe34c, 0x11d4, { 0x82, 0xd9, 0x0, 0xe0, 0x98, 0x72, 0xa0, 0x94 } };

//  Description:   Q Axis Components
//  Version:       1.5
const GUID ID_QC_QAXIS = { 0xd347ba64, 0xe34c, 0x11d4, { 0x82, 0xd9, 0x0, 0xe0, 0x98, 0x72, 0xa0, 0x94 } };

//  Description:   Rotational Position
//  Version:       1.5
const GUID ID_QC_ROTATIONAL = { 0xd347ba62, 0xe34c, 0x11d4, { 0x82, 0xd9, 0x0, 0xe0, 0x98, 0x72, 0xa0, 0x94 } };

//  Description:   D Axis Components
//  Version:       1.5
const GUID ID_QC_DAXIS = { 0xd347ba63, 0xe34c, 0x11d4, { 0x82, 0xd9, 0x0, 0xe0, 0x98, 0x72, 0xa0, 0x94 } };

//  Description:   Linear Position
//  Version:       1.5
const GUID ID_QC_LINEAR = { 0xd347ba61, 0xe34c, 0x11d4, { 0x82, 0xd9, 0x0, 0xe0, 0x98, 0x72, 0xa0, 0x94 } };

//  Description:   Transfer function
//  Version:       1.5
const GUID ID_QC_TRANSFERFUNC = { 0x5202bd07, 0x245c, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  Description:   Status Data
//  Version:       1.5
const GUID ID_QC_STATUS = { 0xb82b5c83, 0x55c7, 0x11d5, { 0xa4, 0xb3, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };

//  ==========================================================
//  The following IDs are the legal values for
//  tagQuantityMeasuredID
//  ==========================================================

//  Description:   None or not applicable.
//  Version:       1.5
#define ID_QM_NONE 0

//  Description:   Voltage.
//  Version:       1.5
#define ID_QM_VOLTAGE 1

//  Description:   Current.
//  Version:       1.5
#define ID_QM_CURRENT 2

//  Description:   Power - includes all data for a quantity or characteristic derived from multiplying voltage and current components.
//  Version:       1.5
#define ID_QM_POWER 3

//  Description:   Energy - includes all data from an integration of a quantity or characteristic derived from multiplying voltage and current components together.
//  Version:       1.5
#define ID_QM_ENERGY 4

//  Description:   Temperature.
//  Version:       1.5
#define ID_QM_TEMPERATURE 5

//  Description:   Pressure.
//  Version:       1.5
#define ID_QM_PRESSURE 6

//  Description:   Charge.
//  Version:       1.5
#define ID_QM_CHARGE 7

//  Description:   Electrical field.
//  Version:       1.5
#define ID_QM_EFIELD 8

//  Description:   Magnetic field.
//  Version:       1.5
#define ID_QM_MFIELD 9

//  Description:   Velocity
//  Version:       1.5
#define ID_QM_VELOCITY 10

//  Description:   Compass Bearing
//  Version:       1.5
#define ID_QM_BEARING 11

//  Description:   Applied Force, Electrical, Mechanical, etc.
//  Version:       1.5
#define ID_QM_FORCE 12

//  Description:   Torque
//  Version:       1.5
#define ID_QM_TORQUE 13

//  Description:   Spacial Position
//  Version:       1.5
#define ID_QM_POSITION 14

//  Description:   Flux linkage Weber Turns
//  Version:       1.5
#define ID_QM_FLUXLINKAGE 15

//  Description:   Magnetic field Density
//  Version:       1.5
#define ID_QM_FLUXDENSITY 16

//  Description:   Status Data
//  Version:       1.5
#define ID_QM_STATUS 17

//  ==========================================================
//  The following IDs are the legal values for
//  tagChanTriggerTypeID
//  ==========================================================

//  Description:   No transition - should not happen
//  Version:       1.5
#define ID_CTT_NONE 0

//  Description:   Normal to low transition
//  Version:       1.5
#define ID_CTT_NORMAL_TO_LO 1

//  Description:   Normal to low low transition
//  Version:       1.5
#define ID_CTT_NORMAL_TO_LO_LO 2

//  Description:   Normal to High transition
//  Version:       1.5
#define ID_CTT_NORMAL_TO_HI 3

//  Description:   Normal to High High transition
//  Version:       1.5
#define ID_CTT_NORMAL_TO_HI_HI 4

//  Description:   Low Low to Lo transition
//  Version:       1.5
#define ID_CTT_LO_LO_TO_LO 5

//  Description:   Low Low to Normal transition
//  Version:       1.5
#define ID_CTT_LO_LO_TO_NORMAL 6

//  Description:   Low Low to High transition
//  Version:       1.5
#define ID_CTT_LO_LO_TO_HI 7

//  Description:   Low Low to High High transition
//  Version:       1.5
#define ID_CTT_LO_LO_TO_HI_HI 8

//  Description:   Low to Low Low transition
//  Version:       1.5
#define ID_CTT_LO_TO_LO_LO 9

//  Description:   Low to Normal transition
//  Version:       1.5
#define ID_CTT_LO_TO_NORMAL 10

//  Description:   Low to High transition
//  Version:       1.5
#define ID_CTT_LO_TO_HI 11

//  Description:   Low to High High transition
//  Version:       1.5
#define ID_CTT_LO_TO_HI_HI 12

//  Description:   High to Low Low transition
//  Version:       1.5
#define ID_CTT_HI_TO_LO_LO 13

//  Description:   High to Low transition
//  Version:       1.5
#define ID_CTT_HI_TO_LO 14

//  Description:   High to Normal transition
//  Version:       1.5
#define ID_CTT_HI_TO_NORMAL 15

//  Description:   High to High High transition
//  Version:       1.5
#define ID_CTT_HI_TO_HI_HI 16

//  Description:   High High to Low Low transition
//  Version:       1.5
#define ID_CTT_HI_HI_TO_LO_LO 17

//  Description:   High High to Low transition
//  Version:       1.5
#define ID_CTT_HI_HI_TO_LO 18

//  Description:   High High to Normal transition
//  Version:       1.5
#define ID_CTT_HI_HI_TO_NORMAL 19

//  Description:   High High to High transition
//  Version:       1.5
#define ID_CTT_HI_HI_TO_HI 20

//  Description:   Deadband transition lower
//  Version:       1.5
#define ID_CTT_DB_LO 21

//  Description:   Deadband transition higher
//  Version:       1.5
#define ID_CTT_DB_HI 22

//  Description:   Hardware initiated trigger based on periodic trigger rule
//  Version:       1.5
#define ID_CTT_PERIODIC 23

//  Description:   User commanded sample - button was pushed
//  Version:       1.5
#define ID_CTT_MANUAL 24

//  Description:   Channel triggered because of internal cross-trigger rule.  tagCrossTriggerChanIdx is index of channel that triggered.
//  Version:       1.5
#define ID_CTT_INT_CROSS_TRIG 25

//  Description:   Channel triggered because of external cross-trigger rule.  tagCrossTriggerChanIdx is index of channel that triggered on external device.  tagCrossTriggerDeviceName is the name of the external device that initiated the cross trigger.
//  Version:       1.5
#define ID_CTT_EXT_CROSS_TRIG 26

//  Description:   Channel triggered because of hardware or software module, rule or algorithm
//  Version:       1.5
#define ID_CTT_MODULE 27

//  Description:   Rate of change threshold exceeded (dV/dt or dI/dt)
//  Version:       1.5
#define ID_CTT_RATE 28

//  ==========================================================
//  The following IDs are the legal values for
//  tagSettingPhysicalConnection
//  ==========================================================

//  Description:   Single phase connection, 1 voltage, 1 current
//  Version:       1.5
#define ID_SINGLE_PHASE 1

//  Description:   Delta Connected 2 Element Monitoring
//  Version:       1.5
#define ID_2ELEMENT_DELTA 2

//  Description:   Wye 2 Voltages, 3 Currents
//  Version:       1.5
#define ID_2_5ELEMENT_WYE 3

//  Description:   3 Voltages, 3 Currents
//  Version:       1.5
#define ID_3ELMENT_WYE 4

//  Description:   Delta Connection, 3 voltages, 3 currents
//  Version:       1.5
#define ID_3ELEMENT_DELTA 5

//  Description:   Split Single Phase,  2 Volage, 2 Current
//  Version:       1.5
#define ID_SPLIT_PHASE 6

//  Description:   2 Phase, 2 Voltages, 2 Currents
//  Version:       1.5
#define ID_2ELEMENT_2PHASE 7



#endif  //  PQDIF_ID_H


