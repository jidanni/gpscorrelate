/* unixtime.c
 * Written by Daniel Foote.
 * Started Feb 2005.
 *
 * This file contains a function that converts a string
 * to a unix time, given a format string.
 */

/* Copyright 2005 Daniel Foote.
 *
 * This file is part of gpscorrelate.
 *
 * gpscorrelate is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gpscorrelate is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gpscorrelate; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "unixtime.h"

time_t ConvertToUnixTime(const char* StringTime, const char* Format,
		int TZOffsetHours, int TZOffsetMinutes)
{
	/* Read the time using the specified format. 
	 * The format and string being read from must
	 * have the most significant time on the left,
	 * and the least significant on the right:
	 * ie, Year on the left, seconds on the right. */

	/* Sanity check... */
	if (StringTime == NULL || Format == NULL)
	{
		return 0;
	}

	/* Define and set up our structure. */
	struct tm Time;
	Time.tm_wday = 0;
	Time.tm_yday = 0;
	Time.tm_isdst = -1;

	/* Read out the time from the string using our format. */
	sscanf(StringTime, Format, &Time.tm_year, &Time.tm_mon,
			&Time.tm_mday, &Time.tm_hour,
			&Time.tm_min, &Time.tm_sec);

	/* Adjust the years for the mktime function to work. */
	Time.tm_year -= 1900;
	Time.tm_mon  -= 1;

	/* Add our timezone offset to the time.
	 * We don't check to see if it overflowed anything;
	 * mktime does this and fixes it for us. */
	/* Note also that we SUBTRACT these times. We want the
	 * result to be in UTC. */

	Time.tm_hour -= TZOffsetHours;
	Time.tm_min  -= TZOffsetMinutes;

	/* Calculate and return the unix time. */
	return mktime(&Time);
}

