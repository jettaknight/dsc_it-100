/**
 *  @file
 *
 *  Sends strings, and receives strings with CR/LF endings.
 */


#ifndef _DSC_SERIAL_H_
#define _DSC_SERIAL_H_

#define MAX_STRING_SIZE         100U

/**
 *  \brief Opens up the serial port
 *
 */
void serial_init(void);

/**
 *  \brief Reads a string from the DSC IT-100
 *
 *  \param[out]  string     String that was received, null terminated
  *
 *  \details This will block until a properly formate string is received
 */
void serial_read(char *string);

/**
 *  \brief Send a string to the DSC IT-100
 *
 *  \param [in] string String to write, null terminated
 *
 *  \details More details
 */
void serial_write(char *string);

#endif /* _DSC_SERIAL_H_ */
