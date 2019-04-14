/**
  ******************************************************************************
  * @file    font24.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-February-2014
  * @brief   This file provides text font24 for STM32xx-EVAL's LCD driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fonts.h"
#if defined(__AVR__)
#include <avr/pgmspace.h>
#elif defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#endif

const unsigned char FontClock_Table [] PROGMEM =
{
	// @88 '0' (32 pixels wide)
	0x01, 0xFF, 0xFF, 0x80, //        ##################
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x09, 0xFF, 0xFF, 0x90, //     #  ##################  #
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
    0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x08, 0x00, 0x00, 0x10, //     #                      #
	0x00, 0x00, 0x00, 0x00, //      
	0x08, 0x00, 0x00, 0x10, //     #                      #
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
    0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x09, 0xFF, 0xFF, 0x90, //     #  ##################  #
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x01, 0xFF, 0xFF, 0x80, //        ##################

	// @176 '1' (17 pixels wide)
	0x00, 0x00, 0x00, 0x00, //        
	0x00, 0x00, 0x00, 0x00, //      
	0x00, 0x00, 0x00, 0x10, //                            #
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
    0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x10, //                            #
	0x00, 0x00, 0x00, 0x00, //      
	0x00, 0x00, 0x00, 0x10, //                            #
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###	
    0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x10, //                            #
	0x00, 0x00, 0x00, 0x00, // 
	0x00, 0x00, 0x00, 0x00, // 

	// @264 '2' (17 pixels wide)
	0x01, 0xFF, 0xFF, 0x80, //        ##################
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x09, 0xFF, 0xFF, 0x80, //     #  ################## 
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x09, 0xFF, 0xFF, 0x80, //     #  ################## 
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x01, 0xFF, 0xFF, 0x80, //        ##################

	// @352 '3' (17 pixels wide)
	0x01, 0xFF, 0xFF, 0x80, //        ##################
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x01, 0xFF, 0xFF, 0x80, //        ##################

	// @440 '4' (17 pixels wide)
	0x00, 0x00, 0x00, 0x00, //     
	0x00, 0x00, 0x00, 0x00, //     
	0x08, 0x00, 0x00, 0x10, //     #                      #
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x09, 0xFF, 0xFF, 0x90, //     #  ##################  #
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x10, //                            #
	0x00, 0x00, 0x00, 0x00, //
	0x00, 0x00, 0x00, 0x00, //

	// @528 '5' (17 pixels wide)
	0x01, 0xFF, 0xFF, 0x80, //        ##################
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x09, 0xFF, 0xFF, 0x80, //     #  ################## 
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###             
	0x09, 0xFF, 0xFF, 0x80, //     #  ################## 
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x01, 0xFF, 0xFF, 0x80, //        ##################

	// @616 '6' (17 pixels wide)
	0x01, 0xFF, 0xFF, 0x80, //        ##################
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x09, 0xFF, 0xFF, 0x80, //     #  ################## 
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###
	0x1C, 0x00, 0x00, 0x00, //    ###             
	0x09, 0xFF, 0xFF, 0x80, //     #  ################## 
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x09, 0xFF, 0xFF, 0x90, //     #  ##################  #
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x09, 0xFF, 0xFF, 0x90, //     #  ##################  #
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x01, 0xFF, 0xFF, 0x80, //        ##################

	// @704 '7' (17 pixels wide)
	0x01, 0xFF, 0xFF, 0x80, //        ##################
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x10, //                            #
	0x00, 0x00, 0x00, 0x00, //      
	0x00, 0x00, 0x00, 0x10, //                            #
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x10, //                            #
	0x00, 0x00, 0x00, 0x00, // 
	0x00, 0x00, 0x00, 0x00, // 

	// @792 '8' (17 pixels wide)
	0x01, 0xFF, 0xFF, 0x80, //        ##################
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x09, 0xFF, 0xFF, 0x90, //     #  ##################  #
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x09, 0xFF, 0xFF, 0x90, //     #  ##################  #
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x09, 0xFF, 0xFF, 0x90, //     #  ##################  #
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x09, 0xFF, 0xFF, 0x90, //     #  ##################  #
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x01, 0xFF, 0xFF, 0x80, //        ##################

	// @880 '9' (17 pixels wide)
	0x01, 0xFF, 0xFF, 0x80, //        ##################
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x09, 0xFF, 0xFF, 0x90, //     #  ##################  #
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x1C, 0x00, 0x00, 0x38, //    ###                    ###
	0x09, 0xFF, 0xFF, 0x90, //     #  ##################  #
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x00, 0x00, 0x00, 0x38, //                           ###
	0x07, 0xFF, 0xFF, 0x90, //        ##################  #
	0x07, 0xFF, 0xFF, 0xE0, //      ######################
	0x01, 0xFF, 0xFF, 0x80, //        ##################

	// @0 ' ' (32 pixels wide)
    0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //           
    0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x03, 0xC0, 0x00, // _ _ _ _ _ _ _ #### _ _ _ _ _ _ _
	0x00, 0x07, 0xE0, 0x00, //              ######
	0x00, 0x07, 0xE0, 0x00, //              ######
	0x00, 0x03, 0xC0, 0x00, //               ####
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x03, 0xC0, 0x00, //               ####
	0x00, 0x07, 0xE0, 0x00, //              ######
	0x00, 0x07, 0xE0, 0x00, //              ######
	0x00, 0x03, 0xC0, 0x00, //               ####
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //           

    // @0 ' ' (32 pixels wide)
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                         
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //           
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                         
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //          
    0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //                  
	0x00, 0x00, 0x00, 0x00, //

};

sFONT FontClock = {
  FontClock_Table,
  32, /* Width */
  30, /* Height */
};

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
