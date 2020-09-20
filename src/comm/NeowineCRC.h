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
	uint8_t totalbyte;
	uint8_t aes_key[32] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};
private:
	std::map< uint16_t, uint8_t > crc_map;

};