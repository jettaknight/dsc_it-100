/**
 *  @file
 *
 *  See IT-100 Data Interface Module v1.0 Developer's Guide.
 */

#include <stdio.h>
#include <string.h>
#include "dsc_protocol.h"

// send a string, excluding checksum and ending
static uint8_t checksum(char *string)
{
    uint8_t a = 0;
    size_t i = 0;
    
    while(string[i] != 0)
    {
        a += string[i];
        i++;
    }
    return a;
}

void dsc_decode(char *string, struct dsc_struct *message)
{
    unsigned int cs = 0;    // scanf demands this type
    size_t i = strlen(string);

    // 5 = command (3) + schecksum (2) + ending (2)
    if (i < 7)
    {
        message->command = 0xFFFF;
        return;
    }


    /* The data bytes is variable and not explicitly declared. */
    i -= 2;
    if ((string[i] != '\r') || (string[i+1] != '\n'))
    {
        message->command = 0xFFFF;
        return;
    }
    // strip off the ending
    string[i] = 0;


    i -= 2;
    sscanf(&string[i], "%02x", &cs);
    // strip off the checksum
    string[i] = 0;

    if (cs != checksum(string))
    {
        message->command = 0xFFFF;
        return;
    }

    sscanf(string, "%03u", &message->command);
    message->data_size = strlen(&string[3]);
    memcpy(message->data, &string[3], message->data_size);
}

void dsc_encode(char *string, struct dsc_struct *message)
{
    size_t i,j;

    sprintf(string, "%03u", message->command);
    j =  3;
    for (i = 0; i < message->data_size; i++)
    {
        string[j] = message->data[i];
        j++;
    }
    // checksum
    string[j] = 0;  // temporary
    sprintf(&string[j], "%02X", checksum(string));
    j += 2;

    string[j++] = '\r';
    string[j++] = '\n';
    string[j] = 0;
}
