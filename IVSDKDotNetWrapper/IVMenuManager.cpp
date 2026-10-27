#include "pch.h"
#include "IVMenuManager.h"

namespace IVSDKDotNet
{
	// - - - Methods / Functions - - -
	// Modified 2026-10-27 by bassisthip63-ui (IV-SDK .NET Unofficial Beta for GTA IV 1.2.0.59): added the 1.2.0.59
	// address of the settings array (0xD60C60; the autosave, HUD, radar, clip capture and helicopter mouse settings
	// were checked to sit at the same offsets from it). Before, any version other than 1.0.7.0/1.0.8.0 read address 0.
	uint32_t IVMenuManager::GetSetting(eSettings setting)
	{
		return AddressSetter::GetRef<uint32_t>(0xCC7A00 + (uint32_t)setting, 0xCFC0D0 + (uint32_t)setting, 0xD60C60 + (uint32_t)setting);
	}
	void IVMenuManager::SetSetting(eSettings setting, uint32_t value)
	{
		AddressSetter::GetRef<uint32_t>(0xCC7A00 + (uint32_t)setting, 0xCFC0D0 + (uint32_t)setting, 0xD60C60 + (uint32_t)setting) = value;
	}
}