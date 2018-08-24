#include <math.h>

int ParseLatLong(const char *latlongstr, struct GPSPoint* point);
int MakeTrackFromLatLong(const struct GPSPoint* latlong, struct GPSTrack* track);
int NumDecimals(const char *Decimal);

