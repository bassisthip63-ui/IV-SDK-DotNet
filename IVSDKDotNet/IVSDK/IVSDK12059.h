// ================ IV-SDK .NET - Unofficial Beta for GTA IV 1.2.0.59 ================
//
// This file was added on 2026-10-27 by bassisthip63-ui (with the help of Claude, an AI model by Anthropic)
// as part of an UNOFFICIAL fork of IV-SDK .NET by ItsClonkAndre (https://github.com/ClonkAndre/IV-SDK-DotNet).
// It is licensed under the GNU General Public License v3, like the rest of IV-SDK .NET (see LICENSE).
// This is not an official IV-SDK .NET release. Please report problems with it to the fork, not to ItsClonkAndre.
//
// What it does
//   GTA IV 1.2.0.59 (Complete Edition) moved some fields of CVehicle, CPed and CPlayerInfo compared with
//   1.0.7.0 / 1.0.8.0. IV-SDK describes those classes with fixed member offsets, so they have to be built
//   differently for 1.2.0.59. Defining IVSDK_GTAIV_12059 selects the 1.2.0.59 layouts in CVehicle.h, CPed.h
//   and CPlayerInfo.h (each change is marked there with "IVSDK_GTAIV_12059").
//
//   A build WITH this define works on 1.2.0.59 only: on 1.0.7.0 / 1.0.8.0 those classes would read the wrong
//   fields. To build the normal 1.0.7.0 / 1.0.8.0 version of IV-SDK .NET, comment out the #define below.
//
// How the 1.2.0.59 layouts were found
//   By comparing the game's own native functions (about 280 field accesses) between GTAIV.exe 1.0.8.0 and
//   1.2.0.59, plus checks by hand in the disassembly. The rules, as offsets in 1.0.8.0 -> 1.2.0.59:
//     CVehicle     everything from 0x260 on                     -0x50
//     CPed         0x210-0x37C unchanged; ShootRate/Accuracy 0x388/0x389 -0x18; 0x3A8 on -0x10
//     CPlayerInfo  Stamina 0x414 +0x10; 0x4BC on +0xC
//   Not verified on 1.2.0.59 (kept at their 1.0.8.0 offsets, exactly as in the tested binary build):
//     CPlayerInfo::m_pPlayerPed2 (0x3F0) and the six m_nLast...Time timers (0x494-0x4A8),
//     the internal layout of PedWeapons (CPed + 0x2B0).
//
// The game version check for the two non-layout fixes (FindNativeAddress, IVMenuManager settings) is done at
// run time and does not depend on this define.

#pragma once

#define IVSDK_GTAIV_12059

#ifdef IVSDK_GTAIV_12059
	#define IVSDK_12059_OR(value1080, value12059) (value12059)
#else
	#define IVSDK_12059_OR(value1080, value12059) (value1080)
#endif
