CRC32 crc;
// checksum object

int messageCount = 0;

char* formMessageSegments(char* msg){
	// msg is a pointer to char array
	// initalise buffer [10][6000]
	// buffer limited to 60kB
	char byteBuffer[10][6000];
	// give char array of size N => form x number of 6000 byte segments
	int N = strlen(msg) ;// string length
	double x = ceil(N/6000); // rounded up to nearest integer
	int X = int(x) // cast double to int
	int remain = N%6000 ; // get remaining via modulus
	// split message
	for (int i = 0 ; i<N-1 ; i++){
		for (int j = 0 ; j<6000 ; j++){
			byteBuffer[i][j] = msg[i*6000+j];
		}
	}
}

char* formPacket(char *msg, uint8_t msgNo, uint8_t segNo){
	// takes in message

	// forms packet header
	// returns string of packet header+message
	// header == 
	// essential info => message_no. (1 byte), n-th message segment(1-byte), checksum(4 bytes)
	// 6006

	// form checksum
	// message size
	char byteBuffer[6000] = msg;
	uint32_t checksum = CRC32.calculate(byteBuffer,32);
	//uint32_t checksum = CRC32::calculate(byteBuffer,32)
	// convert uint32_t => byte[4]

	char packet[6006];
	packet[0] = msgNo;
	packet[1] = segNo;
	// Checksum
	packet[2] = v;
	packet[3] = v>>8;
	packet[4] = v>>16;
	packet[5] = v>>24;
}