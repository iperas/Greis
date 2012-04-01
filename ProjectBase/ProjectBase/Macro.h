#ifndef macro_h__
#define macro_h__

/* ----------------- Internal macro (do not use it) ------------------- */

/* turn a numeric literal into a hex constant
(avoids problems with leading zeroes)
8-bit constants max value 0x11111111, always fits in unsigned long
*/
#define HEX__(n) 0x##n##LU

/* 8-bit conversion function */
#define B8__(x) ((x&0x0000000FLU)?1:0) \
    +((x&0x000000F0LU)?2:0) \
    +((x&0x00000F00LU)?4:0) \
    +((x&0x0000F000LU)?8:0) \
    +((x&0x000F0000LU)?16:0) \
    +((x&0x00F00000LU)?32:0) \
    +((x&0x0F000000LU)?64:0) \
    +((x&0xF0000000LU)?128:0)

/* ----------------- 'B8(01010101) => decimal-value' converters ------------------- */

/* for upto 8-bit binary constants. Usage: B8(01010101) => decimal-value */
#define B8(d) ((unsigned char)B8__(HEX__(d)))

/* for upto 16-bit binary constants, MSB first. Usage: B16(01010101, 01010101) => decimal-value */
#define B16(dmsb,dlsb) (((unsigned short)B8(dmsb)<< \
    + B8(dlsb))

/* for upto 32-bit binary constants, MSB first. Usage: B32(01010101, 01010101, 01010101, 01010101) => decimal-value */
#define B32(dmsb,db2,db3,dlsb) (((unsigned long)B8(dmsb)<<24) \
    + ((unsigned long)B8(db2)<<16) \
    + ((unsigned long)B8(db3)<< \
    + B8(dlsb))

/* ----------------- Type size static assertion ------------------- */

#define VALIDATE_TYPE_SIZE(TYPENAME, EXPECTEDSIZE) static_assert(sizeof(TYPENAME) == EXPECTEDSIZE, \
    "Invalid type size.")

#endif // macro_h__
