# GPSCorrelate

January 2013

## Status

GPSCorrelate was originally written by Daniel Foote. The maintainer is now
Dan Fandrich <dan@coneharvesters.com>.

The GPSCorrelate home page is at https://dfandrich.github.com/gpscorrelate/

## What is it?

Digital cameras are cool. So is GPS. And, EXIF tags are really cool too.

What happens when you merge the three? You end up with a set of photos taken
with a digital camera that are "stamped" with the location at which they were
taken.

The EXIF standard defines a number of tags that are for use with GPS.

A variety of programs exist around the place to match GPS data with digital
camera photos, but most of them are Windows or MacOS only. Which doesn't really
suit me that much. Also, each one takes the GPS data in a different format.

So I wrote my own. A little bit of C, a little bit of C++, a shade of GTK+, and
you end up with... what I have here. I wrote both a command line and GUI
version of the program.

## Things you should know:

* The program takes GPS data in GPX format. This is an XML format. I recommend
  using GPSBabel - it can convert from lots of formats to GPX, as well as
  download from several brands of popular GPS receivers.
* The program can "interpolate" between points (linearly) to get better
  results. (That is, for  GPS logs that are not one sample per second, like
  those I get off my Garmin eTrex GPS)
* The resolution is down to one second. But that should be good enough for most
  things. (This is a limit of the EXIF tags format, as well as GPX)
* For best results, you should synchronise your camera to the GPS time before
  you start taking photos. Note: digital cameras clocks drift quickly - even
  over a short period of time (say, a week).


Daniel Foote, 2005.
Daniel Fandrich, 2013.
