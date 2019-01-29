/**
 *  @file
 */

#ifndef _DSC_HANDLER_H_
#define _DSC_HANDLER_H_

#include "dsc_protocol.h"



// Command codes.
#define DSC_COMMAND_POLL                                  0
#define DSC_COMMAND_STATUS_REQUEST                        1
#define DSC_COMMAND_LABELS_REQUEST                        2
#define DSC_COMMAND_SET_TIME_DATE                        10
#define DSC_COMMAND_OUTPUT_CONTROL                       20
#define DSC_COMMAND_PARTITION_ARM_CONTROL_AWAY           30
#define DSC_COMMAND_PARTITION_ARM_CONTROL_STAY           31
#define DSC_COMMAND_PARTITION_ARM_CONTROL_ARMED          32
#define DSC_COMMAND_PARTITION_ARM_CONTROL_WITH_CODE      33
#define DSC_COMMAND_PARTITION_DISARM_CONTROL             40
#define DSC_COMMAND_TIME_STAMP_CONTROL                   55
#define DSC_COMMAND_TIME_DATE_BCAST_CONTROL              56
#define DSC_COMMAND_TEMPERATURE_BCAST_CONTROL            57
#define DSC_COMMAND_VIRTUAL_KEYBOARD_CONTROL             58
#define DSC_COMMAND_TRIGGER_PANIC_ALARM                  60
#define DSC_COMMAND_KEY_PRESSED                          70
#define DSC_COMMAND_SET_BAUD_RATE                        80
#define DSC_COMMAND_CODE_SEND                           200

// Notification codes.
#define DSC_NOTIFY_ACK                                  500
#define DSC_NOTIFY_ERROR                                501
#define DSC_NOTIFY_SYSTEM_ERROR                         502
#define DSC_NOTIFY_TIME_DATE_BCAST                      550
#define DSC_NOTIFY_LABELS                               570
#define DSC_NOTIFY_BAUD_RATE_SET                        580
#define DSC_NOTIFY_ZONE_ALARM                           601
#define DSC_NOTIFY_ZONE_ALARM_RESTORE                   602
#define DSC_NOTIFY_ZONE_TAMPER                          603
#define DSC_NOTIFY_ZONE_TAMPER_RESTORE                  604
#define DSC_NOTIFY_ZONE_FAULT                           605
#define DSC_NOTIFY_ZONE_FAULT_RESTORE                   606
#define DSC_NOTIFY_ZONE_OPEN                            609
#define DSC_NOTIFY_ZONE_RESTORED                        610
#define DSC_NOTIFY_DURESS_ALARM                         620
#define DSC_NOTIFY_FIRE_KEY_ALARM                       621
#define DSC_NOTIFY_FIRE_KEY_RESTORED                    622
#define DSC_NOTIFY_AUXILARY_KEY_ALARM                   623
#define DSC_NOTIFY_AUXILARY_KEY_RESTORED                624
#define DSC_NOTIFY_PANIC_KEY_ALARM                      625
#define DSC_NOTIFY_PANIC_KEY_RESTORED                   626
#define DSC_NOTIFY_AUXILARY_INPUT_ALARM                 631
#define DSC_NOTIFY_AUXILARY_INPUT_RESTORED              632
#define DSC_NOTIFY_PARTITION_READY                      650
#define DSC_NOTIFY_PARTITION_NOT_READY                  651
#define DSC_NOTIFY_PARTITION_ARMED                      652
#define DSC_NOTIFY_PARTITION_READY_TO_FORCE_ARM         653
#define DSC_NOTIFY_PARTITION_IN_ALARM                   654
#define DSC_NOTIFY_PARTITION_DISARMED                   655
#define DSC_NOTIFY_PARTITION_EXIT_DELAY                 656
#define DSC_NOTIFY_PARTITION_ENTRY_DELAY                657
#define DSC_NOTIFY_KEYPAD_LOCKOUT                       658
#define DSC_NOTIFY_KEYPAD_BLANKING                      659
#define DSC_NOTIFY_COMMAND_OUTPUT                       660
#define DSC_NOTIFY_INVALID_CODE                         670
#define DSC_NOTIFY_FUNCTION_NOT_AVAILABLE               671
#define DSC_NOTIFY_FAILED_TO_ARM                        672
#define DSC_NOTIFY_PARTITION_BUSY                       673
#define DSC_NOTIFY_PARTITION_USER_CLOSING               700
#define DSC_NOTIFY_PARTITION_SPECIAL_CLOSING            701
#define DSC_NOTIFY_PARTITION_PARTIAL_CLOSING            702
#define DSC_NOTIFY_PARTITION_USER_OPENING               750
#define DSC_NOTIFY_PARTITION_SPECIAL_OPENING            751
#define DSC_NOTIFY_PANEL_BATTERY_TROUBLE                800
#define DSC_NOTIFY_PANEL_BATTERY_RESTORED               801
#define DSC_NOTIFY_PANEL_AC_TROUBLE                     802
#define DSC_NOTIFY_PANEL_AC_RESTORED                    803
#define DSC_NOTIFY_SYSTEM_BELL_TROUBLE                  806
#define DSC_NOTIFY_SYSTEM_BELL_RESTORED                 807
#define DSC_NOTIFY_GENERAL_DEV_LOW_BATTERY              821
#define DSC_NOTIFY_GENERAL_DEV_LOW_BATTERY_RESTORED     822
#define DSC_NOTIFY_GENERAL_SYSTEM_TAMPER                829
#define DSC_NOTIFY_GENERAL_SYSTEM_TAMPER_RESTORED       830
#define DSC_NOTIFY_PARTITION_TROUBLE                    840
#define DSC_NOTIFY_PARTITION_TROUBLE_RESTORED           841
#define DSC_NOTIFY_FIRE_TROUBLE_ALARM                   842
#define DSC_NOTIFY_FIRE_TROUBLE_RESTORED                843
#define DSC_NOTIFY_KEYBUS_FAULT                         896
#define DSC_NOTIFY_KEYBUS_RESTORED                      897
#define DSC_NOTIFY_CODE_REQUIRED                        900
#define DSC_NOTIFY_BEEP_STATUS                          904
#define DSC_NOTIFY_VERSION                              908


/**
 *  \brief Process an encoding message
 *
 *  \param [in] message Message received from DSC IT-100
 *
 *
 *
 */
void process_dsc_message(struct dsc_struct *message);

#endif /* _DSC_HANDLER_H_ */
