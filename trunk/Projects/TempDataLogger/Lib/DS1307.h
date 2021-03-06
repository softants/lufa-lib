/*
     Copyright (C) Dean Camera, 2011.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

#ifndef _DS1307_H_
#define _DS1307_H_

	/* Includes: */
		#include <avr/io.h>

		#include <LUFA/Drivers/Peripheral/TWI.h>

	/* Type Defines: */
		typedef struct
		{
			uint8_t Hour;
			uint8_t Minute;
			uint8_t Second;
			uint8_t Day;
			uint8_t Month;
			uint8_t Year;
		} TimeDate_t;
	
		typedef struct
		{
			union
			{
				struct
				{
					unsigned int Sec            : 4;
					unsigned int TenSec         : 3;
					unsigned int CH             : 1;
				} Fields;

				uint8_t IntVal;
			} Byte1;

			union
			{
				struct
				{
					unsigned int Min            : 4;
					unsigned int TenMin         : 3;
					unsigned int Reserved       : 1;
				} Fields;

				uint8_t IntVal;
			} Byte2;

			union
			{
				struct
				{
					unsigned int Hour            : 4;
					unsigned int TenHour         : 2;
					unsigned int TwelveHourMode  : 1;
					unsigned int Reserved        : 1;
				} Fields;

				uint8_t IntVal;
			} Byte3;

			union
			{
				struct
				{
					unsigned int DayOfWeek       : 3;
					unsigned int Reserved        : 5;
				} Fields;

				uint8_t IntVal;
			} Byte4;
		
			union
			{
				struct
				{
					unsigned int Day             : 4;
					unsigned int TenDay          : 2;
					unsigned int Reserved        : 2;
				} Fields;

				uint8_t IntVal;
			} Byte5;

			union
			{
				struct
				{
					unsigned int Month           : 4;
					unsigned int TenMonth        : 1;
					unsigned int Reserved        : 3;
				} Fields;

				uint8_t IntVal;
			} Byte6;

			union
			{
				struct
				{
					unsigned int Year            : 4;
					unsigned int TenYear         : 4;
				} Fields;

				uint8_t IntVal;
			} Byte7;
		} DS1307_DateTimeRegs_t;

	/* Macros: */
		#define DS1307_ADDRESS       0xD0

	/* Function Prototypes: */
		bool DS1307_SetTimeDate(const TimeDate_t* NewTimeDate);
		bool DS1307_GetTimeDate(TimeDate_t* const TimeDate);

#endif

