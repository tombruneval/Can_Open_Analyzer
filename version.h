#ifndef VERSION_H_INCLUDED
#define VERSION_H_INCLUDED
/*
 *   To do list :
 */

/******************************************************************************/
/*                          SOFTWARE VERSION                                  */
/******************************************************************************/

//                     Number       Date        Comments

#define SOFTWARE_VERSION    "2.1"    // 12/01/2024
/*
 *     New updated version
 *     Changelog :
 *     -Added support for CAN2 analysis of Enix BMS
 *     -Fixed radio SDO Index to show batterylevel 
 */

//#define SOFTWARE_VERSION    "2.0"    // 12/01/2024
/*
 *     New updated version
 *     Changelog :
 *     -Added support for PCU Board with all indexes
 *     -Added support for RFID boards without indexes
 */

//#define SOFTWARE_VERSION    "2.0b"    // 04/01/2024
/*
 *     New updated version
 *     Changelog :
 *     -Added or modified some indexes :
 *          *Radio Ox2002 : Added name tags for all faults and alarms numbers
 *     -Fixed lots of bug with PDOs analyzing
 *     -Changed how PDO Data was stored and collected to match what was done previously with SDOs
 */

//#define SOFTWARE_VERSION    "2.0a"    // 19/12/2023
/*
 *     New updated version
 *     Changelog :
 *     -Added multiple Indexes to analyze :
 *          *Radio Indexes : 0x2000, 0x2001, 0x2002
 *          *IO Indexes : 0x2000, 0x2001, 0x2010
 *          *EDS Indexes : 0x2000, 0x2001, 0x2002
 *     -Added all daughter boards PDOs (even Drivers)
 *     -Added Errors for Drivers
 *     -Changed how SDO Segmented Data was stored and collected
 *     -Changed the conversion method to convert HEX Strings to ASCII characters
 *     -Fixed some issues with the SDOWrite State Machine
 */


//#define SOFTWARE_VERSION    "1.1b"    // 27/10/2023
/*
 *     New updated version
 *     Changelog :
 *     -Added ability to analyze multiple input files and generate multiple output files
 */

//#define SOFTWARE_VERSION    "1.1a"    // 27/10/2023
/*
 *     New updated version
 *     Changelog :
 *     -Added a few new Index and SubIndex 
 *     -Added ability to recognize SDO Write frames
 *
 */


//#define SOFTWARE_VERSION    "1.0"    // 27/10/2023
/*
 *     First release of this software.
 *
 *     This software tool is used to analyze one CANOPEN files.
 *     It produces output CSV files for :
 *         - The output file containing main informations
 *         - The debug file containing extended frames informations
 *
 */



#endif // VERSION_H_INCLUDED
