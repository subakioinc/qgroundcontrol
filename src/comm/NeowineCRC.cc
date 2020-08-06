#include <inttypes.h>
#include <iostream>

#include "NeowineCRC.h"

Q_DECLARE_METATYPE(mavlink_message_t)


NeowineCRC::NeowineCRC()
{
	using namespace std;
	crc_map.insert(make_pair( 0  , 50 ));
	crc_map.insert(make_pair( 1  , 124 ));
	crc_map.insert(make_pair( 2  , 137 ));
	crc_map.insert(make_pair( 4  , 237 ));
	crc_map.insert(make_pair( 5  , 217 ));
	crc_map.insert(make_pair( 6  , 104 ));
	crc_map.insert(make_pair( 7  , 119 ));
	crc_map.insert(make_pair( 8  , 117 ));
	crc_map.insert(make_pair( 11  , 89 ));
	crc_map.insert(make_pair( 19  , 137 ));
	crc_map.insert(make_pair( 20  , 214 ));
	crc_map.insert(make_pair( 21  , 159 ));
	crc_map.insert(make_pair( 22  , 220 ));
	crc_map.insert(make_pair( 23  , 168 ));
	crc_map.insert(make_pair( 24  , 24 ));
	crc_map.insert(make_pair( 25  , 23 ));
	crc_map.insert(make_pair( 26  , 170 ));
	crc_map.insert(make_pair( 27  , 144 ));
	crc_map.insert(make_pair( 28  , 67 ));
	crc_map.insert(make_pair( 29  , 115 ));
	crc_map.insert(make_pair( 30  , 39 ));
	crc_map.insert(make_pair( 31  , 246 ));
	crc_map.insert(make_pair( 32  , 185 ));
	crc_map.insert(make_pair( 33  , 104 ));
	crc_map.insert(make_pair( 34  , 237 ));
	crc_map.insert(make_pair( 35  , 244 ));
	crc_map.insert(make_pair( 36  , 222 ));
	crc_map.insert(make_pair( 37  , 212 ));
	crc_map.insert(make_pair( 38  , 9 ));
	crc_map.insert(make_pair( 39  , 254 ));
	crc_map.insert(make_pair( 40  , 230 ));
	crc_map.insert(make_pair( 41  , 28 ));
	crc_map.insert(make_pair( 42  , 28 ));
	crc_map.insert(make_pair( 43  , 132 ));
	crc_map.insert(make_pair( 44  , 221 ));
	crc_map.insert(make_pair( 45  , 232 ));
	crc_map.insert(make_pair( 46  , 11 ));
	crc_map.insert(make_pair( 47  , 153 ));
	crc_map.insert(make_pair( 48  , 41 ));
	crc_map.insert(make_pair( 49  , 39 ));
	crc_map.insert(make_pair( 50  , 78 ));
	crc_map.insert(make_pair( 51  , 196 ));
	crc_map.insert(make_pair( 52  , 132 ));
	crc_map.insert(make_pair( 54  , 15 ));
	crc_map.insert(make_pair( 55  , 3 ));
	crc_map.insert(make_pair( 61  , 167 ));
	crc_map.insert(make_pair( 62  , 183 ));
	crc_map.insert(make_pair( 63  , 119 ));
	crc_map.insert(make_pair( 64  , 191 ));
	crc_map.insert(make_pair( 65  , 118 ));
	crc_map.insert(make_pair( 66  , 148 ));
	crc_map.insert(make_pair( 67  , 21 ));
	crc_map.insert(make_pair( 69  , 243 ));
	crc_map.insert(make_pair( 70  , 124 ));
	crc_map.insert(make_pair( 73  , 38 ));
	crc_map.insert(make_pair( 74  , 20 ));
	crc_map.insert(make_pair( 75  , 158 ));
	crc_map.insert(make_pair( 76  , 152 ));
	crc_map.insert(make_pair( 77  , 143 ));
	crc_map.insert(make_pair( 80  , 14 ));
	crc_map.insert(make_pair( 81  , 106 ));
	crc_map.insert(make_pair( 82  , 49 ));
	crc_map.insert(make_pair( 83  , 22 ));
	crc_map.insert(make_pair( 84  , 143 ));
	crc_map.insert(make_pair( 85  , 140 ));
	crc_map.insert(make_pair( 86  , 5 ));
	crc_map.insert(make_pair( 87  , 150 ));
	crc_map.insert(make_pair( 89  , 231 ));
	crc_map.insert(make_pair( 90  , 183 ));
	crc_map.insert(make_pair( 91  , 63 ));
	crc_map.insert(make_pair( 92  , 54 ));
	crc_map.insert(make_pair( 93  , 47 ));
	crc_map.insert(make_pair( 100  , 175 ));
	crc_map.insert(make_pair( 101  , 102 ));
	crc_map.insert(make_pair( 102  , 158 ));
	crc_map.insert(make_pair( 103  , 208 ));
	crc_map.insert(make_pair( 104  , 56 ));
	crc_map.insert(make_pair( 105  , 93 ));
	crc_map.insert(make_pair( 106  , 138 ));
	crc_map.insert(make_pair( 107  , 108 ));
	crc_map.insert(make_pair( 108  , 32 ));
	crc_map.insert(make_pair( 109  , 185 ));
	crc_map.insert(make_pair( 110  , 84 ));
	crc_map.insert(make_pair( 111  , 34 ));
	crc_map.insert(make_pair( 112  , 174 ));
	crc_map.insert(make_pair( 113  , 124 ));
	crc_map.insert(make_pair( 114  , 237 ));
	crc_map.insert(make_pair( 115  , 4 ));
	crc_map.insert(make_pair( 116  , 76 ));
	crc_map.insert(make_pair( 117  , 128 ));
	crc_map.insert(make_pair( 118  , 56 ));
	crc_map.insert(make_pair( 119  , 116 ));
	crc_map.insert(make_pair( 120  , 134 ));
	crc_map.insert(make_pair( 121  , 237 ));
	crc_map.insert(make_pair( 122  , 203 ));
	crc_map.insert(make_pair( 123  , 250 ));
	crc_map.insert(make_pair( 124  , 87 ));
	crc_map.insert(make_pair( 125  , 203 ));
	crc_map.insert(make_pair( 126  , 220 ));
	crc_map.insert(make_pair( 127  , 25 ));
	crc_map.insert(make_pair( 128  , 226 ));
	crc_map.insert(make_pair( 129  , 46 ));
	crc_map.insert(make_pair( 130  , 29 ));
	crc_map.insert(make_pair( 131  , 223 ));
	crc_map.insert(make_pair( 132  , 85 ));
	crc_map.insert(make_pair( 133  , 6 ));
	crc_map.insert(make_pair( 134  , 229 ));
	crc_map.insert(make_pair( 135  , 203 ));
	crc_map.insert(make_pair( 136  , 1 ));
	crc_map.insert(make_pair( 137  , 195 ));
	crc_map.insert(make_pair( 138  , 109 ));
	crc_map.insert(make_pair( 139  , 168 ));
	crc_map.insert(make_pair( 140  , 181 ));
	crc_map.insert(make_pair( 141  , 47 ));
	crc_map.insert(make_pair( 142  , 72 ));
	crc_map.insert(make_pair( 143  , 131 ));
	crc_map.insert(make_pair( 144  , 127 ));
	crc_map.insert(make_pair( 146  , 103 ));
	crc_map.insert(make_pair( 147  , 154 ));
	crc_map.insert(make_pair( 148  , 178 ));
	crc_map.insert(make_pair( 149  , 200 ));
	crc_map.insert(make_pair( 162  , 189 ));
	crc_map.insert(make_pair( 230  , 163 ));
	crc_map.insert(make_pair( 231  , 105 ));
	crc_map.insert(make_pair( 232  , 151 ));
	crc_map.insert(make_pair( 233  , 35 ));
	crc_map.insert(make_pair( 234  , 150 ));
	crc_map.insert(make_pair( 235  , 179 ));
	crc_map.insert(make_pair( 241  , 90 ));
	crc_map.insert(make_pair( 242  , 104 ));
	crc_map.insert(make_pair( 243  , 85 ));
	crc_map.insert(make_pair( 244  , 95 ));
	crc_map.insert(make_pair( 245  , 130 ));
	crc_map.insert(make_pair( 246  , 184 ));
	crc_map.insert(make_pair( 247  , 81 ));
	crc_map.insert(make_pair( 248  , 8 ));
	crc_map.insert(make_pair( 249  , 204 ));
	crc_map.insert(make_pair( 250  , 49 ));
	crc_map.insert(make_pair( 251  , 170 ));
	crc_map.insert(make_pair( 252  , 44 ));
	crc_map.insert(make_pair( 253  , 83 ));
	crc_map.insert(make_pair( 254  , 46 ));
	crc_map.insert(make_pair( 256  , 71 ));
	crc_map.insert(make_pair( 257  , 131 ));
	crc_map.insert(make_pair( 258  , 187 ));
	crc_map.insert(make_pair( 259  , 92 ));
	crc_map.insert(make_pair( 260  , 146 ));
	crc_map.insert(make_pair( 261  , 179 ));
	crc_map.insert(make_pair( 262  , 12 ));
	crc_map.insert(make_pair( 263  , 133 ));
	crc_map.insert(make_pair( 264  , 49 ));
	crc_map.insert(make_pair( 265  , 26 ));
	crc_map.insert(make_pair( 266  , 193 ));
	crc_map.insert(make_pair( 267  , 35 ));
	crc_map.insert(make_pair( 268  , 14 ));
	crc_map.insert(make_pair( 269  , 109 ));
	crc_map.insert(make_pair( 270  , 59 ));
	crc_map.insert(make_pair( 271  , 22 ));
	crc_map.insert(make_pair( 275  , 126 ));
	crc_map.insert(make_pair( 276  , 18 ));
	crc_map.insert(make_pair( 280  , 166 ));
	crc_map.insert(make_pair( 281  , 0 ));
	crc_map.insert(make_pair( 282  , 123 ));
	crc_map.insert(make_pair( 283  , 247 ));
	crc_map.insert(make_pair( 284  , 99 ));
	crc_map.insert(make_pair( 285  , 137 ));
	crc_map.insert(make_pair( 286  , 210 ));
	crc_map.insert(make_pair( 287  , 74 ));
	crc_map.insert(make_pair( 290  , 221 ));
	crc_map.insert(make_pair( 291  , 10 ));
	crc_map.insert(make_pair( 299  , 19 ));
	crc_map.insert(make_pair( 300  , 217 ));
	crc_map.insert(make_pair( 301  , 243 ));
	crc_map.insert(make_pair( 310  , 28 ));
	crc_map.insert(make_pair( 311  , 95 ));
	crc_map.insert(make_pair( 320  , 243 ));
	crc_map.insert(make_pair( 321  , 88 ));
	crc_map.insert(make_pair( 322  , 243 ));
	crc_map.insert(make_pair( 323  , 78 ));
	crc_map.insert(make_pair( 324  , 132 ));
	crc_map.insert(make_pair( 325  , 228 ));
	crc_map.insert(make_pair( 326  , 24 ));
	crc_map.insert(make_pair( 327  , 178 ));
	crc_map.insert(make_pair( 328  , 160 ));
	crc_map.insert(make_pair( 329  , 121 ));
	crc_map.insert(make_pair( 330  , 23 ));
	crc_map.insert(make_pair( 331  , 91 ));
	crc_map.insert(make_pair( 332  , 236 ));
	crc_map.insert(make_pair( 333  , 231 ));
	crc_map.insert(make_pair( 334  , 72 ));
	crc_map.insert(make_pair( 335  , 225 ));
	crc_map.insert(make_pair( 336  , 245 ));
	crc_map.insert(make_pair( 339  , 199 ));
	crc_map.insert(make_pair( 340  , 99 ));
	crc_map.insert(make_pair( 350  , 232 ));
	crc_map.insert(make_pair( 360  , 11 ));
	crc_map.insert(make_pair( 370  , 98 ));
	crc_map.insert(make_pair( 371  , 161 ));
	crc_map.insert(make_pair( 373  , 117 ));
	crc_map.insert(make_pair( 375  , 251 ));
	crc_map.insert(make_pair( 380  , 232 ));
	crc_map.insert(make_pair( 385  , 147 ));
	crc_map.insert(make_pair( 390  , 156 ));
	crc_map.insert(make_pair( 395  , 163 ));
	crc_map.insert(make_pair( 400  , 110 ));
	crc_map.insert(make_pair( 401  , 183 ));
	crc_map.insert(make_pair( 9000  , 113 ));
	crc_map.insert(make_pair( 9005  , 117 ));
	crc_map.insert(make_pair( 12900  , 114 ));
	crc_map.insert(make_pair( 12901  , 254 ));
	crc_map.insert(make_pair( 12902  , 49 ));
	crc_map.insert(make_pair( 12903  , 249 ));
	crc_map.insert(make_pair( 12904  , 203 ));
	crc_map.insert(make_pair( 12905  , 49 ));
	crc_map.insert(make_pair( 12915  , 62 ));
	crc_map.insert(make_pair( 10001  , 209 ));
	crc_map.insert(make_pair( 10002  , 186 ));
	crc_map.insert(make_pair( 10003  , 4 ));
	crc_map.insert(make_pair( 42000  , 227 ));
	crc_map.insert(make_pair( 42001  , 239 ));

}

void NeowineCRC::encrypt_and_crcupdate(mavlink_message_t *msg)
{
	// crcs[36] = 222;
	// crcs[83] = 22;
	// crcs[111] = 34;
	// crcs[140] = 181;
	// crcs[141] = 47;
	// crcs[231] = 105;
	// crcs[245] = 130;
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
	// crcs[36] = 222;
	// crcs[83] = 22;
	// crcs[111] = 34;
	// crcs[140] = 181;
	// crcs[141] = 47;
	// crcs[231] = 105;
	// crcs[245] = 130;
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
 	// uint8_t crc_extra = msg->msgid >= crcs.size() ? 0 : crcs.at(msg->msgid) ;
	uint8_t crc_extra = 0;
	auto it = crc_map.find(msg->msgid);
	if(it != crc_map.end()) {
		crc_extra = it->second;
	}
	crc_accumulate(crc_extra, &checksum);
	mavlink_ck_a(msg) = (uint8_t)(checksum & 0xFF);
	mavlink_ck_b(msg) = (uint8_t)(checksum >> 8);

	msg->checksum = checksum;
}