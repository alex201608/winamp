/*---- DXhead.h --------------------------------------------


decoder MPEG Layer III

handle Xing header


Copyright 1998 Xing Technology Corp.
-----------------------------------------------------------*/
// A Xing header may be present in the ancillary
// data field of the first frame of an mp3 bitstream
// The Xing header (optionally) contains
//      frames      total number of audio frames in the bitstream
//      bytes       total number of bytes in the bitstream
//      toc         table of contents

// toc (table of contents) gives seek points
// for random access
// the ith entry determines the seek point for
// i-percent duration
// seek point in bytes = (toc[i]/256.0) * total_bitstream_bytes
// e.g. half duration seek point = (toc[50]/256.0) * total_bitstream_bytes


#define FRAMES_FLAG     0x0001
#define BYTES_FLAG      0x0002
#define TOC_FLAG        0x0004
#define VBR_SCALE_FLAG  0x0008

#define FRAMES_AND_BYTES (FRAMES_FLAG | BYTES_FLAG)


int SeekPoint(unsigned char TOC[100], int file_bytes, float percent);
// return seekpoint in bytes (may be at eof if percent=100.0)
// TOC = table of contents from Xing header
// file_bytes = number of bytes in mp3 file
// percent = play time percentage of total playtime. May be
//           fractional (e.g. 87.245)




