/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <autoconf.h>
#include <fw_info.h>
#include <bl_storage_ext_api.h>
#include <tfm_plat_defs.h>

// TODO: Get (some of?) these from kconfig. EXT_API_REQUIRED might
// only be enabled for TF-M as it enables the REQ macro.
#define CONFIG_BL_STORAGE_EXT_API_REQUIRED 1
#define CONFIG_BL_STORAGE_EXT_API_ID 0x1300
#define CONFIG_BL_STORAGE_EXT_API_FLAGS 1
#define CONFIG_BL_STORAGE_EXT_API_VER 1
#define CONFIG_BL_STORAGE_EXT_API_MAX_VER 255


EXT_API_REQ(BL_STORAGE, 1, struct bl_storage_ext_api, bl_storage);

enum tfm_plat_err_t nrf_ext_api_req(void)
{
	printf("Hello world\r\n");

	size_t len = bl_storage->ext_api.implementation_id_len();

	printf("Bye world %d\r\n", len);
}

