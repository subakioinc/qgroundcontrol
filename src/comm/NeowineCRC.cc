#include <inttypes.h>
#include <iostream>

#include "NeowineCRC.h"

Q_DECLARE_METATYPE(mavlink_message_t)


void NeowineCRC::encrypt_and_crcupdate(mavlink_message_t *msg)
{
	crcs[36] = 222;
	crcs[83] = 22;
	crcs[111] = 34;
	crcs[140] = 181;
	crcs[141] = 47;
	crcs[231] = 105;
	crcs[245] = 130;
	// crcs[331] = 91;
	//printf("처음 : msg->payload64, msg->crc : %lld , %d \n", msg->payload64[0], msg->checksum);
	//uint64_t check_value = msg->payload64[0] & 0xff;
	//printf("메시지 초기값 : %lld", check_value);
	uint16_t init_checksum = msg->checksum;
	uint64_t firstItem = msg->payload64[0];
	firstItem = firstItem ^ 0xff;
	msg->payload64[0] = firstItem;
	
	crcupdate(msg);
}

void NeowineCRC::decrypt(mavlink_message_t *msg)
{
	crcs[36] = 222;
	crcs[83] = 22;
	crcs[111] = 34;
	crcs[140] = 181;
	crcs[141] = 47;
	crcs[231] = 105;
	crcs[245] = 130;
	// crcs[331] = 91;
	//printf("처음 : msg->payload64, msg->crc : %lld , %d \n", msg->payload64[0], msg->checksum);
	//uint64_t check_value = msg->payload64[0] & 0xff;
	//printf("메시지 초기값 : %lld", check_value);
	uint16_t init_checksum = msg->checksum;
	uint64_t firstItem = msg->payload64[0];
	firstItem = firstItem ^ 0xff;
	msg->payload64[0] = firstItem;
}


uint16_t NeowineCRC::crc_calculate(const uint8_t* pBuffer, uint16_t length)
{
        uint16_t crcTmp;
        crc_init(&crcTmp);
		while (length--) {
                crc_accumulate(*pBuffer++, &crcTmp);
        }
        return crcTmp;
}

void NeowineCRC::crc_accumulate_buffer(uint16_t *crcAccum, const char *pBuffer, uint16_t length)
{
	const uint8_t *p = (const uint8_t *)pBuffer;
	while (length--) {
                crc_accumulate(*p++, crcAccum);
        }
}

void NeowineCRC::crc_accumulate(uint8_t data, uint16_t *crcAccum)
{
	/*Accumulate one byte of data into the CRC*/
        uint8_t tmp;

        tmp = data ^ (uint8_t)(*crcAccum &0xff);
        tmp ^= (tmp<<4);
        *crcAccum = (*crcAccum>>8) ^ (tmp<<8) ^ (tmp <<3) ^ (tmp>>4);
}

void NeowineCRC::crc_init(uint16_t* crcAccum)
{
		#define X25_INIT_CRC 0xffff
        *crcAccum = X25_INIT_CRC;
}
void NeowineCRC::crcupdate(mavlink_message_t* msg)
{
	#define _MAV_PAYLOAD(msg) ((const char *)(&((msg)->payload64[0])))
    #define _MAV_PAYLOAD_NON_CONST(msg) ((char *)(&((msg)->payload64[0])))

    #define mavlink_ck_a(msg) *((msg)->len + (uint8_t *)_MAV_PAYLOAD_NON_CONST(msg))
    #define mavlink_ck_b(msg) *(((msg)->len+(uint16_t)1) + (uint8_t *)_MAV_PAYLOAD_NON_CONST(msg))

    #define MAVLINK_STX_MAVLINK1 0xFE

    uint8_t header_len = MAVLINK_CORE_HEADER_LEN+1;
    uint8_t buf[MAVLINK_CORE_HEADER_LEN+1];

    bool mavlink1 = false;
    if (msg->magic == MAVLINK_STX_MAVLINK1) 
    {
        mavlink1 = true;
    }
    
    // form the header as a byte array for the crc
	buf[0] = msg->magic;
	buf[1] = msg->len;
	if (mavlink1) {
		buf[2] = msg->seq;
		buf[3] = msg->sysid;
		buf[4] = msg->compid;
		buf[5] = msg->msgid & 0xFF;
	} else {
		buf[2] = msg->incompat_flags;
		buf[3] = msg->compat_flags;
		buf[4] = msg->seq;
		buf[5] = msg->sysid;
		buf[6] = msg->compid;
		buf[7] = msg->msgid & 0xFF;
		buf[8] = (msg->msgid >> 8) & 0xFF;
		buf[9] = (msg->msgid >> 16) & 0xFF;
	}
	
	uint16_t checksum = crc_calculate(&buf[1], header_len-1);
	crc_accumulate_buffer(&checksum, _MAV_PAYLOAD(msg), msg->len);
 	uint8_t crc_extra = msg->msgid >= crcs.size() ? 0 : crcs.at(msg->msgid) ;
	crc_accumulate(crc_extra, &checksum);
	mavlink_ck_a(msg) = (uint8_t)(checksum & 0xFF);
	mavlink_ck_b(msg) = (uint8_t)(checksum >> 8);

	msg->checksum = checksum;
}