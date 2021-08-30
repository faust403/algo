#include "dl-list.h"

char * typeid(void * val)
{
        switch(sizeof(val))
        {
                case sizeof(char):    
                        return "char";
                        break;   
                case sizeof(int):
                case sizeof(unsigned int):
                        return "int";
                        break;
                case sizeof(void*):
                        return "pointer";
                        break;    
                case sizeof(long):
                case sizeof(unsigned long):
                case sizeof(unsigned long long):
                        return "long";
                        break;
                default: return "other";
        }
}

unsigned short stringLength(const char * string)
{
    unsigned short res = 0;
    
    for(int i = 0; i < strlen(string);)
    {
        unsigned char character = string[i];
        
        if((character >> 7) == 0)
        {
            i += 1;
        }
        else if((character >> 5) == 6)
        {
            i += 2;
        }
        else if((character >> 4) == 14)
        {
            i += 3;
        }
        else if((character >> 3) == 30)
        {
            i += 4;
        }
        res += 1;
    }
    return res;
}
