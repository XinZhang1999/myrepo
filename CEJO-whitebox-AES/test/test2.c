#include "wbaes.h"

int main(int argc, char * argv[])
{
    int i;
    unsigned char IN[20] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff,0xed,0xfc,0x12,0x34};
    unsigned char EX_IN[20];
    unsigned char EX_OUT[20];
    unsigned char OUT[20];
    unsigned char OOUT[20];
    u8 key[20] = {0};
    
    wbaes_gen(key);
    // external encodings
    for(i = 0; i < 20; i++)
    {
        EX_IN[i] = TypeIa[i][IN[i]];
    }
    // encryption
    wbaes_encrypt(EX_IN, EX_OUT);
    // external encodings
    for(i = 0; i < 20; i++)
    {
        OUT[i] = TypeIb[i][EX_OUT[i]];
    }
    printstate(OUT);
    
    aes_128_encrypt(IN, key, OOUT);
    printstate(OOUT);
    
    return 0;
}
