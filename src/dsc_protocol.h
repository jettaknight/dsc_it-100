/**
 *  @file
 *
 *  Encodes and decodes messages
 */


#ifndef _DSC_PROTOCOL_H_
#define _DSC_PROTOCOL_H_


#include <stdint.h>



struct dsc_struct
{
    uint16_t command;
    uint16_t data_size;
    uint8_t data[48];
};


/**
 *  \brief Decode a string from the DSC IT-100
 *
 *  \param[in]  string      String that was received, null terminated
 *  \param[out] message     Decoded message, comand will be 0xFFFF if failed.
 *
 *  \details This will block until a properly formate string is received
 */
void dsc_decode(char *string, struct dsc_struct *message);

/**
 *  \brief Encode a string for the DSC IT-100
 *
 *  \param[out] string  Encoded output, null terminated
 *  \param[in] message  Incoming message to be encoded
 *
 *  \details More details
 */
void dsc_encode(char *string, struct dsc_struct *message);

#endif /* _DSC_PROTOCOL_H_ */
