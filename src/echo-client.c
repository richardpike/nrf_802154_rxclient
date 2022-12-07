/* echo-client.c - Networking echo client */

/*
 * Copyright (c) 2017 Intel Corporation.
 * Copyright (c) 2018 Nordic Semiconductor ASA.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * The echo-client application is acting as a client that is run in Zephyr OS,
 * and echo-server is run in the host acting as a server. The client will send
 * either unicast or multicast packets to the server which will reply the packet
 * back to the originator.
 *
 * In this sample application we create four threads that start to send data.
 * This might not be what you want to do in your app so caveat emptor.
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(net_echo_client_sample, LOG_LEVEL_DBG);

#include "nrf_802154.h"

static uint8_t rx_m_message[30];
bool datarx = false;

void main(void)
{
	// This is called for you - zephyr setup.
    //nrf_802154_init();

    nrf_802154_channel_set(20);

	nrf_802154_promiscuous_set(true);

	while(1)
	{
		nrf_802154_receive();
		if (datarx)
		{
			datarx = false;
			LOG_HEXDUMP_DBG(rx_m_message, 30, "received data");
		}
	}

}

void nrf_802154_received_raw(uint8_t * p_data, int8_t power, uint8_t lqi)
{
	memset(rx_m_message, 0xab, sizeof(rx_m_message));
    memcpy(rx_m_message, p_data, p_data[0]);
	datarx = true;
}