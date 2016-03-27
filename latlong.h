#include <math.h>

#ifndef NAN
/* This is not available before C99 */
#define NAN (0. / 0.)
#endif

int ParseLatLong(const char *latlongstr, struct GPSPoint* point);
int MakeTrackFromLatLong(const struct GPSPoint* latlong, struct GPSTrack* track);
int NumDecimals(const char *Decimal);

