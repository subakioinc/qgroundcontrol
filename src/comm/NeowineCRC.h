#include <QString>
#include "MAVLinkProtocol.h"


class NeowineCRC {
public:
	NeowineCRC();
	//neowine
	void encrypt_and_crcupdate(mavlink_message_t *msg);
	void decrypt(mavlink_message_t *msg);

    //neowine CRC check
	uint16_t crc_calculate(const uint8_t* pBuffer, uint16_t length);
	void crc_accumulate_buffer(uint16_t *crcAccum, const char *pBuffer, uint16_t length);
	void crc_accumulate(uint8_t data, uint16_t *crcAccum);
	void crc_init(uint16_t* crcAccum);
	void crcupdate(mavlink_message_t* msg);

private:
	std::map< uint16_t, uint8_t > crc_map;

};